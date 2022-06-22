#include<iostream>
using namespace std;
#include<stack>
#include <string>

int main(){
    stack<char> s;
    string str;
    getline(cin, str);
    int c = 0;
    while(c != str.size()){
        if(s.empty() && str[c] == ')'){
            cout << "False";
            return 0;
        }
        else if(s.empty() && str[c] == '('){
            s.push(str[c]);
            c++;
        }
        else if(s.top() == '(' && str[c] == ')'){
            s.pop();
            c++;
        }
        else if(s.top() == '(' && str[c] == '('){
            s.push(str[c]);
            c++;

        }
    }
    if(s.empty()){
        cout << "True";
    }
    else{
        cout << "False";
    }


}
