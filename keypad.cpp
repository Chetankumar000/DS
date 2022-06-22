#include<iostream>
using namespace std;

string getstring(int d)
{
    if(d == 2)
    {
        return "abc";
    }
    else if(d == 3)
    {
        return "def";
    }
    else if(d == 4)
    {
        return "ghi";
    }
    else if(d == 5)
    {
        return "jkl";
    }
    else if(d==6)
    {
        return "mno";
    }
    else if(d==7)
    {
        return "pqrs";
    }
    else if(d == 8)
    {
        return "tuv";
    }
    else if(d==9)
    {
        return "wxyz";
    }
    else
    {
        return " ";
    }
}

int keypad(int n, string o[])
{
    if(n == 0)
    {
        o[0] = "";
        return 1;
    }
    int c = keypad(n/10, o);
    string s = getstring(n%10);
    for(int i = 0; i< s.size()-1;i++)
    {
        for(int j = 0; j< c; j++)
        {
            o[j +(i+1) * c] = o[j];
        }
    }
    int k = 0;
    for(int i = 0; i < s.size(); i++){
        for (int j = 0; j< c; j++){
            o[k] += s[i];
            k++;
        }
    }
return c*s.size();
}


int main()
{
    int n;
    cin >> n;
    string * o = new string[1000];
    int c = keypad(n,o);
    for (int i=0; i<c; i++)
    {
        cout << o[i]<<endl;
    }


}
