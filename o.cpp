#include<iostream>
#include<cmath>
using namespace std;

int main(){
    float b, hra, da,pf,allow;
    int ts;
    char g;
    cout << "enter basic salary" << endl;
    cin >> b >> g;
    hra = (20.0*b) / 100.0;
    da = (50.0 * b)/ 100.0;
    pf = (11.0 * b) / 100.0;
    if(g == 'A'){
        allow = 1700;
    }else if(g == 'B'){
        allow = 1500;
    }else{
        allow = 1300;
    }
    ts = round(b + hra + da + allow - pf);
    cout << ts;
}
