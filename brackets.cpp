#include<iostream>
#include<string>
using namespace std;

void printbrackets(int n, char s[], int i, int o, int c){
    if (i == 2*n){
        s[i] = '\0';
        cout << s << endl;
        return;
    }
    if(o< n){
        s[i] = '(';
        printbrackets(n,s, i+1, o+1,c);
    }
    if(c<o){
        s[i] = ')';
        printbrackets(n,s, i+1,o,c+1);
    }
}

int main(){
    int n;
    char s[10];
    cin >> n;
    printbrackets(n,s,0, 0 ,0);


}
