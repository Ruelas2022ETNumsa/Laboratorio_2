/*   ----------------------------------------------------------------
   |   Nombre:   Univ. Ruelas Machicado Mijahel Alexander            |
   |   Materia:  Laboratotio de computaion ( ETN307 )                |
    -----------------------------------------------------------------
      Crear un programa capapaz de resolver problemas trigonometricos
     con 3 datos que el usuario ingrese. Luego calcular el Area,
	 Perimetro y las medianas de dicho triangulo.
*/
#include<iostream>
#include<cmath>
#include<conio.h>

using namespace std;
// Declaraciones adelantadas de las funciones
void Presentacion();
void menu_inical();
int analiza_menu_1();
void menu_resultados();
int analiza_menu_2();
void Mostrar_triangulo(char N_Lado[], char N_Angulo[], float Lado[], float Angulo[]);
void Tipo_triangulo(float Lado[], float Angulo[]);
void Pedir_3_lados(char N_Lado[], float Lado[], float var_aux);
void Pedir_3_angulos(char N_Angulo[], float Angulo[], float var_aux);
void Pedir_2_lados_1_angulo(char N_Lado[], float Lado[], char N_Angulo[], float Angulo[], float var_aux);
void Pedir_1_lado_2_angulos(char N_Lado[], float Lado[], char N_Angulo[], float Angulo[], float var_aux);
int No_cero(float var_aux);
int Comprobando_lado_C(float Lado[], float var_aux);
int Comprobando_angulos(char N_Angulo[], float Angulo[], float var_aux, int i);
int Comprobando_angulo_gamma(char N_Angulo[], float var_aux, int i);
void calc_3_angulos(float Angulo[], float Lado[]);
void calc_3_lados(float Lado[], float Angulo[]);
void calc_1_lado_2_angulos(float Lado[], float Angulo[]);
void calc_1_angulo_2_lados(float Angulo[], float Lado[]);
float calc_gamma(float alpha, float beta);
float calc_alpha_cosenos(float L_A, float L_B, float L_C);
float calc_beta_cosenos(float L_A, float L_B, float L_C);
float calc_gamma_cosenos(float L_A, float L_B, float L_C);
float calc_B_senos(float L_A, float alpha, float beta);
float calc_C_senos(float L_A, float alpha, float gamma);
float calc_C_cosenos(float L_A, float L_B, float gamma);
float Calculo_Area(float L_A, float L_B, float L_C);
float Calculo_Perimetro(float L_A, float L_B, float L_C);
float Calculo_Mediana_A(float L_A, float L_B, float L_C);
float Calculo_Mediana_B(float L_A, float L_B, float L_C);
float Calculo_Mediana_C(float L_A, float L_B, float L_C);

int main() {
	int op_m_1,op_m_2;
	char N_Angulo[] = {'a','b','g'}, N_Lado[] = {'A','B','C'};
	float Angulo[3], Lado[3], var_aux = 0;
	// inicia el programa
	Presentacion();
	do {
		do {
			menu_inical();// mostrar el menu inicial
			// Funcion Anliza_menu_1 evitara que se digiten letras o valores no aceptados
			op_m_1 = analiza_menu_1();
		} while (op_m_1==0);
		if (op_m_1!=5) {
			cout << "\n   Sea un triangulo de Lado A, B y C. cuyos" << endl;
			cout << "  angulos alpha,betha y gamma, son opuestos a" << endl;
			cout << "  sus respectivos Lados." << endl;
			cout << "\n * Ingrese :" << endl;
			switch (op_m_1) {
			case 1:
				Pedir_3_lados(N_Lado,Lado,var_aux);
				calc_3_angulos(Angulo,Lado);
				break;
			case 2:
				Pedir_3_angulos(N_Angulo,Angulo,var_aux);
				calc_3_lados(Lado,Angulo);
				break;
			case 3:
				Pedir_2_lados_1_angulo(N_Lado,Lado,N_Angulo,Angulo,var_aux);
				calc_1_lado_2_angulos(Lado,Angulo);
				break;
			case 4:
				Pedir_1_lado_2_angulos(N_Lado,Lado,N_Angulo,Angulo,var_aux);
				calc_1_angulo_2_lados(Angulo,Lado);
				break;
			}
			cout << "\n Presione cualquier tecla para continuar.";
			getch();
			system("cls");
			do {
				do {
					menu_resultados();
					op_m_2 = analiza_menu_2();
				} while (op_m_2==0);
				if (op_m_2!=4) {
					cout << "\n   Sea el triangulo.";
					Mostrar_triangulo(N_Lado,N_Angulo,Lado,Angulo);
					cout << " *----------------------------------*\n" << endl;
					switch (op_m_2) {
					case 1:
						// Calculo_Area(L_A,L_B,L_C)
						cout << "\t* Area = " << Calculo_Area(Lado[0],Lado[1],Lado[2]) << endl;
						break;
					case 2:
						// Calculo_perimetero( L_A,L_B,L_C )
						cout << "\t* Perimetro = " << Calculo_Perimetro(Lado[0],Lado[1],Lado[2]) << endl;
						break;
					case 3:
						cout << "   * Medianas :\n" << endl;
						// Mediana_A(L_A,L_B,L_C)
						cout << "\t  M_a= " << Calculo_Mediana_A(Lado[0],Lado[1],Lado[2]) << endl;
						cout << "\t  M_b= " << Calculo_Mediana_B(Lado[0],Lado[1],Lado[2]) << endl;
						cout << "\t  M_c= " << Calculo_Mediana_C(Lado[0],Lado[1],Lado[2]) << endl;
						break;
					}
					cout << "\n Presione cualquier tecla para continuar.";
					getch();
					system("cls");
				}
			} while (op_m_2!=4);
		}
	} while (op_m_1!=5);
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
    cout << "\n\t    Elaborar un algoritmo que calcule " <<endl;
	cout << "\t el area, perimetro y las medianas de" <<endl;
	cout << "\t un triangulo; ingresando 3 datos." <<endl;
	cout << "\n\t ___________________________________" <<endl;
	cout << "\n\n   ";
    system("pause");
    system("cls");
}
// ********************************************
// *****     Funciones de Presentacion    *****
// ********************************************
// o---------------------------------------*
// ***************************************
// *****     Funciones tipo menu     *****
// ***************************************
void menu_inical() {
	cout << "\n * Calculadora de problemas *" << endl;
	cout << "   *   Trigonometricos    *" << endl;
	cout << "   ________________________" << endl;
	cout << "\n            Menu" << endl;
	cout << "  Desea introducir los datos de:" << endl;
	cout << "\n     1. Los tres Lado." << endl;
	cout << "     2. Los tres Angulo." << endl;
	cout << "     3. Dos Lado y un angulo." << endl;
	cout << "     4. Dos Angulo y un lado." << endl;
	cout << "     5. Salir." << endl;
	cout << "\n   Digite su opcion. -> ";
}

int analiza_menu_1() {
	int opcion_1_n = 10;
	char op_1_char[10];
	cin >> op_1_char[0];
	switch (op_1_char[0]) {
	case '1':	opcion_1_n = 1;break;
	case '2':	opcion_1_n = 2;	break;
	case '3':	opcion_1_n = 3;	break;
	case '4':	opcion_1_n = 4;	break;
	case '5':	opcion_1_n = 5;
		cout << "\n   * Saliendo del programa *" << endl;
		break;
	default:
		opcion_1_n = 0;
		cout << "   Opcion invalida / Intentelo nuevamente." << endl;
	}
	cout << "\n Presione cualquier tecla para continuar.";
	getch();
	system("cls");
	return opcion_1_n;
}

void menu_resultados() {
	cout << "\n           * Menu *" << endl;
	cout << "     1. Area." << endl;
	cout << "     2. Perimetro." << endl;
	cout << "     3. Medianas." << endl;
	cout << "     4. Volver(Menu principal)." << endl;
	cout << "\n   Digite su opcion. -> ";
}

int analiza_menu_2() {
	int opcion_2_n = 10;
	char op_2_char[10];
	cin >> op_2_char[0];
	switch (op_2_char[0]) {
	case '1':	opcion_2_n = 1;	break;
	case '2':	opcion_2_n = 2;	break;
	case '3':	opcion_2_n = 3;	break;
	case '4':	opcion_2_n = 4;	break;
	default:	opcion_2_n = 0;
		cout << "\n   Opcion invalida / Intentelo nuevamente." << endl;
	}
	cout << "\n Presione cualquier tecla para continuar.";
	getch();
	system("cls");
	return opcion_2_n;
}

void Mostrar_triangulo(char N_Lado[], char N_Angulo[], float Lado[], float Angulo[]) {
	int i;
	float pi;
	Tipo_triangulo(Lado,Angulo);
	cout << endl;
	for (i=0;i<=2;i++) {
		cout << "\t* Lado " << N_Lado[i] << " = " << Lado[i]<<endl;
	}
	cout << endl;
	for (i=0;i<=2;i++) {
		cout << "\t* Angulo " << N_Angulo[i] << " = " << Angulo[i]*(180/M_PI)<<endl;
	}
	cout << endl;
}

void Tipo_triangulo(float Lado[], float Angulo[]) {
	float pi;
	if ( pow(Lado[0],2)==pow(Lado[1],2)+pow(Lado[2],2)||pow(Lado[1],2)==pow(Lado[0],2)+pow(Lado[2],2)||pow(Lado[2],2)==pow(Lado[0],2)+pow(Lado[1],2)) {
			cout << " ( Rectangulo )" << endl;
		}else{
		if ( Lado[0]==Lado[1] || Lado[0]==Lado[2] || Lado[1]==Lado[2] ) {
				if( Lado[0]!=Lado[2] || Lado[0]!=Lado[1] ){
				    cout << " ( Isosceles )" << endl;	
				}else{
					cout << " ( Equilatero )" << endl;
				}	
			}else{
				cout << " ( Escaleno )" << endl;
			}		
		}		
}
// **************************************
// *****     Fin Funciones menu     *****
// **************************************
// o--------------------------------------o
// *****************************************
// *****     Funciones pedir datos     *****
// *****************************************
// 3 Lado
// se debe agragar una tricotomia
void Pedir_3_lados(char N_Lado[], float Lado[], float var_aux) {
	int i;
	var_aux = 0;
	for (i=0;i<=1;i++) {
		do {
			cout << "\n  Lado " << N_Lado[i] << " -> ";
			cin >> var_aux;
			// retorna 0 o 1
		} while ((No_cero(var_aux)==0));
		Lado[i] = var_aux;
	}
	// Para ingresar un valor valido para el 3er lado  
	do {
		cout << "\n  Lado " << N_Lado[2] << " -> ";
		cin >> var_aux;
		// retorna 0 o 1
	} while ((Comprobando_lado_C(Lado,var_aux)==0));
	Lado[2] = var_aux;
}

// 3 Angulo
void Pedir_3_angulos(char N_Angulo[], float Angulo[], float var_aux) {
	int i;
	float pi;
	var_aux = 0;
	cout << "\n [ Ingresar en grados ]" << endl;
	for (i=0;i<=2;i++) {
		if (i<2) {
			do {
				cout << "\n  Angulo " << N_Angulo[i] << " -> ";
				cin >> var_aux;
				// retorna 0 o 1
			} while ((Comprobando_angulos(N_Angulo,Angulo,var_aux,i)==0));
			Angulo[i] = var_aux*(M_PI/180);
		} else {
			cout << "\n * Calculo inmediato :" << endl;
			cout << "   " << N_Angulo[2] << " = 180 - ( " << Angulo[0]*(180/M_PI) << " + " << Angulo[1]*(180/M_PI) << " )" << endl;
			Angulo[2] = calc_gamma(Angulo[0],Angulo[1]);
			cout << "\n * Angulo " << N_Angulo[2] << " = " << Angulo[2]*(180/M_PI);
			cout << "" << endl;
		}
	}
}

// Datos : Lado A y B , Angulo Gamma
void Pedir_2_lados_1_angulo(char N_Lado[], float Lado[], char N_Angulo[], float Angulo[], float var_aux) {
	int i;
	float pi;
	var_aux = 0;
	for (i=0;i<=2;i++) {
		if (i<2) {
			do {
				cout << "\n  Lado " << N_Lado[i] << " -> ";
				cin >> var_aux;
				// retorna 0 o 1
			} while ((No_cero(var_aux)==0));
			Lado[i] = var_aux;
		} else {
			do {
				cout << "\n  Angulo " << N_Angulo[2] << " -> ";
				cin >> var_aux;
				// retorna 0 o 1
			} while ((Comprobando_angulo_gamma(N_Angulo,var_aux,i)==0));
			Angulo[2] = var_aux*(M_PI/180);
		}
	}
}

// Datos : Lado A , Angulos Alpha y Beta
void Pedir_1_lado_2_angulos(char N_Lado[], float Lado[], char N_Angulo[], float Angulo[], float var_aux) {
	int i;
	float pi;
	var_aux = 0;
	for (i=0;i<=2;i++) {
		if (i==0) {
			do {
				cout << "\n  Lado " << N_Lado[0] << " -> ";
				cin >> var_aux;
				// retorna 0 o 1
			} while ((No_cero(var_aux)==0));
			Lado[0] = var_aux;
		} else {
			do {
				cout << "\n  Angulo " << N_Angulo[i-1] << " -> ";
				cin >> var_aux;
				// retorna 0 o 1
			} while ((Comprobando_angulos(N_Angulo,Angulo,var_aux,i-1)==0));
			Angulo[i-1] = var_aux*(M_PI/180);
		}
	}
}

// *********************************************
// *****     Fin Funciones pedir datos     *****
// *********************************************
// o-------------------------------------------o
// *********************************************
// *****     Funciones comprobar datos     *****
// *********************************************
int No_cero(float var_aux) {
	int x = 0;
	if (var_aux<=0) {
		x = 0;
		cout << "\n Valor invalido/Intentelo nuevamente." << endl;
		cout << "\n Presione cualquier tecla para continuar.";
		getch();
		system("cls");
		cout << " * El valor ingresado debe ser mayor a 0. *" << endl;
	} else {
		x = 1;
	}
	return x;
}

// comprobando para 3 Lado
int Comprobando_lado_C(float Lado[], float var_aux) {
	float suma_a_b = 0, resta_a_b = 0;
	int x = 0;
	suma_a_b = Lado[0]+Lado[1];
	resta_a_b = abs(Lado[0]-Lado[1]);
	if ((var_aux>=suma_a_b) || (var_aux<=resta_a_b)) {
		x = 0;
		cout << "\n Valor invalido/Intentelo nuevamente." << endl;
		cout << "\n Presione cualquier tecla para continuar.";
		getch(); 
		system("cls");
		cout << " * El valor ingresado debe estar entre los valores: *" << endl;
		cout << "           " << resta_a_b << " < Lado C < " << suma_a_b << endl;
	} else {
		x = 1;
	}
	return x;
}

// comprobando para 3 Angulo , se mandan 2 Angulo
int Comprobando_angulos(char N_Angulo[], float Angulo[], float var_aux, int i) {
	float suma_a_b = 0;
	int x = 0;
	if ((var_aux>=180) || (var_aux<=0)) {
		x = 0;
		cout << "\n Valor invalido/Intentelo nuevamente." << endl;
		cout << "\n Presione cualquier tecla para continuar.";
		getch();
		system("cls");
		cout << " * El valor ingresado debe estar entre los valores: *" << endl;
		cout << "           0 < " << N_Angulo[i] << " < 180" << endl;
	} else {
		x = 1;
		if (i==1) {
			suma_a_b = Angulo[0]+var_aux;
			if (suma_a_b>=180) {
				x = 0;
				cout << " Valor invalido/Intentelo nuevamente." << endl;
				cout << "\n Presione cualquier tecla para continuar.";
				getch();
				system("cls");
				cout << " * El valor ingresado debe estar entre los valores: *" << endl;
				cout << "           0 < " << N_Angulo[i] << " < " << 180-Angulo[0] << endl;
			}
		}
	}
	return x;
}

// comprobando Gamma
int Comprobando_angulo_gamma(char N_Angulo[], float var_aux, int i) {
	int x = 0;
	if ((var_aux>=180) || (var_aux<=0)) {
		x = 0;
		cout << "\n Valor invalido/Intentelo nuevamente." << endl;
		cout << "\n Presione cualquier tecla para continuar.";
		getch();
		system("cls");
		cout << " * El valor ingresado debe estar entre los valores: *" << endl;
		cout << "           0 < " << N_Angulo[i] << " < 180" << endl;
	} else {
		x = 1;
	}
	return x;
}

// ***************************************
// *****     Fin comprobar datos     *****
// ***************************************
// o---------------------------------------o
// *********************************************
// *****     Funciones datos restantes     *****
// *********************************************
// para 3 Lado
void calc_3_angulos(float Angulo[], float Lado[]) {
	// Calculo_Alpha_C_1(L_A,L_B,L_C)
	Angulo[0] = calc_alpha_cosenos(Lado[0],Lado[1],Lado[2]);
	// Calculo_Beta_C_1(L_A,L_B,L_C)
	Angulo[1] = calc_beta_cosenos(Lado[0],Lado[1],Lado[2]);
	Angulo[2] = calc_gamma_cosenos(Lado[0],Lado[1],Lado[2]);
}

// Para 3 Lado
void calc_3_lados(float Lado[], float Angulo[]) {
	// Debemos suponer!!!
	Lado[0] = 10;
	// Calculo_B_C_2(L_A,Alpha,Beta)
	Lado[1] = calc_B_senos(Lado[0],Angulo[0],Angulo[1]);
	// Calculo_C_C_2(L_A,Alpha,Gamma)
	Lado[2] = calc_C_senos(Lado[0],Angulo[0],Angulo[2]);
}

// tenemos el angulo Gamma 
void calc_1_lado_2_angulos(float Lado[], float Angulo[]) {
	// Calculo_C_C_3(L_A,L_B,Gamma)
	Lado[2] = calc_C_cosenos(Lado[0],Lado[1],Angulo[2]);
	// Calculo_Alpha_C_1(L_A,L_B,L_C)
	Angulo[0] = calc_alpha_cosenos(Lado[0],Lado[1],Lado[2]);
	// Calculo_Beta_C_1(L_A,L_B,L_C)
	Angulo[1] = calc_beta_cosenos(Lado[0],Lado[1],Lado[2]);
}

// se calcula inmediatamente.
void calc_1_angulo_2_lados(float Angulo[], float Lado[]) {
	Angulo[2] = calc_gamma(Angulo[0],Angulo[1]);
	// Calculo_B_C_4( L_A,Alpha,Beta )
	Lado[1] = calc_B_senos(Lado[0],Angulo[0],Angulo[1]);
	// Calculo_C_C_4( L_A,Alpha,Gamma )
	Lado[2] = calc_C_senos(Lado[0],Angulo[0],Angulo[2]);
}

// *************************************************
// *****     Fin Funciones datos restantes     *****
// *************************************************
// o-------------------------------------------o
// ******************************************
// *****     Funciones matematicas     ******
// ******************************************
//los Angulo se ingresan en grados
// hallando el angulo restante
// sirve para el caso 2
float calc_gamma(float alpha, float beta) {
	float gamma, pi;
	// llega en grados
	gamma = (M_PI-(alpha+beta));
	return gamma;
}

// caso 1.-de los 3 Lado como datos 
float calc_alpha_cosenos(float L_A, float L_B, float L_C) {
	float alpha, var_aux;
	var_aux = (-pow((L_A),2)+pow(L_B,2)+pow(L_C,2))/(2*L_B*L_C);
	alpha = acos(var_aux);
	return alpha;
}

float calc_beta_cosenos(float L_A, float L_B, float L_C) {
	float beta, var_aux;
	var_aux = (pow(L_A,2)-pow((L_B),2)+pow(L_C,2))/(2*L_A*L_C);
	beta = acos(var_aux);
	return beta;
}

float calc_gamma_cosenos(float L_A, float L_B, float L_C) {
	float gamma, var_aux;
	var_aux = (pow(L_A,2)+pow((L_B),2)-pow(L_C,2))/(2*L_A*L_B);
	gamma = acos(var_aux);
	return gamma;
}

// caso 2 y 4.-.de los 3 Angulo como datos 
float calc_B_senos(float L_A, float alpha, float beta) {
	float L_B;
	L_B = (L_A*sin(beta))/(sin(alpha));
	return L_B;
}

float calc_C_senos(float L_A, float alpha, float gamma) {
	float L_C;
	L_C = (L_A*sin(gamma))/(sin(alpha));
	return L_C;
}

// caso 3.-de 2Lados y 1 Angulo
float calc_C_cosenos(float L_A, float L_B, float gamma) {
	float L_C;
	L_C = pow((pow(L_A,2)+pow(L_B,2)-2*L_A*L_B*cos(gamma)),0.5);
	return L_C;
}

// **************************************
// -----     Hallando lo pedido     -----
// **************************************
// Hallando el area mediante su semicentro
float Calculo_Area(float L_A, float L_B, float L_C) {
	float area, s;
	// s : semiperimetro
	s = (L_A+L_B+L_C)/2;
	area = pow((s*(s-L_A)*(s-L_B)*(s-L_C)),0.5);
	return area;
}

// hallando la superficie
float Calculo_Perimetro(float L_A, float L_B, float L_C) {
	float p;
	p = L_A+L_B+L_C;
	return p;
}

// hallando las medianas
float Calculo_Mediana_A(float L_A, float L_B, float L_C) {
	float m_a;
	m_a = 0.5*pow((2*(pow(L_B,2)+pow(L_C,2))-pow((L_A),2)),0.5);
	return m_a;
}

float Calculo_Mediana_B(float L_A, float L_B, float L_C) {
	float m_b;
	m_b = 0.5*pow((2*(pow(L_A,2)+pow(L_C,2))-pow((L_B),2)),0.5);
	return m_b;
}

float Calculo_Mediana_C(float L_A, float L_B, float L_C) {
	float m_c;
	m_c = 0.5*pow((2*(pow(L_A,2)+pow(L_B,2))-pow((L_C),2)),0.5);
	return m_c;
}
// *********************************************
// *****     Fin Funciones matematicas     *****
// *********************************************
