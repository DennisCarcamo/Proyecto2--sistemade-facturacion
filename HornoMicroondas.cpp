#include "HornoMicroondas.h"
#include "aparato.h"
#include <iostream>
#include <sstream>
#include <string>

using std::stringstream;
using std::string;
using std::endl;

HornoMicroondas::HornoMicroondas(double precio ,int voltaje,int peso, int especialfuntions, string marca)
	:aparato(precio,voltaje,peso),especialfuntions(especialfuntions),marca(marca){
}


int HornoMicroondas::getVoltaje(){
	return 	aparato::getVoltaje();
}

int HornoMicroondas::getpeso(){
	return aparato::getpeso();
}

double HornoMicroondas::getPrecio(){
	return aparato::getPrecio();
}

double HornoMicroondas::getDescuento(int porcentage){
	return calcular_descuento(porcentage,aparato::getPrecio());
}

void  HornoMicroondas::setNew_Precio(double newprecio){
	aparato::setNew_Precio(newprecio);
}

string HornoMicroondas::getMarca(){
	return marca;
}
	  
string HornoMicroondas::toString(){
	stringstream ss;
	ss<<"  Horno Microondas "<<endl
	  <<"  Marca:____________________"<< marca<<endl
	  <<aparato::toString()
	  <<"  Funciones Especiales:_____"<<especialfuntions<<endl
	  <<"  PRECIO:___________________"<<getPrecio()<<" USD"<<endl;
	return ss.str();
}

double HornoMicroondas::getPrecio_por_envio(){
	return precio_por_envio(getpeso());
}

double HornoMicroondas::precio_por_envio(int pesso){
	double sendprice=0.0;
	if (pesso>0 && pesso<=7){
		return 10.25;
	}else if(pesso>7 && pesso<11){
 		return 12.50;
	}else if(pesso=11 ){
		return 14.50;
	}
		 
	
}

double HornoMicroondas::calcular_descuento(int porcentage, double precio){
	return (precio/100)*porcentage;
}
