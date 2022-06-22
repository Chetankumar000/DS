#include<iostream>
using namespace std;

int main(){
    int n,a,c=0;
    cin >> n;
    for (int i =1; i<=n ; i++){
        a = (3*i) + 2;
        if (a%4 != 0){
            cout << a <<" ";
        }
        else{
            n++;
        }
    }


}
