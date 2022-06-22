#include<iostream>
using namespace std;

int main()
{
    int n,c;
    cin >>n>>c;
    if(c == 1)
    {
        int ans = 0;
        for(int i= 1; i<=n; i++)
        {
            ans = ans + i;
        }
        cout << ans;
    }
    else if(c ==2)
    {
        int ans = 1;
        for (int i=1; i<= n; i++)
        {
            ans = ans*i;
        }
        cout << ans;
    }
    else
    {
        cout<<-1;
    }
}
