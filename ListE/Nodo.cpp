#include "Nodo.h"

/*..............Clase Nodo.................*/

template<class T>
Nodo<T>* crear(T a,nature_t b) {
	Nodo<T> *xs=new Nodo<T>(a,b);
	return xs;
}

template<class T>
Nodo<T>::Nodo(): m_key(0), m_id(0), m_next(NULL) {}

template<class T>
Nodo<T>::Nodo(T a,nature_t b): m_key(a), m_id(b), m_next(NULL) {}


template<class T>
Nodo<T>::Nodo(const Nodo<T> *xs) {
	this->m_key=xs->getKey();
	this->m_id=xs->getID();
	this->m_next=xs->m_next;
}

template<class T>
void Nodo<T>::setKey(T a) {
	this->m_key=a;
}

template<class T>
T Nodo<T>::getKey() {	return this->m_key;}

template<class T>
void Nodo<T>::setID(nature_t b) {
	this->m_id=b;
}

template<class T>
nature_t Nodo<T>::getID() {	return this->m_id;}

/*...........clase Stack.................*/

template<class T>
Stack<T>::Stack() {
	m_head=NULL;
}

template<class T>
Stack<T>::Stack(const Stack &m) {
	*this = m;
}

template<class T>
void Stack<T>::push_back(T a,nature_t b) {
	Nodo<T> *xs=new Nodo<T>(a,b);
	if(m_head==NULL){
		m_head=xs;
	}
	else{
		Nodo<T>* prev, *cur;
		prev=m_head;
		cur=m_head->m_next;
		while(cur!=NULL){
			prev=cur;
			cur=cur->m_next;
		}
		prev->m_next=xs;
		delete cur;
	}
}

template<class T>
void Stack<T>::pop(){
	Nodo<T> *prev, *cur;
	prev=m_head;
	cur=m_head->m_next;
	this->setLen();
	nature_t i=1;
	while(true){
		if(i==(this->getLen()-1)){
			prev->m_next=NULL;
			delete cur;
			break;
		}
		prev=cur;
		cur=cur->m_next;
		i++;
	}
}

template<class T>
void Stack<T>::setLen(){
	Nodo<T> *xs;
	xs=m_head;
	nature_t conta=0;
	while(xs!=NULL){
		conta++;
		xs=xs->m_next;
	}
	delete xs;
	m_size=conta;
}

template<class T>
void Stack<T>::imprimir(){
	Nodo<T> *xs;
	xs=m_head;
	while(xs!=NULL){
		cout<<xs->getKey()<<"->";
		xs=xs->m_next;
	}
	delete xs;
}

template<class T>
nature_t Stack<T>::getLen() {
	this->setLen();
	return m_size;
}

template<class T>
bool Stack<T>::empty(){
	this->setLen();
	if(this->getLen()==0){
		return true;
	}
	return false;
}

template<class T>
T Stack<T>::top() {
	if(m_head==NULL){
		return -1;
	}
	else{
		Nodo<T>* prev, *cur;
		prev=m_head;
		cur=m_head->m_next;
		while(cur!=NULL){
			prev=cur;
			cur=cur->m_next;
		}
		delete cur;
		return prev->getKey();
	}
}


/*template<class T>
Stack<T> Stack<T>::operator+<>(Stack &m,Stack &n) {
	Stack rpta;
	Nodo<T> *prev, *cur;
	prev=m.m_head;
	cur=m.m_head->m_next;
	while(cur!=NULL){
		rpta.push_back(prev->getKey(),prev->getID());
		prev=cur;
		cur=cur->m_next;
	}
	prev=n.m_head;
	cur=n.m_head->m_next;
	while(cur!=NULL){
		rpta.push_back(prev->getKey(),prev->getID());
		prev=cur;
		cur=cur->m_next;
	}
	return rpta;
	
}*/
