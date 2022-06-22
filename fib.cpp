#include<iostream>
using namespace std;

bool fib(int n)
{
    int a = 0;
    int b = 1;
    if (n == a)
    {
        return true;
    }
    for (; a<= n;)
    {
        int c = a+b;
        a = b;
        b = c;
        if (a == n)
        {
            return true;
        }
    }
    return false;
}


int main()
{
    int n;
    cin >> n;
    bool i = fib(n);
    if (i)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
}
