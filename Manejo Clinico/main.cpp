#include <iostream>
using namespace std;

class Persona
{
public:
    string cedula;
    string nombre;
    string apellido;
    int edad;
    char sexo;
    string telefono;
    bool seguro;
};

class Nodo
{
private:
    Nodo *sig;
    Nodo *ant;
    Persona p;

public:
    Nodo()
    {
        sig = NULL;
        ant = NULL;
    }

    Nodo(Nodo *s, Nodo *a, Persona &per)
    {
        sig = s;
        ant = a;
        p = per;
    }

    void setSig(Nodo *s)
    {
        sig = s;
    }

    void setAnt(Nodo *a)
    {
        ant = a;
    }

    Nodo *getSig()
    {
        return sig;
    }

    Nodo *getAnt()
    {
        return ant;
    }

    Persona setPersona(Persona per)
    {
        p = per;
    }

    Persona getPersona()
    {
        return p;
    }
};

class Lista
{
private:
    Nodo *ini;

public:
    Lista()
    {
        ini = NULL;
    }
    void insertar(Persona &p)
    {
        Nodo *aux = NULL;

        if (ini == NULL)
        {
            ini = new class Nodo(NULL, NULL, p);
        }
        else
        {
            aux = ini;
            while (aux->getSig() != NULL && p.apellido > aux->getPersona().apellido)
            {
                aux = aux->getSig();
            }
            Nodo *nuevo = new class Nodo(aux->getSig(), aux, p);
            if (aux->getSig() != NULL)
            {
                aux->getSig()->setAnt(nuevo);
            }
            aux->setSig(nuevo);
        }
    }

    void mostrarNombres()
    {
        Nodo *aux = ini;
        while (aux)
        {
            cout << aux->getPersona().apellido << " " << aux->getPersona().nombre;
            aux = aux->getSig();
        }
    }

    void porcentajeEdad()
    {
        int ninos = 0, joven = 0, adult = 0;

        Nodo *aux = ini;

        while (aux)
        {
            if (aux->getPersona().edad <= 13)
            {
                ninos++;
            }
            else if (aux->getPersona().edad > 13 && aux->getPersona().edad <= 30)
            {
                joven++;
            }
            else if (aux->getPersona().edad <= 30)
            {
                adult++;
            }
            aux->getSig();
        }

        int totalPacientes = ninos + joven + adult;

        cout << "Porcentaje de niños: " << (ninos * 100.0) / totalPacientes << "%" << endl;
        cout << "Porcentaje de jóvenes: " << (joven * 100.0) / totalPacientes << "%" << endl;
        cout << "Porcentaje de adultos: " << (adult * 100.0) / totalPacientes << "%" << endl;
    }

    void porcentajeHM()
    {
        Nodo *aux = ini;

        int f = 0, m = 0;

        while (aux)
        {
            if (aux->getPersona().sexo == 'm')
            {
                m++;
            }
            else
            {
                f++;
            }
            aux->getSig();
        }

        int total = f + m;

        cout << "Porcentaje de hombres: " << (m * 100.0) / total << "%\n";
        cout << "Porcentaje de mujeres: " << (f * 100.0) / total << "%\n";
    }

    void datosPaciente(int cedula)
    {

    }

    void porcentajeSeguros()
    {
        Nodo *aux = ini;

        int con = 0, sin = 0;

        while (aux)
        {
            if (aux->getPersona().seguro == true)
            {
                con++;
            }
            else
            {
                sin++;
            }
            aux->getSig();
        }

        int total = con + sin;
        cout << "Porcentaje de asegurados es: " << (con * 100.0) / total << "%\n";
        cout << "Porcentaje de no asegurados es: " << (sin * 100.0) / total << "%\n";
    }
    void bajaPaciente(int cedula)
    {

    }
};

int main(int argc, char const *argv[])
{
    Lista l;
    int opcion;
    do
    {
        cout << "Menu:" << endl;
        cout << "1. Listar nombres de pacientes" << endl;
        cout << "2. Obtener porcentaje por categorias de edad" << endl;
        cout << "3. Obtener porcentaje de hombres y mujeres" << endl;
        cout << "4. Mostrar datos de un paciente" << endl;
        cout << "5. Calcular porcentaje de pacientes con seguro" << endl;
        cout << "6. Dar de baja a un paciente" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        if (opcion == 1)
        {
            l.mostrarNombres();
        }
        else if (opcion == 2)
        {
            l.porcentajeEdad();
        }
        else if (opcion == 3)
        {
            l.porcentajeHM();
        }
        else if (opcion == 4)
        {
            int cedula;
            cout<<"Introdusca la cedula del paciente que desea dar de baja\n";
            cin>>cedula;
            l.datosPaciente(cedula);
        }
        else if (opcion == 5)
        {
            l.porcentajeSeguros();
        }
        else if (opcion == 6)
        {
            int cedula;
            cout<<"Introdusca la cedula del paciente que desea dar de baja\n";
            cin>>cedula;
            l.bajaPaciente(cedula);
        }
    } while (opcion != 7 || opcion < 7);
    return 0;
}
