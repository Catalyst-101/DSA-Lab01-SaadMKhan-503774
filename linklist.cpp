#include<iostream>
using namespace std;

class Node{

    public:

        int data;
        Node* next;
    
        Node(int data, Node* next)
        {
            this->data = data;
            this->next = next;
        }
};

class SLL{

    private:

        Node* start;
        int length = 0;

    public:

        SLL()
        {
            start = nullptr;
        }

        void insertNode(int data, int pos)
        {
            if(pos == 0)
            {
                insertAtStart(data);
                return;
            }

            else
            {
                Node* temp = start;

                for(int i = 0; temp != nullptr && i < pos - 1; i++)
                    temp = temp->next;

                if(temp == nullptr)
                {
                    cout<<"Index out of Range...."<<endl;
                    return;
                }

                Node* node = new Node(data, temp->next);
                temp->next = node;
            }

            length++;
        }

        void insertAtStart(int data)
        {
            Node* node = new Node(data, start);
            start = node;
            length++;
        }

       void insertAtEnd(int data)
        {
            if (start == nullptr) // list empty
            {
                insertAtStart(data);
                return;
            }

            Node* temp = start;
            while (temp->next != nullptr)  // go to last node
                temp = temp->next;

            Node* node = new Node(data, nullptr); // new last node
            length++;
            temp->next = node;
        }

        bool search(int data)
        {
            Node* temp = start;

            while(temp != nullptr)
                if(temp->data == data) return true; else temp = temp->next;

            return false;
        }

        bool contentOfNode(int pos) 
        {
            Node* temp = start;

            for (int i = 0; i < pos && temp != nullptr; i++)
                temp = temp->next;

            if (temp == nullptr) {
                cout << "Position out of range!" << endl;
                return false;
            }

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

            Node* temp = start;
            while (temp != nullptr)
            {
                cout << "Data: " << temp->data << " | Next: " << temp->next << endl;
                temp = temp->next;
            }
            cout<<endl;
        }


        void popFront()
        {
            if(start == nullptr)
            {
                cout<<"List is empty";
                return;
            }

            Node* temp = start;
            start = start->next;
            temp->next = nullptr;
            delete temp;
            length--;
        }

        void popBack()
        {
            if(start == nullptr)
            {
                cout<<"List is empty";
                return;
            }

            if(start->next == nullptr)
            {
                popFront();
                return;
            }

            Node* temp = start;

            while(temp->next->next != nullptr)
                temp = temp->next;

            delete temp->next;
            temp->next = nullptr;
            length--;            
        }

        ~SLL()
        {
            while (start != nullptr)
            {
                Node* temp = start;
                start = start->next;
                delete temp;
            }

            length = 0;
        }


};

int main(void)
{
    SLL* list = new SLL();

    
    list->insertAtEnd(456);
    list->insertAtEnd(456);
    list->printContents();
    list->insertNode(69, 0);
    list->printContents();

    list->contentOfNode(0);

    cout<<(list->search(456));
    
    delete list;
    list = nullptr;


}