#include<iostream>
using namespace std;

int main()
{
    int n,x,c=0;
    cin >> n;
    int a[100];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    cin >>x;
    for (int i= 0; i<n-2; i++)
    {
        for (int j=i+1; j<n-1; j++)
        {
            for(int k=j+1; k<n; k++){
            if ((a[i]+a[j]+a[k]) == x)
            {
                c++;
            }
            }
    }

    }
    cout <<c;
}
