// ejemplo de colas
#include <iostream>
using namespace std;

#define SIZE 5
int A[SIZE];
int front = -1;
int rear = -1;
//funci�n para checar si la cola est� vac�a
bool isempty()
{
	if(front == -1 && rear == -1)
		return true;
	else
		return false;
}
//funci�n para insertar un elemento en la cola
void enqueue ( int value )
{
	if (rear == SIZE-1)
		cout<<"La cola esta llena!!! \n";
	else
	{
		if( front == -1)
			front = 0;
		rear++;
		A[rear] = value;
	}
}
//funci�n para eliminar un elemento de la cola
void dequeue ( )
{
	if( isempty() )
		cout<<"La cola esta llena!!! \n";
	else
		if( front == rear )
		front = rear = -1;
		else
			front++;
}
//funci�n que muestra un elemento al frente
void showfront( )
{
	if( isempty())
		cout<<"La cola esta vacia!!!\n";
	else
		cout<<"Elemento al frente es: "<<A[front]<<"\n";
}
//funci�n para mostrar los elementos de la cola
void mostrarCola()
{
	if(isempty())
		cout<<"La cola esta vacia!!!\n";
	else
	{
		for( int i=front ; i<= rear ; i++)
			cout<<A[i]<<" ";
		cout<<"\n";
	}
}

int main()
{
	//insertando elementos en la cola
	cout<<"Insertando elementos en la cola\n";
	enqueue(2);
	mostrarCola();
	enqueue(3);
	mostrarCola();
	enqueue(5);
	mostrarCola();
	enqueue(7);
	mostrarCola();
	enqueue(8);
	
	mostrarCola();
	// la cola est� llena
	enqueue(9);
	//muestra el elemento del frente
	showfront();
	
	cout<<"Eliminando elementos de la cola\n";
	//elminando elementos de la cola
	dequeue();
	mostrarCola();
	dequeue();
	mostrarCola();
	dequeue();
	mostrarCola();
	dequeue();
	mostrarCola();
	dequeue();
	
	return 0;
}