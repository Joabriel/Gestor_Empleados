#include <stdio.h> 
#include <string.h>
#define CANTIDAD 2

struct empleados{
    char apeynom[20];
    int empNum;
    char direccion[20];
    double sueldo;
};

enum opcs{
	l='l',
	a='a',
	b='b',
};/*
enum opcs2{
	todos=0,
	num=1
};*/

void IngresodeDatos(){  //Borrar en cuanto se agregue archivos.
	struct empleados usaremp[CANTIDAD];
	//crear "boton" para detener la iteraccion.
		for(int i=0; i<CANTIDAD; i++){
		printf("\nIngrese NUMERO de empleado:");
		scanf("%i",&usaremp[i].empNum);
		printf("Ingrese NOMBRE del empleado:");
		scanf("%s",&usaremp[i].apeynom);
		getchar();
		printf("Ingrese DIRECCION del empleado:");
		scanf("%s",usaremp[i].direccion);
		getchar();
		printf("Ingrese SUELDO del empleado:");
		scanf("%f",&usaremp[i].sueldo);
	}
}

//Prototipos de funci�n.
void CasoL();
void CasoA();
void CasoB();

void Seleccion(char selec){
    switch(selec){
	case l:
        printf("\n[todos]: 'todos'\n");
        printf("[num]: ingresar numero de empleado:\n");
		int selec2;
		scanf("%i",&selec2);
		CasoL(selec2);
        break;
	case a:
		getchar();
        printf("\nIngrese numero de empleado:\n");
		int x;
		scanf("%i",&x);
		CasoA(x);
        break;
	case b:
		getchar();
        printf("\ningrese numero de empleado:\n");
		int y;
		scanf("%i",&y);
		CasoB(y);
		break;
	default:
		printf("\nError: Operaci�n Inv�lida.\n");
		break;
    }
}

void CasoL(int selec2){
	struct empleados usaremp[CANTIDAD];
	switch(selec2){
	case 0: //(todos). 
	//Se debe usar archivos, tienen que tener varios empleados.
		for(int i=0; i<CANTIDAD; i++){
			printf("\n%i\n",usaremp[i].empNum);
			printf("%s\n",usaremp[i].apeynom);
			printf("%s\n",usaremp[i].direccion);
			printf("%d\n",usaremp[i].sueldo);
		}
	case 1: //(num).
		//ingresar n�mero del empleado
		printf("Ingrese N�mero del empleado:");
		int x;
		scanf("%i",&x);
		printf("%s",usaremp[x].apeynom);
		printf("%i",usaremp[x].empNum);
		printf("%s",usaremp[x].direccion);
		printf("%f",usaremp[x].sueldo);
	default:
		printf("\nError: Operaci�n Inv�lida.");
	};
}
	
void CasoA(int x){
	struct empleados usaremp[CANTIDAD];
	printf("%s",usaremp[x].apeynom);
	printf("%i",usaremp[x].empNum);
	printf("%s",usaremp[x].direccion);
	printf("%f",usaremp[x].sueldo);
}
	
void CasoB(int y){
	struct empleados usaremp[CANTIDAD];
	printf("%s",usaremp[y].apeynom);
	printf("%i",usaremp[y].empNum);
	printf("%s",usaremp[y].direccion);
	printf("%f",usaremp[y].sueldo);
}

int main(){
	IngresodeDatos();
	getchar();
    printf("\n    ----Gestor de Empleados----\n\n");
    printf("Opciones:\n");
    printf("[ll]:'leer' ");
    printf("[aa]:'actualizar' ");
    printf("[bb]:'borrar'\n\n");
	//Paso 1: menú, seleccion de opción y llevar a MostrarSeleccion1();.
	char selec;
    scanf("%c",&selec);
    Seleccion(selec);
	getchar(); //Evitar que el programa se cierre solo.
	return 0;
}
