#ifndef PILA_H_
#define PILA_H_

#include "Nodo.h"
#include <string>

/*
 * Una Pila es una estructura dinamica de datos organizada de acuerdo al
 * principio LIFO (Last In - First Out).
 *
 * El ultimo elemento en entrar es el primer elemento en salir.
 *
 * Solo permite el acceso al elemento que denomina tope.
 *
 */
template<class T> class Pila {

    private:

        Nodo<T>* tope;

    public:

        /*
         * post: instancia de Pila vacia y lista para ser usada.
         */
        Pila();

        /*
         * post: devuelve si la Pila no tiene ningun elemento.
         */
        bool estaVacia();

        /*
         * post: agrega 'elemento' en el tope de la Pila.
         */
        void apilar(T elemento);

        /*
         * pre : la Pila no esta vacia.
         * post: remueve el tope de la Pila y lo devuelve.
         */
        T desapilar();

        /*
         * pre : la Pila no esta vacia.
         * post: devuelve el tope de la Pila.
         */
        T obtenerTope();

        /*
         * post: remueve todos los elementos y libera
         *       los recursos tomados por la estructura de datos.
         */
        ~Pila();
};

template<class T>
Pila<T>::Pila() {

    this->tope = NULL;
}

template<class T>
bool Pila<T>::estaVacia() {

    return (this->tope == NULL);
}

template<class T>
void Pila<T>::apilar(T elemento) {

    Nodo<T>* nuevoTope = new Nodo<T>(elemento);
    nuevoTope->cambiarSiguiente(this->tope);
    this->tope = nuevoTope;
}

template<class T>
T Pila<T>::desapilar() {

    /* si no existen elementos devuelve basura */
    T elemento;

    if (! this->estaVacia()) {

        /* remueve el tope de la estructura */
        Nodo<T>* topeAnterior = this->tope;
        this->tope = topeAnterior->obtenerSiguiente();

        /* devuelve el elemento y libera los recursos asociados */
        elemento = topeAnterior->obtenerDato();
        delete topeAnterior;

    } else {

        throw std::string("No se puede desapilar un elemento, la pila esta vacia.");
    }

    return elemento;
}

template<class T>
T Pila<T>::obtenerTope() {

    /* si no existen elementos devuelve basura */
    T elemento;

    if (! this->estaVacia()) {

        elemento = this->tope->obtenerDato();

    } else {

        throw std::string("No se puede obtener el tope, la pila esta vacia.");
    }

    return elemento;
}

template<class T>
Pila<T>::~Pila() {

    while (! this->estaVacia()) {

        this->desapilar();
    }
}


#endif /* PILA_H_ */
