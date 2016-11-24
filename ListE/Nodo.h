#ifndef NODO_H
#define NODO_H

#include<iostream>
using namespace std;

typedef unsigned short int nature_t;

template<class T>
class Nodo {
private:
	T m_key;
	nature_t m_id;
public:
	Nodo<T> *m_next;
	
	friend Nodo<T>* crear(T,nature_t);
	Nodo();
	Nodo(T,nature_t);
	Nodo(const Nodo<T> *);
	void setKey(T);
	T getKey();
	void setID(nature_t);
	nature_t getID();
};

template<class T>
class Stack {
private:
	nature_t m_size;
public:
	Nodo<T> *m_head;
	
	Stack();
	Stack(const Stack &m);
	void push_back(T,nature_t);
	void pop();
	void setLen();
	void imprimir();
	nature_t getLen();
	bool empty();
	T top();
	
	friend Stack<T> operator+(Stack<T> &m, Stack<T> &n){
		Stack<T> rpta;
		Nodo<T> *prev, *cur;
		prev=m.m_head;
		cur=m.m_head->m_next;
		while(cur!=NULL){
			rpta.push_back(prev->getKey(),prev->getID());
			prev=cur;
			cur=cur->m_next;
		}//llega al fin de linea
		rpta.push_back(prev->getKey(),prev->getID());
		
		prev=n.m_head;
		cur=n.m_head->m_next;
		while(cur!=NULL){
			rpta.push_back(prev->getKey(),prev->getID());
			prev=cur;
			cur=cur->m_next;
		}
		rpta.push_back(prev->getKey(),prev->getID());
		return rpta;
	}
};

#endif

