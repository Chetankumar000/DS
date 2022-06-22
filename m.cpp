#include<iostream>
using namespace std;

int main(){
    int x,n,m= 1;
    cout << "enter x and n" << endl;
    cin >> x >> n;
    while(n!=0){
        m = m*x;
        n -=1;
    }
    cout << m;
}
