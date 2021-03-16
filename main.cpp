#include <iostream>

using namespace std;

int numeros[] = {1,4,2,45,34,3,5,6};

//Esta función retorna la cantidad de elementos contenido en el arreglo
int GetTamano()
{
    return sizeof(numeros) / sizeof(int);
}

//Intercambia los valores de dos posiciones del arreglo
void Intercambiar(int a, int b)
{
    int temp = numeros[a];
    numeros[a] = numeros[b];
    numeros[b] = temp;
}

//Esta función imprime el valor de cada elemento del arreglo de números
void Imprimir()
{
    int tamano = GetTamano();
    for(int i = 0 ; i < tamano ; i++)
    {
        cout << numeros[i] << "\t";
    }
    cout << endl;
}

//Esta función ordena un arreglo utilizando el algoritmo de ordenamiento llamado burbuja.
void Ordenar()
{
    int tamano = GetTamano();
    for(int i = 0 ; i < tamano; i++)
    {
        for(int j = 0; j < tamano -1; j++)
        {
            if(numeros[j] > numeros[j+1])
            {
                Intercambiar(j,j+1);
            }
        }
    }
}

bool BusquedaLineal(int numero)
{
    int tamano = GetTamano();
    for(int i = 0 ; i < tamano ; i++)
    {
        if(numeros[i] == numero)
        {
            return true;
        }
    }
    return false;
}

bool BusquedaBinaria(int numero)
{
    int tamano = GetTamano();
    int limiteIzquierdo = 0;
    int limiteDerecho = tamano -1;
    int puntoMedio;
    while(limiteIzquierdo <= limiteDerecho)
    {
        puntoMedio = (limiteIzquierdo + limiteDerecho) / 2;
        if(numeros[puntoMedio] < numero)
        {
            limiteIzquierdo = puntoMedio + 1;
        }
        else if(numeros[puntoMedio] > numero)
        {
            limiteDerecho = puntoMedio + 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main()
{
    // Imprimir();
    Ordenar();
    // Imprimir();
    int numero;
    cout << "Introduzca el número que desea buscar: ";
    cin >> numero;
    if(BusquedaBinaria(numero))
    {
        cout << "El número " << numero << " está contenido en el arreglo" << endl;
    }
    else
    {
        cout << "El número " << numero << " NO está contenido en el arreglo" << endl;
    }

    return 0;
}
