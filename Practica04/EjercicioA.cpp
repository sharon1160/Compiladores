#include <stdio.h>
//#include <conio.h>
#include <iostream>

using namespace std;

int preanalisis;

void parea(int);
void A();
void B();
void error();


void S()
{
	if(preanalisis=='x')
	{
		parea('x');
		S();
	}
	else if(preanalisis =='a' )
	{
		A();
		B();
		parea('c');
	}
	else
		error();
}
void A()
{
	if(preanalisis=='a')
		parea('a');
	else
		error();
}
void B()
{
	if(preanalisis == 'b')
		parea('b');
	else
		error();
}
void error()
{
	cout<<"Error de sintaxis"<<endl;
}
void parea(int t)
{
	if(preanalisis==t)
		preanalisis=getchar();
	else 
		error();
}


int main(int argc, char const *argv[])
{
	preanalisis=getchar();
	S();
	return 0;
}

