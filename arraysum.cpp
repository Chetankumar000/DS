#include<iostream>
using namespace std;

int main(){
    int n,a,sum=0;
    cin >> n;
    int arr[100];
    for (int i =0 ; i<n;i++){
        cin >> a;
        arr[i] = a;
        sum = sum+a;
    }
    cout<<sum;

}
