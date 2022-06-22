
#include<iostream>
using namespace std;

int findmin(int a[], int n)
{
    int m = INT_MAX,l;
    for(int i = 0; i<n; i++)
    {
        if(a[i] < m)
        {
            m = a[i];
            l = i;
        }

    }
    return l;
}


    int main()
    {
        int n;
        cin >> n;
        int a[50];
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }
        int m = findmin(a,n);
        cout << m;
    }
