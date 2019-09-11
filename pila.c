#include "pila.h"
#include <stdlib.h>

#define CAPACIDAD_INICIAL 11
#define COEFICIENTE_AGRANDAMIENTO 2
#define COEFICIENTE_ACHICAMIENTO 2
#define RATIO_DE_REDIMENSION 4

/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void** datos;
    size_t cantidad;  // Cantidad de elementos almacenados.
    size_t capacidad;  // Capacidad del arreglo 'datos'.
};

/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

bool condicion_achicamiento_pila(size_t cantidad, size_t capacidad);

/*Cambia la capacidad de una pila
 *pos: devuelve true si es posible redimensionar y cambia el tamaño
 *de la pila, de lo contrario devuelve false y la pila se mantiene
 *en su estado original*/
bool pila_redimensionar(pila_t* pila,size_t nueva_capacidad){

	void* datos_nuevos = realloc(pila->datos, nueva_capacidad * sizeof(void*));
	if (datos_nuevos == NULL){
		return false;
	}

	pila->capacidad = nueva_capacidad;
	pila->datos = datos_nuevos;
	return true;
}

pila_t* pila_crear(void){
	pila_t* pila = malloc(sizeof(pila_t));

	if (pila == NULL){
		return NULL;
	}

	pila->datos = malloc(CAPACIDAD_INICIAL * sizeof(void*));

	if (pila->datos == NULL){
		free(pila);
		return NULL;
	}

	pila->cantidad = 0;
	pila->capacidad = CAPACIDAD_INICIAL;
	return pila;
}

void pila_destruir(pila_t *pila){
	free(pila->datos);
	free(pila);
}

bool pila_esta_vacia(const pila_t *pila){
	return (pila->cantidad) == 0;
}

bool pila_apilar(pila_t* pila, void* valor){

	if (pila->cantidad == pila->capacidad){
	
		if (!pila_redimensionar(pila, pila->capacidad * COEFICIENTE_AGRANDAMIENTO)){
	        return false;
	    }

	}

	pila->datos[pila->cantidad] = valor;
	(pila->cantidad)++;
	return true;
}

void* pila_ver_tope(const pila_t *pila){
	if (pila_esta_vacia(pila)){
		return NULL;
	}

	return pila->datos[pila->cantidad -1];
}

void* pila_desapilar(pila_t *pila){

	
	if (pila_esta_vacia(pila)){
		return NULL;
	}

	void* tope = pila_ver_tope(pila);
	(pila->cantidad)--;
	
	if (condicion_achicamiento_pila(pila->cantidad, pila->capacidad)){

		pila_redimensionar(pila, pila->capacidad / COEFICIENTE_ACHICAMIENTO);
	}
	
	return tope;
}

bool condicion_achicamiento_pila(size_t cantidad, size_t capacidad){

	return cantidad * RATIO_DE_REDIMENSION <= capacidad &&
	capacidad / COEFICIENTE_ACHICAMIENTO > CAPACIDAD_INICIAL;
}
// ...
