#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int i = 1;
    while (i<= n){
        int j = 1;
        while(j<= n-i){
            cout<< " ";
            j ++;
        }
        int k = 1;
        int l = i;
        while(k<= i){
            cout<< l;
            k ++;
            l++;
        }
        int m =1;
        int b = (2*i)-2;
        while(m <= i-1){
            cout << b;
            m++;
            b--;
        }
        cout<< endl;
        i++;
    }
}
