// #include<iostream>
// using namespace std;

// template <typename T>
// class Node 
// {
//     public:

//         T data;
//         Node* next;

//         Node(T data, Node* next) 
//         {
//             this->data = data;
//             this->next = next;
//         }
// };

// template <typename T>
// class SLL 
// {
//     private:

//         Node<T>* start;
//         int length = 0;

//     public:

//         SLL() {start = nullptr;}

//         void insertNode(T data, int pos) 
//         {
//             if (pos < 0 || pos > length) 
//             {
//                 cout << "Index out of Range...." << endl;
//                 return;
//             }

//             if (pos == 0) 
//             {
//                 Node<T>* node = new Node<T>(data, start);
//                 start = node;
//                 length++;
//                 return;
//             }

//             Node<T>* temp = start;

//             for (int i = 0; temp != nullptr && i < pos - 1; i++)
//                 temp = temp->next;

//             Node<T>* node = new Node<T>(data, temp->next);
//             temp->next = node;
//             length++;
//         }

//         void insertAtStart(T data) 
//         {
//             insertNode(data, 0);
//         }

//         void insertAtEnd(T data) 
//         {
//             insertNode(data, length);
//         }

//         bool search(T data) 
//         {
//             Node<T>* temp = start;

//             while (temp != nullptr)
//                 if (temp->data == data) return true; else temp = temp->next;

//             return false;
//         }

//         bool contentOfNode(int pos) 
//         {
//             if (pos < 0 || pos >= length) 
//             {
//                 cout << "Position out of range!" << endl;
//                 return false;
//             }

//             Node<T>* temp = start;

//             for (int i = 0; i < pos && temp != nullptr; i++)
//                 temp = temp->next;

//             cout << "Node at position " << pos << " = " << temp->data << endl;
//             return true;
//         }

//         void printContents() 
//         {
//             if (start == nullptr) 
//             {
//                 cout << "List is Empty" << endl;
//                 return;
//             }

//             Node<T>* temp = start;
//             while (temp != nullptr) 
//             {
//                 cout << "Data: " << temp->data << " | Next: " << temp->next << endl;
//                 temp = temp->next;
//             }
//             cout << endl;
//         }

//         void updateNode(int pos, T newData) 
//         {
//             if (pos < 0 || pos >= length) 
//             {
//                 cout << "Position out of range!" << endl;
//                 return;
//             }

//             Node<T>* temp = start;

//             for (int i = 0; i < pos; i++)
//                 temp = temp->next;

//             temp->data = newData;
//         }

//         void deleteAtPosition(int pos) 
//         {
//             if (pos < 0 || pos >= length || start == nullptr) 
//             {
//                 cout << "Invalid position!" << endl;
//                 return;
//             }

//             if (pos == 0) 
//             {
//                 popFront();
//                 return;
//             }

//             Node<T>* temp = start;

//             for (int i = 0; i < pos - 1; i++) 
//             {
//                 temp = temp->next;
//             }

//             Node<T>* toDelete = temp->next;
//             temp->next = toDelete->next;
//             delete toDelete;
//             length--;
//         }

//         void deleteByValue(T data) 
//         {
//             while (start != nullptr && start->data == data)
//                 popFront();

//             Node<T>* temp = start;
//             while (temp != nullptr && temp->next != nullptr) 
//                 if (temp->next->data == data)
//                 {
//                     Node<T>* toDelete = temp->next;
//                     temp->next = temp->next->next;
//                     delete toDelete;
//                     length--;
//                 } 
//                 else
//                     temp = temp->next;
//         }

//         void popFront() 
//         {
//             if (start == nullptr) 
//             {
//                 cout << "List is empty";
//                 return;
//             }

//             Node<T>* temp = start;
//             start = start->next;
//             temp->next = nullptr;
//             delete temp;
//             length--;
//         }

//         void popBack() 
//         {
//             if (start == nullptr) 
//             {
//                 cout << "List is empty";
//                 return;
//             }

//             if (start->next == nullptr) 
//             {
//                 popFront();
//                 return;
//             }

//             Node<T>* temp = start;

//             while (temp->next->next != nullptr)
//                 temp = temp->next;

//             delete temp->next;
//             temp->next = nullptr;
//             length--;
//         }

//         bool isEmpty() 
//         {
//             return length == 0;
//         }

//         int capacity() 
//         {
//             return length;
//         }

//         T get(int pos) 
//         {
//             if (pos < 0 || pos >= length) 
//             {
//                 throw out_of_range("Position out of range!");
//             }

//             Node<T>* temp = start;

//             for (int i = 0; i < pos; i++)
//                 temp = temp->next;

//             return temp->data;
//         }

//         Node<T>* getStart()
//         {
//             return start;
//         }

//         ~SLL() 
//         {
//             while (start != nullptr) 
//             {
//                 Node<T>* temp = start;
//                 start = start->next;
//                 delete temp;
//             }
            
//             length = 0;
//         }
// };

// class Sorta
// {
//     public:
//         template <typename T>
//         static void mySort(SLL<SLL<T>*>* list)
//         {
//             Node<SLL<T>*>* temp1 = list->getStart();

//             while (temp1 != nullptr)
//             {
//                 Node<SLL<T>*>* temp2 = temp1->next;

//                 while (temp2 != nullptr)
//                 {
//                     if (temp1->data->capacity() > temp2->data->capacity())
//                     {
//                         SLL<T>* t = temp1->data;
//                         temp1->data = temp2->data;
//                         temp2->data = t;
//                     }

//                     temp2 = temp2->next;
//                 }

//                 temp1 = temp1->next;
//             }
//         }
// };


// // int main(void)
// // {
// //     SLL<int>* list1 = new SLL<int>();
// //     SLL<int>* list2 = new SLL<int>();
// //     SLL<int>* list3 = new SLL<int>();
// //     SLL<int>* list4 = new SLL<int>();
// //     SLL<int>* list5 = new SLL<int>();

// //     list1->insertAtEnd(10);
// //     list1->insertAtEnd(20);

// //     list2->insertAtEnd(5);
// //     list2->insertAtEnd(15);
// //     list2->insertAtEnd(25);
// //     list2->insertAtEnd(35);

// //     list3->insertAtEnd(42);

// //     list4->insertAtEnd(7);
// //     list4->insertAtEnd(14);
// //     list4->insertAtEnd(21);

// //     list5->insertAtEnd(100);
// //     list5->insertAtEnd(200);
// //     list5->insertAtEnd(300);
// //     list5->insertAtEnd(400);
// //     list5->insertAtEnd(500);

// //     cout<<"list1: "<<endl;
// //     list1->printContents();
// //     cout<<"list2: "<<endl;
// //     list2->printContents();
// //     cout<<"list3: "<<endl;
// //     list3->printContents();
// //     cout<<"list4: "<<endl;
// //     list4->printContents();
// //     cout<<"list5: "<<endl;
// //     list5->printContents();

// //     cout<<endl;

// //     SLL<SLL<int>*>* megalist = new SLL<SLL<int>*>();

// //     megalist->insertAtEnd(list1);
// //     megalist->insertAtEnd(list2);
// //     megalist->insertAtEnd(list3);
// //     megalist->insertAtEnd(list4);
// //     megalist->insertAtEnd(list5);
    
// //     cout<<"Mega List:"<<endl;
// //     megalist->printContents();

// //     cout<<"After Sorting: "<<endl;
// //     Sorta::mySort(megalist);
// //     megalist->printContents();

// //     for(int i = 0; i < megalist->capacity(); i++)
// //     {
// //         cout<<"list"<<(i+1)<<": "<<endl;
// //         megalist->get(i)->printContents();
// //     }

//     // for (int i = 0; i < megalist->capacity(); i++)
//     //     delete megalist->get(i);

//     // delete megalist;

// // }

// class FreqSort
// {
//     public:

//         template <typename T>
//         static void mySort(SLL<SLL<T>*>* list)
//         {
//             int a = list->capacity();
//             int l[a];
//             int max = 0;

//             for(int i = 0; i < a; i++)
//             {
//                 l[i] = list->get(i)->capacity();
//                 if(l[i] > max)
//                     max = l[i];
//             }

//             int* farr = new int[max+1];
//             for(int i = 0; i <= max; i++)
//                 farr[i] = 0;

//             for(int i = 0; i < a; i++)
//                 farr[l[i]]++;

//             for(int i = 0; i < a-1; i++)
//             {
//                 for(int j = 0; j < a-i-1; j++)
//                 {
//                     int len1 = list->get(j)->capacity();
//                     int len2 = list->get(j+1)->capacity();

//                     if(farr[len1] > farr[len2] || 
//                     (farr[len1] == farr[len2] && len1 > len2))
//                     {
//                         SLL<T>* tmp = list->get(j);
//                         list->updateNode(j, list->get(j+1));
//                         list->updateNode(j+1, tmp);
//                     }
//                 }
//             }

//             delete[] farr;
//         }
// };


// int main(void)
// {
//     SLL<int>* list1 = new SLL<int>();
//     SLL<int>* list2 = new SLL<int>();
//     SLL<int>* list3 = new SLL<int>();
//     SLL<int>* list4 = new SLL<int>();
//     SLL<int>* list5 = new SLL<int>();

//     list1->insertAtEnd(10);
//     list1->insertAtEnd(20);

//     list2->insertAtEnd(5);
//     list2->insertAtEnd(15);
//     list2->insertAtEnd(25);
//     list2->insertAtEnd(35);

//     list3->insertAtEnd(42);
//     list3->insertAtEnd(452);

//     list4->insertAtEnd(7);
//     list4->insertAtEnd(14);
//     list4->insertAtEnd(21);
//     list4->insertAtEnd(21234);

//     list5->insertAtEnd(100);
//     list5->insertAtEnd(200);
//     list5->insertAtEnd(300);
//     list5->insertAtEnd(400);
//     list5->insertAtEnd(500);

//     SLL<SLL<int>*>* megalist = new SLL<SLL<int>*>();
//     megalist->insertAtEnd(list1);
//     megalist->insertAtEnd(list2);
//     megalist->insertAtEnd(list3);
//     megalist->insertAtEnd(list4);
//     megalist->insertAtEnd(list5);

//     cout<<"Before Sorting:"<<endl;
//     for(int i = 0; i < megalist->capacity(); i++)
//         megalist->get(i)->printContents();

//     FreqSort::mySort(megalist);

//     cout<<"After Sorting:"<<endl;
//     for(int i = 0; i < megalist->capacity(); i++)
//         megalist->get(i)->printContents();

//     for (int i = 0; i < megalist->capacity(); i++)
//         delete megalist->get(i);

//     delete megalist;
// }

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
class CLL
{
private:
    Node<T>* start;
    Node<T>* tail;
    int length = 0;

public:
    CLL()
    {
        start = nullptr;
        tail = nullptr;
    }

    void insertAtStart(T data)
    {
        Node<T>* node = new Node<T>(data, nullptr);
        if (start == nullptr)
        {
            start = node;
            tail = node;
            node->next = start;
        }
        else
        {
            node->next = start;
            start = node;
            tail->next = start;
        }
        length++;
    }

    void insertAtEnd(T data)
    {
        Node<T>* node = new Node<T>(data, nullptr);
        if (start == nullptr)
        {
            start = node;
            tail = node;
            node->next = start;
        }
        else
        {
            tail->next = node;
            tail = node;
            tail->next = start;
        }
        length++;
    }

    void insertAtPosition(T data, int pos)
    {
        if (pos < 0 || pos > length) return;
        if (pos == 0) { insertAtStart(data); return; }
        if (pos == length) { insertAtEnd(data); return; }
        Node<T>* temp = start;
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;
        Node<T>* node = new Node<T>(data, temp->next);
        temp->next = node;
        length++;
    }

    void deleteAtPosition(int pos)
    {
        if (pos < 0 || pos >= length || start == nullptr) return;
        if (pos == 0)
        {
            if (length == 1)
            {
                delete start;
                start = nullptr;
                tail = nullptr;
            }
            else
            {
                Node<T>* temp = start;
                start = start->next;
                tail->next = start;
                delete temp;
            }
            length--;
            return;
        }
        Node<T>* temp = start;
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;
        Node<T>* toDelete = temp->next;
        temp->next = toDelete->next;
        if (toDelete == tail) tail = temp;
        delete toDelete;
        length--;
    }

    void deleteByValue(T data)
    {
        if (start == nullptr) return;
        if (start->data == data)
        {
            deleteAtPosition(0);
            return;
        }
        Node<T>* temp = start;
        do
        {
            if (temp->next->data == data)
            {
                Node<T>* toDelete = temp->next;
                temp->next = toDelete->next;
                if (toDelete == tail) tail = temp;
                delete toDelete;
                length--;
                return;
            }
            temp = temp->next;
        } while (temp != start);
    }

    void updateNode(int pos, T newData)
    {
        if (pos < 0 || pos >= length) return;
        Node<T>* temp = start;
        for (int i = 0; i < pos; i++)
            temp = temp->next;
        temp->data = newData;
    }

    void printContents()
    {
        if (start == nullptr)
        {
            cout << "List is Empty" << endl;
            return;
        }
        Node<T>* temp = start;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != start);
        cout << endl;
    }

    bool search(T data)
    {
        if (start == nullptr) return false;
        Node<T>* temp = start;
        do
        {
            if (temp->data == data) return true;
            temp = temp->next;
        } while (temp != start);
        return false;
    }

    void rotateLeft(int n)
    {
        if (start == nullptr || n <= 0) return;
        n = n % length;
        for (int i = 0; i < n; i++)
        {
            start = start->next;
            tail = tail->next;
        }
    }

    int capacity()
    {
        return length;
    }

    bool isEmpty()
    {
        return length == 0;
    }

    Node<T>* getStart()
    {
        return start;
    }

    Node<T>* getTail()
    {
        return tail;
    }

    T get(int pos)
    {
        if (pos < 0 || pos >= length) throw out_of_range("Position out of range!");
        Node<T>* temp = start;
        for (int i = 0; i < pos; i++)
            temp = temp->next;
        return temp->data;
    }

    ~CLL()
    {
        if (start == nullptr) return;
        Node<T>* temp = start->next;
        while (temp != start)
        {
            Node<T>* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        delete start;
        start = nullptr;
        tail = nullptr;
        length = 0;
    }
};

int main(void)
{
    CLL<string>* cl = new CLL<string>();
    cl->insertAtEnd("hello");
    cl->insertAtEnd("im");
    cl->insertAtEnd("saad");
    cl->insertAtEnd("khan");
    cl->insertAtEnd("503774");

    cout << "Original CLL: "<<endl;
    cl->printContents();

    cl->rotateLeft(2);

    cout << "Rotated CLL: "<<endl;
    cl->printContents();

    delete cl;
}
