#include<iostream>
using namespace std;

int countbinarystrings(int prev, int n){
    if(n == 0){
        return 1;
    }
    if( n ==1){
        if(prev ==1){
            return 1;
        }else if( prev == 0){
        return 2;
        }
    }
    if( prev == 0){
        return countbinarystrings(0,n-1) + countbinarystrings(1,n-1);
    }
    else if(prev == 1){
        return countbinarystrings(0,n-1);
    }

}




int main(){
    int n;
    cin >> n;
    int a = countbinarystrings(0,n);
    cout << a;


}
