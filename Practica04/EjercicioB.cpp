/* Analizador Sintáctico de Infija a Postfija 
Exp --> Term Resto
Resto --> + Term {printf("+")} Resto
Resto --> - Term {printf("-")} Resto
Resto -->
Term --> {printf("0")} 0
Term --> {printf("1")} 1
...
Term --> {printf("9")} 9
*/

#include <stdio.h>
//#include <conio.h>
#include <ctype.h>


#define FIN -1

char lexema[80];
int tok;

void parea(int);
void error();
void Resto();
void Term();
int scanner();

int NUM(int tok){
	switch (tok)
	{
		case 0:
			return 0;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 3;
			break;
		case 4:
			return 4;
			break;
		case 5:
			return 5;
			break;
		case 6:
			return 6;
			break;
		case 7:
			return 7;
			break;
		case 8:
			return 8;
			break;
		case 9:
			return 9;
			break;
		default:{
			return -1;
		 	break;
		}
	}
}

void Exp()
{
	if (tok==NUM(tok)){ 
		Term();
	    Resto(); 
	}
	else
		error();
}

void Resto()
{
	if (tok == '+'){
		parea('+');
		Term();
		printf("+");
		Resto();
	}
	else if (tok == '-'){
		parea('-');
		Term();
		printf("-");
		Resto();
	}
	else //cadena vacia
		;
}

void Term()
{
	if (tok==NUM(tok)){ 
		printf("%s",lexema);
	    parea(NUM(tok)); 
	}
	else
		error();
}

void error()
{
	printf("Error de sintaxis");
	printf("\n");
}

void parea(int t)
{
	if (tok==t)
		tok=scanner();
	else
		error();
}

int scanner()
{
	int c,i;
	do c=getchar(); while(c==' ');
	if (c=='\n')
		return FIN;
	if (c=='+' || c=='-')
		return c;
	if(isdigit(c))
	{
		i=0;
		do { 
			lexema[i++]=c;
			c=getchar();
		}while(isdigit(c));
			lexema[i]=0;
			ungetc(c,stdin);
			return NUM(tok);
	}
}

int main()
{
	tok=scanner();
	Exp();
	printf("\n");
	return 0;
}
