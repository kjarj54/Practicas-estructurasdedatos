struct lista{
	int n;
	lista *sig
	
}*ini=null,*aux=null, *dato = null;


void mostrar(lista *l){
 	aux=1;
	while(aux!=null){
		cout<<aux->n<<"->";
		aux=aux->sig;
	}	
}

void ingresar(lista *l, int n){
	aux=1;
	while(){
		aux=aux->sig;
	}
	aux=new lista;
	aux->n=x;
	aux-sig=null;
}

void insertar(int n){
	aux=ini;
	dato=new lista;
	dato->n=x;
	dato->sig=NULL;
	if(aux==NULL){
		ini=dato;
	}else{
		while(aux-sig !=NULL){
			aux=aux-sig;
		}
		aux->sig=dato;
	}
}