#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char a[50];
    cin >> a;
    int n = strlen(a);

    int mc= INT_MIN,k ;
    for(int i=0; i<n; i++){
            int c = 0;
        for(int j =0; j<n; j++){
            if(a[i] == a[j]){
                c++;
            }
        }
        if(c>mc){
            mc = c;
            k =  i;

        }
    }
    cout<<a[k] << " "<< mc;






}
