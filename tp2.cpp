#include "tp2.h"
#include <iostream>
#include <conio.h>
#define J 100
#include <cstring>
#include <string>
using namespace std;
int cont=0;
double aux=0;


void Registro(int& cant){
	int longitud =0;
	FILE *arch;
	arch=fopen("base.dat","ab");
	if (arch==NULL){
		exit(1);
	}
	Datos usuario;
	fflush(stdin);
	printf("Ingrese un nuevo nombre de  Usuario:");
	gets(usuario.nombre);
	fflush(stdin);
	while(longitud<8){
	printf("Ingrese la Clave a establecer:");
	gets(usuario.contra);
	string con = usuario.contra;
	longitud = con.length();
	if(longitud>0 && longitud<4){
		cout<<"Clave muy poco segura, prueba con otra"<<endl;
		system("pause");
		system("cls");
	}
	if(longitud>=4 && longitud<8){
		cout<<"Clave poco segura, prueba colocando mas caracteres"<<endl;
		system("pause");
		system("cls");
	}
	if(longitud>=8 && longitud<12){
		cout<<"Clave muy segura, su cuenta fue creada existosamente"<<endl;
		cant++;
	}
	}
	
	fwrite(&usuario, sizeof(Datos), 1, arch);
	fclose(arch);
	
	
	system("pause");
}
	
int Login(){
	int existe=0;
	system("cls");
	FILE *arch;
	arch=fopen("base.dat","rb");
	if (arch==NULL){
		cout<<"No hay registros cargados en la base de datos"<<endl;
	system("pause");
	}
	if (arch!=NULL){
	printf("Ingrese su Nombre de Usuario: ");
	string cod;
	string con;
	cin>>cod;
	Datos usuario;
	fread(&usuario, sizeof(Datos), 1, arch);
	while(!feof(arch))
	{
		if (cod==usuario.nombre)
		{
			
			string l2;
			cout<<"Ingrese su clave: ";
			char caracter;
			caracter = getch();
			l2 = "";
			while(caracter != 13){
				if(caracter != 8){
					l2.push_back(caracter);
					cout<<"*";
				}else{
					if(l2.length() > 0){
						cout<< "\b \b";	
						l2 = l2.substr(0, l2.length() -1);
					}
					
				}
				caracter = getch();
			}
			if(l2==usuario.contra){
		    cout<<endl;
			cout<<"Bienvenido "<<usuario.nombre<<endl;
			system("pause");
			existe=1;
			return 1;
			break;
		}
		}
		fread(&usuario, sizeof(Datos), 1, arch);
	}
	}
	if (existe==0 && arch!=NULL && cont!=2){
		cout<<endl;
		cout<<"Datos erroneos. Por favor, intentelo otra vez."<<endl;
		cont++;
	system("pause");
	system("cls");
	return 0;
	}
	 if(cont==2){
		cout<<"Datos erroneos, espere unos segundos y vuelva a intentar. "<<endl;
		system("pause");
		cont=0;
	}
	fclose(arch);
	return 2;
}
	
void Puntaje(float& auxtiempo){
	FILE *arch;
	arch=fopen("base.dat","rb");
	
	if (arch==NULL)
		exit(1);
	Datos usuario;
	usuario.Puntaje = auxtiempo;
	fread(&usuario, sizeof(Datos), 1, arch);
	while(!feof(arch))
	{
		
		printf("%s %0.2f\n",usuario.nombre, usuario.Puntaje);
		
		fread(&usuario, sizeof(Datos), 1, arch);
	}
	system("pause");
	fclose(arch);
}
	
	void Puntaje1(float& auxtiempo1){
		FILE *arch;
		arch=fopen("base.dat","rb");
		
		if (arch==NULL)
			exit(1);
		Datos usuario;
		usuario.Puntaje = auxtiempo1;
		fread(&usuario, sizeof(Datos), 1, arch);
		while(!feof(arch))
		{
			
			printf("%s %0.2f\n",usuario.nombre, usuario.Puntaje);
			
			fread(&usuario, sizeof(Datos), 1, arch);
		}
		system("pause");
		fclose(arch);
	}
		
		
		void Puntaje2(float& auxtiempo2){
			FILE *arch;
			arch=fopen("base.dat","rb");
			
			if (arch==NULL)
				exit(1);
			Datos usuario;
			usuario.Puntaje = auxtiempo2;
			fread(&usuario, sizeof(Datos), 1, arch);
			while(!feof(arch))
			{
				
				printf("%s %0.2f\n",usuario.nombre, usuario.Puntaje);
				
				fread(&usuario, sizeof(Datos), 1, arch);
			}
			system("pause");
			fclose(arch);
		}
