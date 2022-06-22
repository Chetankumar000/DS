#include<iostream>
using namespace std;

int main()
{
    int p,c,i=1,n;
    cin >> n;
    bool d = true;
    cin >>p;
    while(i<n)
    {
        cin >> c;
        if (c == p)
        {
            cout << "Not a valid sequence";
            break;
        }
        else if(c>p)
        {
            d = false;
            p = c;
            if (i == n-1){
                cout << "Valid Sequence";
            }
        }
        else
        {
            if (d == false)
            {
                cout << "Not a valid sequence";
                break;
            }else if (i == n-1){
                cout << "Valid Sequence";
            }
            d = true;
            p =c;
        }
        i++;
    }
}
