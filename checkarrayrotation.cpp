
#include<iostream>
using namespace std;

int findmin(int a[], int n)
{
    int m = INT_MAX;
    for(int i = 0; i<n; i++)
    {
        if(a[i] < m)
        {
            m = a[i];
        }

    }
    return m;
}
int checkarrayrotation(int a[], int m, int n)
    {
        int k = 0,c,j=0;
        while (a[0] != m)
        {
            c = a[0];
            for(int i=0; i<n; i++)
            {
                if(i==n-1)
                {
                    a[i] = c;
                    continue;
                }
                a[i] = a[i+1];

            }
            j++;
            k++;
        }

        return k;

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
        int k = checkarrayrotation(a,m,n);
        cout << k;
    }
