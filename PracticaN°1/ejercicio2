
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
        for (int i=0;i<texto.length();i++)
            if(texto[i]!=' ')
                cout<<texto[i]<<endl;
    }
    archivo.close();
    return 0;
}

/* compilar.txt
Inicio
Mostrar "Introduzca el diametro, en metros": Pedir D
Mostrar "Introduzca la altura, en metros": Pedir H
R = D/2: Pi = 3,141593
V = Pi * (R ^ 2) * H
Mostrar "El volumen del cilindro es de", V, "metros cubicos"
Fin
*/
