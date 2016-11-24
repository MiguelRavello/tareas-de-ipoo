#include "Geometria.h"



int main (){
	/*Poligono cuadrado(0,0,8);
	area_t a1=cuadrado.getArea();
	radio_t p1=cuadrado.getPerimetro();
	cout<<"area total: "<<a1<<endl;
	cout<<"perimetro total: "<<p1<<endl;
	*/
	
	/*PointArray xs1(4);
	xs1.resize(5);
	Point p1(6,6);
	Point p2(5,5);
	xs1.push_back(p1);
	xs1.insert(4,p2);
	xs1.remove(5);
	for(int i=0;i<xs1.getSize();i++){
		xs1.getPointerN(i)->imprimir_Punto();
	}*/
	
	Cuadrilatero fig1(0,0);
	area_t a2=fig1.getArea();
	radio_t p2=fig1.getPerimetro();
	cout<<"area total: "<<a2<<endl;
	cout<<"perimetro total: "<<p2<<endl;
	cout<<fig1.getIdentidad()<<endl;
	
	//reinterpret_cast<Triangulo *>(&fig1);
	dynamic_cast<Triangulo *>(&fig1);
	
	/*Triangulo obj(0,0);
	area_t a3=obj.getArea();
	cout<<"area total: "<<a3<<endl;*/
	
	
	return 0;
}

