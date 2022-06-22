#include<iostream>
#include<string>
using namespace std;

void interleavings(string m, string n, string k){
    if(m == "" && n == ""){
        cout << k<<endl;
        return;
    }
    if(m.size()){
    interleavings(m.substr(1), n, k+m.at(0));
    }
    if(n.size()){
    interleavings(m,n.substr(1), k+n.at(0));
    }

}


int main(){
    string m,n,k;
    cin >> m>>n;
    interleavings(m,n,k);
}
