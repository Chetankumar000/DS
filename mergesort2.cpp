#include<iostream>
using namespace std;

void mergge(int a[], int s, int mid, int e){
    int * z = new int[e-s+1];
    int i = s, j = mid+1, c=0;
    while(i < mid+1 && j <e+1){
        if(a[i] < a[j]){
            z[c] = a[i];
            c++;
            i++;
        }else if(a[j] < a[i]){
            z[c] = a[j];
            c++;
            j++;
        }
    }
    while(i<mid+1){
        z[c] = a[i];
        c++;
        i++;
    }
    while(j<e+1){
        z[c] = a[j];
        c++;
        j++;
    }
    int m = 0;
    for(int i = s; i<e+1; i++){
        a[i] = z[m];
        m++;
    }
    delete [] z;

}


void mergesort(int a[], int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    mergesort(a,s,mid);
    mergesort(a,mid+1, e);
    mergge(a, s, mid, e);
}

int main(){
    int a[20], n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    mergesort(a,0,n-1);
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }}
