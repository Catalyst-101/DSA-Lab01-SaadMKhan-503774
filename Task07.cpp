#include<iostream>
using namespace std;

int* alli(int arr[], int key, int size, int &count)
{
    int* temp = new int[size];
    int a = 0;

    for(int i = 0; i < size; i++)
        if(key == arr[i])
            temp[a++] = i;

    count = a;

    return temp;
}

int main(void)
{
    int a[] = {1, 1, 2, 2, 3, 3};
    int b;
    int *p = alli(a, 2, 6, b);

    // Multiple occurance 
    if(b == 0)
        cout<<"The key isnt present";
    else
        for(int i = 0; i < b; i++)
            cout<<*(p+i)<<" ";

    cout<<endl;

    // no key present
    p = alli(a, 9, 6, b); 
    if(b == 0)
        cout<<"The key "<<9<<" isnt present";
    else
        for(int i = 0; i < b; i++)
            cout<<*(p+i)<<" ";

    cout<<endl;

    // empty array
    int c[0];
    if(sizeof(c) == 0)
        cout<<"The size of the array is 0";
    else
    {
        p = alli(a, 9, 6 ,b);
        
        if(b == 0)
            cout<<"The key "<<9<<" isnt present";
        else
            for(int i = 0; i < b; i++)
                cout<<*(p+i)<<" ";
    }


    delete[] p;
}
