#include <stdio.h> 
#define CANTIDAD 2

struct empleados{
    char apeynom[20];
    int empNum;
    char direccion[20];
    double sueldo;
};

enum opcs{
	e='e',
	l='l',
	a='a',
	b='b',
};/*
enum opcs2{
	todos=0,
	num=1
};*/

/*
//Prototipos de funci�n.
void CasoL();
void CasoA();
void CasoB();
*/

void Seleccion(char selec){
	FILE *ArchivoenUso;
	struct empleados emp[CANTIDAD];
    switch(selec){
	case e: 
	ArchivoenUso = fopen("empleados.txt","wb");
	if(ArchivoenUso == NULL){
		perror("error al abrir archivo");
		//return 1;
	}

	emp->empNum = 1;
	printf("\nIngrese información sobre el empleado: %i",emp->empNum);
	fputs("               ----Datos de empleados----",ArchivoenUso);
	fprintf(ArchivoenUso, "\nEmpleado N°:		%i\n",emp->empNum);
	printf("\n\nNombre y Apellido: ");
	scanf("%s",&emp->apeynom);
	fprintf(ArchivoenUso, "Nombre y Apellido:		%s\n", emp->apeynom);
	getchar();

	printf("\nDirección: ");
	scanf("%s",&emp->direccion);
	fprintf(ArchivoenUso, "Dirección:		%s\n", emp->direccion);
	getchar();

	printf("\nSueldo: ");
	scanf("%d",&emp->sueldo);
	fprintf(ArchivoenUso, "Sueldo:			%d\n", emp->sueldo);
	getchar();


	break;
	case l:	
	/*printf("\n[todos]: 'todos'\n");
	printf("[num]: ingresar numero de empleado:\n");
	int selec2;
	scanf("%i",&selec2);
	CasoL(selec2);*/
	getchar();
	ArchivoenUso = fopen("empleados.txt", "rb");
	if(ArchivoenUso == NULL){
		printf("Error: Archivo Vacio.");
	}
	char caracter;
	while(feof(ArchivoenUso) == 0){
		caracter = fgetc(ArchivoenUso);
		printf("%c",caracter);
	};
	break;
/*
	case a:
		getchar();
		ArchivoenUso = fopen("empleados.dat","rb")
		if(ArchivoenUso == NULL){
			perror("Error en la apertura del archivo");
			return 1;
		}
		//.
		printf("\nIngrese número de empleado para ACTUALIZAR información:\n");
		int x;
		scanf("%i",&x);

		bool numeroEncontrado = false;
		int capNum;

		while(feof(ArchivoenUso) == 0 || numeroEncontrado == true){
			fscanf(ArchivoenUso, "%i", &capNum);
			if(capNum == x){
				numeroEncontrado = true;
				printf("Que información desea actualizar de: %i?\n",emp.empNum);
				printf("0=[Nombre]  1=[Dirección]  2=[Sueldo]");

				switch(x){
					case 0:
					scanf("%s",&emp[x].empNum);

					break;
					case 1: 
					scanf("%s",&emp[x].direccion);
					break;
					case 2: 
					scanf("%f",&emp[x].sueldo);
				}
			}
		}



		//CasoA(x);
        break;
	case b:
		getchar();
		
        printf("\ningrese numero de empleado:\n");
		int y;
		scanf("%i",&y);
		//CasoB(y);

		break;
	default:
		perror("\nError: Operaci�n Inv�lida.\n");
		break;*/
    }
}

/*
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
}
	
void CasoB(int y){
}
*/
//3ra versión.
int main(){
	//getchar();
    printf("\n    ----Gestor de Empleados----\n\n");
    printf("Opciones:\n");
	printf("[ee]: 'escribir'");
    printf("[ll]:'leer' ");
    printf("[aa]:'actualizar' ");
    printf("[bb]:'borrar'\n\n");
	//Paso 1: menú, seleccion de opción y llevar a Seleccion();.
	char selec;
    scanf("%c",&selec);
    Seleccion(selec);
	getchar(); //Evitar que el programa se cierre solo.
	return 0;
}