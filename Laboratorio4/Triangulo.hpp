#include <iostream>
#include <cmath>
using namespace std;

#ifndef TRIANGULO_H
#define TRIANGULO_H

template<typename T>
class Triangulo
{
private:
    T lado1;
    T lado2;
    T lado3;
public:
    Triangulo(T lado1,T lado2 ,T lado3){
        this->lado1 = lado1;
        this->lado2 = lado2;
        this->lado3 = lado3;
        //cout<<"El triangulo es "<<tipo();
    }

    ~Triangulo(){}

    string tipo(){
        if ((abs(lado2-lado1) < lado3) &&  (lado3 < lado2+lado1)) {
            if((lado1 == lado2) && (lado2 == lado3)){
                return "equilatero";
            }
            else if(lado1 == lado2 || lado1 == lado3 || lado2 == lado3){
                return "isosceles";
            }
            else {
                return "escaleno";
            }
        }
        return "invalido";
    }
};

#endif
