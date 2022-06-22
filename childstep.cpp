#include<iostream>
using namespace std;

int childstep(int n){
    if(n == 0){
        return 1;
    }
    else if(n < 0){
        return 0;
    }
    else{
    int x = childstep(n-1);
    int y = childstep(n-2);
    int z = childstep(n-3);
    return x+y+z;
    }
}




int main(){
    int n;
    cin >> n;
    int x = childstep(n);
    cout << x;

}
