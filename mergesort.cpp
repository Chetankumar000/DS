#include<iostream>
using namespace std;

void mergesort(int x[], int y[],int z[],  int a, int b)
{
    int i = 0, j =0, c=0;
    while(i<a && j<b){
       if(x[i] < y[j] ){
            z[c] = x[i];
            c++;
            i++;
       }
       else if(y[j] < x[i]){
            z[c] = y[j];
            c++;
            j++;
       }
        }
       while(i < a) {
        z[c] = x[i];
        i++;
        c++;
        }

        while(j < b) {
        x[c] = y[j];
        j++;
        c++;
    }

}

int main()
{
    int a,b;
    cin >> a;
    int x[50], y[50], z[50];
    for(int i=0; i< a; i++)
    {
        cin >> x[i];
    }
    cin>> b;
    for(int j=0; j<b; j++)
    {
        cin >> y[j];
    }
    mergesort(x,y,z,a,b);
    for(int j=0; j<a+b; j++)
    {
        cout << z[j] << " ";
    }

}
