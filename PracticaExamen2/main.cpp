#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct nodo
{
    int dato;
    nodo *izq;
    nodo *der;
};

class Cola
{

public:
    queue<nodo *> elementos;
    void Push(nodo *c)
    {
        elementos.push(c);
    }

    nodo *Pop()
    {
        if (!elementos.empty())
        {
            nodo *c = elementos.front();
            elementos.pop();
            return c;
        }
        return NULL;
    }

    void imprimirCola()
    {
        queue<nodo *> temp = elementos;
        while (!temp.empty())
        {
            cout << temp.front()->dato << " ";
            temp.pop();
        }
        cout << endl;
    }
};

void imprimirArbolPorNivel(nodo *raiz)
{
    Cola cola;
    cola.Push(raiz);
    while (true)
    {
        int nodosEnNivel = cola.elementos.size();
        if (nodosEnNivel == 0)
        {
            break;
        }
        while (nodosEnNivel > 0)
        {
            nodo *nodoActual = cola.Pop();
            cout << nodoActual->dato << " ";
            if (nodoActual->izq)
            {
                cola.Push(nodoActual->izq);
            }
            if (nodoActual->der)
            {
                cola.Push(nodoActual->der);
            }
            nodosEnNivel--;
        }
    }
}

void preordenSinRecursion(nodo *raiz)
{
    stack<nodo *> pila;
    nodo *actual = raiz;
    while (actual != NULL || !pila.empty())
    {
        while (actual != NULL)
        {
            cout << actual->dato << " ";
            pila.push(actual);
            actual = actual->izq;
        }
        actual = pila.top();
        pila.pop();
        actual = actual->der;
    }
}

// Estructura de datos para almacenar un nodo de árbol binario
struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Función para recorrer el árbol binario en orden y almacenar los valores en un arreglo
void inorder(Node *root, vector<int> &arr)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

// Función para crear una nueva estructura con los valores ordenados
Node *createStructure(vector<int> &arr)
{
    // Crear un nodo centinela para facilitar la inserción
    Node *sentinel = new Node(-1);
    // Mantener un puntero al último nodo insertado
    Node *last = sentinel;
    // Recorrer el arreglo y crear un nuevo nodo por cada valor
    for (int val : arr)
    {
        Node *node = new Node(val);
        // Enlazar el nuevo nodo con el último nodo insertado
        node->left = last;
        last->right = node;
        // Actualizar el último nodo insertado
        last = node;
    }
    // Eliminar el nodo centinela y devolver el primer nodo de la nueva estructura
    Node *first = sentinel->right;
    delete sentinel;
    return first;
}
Node *convertIterative(Node *root)
{
    Node *sentinel = new Node(-1);
    Node *last = sentinel;
    Node *current = root;

    while (current != nullptr || last->right != nullptr)
    {
        if (current != nullptr)
        {
            Node *node = new Node(current->data);
            node->left = last;
            last->right = node;
            last = node;
            current = current->left;
        }
        else
        {
            current = last->right;
            last = last->right;
        }
    }

    Node *first = sentinel->right;
    delete sentinel;
    return first;
}

Node *insert(Node *root, int data)
{
    if (root == nullptr)
    {
        return new Node(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

Node *arrayToBST(int arr[], int n)
{
    Node *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    return root;
}

int main(int argc, char const *argv[])
{

    nodo *raiz = new nodo{1, NULL, NULL};
    raiz->izq = new nodo{2, NULL, NULL};
    raiz->der = new nodo{3, NULL, NULL};
    raiz->izq->izq = new nodo{4, NULL, NULL};
    raiz->izq->der = new nodo{5, NULL, NULL};
    raiz->der->izq = new nodo{6, NULL, NULL};
    raiz->der->der = new nodo{7, NULL, NULL};

    imprimirArbolPorNivel(raiz);

    raiz = new nodo{1, nullptr, nullptr};
    raiz->izq = new nodo{2, nullptr, nullptr};
    raiz->der = new nodo{3, nullptr, nullptr};
    raiz->izq->izq = new nodo{4, nullptr, nullptr};
    raiz->izq->der = new nodo{5, nullptr, nullptr};
    raiz->der->izq = new nodo{6, nullptr, nullptr};
    raiz->der->der = new nodo{7, nullptr, nullptr};

    preordenSinRecursion(raiz);

    int arr[] = {10, 25, 40, 55, 60, 75, 77, 80, 85};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = arrayToBST(arr, n);
    return 0;
}
