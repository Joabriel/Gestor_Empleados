#include <stdio.h> 
#include <string.h>
#define CANTIDAD 1

struct empleados{
    char apeynom[20];
    int empNum;
    char direccion[20];
    double sueldo;
};
/*
enum opcs{
	ll,aa,dd,tt,nn
};
/*
int MostrarSeleccion1(char selec[]){
    switch(selec){
	case ll:
		char selec2[] = selec;
        printf("[tt]: 'todos'\n");
        printf("[nn]: ingresar número de empleado:\n");
		MostrarSeleccion2(selec2);
        break;
	case aa:
        printf("Ingrese número de empleado:\n");
        break;
	case dd:
        printf("ingrese número de empleado:\n");
		break;
	default:
		printf("Error: Operaci�n Inv�lida.\n");
		break;
    }
}*/
/*	
int MostrarSeleccion2(char selec2[]){
case tt: 
	return (Funcion imprimir todos los empleados);
	break;
case nn:
	return (Funsion imprimir al empleado seleccionado);
	break;
default: 
	printf("Error: Operaci�n Inv�lida.\n");
	break;
}*/

int main(){
    printf("    ----Gestor de Empleados----\n\n");
    printf("Opciones:\n");
    printf("[ll]:'leer' ");
    printf("[aa]:'actualizar' ");
    printf("[bb]:'borrar'\n\n");
	
	struct empleados usaremp[CANTIDAD];
	
	printf("Ingrese numero de empleado:");
	scanf("%i",&usaremp[0].empNum);
	printf("Ingrese nombre del empleado:");
	scanf("%s",&usaremp[0].apeynom);
	printf("Ingrese direccion del empleado:");
	scanf("%s",usaremp[0].direccion);
	printf("Ingrese sueldo del empleado:");
	scanf("%d",&usaremp[0].sueldo);

	printf("\n%i\n%s\n%s\n%d",usaremp[0].empNum,usaremp[0].apeynom,usaremp[0].direccion,usaremp[0].sueldo);
	
	/*
    char selec[1];
    scanf("%s",&selec);
    MostrarSeleccion(selec);*/
	
	/*
	for(int i=0; i<=CANTIDAD; i++){
		printf("Ingrese n�mero de empleado:");
		scanf("%i",&emp[1].usar.empNum);
		printf("Ingrese nombre del empleado:");
		scanf("%s",&emp[i].usar.apeynom);
		printf("Ingrese direccion del empleado:");
		scanf("%s",&emp[i].usar.direccion);
		printf("Ingrese sueldo del empleado:");
		scanf("%d",&emp[i].usar.sueldo);
	}*/
	
}
