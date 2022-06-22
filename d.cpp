#include <iostream>
using namespace std;
int main(){
//do array ka input liya hai ek ka size n dusre ka m hai
int n,m;
cin>>n;
int arr1[n];
for(int i=0;i<n;i++)
   cin>>arr1[i];
cin>>m;
int arr2[m];
for(int i=0;i<m;i++)
   cin>>arr2[i];
int opsize=(n>m)?n:m;
opsize++; // output array hai jiska size ek jyada hai as compared to max size of m and n
int i=n-1,j=m-1,k=opsize-1,sum=0,carry=0;
int op[opsize]={0};
while(k>=0&&i>=0&&j>=0){
sum=arr1[i]+arr2[j];
op[k]=(sum+carry)%10;
carry=(sum+carry)/10;
i--;
j--;
k--;
}
if(i<0&&j>=0){
  do{
    sum=arr2[j];
   op[k]=(sum + carry)%10;
   carry=(sum+carry)/10;
   j--;
   k--;
  }while(k>=0&&j>=0);
  op[0]=0;
}else if(j<0&&i>=0){
 do{
   sum=arr1[i];
   op[k]=(sum + carry)%10;
   carry=(sum+carry)/10;
   i--;
   k--;
  }while(k>=0&&i>=0);
  op[0]=0;
}
if(i<0&&j<0){
op[0]=carry;
}
//output array hai yeh bas print kara raha hu
for(int i=0;i<opsize;i++)
  cout<<op[i]<<" ";
return 0;
}
