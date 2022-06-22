#include<iostream>
using namespace std;

int digits(int n){
    if(n <= 9){
        return 1;
    }
    int i = 1 + digits(n/10);
    return i;
}

int main(){
    int n;
    cin >> n;
    int i = digits(n);
    cout << i <<" ";



}
