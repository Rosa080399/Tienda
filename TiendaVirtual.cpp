#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
using namespace std;

const int num = 10;
//Estructura para registrar los productos
struct Tienda
{
	int clave;
	string nombre;
	int cantidad;
	double precio;
};
Tienda tienda[num];
//Estructura 
struct Usuario
{
	int clave = 10;
	string nombre;
	double saldo;
};
Usuario usuario;

struct Comprados
{
	int clave;
	string nProducto;
};
Comprados comprados[num];

void menu1();
void menuAdmin();
void menuUsuario();
void funcionAdmin();
void funcionUsuario();
void comprar(int);
int buscarClave(int);

int main()
{
	int opcion1;//Variabe elegir tipo de usuario

	do{
		menu1();
		cin >> opcion1;
		switch(opcion1)
		{//Menu usuario
			case '1':
					funcionAdmin();
			break;
			case '2':
					funcionUsuario();
			break;
			case '3':
					cout << "Programa finalizado" << endl;
			break;
			case '4': 
			default:
					cout << "Opcion invalida! " << endl;
			break;
		}
	}while(opcion1 != '4');
	getch();
	return 0;
}//Fin de main

//Funcion elegir el tipo de usuario
void menu1()
{
	cout << "\nBienvenido... Eliga su opcion"<< endl;
	cout << "1.Administrador."<< endl;
	cout << "2.Cliente."<< endl;
	cout << "3.Salir\n" << "OPCION: ";
}

//Fucion mostrara menu al administrador
void menuAdmin()
{
	cout << "Bienvenido administrador\n";
	cout << "1.-Registrar productos" << endl;
	cout << "2.-Agregar productos a la bodega" << endl;
	cout << "3.-Salir." << "OPCION: " << endl;
}

//Menu para usuarios
void menuUsuario()
{
	cout << "Bienvenido usuario." << endl;
	cout << "1.-Comprar productos." << endl;
	cout << "2.-Mostrar productos comprados. " << endl;
	cout << "3.-Salir." << "OPCIO: " << endl;
}

void funcionAdmin()
{
	//
}

void funcionUsuario()
{
	int opcion;
	int numClave;
	do{
		switch(opcion)
		{
		case '1':
			cout<<"------Productos disponibles------\n";
        	for(int i=0; i<num; i++)
        	{
        		if( tienda.clave [i] == i)
				{
        			cout << i+1 << ". " << tienda.nombre[i] << ndl;
        		}
        	}
        	cout << "\nIngresar la clave del producto que desea comprar: "; cin >> numClave;
        	comprar(numClave);
		break;
		case '2':
				cout << "Productos adquiridos." << endl;
				cout << "\tClave " << "\tNombre" << endl;
				for(int i=0; i<num; i++)
				{
					if(comprados.clave[i] !=0)
					{
						cout << "\t" << comprados.clave[i] << "\t " << comprados.nProducto[i] << endl;
					}
				}
		break;
		case '3':
				cout<<"Gracias por utilizar el programa"<<endl;
		break;
		default:
				cout<<"Opcion invalida"<<endl;
		break;
    	}
	}while(opcion !='3');
}

//funcion para comprar los productos 
void comprar(int clave)
{
	int bClave = buscarClave(clave);
	if(bClave != 0)
	{
		for(int i=0; i<num; i++)
		{
			if(comprados.clave[i] == 0 && tienda.precio[bClave] < usuario.saldo)
			{
				comprados.clave[i] == tienda.clave[bClave];
				comprados.nProducto[i] == tienda.nombre[bClave];
				tienda.clave[bClave] == 0;
				cout << "Producto comprado satisfactoriamente" << endl;
				return;
			}
		}
	}
	cout << "Ocurrio un error durante la operacion" << endl;
	return;
}

//Busca la clave del producto a comprar 
int buscarClave(int nClave)
{
	for(int i=0; i<num; i++)
	{
		if(nClave == tienda.clave[i])
		{
			if(tienda.cantidad[i] !=0)
			{
				return i;
			}
			return 0;
		}
	}
	return 0;
}

//Iguala la clave del producto que desea eliminar a 0 y se toma como eliminado pero no lo elimina
void eliminarProducto(int c)
{
	for(int i=0; i<num; i++)
	{
		tienda.clave[c] == 0;
	}
}
