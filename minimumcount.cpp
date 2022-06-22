#include<iostream>
using namespace std;

int minimumcount(int n){
    if(n == 0){
        return 0;
    }
    if( n==1){
        return 1;
    }
    int c ;
    for(int i = 1; i<=n/2; i++){
        if(i*i == n){
            return 1;
        }
        if(i*i<n){
           c = minimumcount(n - (i*i));
        }
    }
    return 1+c;

}



int main(){
    int n;
    cin>> n;
    int c = minimumcount(n);
    cout << c;
}
