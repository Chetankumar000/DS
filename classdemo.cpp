#include<iostream>
using namespace std;
#include "classhelper.cpp"

int main(){
    animals dog;
    animals * lion = new animals;
    dog.age = 55;
    dog.breed = "street";
    dog.color = "purple";
    (*lion).name = "jojo";
    cout << dog.age << endl <<dog.breed << endl << dog.color<< endl << (*lion).name ;

}
