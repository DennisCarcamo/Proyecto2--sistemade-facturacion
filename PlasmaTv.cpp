#include "PlasmaTv.h"
#include "aparato.h"
#include <iostream>
#include <sstream>
#include <string>

using std::stringstream;
using std::string;
using std::endl;

PlasmaTv::PlasmaTv(double precio ,int voltaje,int peso, int pulgadas, string marca)
	:aparato(precio,voltaje,peso),pulgadas(pulgadas),marca(marca){
}


int PlasmaTv::getVoltaje(){
	return 	aparato::getVoltaje();
}

int PlasmaTv::getpeso(){
	return aparato::getpeso();
}

double PlasmaTv::getPrecio(){
	return aparato::getPrecio();
}

double PlasmaTv::getDescuento(int porcentage){
	return calcular_descuento(porcentage,aparato::getPrecio());
}

string PlasmaTv::getMarca(){
	return marca;
}

void PlasmaTv::setNew_Precio(double newprecio){
	aparato::setNew_Precio(newprecio);
}
	  
string PlasmaTv::toString(){
	stringstream ss;
	ss<<"  Televisor Plasma "<<endl
	  <<"  Marca:____________________"<< marca<<endl
	  <<aparato::toString()
	  <<"  Tamano:___________________"<<pulgadas<<" Plg"<<endl
	  <<"  PRECIO:___________________"<<getPrecio()<<" USD"<<endl;
	return ss.str();
}


double PlasmaTv::getPrecio_por_envio(){
	return precio_por_envio(getpeso(),getPrecio());
}

double PlasmaTv::precio_por_envio(int pesso,int precio){
	double sendprice=0.0;
	if (pesso>0 && pesso<=7){
		if (precio>0 && precio<200){
			sendprice=((precio*5/100)+30);
			return sendprice;
		}else if (precio>200 && precio<400){
			sendprice=((precio*3/100)+30);
			return sendprice;
		}else{
			sendprice=((precio*1/100)+30);
			return sendprice;
		}

	}else if(pesso>7 && pesso<=11){
		if (precio>0 && precio<200){
			sendprice=((precio*5/100)+35);
			return sendprice;
		}else if (precio>200 && precio<400){
			sendprice=((precio*3/100)+35);
			return sendprice;
		}else{
			sendprice=((precio*1/100)+35);
			return sendprice;
		}

	}else if(pesso>11 && pesso<=13){
		if (precio>0 && precio<200){
			sendprice=((precio*5/100)+40);
			return sendprice;
		}else if (precio>200 && precio<400){
			sendprice=((precio*3/100)+40);
			return sendprice;
		}else{
			sendprice=((precio*1/100)+40);
			return sendprice;
		}

	}else if(pesso>13){
		if (precio>0 && precio<210){
			sendprice=((precio*5/100)+60);
			return sendprice;
		}else if (precio>210 && precio<400){
			sendprice=((precio*3/100)+60);
			return sendprice;
		}else{
			sendprice=((precio*1/100)+60);
			return sendprice;
		}
	}
}


double PlasmaTv::calcular_descuento(int porcentage, double precio){
	return (precio/100)*porcentage;
}
