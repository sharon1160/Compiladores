#include<iostream>
#include<vector>

using namespace std;

void diagramaDeTransicion(vector <char> cad){
    char estado;
    char simbolo;
    estado='1';
    int num=0;
    simbolo=cad[num];
    while(simbolo!=cad[cad.size()-1]){
        switch (estado)
        {
            case '1':
                if(simbolo>='0' && simbolo<='9'){
                    estado='2';
                    break;
                }
                else if(simbolo>='a' && simbolo<='z' || simbolo>='A' && simbolo<='Z' ){
                    estado='3';
                    break;
                }
                else{
                    cout<<"ERROR"<<endl;
                    break;
                }
            case '2':
                break;
            case '3':
                if(simbolo>='a' && simbolo<='z' || simbolo>='A' && simbolo<='Z' ){
                    estado='3';
                    break;
                }
                else if(simbolo>='0' && simbolo<='9'){
                    estado='3';
                    break;
                }
                default:
                     break;
        }
        simbolo=cad[num++];
    }
    if (estado!='3')
        cout<<"ERROR"<<endl;
    else
        cout<<"CORRECTO"<<endl;  
}

int main(){
    string cadena;
    vector<char> cad;
    cout<<"Ingrese una cadena :"<<endl;
    cin>>cadena;
    for(int i=0;i<cadena.length();i++){
        cad.push_back(cadena[i]);
    }
    diagramaDeTransicion(cad);
    return 0;
}
