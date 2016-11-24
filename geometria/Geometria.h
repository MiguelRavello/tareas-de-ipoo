#ifndef GEOMETRIA_H
#define GEOMETRIA_H

#include<cmath>
#include<iostream>

using namespace std;

typedef double cordenada_t;
typedef double radio_t;
typedef double area_t;
typedef double angulo_t;
typedef unsigned int conter_t;

const double PI = 3.1416;

conter_t the_max(conter_t &,conter_t &);


class Point {
private:
	cordenada_t x;
	cordenada_t y;
public:
	Point();
	Point(cordenada_t,cordenada_t);
	Point(Point &o);
	void setX(cordenada_t);
	void setY(cordenada_t);
	cordenada_t getX();
	cordenada_t getY();
	void imprimir_Punto();
};

class PointArray{
protected:
	int m_size;
	Point *m_lista; //lista de puntos de la figura x
public:
	PointArray();
	PointArray(int);
	PointArray(PointArray &m);
	~PointArray();
	int getSize();
	void setSize(int);
	void llenarArray();
	Point getPuntoN(int);
	Point *getPointerN(int);
	void resize(int);
	void push_back(Point &);
	void clear();
	void insert(int,Point &);
	void remove(int);
};

class Vectorial {
private:
	Point m_inicial;
	Point m_final;
public:
	Vectorial();
	Vectorial(cordenada_t,cordenada_t,cordenada_t,cordenada_t);
	Vectorial(Point,Point);
	Vectorial(Vectorial &);
	void setPuntoA(cordenada_t,cordenada_t);
	void setPuntoB(cordenada_t,cordenada_t);
	void setPuntoS(Point,Point);
	Point getPuntoA();
	Point getPuntoB();
	radio_t modulo();
	Point lineaAB(); //lo uso para la reduccion de los vectores como si estubiesen en el origen
	area_t producto_cruz();
};

//sera la clase base para la clase poligono
//de PointArray heredara el conjunto de puntos y su tama\~no;
class Geometria : public PointArray {
protected:
	Point m_origen;
	area_t m_area;
	radio_t m_perimetro;
public:
	Geometria();
	Geometria(cordenada_t,cordenada_t,int);
	virtual void setArea()=0;
	virtual void setPerimetro()=0;
	area_t getArea();
	radio_t getPerimetro();
};

class Poligono : public Geometria {
protected:
	Vectorial *m_vectores; //lista de vectores desde el origen
						  // hasta cada punto del poligono.
public:
	Poligono();
	Poligono(cordenada_t,cordenada_t,int);
	~Poligono();
	void llenarVectores();
	void setArea();
	void setPerimetro();
};

/*sumar los vectores del origen y el reducido devuelve el original */
class Cuadrilatero : public Poligono {
private:
	string m_identidad;
	conter_t mc_angulo90;
	conter_t mc_ladoigual;
public:
	Cuadrilatero();
	Cuadrilatero(cordenada_t,cordenada_t);
	angulo_t pendiente(int);
	bool contAngulo90(int);
	void setAngulo90();
	void setLadoigual();
	void setIdentidad();
	conter_t getAngulo90();
	conter_t getLadoigual();
	string getIdentidad();
};

class Triangulo : public Poligono {
public:
	Triangulo();
	Triangulo(cordenada_t,cordenada_t);
};

#endif
