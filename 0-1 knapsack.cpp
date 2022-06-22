#include<iostream>
#include<algorithm>
using namespace std;

int knapsack(int n,int c,int w[],int p[]){
    if(n == 0 or c == 0){
        return 0;
    }
    int p1;
    if(w[n-1] < c){
        p1 = p[n-1] + knapsack(n-1, c-w[n-1], w,p);
    }
    int p2 = knapsack(n-1, c,w,p);
    return max(p1,p2);
}
int main(){
    int c =7,n = 4;
    int w[10] = {1,2,3,5};
    int p[10] = {40,20,30,100};
    int a = knapsack(n,c,w,p);
    cout << a;
}
