#include<iostream>
using namespace std;

template <typename T>
class Node 
{
    public:

        T data;
        Node* next;

        Node(T data, Node* next) 
        {
            this->data = data;
            this->next = next;
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

class Palindrome
{

    public:

        template <typename T>
        static bool isPal(SLL<T>* list)
        {
            int l = list->capacity();

            if(l == 0)
                return true;

            for(int i = 0; i < l / 2; i++)
                if(list->get(i) != list->get(l - i - 1))
                    return false;

            return true;
        }
};

int main(void) 
{
    SLL<int>* list1 = new SLL<int>();
    SLL<int>* list2 = new SLL<int>();
    SLL<string>* list3 = new SLL<string>();
    SLL<string>* list4 = new SLL<string>();
    SLL<int>* list5 = new SLL<int>();

    int num1[5] = {54, 45, 6, 45, 54};
    int num2[5] = {54, 46, 6, 45, 54};

    string str1[5] = {"saad", "kaif", "saad", "kaif", "saad"};
    string str2[5] = {"hello", "my", "name", "is", "saad"};

    for(int i = 0; i < 5; i++)
    {
        list1->insertNode(num1[i], i);
        list2->insertNode(num2[i], i);
        list3->insertNode(str1[i], i);
        list4->insertNode(str2[i], i);
    }

    list1->printContents();
    list2->printContents();
    list3->printContents();
    list4->printContents();
    list5->printContents();

    cout<<endl;

    cout<<(Palindrome::isPal(list1) ? "list1 is Palindrome" : "list1 isn't Palindrome")<<endl;
    cout<<(Palindrome::isPal(list2) ? "list2 is Palindrome" : "list2 isn't Palindrome")<<endl;
    cout<<(Palindrome::isPal(list3) ? "list3 is Palindrome" : "list3 isn't Palindrome")<<endl;
    cout<<(Palindrome::isPal(list4) ? "list4 is Palindrome" : "list4 isn't Palindrome")<<endl;
    cout<<(Palindrome::isPal(list5) ? "list5 is Palindrome" : "list5 isn't Palindrome")<<endl;

}
