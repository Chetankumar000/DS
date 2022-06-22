#include<iostream>
using namespace std;

int lastocc(int a[],int  n ,int x){
    if (n == 0){
        return -1;
    }
    int c = lastocc(a, n-1, x);
    if(a[n-1] == x){
        return n-1;
    }

    return c;
}



int main(){
    int n,x;
    cin >> n;
    int a[10];
    for(int i = 0; i<n ; i++){
        cin >> a[i];
    }
    cin >> x;
    int c = lastocc(a,n,x);
    cout << c;

}
