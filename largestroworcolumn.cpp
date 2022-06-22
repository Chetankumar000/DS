#include<iostream>
using namespace std;

int main(){
    int a[100][100];
    int n,m;
    cin >>m>>n;
    for(int i=0; i<m;i++){
        for(int j=0; j<n;j++){
            cin >> a[i][j];
        }
    }
    int s=0,mx = INT_MIN,k;
    for(int j=0; j<m;j++){
    s=0;
    for(int i=0;i<n;i++){
        s = s+a[j][i];
        if(s>mx){
            mx = s;
            k = j;
        }
    }}

    int cs=0,mx1 = INT_MIN,k1;
    for(int j=0; j<n;j++){
    cs=0;
    for(int i=0;i<m;i++){
        cs = cs+a[i][j];
        if(cs>mx1){
            mx1=cs;
            k1 = i;
        }
    }
    }
    if(s>=cs){
        cout<< "row"<<" "<<k<<" "<<mx;
    }else{
        cout<< "column"<<" "<<k1<<" "<<mx1;
    }


}
