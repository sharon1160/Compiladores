#include <iostream>
#include <fstream>
 
using namespace std;

int main() {
    ifstream archivo;
    string texto;
    archivo.open("compilar.txt",ios::in);
    while(!archivo.eof()){//mientras no sea el final
        getline(archivo,texto);
        for (int i=0;i<texto.length();i++){
            if(texto[i]>='a' && texto[i]<='z' || texto[i]>='A' && texto[i]<='Z' ){
                texto[i]+=3;
                cout<<texto[i];
            }
            else
                cout<<texto[i];
        }
        cout<<endl;
    }
    archivo.close();
    return 0;
}
// Pseudocódigo de un programa que permita leer la edad
//y peso de una persona y posteriormente imprimirla.
/*
Inicio

Variables edad, peso.

Mostrar "Escribir los datos (Edad, Peso):"

Leer Edad, Leer Peso.

Mostrar "Tu peso es: ", peso, "Tu edad es: ", edad.

Fin.
*/
