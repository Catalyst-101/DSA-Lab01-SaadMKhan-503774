#include <iostream>
using namespace std;

class MyCustomArray 
{
    private:

        int* MyArr;
        int size;

    public:

        MyCustomArray(int n) 
        {
            size = n;
            MyArr = new int[size];
        }

        void input() 
        {
            cout << "Enter " << size << " integers:" << endl;

            for (int i = 0; i < size; i++)
                cin >> MyArr[i];
        }

        int getSum() 
        {
            int sum = 0;

            for (int i = 0; i < size; i++)
                sum += MyArr[i];

            return sum;
        }

        double getAverage() 
        {
            return (size == 0) ? 0.0 : (double)(getSum()) / size;
        }

        void displayResults() 
        {
            cout << "The Sum is:  " << getSum() << endl;
            cout << "The Average is: " << getAverage() << endl;
        }

        ~MyCustomArray() 
        {
            delete[] MyArr;
        }
};

int main() 
{
    int n;
    cout << "Plz Enter size of array: ";
    cin >> n;

    MyCustomArray* obj = new MyCustomArray(n);

    obj->input();
    obj->displayResults();

    delete obj;

    return 0;
}
