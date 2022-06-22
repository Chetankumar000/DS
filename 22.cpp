#include<iostream>
using namespace std;

int main(){
	int n, rev=0,a;
	cin >> n;
	while (n!=0){
        a = n%10;
        rev = (rev * 10) + a;
        n = n/10;
	}
    cout << rev;
}
