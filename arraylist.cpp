#include<iostream>
using namespace std;

class ArrayList
{
private:
    int size;
    int length;
    int* arr;

    void resize()
    {
        int newSize = size * 2;
        int* newArr = new int[newSize];

        for(int i = 0; i < length; i++)
            newArr[i] = arr[i];
            
        delete [] arr;
        arr = newArr;
        size = newSize;
    }

    void makeRoom(int pos)
    {
        if(isFull())
            resize();
        for(int i = length - 1; i >= pos; i--)
            arr[i + 1] = arr[i];
    }

    void fillRoom(int pos)
    {
        for(int i = pos; i < length - 1; i++)
            arr[i] = arr[i + 1];
    }

public:

    ArrayList(int size = 100)
    {
        this->size = size;
        arr = new int[size];
        length = 0;
    }

    ~ArrayList()
    {
        delete [] arr;
    }

    bool isEmpty()
    {
        return length == 0;
    }

    bool isFull()
    {
        return size == length;
    }

    void insertAtEnd(int value)
    {
        if(isFull())
            resize();
        arr[length++] = value;
    }

    void insertAtPos(int value, int pos)
    {
        if(pos >= 0 && pos <= length)
            if(pos == length)
                insertAtEnd(value);
            else
            {
                makeRoom(pos);
                arr[pos] = value;
                length++;
            }
        else
            cout<<"Invalid Position."<<endl;
    }

    int search(int value)
    {
        for(int i = 0; i < length; i++)
            if(arr[i] == value)
                return i;
        return -1;
    }

    void Delete(int pos)
    {
        if(pos >= 0 && pos < length)
        {
            fillRoom(pos);
            length--;
        }
        else
            cout<<"Index out of range"<<endl;
    }

    void deleteByValue(int value)
    {
        int pos = search(value);
        if(pos != -1)
            Delete(pos);
        else
            cout<<"Value not found."<<endl;
    }

    void deleteAll(int value)
    {
        int i = 0;
        while(i < length)
        {
            if(arr[i] == value)
                Delete(i);
            else
                i++;
        }
    }

    int getAt(int pos)
    {
        if(pos >= 0 && pos < length)
            return arr[pos];
        else
            cout<<"Index out of range"<<endl;
    }

    void updateAt(int pos, int newVal)
    {
        if(pos >= 0 && pos < length)
            arr[pos] = newVal;
        else
            cout<<"Index out of range"<<endl;
    }

    void clear()
    {
        length = 0;
    }

    int getLength()
    {
        return length;
    }

    int getCapacity()
    {
        return size;
    }

    void printList()
    {
        if(!isEmpty())
        {
            for(int i = 0; i < length; i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
        else
            cout<<"List is Empty"<<endl;
    }
};
