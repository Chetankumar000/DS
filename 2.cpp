#include<iostream>
using namespace std;

int main(){
    int s,e,w,c;
    cin >>s >> e >>w;
    while (s<=e){
        c = ((s-32) * 5)/9;
        cout << s << " "<< c <<endl;
        s = s+w;
    }
}
