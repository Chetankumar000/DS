#include<iostream>
using namespace std;
#include<stack>

int balancebrackets(string s){
    stack<char> st;
    int z=s.size();
    if(z%2 != 0){
        return -1;
    }
    for(int i =0; i< z; i++ ){
        if(s[i] == '}' && !st.empty()){
            if(st.top()== '{'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }

        }
        else{
            st.push(s[i]);
        }


    }

    int l = st.size();
    int n= 0;
    while( !st.empty()&&st.top() == '{'){
        st.pop();
        n++;
    }


    return (l/2 + n%2);




}



int main(){
    int a = balancebrackets("}{{}}{{{");
    cout << a;
}
