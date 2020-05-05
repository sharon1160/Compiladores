#include <iostream>
#include <vector>
#include <fstream>
 
using namespace std;

bool isIntNumber(vector <char> cadena){
    int cont=0;
    for(int i=0;i<cadena.size();i++){
        if(cadena[i]>='0' && cadena[i]<='9')
           cont++;
    }
    if(cont==cadena.size()){
        return true;
    }
    else
        return false;
}

bool isEspecialChar(vector <char> cadena){
    if(cadena.size()==1){
        if(cadena[0]=='+' || cadena[0]=='-' || cadena[0]=='*'|| cadena[0]=='/' )
            return true;
        else
            return false;
    }
    else
        return false;
}

bool isWord(vector <char> cadena){
    bool wordWithNumber=false;
    for(int i=0;i<cadena.size();i++){
        if(cadena[i]>='a' && cadena[i]<='z' || cadena[i]>='A' && cadena[i]<='Z'){
           wordWithNumber=true;
        }
        else if(cadena[i]>='0' && cadena[i]<='9'){
            if(wordWithNumber!=true)
                return false;
        }
        else if(cadena[i]=='+' || cadena[i]=='-' || cadena[i]=='*'|| cadena[i]=='/' )
                return false;
        if(i==cadena.size()-1){
            return true;
        }
    }
}
void analizar(vector <char> cadena){
    if(isIntNumber(cadena)==true){
        cout<<endl;
        cout<<"The string is an integer"<<endl;
    }
    else if(isEspecialChar(cadena)==true){
        cout<<endl;
        cout<<"The string is special character"<<endl;
    }
    else if(isWord(cadena)==true){
        cout<<endl;
        cout<<"The string is a word"<<endl;
    }
    else{
        cout<<endl;
        cout<<"The string is not an integer or a word or a special character"<<endl;
    }
}

int main() {
    ifstream archivo;
    string texto;
    vector<char> cadena;
    bool flag=true;
    archivo.open("compilar.txt",ios::in);
    while(!archivo.eof() && flag==true){//mientras no sea el final
        getline(archivo,texto);
        for(int i=0;i<texto.length();i++){
            if(texto[i]==' ' || texto[i]=='\t'){
                analizar(cadena);
                flag=false;
                break;
            }
            else{
                cadena.push_back(texto[i]);
                cout<<texto[i];
            }
            if(i==texto.length()-1){
                analizar(cadena);
                flag=false;
                break;
            }
        }
        cout<<endl; 
    }
    archivo.close();
    return 0;
}

/*
::::::::::::::archivo de texto plano::::::::::::::
Inicio

Variables edad, peso.

Mostrar "Escribir los datos (Edad, Peso):"

Leer Edad, Leer Peso.

Mostrar "Tu peso es: ", peso, ",tu edad es: ", edad.

Fin.

*/
