#include<iostream>
using namespace std;

int lastindex(int a[], int n, int x){
    if(n == 0){
        return -1;
    }
    int k = lastindex(a, n-1,x);
    if(a[n-1] == x){
        k = n-1;
        return k;
    }else{
        return k;
    }
}

int main(){
    int a[5], n, x,c= 0;
    cin >>n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> x;
    int k = lastindex(a,n,x);
    cout << k;

}

