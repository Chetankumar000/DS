#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int n1,n2,i=2;
    cin>>n1;
    cin>>n2;
    while((n2-n1)<0)
    {
        i++;
        n1=n2;
        cin>>n2;
    }
    while((n2-n1)>0)
    {
        i++;
        n1=n2;
        cin>>n2;
    }

    if(i==(n)) cout<<"true"<<endl;
    else cout<<i<<"false"<<endl;

    return 0;
}
