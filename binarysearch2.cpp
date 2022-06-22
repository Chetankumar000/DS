#include<iostream>
using namespace std;

int binarysearch(int a[], int x, int s, int e){
    if(s > e){
        return -1;
    }
    int m = (s+e)/2;
    if(x > a[m]){
        return binarysearch(a,x,m+1,e);
    }else if( x< a[m]){
        return binarysearch(a,x,s,m-1);
    }else{
        return m;
    }
}

int main(){
    int n, a[50],x;
    cin >>n;
    for(int i=0;i <n;i++){
        cin >> a[i];
    }
    cin >> x;
    int c = binarysearch(a,x,0,n-1);
    cout << c;
}
