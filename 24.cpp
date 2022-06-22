#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n,a,ans=0;
	cin >> n;

	int i = 0;
    while(n!=0){
        a = n%2;
        ans = ans + (a * pow(10,i));
        n = n/2;
        i++;
        }
    cout<< ans;
}

