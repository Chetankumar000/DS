#include<iostream>
using namespace std;

int towerofhanoi(int n, char s, char h, char d){
    if (n == 0){
        return 0;
    }
    int c = 1;
    c+= towerofhanoi(n -1, s,d,h);
    cout << "Shift disk " << n << " from " << s << " to " << d <<endl;
    c+= towerofhanoi(n-1, h, s, d);
    return c;

}


int main(){
    int n;
    cin >>n;
    int s = towerofhanoi(n,'A','B', 'C');
    cout << s;



}
