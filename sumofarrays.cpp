#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[50];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    int m,o;
    cin >> m;
    int b[50];
    for(int i=0; i<m; i++)
    {
        cin >> b[i];
    }
    if(n>m)
    {
        o = n+1;
    }
    else
    {
        o = m+1;
    }
    int c[10];
    int k = o-1,t=0;
    int i = n-1, j = m-1;
    for(; i>=0 && j>=0; i--, j--)
    {
        int r = a[i] + b[j] + t;
        if(r > 9)
        {
            int q = r%10;
            t = r/10;
            c[k] = q;
            k--;
            if(k == 0)
            {
                c[j] = t;
            }
            continue;
        }

        c[k] = r;
        k--;
    }
    while(i>=0)
    {
        int r = a[i] + t;
        t = 0;
        if(r > 9)
        {
            int q = r%10;
            t = r/10;
            c[k] = q;
            if(i == 0)
            {
                c[i] = t;
            }
            k--;
            i--;
            continue;
        }
        if(i == 0)
        {
            c[i] = t;
        }
        c[k] = r;
        k--;
        i--;
    }
    while(j>=0)
    {
        int r = b[j] + t;
        t = 0;
        if(r > 9)
        {
            int q = r%10;
            t = r/10;
            c[k] = q;

            if(j == 0)
            {
                c[j] = t;
            }
            k--;
            j--;
            continue;
        }

        if(j == 0)
        {
            c[j] = t;
        }
        c[k]= r;
        k--;
        j--;
    }
    for(int u=0; u<o; u++)
    {
        cout << c[u];
    }

}
