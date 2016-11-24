#include "Nodo.h"
#include "Nodo.cpp"

int main () {
	Stack<int> obj;
	obj.push_back(11,0);
	obj.push_back(12,1);
	obj.push_back(13,2);
	obj.imprimir();
	cout<<endl;
	
	Stack<int> obj2;
	obj2.push_back(21,3);
	obj2.push_back(22,4);
	obj2.push_back(23,5);
	obj2.imprimir();
	cout<<endl;
	
	Stack<int> r;
	r = obj + obj2;
	r.imprimir();
	cout<<endl;
	cout<<r.top()<<endl;
	cout<<endl;
	r.pop();
	r.imprimir();
	return 0;
}

