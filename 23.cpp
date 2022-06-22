#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n,a,ans=0;
	cin >> n;

	int i = 0;
    while(n!=0){
        a = n%10;
        ans = ans + (a * pow(2,i));
        n = n/10;
        i++;
        }
    cout<< ans;
}
