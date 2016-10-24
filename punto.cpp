#include "punto.h"

punto::punto():x(0),y(0){}
punto::punto(cor_t nx,cor_t ny):x(nx),y(ny){}
punto::punto(punto &arg):x(arg.x),y(arg.y){}
punto::~punto() {}

void punto::setX(cor_t nx){x=nx;}
void punto::setY(cor_t ny){y=ny;}

void punto::setPunto(cor_t nx,cor_t ny){
	x=nx;
	y=ny;
}

cor_t punto::getX(){return x;}
cor_t punto::getY(){return y;}

radio_t punto::distancia(punto a, punto b){
	radio_t radio=sqrt(pow((float)(a.getX()-b.getX()),2) + pow((float)(a.getY()-b.getY()),2));
	return radio;
}

punto punto::linea(punto a,punto b){
	cor_t nx=b.getX()-a.getX();
	cor_t ny=b.getY()-a.getY();
	punto c(nx,ny);
	return c;
}

area_t punto::producto(punto b){
	return (area_t)(this->getX()*b.getY()-b.getX()*this->getY());
}

/*........Clase Figura.........*/
Figura::Figura():m_origen(0,0),tam_lista(0){}
Figura::Figura(cor_t nx,cor_t ny,int tam): m_origen(nx,ny), tam_lista(tam){
	m_lista=new punto[tam_lista];
}

Figura::Figura(const Figura&m){
	*this=m;
}

void Figura::areaPoligono(){
	m_area=0;
}

area_t Figura::getArea(){return m_area;}

/*.......clase poligono.......*/
Poligon::Poligon():Figura(){}
Poligon::Poligon(cor_t nx,cor_t ny,int tam): Figura(nx,ny,tam){
	m_lista=new punto[tam_lista];
	//radio=distancia(m_origin,m_lista[0]);
}

void Poligon::llenar_lista(){
	cor_t nx, ny;
	for(int i=0;i<tam_lista;i++){
		cout<<"ingrese el punto: "<<i<<endl;
		cout<<"la cordenada x: ";
		cin>>nx;
		cout<<"la cordenada y: ";
		cin>>ny;
		punto a(nx,ny);
		m_lista[i]=a;
	}
	cout<<"fin"<<endl;
}

void Poligon::areaPoligono(){
	area_t temp1;
	area_t temp2;
	punto *xs;
	xs=new punto[tam_lista];
	for(int i=0;i<tam_lista;i++){
		punto temp;
		temp.linea(m_origen,m_lista[i]);
		xs[i]=temp;//los vectores q van del origen a la periferie
	}
	for(int j=0;j<tam_lista;j++){
		if(j==(tam_lista-1)){
			temp2=abs(xs[j].producto(xs[0]))/2.0;
			temp1+=temp2;
			break;
		}
		temp2=abs(xs[j].producto(xs[j+1]))/2.0;//areas desde el origen
		temp1+=temp2;
	}
	m_area=temp1;
	//delete xs;
}
