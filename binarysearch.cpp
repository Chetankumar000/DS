#include<iostream>
using namespace std;

int binarysearch(int a[], int n, int k){
    int s=0, e= n-1, m;
    while(s<=e){
        m = (s+e)/2;
        if(a[m] == k){
            return m;
        }else if(k > a[m]){
            s = m+1;
        }else{
            e = m-1;
        }
    }
    return -1;
}



int main(){
    int n,k;
    cin >> n;
    int a[100];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    cin >> k;
    int b = binarysearch(a,n,k);
    cout << b;
}
