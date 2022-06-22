#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char a[50];
    cin.getline(a,50);
    int l = strlen(a);
    int i = 0;
    while (i<l)
    {
        if (a[i] == ' '){
            int j = i;
            while(j<l){
                a[j] = a[j+1];
                j++;
            }
        }else{
            i++;
        }
    }
    cout << a;

}

