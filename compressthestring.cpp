#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char a[50];
    cin.getline(a,50);
    int m = strlen(a);
    int k = 0, i = 0, j;

    while(k<m){
        while(a[k]==a[i] && a[k]!= '\0'){
            k++;
        }
        if(a[k] != a[i]){
        j = k-i;
        if(j==1){
                cout<<a[i];
                i = k;
                continue;}
        cout << a[i]<<j;
        }
        i =k;


}

}
