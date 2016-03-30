#include "aparato.h"
#include <iostream>
#include <sstream>
#include <iomanip>


using std::stringstream;
using std::string;
using std::endl;
using std::setw;

aparato::aparato(double precio ,int voltaje,int peso):precio(precio),voltaje(voltaje),peso(peso){
}

double aparato::getPrecio_por_envio(){
	return precio_por_envio(peso,precio);
}

int aparato::getVoltaje(){
	return voltaje;
}

double aparato::getDescuento(int porcentage){
}

void aparato::setNew_Precio(double newprecio){
	this->precio=newprecio;
}

double aparato::getPrecio(){
	return precio;
}

int aparato::getpeso(){
	return peso;
}

string aparato::toString(){
	stringstream ss;
	ss<<"  Voltaje:__________________"<< getVoltaje()<<setw(4)<<" Voltios"<<endl
	  <<"  Peso:_____________________"<< getpeso()<<setw(4)<<" lbs"<<endl;
	return ss.str();
}

double aparato::precio_por_envio(int pesso,int precio){
}

double aparato::calcular_descuento(int porcentage, double precio){
	return (precio/100)*porcentage;
}
string aparato::getMarca(){
	
}