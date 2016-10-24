#ifndef PUNTO_H
#define PUNTO_H

#include<cmath>
#include<iostream>
using namespace std;

typedef int cor_t;
typedef float area_t;
typedef float angle_t;
typedef float radio_t;
const float PI=3.1416;

class punto{
public:
	cor_t x;
	cor_t y;
public:
	punto();
	punto(cor_t,cor_t);
	punto(punto &arg);
	~punto();
	void setX(cor_t);
	void setY(cor_t);
	void setPunto(cor_t,cor_t);
	cor_t getX();
	cor_t getY();
	radio_t distancia(punto,punto);
	punto linea(punto,punto);
	area_t producto(punto);
};

class Figura{
protected:
	punto m_origen; //centro de la figura
	int tam_lista; //tamaño del # de puntos q define la figura
	punto *m_lista; //conjunto de puntos 
	area_t m_area; //el area de dicha figura
	
public:
	Figura();
	Figura(cor_t,cor_t,int);
	Figura(const Figura&m);
	virtual void areaPoligono();
	area_t getArea();
};

/*.....clase derivada poligono */
class Poligon : public Figura{
public:
	Poligon();
	Poligon(cor_t,cor_t,int);
	void llenar_lista();
	void areaPoligono();
};

#endif

