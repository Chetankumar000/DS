#include<iostream>
using namespace std;

int multiplication(int m,int n){
    if(m == 0 || n==0){
        return 0;
    }
    int s = multiplication(m, n-1);
    return m+s;
}



int main(){
    int m,n;
    cin>>m>>n;
    cout << multiplication(m,n);
}
