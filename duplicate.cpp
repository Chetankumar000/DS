#include<iostream>
using namespace std;

int duplicate(int a[],int n)
{
    for (int i=0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(i == j)
            {
                continue;
            }
            else if (a[i] == a[j])
            {
                return a[i];
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a[100];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    int d = duplicate(a,n);
    cout << d;


}
