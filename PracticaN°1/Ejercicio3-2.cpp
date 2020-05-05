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
                texto[i]-=3;
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
//y peso de una persona y posteriormente imprimirla.(CIFRADO)
/*
Lqlflr

Yduldeohv hgdg, shvr.

Prvwudu "Hvfulelu orv gdwrv (Hgdg, Shvr):"

Ohhu Hgdg, Ohhu Shvr.

Prvwudu "Wx shvr hv: ", shvr, "Wx hgdg hv: ", hgdg.

Ilq.
*/
