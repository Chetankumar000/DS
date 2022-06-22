#include<iostream>
using namespace std;

int friendspairing(int n){
    if(n == 0 or n==1){
        return 1;
    }
    int a = friendspairing(n-1);
    int b = (n-1) * friendspairing(n-2);
    return a+b;
}

int main(){
    int n;
    cin>> n;
    int a = friendspairing(n);
    cout << a;
}
