#include<iostream>
#include<string>
using namespace std;

int main(){
    string line;
    cout << "Enter the sentence: " << endl;
    getline(cin,line);
    int k = 0;
    for(int i =(line.length()-1);i>=0;i--){

        k++;
            if((line[i]==' ')){
                if((i+1)!=line.length()){
                    for(int j = i+1; j<i+k;j++){
                        cout<<line[j];
                    }
                    cout<<" ";
                }
                k = 0;
            }
        if(i==0){
            for(int j = i; j<i+k;j++){
                cout<<line[j];
            }
        }
    }
    cout<<endl;
    return 0;
}
