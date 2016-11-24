#ifndef NODE_H
#define NODE_H

#include<iostream>
using namespace std;

typedef unsigned int nature_t;

template<class T>
class Nodo {
private:
	T m_val;
	nature_t m_id;
public:
	Nodo<T> *m_next; //enlace
	
	Nodo();
	Nodo(T,nature_t);
	Nodo(Nodo<T> &);
	T getValue();
	nature_t getID();
	void setID(nature_t);
	void setValue(T);
	friend Nodo<T>* crear(T,nature_t);
};

template<class T>
class Stack {
private:
	nature_t m_size;
	Nodo<T> *m_head; //cabeza de la lista
public:
	Stack();
	void setLen();
	nature_t getLen();
	void imprimir();
	void setPos(Nodo<T> *,nature_t);
	void setStack(nature_t);
	void push_back(Nodo<T> *);
	void insertar(Nodo<T> *,nature_t);
	void eliminar(nature_t);
	void pop();
	
	
};

#endif

