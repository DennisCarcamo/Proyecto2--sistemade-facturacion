#include "equipo.h"
#include "aparato.h"
#include <iostream>
#include <sstream>
#include <string>

using std::stringstream;
using std::string;
using std::endl;

equipo::equipo(double precio ,int voltaje,int peso, int compartimientos_cd, int potencia_watts, string marca)
	:aparato(precio,voltaje,peso),compartimientos_cd(compartimientos_cd), potencia_watts(potencia_watts),marca(marca){
}


int equipo::getVoltaje(){
	return aparato::getVoltaje();
}


double equipo::getPrecio(){
	return aparato::getPrecio();
}

int equipo::getpeso(){
	return aparato::getpeso();
}

void equipo::setNew_Precio(double newprecio){
	aparato::setNew_Precio(newprecio);
}

double equipo::getDescuento(int porcentage){
	return calcular_descuento(porcentage,aparato::getPrecio());
}

string equipo::getMarca(){
	return marca;
}
	  
string equipo::toString(){
	stringstream ss;
	  ss<<"  Equipo de Sonido "<<endl
	  <<"  Marca:____________________"<< marca<<endl
	  <<aparato::toString()
	  <<"  Compartimientos para CD:__"<<compartimientos_cd<<endl
	  <<"  Potencia de Sonido:_______"<<potencia_watts<<" Watts"<<endl
	  <<"  PRECIO:___________________"<<getPrecio()<<" USD"<<endl;
	return ss.str();
}

double equipo::getPrecio_por_envio(){
	return precio_por_envio(getpeso(),getPrecio());
}

double equipo::precio_por_envio(int pesso,int precio){
	double sendprice=0.0;
	if (pesso>0 && pesso<=8){
		if (precio>90 && precio<116){
			sendprice=((precio*5/100)+30);
			return sendprice;
		}else if (precio>116 && precio<120){
			sendprice=((precio*3/100)+30);
			return sendprice;
		}else{
			sendprice=((precio*1/100)+30);
			return sendprice;
		}

	}else if(pesso>8 && pesso<=12){
		if (precio>90 && precio<116){
			sendprice=((precio*5/100)+35);
			return sendprice;
		}else if (precio>116 && precio<120){
			sendprice=((precio*3/100)+35);
			return sendprice;
		}else{
			sendprice=((precio*1/100)+35);
			return sendprice;
		}

	}else if(pesso>12 && pesso<15){
		if (precio>90 && precio<116){
			sendprice=((precio*5/100)+40);
			return sendprice;
		}else if (precio>116 && precio<120){
			sendprice=((precio*3/100)+40);
			return sendprice;
		}else{
			sendprice=((precio*1/100)+40);
			return sendprice;
		}

	}else if(pesso=15){
		if (precio>90 && precio<116){
			sendprice=((precio*5/100)+60);
			return sendprice;
		}else if (precio>116 && precio<120){
			sendprice=((precio*3/100)+60);
			return sendprice;
		}else{
			sendprice=((precio*1/100)+60);
			return sendprice;
		}
	}
}


double equipo::calcular_descuento(int porcentage, double precio){
	return (precio/100)*porcentage;
}
