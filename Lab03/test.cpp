#include <iostream>
using namespace std;

void print(int a, int b)
{
    int arr[2] = {a, b};
    cout<<arr<<" "<<arr+1;
}

int main(void)
{
    print(2, 3);
}