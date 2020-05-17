#include<fstream>
#include <string>
#include <iostream>
using namespace std;

int main() {
    ifstream archivo;
    string texto;
    archivo.open("compilar.txt",ios::in);
    while(!archivo.eof()){//mientras no sea el final
        getline(archivo,texto);
        for (int i = 0; i < texto.length(); i++)
            if(texto[i] != ' ')
                cout<<texto[i]<<endl;
    }
    archivo.close();
    return 0;
}

/* 
TEXTO PLANO
:::::::::::::::compilar.txt:::::::::::::::::::

Inicio
Variables edad, peso.
Mostrar "Escribir los datos (Edad, Peso):"
Leer Edad, Leer Peso.
Mostrar "Tu peso es: ", peso, ",tu edad es: ", edad.
Fin.

*/
