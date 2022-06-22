#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of element of array :"<< endl;
    cin >> n;
    int a[100];
    if(n%2!=0){
    int j = 1;
    for (int i = 0; i<=n/2; i++)
        {
            a[i] = j;
            j= j+2;
        }
    int k =j-3;
    for(int i= n/2+1; i<n; i++){
        a[i] = k;
        k=k-2;

    }
    }else{
       int j = 1;
    for (int i = 0; i<n/2; i++)
        {
            a[i] = j;
            j= j+2;
        }
    int k =j-1;
    for(int i= n/2; i<n; i++){
        a[i] = k;
        k=k-2;

    }
    }

    for (int i=0; i<n;i++){
        cout << a[i] << endl;
    }
}
