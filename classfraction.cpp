#include<iostream>
using namespace std;

class Fraction{
    private:
    int n;
    int d;
    public:
    Fraction(int n, int d){
        this -> n = n;
        this -> d = d;
    }
    void sim(){
        int gcd = 1;
        int j = min(this -> n, this -> d);
        for(int i=1; i<=j; i++){
            if(this-> n %i == 0 && this -> d%i == 0){
                gcd = i;
            }
        }
        this -> n /= gcd;
        this -> d /= gcd;
    }

    void add(Fraction &f2){
        int lcm = this-> d * f2.d;
        int x =  lcm/this-> d;
        int y = lcm / f2.d;
        int num = x * this -> n + (y * f2.n);
        this -> n = num;
        this -> d = lcm;
        sim();
    }
    void mul(Fraction &f2){
        this -> n *= f2.n;
        this -> d *= f2.d;
        sim();
    }



    void print(){
        cout <<this -> n << "/"<< this -> d << endl;
    }
};

int main(){
    Fraction f1(10, 2);
    Fraction f2( 15, 4);
    f1.print();
    f1.add(f2);
    f1.print();
    f1.mul(f2);
    f1.print();
}
