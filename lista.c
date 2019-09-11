#include "lista.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct nodo{
	void* dato;
	struct nodo* proximo;

}nodo_t;

struct lista{
	nodo_t* primero;
	nodo_t* ultimo;
	size_t largo;
};

////////Funciones Nodos
nodo_t* crear_nodo(void* valor){

	nodo_t* nuevo_nodo = malloc(sizeof(nodo_t));

	if(!nuevo_nodo) return NULL;
	
	nuevo_nodo->dato = valor;

	nuevo_nodo->proximo = NULL;
	return nuevo_nodo;
}

void destruir_nodo(nodo_t* nodo){

	free(nodo);
}

///////Funciones Lista
lista_t *lista_crear(void){

	lista_t* lista = malloc(sizeof(lista_t));

	if(!lista) return NULL;

	lista->primero = NULL;
	lista->ultimo = NULL;
	lista->largo = 0;

	return lista;
}

bool lista_esta_vacia(const lista_t *lista){

	return !lista->largo;

}

bool lista_insertar_primero(lista_t *lista, void *dato){

	nodo_t* nuevo_nodo = crear_nodo(dato);
	if (!nuevo_nodo) return false;

	if (lista_esta_vacia(lista)){
		
		lista->ultimo = nuevo_nodo;
	}
	else {

		nuevo_nodo->proximo = lista->primero;
	}

	lista->primero = nuevo_nodo;
	lista->largo++;
	return true;
}

bool lista_insertar_ultimo(lista_t *lista, void *dato){

	nodo_t* nuevo_nodo = crear_nodo(dato);
	if (!nuevo_nodo) return false;

	if (lista_esta_vacia(lista)){

		lista->primero = nuevo_nodo;
	}
	else {

		lista->ultimo->proximo = nuevo_nodo;
	}

	lista->ultimo = nuevo_nodo;
	lista->largo++;
	return true;
}

void *lista_borrar_primero(lista_t *lista){

	if(lista_esta_vacia(lista)) return NULL;

	nodo_t* nodo_viejo = lista->primero;
	void* dato = nodo_viejo->dato; 
	lista->primero = nodo_viejo->proximo;

	if(nodo_viejo == lista->ultimo) lista->ultimo = NULL;

	destruir_nodo(nodo_viejo);
	lista->largo--;
	return dato;
}

void *lista_ver_primero(const lista_t *lista){

	if (lista_esta_vacia(lista)) return NULL;

	return lista->primero->dato;
}

void *lista_ver_ultimo(const lista_t* lista){

	if (lista_esta_vacia(lista)) return NULL;

	return lista->ultimo->dato;
}

size_t lista_largo(const lista_t *lista){

	return lista->largo;
}

void lista_destruir(lista_t *lista, void destruir_dato(void *)){

	while(!lista_esta_vacia(lista)){

		void* dato = lista_borrar_primero(lista);
		if(destruir_dato) destruir_dato(dato);
	}

	free(lista);
}

////Iterador Interno
void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra){

	nodo_t* actual = lista->primero;
	bool continuar = true;
	
	while(actual && continuar){
		if (visitar){
			continuar = visitar(actual->dato, extra);
		}
		actual = actual->proximo;
	}	
}

////Iterador Externo
struct lista_iter{

	nodo_t* anterior;
	nodo_t* actual;
	lista_t* lista;
};


lista_iter_t *lista_iter_crear(lista_t *lista){

	lista_iter_t* iter = malloc(sizeof(lista_iter_t));

	if(!iter) return NULL;

	iter->lista = lista;
	iter->anterior = NULL;
	iter->actual = iter->lista->primero;

	return iter;
}

bool lista_iter_avanzar(lista_iter_t *iter){

	if(lista_iter_al_final(iter)) return false;

	iter->anterior = iter->actual;
	iter->actual = iter->actual->proximo;
	return true;
}

void *lista_iter_ver_actual(const lista_iter_t *iter){
	if(lista_iter_al_final(iter)) return NULL;
	return iter->actual->dato;
}

bool lista_iter_al_final(const lista_iter_t *iter){

	return !iter->actual;
}

void lista_iter_destruir(lista_iter_t *iter){

	free(iter);
}

bool lista_iter_insertar(lista_iter_t *iter, void *dato){

	if(!iter->anterior){
		if (!lista_insertar_primero(iter->lista,dato)) return false;
		iter->actual = iter->lista->primero;
		return true;
	}
	if(lista_iter_al_final(iter)){
		if (!lista_insertar_ultimo(iter->lista,dato)) return false;
		iter->actual = iter->lista->ultimo;
		return true;
	}

	nodo_t* nuevo_nodo = crear_nodo(dato);
	if (!nuevo_nodo) return false;
		
	nuevo_nodo->proximo = iter->actual;
	iter->anterior->proximo = nuevo_nodo;
	iter->actual = nuevo_nodo;
	iter->lista->largo++;
	return true;		
}

void *lista_iter_borrar(lista_iter_t *iter){

	if (lista_iter_al_final(iter)) return NULL;

	void* dato;

	if (iter->actual == iter->lista->primero){

		dato = lista_borrar_primero(iter->lista);
		iter->actual = iter->lista->primero;
		return dato;
	}

	dato = iter->actual->dato;
	nodo_t* nodo_viejo = iter->actual;
		
	iter->actual = iter->actual->proximo;
	iter->anterior->proximo = iter->actual;
	if (lista_iter_al_final(iter)) iter->lista->ultimo = iter->anterior;		
	iter->lista->largo--;
	destruir_nodo(nodo_viejo);
	
	return dato;
}