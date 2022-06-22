#include<iostream>
using namespace std;

int flags(int n, char p, char pp){
    if( n == 1){
        p = 'w';
        return 1;
    }
    int c;
    if( p == 'b' && pp == 'w'){
        c = flags(n-1, 'r','b');
        return c+1;
    }else if(p == 'b' && pp == 'r'){
        c = flags(n-1, 'w', 'b');
        return c+1;
    }
    else if(p == 'w'){
        c = flags(n-1, 'b', 'w') + flags(n-1, 'r', 'w');
    }
    else if(p == 'r'){
        c = flags(n-1, 'b', 'r')+ flags(n-1, 'w', 'r');
    }

    return c;




}



int main(){
    int n;
    cin >> n;
    int c =flags(n,'b','s');
    cout << c;


}
