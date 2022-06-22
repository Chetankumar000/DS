#include<iostream>
using namespace std;


int main(){
    char a[50];
    cin >> a;
    int c=0;
    bool b = true;
    for(int i=0; a[i]!=0; i++){
        c++;
    }
    int i =0, j = c-1;
    while(i<j){
        if(a[i] != a[j]){
            b = false;
            break;
        }
    i++;
    j--;
    }
    if(!b){
        cout << "false";
    }else{
    cout<< "true";
    }


}
