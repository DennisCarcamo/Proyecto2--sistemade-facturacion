#include <iostream>
#include "aparato.h"
#include "PlasmaTv.h"
#include "equipo.h"
#include "HornoMicroondas.h"
#include "refrigeradora.h"
#include <string>
#include <sstream>
#include <vector>
#include <typeinfo>
#include <iomanip>
#include <fstream>

/*Pograma de facturacion Basica*/
//********* Autor: Dennis Carcamos *************//

using std::stringstream;
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::ofstream;
using std::setprecision;
using std::fixed;
using std::right;


void agregarproducto(vector <aparato*>&);
void guardarFactura(vector <aparato*>&, int, string);
void eliminardelcarrito(vector <aparato*>& );
void liberarmemoria(vector <aparato*>& );
void cancelarcompra(vector <aparato*>& compras);
double preciotvs(int);
double precioequipos(int, int);
double precioHorno(int);
double precirefrigeradora(int, int);

int main(int argc, char* argv[]){
	bool otracompra=true;
	while(otracompra){
		int edad;
		string nombrecliente="";
		cout<<"****************** BIENVENIDOS A SYSTEM SMART ONLINE ********************"<<endl;
		vector <aparato*> compras;
 		cout<<"Ingrese el nombre del cliente"<<endl;
		getline(cin,nombrecliente);
		cout<<"Ingrese la edad"<<endl;
		cin>>edad;
		int opcionmenu=0;
		while(opcionmenu!=5){
	 		cout<<"**************************** OPCIONES ***********************************"<<endl;
			cout<<""<<endl
				<<"1-Agregar Articulos al Carrito"<<endl
				<<"2-Eliminar Producto del Carrito"<<endl
				<<"3-Cancelar Compra"<<endl
				<<"4-Facturar"<<endl
				<<"5-Salir"<<endl;
			cin>>opcionmenu;
			cout<<""<<endl;

			if (opcionmenu==1){
				agregarproducto(compras);
			
			}else if (opcionmenu==2){
				eliminardelcarrito(compras);
			
			}else if (opcionmenu==3){
				cout<<""<<endl
					<<"************************* CANCELAR COMPRA *******************************"<<endl;
					cout<<""<<endl;
				if (compras.size()!=0){
					cancelarcompra(compras);
					break;
				}else{
					cout<<"No hay Articulos en el carrito"<<endl;
					cout<<""<<endl;
				}
				
			}else if (opcionmenu==4){
				cout<<""<<endl
					<<"****************************** FACTURAR *********************************"<<endl;
				if (compras.size()!=0){
				
					double impuesto=0.0;
					double total=0.0;
					double precioenvio=0.0;
					double totalfinal=0.0;
		
					
					for (int i = 0; i < compras.size(); i++){
						cout<<i+1<<compras.at(i)->toString();

						if (typeid(*compras[i])==typeid(PlasmaTv)){
							total=compras.at(i)->getPrecio()-compras.at(i)->getDescuento(5);
							precioenvio=compras.at(i)->getPrecio_por_envio();
							compras.at(i)->setNew_Precio(total+precioenvio); 
							cout<<"  Descuento del 5%________________________________ $";
							cout.width(8);
							cout<<right;
							printf("%9.2f\n",compras.at(i)->getDescuento(5)); 
							cout<<"  Precio de Envio_________________________________ $";
							cout.width(8);
							cout<<right;
							printf("%9.2f\n",precioenvio);
							cout<<"  Subtotal:_______________________________________ $";
							cout.width(8);
							cout<<right;
							printf("%9.2f\n",compras.at(i)->getPrecio());

							totalfinal+=total+precioenvio;

						}else if (typeid(*compras[i])==typeid(equipo)){
							total=compras.at(i)->getPrecio()-compras.at(i)->getDescuento(10);
							precioenvio=compras.at(i)->getPrecio_por_envio();
							compras.at(i)->setNew_Precio(total+precioenvio);
							cout<<"  Descuento del 10%_______________________________ $";
						 
							printf("%9.2f\n",compras.at(i)->getDescuento(10));
							cout<<"  Precio de Envio_________________________________ $";
							 
							printf("%9.2f\n",precioenvio);
							cout<<"  Subtotal:_______________________________________ $";
						 
							printf("%9.2f\n",compras.at(i)->getPrecio());

							totalfinal+=total+precioenvio;

						}else if(typeid(*compras[i])==typeid(HornoMicroondas)){
							total=compras.at(i)->getPrecio()-compras.at(i)->getDescuento(12);
							precioenvio=compras.at(i)->getPrecio_por_envio();
							compras.at(i)->setNew_Precio(total+precioenvio);
							cout<<"  Descuento del 12%_______________________________ $";
							 
							printf("%9.2f\n",compras.at(i)->getDescuento(12));
							cout<<"  Precio de Envio_________________________________ $";
							 
							printf("%9.2f\n",precioenvio);
							cout<<"  Subtotal:_______________________________________ $";
				 
							printf("%9.2f\n",compras.at(i)->getPrecio());

							totalfinal+=total+precioenvio;

						}else if (typeid(*compras[i])==typeid(refrigeradora)){
							total=compras.at(i)->getPrecio()-compras.at(i)->getDescuento(12);
							precioenvio=compras.at(i)->getPrecio_por_envio();
							compras.at(i)->setNew_Precio(total+precioenvio);
							cout<<"  Descuento del 5%________________________________ $";
						 
							printf("%9.2f\n",compras.at(i)->getDescuento(5)); 
							cout<<"  Precio de Envio_________________________________ $";
						 
							printf("%9.2f\n",precioenvio);
							cout<<"  Subtotal:_______________________________________ $";
						 
							printf("%9.2f\n",compras.at(i)->getPrecio());
							totalfinal+=total+precioenvio;
						}
 
						cout<<""<<endl;
					} 
					if (edad>0 && edad< 63 ){
						cout<<"  SUBTOTAL DE LA COMPRA______________________________________________________ $";
					 
						printf("%11.2f\n",totalfinal);
						cout<<"  15% Impuesto S/V___________________________________________________________ $";
						 
						printf("%11.2f\n",(totalfinal/100)*15);
						cout<<"  TOTAL DE LA COMPRA_________________________________________________________ $";
						 
						printf("%11.2f\n",totalfinal+((totalfinal/100)*15));
						cout<<""<<endl;
						
					}else if(edad>0 && edad>=63){
						double descterceraedad=0.0;
						descterceraedad=(totalfinal/100*15);
						cout<<"  SUBTOTAL DE LA COMPRA______________________________________________________ $";
						printf("%11.2f\n",totalfinal);
						cout<<"  Descuento de la tercera edad 15%___________________________________________ $"; 
						printf("%11.2f\n",(totalfinal/100)*5);
						cout<<"  5% Impuesto S/V____________________________________________________________ $"; 
						printf("%11.2f\n",totalfinal);
						cout<<"  TOTAL DE LA COMPRA_________________________________________________________ $"; 
						cout<<""<<endl;

					}
					char guardar;
					cout<<"precione G para documentar factura"<<endl;
					cin>>guardar;
					if (guardar=='G' || guardar=='g'){
						guardarFactura(compras,edad,nombrecliente);
					}
					liberarmemoria(compras);
					break;
				}else{
					cout<<"No hay Articulos en el carrito"<<endl;
					cout<<""<<endl;
				}
				
			}else if (opcionmenu==5){
				cancelarcompra(compras);
				break;
			} 
		}//fin del while
		char continuar;
		cout<<"¿Hacer otra compra? s/n"<<endl;
		cin>>continuar;
		if (continuar=='S' || continuar=='s'){
			otracompra=true;
			cout<<""<<endl;
		}else{
			otracompra=false;
			cout<<""<<endl;
		}
		cin.ignore();
	}//seguir comprando
	return 0;
}

void guardarFactura(vector <aparato*>& compras, int edad, string nombrecliente){
	double impuesto=0.0;
	double total=0.0;
	double precioenvio=0.0;
	double totalfinal=0.0;

	struct tm *tiempo;
	int dia;
	int mes;
	int anio;

 	time_t fecha_sistema;
	time(&fecha_sistema);
    tiempo=localtime(&fecha_sistema);
 
	anio=tiempo->tm_year + 1900;
	mes=tiempo->tm_mon + 1;
	dia=tiempo->tm_mday;
	//encabezado de la factura.
	ofstream file("Factura.txt");
	file<<"***************** SISTEM SMART ONLINE *********************"<<endl;
	file<<""<<endl
	    <<"       FACTURA           FECHA: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
	file<<"\n Cliente: "<<nombrecliente<<endl;
	file<<""<<endl;

	for (int i = 0; i < compras.size(); i++){
		if (typeid(*compras[i])==typeid(PlasmaTv)){
			file<<i+1<<" Televisor Plasma "<<compras.at(i)->getMarca()<<endl;
			total=compras.at(i)->getPrecio()-compras.at(i)->getDescuento(5);
			precioenvio=compras.at(i)->getPrecio_por_envio(); 
			file<<"  Descuento del 5%.................. $";
			file.width(8);
			file<<right<<fixed<< setprecision(2)<<compras.at(i)->getDescuento(5)<<endl; 
			file<<"  Precio de Envio................... $";
			file.width(8);
			file<<right<<fixed<<setprecision(2)<<precioenvio<<endl;
			file<<"  Subtotal:......................... $";
			file.width(8);
			file<<right<<fixed<< setprecision(2)<<compras.at(i)->getPrecio()<<endl;
			totalfinal+=compras.at(i)->getPrecio();

		}else if (typeid(*compras[i])==typeid(equipo)){
			file<<i+1<<" Equipo de Sonido "<<compras.at(i)->getMarca()<<endl;
			total=compras.at(i)->getPrecio()-compras.at(i)->getDescuento(10);
			precioenvio=compras.at(i)->getPrecio_por_envio(); 
			file<<"  Descuento del 10%................. $";
			file.width(8);
			file<<right<<fixed<< setprecision(2)<<compras.at(i)->getDescuento(10)<<endl; 
			file<<"  Precio de Envio................... $";
			file.width(8);
			file<<right<<fixed<<setprecision(2)<<precioenvio<<endl;
			file<<"  Subtotal:......................... $";
			file.width(8);
			file<<right<<fixed<< setprecision(2)<<compras.at(i)->getPrecio()<<endl;
			totalfinal+=compras.at(i)->getPrecio();

		}else if(typeid(*compras[i])==typeid(HornoMicroondas)){
			file<<i+1<<" Horno Microondas "<<compras.at(i)->getMarca()<<endl;
			total=compras.at(i)->getPrecio()-compras.at(i)->getDescuento(12);
			precioenvio=compras.at(i)->getPrecio_por_envio(); 
			file<<"  Descuento del 12%................. $";
			file.width(8);
			file<<right<<fixed<< setprecision(2)<<compras.at(i)->getDescuento(12)<<endl; 
			file<<"  Precio de Envio................... $";
			file.width(8);
			file<<right<<fixed<<setprecision(2)<<precioenvio<<endl;
			file<<"  Subtotal:......................... $";
			file.width(8);
			file<<right<<fixed<< setprecision(2)<<compras.at(i)->getPrecio()<<endl;
			totalfinal+=compras.at(i)->getPrecio();

		}else if(typeid(*compras[i])==typeid(refrigeradora)){
			file<<i+1<<" Refrigeradora "<<compras.at(i)->getMarca()<<endl;
			total=compras.at(i)->getPrecio()-compras.at(i)->getDescuento(5);
			precioenvio=compras.at(i)->getPrecio_por_envio(); 
			file<<"  Descuento del 5%.................. $";
			file.width(8);
			file<<right<<fixed<< setprecision(2)<<compras.at(i)->getDescuento(5)<<endl; 
			file<<"  Precio de Envio................... $";
			file.width(8);
			file<<right<<fixed<<setprecision(2)<<precioenvio<<endl;
			file<<"  Subtotal:......................... $";
			file.width(8);
			file<<right<<fixed<< setprecision(2)<<compras.at(i)->getPrecio()<<endl;
			totalfinal+=compras.at(i)->getPrecio();
		}


		file<<""<<endl;

	}
	file<<" __________________________________________________________  "<<endl;
	if (edad>0 && edad< 63 ){
		file<<"  SUBTOTAL DE LA COMPRA..............$ "<<totalfinal<<endl;
		file<<"  15% Impuesto S/V...................$ "<<(totalfinal/100)*15<<endl;
		file<<"  TOTAL DE LA COMPRA......................... $ "<<totalfinal+((totalfinal/100)*15)<<endl;
		file<<""<<endl;

	}else if(edad>0 && edad>=63){
		double descterceraedad=0.0;
		descterceraedad=(totalfinal/100*15);
		file<<"  SUBTOTAL DE LA COMPRA............. $ "<<totalfinal<<setw(5)<< endl;
		file<<"  Descuento de la tercera edad 15%...$ "<<descterceraedad<<setw(5) <<endl;
		file<<"  5% Impuesto S/V....................$ "<<(totalfinal/100)*5 <<endl;
		file<<"  TOTAL DE LA COMPRA.............................. $ "<<(totalfinal+((totalfinal/100)*5))-descterceraedad<<endl;
		file<<""<<endl;

	}
	file<<""<<endl;
	file<<"***************** GRACIAS POR PREFERIRNOS *****************"<<endl;

	file.close();
}

void liberarmemoria(vector <aparato*>& compras){
	for (int i = 0; i < compras.size(); i++){
		delete compras.at(i);
	}	
}

void cancelarcompra(vector <aparato*>& compras){
	for (int i = 0; i < compras.size(); i++){
		delete compras.at(i);
	}
	cout<<"************************ PEDIDOS CANCELADOS *****************************"<<endl;
	cout<<""<<endl;
}

void eliminardelcarrito(vector <aparato*>& compras){
	int opcioneliminar;
	cout<<"************************ ELIMINAR DEL CARRITO **************************"<<endl
		<<""<<endl;
	if(compras.size()==0){
		cout<<"No hay Articulos en el carrito"<<endl;
		cout<<""<<endl;
	}else if (compras.size()){
		cin.ignore();
		cout<<"********** Seleccione el Producto que desea sacar del carrito **********"<<endl;
		for (int i = 0; i < compras.size(); i++){
			cout<<i+1<<compras.at(i)->toString()<<endl;
		}
		cin>>opcioneliminar;
		if (opcioneliminar>=1 && opcioneliminar<=compras.size()){
			compras.erase(compras.begin()+opcioneliminar-1);
		}else{
			cout<<"Lo Siento no existe ese Indice en el carrito"<<endl;
		}
	}
}

void agregarproducto(vector <aparato*>& compras){
	double precio=0.0;
	int voltaje;
	int peso;
	int opcionarticulo;
	cout<<"*********************** AGREGAR AL CARRITO ******************************"<<endl;
	cout<<""<<endl
	<<"1-Televisor Plasma"<<endl
	<<"2-Equipo de Sonido"<<endl
	<<"3-Horno Microondas"<<endl
	<<"4-Refrigeradora"<<endl;
	cin>>opcionarticulo;
	if (opcionarticulo==1){
		int pulgadas;
		string marca;
		cout<<""<<endl;
		while(voltaje<110 || voltaje>200){
			cout<<"Ingrese el voltaje (voltios) del Televisor ---rango 110-200: ";
			cin>>voltaje;
		}

		while (peso<7 || peso>13){ 
			cout<<"Ingrese el peso en libras del Televisor ---rango 7-13: ";
			cin>>peso;
		}

		while(pulgadas<20 || pulgadas>85){
			cout<<"Ingrese de cuantas pulgadas es el Televisor ---rango 20-85: ";
			cin>>pulgadas;
		}
		cout<<"Ingrese la marca del Televisor: ";
		cin>>marca;
		cout<<""<<endl;
		precio=	preciotvs(pulgadas);
		compras.push_back(new PlasmaTv(precio,voltaje,peso,pulgadas,marca));
	

	}else if (opcionarticulo==2){
		int compartimientos_cd;
		int potencia_watts;
		string marca;
		cout<<""<<endl;
		while(voltaje<110 || voltaje>160){
			cout<<"Ingrese el voltaje (voltios) del Equipo ---rango 110-160: ";
			cin>>voltaje;
		}
		
		while(peso<5 || peso>11){
			cout<<"Ingrese el peso en libras del Equipo ---rango 7-11: ";
			cin>>peso;

		}

		while(compartimientos_cd >3 || compartimientos_cd<0){
			cout<<"Ingrese la cantidad de compartimientos para cd ---rango 0-3: ";
			cin>>compartimientos_cd;
		}

		while(potencia_watts<300 || potencia_watts>1400){
			cout<<"Ingrese  la Potencia de Sonido Watts ---rango 300-1400: ";
			cin>>potencia_watts;
		}
		
		cout<<"Ingrese la marca del Equipo de Sonido: ";
		cin>>marca;
		cout<<""<<endl;
		precio=precioequipos(compartimientos_cd,potencia_watts);
		compras.push_back(new equipo(precio,voltaje,peso,compartimientos_cd,potencia_watts,marca));
		
	}else if(opcionarticulo==3){
		int specialfuntions;
		string marca;
		cout<<""<<endl;
		while(voltaje<110 || voltaje>220){
			cout<<"Ingrese el voltaje (voltios) del Horno Microondas ---rango 110-220: ";
			cin>>voltaje;
		}

		while(peso<7 || peso>11){
			cout<<"Ingrese el peso en libras del Horno Microondas ---rango 7-11: ";
			cin>>peso;
		}

		while(specialfuntions<1 || specialfuntions>7){
			cout<<"Ingrese la cantidad de Funciones Especiales que posee ---rango 1-7: ";
			cin>>specialfuntions;
		}

		cout<<"Ingrese la marca del Horno: ";
		cin>>marca;
		cout<<""<<endl;
		precio=precioHorno(specialfuntions);
		compras.push_back(new HornoMicroondas(precio,voltaje,peso,specialfuntions,marca));

	}else if (opcionarticulo==4){
		int puertas=0;
		int piescubicos=0;
		string marca;
		cout<<""<<endl;
		while(voltaje<110 || voltaje>220){
			cout<<"Ingrese el voltaje (voltios) de la Refrigeradora ---rango 110-220: ";
			cin>>voltaje;
		}

		while(peso<20 || peso>100){
			cout<<"Ingrese el peso en libras de la Refrigeradora ---rango 20-100: ";
			cin>>peso;
		}

		while(puertas<1 || puertas>4){
			cout<<"Ingrese la cantidad de Puertas que tiene la Refrigeradora ---rango 1-4: ";
			cin>>puertas;
		}

		while(piescubicos<1 || piescubicos>3){
			cout<<"Ingrese los pies Cubicos de la Refrigeradora ---rango 1-3: ";
			cin>>piescubicos;
		}
		cout<<"Ingrese la marca de la Refrigeradora: ";
		cin>>marca;
		cout<<""<<endl;
		precio=precirefrigeradora(piescubicos,puertas);
		compras.push_back(new refrigeradora(precio,voltaje,peso,puertas,piescubicos,marca));
	}
}

double preciotvs(int pulgadas){
	if (pulgadas>=20 && pulgadas<=26){
		return 100.0;
	}else if(pulgadas==26 && pulgadas<=32){
		return 299.0;
	}else if(pulgadas==32 && pulgadas<=40){
	 	return 449.0;
	}else if(pulgadas>40 && pulgadas<=46){
		return 460.0;
	}else if(pulgadas>46 && pulgadas<=52){
		return 800.0;
	}else if(pulgadas>52 && pulgadas<=85){
		return 920.0;
	}
}

double precioequipos(int compartimientos_cd, int potencia_watts){
	if (compartimientos_cd==1){
        	if (potencia_watts>=300 && potencia_watts<=500){
			return 96.95;
		}else if(potencia_watts>=500 && potencia_watts<=800){
			return 110.10;
		}else if(potencia_watts>=900 && potencia_watts<=1200){
			return 115.25;
		}else if(potencia_watts>=1200 && potencia_watts<=1400){
			return 120.50;
		}
	}else if (compartimientos_cd==2){
		if (potencia_watts>=300 && potencia_watts<=500){
			return 110.25;
		}else if(potencia_watts>=500 && potencia_watts<=800){
			return 118.10;
		}else if(potencia_watts>=900 && potencia_watts<=1200){
			return 123.25;
		}else if(potencia_watts>=1200 && potencia_watts<=1400){
			return 127.03;
		}
	}else if (compartimientos_cd==3){
		if (potencia_watts>=300 && potencia_watts<=500){
			return 115.25;
		}else if(potencia_watts>=500 && potencia_watts<=800){
			return 122.10;
		}else if(potencia_watts>=900 && potencia_watts<=1200){
			return 129.25;
		}else if(potencia_watts>=1200 && potencia_watts<=1400){
			return 135.03;
		}
	}else if (compartimientos_cd==0){
		if (potencia_watts>=300 && potencia_watts<=500){
			return 90.95;
		}else if(potencia_watts>=500 && potencia_watts<=800){
			return 100.10;
		}else if(potencia_watts>=900 && potencia_watts<=1200){
			return 102.25;
		}else if(potencia_watts>=1200 && potencia_watts<=1400){
			return 107.50;
		}
	}
}

double precioHorno(int specialfuntions){
	if (specialfuntions>=1 && specialfuntions<3){
		return 60.30;
	}else if (specialfuntions>=3 && specialfuntions<5){
		return 75.20;
	}else if (specialfuntions=5 && specialfuntions<=7 ){
		return 90.20;
	}
}

double precirefrigeradora(int piescubicos ,int puertas){
	 
	if (piescubicos==1){ 
		if (puertas==1){
			return 199.60;
		}else if (puertas==2){
			return 210.35;
		}else if (puertas==3){
			return 212.60;
		}else if (puertas==4){
			return 215.60;
		}
	}else if (piescubicos==2){ 
		if (puertas==1){
			return 220.60;
		}else if (puertas==2){
			return 230.60;
		}else if (puertas==3){
			return 240.60;
		}else if (puertas==4){
			return 250.60;
		}
	}else if (piescubicos==3){ 
		if (puertas==1){
			return 240.60;
		}else if (puertas==2){
			return 260.60;
		}else if (puertas==3){
			return 270.60;
		}else if (puertas==4){
			return 285.60;
		}
    }
}

 
