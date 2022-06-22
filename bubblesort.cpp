#include<iostream>
using namespace std;


void bubblesort(int a[],int n){
    int s = 0, e = n-1;
    while(s<e){
        for(int i = 0; i< e; i++){
            if(a[i] > a[i+1]){
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
        e--;
    }
}




int main(){
    int n;
    cin >> n;
    int a[100];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    bubblesort(a,n);
    for(int i=0; i<n;i++){
        cout<<a[i]<<" ";
    }
}



