#include<iostream>
using namespace std;

int allindex(int a[], int n, int x,int b[],int c){
    if(n == 0){
        return 0;
    }
    int k = allindex(a+1, n-1,x,b,c);
    for(int i=0; i<k; i++){
        b[i] = b[i] + 1;
    }
    if(a[0] == x){
        for(int i = k; i>0; i--){
        b[i] = b[i-1];

        }
        b[0] = 0;
        k++;
        return k;
    }else{
    return k;

    }



}



int main(){
    int a[5], n, x,b[5],c= 0;
    cin >>n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> x;
    int k = allindex(a,n,x,b,c);
    for(int i=0; i<k; i++){
        cout<< b[i] << " ";
    }



}
