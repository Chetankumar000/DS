#include<iostream>
using namespace std;

int firstindexofnumber(int a[], int n, int x){
    if(n == 0){
        return -1;
    }
    if(a[0] == x){
        return 0;
    }
    int i = firstindexofnumber(a+1, n-1,x);
    if(i == -1){
        return -1;
    }else{
        return 1+ firstindexofnumber(a+1, n-1,x);

    }
}



int main(){
    int a[50], n, x;
    cin >>n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> x;
    int i = firstindexofnumber(a,n,x);
    cout << i;



}
