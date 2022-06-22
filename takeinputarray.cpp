#include<iostream>
using namespace std;

void takeinputarray(int a[], int n){
    cout << "Enter the elements of array size :"<<n<< endl;
    for(int i=0; i< n; i++){
        cin >> a[i];
    }
}



int main(){
    int n;
    cin >> n;
    int a[50];
    takeinputarray(a,n);

    for(int i=0; i<n; i++){
        cout << a[i];
    }


}
