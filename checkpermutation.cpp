#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char a[10], b[10];
    cin >> a;
    cin >> b;
    int m = strlen(a);
    int n = strlen(b);
    bool q = false;
    for(int i=0;i<m;i++){
            q = false;
        for(int j = 0; j<n;j++){
            if(a[i] == b[j]){
                b[j] = 0;
                q=true;
                break;
            }
            }
            if(!q){
            cout << "False";
            break;
        }
        else{
            continue;
        }
    }
    if(q){
    cout << "True";
    }




}
