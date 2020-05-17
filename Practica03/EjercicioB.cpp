#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
//:::::::::: DEFINE ::::::::::::
#define ID 256
#define NUM 257
//::::::::::::::::::::::::::::::
#define MAYOR '>'
#define MENOR '<'
#define IGUAL '='
#define MAYORIGUAL 258
#define MENORIGUAL 261
#define DOBLEIGUAL 262
#define DIFERENT 263
//::::::::::::::::::::::::::::::
#define CORCHOPEN '['
#define CORCHCLOSE ']'
#define PAREOPEN '('
#define PARECLOSE ')'
#define LLAVEOPEN '{'
#define LLAVECLOSE '}'
//::::::::::::::::::::::::::::::
#define PUNTOYCOMA ';'
#define COMA ','
//::::::::::::::::::::::::::::::
#define WHILE 259
#define FOR 267
#define IF 260
#define DO 265
#define SWITCH 266
#define ELSE 264
//::::::::::::::::::::::::::::::
#define MAS '+'
#define MULT '*'
#define DIV '/'
#define MENOS '-'
//::::::::::::::::::::::::::::::

using namespace std;

FILE *f;
char lexema[80];
int tok;

int palabras_reservadas(){//palabras reservadas
	if(strcmp(lexema,"while")==0)
		return WHILE;
	if(strcmp(lexema,"if")==0)
		return IF;
	if(strcmp(lexema,"for")==0)
		return FOR;
	if(strcmp(lexema,"switch")==0)
		return SWITCH;
	if(strcmp(lexema,"else")==0)
		return ELSE;
	if(strcmp(lexema,"do")==0)
		return DO;
	return -1;
}

int scanner(){//analizador lexico
	int c,c2;
	do{
		c = fgetc(f); 
	}while(c == ' ');
	if(c=='\n')
		return -1;
	if(c == MAS || c == MENOS)
		return c;
	if(isalpha(c)){
		int i=0;
		do{
			lexema[i++]=c;
			c=fgetc(f);
		}while(isalnum(c) || c=='_');
		lexema[i]=0;
		ungetc(c,f);
		i=palabras_reservadas();
		if(i>=0)
			return i;
		else
			return ID;
	}
	if(isdigit(c)){
		int i=0;
		do{lexema[i++]=c; c=fgetc(f);}
		while(isdigit(c));
		lexema[i]=0;
		ungetc(c,f);
		return NUM;
	}
	if(c=='/'){
		c=fgetc(f);
		if(c=='/'){
			do{c=fgetc(f);}while(c!='\n');
			return -1;
		}
		else if(c=='*'){
			while(1){
				c=fgetc(f);
				if(c=='*'){
					c=fgetc(f);
					if(c=='/')
						break;
				}
			}
			c=fgetc(f);
			return -1;
		}
		else
			return c;
	}
	if((c==';')||(c==',')||(c=='(')||(c==')')||(c=='{')||(c=='}')||(c=='[')||(c==']')){
		lexema[0]=c;
		return c;
	}
	if((c=='+')||(c=='-')||(c=='*')){
		return c;
	}
	if(c=='>'){
		c=fgetc(f);
		if(c=='='){
			lexema[0]='>';lexema[1]='=';
			return MAYORIGUAL;
		}
		ungetc(c,f);
		lexema[0]='>';
		return MAYOR;
	}
	if(c=='<'){
		c=fgetc(f);
		if(c=='='){
			lexema[0]='<';lexema[1]='=';
			return MENORIGUAL;
		}
		ungetc(c,f);
		lexema[0]='<';
		return MENOR;
	}
	if(c=='='){
		c=fgetc(f);
		if(c=='='){
			lexema[0]='=';lexema[1]='=';
			return DOBLEIGUAL;
		}
		ungetc(c,f);
		lexema[0]='=';
		return IGUAL;
	}
	if(c=='!'){
		c=fgetc(f);
		if(c=='='){
			lexema[0]='!';lexema[1]='=';
			return DIFERENT;
		}
		ungetc(c,f);
	}
}
//vaciamos el arreglo
void VaciarArray(char arr[],int n=80){
	for(int i=0; i < n ;i++)
		arr[i]=0;
}

void mostrar(int token){

	switch(token)
	{
		case ID:
			printf("token=ID[%s]\n",lexema);
			VaciarArray(lexema);
			break;
		case NUM:
			printf("token=NUM[%s]\n",lexema);
			VaciarArray(lexema);
			break;
		case MAYOR:
			printf("token=MAYOR[%s]\n",lexema);
			VaciarArray(lexema);
			break;
		case MAYORIGUAL:
			printf("token=MAYORIGUAL[%s]\n",lexema);
			VaciarArray(lexema);
			break;
		case MENOR:
			printf("token=MENOR[%s]\n",lexema);
			VaciarArray(lexema);
			break;
		case MENORIGUAL:
			printf("token=MENORIGUAL[%s]\n",lexema);
			VaciarArray(lexema);
			break;
		case IGUAL:
			printf("token=IGUAL[%s]\n",lexema);
			VaciarArray(lexema);
			break;
		case DOBLEIGUAL:
			printf("token=DOBLEIGUAL[%s]\n",lexema);
			VaciarArray(lexema);
			break;
		case WHILE:
			printf("token=WHILE[%s]\n",lexema);
			VaciarArray(lexema);
			break;
		case IF:
			printf("token=IF[%s]\n",lexema);
			VaciarArray(lexema);
			break;
		case ELSE:
			printf("token=ELSE[%s]\n",lexema);
			VaciarArray(lexema);
			break;
		case DO:
			printf("token=DO[%s]\n",lexema);
			VaciarArray(lexema);
			break;
		case SWITCH:
			printf("token=SWITCH[%s]\n",lexema);
			VaciarArray(lexema);
			break;
		case FOR:
			printf("token=FOR[%s]\n",lexema);
			VaciarArray(lexema);
			break;
		case PAREOPEN:
			printf("token=PAREOPEN[%s]\n",lexema);
			VaciarArray(lexema);
			break;
		case PARECLOSE:
			printf("token=PARECLOSE[%s]\n",lexema);
			VaciarArray(lexema);
			break;
		case LLAVEOPEN:
			printf("token=LLAVEOPEN[%s]\n",lexema);
			VaciarArray(lexema);
			break;
		case LLAVECLOSE:
			printf("token=LLAVECLOSE[%s]\n",lexema);
			VaciarArray(lexema);
			break;
		case CORCHOPEN:
			printf("token=CORCHOPEN[%s]\n",lexema);
			VaciarArray(lexema);
			break;
		case CORCHCLOSE:
			printf("token=CORCHCLOSE[%s]\n",lexema);
			VaciarArray(lexema);
			break;
		case PUNTOYCOMA:
			printf("token=PUNTOYCOMA[%s]\n",lexema);
			VaciarArray(lexema);
			break;
		case COMA:
			printf("token=COMA[%s]\n",lexema);
			VaciarArray(lexema);
			break;
		case MAS:
			printf("token=MAS[+]\n");
			break;
		case MENOS:
			printf("token=MENOS[-]\n");
			break;
		case MULT:
			printf("token=MULT[%s]\n",lexema );
			VaciarArray(lexema);
			break;
		case DIV:
			printf("token=DIV[%s]\n",lexema );
			VaciarArray(lexema);
			break;
	}
}

int main(int n,char *pal[]){
	int token;
	char opc;
	cout<<"::::::: MENU :::::::"<<endl;
	cout<<"a) Leer entrada por archivo "<<endl;
	cout<<"b) Leer entrada por consola "<<endl;
	cin>>opc;
	cout<<endl;
	if(opc=='a')
		n=2;
	else if(opc=='b')
		f=stdin;
	if(n==2){
		f=fopen("archivo.txt","rt");
		if(!f){
			printf("Error al abrir el archivo\n");
			f=stdin;
		}
	}
	if(f==stdin)
		printf("Ingrese una entrada : (ctrl z para finalizar)\n");
	while(1){
		token=scanner();
		if(feof(f))
			break;
		mostrar(token);
	}
	if(f!=stdin){
		fclose(f);
	}
	return 0;
}
