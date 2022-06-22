#include<iostream>
#include<cstring>
using namespace std;

int main(){

    char a[50];
    cin.getline(a,50);
    int n = strlen(a);
    int k=0, i = 0,j,m = INT_MAX,s,e;


    while(k<n){
        while(a[k]!=' ' && a[k] != '\0'){
            k++;
        }
        j = k-i;
        if(j<m){
            m = j;
            s = i;
            e = k;
        }
        k++;
        i=k;

    }
    for(int i=s; i<e;i++){
        cout<<a[i];
    }

}
