#include<iostream>
#include<cstring>
using namespace std;

bool checkpalindromehelper(char a[],int s,int e){
     if(e+1 == 0 || e+1 ==1){
        return true;
    }
    if(a[s] != a[e]){
        return false;
    }
    bool b = checkpalindromehelper(a,s+1,e-1);
    return b;
}




bool checkpalindrome(char a[]){
    int n = strlen(a);
    bool b = checkpalindromehelper(a,0,n-1);
    return b;



}


int main(){
    char a[50];
    cin >> a;
    int n = strlen(a);
    cout << checkpalindrome(a);



}
