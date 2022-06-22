#include<iostream>
using namespace std;

int findunique(int a[],int n)
{
    for (int i=0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(i == j){
                continue;}
            else if (a[i] == a[j])
            {
                break;
            }
            else if(j == n-1 && a[i]!=a[j])
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
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int f = findunique(a,n);
    cout << f;


}
