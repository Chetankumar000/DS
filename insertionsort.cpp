#include<iostream>
using namespace std;

void insertionsort(int a[], int n){
    int i=1;
    while(i<n){
        int j=i-1, c = a[i];
        for(; j>=0;j--){
            if(a[j] > c){
                a[j+1] = a[j];
            }
            else{
                break;
            }
            a[j] = c;
        }
        i++;
    }
}



int main(){
    int n;
    cin >> n;
    int a[100];
    for(int i=0; i<n;i++){
        cin >> a[i];
    }
    insertionsort(a,n);
    for(int i=0; i<n; i++){
        cout << a[i];
    }

}
