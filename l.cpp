#include<iostream>
using namespace std;
int main(){
    int se = 0,so = 0,n,q;
    cout << "enter a number"<< endl;
    cin >> n;
    while(n != 0){
        q = n%10;
        n = n/10;
        if(q%2 == 0){
            se += q;
        }else{
            so += q;
        }
    }
    cout<<se <<" "<< so;
}
