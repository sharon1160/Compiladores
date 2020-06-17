#include <iostream>
#include <stack>
#include <cmath>
#include <cstdlib> 
#include <string>

using namespace std;

stack<double> pila;
string cad;
double a, b, result;

double evalPosFija(string cad)
{
    if (cad != ";")
    {
        result = atof(cad.c_str());
        if (result >0.0 ){
            pila.push(result);
        }
        else if (cad == "0.0"){
            pila.push(result);
        }
        else if(cad =="+" || cad =="-" ||  cad =="*" || cad =="/" ){
             switch (cad[0])
            {
                case '+' : 
                    a = pila.top(); 
                    pila.pop(); 
                    b = pila.top();
                    pila.pop(); 
                    pila.push(a+b); 
                    break;
                case '-' : 
                    a = pila.top(); 
                    pila.pop(); 
                    b = pila.top();
                    pila.pop(); 
                    pila.push(b-a); 
                    break;
                case '*' : 
                    a = pila.top(); 
                    pila.pop(); 
                    b = pila.top();
                    pila.pop(); 
                    pila.push(a*b); 
                    break;
                case '/' : 
                    a = pila.top(); 
                    pila.pop(); 
                    b = pila.top();
                    pila.pop(); 
                    pila.push(b/a); 
                    break;
                case '^' : 
                    a = pila.top(); 
                    pila.pop(); 
                    b = pila.top();
                    pila.pop(); 
                    pila.push(exp(a*log(b)));
                    break;
            }
        }

    }
    else{
        cout<<"RESPUESTA "<< pila.top()<<endl;
        while (!pila.empty())
        {
            pila.pop();
        }
        result=0.0;
    }
    
}


int main()
{
    //si la expresion no es Posfija mostrara
    //Segmentation fault
    evalPosFija("8");
    evalPosFija("12");
    evalPosFija("+");
    evalPosFija("5");
    evalPosFija("2");
    evalPosFija("-");
    evalPosFija("-");
    evalPosFija("2");
    evalPosFija("*");
    evalPosFija(";");
    
    return 0;
}
