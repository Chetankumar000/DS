#include<iostream>
using namespace std;

int main()
{
    int n,b,c;
    cout << "Enter the number of element of array :"<< endl;
    cin >> n;
    int a[100];
    cout << "Enter the elements"<<endl;
    for (int i = 0; i< n; i++)
    {
        cin >> b;
        a[i] = b;
    }
    cout<< "Enter the value to be search:" << endl;
    cin >> c;

    for (int i = 0; i<n; i++)
    {
        if(a[i] == c)
        {
            cout<<"Element was found at position :"<< i ;
            return 0;
        }

    }
    cout << -1;

}
