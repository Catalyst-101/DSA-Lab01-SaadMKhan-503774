#include<iostream>
#include<vector>
using namespace std;

vector<int> alli(int arr[], int size, int key)
{
    vector<int> temp;

    for(int i = 0; i < size; i++)
        if(arr[i] == key)
            temp.push_back(i);

    return temp;
}

int main()
{
    int a[] = {1, 1, 2, 2, 3, 3};

    vector<int> p = alli(a, 6, 2);

    if(p.empty())
        cout << "The key isnt present";
    else
        for(int x : p) cout << x << " ";

    cout << endl;

    p = alli(a, 6, 9);

    if(p.empty())
        cout << "The key " << 9 << " isnt present";
    else
        for(int x : p) cout << x << " ";
        
    cout << endl;

    int c[] = {};
    if(sizeof(c) / sizeof(c[0]) == 0)
        cout << "The size of the array is 0";
    else
    {
        p = alli(c, 0, 9);
        if(p.empty())
            cout << "The key " << 9 << " isnt present";
        else
            for(int x : p) cout << x << " ";
    }
}
