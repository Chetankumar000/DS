#include<iostream>
using namespace std;

int countzero(int n){
    if(n == 0){
        return 0;
    }
    int z = countzero(n/10);
    if(n%10 == 0){
        return 1+z;
    }else{
    return z;
    }
}



int main(){
    int n;
    cin >> n;
    int z = countzero(n);
    cout<<z;
}
