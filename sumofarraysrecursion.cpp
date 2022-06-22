#include<iostream>
using namespace std;

int sum(int a[], int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return a[0];
    }
    return a[0] + sum(a+1, n-1);

}


int main(){
    int a[50], n;
    cin >>n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }


    int s = sum(a,5);
    cout<< s;


}
