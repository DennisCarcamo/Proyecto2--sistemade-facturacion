#include "refrigeradora.h"
#include "aparato.h"
#include <iostream>
#include <sstream>
#include <string>

using std::stringstream;
using std::string;
using std::endl;

refrigeradora::refrigeradora(double precio ,int voltaje,int peso, int puertas,int piescubicos, string marca)
	:aparato(precio,voltaje,peso),puertas(puertas),piescubicos(piescubicos),marca(marca){
}


int refrigeradora::getVoltaje(){
	return 	aparato::getVoltaje();
}

int refrigeradora::getpeso(){
	return aparato::getpeso();
}

double refrigeradora::getPrecio(){
	return aparato::getPrecio();
}

double refrigeradora::getDescuento(int porcentage){
	if (piescubicos==1 || porcentage==2){
		porcentage*=1;
	}else if(piescubicos==3){
		porcentage*=2;
	}else if(porcentage==4){
		porcentage*=3;
	}

	return  calcular_descuento(porcentage,aparato::getPrecio());
}

void  refrigeradora::setNew_Precio(double newprecio){
	aparato::setNew_Precio(newprecio);
}

string refrigeradora::getMarca(){
	return marca;
}
	  
string refrigeradora::toString(){
	stringstream ss;
	ss<<"  Refrigeradora "<<endl
	  <<"  Marca:____________________"<< marca<<endl
	  <<aparato::toString()
	  <<"  Pies Cubicos:_____________"<<piescubicos<<endl
	  <<"  PRECIO:___________________"<<getPrecio()<<" USD"<<endl;
	return ss.str();
}

double refrigeradora::getPrecio_por_envio(){
	return precio_por_envio( getpeso());
}

double refrigeradora::precio_por_envio(int peso){
	double sendprice=0.0;
	if (peso>=20 && peso<=30){
		if (piescubicos==1){
			sendprice=25.2;
		}else if (piescubicos==2){
			sendprice=27.2;
		}else if (piescubicos==3){
			sendprice=29.2;
		}
	}else if (peso>=40 && peso<=60){
		if (piescubicos==1){
			sendprice= 28.2;
		}else if (piescubicos==2){
			sendprice=31.2;
		}else if (piescubicos==3){
			sendprice=33.2;
		}
	}else if (peso>60 && peso<=100){
		if (piescubicos==1){
			sendprice= 34.2;
		}else if (piescubicos==2){
			sendprice= 37.2;
		}else if (piescubicos==3){
			sendprice=40.2;
		}
	}

	return sendprice;
}

double refrigeradora::calcular_descuento(int porcentage, double precio){
	return (precio/100)*porcentage;
}
