#include<iostream>
using namespace std;

int main()
{
    int a[6] = {1,5,10,15,20,25},b[5]= {2,4,5,9,15};
    int n=6,m=5;

    int curr_sum1=0,curr_sum2=0,max_sum=0;
    int i=0,j=0;
    while(i<n&&j<m)
    {

        if(a[i]!=b[j])
        {
            if(a[i]<b[j])
            {
                curr_sum1=curr_sum1+a[i];
                i++;
                continue;
            }
            else if(b[j]<a[i])
            {
                curr_sum2=curr_sum2+b[j];
                j++;
                continue;
            }
        }
            else
            {
                curr_sum1=curr_sum1+a[i];
                curr_sum2=curr_sum2+b[j];
                i++;
                j++;


            }
        if(curr_sum1>curr_sum2)
            {
                max_sum=max_sum+curr_sum1;
            }
            else
            {
                max_sum=max_sum+curr_sum2;
            }
            curr_sum1=0;
            curr_sum2=0;




    }
    while(i<n)
    {
      curr_sum1=curr_sum1+a[i];
      i++;
    }
    while(j<m)
    {
      curr_sum2=curr_sum2+a[i];
    }
    if(curr_sum1>curr_sum2)
    {
      max_sum=max_sum+curr_sum1;
    }
    else
    {
      max_sum=max_sum+curr_sum2;
    }



    cout<<max_sum;


}

