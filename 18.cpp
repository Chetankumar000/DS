#include<iostream>
using namespace std;

int main(){
    int n,c;
    cin >> c;
    n = c/2 + 1;
    int i = 1;
    while (i<= n){
        int j = 1;
        while(j<= n-i){
            cout<< " ";
            j ++;
        }
        int k = 1;
        while(k<= (2*i)-1){
            cout<< "*";
            k ++;
        }
        cout<< endl;
        i++;
    }
    int q = c/2;
    int l =1;
    while (l<=q){
        int y = l;
        while (y!=0){
            cout << " ";
            y--;
        }
        int g = l;
        while(g > (2*l)-3){
            cout << "*";
            g--;
        }
        cout << endl;
        l++;
    }
}
