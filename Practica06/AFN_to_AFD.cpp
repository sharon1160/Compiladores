#include <stdio.h>
#include <vector>
#include <bits/stdc++.h> 
#include <stdlib.h>
#include <string>
#include <stack>
#include <fstream>
#include <iostream>

using namespace std;

struct Estado{
    vector<int> SubEstados;
    bool Esta_marcado=false;
    bool Es_Aceptacion=false;
    int num;//numero del estado
    Estado(int numero,bool acept){
        num = numero;
        Es_Aceptacion = acept;
        Esta_marcado = false;
    }
    Estado(int numero){
        num = numero;
        Es_Aceptacion = false;
        Esta_marcado = false;
    }
};

struct Transicion{
    int start,end;
    string token;
    Transicion(int s,int e,string tok){
        token = tok;
        start = s;
        end = e;
    }
};


class Automata
{
    //Lista de Entradas,Lista de Estados,Lista de transiciones
    vector<string> Entradas;vector<Estado> Estados;vector<Transicion> Transiciones;
public:
    Automata();
    //constructor
    void Estado_Nuevo(int n);//metodo para crear estado
    void Entrada_Nueva(string ent){Entradas.push_back(ent);}
    void TransNueva(int start,int end, string cad);
    void Estados_acept(int n);
    //metodos para mostrar
    void MostrarEstados();
    void MostrarSubestados();
    void MostrarTrans();
    void MostrarEstadosAcep();
    //
    int nEstados(){//cantidad de estados
        return Estados.size();
    }
    int nTrans(){//cantidad de transiciones
        return Transiciones.size();
    }
    //existencia del estado
    vector<int> eClausu(vector<int> &vect);
    bool EstadoExistente(vector<int> &vect){
        for(int i=0;i<Estados.size();i++){
            if(Estados[i].SubEstados==vect)
                return true;
        }
        return false;
    }
    //estados marcados
    bool Estados_marcados(){
        for(int i=0;i<Estados.size();i++){
            if(Estados[i].Esta_marcado==false)
                return false;
        }
        return true;
    }
    Automata* AFD();
};

Automata::Automata(){}

void Automata::Estado_Nuevo(int n){
    Estado nuevo(n);
    this->Estados.push_back(nuevo);
}

void Automata::TransNueva(int start,int end, string cad){
    Transiciones.push_back(Transicion(start,end,cad));
}
void Automata::Estados_acept(int n){
    for(int i=0;i<Estados.size();i++){
        if(Estados[i].num==n)
            this->Estados[i].Es_Aceptacion=true;
    }
}
void Automata::MostrarEstados(){
    for(int i=0;i<Estados.size();i++)
        cout<<Estados[i].num<<" "<<Estados[i].Es_Aceptacion<<endl;
}
void Automata::MostrarSubestados(){
    cout<<"Estados"<<endl;
    for(int i=0;i<Estados.size();i++){
        cout<<Estados[i].num<<"= { ";
        for(int j=0;j<Estados[i].SubEstados.size();j++)
            cout<<Estados[i].SubEstados[j]<<" ";
        cout<<"}"<<endl;
    }
}
void Automata::MostrarTrans(){
    cout<<"Transiciones de Estados (x,y,z)"<<endl;
    for(int i=0;i<Transiciones.size();i++)
        cout<<Transiciones[i].start<<" "<<Transiciones[i].token<<" "<<Transiciones[i].end<<endl;
}
void Automata::MostrarEstadosAcep()
{
    cout<<"Estados de Aceptacion"<<endl;
    for(int i=0;i<Estados.size();i++){
        if(Estados[i].Es_Aceptacion)
            cout<<Estados[i].num<<" ";
    }
    cout<<endl;
}

vector<int> Automata::eClausu(vector<int> &v){
    stack<int> mipila;
    vector<int> result;
    for(int i=0;i<v.size();i++){
        mipila.push(v[i]);
    }
    while(!mipila.empty()){
        int act;
        act=mipila.top();
        mipila.pop();
        result.push_back(act);
        for(int i=0;i<nTrans();i++){
            if(Transiciones[i].start==act && Transiciones[i].token=="-1")
                mipila.push(Transiciones[i].end);
        }
    }
    sort(result.begin(),result.end());
    return result;
}

//Funcion inicializar
void iniciar(Automata *automata)
{
    char cad[128];
    string num="";
    ifstream archivo("in.txt");
    while(!archivo.eof()){
        archivo.getline(cad,128);
        string aux(cad);
        if(aux=="Estados"){
            archivo.getline(cad,128);
            int n=atoi(cad);

            archivo.getline(cad,128);
            string c(cad);

            for(int i=0;i<c.length();i++){	
                if(c[i]==' ' || c[i]=='\n'){
                    automata->Estado_Nuevo(stoi(num));
                    num="";
                }
                else
                    num+=c[i];
            }
            automata->Estado_Nuevo(stoi(num));
            num="";
            if(n!=automata->nEstados())
                cout<<"ERROR en estados"<<endl;
        }
		if(aux=="Estados_de_Aceptacion"){
            archivo.getline(cad,128);
            int n=atoi(cad);

            archivo.getline(cad,128);
            string c(cad);
            int count=0;
            for(int i=0;i<c.length();i++){	
                if(c[i]==' ' || c[i]=='\n'){
                    automata->Estados_acept(stoi(num));
                    num="";
                    count++;
                }
                else
                    num+=c[i];
            }
            automata->Estados_acept(stoi(num));
            num="";
            count++;
            if(n!=count)
                cout<<"ERROR en estados de aceptacion"<<endl;
		}
		if(aux=="Transiciones_(x,y,z)_epsilon=-1"){
            archivo.getline(cad,128);
            int n=atoi(cad);

            int e1,e2,p=1;
            string token;
            for(int i=0;i<n;i++){
                archivo.getline(cad,128);
                string c(cad);

                for(int i=0;i<c.length();i++){	
                    if(c[i]==' ' && p==1){
                        e1=stoi(num);
                        num="";
                        p++;
                    }
                    else if(c[i]==' ' && p==2){
                        token=num;
                        num="";
                        p++;
                    }
                    else
                        num+=c[i];
                }
                e2=stoi(num);
                p=1;
                automata->TransNueva(e1,e2,token);
                num="";
            }
            if(n!=automata->nTrans())
                cout<<"ERROR en transiciones"<<endl;
		}
        if(aux=="Entradas"){
            archivo.getline(cad,128);
            int n=atoi(cad);

            archivo.getline(cad,128);
            string c(cad);
            int count=0;
            for(int i=0;i<c.length();i++){	
                if(c[i]==' ' || c[i]=='\n'){
                    automata->Entrada_Nueva(num);
                    num="";
                    count++;
                }
                else
                    num+=c[i];
            }
            automata->Entrada_Nueva(num);
            num="";
            count++;
            if(n!=count)
                cout<<"ERROR en las entradas"<<endl;
		}
	}
    archivo.close();
}

Automata* Automata::AFD()
{
    Automata* AF_deter=new Automata();
    AF_deter->Estado_Nuevo(0);
    int estado_act=0;
    int nomEstado=1;
    vector<int> vec;
    vector<int> vec2;

    vec.push_back(this->Estados[0].num);
    AF_deter->Estados[estado_act].SubEstados=eClausu(vec);
    vec.clear();

    while(!AF_deter->Estados_marcados()){

        for(int i=0;i<Entradas.size();i++){	
            for(int k=0; k < AF_deter->Estados[estado_act].SubEstados.size(); k++){  
                for(int j=0; j<Transiciones.size(); j++){
                    if(Transiciones[j].start==AF_deter->Estados[estado_act].SubEstados[k] && Transiciones[j].token==Entradas[i])
                        vec.push_back(Transiciones[j].end);
                }
            }
            vec2=eClausu(vec);
            if(!AF_deter->EstadoExistente(vec2)){

                AF_deter->Estado_Nuevo(nomEstado);
                AF_deter->Estados[nomEstado].SubEstados=vec2;
                AF_deter->TransNueva(estado_act,nomEstado,Entradas[i]);
                for(int l=0;l<Estados.size();l++){
                    for(int ll=0;ll<vec2.size();ll++){
                        if(Estados[l].num==vec2[ll] && Estados[l].Es_Aceptacion==true)
                            AF_deter->Estados[nomEstado].Es_Aceptacion=true;
                    }
                }
                nomEstado++;
            }
            else{
                for(int l=0;l<AF_deter->Estados.size();l++){
                    if(vec2==AF_deter->Estados[l].SubEstados)
                        AF_deter->TransNueva(estado_act,AF_deter->Estados[l].num,Entradas[i]);
                }
            }
            vec.clear();
		}
        AF_deter->Estados[estado_act].Esta_marcado=true;
        estado_act++;
	}
    return AF_deter;
}

int main(int argc, char const *argv[])
{
    /*Para compilar

        g++ AFN_to_AFD.cpp -o AFN_to_AFD.out
        ./AFN_to_AFD.out > out.txt
    */
    Automata* AF_NoDeter=new Automata();	
    iniciar(AF_NoDeter);//inicializamos el automata no
    //                  //determinista
    Automata* AF_deter=AF_NoDeter->AFD();
    //
    AF_deter->MostrarSubestados();
    AF_deter->MostrarEstadosAcep();
    AF_deter->MostrarTrans();
    return 0;
}
