#include <iostream>
using namespace std;

int main(void)
{
    int myArr[5] = {3, 6, 9, 12, 15};
    int* ptrArr = myArr;

    for(int i = 0; i < 5; i++)
        cout<<*(ptrArr + i)<<" ";
    
}

