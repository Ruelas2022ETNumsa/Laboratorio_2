/*   ----------------------------------------------------------------
   |   Nombre:   Univ. Ruelas Machicado Mijahel Alexander            |
   |   Materia:  Laboratotio de programacion ( ETN307 )              |
    -----------------------------------------------------------------
      Crear un programa capapaz de calcular la Determinante de una
	 Matriz de Vandermonde
*/
#include<iostream>
#include<cmath>
#include<conio.h>
#include<cstdlib>
using namespace std;
// Declaraciones adelantadas de las funciones
void Presentacion();
void Menu_inical();
int Analiza_menu_1();
float Tamanio_matriz();
void Menu_2();
int Analiza_menu_2();
void Espacios_matriz(float Matriz[][100],float Fila_1[], int size_m, int i, int j);
void Espacios_determinante(float Mat_op[][100], float Fila_1, int size_m, int i, int j);
void Generando_matriz(float size_m, float Fila_1[]);
void Determinante(float size_m, float Fila_1[], float Mat_aux[][100]);
float Op_aux(float size_m, float var_aux, float Mat_aux[][100], int i, int filas, int columnas);
float Op_determinante(float size_m, float Mat_aux[][100]);

int main() {
	float Fila_1[100];
	int i,op_m_1,op_m_2,size_m = 0;
	//Presentacion();
	do {
		do {
			Menu_inical();// mostrar el menu inicial
			// Funcion Anliza_menu_1 evitara que se digiten letras o valores no aceptados
			op_m_1 = Analiza_menu_1();
		} while (op_m_1==0);
			if (op_m_1==1) {
				size_m = Tamanio_matriz();
				cout << "\n Presione cualquier tecla para continuar.";
				getch();
				system("cls");
				do {
					Menu_2();
					op_m_2 = Analiza_menu_2();
				} while (op_m_2==0);
				// generamos los elementos de la Matriz
				if (op_m_2<3) {
					for (i=0;i<=size_m-1;i++) {
						if (op_m_2==1) {
							Fila_1[i] = -25+(rand()%25);
						} else {
							if(i==0){cout << "\n   Ingrese :\n" << endl;
							}
							cout << "\tM [" << i << "][1] -> ";
							cin >> Fila_1[i];
						}
					}
					if (op_m_2==2) {
						cout << "\n Presione cualquier tecla para continuar.";
						getch();
						system("cls");
					}
					cout << "\n   La Matriz transpuesta de Vandermonde sera :\n" << endl;
					Generando_matriz(size_m,Fila_1);
					cout << "\n Presione cualquier tecla para continuar.";
					getch();
					system("cls");
				}
			}	
	} while (op_m_1!=2);
	return 0;
}
// o----------o
// ********************************************
// *****     Funciones de Presentacion    *****
// ********************************************
void Presentacion(){
	cout << "\n\t | UNIVERSIDAD MAYOR DE SAN ANDRES |" <<endl;
    cout << "\t | FACULTAD DE INGENIERIA          |" <<endl;
	cout << "\t | INGENIERIA ELECTRONICA          |" <<endl;
	cout << "\t ***********************************" <<endl;
	cout << "\t  Materia :  \n\t    Lab. de programacion (ETN 307) \n " <<endl;
    cout << "\t  Estudiante : \n\t\t  Univ. Mijahel Alexander " <<endl;
	cout << "\t\t\tRuelas Machicado " <<endl;
	cout << "\n\t ___________________________________" <<endl;
    cout << "\n\t  Elaborar un algoritmo que calcule " <<endl;
	cout << "\t  la determinante de una matriz de " <<endl;
	cout << "\t  Vandermonde." <<endl;
	cout << "\n\t ___________________________________" <<endl;
	cout << "\n\n   ";
    system("pause");
    system("cls");
}
// ********************************************
// *****     Funciones de Presentacion    *****
// ********************************************
// o----------------------------------------------o
// ******************************************************
// *****     Funciones tipo mostrar en pantalla     *****
// ******************************************************
void Menu_inical() {
	cout << "\n * Calculadora Matrices de Vandermonde *" << endl;
	cout << "   ___________________________________" << endl;
	cout << "\n            Menu" << endl;
	cout << "\n     1. Ingresar datos de la Matriz." << endl;
	cout << "     2. Salir." << endl;
	cout << "\n      Digite su opcion. -> ";
}

int Analiza_menu_1() {
	char opcion_1_char[10];
	int opcion_1_n = 10;
	cin >> opcion_1_char[0];
	switch (opcion_1_char[0]) {
	case '1':	opcion_1_n = 1;		break;
	case '2':	opcion_1_n = 2;
		cout << "   * Saliendo del programa *" << endl;
		break;
	default:	opcion_1_n = 0;
		cout << "\n   Opcion invalida / Intentelo nuevamente." << endl;
	}
	cout << "\n Presione cualquier tecla para continuar.";
	getch();
	system("cls");
	return opcion_1_n;
}

float Tamanio_matriz() {
	float var_aux;
	do {
		cout << "\n * Ingrese la dimension ->  ";
		cin >> var_aux;
		if (var_aux<=1) {
			cout << "\n Valor invalido/Intentelo nuevamente." << endl;
			cout << "\n Presione cualquier tecla para continuar.";
			getch();
			system("cls");
			cout << "\n Debe ingresar un numero natural y mayor a 1." << endl;
		}
	} while (var_aux<=1);
	return var_aux;
}

void Menu_2() {
	cout << "\n * Para los elementos." << endl;
	cout << "\n             * Menu *" << endl;
	cout << "\n     1. Ingresar datos aleatorios." << endl;
	cout << "     2. Ingresar la 1ra fila." << endl;
	cout << "     3. Volver menu principal." << endl;
	cout << "\n      Digite su opcion. -> ";
}

int Analiza_menu_2() {
	int opcion_2_n = 10;
	char opcion_n_char[10];
	cin >> opcion_n_char[0];
	switch (opcion_n_char[0]) {
	case '1':	opcion_2_n = 1;	break;
	case '2':	opcion_2_n = 2;	break;
	case '3':	opcion_2_n = 3;	break;
	default:	opcion_2_n = 0;
		cout << "\n   Opcion invalida / Intentelo nuevamente." << endl;
	}
	cout << "\n Presione cualquier tecla para continuar.";
	getch();
	system("cls");
	return opcion_2_n;
}

void Espacios_matriz(float Matriz[][100],float Fila_1[], int size_m, int i, int j) {
	// agrega espacios si hay negativo
	if (i%2==0) {
		if (Fila_1[j]<0) {
			cout << " ";
		}
	}
	// agrega espacion si 
	if (abs(Matriz[size_m-1][j])>9) {
		if (abs(Matriz[i][j])<10) {
			cout << " ";
		}
		if (abs(Matriz[size_m-1][j])>99) {
			if (abs(Matriz[i][j])<100) {
				cout << " ";
			}
			if (abs(Matriz[size_m-1][j])>999) {
				if (abs(Matriz[i][j])<1000) {
					cout << " ";
				}
				if (abs(Matriz[size_m-1][j])>9999) {
					if (abs(Matriz[i][j])<10000) {
						cout << " ";
					}
					if (abs(Matriz[size_m-1][j])>99999) {
						if (abs(Matriz[i][j])<100000) {
							cout << " ";
						}
					}
				}
			}
		}
	}
}

// (Mat_op,Fila_1,Size_M,filas,columnas)
void Espacios_determinante(float Mat_op[][100],float Fila_1[], int size_m, int i, int j) {
	// i ->  filas ->  columnas
	// agrega espacios si hay negativo
	if (Mat_op[i][j]>=0) {
		cout << " ";
	}
	// agrega espacion si 
	if (abs(Mat_op[size_m-1][j])>9) {
		if (abs(Mat_op[i][j])<10) {
			cout << " ";
		}
		if (abs(Mat_op[size_m-1][j])>99) {
			if (abs(Mat_op[i][j])<100) {
				cout << " ";
			}
			if (abs(Mat_op[size_m-1][j])>999) {
				if (abs(Mat_op[i][j])<1000) {
					cout << " ";
				}
				if (abs(Mat_op[size_m-1][j])>9999) {
					if (abs(Mat_op[i][j])<10000) {
						cout << " ";
					}
					if (abs(Mat_op[size_m-1][j])>99999) {
						if (abs(Mat_op[i][j])<100000) {
							cout << " ";
						}
					}
				}
			}
		}
	}
}

// *****************************************************
// *****     Fin Funciones mostrar en pantalla     *****
// *****************************************************
// o----------------------------------------------o
// *****************************************
// *****     Funciones matematicas     *****
// *****************************************
void Generando_matriz(float size_m, float Fila_1[]) {
	int i, j;
	float Matriz[100][100], Mat_aux[100][100];
	// genaramos la Matriz
	for (i=0;i<=size_m-1;i++) {
		for (j=0;j<=size_m-1;j++) {
			Matriz[i][j] = pow((Fila_1[j]),i);
		}
	}
	// mostramos la Matriz en pantalla
	for (i=0;i<=size_m-1;i++) {
		cout << "\t[ ";
		for (j=0;j<=size_m-1;j++) {
			Espacios_matriz(Matriz,Fila_1,size_m,i,j);
			// nueva Matriz auxiliar
			Mat_aux[i][j] = Matriz[i][j];
			cout << Matriz[i][j] << "  ";
		}
		cout << "] " << endl;
	}
	cout << "  _______________________________________________" <<endl;
	cout << "\n El procedimiento para hallar la Determinante es :" << endl;
	Determinante(size_m,Fila_1,Mat_aux);
}

// Para la Determinante
void Determinante(float size_m, float Fila_1[], float Mat_aux[][100]) {
	int columnas, filas, i;
	float Mat_op[100][100], var_aux = 1;
	for (i=0;i<=size_m-2;i++) {
		// Escribir "[i=",i,"][v=",var_aux,"]"
		var_aux = Fila_1[i];
		cout << "\n * Operaciones :" << endl;
		for (filas=0;filas<=size_m-1;filas++) {
			if (filas<size_m-i-1) {
				cout << "   Fila[" << filas+i+1 << "] - (" << var_aux << ")*Fila[" << filas+i << "]+ ->  Fila[" << filas+i+1 << "]" << endl;
			}
			for (columnas=0;columnas<=size_m-1;columnas++) {
				Mat_op[filas][columnas] = Op_aux(size_m,var_aux,Mat_aux,i,filas,columnas);
			}
		}
		// copiando Matriz
		cout << "\n  En la Matriz :" << endl;
		for (filas=0;filas<=size_m-1;filas++) {
			cout << "\t\t| ";
			for (columnas=0;columnas<=size_m-1;columnas++) {
				Mat_aux[filas][columnas] = Mat_op[filas][columnas];
				Espacios_determinante(Mat_op,Fila_1,size_m,filas,columnas);
				cout << Mat_op[filas][columnas] << "  ";
			}
			cout << "|" << endl;
		}
	}
	// hallando la Determinante multiplicando su diagonal principal
	cout << "  _______________________________________________" <<endl;
	cout << "\n * Finalmente :" << endl;
	cout << "\n  Determinante = ";
	for (filas=0;filas<=size_m-1;filas++) {
		for (columnas=0;columnas<=size_m-1;columnas++) {
			if (filas==columnas) {
				cout << "(" << Mat_aux[filas][columnas] << ")";
			}
		}
	}
	cout << "\n\n  Determinante = " << Op_determinante(size_m,Mat_aux) << endl;
}

// elementos
float Op_aux(float size_m, float var_aux, float Mat_aux[][100], int i, int filas, int columnas) {
	float elemento;
	if ((filas>i && columnas>i-1)) {
		elemento = Mat_aux[filas][columnas]-var_aux*Mat_aux[filas-1][columnas];
	} else {
		elemento = Mat_aux[filas][columnas];
	}
	return elemento;
}

// operacion auxiliar Determinante
float Op_determinante(float size_m, float Mat_aux[][100]) {
	int i, j;
	float x = 1;
	for (i=0;i<=size_m-1;i++) {
		for (j=0;j<=size_m-1;j++) {
			if (i==j) {
				x = x*Mat_aux[i][j];
			}
		}
	}
	return x;
}

