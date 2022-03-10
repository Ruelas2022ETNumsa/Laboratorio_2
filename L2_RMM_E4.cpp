/*   ----------------------------------------------------------------
   |   Nombre:   Univ. Ruelas Machicado Mijahel Alexander            |
   |   Materia:  Laboratotio de programacion ( ETN307 )              |
    -----------------------------------------------------------------
      Crear un programa capapaz dividir polinomios con el metodo Horner
*/
#include<iostream>
#include<conio.h>
using namespace std;
// Declaraciones adelantadas de las funciones
void Presentacion();
void Menu_inical();
int Analiza_menu_1();
float Determinante(float s_i, float s_d, float i_i, float i_d);
void analisis_del_cero(float d, float d_x, float d_y);

int main() {
	int i, op_m_1;
	float d, d_x, d_y;
	char n_v_1[]={'a','b','c'};
	char n_v_2[]={'m','n','p'};
	float v_1[3], v_2[3];
	Presentacion();
	do {
		do {
			// mostrar el menu inicial
			Menu_inical();
			// Funcion Anliza_menu_1 evitara que se digiten letras o valores no aceptados
			op_m_1 = Analiza_menu_1();
		} while (op_m_1==0);
		if (op_m_1==1) {
			cout << "\n\t Sea el sistema de ecuaciones :" << endl;
			cout << "\n\n\t   {   (a)*x + (b)*y = c   . . .  (1)" << endl;
			cout << "\n\t   {   (m)*x + (n)*y = p   . . .  (2)" << endl;
			cout << "\n\n\t Ingrese los valores. " << endl;
			cout << "\n\n\t * Para la ec. (1)" << endl;
			for (i=0;i<=2;i++) {
				cout << "\n\t\t" << n_v_1[i] << " -> ";
				cin >> v_1[i];
			}
			cout << "\n\t * Para la ec. (2)" << endl;
			for (i=0;i<=2;i++) {
				cout << "\n\t\t" << n_v_2[i] << " -> ";
				cin >> v_2[i];
			}
			d = Determinante(v_1[0],v_1[1],v_2[0],v_2[1]);
			d_x = Determinante(v_1[2],v_1[1],v_2[2],v_2[1]);
			d_y = Determinante(v_1[0],v_1[2],v_2[0],v_2[2]);
			cout << "\n Presione cualquier tecla para continuar.";
			getch();
			system("cls");
			cout << "\n\t Sea el sistema de ecuaciones :" << endl;
			cout << "\n\n\t   {   ("<<v_1[0]<<")*x + ("<<v_1[1]<<")*y = ("<<v_1[2]<<")   . . .  (1)" << endl;
			cout << "\n\t   {   ("<<v_2[0]<<")*x + ("<<v_2[1]<<")*y = ("<<v_2[2]<<")   . . .  (2)\n" << endl;
			analisis_del_cero(d,d_x,d_y);
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
    cout << "\n\t  Elaborar un algoritmo para hallar " <<endl;
	cout << "\t  la solucion a un sistema de ec. " <<endl;
	cout << "\n\t ___________________________________" <<endl;
	cout << "\n\n   ";
    system("pause");
    system("cls");
}
// ********************************************
// *****     Funciones de Presentacion    *****
// ********************************************
// o----------------------------------------o
// ***************************************
// *****     Funciones tipo menu    *****
// **************************************
void Menu_inical() {
	cout << "\n\t * Calculadora Sistema de ecuaciones *" << endl;
	cout << "\t   _________________________________" << endl;
	cout << "\n\t            Menu" << endl;
	cout << "\n\t     1. Iniciar el programa." << endl;
	cout << "\t     2. Salir." << endl;
	cout << "\n\t      Digite su opcion. -> ";
}

int Analiza_menu_1() {
	char opcion_1_char[10];
	int opcion_1_n;
	opcion_1_n = 10;
	cin >> opcion_1_char[0];
	switch (opcion_1_char[0]) {
	case '1':	opcion_1_n = 1;	break;
	case '2':	opcion_1_n = 2;
		cout << "   * Saliendo del programa *" << endl;
		break;
	default:	opcion_1_n = 0;
		cout << "   Opcion invalida / Intentelo nuevamente." << endl;
	}
	cout << "\n Presione cualquier tecla para continuar.";
	getch();
	system("cls");
	return opcion_1_n;
}

// *************************************
// *****     Fin funciones menu    *****
// *************************************
// o------------------------------------o
// ****************************************
// *****     Analisis Determinante    *****
// ****************************************
float Determinante(float s_i, float s_d, float i_i, float i_d) {
	float d;
	d = s_i*i_d-s_d*i_i;
	return d;
}

void analisis_del_cero(float d, float d_x, float d_y) {
	if (d==0) {
		if ((d_x==0 && d_y==0)) {
			cout << "\n\t Infitas soluciones" << endl;
		} else {
			cout << "\n\t No tiene solucion." << endl;
		}
	} else {
		cout << "\n\t La soluciones al sistema es :" << endl;
		cout << "\n\n\t\t\t  x = " << d_x/d << endl;
		cout << "\n\t\t\t  y = " << d_y/d << endl;
	}
	cout << "\n Presione cualquier tecla para continuar.";
	getch();
	system("cls");
}
// ********************************************
// *****     fin Analisis Determinante    *****
// ********************************************
