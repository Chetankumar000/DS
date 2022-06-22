#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter a number" << endl;
    cin >> n;
    int i = 1;
    while(i <= n){
        int l = 1;
        while(l<= n-i){
            cout<<" ";
            l = l+1;
        }
        int j = 1;
        int k = i;
        while(j<=i){
            cout << k;
            j = j+ 1;
            k = k + 1;
        }
        cout << endl;
        i += 1;
    }
}
