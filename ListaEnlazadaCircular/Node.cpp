#include "Node.h"
template<class T>
Nodo<T>::Nodo(): m_val(0), m_id(0) {
	this->m_next=NULL;
}

template<class T>
Nodo<T>::Nodo(T a, nature_t b): m_val(a), m_id(b) {
	this->m_next=NULL;
}

template<class T>
Nodo<T>::Nodo(Nodo<T> &n1) {
	this->m_val = n1.m_val;
	this->m_id = n1.m_id;
	this->m_next = n1.m_next;
}

template<class T>
void Nodo<T>::setID(nature_t dni){
	this->m_id=dni;
}

template<class T>
nature_t Nodo<T>::getID(){	return m_id;}

template<class T>
void Nodo<T>::setValue(T newval){
	this->m_val=newval;
}

template<class T>
T Nodo<T>::getValue(){	return m_val;}

template<class T>
Nodo<T>* crear(T val, nature_t dni){
	Nodo<T> *xs=new Nodo<T>(val,dni);
	return xs;
}

/*------------------------clase Stack----------------------------------*/

template<class T>
Stack<T>::Stack() {
	m_head=new Nodo<T>;
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
nature_t Stack<T>::getLen(){	return this->m_size;}

template<class T>
void Stack<T>::imprimir(){
	Nodo<T> *xs;
	xs=m_head;
	while(xs!=NULL){
		cout<<xs->getValue()<<"->";
		xs=xs->m_next;
	}
	delete xs;
}

template<class T>
void Stack<T>::setPos(Nodo<T> *n1,nature_t pos){
	Nodo<T> *prev, *cur;
	prev=m_head;
	cur=m_head->m_next;
	nature_t i=0;
	while(cur!=NULL){
		if(i==pos){
			prev->m_next=n1;
			n1->m_next=cur;
			break;
		}
		prev=cur;
		cur=cur->m_next;
		i++;
	}
}

template<class T>
void Stack<T>::setStack(nature_t tam){
	Nodo<T> *prev, *cur; 
	cout<<"Introdusca el valor de la cabeza: "<<endl;
	T key;
	nature_t i=0;
	cin>>key;
	//m_head=new Nodo<T>(key,i);
	this->m_head->setValue(key);
	this->m_head->setID(i);
	prev=m_head;
	i++;
	while(i<=tam){
		T temp;
		cout<<"valor del siguiente nodo: "<<i<<endl;
		cin>>temp;
		cur=new Nodo<T>(temp,i);
		prev->m_next=cur;
		prev=cur;
		i++;
	}
	prev->m_next=NULL;
	cout<<"fin"<<endl;
}

template<class T>
void Stack<T>::push_back(Nodo<T> *nuovonodo){
	Nodo<T> *prev, *cur;
	prev=m_head;
	cur=m_head->m_next;
	while(true){
		if(cur==NULL){
			prev->m_next = nuovonodo;
			delete cur;
			break;
		}
		prev=cur;
		cur=cur->m_next;
	}
}


template<class T>
void Stack<T>::insertar(Nodo<T> *nuovo, nature_t pos){
	Nodo<T> *prev, *cur;
	prev=m_head;
	cur=m_head->m_next;
	int i=0;
	while(cur!=NULL){
		if(i==pos){
			prev->m_next=nuovo;
			nuovo->m_next=cur;
			break;
		}
		prev=cur;
		cur=cur->m_next;
		i++;
	}
}

template<class T>
void Stack<T>::eliminar(nature_t pos){
	Nodo<T> *prev, *cur, *victima;
	prev=m_head;
	cur=m_head->m_next;
	nature_t i=0;
	while(cur!=NULL){
		if(i==pos){
			prev->m_next=cur->m_next;
			victima=cur;
			delete victima;
			break;
		}
		prev=cur;
		cur=cur->m_next;
		i++;
	}
}

template<class T>
void Stack<T>::pop(){
	Nodo<T> *prev, *cur;
	prev=m_head;
	cur=m_head->m_next;
	while(true){
		if(cur==NULL){
			prev->m_next=NULL;
			delete cur;
			break;
		}
		prev=cur;
		cur=cur->m_next;
	}
}
