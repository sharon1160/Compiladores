#include<iostream>
#include<vector>

using namespace std;

void diagramaDeTransicion(vector <char> cad){
    char estado,simbolo;
    int num=0;
    int cont=0;
    estado='a';
    simbolo=cad[num];
    while(cont<cad.size()){
        simbolo=cad[num+cont];
        switch (estado)
        {
            case 'a':
                if(simbolo=='.' ){
                    estado='d';
                    break;
                }
                if(simbolo=='-' ){
                    estado='b';
                    break;
                }
                else if(simbolo>='0' && simbolo<='9'){
                    if(cad[num+1]=='.'){
                        estado='c';
                        break;
                    }
                    if(cad[num+1]>='0' && cad[num+1]<='9'){
                        estado='e';
                        break;
                    }
                }
                else{
                    break;
                }
            case 'b':
                if(simbolo=='.' ){
                    estado='d';
                    break;
                }
                if(simbolo>='0' && simbolo<='9'){
                    if(cad[num+1]=='.'){
                        estado='c';
                        break;
                    }
                    else if(cad[num+1]>='0' && cad[num+1]<='9'){
                        estado='e';
                        break;
                    }
                }
                else{
                    break;
                }
            case 'c':
                if(simbolo=='.'){
                    estado='d';
                    break;
                }
                else{

                    break;
                }
            case 'd':
                if(simbolo>='0' && simbolo<='9'){
                    estado='e';
                    break;
                }
                else{
                    break;
                }
            case 'e':
                if(simbolo>='0' && simbolo<='9'){
                    estado='e';
                    break;
                }
                else{
                    break;
                }
            default:
                    break;
        }
        cont++;
    }
    if (estado!='e')
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
