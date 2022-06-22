#include<iostream>
using namespace std;

class Complex{
    private:
    int r;
    int i;
    public:
    Complex(int r,int i){
        this-> r = r;
        this -> i = i;
    }
    add(Complex &c2){
        r = r + c2.r;
        i = i + c2.i;
    }
    multiply(Complex &c2){
        r = r * c2.r - i * c2.i;
        i = r * c2.r + i * c2.i;
    }
    print(){
        cout << r   << i<< "i" << endl;
    }
};



int main(){
    Complex c1(2,4);
    Complex c2(3,6);
    c1.print();
    c2.print();
    c1.add(c2);
    c1.print();
    c1.multiply(c2);
    c1.print();




}
