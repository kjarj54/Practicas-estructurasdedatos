#include <iostream>
#include <Stack>
#include <stdlib.h>
using namespace std;

struct nodo
{
	int dato;
	nodo *izq;
	nodo *der;
};

void insertarRec(nodo *&t, int x)
{
	if (t == NULL)
	{
		t = new struct nodo;
		t->dato = x;
		t->izq = NULL;
		t->der = NULL;
	}
	else
	{
		if (t->dato < x)
		{
			insertarRec(t->der, x);
		}
		else
		{
			if (t->dato > x)
			{
				insertarRec(t->izq, x);
			}
		}
	}
}
void Insertar(nodo *&t, int x)
{
	if (t == NULL)
	{
		t = new struct nodo;
		t->dato = x;
		t->izq = NULL;
		t->der = NULL;
	}
	else
	{
		nodo *aux = t;
		while (aux != NULL)
		{
			if (x < aux->dato)
			{
				if (aux->izq != NULL)
				{
					aux = aux->izq;
				}
				else
				{
					aux->izq = new nodo;
					aux->izq->dato = x;
					aux->izq->izq = NULL;
					aux->izq->der = NULL;
					aux = NULL;
				}
			}
			else
			{
				if (aux->der != NULL)
				{
					aux = aux->der;
				}
				else
				{
					aux->der = new nodo;
					aux->der->dato = x;
					aux->der->izq = NULL;
					aux->der->der = NULL;
					aux = NULL;
				}
			}
		}
	}
}
void preOrden(nodo *t)
{
	if (t != NULL)
	{

		cout << t->dato << " - ";
		preOrden(t->izq);
		preOrden(t->der);
	}
}
void eliminar(nodo *&n, int x)
{
	bool bo;
	if (n != NULL)
	{
		if (n->dato < x)
		{
			eliminar(n->der, x);
		}
		else
		{
			if (n->dato > x)
			{
				eliminar(n->izq, x);
			}
			else
			{
				nodo *otro = n;
				if (otro->der == NULL)
				{
					n = otro->izq;
				}
				else
				{
					if (otro->izq == NULL)
					{
						n = otro->der;
					}
					else
					{
						nodo *aux = n->izq;
						nodo *aux1 = NULL;
						bo = false;
						while (aux->der != NULL)
						{
							aux1 = aux;
							aux = aux->der;
							bo = true;
						}
						// dos opciones trasladar el valor y mantener las referencias
						// trasladar los nodos y cuidar las referencias
						n->dato = aux->dato;
						otro = aux;
						if (bo == true)
						{
							aux1->der = aux->izq;
						}
						else
						{
							n->izq = aux->izq;
						}
					}
				}
			}
		}
	}
}

// Metodos Recursivos
//  PostOrden
void postOrden(nodo *t)
{
	if (t != NULL)
	{
		postOrden(t->izq);
		postOrden(t->der);
		cout << t->dato << " - ";
	}
}

// InOrden

void inOrden(nodo *t)
{
	if (t != NULL)
	{
		inOrden(t->izq);
		cout << t->dato << " - ";
		inOrden(t->der);
	}
}

// Metodos iterativos
// preOrdenIterativo
void preOrdenIterativo(nodo *t)
{
	nodo *actual = t;
	while (actual != NULL)
	{
		if (actual->izq == NULL)
		{
			cout << actual->dato << " - ";
			actual = actual->der;
		}
		else
		{
			nodo *pre = actual->izq;
			while (pre->der != NULL && pre->der != actual)
			{
				pre = pre->der;
			}
			if (pre->der == NULL)
			{
				cout << actual->dato << " - ";
				pre->der = actual;
				actual = actual->izq;
			}
			else
			{
				pre->der = NULL;
				actual = actual->der;
			}
		}
	}
}

// inOrdenIterativo
void inOrdenIterativo(nodo *t)
{
	nodo *actual = t;
	while (actual != NULL)
	{
		if (actual->izq == NULL)
		{
			cout << actual->dato << " - ";
			actual = actual->der;
		}
		else
		{
			nodo *pre = actual->izq;
			while (pre->der != NULL && pre->der != actual)
			{
				pre = pre->der;
			}
			if (pre->der == NULL)
			{
				pre->der = actual;
				actual = actual->izq;
			}
			else
			{
				pre->der = NULL;
				cout << actual->dato << " - ";
				actual = actual->der;
			}
		}
	}
}
// postOrdenIterativo
void postOrdenIterativo(nodo *t)
{
	if (t == NULL)
		return;

	stack<pair<nodo *, bool>> pila;
	pila.push(make_pair(t, false));

	while (!pila.empty())
	{
		nodo *actual = pila.top().first;
		bool visitado = pila.top().second;
		pila.pop();

		if (actual == NULL)
			continue;

		if (visitado)
		{
			cout << actual->dato << " - ";
		}
		else
		{
			pila.push(make_pair(actual, true));
			pila.push(make_pair(actual->der, false));
			pila.push(make_pair(actual->izq, false));
		}
	}
}
int altura(nodo *t)
{
	if (t == NULL)
		return -1; // Si el nodo es nulo, su altura es -1
	else
	{
		// Calculamos la altura de los subárboles izquierdo y derecho
		int altura_izquierda = altura(t->izq);
		int altura_derecha = altura(t->der);

		// La altura del nodo es el máximo entre la altura del subárbol izquierdo y derecho, más 1 (por el nodo actual)
		return 1 + max(altura_izquierda, altura_derecha);
	}
}

nodo *rotacionII(nodo *t)
{
	nodo *temp = t->izq;
	t->izq = temp->der;
	temp->der = t;
	return temp;
}

void insertarII(nodo *&t, int x)
{
	if (t == NULL)
	{
		t = new struct nodo;
		t->dato = x;
		t->izq = NULL;
		t->der = NULL;
	}
	else
	{
		if (x < t->dato)
		{
			insertarII(t->izq, x);

			// Verificamos si el árbol se ha desbalanceado hacia la izquierda
			if (altura(t->izq) - altura(t->der) > 1)
			{
				// Aplicamos la rotación izquierda-izquierda
				t = rotacionII(t);
			}
		}
		else if (x > t->dato)
		{
			// Insertar normalmente en la rama derecha
			insertarII(t->der, x);
		}
	}
}

void DI(nodo *& n){
	nodo * nod = NULL;
	nodo * nod1 = NULL;
	
}

// Insertar Recursivo
// ver las Hojas de un arbol
// Ver los nodos medios de un arbol
// Mostrar los nodos que tenga sus hijos completos(izq,der)
// Invertir un arbol (recursivo)
// Buscar un valor en un arbol binario de busqueda, devolver true o false.
// realizarlo con POO
void verArbol(nodo *arbol, int n) // analizar y entender esta funci�n
{
	if (arbol == NULL)
	{
		return;
	}
	verArbol(arbol->der, n + 1);
	for (int i = 0; i < n; i++)
	{
		cout << "    ";
	}
	cout << arbol->dato << endl;
	verArbol(arbol->izq, n + 1);
}
nodo *raiz = NULL;
int main(int argc, char *argv[])
{
	Insertar(raiz, 50);
	Insertar(raiz, 25);
	Insertar(raiz, 75);
	Insertar(raiz, 10);
	Insertar(raiz, 30);
	Insertar(raiz, 5);
	Insertar(raiz, 15);
	Insertar(raiz, 28);
	Insertar(raiz, 35);
	Insertar(raiz, 60);
	Insertar(raiz, 80);
	Insertar(raiz, 55);
	Insertar(raiz, 73);
	Insertar(raiz, 78);
	Insertar(raiz, 87);
	cout << "Arbol" << endl;
	verArbol(raiz, 1);

	cout << "Preorden" << endl;
	preOrden(raiz);
	cout << "\nPreorden Iterativo" << endl;
	preOrdenIterativo(raiz);

	cout << "\nPostOrden" << endl;
	postOrden(raiz);
	cout << "\nPostorden Iterativo" << endl;
	postOrdenIterativo(raiz);

	cout << "\ninOrden" << endl;
	inOrden(raiz);
	cout << "\nInorden Iterativo" << endl;
	inOrdenIterativo(raiz);

	return 0;
}
