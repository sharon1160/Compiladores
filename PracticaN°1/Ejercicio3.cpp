#include <iostream>
#include <fstream>
 
using namespace std;

void cifrar(string texto){
    
    for (int i = 0; i < texto.length(); i++){
        if(texto[i] >= 'a' && texto[i] <= 'z' || texto[i] >= 'A' && texto[i] <= 'Z' ){
            texto[i]+=3;
            cout<<texto[i];
        }
        else
            cout<<texto[i];
    }
    cout<<endl;
}

void descifrar(string texto){
    for (int i = 0; i < texto.length(); i++){
        if(texto[i] >= 'a' && texto[i] <= 'z' || texto[i] >= 'A' && texto [i]<= 'Z' ){
            texto[i] -= 3;
            cout<<texto[i];
        }
        else
            cout<<texto[i];
    }
    cout<<endl;
}

int main() {
    ifstream archivo;
    string texto;
    int opc;
    cout<<":::::::::::CIFRADO DE CESAR:::::::::::"<<endl;
    cout<<endl;
    cout<<"Elija una opción :"<<endl;
    cout<<"1.Cifrar pseudocodigo"<<endl;
    cout<<"2.Descifrar pseudocodigo"<<endl;
    cin>>opc;
    cout<<endl;
    archivo.open("compilar.txt",ios::in);
    switch (opc)
    {
        case 1:
            cout<<":::::::::::PSEUDOCODIGO CIFRADO:::::::::::"<<endl;
            cout<<endl;
            while(!archivo.eof()){//mientras no sea el final
                getline(archivo,texto);
                cifrar(texto);
            }
            archivo.close();
            break;
        
        default:
            cout<<":::::::::::PSEUDOCODIGO DESCIFRADO:::::::::::"<<endl;
            cout<<endl;
            while(!archivo.eof()){//mientras no sea el final
                getline(archivo,texto);
                descifrar(texto);
            }
            archivo.close();
            break;
    }
    return 0;
}
/*

Pseudocódigo de un programa que permita leer la edad
y peso de una persona y posteriormente imprimirla.

TEXTO PLANO SIN CIFRAR

:::::::::::::::compilar.txt::::::::::::::::
Inicio
Variables edad, peso.
Mostrar "Escribir los datos (Edad, Peso):"
Leer Edad, Leer Peso.
Mostrar "Tu peso es: ", peso, ", tu edad es: ", edad.
Fin.

TEXTO PLANO CIFRADO

:::::::::::::::compilar.txt::::::::::::::::
Lqlflr
Yduldeohv hgdg, shvr.
Prvwudu "Hvfulelu orv gdwrv (Hgdg, Shvr):"
Ohhu Hgdg, Ohhu Shvr.
Prvwudu "Wx shvr hv: ", shvr, ",wx hgdg hv: ", hgdg.
Ilq.

*/
