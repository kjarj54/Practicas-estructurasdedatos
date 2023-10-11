// ejemplo de pila
#include <iostream>
using namespace std;

#define SIZE 5
int A[SIZE];
int top = -1;

bool isempty()
{
	if(top==-1)
		return true;
	else
		return false;
}

void push(int valor)
{
	if(top==SIZE-1)
	{    cout<<"La pila esta llena!!!\n";
	}
	else
	{
		top++;
		A[top]=valor;
	}
}

void pop()
{
	if(isempty())
		cout<<"La pila esta vacia!!!\n";
	else
		top--;
}

void muestra_top()
{
	if(isempty())
		cout<<"La pila esta vacia!!!\n";
	else
		cout<<"Elemento de arriba (top) es  is: "<<A[top]<<"\n";
	
}

void muestraPila()
{
	if(isempty())
	{
		cout<<"La pila esta vacia!!!\n";
	}
	else
	{
		for(int i=0 ; i<=top; i++)
			cout<<A[i]<<" ";
		cout<<"\n";
		
	}
	
}

int main()
{
	
	int opcion, flag=1, valor;
	while( flag == 1)
	{
		cout<<"\n1.PUSH 2.POP 3.MUESTRA_TOP 4.MUESTRA_PILA 5.SALIR\n";
		cin>>opcion; switch (opcion)
		{
		case 1: cout<<"Digite el valor:\n";
		cin>>valor;
		push(valor);
		break;
		case 2: pop();
		break;
		case 3: muestra_top();
		break;
		case 4: muestraPila();
		break;
		case 5: flag = 0;
		break;
		}
	}
	return 0;
}