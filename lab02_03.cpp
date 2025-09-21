#include <iostream>
using namespace std;

void swap1(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap2(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap3(int** a, int** b)
{
    int* temp = *a;
    *a = *b;
    *b = temp;
}

void swap4(int** a, int** b)
{
    int temp = **a;
    **a = **b;
    **b = temp;
}

int main(void)
{
    int a = 4352, b = 3525;
    int* pa = &a;
    int* pb = &b;
    int** ppa = &pa;
    int** ppb = &pb;

    cout << "Before swap: a: " << a << ", b: " << b << endl;
    swap1(a, b);
    cout << "After swap1: a: " << a << ", b: " << b << endl;
    swap2(pa, pb);
    cout << "After swap2: a: " << a << ", b: " << b << endl;
    swap4(ppa, ppb);
    cout << "After swap4: a: " << a << ", b: " << b << endl;
    swap3(ppa, ppb);
    cout << "After swap3: a: " << *pa << ", b: " << *pb << endl;
}

