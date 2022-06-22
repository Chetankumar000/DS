#include<iostream>
using namespace std;

int F2C(int f){
    return ((f-32)*5)/9;
}


int main(){
    int s,e,w;
    cin >> s>> e>> w;
    for ( int i=s; i<=e; i= i+w){
        cout<<i<<"\t"<<F2C(i)<<endl;
    }
}
