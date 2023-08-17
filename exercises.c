#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) {
    if (size <= 0) {
        // Manejar caso de arreglo vacío o inválido
        return -1; 
    }

    int maxElement = arr[0]; // Inicializamos con el primer elemento del arreglo

    for (int i = 1; i < size; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i]; // Actualizamos si encontramos un valor mayor
        }
    }

    return maxElement;
}


/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        // Intercambiar el elemento en start con el elemento en end
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Mover los índices hacia adentro
        start++;
        end--;
    }
}
/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize) {
    // Contar la cantidad de números pares en el arreglo
    int evenCount = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++;
        }
    }

    // Asignar memoria para el nuevo arreglo
    int *evenArray = (int *)malloc(evenCount * sizeof(int));
    if (evenArray == NULL) {
        *newSize = 0;
        return NULL; // Manejo de error si no se puede asignar memoria
    }

    // Llenar el nuevo arreglo con los números pares
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenArray[index] = arr[i];
            index++;
        }
    }

    *newSize = evenCount;
    return evenArray;
}+

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int index1 = 0; // Índice para recorrer arr1
    int index2 = 0; // Índice para recorrer arr2
    int indexResult = 0; // Índice para recorrer el arreglo resultado

    while (index1 < size1 && index2 < size2) {
        if (arr1[index1] < arr2[index2]) {
            result[indexResult] = arr1[index1];
            index1++;
        } else {
            result[indexResult] = arr2[index2];
            index2++;
        }
        indexResult++;
    }

    // Copiar los elementos restantes de arr1, si los hay
    while (index1 < size1) {
        result[indexResult] = arr1[index1];
        index1++;
        indexResult++;
    }

    // Copiar los elementos restantes de arr2, si los hay
    while (index2 < size2) {
        result[indexResult] = arr2[index2];
        index2++;
        indexResult++;
    }
}
/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) {
    int ascending = 1;
    int descending = 1;

    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            ascending = 0;
        }
        if (arr[i] > arr[i - 1]) {
            descending = 0;
        }
    }

    if (ascending == 1) {
        return 1; // Orden ascendente
    } else if (descending == 1) {
        return -1; // Orden descendente
    } else {
        return 0; // No está ordenado
    }
}


/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
    char nombre[50];
    int anioNacimiento;
} Autor;

typedef struct {
    char titulo[100];
    Autor autor;
    int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor,
                      int anioNacimiento, int anioPublicacion) {
    strncpy(libro->titulo, titulo, sizeof(libro->titulo));
    strncpy(libro->autor.nombre, nombreAutor, sizeof(libro->autor.nombre));
    libro->autor.anioNacimiento = anioNacimiento;
    libro->anioPublicacion = anioPublicacion;
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
    int numero;
    struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) {
    Nodo *inicio = NULL; // Puntero al primer nodo
    Nodo *actual = NULL; // Puntero al nodo actual

    for (int i = 0; i < size; i++) {
        // Crear un nuevo nodo
        Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
        if (nuevoNodo == NULL) {
            // Manejar error de asignación de memoria
            return NULL;
        }

        nuevoNodo->numero = arr[i];
        nuevoNodo->siguiente = NULL;

        if (actual == NULL) {
            // Si es el primer nodo, establecerlo como inicio
            inicio = nuevoNodo;
            actual = nuevoNodo;
        } else {
            // Enlazar el nodo actual con el nuevo nodo
            actual->siguiente = nuevoNodo;
            actual = nuevoNodo;
        }
    }

    return inicio; // Devolver el puntero al primer nodo
}
