#include<iostream>
using namespace std;

void generateparanthesis(int n, char a[],int i, int o,int c){
    if(i == 2*n){
        cout << a << endl;
        return;
    }
    if(o<n){
        a[i] = '{';
        generateparanthesis(n,a,i+1, o+1,c);
    }
    if(c<o){
        a[i] = '}';
        generateparanthesis(n,a,i+1,o,c+1);
    }
}
int main(){
    int n;
    cin>> n;

    char a[100];
    generateparanthesis(n,a,0,0,0);



}
