#include "tp2.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <conio.h>
#include <iterator>
#include <ctime>
#include<time.h>
#include<windows.h>
#define J 100
#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13
#include <cctype>
using namespace std;
unsigned tiempoInicial,tiempoFinal;
void instrucciones();
void jugada(int &lvl);
void Menu(int &lvl);
void Completar(int& lvl, int Matriz[J][J]);
void Jugar(int& lvl,int Matriz[J][J]);
void color(int X);
void cara();
void matrizGrande(int MatrizAux[J][J]);
void matrizMediana(int MatrizAux[J][J]);
void matrizChica(int MatrizAux[J][J]);
void gotoxy(int x,int y);
void CARTEL();
void MenuUsuario();
void menupuntaje();
float auxtiempo,auxtiempo1,auxtiempo2;
float tiempoTotal;
int Nivel(int &lvl);
int MenuP(const char* opciones[], int n);
int cant=0;
int lvl=0;
int main() {
	system("mode con: cols=100 lines=30");
	system("color 17");
	//Sleep(5000);
	bool salir = true;
	int opss;
	cout<<""<<endl; 
	cout<<""<<endl;
	cout<<"		____________________________________________________________________________		"<<endl;
	cout<<"		|######                                                                    |      "<<endl;
	cout<<"		|#     #  #    #   ####    ####     ##    #    #  #  #    #    ##     #### | 		"<<endl;
	cout<<"		|#     #  #    #  #       #    #   #  #   ##  ##  #  ##   #   #  #   #     | 		"<<endl;
	cout<<"		|######   #    #   ####   #       #    #  # ## #  #  # #  #  #    #   #### | 		"<<endl;
	cout<<"		|#     #  #    #       #  #       ######  #    #  #  #  # #  ######       #| 		"<<endl;
	cout<<"		|#     #  #    #  #    #  #    #  #    #  #    #  #  #   ##  #    #  #    #|		"<<endl;
	cout<<"		|######    ####    ####    ####   #    #  #    #  #  #    #  #    #   #### |		"<<endl;
	cout<<"		|__________________________________________________________________________|		"<<endl;
	cout<<""<<endl;
	cout<<""<<endl;
	system ("pause");
	Beep(500,1000);
	const char *opciones[] = {"AVANZAR","SALIR"};
	int n  = 2;
	do{
		opss = MenuP(opciones,n);
		switch(opss){
		case 1 :
			system("cls");
			MenuUsuario();
			break;
		case 2 :
			salir = false;
			Beep(200,1000);
			break;
		}
	}while(salir);
	
	return 0;
}
void MenuUsuario(){
	int opss;
	bool salir = true;
	const char *opciones[] = {"INICIAR SECION","CREAR USUARIO","VER PUNTAJE","INSTRUCCIONES","SALIR"};
	int n  = 5;
	do{
		opss = MenuP(opciones,n);
		switch(opss){
		case 1:
			Beep(1500,700);
			if(Login()==1){
				Menu(lvl);
			}
			else{
				break;
			}
			
			system("cls");
			
			
			break;
		case 2:
			Beep(1500,700);
			system("cls");
			if(cant < 100){   // CANTIDAD MAXIMA DE USUARIOS ES 100
			Registro(cant);
			}else{
				cout<<"Opcion no valida, base de datos llena"<<endl;
				system("pause");
			}
			break;
			
		case 3:
			Beep(1500,700);
			system("cls");
			menupuntaje();
			break;
			
		case 4:
			Beep(1500,700);
			system("cls");
			instrucciones();
			break;
			
		case 5:
			system("cls");
			salir = false;
			break;
		}Beep(1500,700);
	}while(salir);
}
void Menu(int &lvl){
	bool salir = true;
	int opss;
	int Matriz[J][J];
	const char *opciones[] = {"Dificultad","Comenzar","Cerrar Sesion"};
	int n  = 3;
	do{
		opss = MenuP(opciones,n);
		/*system("cls");
		cout<<endl;
		cout<<"              			    A - Instrucciones del Juego"<<endl;
		cout<<endl;
		cout<<"              			    B - Dificultad del Juego"<<endl;
		cout<<endl;
		cout<<"              			    C - Comenzar el Juego"<<endl;
		cout<<endl;
		cout<<"              			    S - Para volver al menu anterior"<<endl;
		cout<<endl;
		cin>>opss;
		*/
		switch(opss){
		case 1:
			system("cls");
			Nivel(lvl);
			
			break;
		case 2:
			system("cls");
			Completar(lvl,Matriz); //COMPLETAR MATRIZ
			Jugar(lvl,Matriz); // JUGAR
			
			break;
		case 3:
			system("cls");
			salir = false;
			Beep(200,1000);
			break;
			
			break;
		}
	}while(salir);
	
}
	
	int Nivel(int &lvl){
		bool salir = true;
		int opss;
		const char *opciones[] = {"Facil","Intermedio","Dificil","Regresar"};
		int n  = 4;
		do{
			opss = MenuP(opciones,n);
			switch (opss){
			case 1:{
				lvl = 0;
				system("cls");
				cout<<endl;
				cout<< "              			    Dificultad Facil establecida"<<endl;
				
				cout<<endl;
				system("pause");
				system("cls");
				break;
			}
			case 2:{
					lvl = 1;
					system("cls");
					cout<<endl;
					cout<< "              			    Dificultad Intermedia establecida"<<endl;
					
					cout<<endl;
					system("pause");
					system("cls");
					break;
				}
			case 3:{
						lvl = 2;
						system("cls");
						cout<<endl;
						cout<< "              			    Dificultad Dificil establecida"<<endl;
						
						cout<<endl;
						system("pause");
						system("cls");
						break;
					}
			case 4:{
							salir = false;
							break;
						}
			}
		}while(salir);
		
		return lvl;
	}
		void Completar(int &lvl,int Matriz[J][J]){
			
			int cont1=0;
			int auxf,auxc;
			srand(time(NULL));
			
			if(lvl == 0){
				for(int i=0; i<8; i++){
					for(int k=0 ; k<8; k++){
						Matriz[i][k] = 10;
					}
				}
				while(cont1<10){
					auxc = rand()%8;
					auxf = rand()%8;
					if(Matriz[auxf][auxc]!=9){
						Matriz[auxf][auxc] = 9;
						cont1++;
					}
					auxc=0;
					auxf=0;
				}
				for(int i=0; i<8; i++){
					for(int k=0 ; k<8; k++){
						cout<<char(254)<<" ";
						//cout<<Matriz[i][k]<<" ";
					}
					cout<<endl;
				}
			}
			
			if(lvl == 1){
				for(int i=0; i<16; i++){
					for(int k=0 ; k<16; k++){
						Matriz[i][k] = 10;
					}
				}
				while(cont1<40){
					auxc = rand()%16;
					auxf = rand()%16;
					if(Matriz[auxf][auxc]!=9){
						Matriz[auxf][auxc] = 9;
						cont1++;
					}
					auxc=0;
					auxf=0;
				}
				for(int i=0; i<16; i++){
					for(int k=0 ; k<16; k++){
						cout<<char(254)<<" ";
						//cout<<Matriz[i][k]<<" ";
					}
					cout<<endl;
				}
			}
			
			if(lvl == 2){
				for(int i=0; i<16; i++){
					for(int k=0 ; k<32; k++){
						Matriz[i][k] = 10;
					}
				}
				while(cont1<99){
					auxc = rand()%32;
					auxf = rand()%16;
					if(Matriz[auxf][auxc]!=9){
						Matriz[auxf][auxc] = 9;
						cont1++;
					}
					auxc=0;
					auxf=0;
				}
				for(int i=0; i<16; i++){
					for(int k=0 ; k<32; k++){
						cout<<char(254)<<" ";
						//cout<<Matriz[i][k]<<" ";
					}
					cout<<endl;
				}
			}
		}
			
			void Jugar(int &lvl,int Matriz[J][J]){
				char opc;
				int f,c,nm=10;
				int vic=0;
				int contadordeminas=0;
				bool band= false;
				
				
				int aux=20; 
				int MatrizAux[J][J];
				
				if(lvl == 0){
					for(int i=0;i<8;i++){
						for(int j=0;j<8;j++){
							MatrizAux[i][j] = 10;
						}
					}
				}
				
				if(lvl == 1){
					for(int i=0;i<16;i++){
						for(int j=0;j<16;j++){
							MatrizAux[i][j] = 10;
						}
					}
				}
				
				if(lvl == 2){
					for(int i=0;i<16;i++){
						for(int j=0;j<32;j++){
							MatrizAux[i][j] = 10;
						}
					}
				}
				
				// TERMINA LA ASIGNACION DE MATRICES (TAMAÑO) MatrizAUX
				
				if(lvl == 0){
					tiempoInicial=clock();
					vic=0;
					do{
						cout<<endl;
						cout<<" Fila: ";
						cin>>f;
						cout<<endl;
						cout<<" Columna: ";
						cin>>c;
						cout<<endl;
						cout<<" Accion: ";
						cin>>opc;
						if(f<8 && c<8){
							switch(opc){
							case 'M':
								if(MatrizAux[f][c] == nm ){
									MatrizAux[f][c] = aux;
									
									cout<<"La opcion fue marcada correctamente"<<endl;
									Beep(5000,50);
									system("pause");
									
								}
								else{
									MatrizAux[f][c] = nm;
									cout<<"La opcion fue desmarcada correctamente"<<endl;
									Beep(5000,50);
									system("pause");
								}
								
								system("cls");
								matrizChica(MatrizAux);
								break;
							case 'D':
								
								if(MatrizAux[f][c] == nm){
									for(int i=0;i<8;i++){
										for(int j=0;j<8;j++){
											if(Matriz[f][c]== 9){
												band=true;
											}
											else{
												band=false;
											}
										}
									}
									if(band == true){
										system("cls");
										cara();
										Beep(100,2000);
										tiempoFinal=clock();
										tiempoTotal=double((tiempoFinal-tiempoInicial)/CLOCKS_PER_SEC);
										cout<<"Tiempo de ejecución (en segundos): "<<tiempoTotal<<endl;
										cout<<endl;
										auxtiempo = tiempoTotal;
										
										for(int i =0;i<8;i++){
											for(int j=0;j<8;j++){
												if(Matriz[i][j]==9){
													cout<<char(158)<<" ";
												}else{
													cout<<char(254)<<" ";
												}
											}
											cout<<endl;
										}
										system("pause");
									}
									else{
										
										for(int i = f-1; i<f+2; i++) {
											for(int j=c-1; j<c+2; j++) {
												if(Matriz[i][j]==9) {
													contadordeminas++;
													vic++;
													
												}
											}
										}

										system("cls");
										MatrizAux[f][c] = contadordeminas;
										matrizChica(MatrizAux);
										contadordeminas=0;
										if(vic == 54){
											cout<<endl;
											cout<<"  FELICIDADES, SUPERASTE EL NIVEL FACIL!"<<endl;
										}
									}
								}else{
									Beep(1500,1000);
									cout<<endl;
									cout<<"  Esta casilla fue marcada o ya descubierta"<<endl;
									cout<<endl;
									system("pause");
									system("cls");
									matrizChica(MatrizAux);
								}
							}
						}else{
							Beep(1500,1000);
							cout<<endl;
							cout<<"  Porfavor ingrese una posicioón válida"<<endl;
							cout<<endl;
							system("pause");
							system("cls");
							matrizChica(MatrizAux);
							
						}
						
					} while(band==false && opc!='S');
					band=false;
				}
				
				if(lvl == 1){
					tiempoInicial=clock();
					vic=0;
					do{
						cout<<endl;
						cout<<" Fila: ";
						cin>>f;
						cout<<endl;
						cout<<" Columna: ";
						cin>>c;
						cout<<endl;
						cout<<" Accion: ";
						cin>>opc;
						if(f<16 && c<16){
							switch(opc){
							case 'M':
								if(MatrizAux[f][c] == nm ){
									MatrizAux[f][c] = aux;
									cout<<"La opcion fue marcada correctamente"<<endl;
									Beep(5000,50);
									system("pause");
									
								}
								else{
									MatrizAux[f][c] = nm;
									cout<<"La opcion fue desmarcada correctamente"<<endl;
									Beep(5000,50);
									system("pause");
								}
								
								system("cls");
								matrizMediana(MatrizAux);
								break;
							case 'D':
								
								if(MatrizAux[f][c] == nm){
									for(int i=0;i<16;i++){
										for(int j=0;j<16;j++){
											if(Matriz[f][c]== 9){
												band=true;
											}
											else{
												band=false;
											}
										}
									}
									if(band == true){
										system("cls");
										Beep(100,2000);
										cara();
										tiempoFinal=clock();
										tiempoTotal=double((tiempoFinal-tiempoInicial)/CLOCKS_PER_SEC);
										cout<<"Tiempo de ejecución (en segundos): "<<tiempoTotal<<endl;
										cout<<endl;
										auxtiempo1 = tiempoTotal;
										for(int i =0;i<16;i++){
											for(int j=0;j<16;j++){
												if(Matriz[i][j]==9){
													cout<<char(158)<<" ";
												}else{
													cout<<char(254)<<" ";
												}
											}
											cout<<endl;
										}
										system("pause");
									}
									else{
										for(int i = f-1; i<f+2; i++) {
											for(int j=c-1; j<c+2; j++) {
												if(Matriz[i][j]==9) {
													contadordeminas++;
													vic++;
												}
											}
										}
										system("cls");
										MatrizAux[f][c] = contadordeminas;
										matrizMediana(MatrizAux);
										contadordeminas=0;
										if(vic == 216){
											cout<<endl;
											cout<<"  FELICIDADES, SUPERASTE EL NIVEL INTERMEDIO!"<<endl;
										}
									}
								}else{
									Beep(1500,1000);
									cout<<endl;
									cout<<"  Esta casilla fue marcada o ya descubierta"<<endl;
									cout<<endl;
									system("pause");
									system("cls");
									matrizMediana(MatrizAux);
								}
							}
						}else{
							Beep(1500,1000);
							cout<<endl;
							cout<<"  Porfavor ingrese una posicioón válida"<<endl;
							cout<<endl;
							system("pause");
							system("cls");
							matrizMediana(MatrizAux);
							
						}
						
					} while(band==false && opc!='S');
					band=false;
				}
				
				if(lvl == 2){
					tiempoInicial=clock();
					vic=0;
					do{
						cout<<endl;
						cout<<" Fila: ";
						cin>>f;
						cout<<endl;
						cout<<" Columna: ";
						cin>>c;
						cout<<endl;
						cout<<" Accion: ";
						cin>>opc;
						if(f<16 && c<32){
							switch(opc){
							case 'M':
								if(MatrizAux[f][c] == nm ){
									MatrizAux[f][c] = aux;
									cout<<"La opcion fue marcada correctamente"<<endl;
									Beep(5000,50);
									system("pause");
									
								}
								else{
									MatrizAux[f][c] = nm;
									cout<<"La opcion fue desmarcada correctamente"<<endl;
									Beep(5000,50);
									system("pause");
								}
								
								system("cls");
								matrizGrande(MatrizAux);
								break;
							case 'D':
								
								if(MatrizAux[f][c] == nm){
									for(int i=0;i<16;i++){
										for(int j=0;j<32;j++){
											if(Matriz[f][c]== 9){
												band=true;
											}
											else{
												band=false;
											}
										}
									}
									if(band == true){
										system("cls");
										Beep(5000,50);
										cara();
										tiempoFinal=clock();
										tiempoTotal=double((tiempoFinal-tiempoInicial)/CLOCKS_PER_SEC);
										cout<<"Tiempo de ejecución (en segundos): "<<tiempoTotal<<endl;
										cout<<endl;
										auxtiempo2 = tiempoTotal;
										for(int i =0;i<16;i++){
											for(int j=0;j<32;j++){
												if(Matriz[i][j]==9){
													cout<<char(158)<<" ";
												}else{
													cout<<char(254)<<" ";
												}
											}
											cout<<endl;
										}
										system("pause");
									}
									else{
										for(int i = f-1; i<f+2; i++) {
											for(int j=c-1; j<c+2; j++) {
												if(Matriz[i][j]==9) {
													contadordeminas++;
													vic++;
												}
											}
										}
										system("cls");
										MatrizAux[f][c] = contadordeminas;
										matrizGrande(MatrizAux);
										contadordeminas=0;
										if(vic == 413){
											cout<<endl;
											cout<<"  FELICIDADES, SUPERASTE EL NIVEL DIFICIL!"<<endl;
										}
									}
								}else{
									Beep(1500,1000);
									cout<<endl;
									cout<<"  Esta casilla fue marcada o ya descubierta"<<endl;
									cout<<endl;
									system("pause");
									system("cls");
									matrizGrande(MatrizAux);
								}
							}
						}else{
							Beep(1500,1000);
							cout<<endl;
							cout<<"  Porfavor ingrese una posicioón válida"<<endl;
							cout<<endl;
							system("pause");
							system("cls");
							matrizGrande(MatrizAux);
							
						}
						
					} while(band==false && opc!='S');
					band=false;
				}
				
			}
				
void instrucciones(){
					
					cout<<endl;
					cout<< "  INSTRUCCIONES PARA UN JUEGO DIVERTIDO!!!"<<endl;
					cout<<endl;
					cout<< " 1 - Elija dificultad del juego (opcion b), sino este se iniciara en Tablero Facil"<<endl;
					cout<<endl;
					cout<< " 2 - Comieza a jugar (opcion c)"<<endl;
					cout<<endl;
					cout<< " 3 - Indique primero la acción (M(marcar/desmarcar)- D(descubrir) - S(salir)) y el numero de fila, por segundo el numero de columna"<<endl;
					cout<<endl;
					cout<< " 4 - Si la celda esta Marcada y oprimes M se desmarcara, y viceversa"<<endl;
					cout<<endl;
					cout<< " 5 - No olvides que la matriz empieza en fila 0 y columna 0"<<endl;
					cout<<endl;
					cout<< " 6 - DIVERTITE!!!"<<endl;
					cout<<endl;
					system("pause");
					
				}
					
void color(int X){
						
						SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X);
					}
void cara(){
							cout<<" ..  ..  ..  ...  ..  .&  ..   ..  ..  . "<<endl;
							cout<<".  ..  ..  ..   .. &*&  &.  ...  ..  ..  "<<endl;
							cout<<".  ..  ..& ..   .&*&..  &*& ...  ..  ..  "<<endl;
							cout<<".  .. ......& &..&  .&%%%%%%&&.  ..  .. "<<endl;
							cout<<".  .....///*(&  .. &&&%%%%%%%&&& ..  .. "<<endl;
							cout<<".  .. &......   @&%%   %%%%%%%%%%&&  ..  "<<endl;
							cout<<".  ..  ..&..&  &%%  %%%%%%%%%%%%%%%& ..  "<<endl;
							cout<<" ..  ..  ..  .&%% %%%%%%%%%%%%%%%%%%&  . "<<endl;
							cout<<" ..  ..  ..  .&%%%%%%%%%%%%%%%%%%%%%&  . "<<endl;
							cout<<" ..  ..  ..  .&&%%%%%%%%%%%%%%%%%%%&&  . "<<endl;
							cout<<" ..  ..  ..  ..&&%%%%%%%%%%%%%%%%%&&.  . "<<endl;
							cout<<" ..  ..  ..  ... &&%%%%%%%%%%%%%&& ..  . "<<endl;
							cout<<" ..  ..  ..  ...  . .&&&&&&&&&&&..  ..  . "<<endl;
							
							
			}
void matrizGrande(int MatrizAux[J][J]){
								int aux=20;
								for(int i =0;i<16;i++){
									for(int j=0;j<32;j++){
										if(MatrizAux[i][j]!= 10 && MatrizAux[i][j]!=aux){
											cout<<MatrizAux[i][j]<<" ";
										}
										else{
											if(MatrizAux[i][j] == aux){
												color(22);
												cout<<char(244)<<" ";
												color(23);
											}else
												cout<<char(254)<<" ";
										}
										
									}
									cout<<endl;
								}
							}
void matrizMediana(int MatrizAux[J][J]){
									int aux=20;
									for(int i =0;i<16;i++){
										for(int j=0;j<16;j++){
											if(MatrizAux[i][j]!= 10 && MatrizAux[i][j]!=aux){
												cout<<MatrizAux[i][j]<<" ";
											}
											else{
												if(MatrizAux[i][j] == aux){
													color(22);
													cout<<char(244)<<" ";
													color(23);
												}else
													cout<<char(254)<<" ";
											}
											
										}
										cout<<endl;
									}
								}
void matrizChica(int MatrizAux[J][J]){
										int aux=20;
										for(int i =0;i<8;i++){
											for(int j=0;j<8;j++){
												if(MatrizAux[i][j]!= 10 && MatrizAux[i][j]!=aux){
													cout<<MatrizAux[i][j]<<" ";
												}
												else{
													if(MatrizAux[i][j] == aux){
														color(22);
														cout<<char(244)<<" ";
														color(23);
													}else
														cout<<char(254)<<" ";
												}
												
											}
											cout<<endl;
										}
									}
										
										
int MenuP(const char* opciones[], int n){
											int opcionSellecionada = 1;
											int tecla;
											bool repite = true;
											do{
												Beep(1500,100);
												system("cls");
												gotoxy(40,10+opcionSellecionada);
												cout<<"~";
												
												for(int i =0;i<n;i++){
													gotoxy(45,11+i);
													cout<<opciones[i];
												}
												
												do{
													tecla = getch();
												} while(tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla!= ENTER);
												
												
												switch(tecla){
												case TECLA_ARRIBA:
													opcionSellecionada--;
													if(opcionSellecionada < 1){
														opcionSellecionada = n;
													}
													break;
												case TECLA_ABAJO:
													opcionSellecionada++;
													if(opcionSellecionada > n){
														opcionSellecionada = 1;
													}
													break;
												case ENTER:
													repite = false;
													break;
												}
												
											} while(repite);
											
											
											return opcionSellecionada;
										}
void gotoxy(int x,int y){  
												HANDLE hcon;  
												hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
												COORD dwPos;  
												dwPos.X = x;  
												dwPos.Y= y;  
												SetConsoleCursorPosition(hcon,dwPos);  
											} 
void menupuntaje(){
	int opss;
	bool salir = true;
	const char *opciones[] = {"NIVEL FACIL","NIVEL INTERNEMIO","NIVEL DIFICIL","SALIR"};
	int n  = 4;
	do{
		opss = MenuP(opciones,n);
		switch(opss){
		case 1:
			system("cls");
			Puntaje(auxtiempo);
			break;
		case 2:
			system("cls");
			Puntaje1(auxtiempo1);
			break;
		case 3:
			system("cls");
			Puntaje2(auxtiempo2);
			break;
		case 4:
			system("cls");
			salir = false;
			break;
		}
		
	}while(salir);
}
