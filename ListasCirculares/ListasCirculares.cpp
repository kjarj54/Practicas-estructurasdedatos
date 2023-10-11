//---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>



struct nodo
{
	int n;
	nodo *sig;
	nodo *ant;
};
nodo *ini=NULL;
nodo *fin=NULL;
nodo *dato=NULL;
int op;
int val;
using namespace std;
void mostrar(nodo *l)
{
	if (l==NULL) {
		cout<<"La lista esta nula"<<endl;
	}
	else
	{
		cout<<l->n<<"->";
		while(l->sig!=ini)
		{
			cout<<l->sig->n<<"->";
			l=l->sig;
		}
		cout<<endl;
	}
}
void insertar(nodo *&p,int n)
{
	if (p==NULL) {
		dato=new struct nodo;
		dato->n=n;
		dato->sig=dato;
		dato->ant=dato;
		ini=dato;
		fin=dato;
	}
	else
	{
		if (p->n>n&&p->ant==fin) {
			dato= new struct nodo;
			dato->n=n;
			dato->sig=p;
			dato->ant=p->ant;
			p->ant->sig=dato;
			p->ant=dato;
			ini=dato;
		}
		else
		{
			if (p->n<n&&p->sig==ini) {
				dato= new struct nodo;
				dato->n=n;
				dato->sig=p->sig;
				dato->ant=p;
				p->sig->ant=dato;
				p->sig=dato;
				fin=dato;
			}
			else
			{
				if (p->n<n && p->sig->n>n) {
					dato = new struct nodo;
					dato->n=n;
					dato->sig=p->sig;
					p->sig->ant=dato;
					dato->ant=p;
					p->sig=dato;
				}
				else
				{
					insertar(p->sig,n);
				}
			}
		}
	}
}
int main()
{
	do
	{
		cout<<"1-Ingresar"<<endl;
		cout<<"2-Mostrar"<<endl;
		cin>>op;
		switch(op)
		{
			case 1:
				cout<<"Ingrese el dato"<<endl;
				cin>>val;
				insertar(ini,val);
				break;
			case 2:
				mostrar(ini);
				break;
		}
		cout<<"Ini:"<<ini->n<<endl;
		cout<<"Fin:"<<fin->n<<endl;
		getch();
	}while (true);
	return 0;
}
//---------------------------------------------------------------------------
