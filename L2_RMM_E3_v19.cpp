/*   ----------------------------------------------------------------
   |   Nombre:   Univ. Ruelas Machicado Mijahel Alexander            |
   |   Materia:  Laboratorio de programacion ( ETN307 )              |
    -----------------------------------------------------------------
      Crear un programa capapaz dividir polinomios con el metodo Horner
*/
#include<iostream>
#include<cmath>
#include<conio.h>
using namespace std;
// Declaraciones adelantadas de las funciones
void Presentacion();
void Datos_grados(int &grado_Divsor, int &grado_divndo);
void Datos_coef(float d[], float q[], int grado_Divsor, int grado_divndo);
void Menu_inical();
int Analiza_menu_1();
float Sumatoria(float M_principal[][100], float V_suma[], int grado_Divsor, float var_sum, float var_div, int cant_op);
float Dividir(float var_sum, float var_aux);
void Multiplicacion(float M_principal[][100], float V_cociente[], float V_Divisor[], float var_div, int grado_Divsor, int cant_op);
void Residuo(float V_residuo[], float V_suma[], float M_principal[][100], int grado_Divsor, int grado_divndo, int cant_op);
void Matrices_y_Vectores(float M_principal[][100], float V_Divisor[], float V_cociente[], float V_residuo[], float d[], float q[], int grado_Divsor, int grado_divndo);
void Matriz_principal(float M_principal[][100], float d[], int grado_Divsor);
void Vector_divisor(float V_Divisor[], float q[], int grado_Divsor, int grado_divndo);
void Vector_cociente(float V_cociente[], int grado_Divsor);
void Vector_residuo(float V_residuo[], int grado_Divsor);
void Vector_suma(float V_suma[], int grado_Divsor);
void Mostrar_parte_superior(int cant_op, float var_sum);
void Mostrar_parte_derecha(int filas, float columnas, float var_aux, int grado_Divsor, int grado_divndo, float V_Divisor[]);
void Mostrar_parte_central_linea_superior(int filas, int columnas, int grado_divndo, int grado_Divsor, float M_principal[][100]);
void Mostrar_lina_inferior_cociente(float filas, float columnas, int cant_op, int grado_divndo, int grado_Divsor, float V_cociente[]);
void Mostrar_lina_inferior_residuo(float filas, float columnas, int grado_divndo, int grado_Divsor, float V_cociente[], float V_residuo[]);
void Mostrar_operaciones_cociente(float M_principal[][100], float V_Divisor[], float V_cociente[], int grado_divndo, int grado_Divsor, float var_aux, float var_sum, int cant_op);
void Mostrar_operaciones_residuo(float M_principal[][100], float V_Divisor[], float V_cociente[], float V_residuo[], int grado_divndo, int grado_Divsor, float var_aux, int cant_op);
void Mostrar_polinomios(float d[], float q[], int grado_Divsor, int grado_divndo);
void Mostrar_resultados(float V_cociente[], float V_residuo[], int grado_Divsor, int grado_divndo);

int main() {
	int op_m_1, n, grado_Divsor = 0, grado_divndo, cant_op = 0;
	float d[100],q[100];
	float M_principal[100][100], V_cociente[100], V_Divisor[100], V_residuo[100], V_suma[100];
	float var_aux, var_div, var_sum;
	//Presentacion();
	do {
		do {
			Menu_inical();// mostrar el menu inicial
			// Funcion Anliza_menu_1 evitara que se digiten letras o valores no aceptados
			op_m_1 = Analiza_menu_1();
		} while (op_m_1==0);
		if (op_m_1==1) {
			Datos_grados(grado_Divsor,grado_divndo);
			Datos_coef(d,q,grado_Divsor,grado_divndo);
			var_aux = q[0];
			var_sum = 0;
			var_div = 1;
			// Copiando datos a las matrices y vectores
			Matrices_y_Vectores(M_principal,V_Divisor,V_cociente,V_residuo,d,q,grado_Divsor,grado_divndo);
			for (cant_op=0;cant_op<=grado_Divsor;cant_op++) {
				if (cant_op==0) {
					Vector_suma(V_suma,grado_Divsor);
					// copia los valores al vector para luego sumar
					var_sum = Sumatoria(M_principal,V_suma,grado_Divsor,var_sum,var_div,cant_op);
					var_div = Dividir(var_sum,var_aux);
					cout << endl;
				} else {
					if (cant_op<=grado_Divsor-grado_divndo+1) {
						Multiplicacion(M_principal,V_cociente,V_Divisor,var_div,grado_Divsor,cant_op);
						Mostrar_operaciones_cociente(M_principal,V_Divisor,V_cociente,grado_divndo,grado_Divsor,var_aux,var_sum,cant_op);
						// copia los valores al vector para luego sumar
						var_sum = Sumatoria(M_principal,V_suma,grado_Divsor,var_sum,var_div,cant_op);
						var_div = Dividir(var_sum,var_aux);
						if (cant_op==grado_Divsor-grado_divndo+1) {
							Residuo(V_residuo,V_suma,M_principal,grado_Divsor,grado_divndo,cant_op);
						}
					} else {
						// copia los valores al vector para luego sumar
						var_sum = Sumatoria(M_principal,V_suma,grado_Divsor,var_sum,var_div,cant_op);
						Residuo(V_residuo,V_suma,M_principal,grado_Divsor,grado_divndo,cant_op);
						// es de ceros
						Vector_suma(V_suma,grado_Divsor);
						Mostrar_operaciones_residuo(M_principal,V_Divisor,V_cociente,V_residuo,grado_divndo,grado_Divsor,var_aux,cant_op);
					}
					Vector_divisor(V_Divisor,q,grado_Divsor,grado_divndo);
				}
			}
			Mostrar_polinomios(d,q,grado_Divsor,grado_divndo);
			Mostrar_resultados(V_cociente,V_residuo,grado_Divsor,grado_divndo);
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
    cout << "\n\t  Elaborar un algoritmo para dividir " <<endl;
	cout << "\t  polinomios con elmetodo Horner " <<endl;
	cout << "\n\t ___________________________________" <<endl;
	cout << "\n\n   ";
    system("pause");
    system("cls");
}
// ********************************************
// *****     Funciones de Presentacion    *****
// ********************************************
// o----------------------------------------o
// **************************************
// *****     Funciones tipo menu    *****
// **************************************
void Menu_inical() {
	cout << "\n   * Calculadora Metodo de Horner *" << endl;
	cout << "  * para la division de polinomios *" << endl;
	cout << "    ______________________________" << endl;
	cout << "\n            Menu" << endl;
	cout << "\n     1. Ingresar datos." << endl;
	cout << "     2. Salir." << endl;
	cout << "\n      Digite su opcion. -> ";
}

int Analiza_menu_1() {
	char opcion_1_char[10];
	int opcion_1_n = 10;
	cin >> opcion_1_char[0];
	switch (opcion_1_char[0]) {
	case '1':	opcion_1_n = 1;	break;
	case '2':	opcion_1_n = 2;
		cout << "\n   * Saliendo del programa *" << endl;
		break;
	default:	opcion_1_n = 0;
		cout << "\n   Opcion invalida / Intentelo nuevamente." << endl;
	}
	cout << "\n Presione cualquier tecla para continuar" ;
	getch();
	system("cls");
	return opcion_1_n;
}

// ********************************************
// ******     Fin Funciones tipo dato     *****
// ********************************************
// o------------------------------------------o
// *********************************************
// *****     Funciones tipo pedir datos    *****
// *********************************************
void Datos_grados(int &grado_Divsor, int &grado_divndo) {
	int x;
	grado_Divsor = 0;
	grado_divndo = 0;
	do {
		cout << "\n\tIngrese el grado del :" << endl;
		cout << "\n\t* Dividendo -> ";
		cin >> grado_Divsor;
		cout << "\n\t* Divisor -> ";
		cin >> grado_divndo;
		if (grado_Divsor>grado_divndo) {
			x = 1;
		} else {
			x = 0;
			cout << "  Valores invalidos/Intentelo nuevamente." << endl;
			cout << "\n Presione cualquier tecla para continuar.";
			getch();
			system("cls");
			cout << "  * El grado del dividendo debe" << endl;
			cout << "    ser mayor al del divisor. *" << endl;
		}
	} while (x==0);
	cout << "\n Presione cualquier tecla para continuar." ;
	getch();
	system("cls");
}

void Datos_coef(float d[], float q[], int grado_Divsor, int grado_divndo) {
	int i;
	cout << "\n\tPara el dividendo ingrese el coeficiente :" << endl;
	for (i=0;i<=grado_Divsor;i++) {
		cout << "\n\t\tx^" << grado_Divsor-i << " -> ";
		cin >> d[i];
	}
	cout << "\n Presione cualquier tecla para continuar.";
	getch();
	system("cls");
	cout << "\n\tPara el divisor ingrese el coeficiente :" << endl;
	for (i=0;i<=grado_divndo;i++) {
		cout << "\n\t\tx^" << grado_divndo-i << " -> ";
		cin >> q[i];
	}
	cout << "\n Presione cualquier tecla para continuar." ;
	getch();
	system("cls");
}

void Mostrar_polinomios(float d[], float q[], int grado_Divsor, int grado_divndo) {
	int i;
	cout << "\n     Sea el polinomio:" <<endl;
	cout << "\n\t* Divisor = ";
	for (i=0;i<=grado_Divsor;i++) {
		if(i!=0){	cout << " + ";	}
		cout << "(" <<d[i]<<")";
		if(grado_Divsor-i>1){
			cout << "*x^" << grado_Divsor-i;
		}else{
			if(grado_Divsor-i!=0){	cout << "*x";	}
		}	
	}
	cout << "\n\n\t* Dividendo = ";
	for (i=0;i<=grado_divndo;i++) {
		if(i!=0){	cout << " + ";	}
		cout << "(" <<q[i]<<")";
		if(grado_divndo-i>1){
			cout << "*x^" << grado_divndo-i;
		}else{
			if(grado_divndo-i!=0){	cout << "*x";	}
		}		
	}
}
// **********************************
// *****     Fin pedir datos    *****
// **********************************
// o-------------------------------o
// ********************************
// *****     Llenando datos   *****
// ********************************
void Matrices_y_Vectores(float M_principal[][100], float V_Divisor[], float V_cociente[], float V_residuo[], float d[], float q[], int grado_Divsor, int grado_divndo) {
	Matriz_principal(M_principal,d,grado_Divsor);
	Vector_divisor(V_Divisor,q,grado_Divsor,grado_divndo);
	Vector_cociente(V_cociente,grado_Divsor);
	Vector_residuo(V_residuo,grado_Divsor);
}

void Matriz_principal(float M_principal[][100], float d[], int grado_Divsor) {
	for (int i=0;i<=grado_Divsor;i++) {
		for (int j=0;j<=grado_Divsor;j++) {
			if (i==0) {
				M_principal[i][j] = d[j];
			} else {	M_principal[i][j] = 0;	}
		}
	}
}

// para el divisor 
void Vector_divisor(float V_Divisor[], float q[], int grado_Divsor, int grado_divndo) {
	for (int i=0;i<=grado_Divsor;i++) {
		if (i<grado_divndo) {
			if(q[i+1]==0){
				V_Divisor[i] = q[i+1];
			}else{	V_Divisor[i] = -q[i+1];		}
		} else {	V_Divisor[i] = 0;	}
	}
}

// cociente
void Vector_cociente(float V_cociente[], int grado_Divsor) {
	for (int i=0;i<=grado_Divsor;i++) {
		V_cociente[i] = 0;
	}
}

// Residuo
void Vector_residuo(float V_residuo[], int grado_Divsor) {
	for (int i=0;i<=grado_Divsor;i++) {
		V_residuo[i] = 0;
	}
}

// vector suma lleno de ceros
void Vector_suma(float V_suma[], int grado_Divsor) {
	for (int i=0;i<=grado_Divsor;i++) {
		V_suma[i] = 0;
	}
}

// ************************************
// *****     Fin llenando datos   *****
// ************************************
// o------------------------------------o
// ****************************************
// ****     Funciones matematicas    ******
// ****************************************
float Sumatoria(float M_principal[][100], float V_suma[], int grado_Divsor, float var_sum, float var_div, int cant_op) {
	int i;
	float s = 0;
	var_sum = 0;
	var_div = 1;
	for (i=0;i<=grado_Divsor;i++) {
		V_suma[i] = M_principal[i][cant_op];
		s = s+V_suma[i];
	}
	return s;
}

float Dividir(float var_sum, float var_aux) {
	float x = 1;
	x = var_sum/var_aux;
	return x;
}

void Multiplicacion(float M_principal[][100], float V_cociente[], float V_Divisor[], float var_div, int grado_Divsor, int cant_op) {
	int columnas, filas;
	for (filas=1;filas<=1;filas++) {
		for (columnas=1;columnas<=grado_Divsor;columnas++) {
			// para llenar el vector cociente
			V_cociente[cant_op-1] = var_div;
			M_principal[filas+cant_op-1][columnas+filas-2+cant_op] = var_div*V_Divisor[columnas-1];
		}
	}
}

void Residuo(float V_residuo[], float V_suma[], float M_principal[][100], int grado_Divsor, int grado_divndo, int cant_op) {
	int i;
	float s = 0;
	for (i=0;i<=grado_Divsor;i++) {
		V_suma[i] = M_principal[i][cant_op];
		s = s+V_suma[i];
		V_residuo[cant_op-(grado_Divsor-grado_divndo+1)] = s;
	}
}
// ********************************************
// *****     Fin Funciones matematicas    *****
// ********************************************
// o--------------------------------------------o
// ************************************************
// *****     Funciones mostrar operaciones    *****
// ************************************************
void Mostrar_parte_superior(int cant_op, float var_sum) {
	int k;
	cout << "\t(/)";
	for (k=0;k<=cant_op-1;k++) {	cout << " <-";}
	cout << "[" << var_sum << "]" << endl;
	cout << "\t v ";
	for (k=0;k<=cant_op-1;k++) {	cout << "   ";	}
	cout << "^^^" << endl;
}
//parte izquierda
void Mostrar_parte_derecha(int filas, float columnas, float var_aux, int grado_Divsor, int grado_divndo, float V_Divisor[]) {
	if (filas==0 && columnas==0) {
		cout << "\t " << var_aux << " | ";
	} else {
		if (filas>0 && filas<=grado_Divsor-grado_divndo+1 && columnas==0) {
			if (V_Divisor[filas-1]<0) {
				cout << "\t" << V_Divisor[filas-1];
			} else {	cout << "\t " << V_Divisor[filas-1];	}
			if (abs(V_Divisor[filas-1])>9){
				cout << "| ";
			}else{	cout << " | ";	}	
		}
	}
}

void Mostrar_parte_central_linea_superior(int filas, int columnas, int grado_divndo, int grado_Divsor, float M_principal[][100]) {
	// muestra toda la parte central
	if (filas<=grado_Divsor-grado_divndo+1) {
		if (M_principal[filas][columnas]<0) {//para valores negativos
			if(abs(M_principal[filas][columnas-1])>9){
				cout << M_principal[filas][columnas];
			}else{	cout << " " << M_principal[filas][columnas];	}
		}else {
			if(M_principal[filas][columnas]==0){
				if(abs(M_principal[filas][columnas-1])>9){
				cout << " " << abs(M_principal[filas][columnas]);
			}else{	cout << "  " << abs(M_principal[filas][columnas]);	}	
			}else{	
			if(abs(M_principal[filas][columnas-1])>9){
				cout << " " << M_principal[filas][columnas];
			}else{	cout << "  " << M_principal[filas][columnas];	}		
			}		
		}
	}
	// line superior
	if (filas==0 && columnas==grado_Divsor) {
		cout << "\n\t";
		for (int k=0;k<=grado_Divsor;k++) {	cout << "----";	}
	}
}

void Mostrar_lina_inferior_cociente(float filas, float columnas, int cant_op, int grado_divndo, int grado_Divsor, float V_cociente[]) {
	int k;
	// linea inferior y Vector cociente
	if (filas==grado_Divsor-grado_divndo+1 && columnas==grado_Divsor) {
		cout << "\n\t";
		for (k=0;k<=grado_Divsor;k++) {	cout << "----";	}
		cout << "\n\t ->  ";
		for (k=0;k<=cant_op-1;k++) {
			if (V_cociente[k]<0) {
				cout << " " << V_cociente[k];
			} else {	cout << "  " << V_cociente[k];	}
		}
	}
}

void Mostrar_lina_inferior_residuo(float filas, float columnas, int grado_divndo, int grado_Divsor, float V_cociente[], float V_residuo[]) {
	int k;
	// linea inferior
	if (filas==grado_Divsor-grado_divndo+1 && columnas==grado_Divsor) {
		cout << "\n\t";
		for (k=0;k<=grado_Divsor;k++) {
			cout << "----";
		}
		cout << "\n\t ->  ";
		for (k=0;k<=grado_Divsor-grado_divndo;k++) {
			if (V_cociente[k]<0) {
				cout << " " << V_cociente[k];
			} else {	cout << "  " << V_cociente[k];	}	
		}
		// Residuo
		for (k=0;k<=grado_Divsor-grado_divndo;k++) {
			if (V_residuo[k]!=0) {
				if (V_residuo[k]<0) {
					if(abs(V_residuo[k])>9){
						cout << V_residuo[k];
					}else{	cout << " " << V_residuo[k];	}	
				}else {		cout << "  " << V_residuo[k];	}	
			}
		}
	}
}

void Mostrar_operaciones_cociente(float M_principal[][100], float V_Divisor[], float V_cociente[], int grado_divndo, int grado_Divsor, float var_aux, float var_sum, int cant_op) {
	int columnas, filas;
	// parte superior de las operaciones
	Mostrar_parte_superior(cant_op,var_sum);
	for (filas=0;filas<=grado_Divsor;filas++) {
		for (columnas=0;columnas<=grado_Divsor;columnas++) {
			Mostrar_parte_derecha(filas,columnas,var_aux,grado_Divsor,grado_divndo,V_Divisor);
			Mostrar_parte_central_linea_superior(filas,columnas,grado_divndo,grado_Divsor,M_principal);
			Mostrar_lina_inferior_cociente(filas,columnas,cant_op,grado_divndo,grado_Divsor,V_cociente);
		}
		cout << endl;
	}
}

void Mostrar_operaciones_residuo(float M_principal[][100], float V_Divisor[], float V_cociente[], float V_residuo[], int grado_divndo, int grado_Divsor, float var_aux, int cant_op) {
	int columnas, filas;
	if (cant_op==grado_Divsor) {
		for (filas=0;filas<=grado_Divsor;filas++) {
			for (columnas=0;columnas<=grado_Divsor;columnas++) {
				Mostrar_parte_derecha(filas,columnas,var_aux,grado_Divsor,grado_divndo,V_Divisor);
				Mostrar_parte_central_linea_superior(filas,columnas,grado_divndo,grado_Divsor,M_principal);
				Mostrar_lina_inferior_residuo(filas,columnas,grado_divndo,grado_Divsor,V_cociente,V_residuo);
			}
			cout << endl;
		}
	}
}
// ******************************************
// *****     Fin mostrar operaciones    *****
// ******************************************
// o-----------------------------------------o
// ********************************************
// *****     Funcion mostrar resultado    *****
// ********************************************
void Mostrar_resultados(float V_cociente[], float V_residuo[], int grado_Divsor, int grado_divndo) {
	int n;
	//*******************
	cout << "\n\n\n     Sus resultados son :" << endl;
//**************
	cout << "\n\t* Cociente = ";
	for (n=0;n<=grado_Divsor-grado_divndo;n++) {
		if (n!=0) {	cout << " + ";	}
		cout << "(" << V_cociente[n] << ")";
		if ((grado_Divsor-grado_divndo)-n!=0) {
			if ((grado_Divsor-grado_divndo)-n==1) {
				cout << "*x";
			}else{	cout << "*x^" << (grado_Divsor-grado_divndo)-n;		}	
		}
	}
	cout << endl;
	cout << "\n\t* Residuo  = ";
	for (n=0;n<=grado_divndo-1;n++) {
		if (n!=0) {	cout << " + ";	}
		cout << "(" << V_residuo[n] << ")";
		if (grado_divndo-n-1!=0) {
			if (grado_divndo-n-1==1) {
				cout << "*x";
			}else{	cout << "*x^" << grado_divndo-n-1;	}	
		}
	}
	cout << "\n\n Presione cualquier tecla para continuar" <<endl;
	getch();
	system("cls");
}
// ****************************************
// *****     fin mostrar resultado    *****
// ****************************************
