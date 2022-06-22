#include<iostream>
#include<climits>
using namespace std;

int main(){
    int m,n;
    cin >> m;
    int a[100];
    for(int i=0; i<m; i++)
    {
        cin >> a[i];
    }
    cin >> n;
    int b[100];
    for(int i=0; i<n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i<m; i++){
        for (int j=0; j<n; j++){
            if (a[i] == b[j]){
                cout << a[i] <<" ";
                b[j] = INT_MIN;
                break;
            }
        }
    }


}
