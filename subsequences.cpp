#include<iostream>
#include<cstring>
using namespace std;

int subseq(string s, string o[]){
    if(s.empty()){
        o[0] = "";
        return 1;
    }
    string sm = s.substr(1);
    int c = subseq(sm, o);

    for(int i=0; i<c;i++){
        o[i+c] = s[0] + o[i];

    }

    return 2*c;
}

int main(){
    string s;
    cin >> s;
    string * o = new string[1000];
    int c = subseq(s,o);
    for (int i=0; i<c; i++){
        cout << o[i]<<endl;
    }




}
