#include<iostream>
#include<string>
using namespace std;

void stringlenk(int a,string s,int k){
    if(k == 0){
        cout << s<< endl;
        return ;
    }
    for(int i=a; i<=9; i++){
        string ns = s + to_string(i);
        stringlenk(i+1,ns,k-1);
    }
}

void stringlenK(int a,int k){
    stringlenk(a,"",k);
}

int main(){
    int k;
    cin >> k;
    stringlenK(1,k);

}
