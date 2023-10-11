#include <iostream>

using namespace std;

struct lista{
	int n;
	lista *sig;
	
}*ini=NULL,*aux=NULL, *dato = NULL;

void mostrar(lista *l){
 	lista *aux=l;
	while(aux!=NULL){
		cout<<aux->n<<"->";
		aux=aux->sig;
	}	
}
/*
void ingresar(lista *l, int n){
	aux=1;
	while(){
		aux=aux->sig;
	}
	aux=new lista;
	aux->n=x;
	aux-sig=NULL;
}
*/

void insertar(int x){
	aux=ini;
	dato=new lista;
	dato->n=x;
	dato->sig=NULL;
	if(aux==NULL){
		ini=dato;
	}else{
		while(aux->sig !=NULL){
			aux=aux->sig;
		}
		aux->sig=dato;
	}
}

void insertarOrdenado(int x){
	lista* nuevo = NULL;

    if (ini == NULL || x < ini->n) {
        nuevo->sig = ini;
        ini = nuevo;
    } else {
        lista* aux = ini;
        while (aux->sig != NULL && aux->sig->n < x) {
            aux = aux->sig;
        }
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    }
}

void x(lista *&p, int n){
	if(p!=NULL){
		x(p->sig,n);
	}else{
		dato=new lista;
		dato->n=n;
		dato->sig=NULL;
		p=dato;
	}
}

int main(int argc, char** argv) {   
    insertar(5);
    insertar(10);
    insertar(15);
    
    mostrar(ini);
    
    lista *list=NULL;
    
    x(list,1);
    x(list,4);
    x(list,3);
    
    mostrar(list);


    return 0;
}

