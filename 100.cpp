#include<iostream>
using namespace std;

void printarray(int a[], int n)
{
    for (int i =0 ; i< n; i++)
    {
        cout << a[i] <<" ";
    }
}


int main()
{
    int n =5, i= 0, j=n-1 ;
    int a[5] = {0,1,1,0,0};
    while(i<j)
    {
        if(a[i]== 1 && a[j] == 1)
        {
            j--;
            continue;
        }
        else if(a[i] == 1 && a[j]==0)
        {
            a[i] = 0;
            a[j] = 1;

        }
        i++;

    }
    printarray(a, n);
}
