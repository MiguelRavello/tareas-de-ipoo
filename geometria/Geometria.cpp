#include "Geometria.h"

conter_t the_max(conter_t &a,conter_t &b){
	if(a<b)
		return b;
	return a;
}
/*------clase punto----------*/
Point::Point(): x(0), y(0) {}

Point::Point(cordenada_t nx,cordenada_t ny): x(nx), y(ny) {}

Point::Point(Point &o): x(o.getX()), y(o.getY()) {}

void Point::setX(cordenada_t nx){
	x=nx;
}
void Point::setY(cordenada_t ny){
	y=ny;
}

cordenada_t Point::getX(){	return x;}
cordenada_t Point::getY(){	return y;}

void Point::imprimir_Punto(){
	cout<<"("<<this->getX()<<","<<this->getY()<<")"<<endl;
}

/*...........clase Point array-...............*/

PointArray::PointArray():m_size(0){
	m_lista=new Point[0];
}
PointArray::PointArray(int tam):m_size(tam){
	m_lista=new Point[m_size];
	//this->llenarArray();
}
PointArray::PointArray(PointArray &m){
	this->setSize(m.getSize());
	this->m_lista=new Point[m_size];
	for(int i=0;i<m_size;i++){
		this->m_lista[i]=m.m_lista[i];
	}
}

PointArray::~PointArray(){
	delete[] m_lista;
}

int PointArray::getSize(){	return m_size;}

void PointArray::setSize(int tam){
	m_size=tam;
}

void PointArray::llenarArray(){
	cordenada_t nx, ny;
	for(int i=0;i<m_size;i++){
		cout<<"dadle cordenadas a los puntos: "<<i+1<<endl;
		cout<<"x: ";
		cin>>nx;
		cout<<"y: ";
		cin>>ny;
		Point temporal(nx,ny);
		this->m_lista[i]=temporal;
	}
	cout<<"fin"<<endl;
}

Point PointArray::getPuntoN(int n){
	if(n>=0 && n<m_size)
		return this->m_lista[n];
}

Point *PointArray::getPointerN(int n){
	if(n>=0 && n<m_size)
		return m_lista+n;
	return NULL;
}

void PointArray::resize(int nuovotam){
	Point *xs;
	xs=new Point[nuovotam];
	int min;
	if(nuovotam<m_size)
		min=nuovotam;
	else
		min=m_size;
	for(int i=0;i<min;i++)
		*(xs+i)=*(m_lista+i);
	delete[] m_lista;
	m_size=nuovotam;
	m_lista=xs;
}

void PointArray::push_back(Point &p){
	this->resize(m_size+1);
	this->m_lista[m_size-1]=p;
}

void PointArray::clear(){
	resize(0);
}

void PointArray::insert(int pos,Point &p){
	this->resize(m_size+1);/*agrega un slot */
	for(int i=m_size-1;i>pos;i--)
		*(m_lista+i)=*(m_lista+i-1); /*reacomoda los slot, agregandole el anterior */
	*(m_lista+pos)=p;
}

void PointArray::remove(int pos){
	if(pos>0 && pos<m_size){
		for(int i=pos;i<m_size-1;i++){
			*(m_lista+i)=*(m_lista+i+1);
		}
		this->resize(m_size-1);
	}	
}

/*.............clase vector...........*/

Vectorial::Vectorial(): m_inicial(0,0), m_final(0,0) {}

Vectorial::Vectorial(cordenada_t nx,cordenada_t ny,cordenada_t mx,cordenada_t my)
	:m_inicial(nx,ny), m_final(mx,my){}

Vectorial::Vectorial(Point p1, Point p2): m_inicial(p1), m_final(p2) {}

//Vectorial::Vectorial(Vectorial &m):m_inicial(m.getPuntoA()), m_final(m.getPuntoB() ) {}

void Vectorial::setPuntoA(cordenada_t x1,cordenada_t y1){
	this->m_inicial.setX(x1);
	this->m_inicial.setY(y1);
}

void Vectorial::setPuntoB(cordenada_t x2, cordenada_t y2){
	this->m_final.setX(x2);
	this->m_final.setY(y2);
}

void Vectorial::setPuntoS(Point v1,Point v2){
	this->setPuntoA(v1.getX(),v1.getY());
	this->setPuntoB(v2.getX(),v2.getY());
}

Point Vectorial::getPuntoA(){	return m_inicial;}

Point Vectorial::getPuntoB(){	return m_final;}

radio_t Vectorial::modulo(){
	radio_t radio=sqrt(pow((radio_t)(this->m_inicial.getX() - this->m_final.getX()),2) 
					+ pow((radio_t)(this->m_inicial.getY() - this->m_final.getY()),2));
	return radio;
}

Point Vectorial::lineaAB(){
	cordenada_t nx=this->m_final.getX() - this->m_inicial.getX();
	cordenada_t ny=this->m_final.getY() - this->m_inicial.getY();
	Point c(nx,ny); //reduce el vector al origen
	return c;
}

area_t Vectorial::producto_cruz(){
	return (area_t)((this->m_inicial.getX())*(this->m_final.getY())-this->m_final.getX()*(this->m_inicial.getY()));
}

/*.............clase Abstracta Geometria......*/

Geometria::Geometria(): m_origen(0,0), PointArray(0){}
Geometria::Geometria(cordenada_t nx,cordenada_t ny,int tam): m_origen(nx,ny), PointArray(tam){}

area_t Geometria::getArea(){	return m_area;}
radio_t Geometria::getPerimetro(){	return m_perimetro;}
/*.............Clase Poligono ...............*/

Poligono::Poligono(): Geometria(0,0,0){}
Poligono::Poligono(cordenada_t nx, cordenada_t ny, int tam): Geometria(nx,ny,tam){
	if(m_size==2)
		cout<<"es una linea"<<endl;
	else if(m_size==1)
		cout<<"es un punto"<<endl;
	else{
		m_vectores=new Vectorial[m_size];
		this->llenarArray();
		this->llenarVectores();
		this->setArea();
		this->setPerimetro();
	}
}

Poligono::~Poligono(){
	delete[] m_vectores;
}

void Poligono::llenarVectores(){
	Point *xs;
	xs=new Point[m_size];
	for(int i=0;i<m_size;i++){
		Vectorial temp1(m_origen,m_lista[i]);
		xs[i] = temp1.lineaAB();
		cout<<i+1<<"-punto reducido al origen"<<endl;
		xs[i].imprimir_Punto();
	}
	for(int j=0;j<m_size;j++){
		if(j==(m_size-1)){
			/*cout<<"ultimo par de vectores q definen un triangulo"<<endl;*/
			m_vectores[j].setPuntoS(xs[j],xs[0]);
			continue;
		}
		/*cout<<j<<"-esimo punto q define un triangulo en el poligono"<<endl;*/
		m_vectores[j].setPuntoS(xs[j],xs[j+1]);
	}
	delete[] xs;
}

void Poligono::setArea(){
	area_t temp1=0;
	area_t temp2=0;
	cout<<endl;
	for(int i=0;i<m_size;i++){
		cout<<i+1<<"-- vectores q definen un triangulo en el poligono"<<endl;
		temp2=abs(this->m_vectores[i].producto_cruz())/2;
		(this->m_vectores[i].getPuntoA()).imprimir_Punto();
		(this->m_vectores[i].getPuntoB()).imprimir_Punto();
		cout<<"area de dicho tringulo: "<<temp2<<endl;
		temp1+=temp2;
	}
	m_area=temp1;
}

/*los vectores reducidos representan los puntos q defienen el poligono 
y la union de cada punto de la figura*/
void Poligono::setPerimetro(){
	radio_t temp=0;
	for(int i=0;i<m_size;i++){
		temp+=this->m_vectores[i].modulo();
	}
	m_perimetro=temp;
}

/*-------------Clase Cuadrilatero...........*/
Cuadrilatero::Cuadrilatero(): Poligono(0,0,4) {}
Cuadrilatero::Cuadrilatero(cordenada_t nx, cordenada_t ny): Poligono(nx,ny,4) {
	this->setAngulo90();
	this->setLadoigual();
	this->setIdentidad();
}

angulo_t Cuadrilatero::pendiente(int n){
	angulo_t m = (this->m_vectores[n].getPuntoB().getY() - this->m_vectores[n].getPuntoA().getY()) / 
		(this->m_vectores[n].getPuntoB().getX() - this->m_vectores[n].getPuntoA().getX());
	return m;
}

bool Cuadrilatero::contAngulo90(int n){
	int m=n+1;
	
	if(n==3){
		m=0;
	}
	if(this->m_vectores[n].getPuntoA().getX() == this->m_vectores[n].getPuntoB().getX()){
		if(this->pendiente(m)==0)
			return true;
	}
	else if(this->m_vectores[m].getPuntoA().getX() == this->m_vectores[m].getPuntoB().getX()){
		if(this->pendiente(n)==0)
			return true;
	}
	else if(this->pendiente(n) * this->pendiente(m) == -1){
		return true;
	}
	else
		return false;
}

void Cuadrilatero::setAngulo90(){
	conter_t conta=0;
	for(int i=0;i<m_size;i++){
		if(this->contAngulo90(i)==true){
			conta++;
		}
	}
	mc_angulo90=conta;
}

void Cuadrilatero::setLadoigual(){
	conter_t *xs;
	xs=new conter_t[3];
	conter_t mayor=0;
	for(int w=0;w<3;w++)
		xs[w]=0;
	
	for(int i=0;i<3;i++){
		for(int j=i;j<m_size;j++){
			if(this->m_vectores[i].modulo() == this->m_vectores[j].modulo()){
				++xs[i];
			}
		}
	}
	mayor=the_max(xs[1],xs[2]);
	mc_ladoigual=the_max(xs[0],mayor);
	delete[] xs;
}

void Cuadrilatero::setIdentidad(){
	if(this->getAngulo90() == 4){ 
		if(this->getLadoigual() == 4)
			m_identidad="cuadrado";
		else if(this->getLadoigual() == 2)
			m_identidad="rectangulo";
	}
	else if(this->getAngulo90() == 2)
		m_identidad="trapecio escaleno";
	else
		m_identidad="cuadrilatero";
}

conter_t Cuadrilatero::getAngulo90(){	return mc_angulo90;}
conter_t Cuadrilatero::getLadoigual(){	return mc_ladoigual;}
string Cuadrilatero::getIdentidad(){	return m_identidad;}

/*............clase triangulo .................*/
Triangulo::Triangulo(): Poligono(0,0,3) {}
Triangulo::Triangulo(cordenada_t nx, cordenada_t ny): Poligono(nx,ny,3) {}


