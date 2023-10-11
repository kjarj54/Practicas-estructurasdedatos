#include<iostream>
#include<stdlib.h>
using namespace std;
class nodo
{
private:
	int n;
	nodo *sig;
	nodo *ant;
public:
	nodo()
	{
		n=0;
		sig=NULL;
		ant=NULL;
	}
	nodo (int n1, nodo *s, nodo *a)
	{
		n=n1;
		sig=s;
		ant=a;
	}
	void setN(int n1)
	{
		n=n1;
	}
	void setSig(nodo *s)
	{
		sig=s;
	}
	void setAnt(nodo *a)
	{
		ant=a;
	}
	int getN()
	{
		return n;
	}
	nodo*& getSig()
	{
		return sig;
	}
	nodo*& getAnt()
	{
		return ant;
	}
};
class Cola
{
private:
	nodo *ini;
	nodo *fin;
public:
	Cola()
	{
		ini=NULL;
		fin=NULL;
	}
	void push( int n)
	{
		nodo *dato=NULL;
		if (ini==NULL)
		{
			ini=new nodo(n,NULL,NULL);
			fin=ini;
		}
		else
		{
			dato=new nodo(n,NULL,fin);
			fin->setSig(dato);
			fin=dato;
		}
	}
	void pushOrdenado(int n) {
        nodo* nuevoNodo = new nodo(n, NULL, NULL);

        if (ini == NULL) {
            // La lista está vacía, el nuevo nodo se convierte en el inicio y fin de la lista.
            ini = nuevoNodo;
            fin = nuevoNodo;
        } else if (n < ini->getN()) {
            // El nuevo nodo debe ser el nuevo inicio de la lista.
            nuevoNodo->setSig(ini);
            ini->setAnt(nuevoNodo);
            ini = nuevoNodo;
        } else if (n >= fin->getN()) {
            // El nuevo nodo debe ser el nuevo fin de la lista.
            nuevoNodo->setAnt(fin);
            fin->setSig(nuevoNodo);
            fin = nuevoNodo;
        } else {
            // El nuevo nodo debe ser insertado en algún lugar en el medio de la lista.
            nodo* actual = ini;

            while (actual->getN() < n) {
                actual = actual->getSig();
            }

            nuevoNodo->setSig(actual);
            nuevoNodo->setAnt(actual->getAnt());
            actual->getAnt()->setSig(nuevoNodo);
            actual->setAnt(nuevoNodo);
        }
    }
	int pop()
	{
		int n=ini->getN();
		ini=ini->getSig();
		return n;
	}
	int top()
	{
		return ini->getN();
	}
	
};
int main (int argc, char *argv[]) {
	
	return 0;
}
