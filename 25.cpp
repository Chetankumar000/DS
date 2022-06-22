#include<iostream>
using namespace std;

int main(){
    int n,a;
    cin >> n;
    for (int i=1; i<=n;i++){
        if(i*i <= n){
            a = i;
        }
    }
    cout << a;
}
