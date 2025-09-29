#include<iostream>
using namespace std;

template <typename T>
class Node
{
    public:
        T data;
        Node* next;
        Node* prev;
        Node* child;

        Node(T data, Node* next = nullptr, Node* prev = nullptr, Node* child = nullptr)
        {
            this->data = data;
            this->next = next;
            this->prev = prev;
            this->child = child;
        }
};

template <typename T>
class SLL 
{
    private:

        Node<T>* start;
        int length = 0;

    public:

        SLL() {start = nullptr;}

        void insertNode(T data, int pos) 
        {
            if (pos < 0 || pos > length) 
            {
                cout << "Index out of Range...." << endl;
                return;
            }

            if (pos == 0) 
            {
                Node<T>* node = new Node<T>(data, start);
                start = node;
                length++;
                return;
            }

            Node<T>* temp = start;

            for (int i = 0; temp != nullptr && i < pos - 1; i++)
                temp = temp->next;

            Node<T>* node = new Node<T>(data, temp->next);
            temp->next = node;
            length++;
        }

        void insertAtStart(T data) 
        {
            insertNode(data, 0);
        }

        void insertAtEnd(T data) 
        {
            insertNode(data, length);
        }

        bool search(T data) 
        {
            Node<T>* temp = start;

            while (temp != nullptr)
                if (temp->data == data) return true; else temp = temp->next;

            return false;
        }

        bool contentOfNode(int pos) 
        {
            if (pos < 0 || pos >= length) 
            {
                cout << "Position out of range!" << endl;
                return false;
            }

            Node<T>* temp = start;

            for (int i = 0; i < pos && temp != nullptr; i++)
                temp = temp->next;

            cout << "Node at position " << pos << " = " << temp->data << endl;
            return true;
        }

        void printContents() 
        {
            if (start == nullptr) 
            {
                cout << "List is Empty" << endl;
                return;
            }

            Node<T>* temp = start;
            while (temp != nullptr) 
            {
                cout << "Data: " << temp->data << " | Next: " << temp->next << endl;
                temp = temp->next;
            }
            cout << endl;
        }

        void updateNode(int pos, T newData) 
        {
            if (pos < 0 || pos >= length) 
            {
                cout << "Position out of range!" << endl;
                return;
            }

            Node<T>* temp = start;

            for (int i = 0; i < pos; i++)
                temp = temp->next;

            temp->data = newData;
        }

        void deleteAtPosition(int pos) 
        {
            if (pos < 0 || pos >= length || start == nullptr) 
            {
                cout << "Invalid position!" << endl;
                return;
            }

            if (pos == 0) 
            {
                popFront();
                return;
            }

            Node<T>* temp = start;

            for (int i = 0; i < pos - 1; i++) 
            {
                temp = temp->next;
            }

            Node<T>* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
            length--;
        }

        void deleteByValue(T data) 
        {
            while (start != nullptr && start->data == data)
                popFront();

            Node<T>* temp = start;
            while (temp != nullptr && temp->next != nullptr) 
                if (temp->next->data == data)
                {
                    Node<T>* toDelete = temp->next;
                    temp->next = temp->next->next;
                    delete toDelete;
                    length--;
                } 
                else
                    temp = temp->next;
        }

        void popFront() 
        {
            if (start == nullptr) 
            {
                cout << "List is empty";
                return;
            }

            Node<T>* temp = start;
            start = start->next;
            temp->next = nullptr;
            delete temp;
            length--;
        }

        void popBack() 
        {
            if (start == nullptr) 
            {
                cout << "List is empty";
                return;
            }

            if (start->next == nullptr) 
            {
                popFront();
                return;
            }

            Node<T>* temp = start;

            while (temp->next->next != nullptr)
                temp = temp->next;

            delete temp->next;
            temp->next = nullptr;
            length--;
        }

        bool isEmpty() 
        {
            return length == 0;
        }

        int capacity() 
        {
            return length;
        }

        T get(int pos) 
        {
            if (pos < 0 || pos >= length) 
            {
                throw out_of_range("Position out of range!");
            }

            Node<T>* temp = start;

            for (int i = 0; i < pos; i++)
                temp = temp->next;

            return temp->data;
        }

        Node<T>* getStart()
        {
            return start;
        }

        ~SLL() 
        {
            while (start != nullptr) 
            {
                Node<T>* temp = start;
                start = start->next;
                delete temp;
            }
            
            length = 0;
        }
};

template <typename T>
class DLL
{
    private:
        Node<T>* start;
        Node<T>* end;
        int length = 0;

    public:
        DLL() { start = nullptr; end = nullptr; }

        void insertNode(T data, int pos)
        {
            if(pos < 0 || pos > length)
            {
                cout << "Index out of Range...." << endl;
                return;
            }

            if(pos == 0)
            {
                Node<T>* node = new Node<T>(data, start, nullptr);
                if(start != nullptr) start->prev = node;
                start = node;
                if(length == 0) end = node;
                length++;
                return;
            }

            if(pos == length)
            {
                Node<T>* node = new Node<T>(data, nullptr, end);
                if(end != nullptr) end->next = node;
                end = node;
                if(length == 0) start = node;
                length++;
                return;
            }

            Node<T>* temp = start;
            for(int i = 0; i < pos - 1; i++) temp = temp->next;
            Node<T>* node = new Node<T>(data, temp->next, temp);
            temp->next->prev = node;
            temp->next = node;
            length++;
        }

        void insertAtStart(T data)
        {
            insertNode(data, 0);
        }

        void insertAtEnd(T data)
        {
            insertNode(data, length);
        }

        void addChild(Node<T>* parent, T data)
        {
            if(parent == nullptr) return;
            if(parent->child == nullptr)
            {
                parent->child = new Node<T>(data);
                return;
            }
            Node<T>* temp = parent->child;
            while(temp->next != nullptr) temp = temp->next;
            Node<T>* node = new Node<T>(data, nullptr, temp);
            temp->next = node;
        }

        bool search(T data)
        {
            Node<T>* temp = start;
            while(temp != nullptr)
            {
                if(temp->data == data) return true;
                Node<T>* c = temp->child;
                while(c != nullptr)
                {
                    if(c->data == data) return true;
                    c = c->next;
                }
                temp = temp->next;
            }
            return false;
        }

        bool contentOfNode(int pos)
        {
            if(pos < 0 || pos >= length)
            {
                cout << "Position out of range!" << endl;
                return false;
            }
            Node<T>* temp = start;
            for(int i = 0; i < pos; i++) temp = temp->next;
            cout << "Node at position " << pos << " = " << temp->data << endl;
            return true;
        }

        void printContents(Node<T>* node, int level = 0)
        {
            if(node == nullptr) return;

            Node<T>* temp = node;
            while(temp != nullptr)
            {
                for(int i = 0; i < level; i++) cout << "    ";
                cout << "Data: " << temp->data;
                if(temp->child != nullptr)
                {
                    cout << " -> Child:" << endl;
                    printContents(temp->child, level + 1);
                }
                else
                {
                    cout << endl;
                }
                temp = temp->next;
            }
        }

        void updateNode(int pos, T newData)
        {
            if(pos < 0 || pos >= length)
            {
                cout << "Position out of range!" << endl;
                return;
            }
            Node<T>* temp = start;
            for(int i = 0; i < pos; i++) temp = temp->next;
            temp->data = newData;
        }

        void deleteAtPosition(int pos)
        {
            if(pos < 0 || pos >= length || start == nullptr)
            {
                cout << "Invalid position!" << endl;
                return;
            }
            if(pos == 0)
            {
                popFront();
                return;
            }
            if(pos == length - 1)
            {
                popBack();
                return;
            }
            Node<T>* temp = start;
            for(int i = 0; i < pos; i++) temp = temp->next;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            length--;
        }

        void deleteByValue(T data)
        {
            Node<T>* temp = start;
            while(temp != nullptr)
            {
                if(temp->data == data)
                {
                    if(temp == start) { popFront(); temp = start; }
                    else if(temp == end) { popBack(); temp = nullptr; }
                    else
                    {
                        Node<T>* toDelete = temp;
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                        temp = temp->next;
                        delete toDelete;
                        length--;
                    }
                }
                else temp = temp->next;
            }
        }

        void popFront()
        {
            if(start == nullptr)
            {
                cout << "List is empty" << endl;
                return;
            }
            Node<T>* temp = start;
            start = start->next;
            if(start != nullptr) start->prev = nullptr;
            else end = nullptr;
            delete temp;
            length--;
        }

        void popBack()
        {
            if(end == nullptr)
            {
                cout << "List is empty" << endl;
                return;
            }
            Node<T>* temp = end;
            end = end->prev;
            if(end != nullptr) end->next = nullptr;
            else start = nullptr;
            delete temp;
            length--;
        }

        bool isEmpty()
        {
            return length == 0;
        }

        int capacity()
        {
            return length;
        }

        T get(int pos)
        {
            if(pos < 0 || pos >= length) throw out_of_range("Position out of range!");
            Node<T>* temp = start;
            for(int i = 0; i < pos; i++) temp = temp->next;
            return temp->data;
        }

        Node<T>* getStart()
        {
            return start;
        }

        Node<T>* getEnd()
        {
            return end;
        }

        ~DLL()
        {
            while(start != nullptr)
            {
                Node<T>* temp = start;
                if(temp->child != nullptr)
                {
                    Node<T>* c = temp->child;
                    while(c != nullptr)
                    {
                        Node<T>* nextC = c->next;
                        delete c;
                        c = nextC;
                    }
                }
                start = start->next;
                delete temp;
            }
            end = nullptr;
            length = 0;
        }
};

template <typename T>
class Flating
{
    public:

        static void helpp(Node<T>* node, SLL<T>* llist)
        {
            while(node != nullptr)
            {
                llist->insertAtEnd(node->data);

                if(node->child != nullptr)
                    helpp(node->child, llist);

                node = node->next;
            }
        }

        static SLL<T>* flat(DLL<T>* list)
        {
            SLL<T>* llist = new SLL<T>();
            helpp(list->getStart(), llist);
            return llist;
        }
};

int main(void)
{
    DLL<int>* dll = new DLL<int>();

    dll->insertAtEnd(1234);
    dll->insertAtEnd(2156);
    dll->insertAtEnd(572);

    Node<int>* n1 = dll->getStart();
    Node<int>* n2 = n1->next;
    Node<int>* n5 = n2->next;

    dll->addChild(n2, 674);

    Node<int>* n6 = n2->child;
    dll->addChild(n6, 353);

    Node<int>* n35 = n6->child;
    dll->addChild(n35, 288);

    dll->addChild(n35, 40);

    Node<int>* n4 = n35->child->next;
    dll->addChild(n4, 0);

    dll->addChild(n4, 388);

    dll->printContents(dll->getStart());

    cout<<endl;

    SLL<int>* sll = Flating<int>::flat(dll);

    sll->printContents();

    delete sll;
    delete dll;
    sll = nullptr;
    dll = nullptr;
}
