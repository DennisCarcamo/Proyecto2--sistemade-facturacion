#include "aparato.h"
#include <string>
using std::string;

class equipo:public aparato{
  public:	
	int compartimientos_cd;
	int potencia_watts;
	string marca;

 	equipo(double, int, int, int, int, string);
 	virtual int getVoltaje();
	virtual double getPrecio();
	virtual string getMarca();
	virtual int  getpeso();
	virtual void setNew_Precio(double);
	virtual double getPrecio_por_envio();
	virtual double calcular_descuento(int,double);
	virtual double precio_por_envio(int ,int );
	virtual double getDescuento(int);
	virtual string toString();

};