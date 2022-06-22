#include<iostream>
using namespace std;

int main(){
    char a;
    cout << "enter a character" << endl;
    cin >> a;
    if(a >= 65 && a <= 90)
    {
        cout << "1";
    }
    else if(a >= 97 && a <= 122)
    {
        cout << "0";
    }
    else
    {
        cout << "-1";
    }
}
