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
    int s=0;
    for(int j=0; j<n;j++){
    s=0;
    for(int i=0;i<m;i++){
        s = s+a[i][j];
    }
    cout << s <<" ";
    }


}
