#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char a[50];
    cin.getline(a,50);
    int l = strlen(a);

    for(int k=0; k<l; k++){
        for(int i = k; i<l; i++ ){
            for(int j =k; j<=i; j++){
                cout << a[j];
            }
            cout<< endl;
        }
    }





}
