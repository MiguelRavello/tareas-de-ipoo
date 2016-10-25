//#include<iostream>
#include "punto.h"
//using namespace std;

int main () {
	Poligon P1(2,2,4);
	P1.llenar_lista();
	P1.areaPoligono();
	area_t s1;
	s1=P1.getArea();
	cout<<"area de un cuadrado: "<<s1<<endl;
	return 0;
}

