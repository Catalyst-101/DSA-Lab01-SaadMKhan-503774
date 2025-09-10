#include <iostream>
using namespace std;

int find(string s1, string s2)
{
    for(int i = 0; i <= s1.length() - s2.length(); i++)
        if(s1.substr(i, s2.length()) == s2)
            return i;
    return -1;
}

int main(void)
{
    string s1 = "Hello My Name is Saad Muhammad Khan";
    string s[4] = {"Hello", "Khan", "Ali", ""};

    for(int i = 0; i < 4; i++)
        if(s[i].length() == 0)
            cout<<"The smaller string is empty"<<endl;
        else if(find(s1, s[i]) == -1)
            cout<<"Index not found"<<endl;
        else
            cout<<"Index is: "<<find(s1, s[i])<<endl;

    return 0;
}
