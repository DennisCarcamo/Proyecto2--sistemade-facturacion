#pragma once
#include <iostream>
#include <string>

using std::string;

class aparato{
 
	double precio;
	int voltaje;
	int peso;
 public:
	aparato(double, int, int );
	virtual int getVoltaje();
	virtual double getPrecio();
	virtual int  getpeso();
	virtual void setNew_Precio(double);
	virtual double precio_por_envio(int,int);
	virtual string toString();
	virtual double  getDescuento(int )=0;
	virtual double getPrecio_por_envio()=0;
	virtual double calcular_descuento(int , double)=0;
 	virtual string   getMarca();
};