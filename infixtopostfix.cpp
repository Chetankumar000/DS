#include<iostream>
using namespace std;
#include<string>
#include<stack>

int prec(char a){
    if(a == '^'){
        return 3;
    }
    else if(a == '*' || a == '/'){
        return 2;
    }
    else if(a == '+' || a == '-'){
        return 1;
    }
    else{
        return -1;
    }


}








string InftoPost(string s){
    stack<char> st;
    string ans = "";
    for(int i=0 ; i< s.size(); i++){
        char a = s[i];

        if((a >= 'a' && a <= 'z') || (a >= '0' && a <= '9') ){
            ans+= a;
        }

        else if(a == '('){
            st.push(a);
        }

        else if(a == ')'){
            while(st.top() != '('){
                    ans += st.top();
                    st.pop();
                  }
            st.pop();
        }

        else{
            while(!st.empty() && prec(a) <= prec(st.top())){
                if(a == '^' && st.top() == '^'){
                    break;
                }
                else{
                    ans += st.top();
                    st.pop();
                }

            }
            st.push(a);


        }
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();

    }
    return ans;

}


int main(){
    string ans = InftoPost("a+b*(c^d-e)^(f+g*h)-i");
    cout << ans;
}
