#include<iostream>
using namespace std;

int main(){
    int a[50],n;
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    bool b = false;
    for(int i=0; i<n;i++){
        if(i==n-1){
            b=true;
        }else{b = false;
        }

        for(int j=i+1; j<n; j++){
            if(a[i] >= a[j]){
                b = true;
            }else{
                b = false;
                break;
            }
        }
        if(b){
            cout << a[i]<<" ";
        }
    }


}
