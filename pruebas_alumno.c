#include "lista.h"
#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>

#define DIMENSION_VOLUMEN 1000

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/
void pruebas_lista_nueva(){

	printf("INICIO DE PRUEBA DE LISTA NUEVA\n");
	lista_t* lista;
	print_test("Crear lista", (lista = lista_crear()) != NULL);
	print_test("Lista vacia",  lista_esta_vacia(lista));
	print_test("Lista ver primero vacio", lista_ver_primero(lista) == NULL);
	print_test("Lista ver ultimo vacio", lista_ver_ultimo(lista) == NULL);
	print_test("Lista borrar primero vacio", lista_borrar_primero(lista) == NULL);
	print_test("Lista largo es 0", lista_largo(lista) == 0);
	lista_destruir(lista,NULL);
}

void pruebas_lista_algunos_elementos(){

	printf("INICIO DE PRUEBA AGREGAR Y BORRAR\n");
	lista_t* lista;
	print_test("Crear lista", (lista = lista_crear()) != NULL);

	//Agrego entero al principio
	int entero = 1;

	print_test("Agregar entero al principio en lista", lista_insertar_primero(lista, &entero));
	print_test("Primero es entero", lista_ver_primero(lista) == &entero);
	print_test("Ultimo es entero", lista_ver_ultimo(lista) == &entero);
	print_test("Largo es 1",lista_largo(lista) == 1);
	print_test("Borrar primero es entero y primero y ultimo vacio", lista_borrar_primero(lista) == &entero &&
																	lista_ver_primero(lista) == NULL &&
																	lista_ver_ultimo(lista) == NULL);

	//Agrego entero al final
	print_test("Agregar entero al final en lista", lista_insertar_ultimo(lista, &entero));
	print_test("Primero es entero", lista_ver_primero(lista) == &entero);
	print_test("Ultimo es entero", lista_ver_ultimo(lista) == &entero);
	print_test("Largo es 1",lista_largo(lista) == 1);
	print_test("Borrar primero es entero y primero y ultimo vacio", lista_borrar_primero(lista) == &entero &&
																	lista_ver_primero(lista) == NULL &&
																	lista_ver_ultimo(lista) == NULL);

	//Agrego caracter al principio
	char caracter = 'A';

	print_test("Agregar caracter al principio en lista", lista_insertar_primero(lista, &caracter));
	print_test("Primero es caracter", lista_ver_primero(lista) == &caracter);
	print_test("Ultimo es caracter", lista_ver_ultimo(lista) == &caracter);
	print_test("Largo es 1",lista_largo(lista) == 1);
	print_test("Borrar primero es caracter y primero y ultimo vacio",	lista_borrar_primero(lista) == &caracter &&
																		lista_ver_primero(lista) == NULL &&
																		lista_ver_ultimo(lista) == NULL);

	//Agrego caracter al ultimo
	print_test("Agregar caracter al final en lista", lista_insertar_ultimo(lista, &caracter));
	print_test("Primero es caracter", lista_ver_primero(lista) == &caracter);
	print_test("Ultimo es caracter", lista_ver_ultimo(lista) == &caracter);
	print_test("Largo es 1",lista_largo(lista) == 1);
	print_test("Borrar primero es caracter y primero y ultimo vacio",	lista_borrar_primero(lista) == &caracter &&
																		lista_ver_primero(lista) == NULL &&
																		lista_ver_ultimo(lista) == NULL);

	//Agrego Double al principio
	double doble = 3.14;

	print_test("Agregar Double al principio en lista", lista_insertar_primero(lista, &doble));
	print_test("Primero es Double", lista_ver_primero(lista) == &doble);
	print_test("Ultimo es Double", lista_ver_ultimo(lista) == &doble);
	print_test("Largo es 1",lista_largo(lista) == 1);
	print_test("Borrar primero es Double y primero y ultimo vacio", lista_borrar_primero(lista) == &doble &&
																	lista_ver_primero(lista) == NULL &&
																	lista_ver_ultimo(lista) == NULL);

	//Agrego Double al final
	print_test("Agregar Double al final en lista", lista_insertar_ultimo(lista, &doble));
	print_test("Primero es Double", lista_ver_primero(lista) == &doble);
	print_test("Ultimo es Double", lista_ver_ultimo(lista) == &doble);
	print_test("Largo es 1",lista_largo(lista) == 1);
	print_test("Borrar primero es Double y primero y ultimo vacio", lista_borrar_primero(lista) == &doble &&
																	lista_ver_primero(lista) == NULL &&
																	lista_ver_ultimo(lista) == NULL);

	//Agrego todo al principio y borro varios

	print_test("Agregar entero en lista", lista_insertar_primero(lista, &entero));
	print_test("Largo es 1",lista_largo(lista) == 1);
	print_test("Agregar caracter en lista", lista_insertar_primero(lista, &caracter));
	print_test("Largo es 2",lista_largo(lista) == 2);
	print_test("Agregar Double en lista", lista_insertar_primero(lista, &doble));
	print_test("Largo es 3",lista_largo(lista) == 3);
	print_test("Primero es Double", lista_ver_primero(lista) == &doble);
	print_test("Ultimo es entero", lista_ver_ultimo(lista) == &entero);
	print_test("Borrar es Double, primero caracter y ultimo es entero", lista_borrar_primero(lista) == &doble &&
																		lista_ver_primero(lista) == &caracter &&
																		lista_ver_ultimo(lista) == &entero);
	print_test("Largo es 2",lista_largo(lista) == 2);
	print_test("Borrar es caracter, primero entero y ultimo es entero", lista_borrar_primero(lista) == &caracter &&
																		lista_ver_primero(lista) == &entero &&
																		lista_ver_ultimo(lista) == &entero);
	print_test("Largo es 1",lista_largo(lista) == 1);
	print_test("Borrar es entero, primero es vacio y ultimo es vacio", lista_borrar_primero(lista) == &entero &&
																		lista_ver_primero(lista) == NULL &&
																		lista_ver_ultimo(lista) == NULL);
	print_test("Largo es 0",lista_largo(lista) == 0);

	//Agrego todo al final y borro varios
	print_test("Agregar entero en lista", lista_insertar_ultimo(lista, &entero));
	print_test("Largo es 1",lista_largo(lista) == 1);
	print_test("Agregar caracter en lista", lista_insertar_ultimo(lista, &caracter));
	print_test("Largo es 2",lista_largo(lista) == 2);
	print_test("Agregar Double en lista", lista_insertar_ultimo(lista, &doble));
	print_test("Largo es 3",lista_largo(lista) == 3);
	print_test("Primero es entero", lista_ver_primero(lista) == &entero);
	print_test("Ultimo es doble", lista_ver_ultimo(lista) == &doble);
	print_test("Borrar es entero, primero caracter y ultimo es Double", lista_borrar_primero(lista) == &entero &&
																		lista_ver_primero(lista) == &caracter &&
																		lista_ver_ultimo(lista) == &doble);
	print_test("Largo es 2",lista_largo(lista) == 2);
	print_test("Borrar es caracter, primero Double y ultimo es Double", lista_borrar_primero(lista) == &caracter &&
																		lista_ver_primero(lista) == &doble &&
																		lista_ver_ultimo(lista) == &doble);
	print_test("Largo es 1",lista_largo(lista) == 1);
	print_test("Borrar es entero, primero es vacio y ultimo es vacio", lista_borrar_primero(lista) == &doble &&
																		lista_ver_primero(lista) == NULL &&
																		lista_ver_ultimo(lista) == NULL);
	print_test("Largo es 0",lista_largo(lista) == 0);

	//Agrego al principio y borro  varios inverso

	print_test("Agregar Double en lista", lista_insertar_primero(lista, &doble));
	print_test("Largo es 1",lista_largo(lista) == 1);
	print_test("Agregar caracter en lista", lista_insertar_primero(lista, &caracter));
	print_test("Largo es 2",lista_largo(lista) == 2);
	print_test("Agregar entero en lista", lista_insertar_primero(lista, &entero));
	print_test("Largo es 3",lista_largo(lista) == 3);
	print_test("Primero es entero", lista_ver_primero(lista) == &entero);
	print_test("Ultimo es doble", lista_ver_ultimo(lista) == &doble);
	print_test("Borrar es entero, primero caracter y ultimo es Double", lista_borrar_primero(lista) == &entero &&
																		lista_ver_primero(lista) == &caracter &&
																		lista_ver_ultimo(lista) == &doble);
	print_test("Largo es 2",lista_largo(lista) == 2);
	print_test("Borrar es caracter, primero Double y ultimo es Double", lista_borrar_primero(lista) == &caracter &&
																		lista_ver_primero(lista) == &doble &&
																		lista_ver_ultimo(lista) == &doble);
	print_test("Largo es 1",lista_largo(lista) == 1);
	print_test("Borrar es entero, primero es vacio y ultimo es vacio", lista_borrar_primero(lista) == &doble &&
																		lista_ver_primero(lista) == NULL &&
																		lista_ver_ultimo(lista) == NULL);
	print_test("Largo es 0",lista_largo(lista) == 0);

	//Lista como nueva

	print_test("Lista vacia",  lista_esta_vacia(lista));
	print_test("Lista ver primero vacio", lista_ver_primero(lista) == NULL);
	print_test("Lista ver ultimo vacio", lista_ver_ultimo(lista) == NULL);
	print_test("Lista borrar primero vacio", lista_borrar_primero(lista) == NULL);
	print_test("Lista largo es 0", lista_largo(lista) == 0);

	lista_destruir(lista, NULL);
}

void pruebas_agregar_elemento_null(){

	printf("INICIO DE PRUEBA AGREGAR 'NULL'\n");
	lista_t* lista;
	print_test("Crear lista", (lista = lista_crear()) != NULL);

	//Agregar y borrar NULL
	
	print_test("Agregar NULL al principio en lista", lista_insertar_primero(lista, NULL));
	print_test("Primero es NULL", lista_ver_primero(lista) == NULL);
	print_test("Ultimo es NULL", lista_ver_ultimo(lista) == NULL);
	print_test("Largo es 1",lista_largo(lista) == 1);
	print_test("Borrar primero es NULL y primero y ultimo vacio",	lista_borrar_primero(lista) == NULL &&
																		lista_ver_primero(lista) == NULL &&
																		lista_ver_ultimo(lista) == NULL);
	//Lista como nueva

	print_test("Lista vacia",  lista_esta_vacia(lista));
	print_test("Lista ver primero vacio", lista_ver_primero(lista) == NULL);
	print_test("Lista ver ultimo vacio", lista_ver_ultimo(lista) == NULL);
	print_test("Lista borrar primero vacio", lista_borrar_primero(lista) == NULL);
	print_test("Lista largo es 0", lista_largo(lista) == 0);

	lista_destruir(lista, NULL);
}

void pruebas_lista_volumen(){
	printf("INICIO DE PRUEBAS DE VOLUMEN\n");

	size_t vector[DIMENSION_VOLUMEN];

	//Crea un vector con 1000 elementos
	for (size_t i = 0; i < DIMENSION_VOLUMEN; i++){
		vector[i] = i;
	}
	
	lista_t* lista = lista_crear();
	bool ok = true;

	//Agregar 1000 elementos al final
	for (size_t i=0; i < DIMENSION_VOLUMEN; i++){
		ok &= lista_insertar_primero(lista, &vector[i]) && (lista_largo(lista) == i+1);
	}
	print_test("Se pudieron agregar todos los elementos", ok);

	ok = true;

	//Borrar 1000 elementos
	for (size_t i = DIMENSION_VOLUMEN - 1; i >= 1; i--){
		ok &= lista_borrar_primero(lista) == &vector[i] &&
				lista_ver_primero(lista) == &vector[i-1] &&
				lista_largo(lista) == i;
	}

	ok &= lista_borrar_primero(lista) == &vector[0] && lista_ver_primero(lista) == NULL && lista_largo(lista) == 0;
	print_test("Se pudieron borrar todos los elementos", ok);

	lista_destruir(lista, NULL);
}

void pruebas_lista_destruir_con_datos(){

	printf("INICIO DE PRUEBA DESTRUIR CON DATOS\n");
	lista_t* lista = lista_crear();
	pila_t* pila_1 = pila_crear();
	pila_t* pila_2 = pila_crear();
	pila_t* pila_3 = pila_crear();

	//Se agregan pilas
	print_test("Agregar pilas en cola", lista_insertar_primero(lista, pila_1) &&
										lista_insertar_primero(lista, pila_2) &&
										lista_insertar_primero(lista, pila_3));	
	print_test("Primero es pila 3", lista_ver_primero(lista) == pila_3);
	print_test("Primero es pila 1", lista_ver_ultimo(lista) == pila_1);
	void* puntero_pila_destruir = pila_destruir;
	lista_destruir(lista,puntero_pila_destruir);
	print_test("Lista y datos destruidos", true);
}

bool funcion_extra(void* dato, void* cantidad);
void pruebas_iterador_interno(){

	printf("INICIO DE PRUEBAS DE ITERADOR INTERNO\n");

	size_t vector[DIMENSION_VOLUMEN];

	//Crea un vector con 1000 elementos
	for (size_t i = 0; i < DIMENSION_VOLUMEN; i++){
		vector[i] = i;
	}
		
	lista_t* lista = lista_crear();
	
	//Agregar 1000 elementos al final
	for (size_t i=0; i < DIMENSION_VOLUMEN; i++){
		lista_insertar_primero(lista, &vector[i]);
	}

	void* puntero_funcion = funcion_extra;
	size_t cantidad = 0;
	lista_iterar(lista, puntero_funcion, &cantidad);
	print_test("Se iteraron 1000 elementos", cantidad == DIMENSION_VOLUMEN);		
	lista_destruir(lista,NULL);
}

bool funcion_extra(void* dato, void *extra){
	size_t* cantidad = extra;
	(*cantidad)++;
	return true;
}

void pruebas_iterador_externo(){
	lista_t* lista  = lista_crear();

	int dimension = 10;
	int vector[dimension];
	int elemento = 10;

	//Crea un vector con 1000 elementos
	for (int i = 0; i < dimension; i++){
		vector[i] = i;
	}

	lista_iter_t* iter = lista_iter_crear(lista);
	int i = 0;
	bool insertar = true;
	bool ok = true;
	bool avanza = true;
	while(i < dimension){

		insertar &= lista_iter_insertar(iter, &vector[i]);
		if (i == 0){
			ok &= lista_iter_ver_actual(iter) == lista_ver_primero(lista) && lista_ver_primero(lista) == &vector[i];
		}
		ok &= lista_iter_ver_actual(iter) == lista_ver_ultimo(lista) && lista_ver_ultimo(lista) == &vector[i];
		avanza &= lista_iter_avanzar(iter);
		i++;
	}
	print_test("El iterador inserta los elementos correctamente", ok);
	print_test("El iterador inserta elementos en la lista", insertar);
	print_test("El iterador puede avanzar", avanza);
	print_test("El iterador esta al final de la lista", lista_iter_al_final(iter));
	
	lista_iter_destruir(iter);
	iter = lista_iter_crear(lista);
	i = 0;
	print_test("Se inserto un elemento al principio de la lista", lista_iter_insertar(iter, &elemento) &&
																	lista_iter_ver_actual(iter) == lista_ver_primero(lista) &&
																	lista_ver_primero (lista)== &elemento);

	print_test("Se borro un elemento al principio de la lista", lista_iter_borrar(iter)== &elemento &&
																lista_iter_ver_actual(iter) == lista_ver_primero(lista) &&
																			lista_ver_primero (lista)== &vector[i]);	


	while(i < (dimension-1)/2){
		i++;
		lista_iter_avanzar(iter);
	}
	
	print_test("Se inserto un elemento en el centro de la lista", lista_iter_insertar(iter, &elemento) &&
																	lista_iter_ver_actual(iter) == &elemento);

	print_test("Se borro un elemento en el centro de la lista", lista_iter_borrar(iter) == &elemento &&
																lista_iter_ver_actual(iter) == &vector[i]);

	while(i < dimension-1){
		i++;
		lista_iter_avanzar(iter);
	}
	lista_iter_avanzar(iter);

	print_test("El iterador esta al final de la lista", lista_iter_al_final(iter));
	print_test("Se inserto un elemento al final de la lista", lista_iter_insertar(iter, &elemento) &&
																		lista_iter_ver_actual(iter) == &elemento &&
																		lista_ver_ultimo(lista) == &elemento);

	print_test("Se borro un elemento en el final de la lista", lista_iter_borrar(iter) == &elemento &&
																lista_iter_ver_actual(iter) == NULL &&
																lista_ver_ultimo(lista) == &vector[i]);

	lista_iter_destruir(iter);
	lista_destruir(lista,NULL);
}


void pruebas_lista_alumno() {
	
	pruebas_lista_nueva();
	pruebas_lista_algunos_elementos();
	pruebas_agregar_elemento_null();
	pruebas_lista_volumen();
	pruebas_lista_destruir_con_datos();
	pruebas_iterador_interno();
	pruebas_iterador_externo();
}