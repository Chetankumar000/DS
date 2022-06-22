#include<iostream>
using namespace std;

int main(){
    int a[50], b[50],m,n;
    cin >> m;
    for(int i=0; i<m;i++){
        cin>>a[i];
    }
    cin >>n;
    for(int i=0; i<n;i++){
        cin>>b[i];
    }

    bool q = false;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
        if(a[i] == b[j]) {
            q = true;
            break;
        }
        }
    }
    int sum1 = 0, sum2 = 0;
    if(!q){
        for(int i = 0; i<m;i++){
            sum1+= a[i];
        }
        for(int j = 0; j<n;j++){
            sum2+= b[j];
        }
        if(sum1>=sum2){
            cout << sum1;
        }else{
            cout << sum2;
        }
        return 0;
    }






    int i = 0, j = 0, s1 = 0,s2 = 0, ms = 0;
    while(i<m && j<n && q == true){

        if(a[i] > b[j]){
            s2 += b[j];
            j++;
            continue;
        }else if(a[i] < b[j]){
            s1 += a[i];
            i++;
            continue;
        }else{
            s1 += a[i];
            s2 += b[j];
            i++;
            j++;
        }
        if(s1>s2){
            ms+=s1;
        }else{
            ms+=s2;
        }
        s1 = 0; s2 = 0;

    }
    while(i<m){
        s1 += a[i];
        i++;
    }
    while(j<n){
        s2 += b[j];
        j++;
    }
    if(s1>=s2){
        ms+=s1;
    }else{
        ms+=s2;
    }

    cout << ms;

}
