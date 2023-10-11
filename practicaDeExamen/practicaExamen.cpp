#include <iostream>
using namespace std;

struct Ventas
{
    /* data */
    int cantVen;
    Ventas *sig;

}*auxVe=NULL,*dato;


struct Empleado
{
    /* data */
    Empleado *sig;
    string nombre;
    Ventas *ventas;

}*auxEmp=NULL;

struct Piso
{
    /* data */
    Piso *sig;
    int numero;
    Empleado *empleados;
}*ini=NULL,*aux=NULL;


void insertarVen(int n){
    //auxVe= "";
    dato= new Ventas;
    dato->cantVen=n;
    dato->sig=NULL;
    

}


int main(int argc, char const *argv[])
{
    /* code */
    cout<<"Hello world";
    return 0;
}


