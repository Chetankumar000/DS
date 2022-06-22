#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int i =1;
    while (i<=n){
        int j = 1;
        char k =  'A' + n - i ;
        while(j<=i){
            cout << k;
            j ++;
            k ++;
        }
        cout <<endl;
        i ++;
    }

}
