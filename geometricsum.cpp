#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

double gm(int n){
    if(n ==0){
        return 1;
    }
    float c = gm(n-1);
    double x = c+(1.00/pow(2,n));
    return x;
}


int main(){
    int n;
    cin>> n;
    cout <<fixed << setprecision(5) << gm(n);;
}
