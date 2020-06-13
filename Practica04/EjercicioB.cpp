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
#include  <stdlib.h>
//#include <conio.h>
#include <ctype.h>

int tok;
bool flag =false;

void parea(int);
void error();
void Resto();
void Term();
int scanner();

void Exp()
{
	Term();
	Resto(); 
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
	else if (isdigit(tok))
	{
		error();
	}
	else //cadena vacia
		;
}

void Term()
{
	if (tok== '0'){ 
		printf("0");
	    parea('0'); 
		return;
	}
	else if (tok== '1'){ 
		printf("1");
	    parea('1'); 
		return;
	}
	else if (tok== '2'){ 
		printf("2");
	    parea('2');
		return; 
	}
	else if (tok== '3'){ 
		printf("3");
	    parea('3'); 
		return;
	}
	else if (tok== '4'){ 
		printf("4");
	    parea('4'); 
		return;
	}
	else if (tok== '5'){ 
		printf("5");
	    parea('5'); 
		return;
	}
	else if (tok== '6'){ 
		printf("6");
	    parea('6'); 
		return;
	}
	else if (tok== '7'){ 
		printf("7");
	    parea('7'); 
		return;
	}
	else if (tok== '8'){ 
		printf("8");
	    parea('8'); 
		return;
	}
	else if (tok== '9'){ 
		printf("9");
	    parea('9'); 
		return;
	}
	else
		error();
}

void error()
{
	printf("\nError de sintaxis\n");
	exit (-1);
}

void parea(int t)
{
	if (tok==t)
		tok=getchar();
	else
		error();
}

int main()
{
	tok=getchar();
	Exp();
	printf("\n");
	return 0;
}
