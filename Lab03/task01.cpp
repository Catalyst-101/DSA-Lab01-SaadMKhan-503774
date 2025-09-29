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


// int main(void)
// {
//     SLL<int>* list = new SLL<int>();

//     list->insertAtStart(10);
//     list->insertAtStart(20);
//     list->insertAtStart(30);

//     list->printContents();

//     list->insertNode(99, 1);
//     list->insertNode(77, 3);

//     list->printContents();

//     cout<<"Count: "<<list->capacity()<<endl<<endl;

//     list->deleteByValue(99);

//     list->printContents();

//     list->deleteAtPosition(3);

//     list->printContents();

//     delete list;
//     list = nullptr;

// }

// class Zigzag
// {
//     public:

//         template <typename T>
//         static void zz(Node<T>* head)
//         {
//             bool l = true;

//             while (head && head->next)
//             {
//                 if (l && head->data > head->next->data)
//                     swap(head->data, head->next->data);

//                 else if (!l && head->data < head->next->data)
//                     swap(head->data, head->next->data);

//                 head = head->next;
//                 l = !l;
//             }
//         }
// };

// int main()
// {
//     SLL<int>* list = new SLL<int>();

//     list->insertAtEnd(4);
//     list->insertAtEnd(3);
//     list->insertAtEnd(7);
//     list->insertAtEnd(8);
//     list->insertAtEnd(6);
//     list->insertAtEnd(2);
//     list->insertAtEnd(1);

//     cout << "Before:" << endl;
//     list->printContents();

//     Zigzag::zz(list->getStart());

//     cout << "After:" << endl;
//     list->printContents();

//     return 0;
// }

int main(void)
{
    SLL<int>* list = new SLL<int>();

    list->insertAtEnd(5);
    list->insertAtEnd(0);
    list->insertAtEnd(3);
    list->insertAtEnd(7);
    list->insertAtEnd(7);
    list->insertAtEnd(4);
    list->insertAtEnd(0);
    list->insertAtEnd(5);
    list->insertAtEnd(0);
    list->insertAtEnd(3);
    list->insertAtEnd(7);
    list->insertAtEnd(7);
    list->insertAtEnd(4);

    int r = 3, c = 5;

    int** mat = new int*[r];
    
    for(int i = 0; i < r; i++)
        mat[i] = new int[c];

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            mat[i][j] = -1;

    Node<int>* curr = list->getStart();

    int top = 0, bottom = r - 1, left = 0, right = c - 1;

    while (curr && top <= bottom && left <= right)
    {
        for (int j = left; j <= right && curr; j++) 
        {
            mat[top][j] = curr->data;
            curr = curr->next;
        }

        top++;

        for (int i = top; i <= bottom && curr; i++) 
        {
            mat[i][right] = curr->data;
            curr = curr->next;
        }

        right--;

        for (int j = right; j >= left && curr; j--) 
        {
            mat[bottom][j] = curr->data;
            curr = curr->next;
        }

        bottom--;

        for (int i = bottom; i >= top && curr; i--) 
        {
            mat[i][left] = curr->data;
            curr = curr->next;
        }

        left++;
    }

    cout<<"Circular Mat\n"<<endl;
    
    for(int i = 0; i < r; i++) 
    {
        for(int j = 0; j < c; j++)
            cout<<mat[i][j]<<(( mat[i][j] == -1 ) ? "  " : "   ");

        cout<<endl;
    }

    for(int i = 0; i < r; i++)
        delete[] mat[i];

    delete[] mat;
    delete list;

    list = nullptr;
    mat = nullptr;
}