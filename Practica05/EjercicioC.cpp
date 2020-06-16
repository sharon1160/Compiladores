#include <stdio.h>
#include <ctype.h>
#include <cstring>
#include <string>
#include <iostream>
#include<stdlib.h>

#define MAS '+'
#define MENOS '-'
#define NUM 256
#define FIN -1

/* GRAMÁTICA  

Prog  --> I B F
B --> E p b

b --> B
b -->
E --> T e

e --> + T {print +} e
e --> - T {print -} e
e --> 

T --> F t

t --> * F {print *} t
t --> / F {print /} t
t --> 

F --> PI E PD
F -->  {print num} numero

p --> {print ;} ;

PI --> {print (} (
PD --> {print )} )

I --> {print Inicio} inicio

F --> {print Fin}  fin
*/

FILE *f;
char lexema[80];
int tok;

void parea(int);
void error();

void Prog();
void B();
void b();
void E();
void e();
void T();
void t();
void F();
void p();
void PI();
void PD();
void I();
void Fn();

int scanner();

void Prog()
{
	if (tok=='I'){ 
		I();
		B();
		Fn();
	}
	else
		error();
}

void B()
{
	if (tok != ' '){
		E();
		p();
		b();
	}
	else //cadena vacia
		;
}

void b()
{
	if (tok==NUM || tok=='('){ 
		B(); 
	}
	else
		;
}

void error()
{
	printf("\nError de sintaxis \n") ;
    	exit (-1) ;
}

void E(){
    T();
    e();
}

void e(){
    if(tok == MAS){
        parea(MAS);
        T();
        printf("+");
        e();
    }
    else if(tok == MENOS){
        parea(MENOS);
        T();
        printf("-");
        e();
    }
    else //cadena vacia
        ;
}

void T(){
    F();
    t();
}

void t(){
    if(tok == '*'){
        parea('*');
        F();
        printf("*");
        t();
    }
    else if(tok == '/'){
        parea('/');
        F();
        printf("/");
        t();
    }
    else //cadena vacia
        ;
}

void F(){
    if (tok==NUM){
        printf("%s",lexema);
        parea(NUM); 
    }
    else if (tok=='('){
        PI();
        E();
        PD();
    }
    else
        error();
}

void p(){
    printf(";\n");
    parea(';');
    if(tok!='F')
        printf("\t");
}

void PI(){
    parea('(');
}

void PD(){
    parea(')');
}

void I(){
    printf("Inicio\n");
    printf("\t");
    parea('I');    
}

void Fn(){
    printf("Fin");
    parea('F');    
}

void parea(int t)
{
	if (tok==t)
		tok=scanner();
	else
		error();
}

char inicio[6]={'I','n','i','c','i','o'};
int j=2;

char fin[6]={'F','i','n'};
int k=2;

int scanner()
{
    int c,i;
    do{
	if(feof(f))
	   break;
        c=fgetc(f);
    }while(c==' ' || c=='\n');
    if (c=='I')
        return c;
    if (c=='F')
        return c;
    if (c=='n'){
        do {
            if(feof(f))
		break;
            c=fgetc(f);
            if(j<6){
                if(inicio[j]!=c)
                    error();
                else
                    j++;
            }
            if(c=='(')
                break;
         } while(c==' ' || isdigit(c)==false || c=='\n');
    }
    if (c=='i'){
        do{
            c=fgetc(f);
            if(k<3){
                if(fin[k]!=c)
                    error();
                else
                    k++;
            }
        }while(feof(f)!=true);
    }
    if (c=='\n')
	return FIN;
    if (c==MAS || c==MENOS)
	return c;
    if (c=='*' || c=='/')
	return c;
    if (c=='(' || c==')')
	return c;
    if (c==';' )
	return c;
    if(isdigit(c)){
	i=0;
	do { 
	    lexema[i++]=c;
	    if(feof(f))
	       break;
	    c=fgetc(f);
	}while(isdigit(c));
	lexema[i]=0;
	ungetc(c,f);
	return NUM;
    }
}

int main()
{
    f=fopen("programa1.txt","rt");
    if(!f)
         printf("Error al abrir el archivo\n");
    tok=scanner();
    Prog();
    printf("\n");
    fclose(f);
    return 0;
}
