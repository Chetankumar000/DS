#include<iostream>
using namespace std;
int s = 0;


int noofdigits(int n){
    if(n == 0){
        return 0;
    }
    s = noofdigits(n/10);
    int x = n%10;
    return s+x;
}


int main(){
    int n;
    cin >> n;
    int k = noofdigits(n);
    cout << k;
}
