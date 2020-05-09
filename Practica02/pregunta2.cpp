#include<iostream>
#include<vector>

using namespace std;

void llenadoMatriz(string tabla[][4]){
    tabla[0][0]="-";
    tabla[0][1]="digito";
    tabla[0][2]="letra";
    tabla[0][3]="fdc";
    tabla[1][0]="1";
    tabla[1][1]="2";
    tabla[1][2]="3";
    tabla[1][3]="error";
    tabla[2][0]="2";
    tabla[2][1]="error";
    tabla[2][2]="error";
    tabla[2][3]="error";
    tabla[3][0]="3";
    tabla[3][1]="3";
    tabla[3][2]="3";
    tabla[3][3]="aceptar";
}

void TablaTransicion(vector<char> cadena,string tabla[][4]){
    int i=1;
    int Entrada;
    string Estado="1";
    int n=0;
    char simbolo,opc;
    do
    {
        simbolo=cadena[n];
        if(n==cadena.size()-1)
            opc='f';
        else if(simbolo>='a' && simbolo<='z'|| simbolo>='A' && simbolo<='Z')
            opc='l';
        else if(simbolo>='0' && simbolo<='9')
            opc='d';
        else {
            cout<<"ERROR"<<endl;
            break;
        }  
        n++;  
        switch (opc)
        {
            case 'd':
                Entrada=1;
                break;
            case 'l':
                Entrada=2;
                break;
            case 'f':
                Entrada=3;
                break;
            default:
                cout<<"ERROR"<<endl;
                break;
        }
        if(Estado=="1"){
            Estado=tabla[1][Entrada];
        }
        else if(Estado=="2"){
            Estado=tabla[2][Entrada];
        }
        else if(Estado=="3"){
            Estado=tabla[3][Entrada];
        }
        else if(Estado=="error"){
            cout<<"ERROR"<<endl;
            break;
        }
    } while (Estado!="aceptar");
    if(Estado=="aceptar"){
        cout<<"Cadena aceptada"<<endl;
    }
}

int main(){
    string tabla[4][4];
    llenadoMatriz(tabla);
    string cad;
    vector <char> cadena;
    cout<<"Ingrese una cadena : "<<endl;
    cin>>cad;
    for(int i=0;i<cad.length();i++)
        cadena.push_back(cad[i]);
    TablaTransicion(cadena,tabla);
    return 0;
}
