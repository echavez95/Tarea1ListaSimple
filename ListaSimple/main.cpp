#include <iostream>
#include <stdlib.h>

using namespace std;

class Elemento
{
    public:
        int Value;
        Elemento *NextElement;

    Elemento(int val)
    {
        Value=val;
        NextElement = 0;
    }

    ~Elemento(){}
};

class Lista
{
    public :
		int Size;
		Elemento *FirstElement;
		Elemento *LastElement;

	Lista ()
	{
        FirstElement = LastElement =0;
        Size = 0;
	}

    void Insert(int valor) /**Inserta un elemento al inicio**/
    {
        Elemento *nodo = new Elemento(valor);
        if(FirstElement==0)
        {
            FirstElement=LastElement=nodo;
        }
        else
            {
                nodo->NextElement=FirstElement;
                FirstElement=nodo;
            }
        Size++;
    }

    int Search(int valor) /**Busca un valor y devuelve la posicion del elemento en la lista**/
    {
        Elemento *NodoTemp = FirstElement;
        for(int i=0;i<Size;i++)
        {
            if(NodoTemp->Value==valor){
                return i;
            }
            NodoTemp=NodoTemp->NextElement;
        }
        return NULL;
    }

    int Get(int posicion) /**busca la posicion y devuelve el valor del elemento**/
    {
        Elemento *NodoTemp = FirstElement;
        if(posicion<Size){
            for(int i=0;i<posicion;i++)
            {
                NodoTemp=NodoTemp->NextElement;
            }
        }else{
            return NULL;
        }
        return NodoTemp->Value;
    }

    void DeleteValue(int valor) /**borra el elemento que contiene el valor de parametro**/
    {
        Elemento *NodoActual = FirstElement;
        Elemento *NodoAnterior=FirstElement;
        for(int i=0;i<Size;i++)
        {
            if(NodoActual->Value==valor)
            {
                if(NodoActual==FirstElement){
                    FirstElement=NodoActual->NextElement;
                    NodoActual=NULL;
                }
                else if(NodoActual==LastElement)
                {
                    LastElement=NodoAnterior;
                    LastElement->NextElement=0;
                    NodoActual=NULL;
                }
                else
                {
                    NodoAnterior->NextElement=NodoActual->NextElement;
                    NodoActual=NULL;
                }
                Size--;
                break;
            }
            NodoAnterior=NodoActual;
            NodoActual=NodoActual->NextElement;
        }
    }


    void Print() /**imprime la lista**/
    {
        Elemento *NodoTemp = FirstElement;
        for(int i=0;i<Size;i++)
        {
            cout<<NodoTemp->Value<<endl;
            NodoTemp=NodoTemp->NextElement;
        }
    }

    void printLastFirst() /**imprime el ultimo y el primer elemento de la lista**/
    {
        cout<<"Primero: "<<FirstElement->Value<<endl;
        cout<<"Ultimo: "<<LastElement->Value<<endl;
    }

};

int main()
{
    Lista listaEnteros;
    int res;
    int entero;
    int posicion;
    do{
        system("cls");
        cout << "EJEMPLO LISTA SIMPLE" << endl;
        cout << "1. Insertar Elemento" << endl;
        cout << "2. Obtener Posicion del Valor" << endl;
        cout << "3. Obtener Valor" << endl;
        cout << "4. Borrar Elemento" << endl;
        cout << "5. Ver Lista" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion" << endl;
        cin>>res;
        system("cls");
        switch(res)
        {
            case 1:
                cout << "Escriba un Numero: " << endl;
                cin>>entero;
                listaEnteros.Insert(entero);
                break;
            case 2:
                cout << "Escriba el valor a buscar: " << endl;
                cin>>entero;
                cout<<"Posicion: "<<listaEnteros.Search(entero)<<endl;
                system("pause");
                break;
            case 3:
                cout << "Escriba la posicion: " << endl;
                cin>>posicion;
                cout<<"Valor: "<<listaEnteros.Get(posicion)<<endl;
                system("pause");
                break;
            case 4:
                cout << "Escriba el valor a borrar: " << endl;
                cin>>entero;
                listaEnteros.DeleteValue(entero);
                cout<<"Elemento Borrado"<<endl;
                cout << "Lista:" << endl;
                listaEnteros.Print();
                system("pause");
                break;
            case 5:
                cout << "Lista:" << endl;
                listaEnteros.Print();
                system("pause");
                break;
        }
    }while(res!=0);
    return 0;
}
