#include <stdio.h>
#include <stdlib.h>  
#define CANT_ADMIT 10
#define ARCHIVONOMBRE "empleados.dat"

typedef struct{
	int empNum;
	char apeynom[20];
    char direccion[20];
    double sueldo;
}Empleados;

enum opcs{
	a='a',
	l='l',
	b='b',
	//(Actualizar).
};

int obtenerUltimoId();
void agregarDato();
void leerDato();
	
	int main(){
		printf("\n    ----Gestor de Empleados----\n");
		printf("Nombre del archivo: %s\n\n",ARCHIVONOMBRE);	
		printf("Opciones:\n");
		printf("[ll]:'leer' ");
		printf("[aa]:'Agregar Empleado.' \n\n");
		//printf("[bb]:'borrar'\n");
		
		char selec;
		scanf("%c",&selec);
	
		switch(selec){
		case a:
			agregarDato(ARCHIVONOMBRE);
			break;  
		case l: 
			leerDato();
			break;
		default: 
			printf("operación inválida.");
			break;
		}

	getchar(); //Evitar que el programa se cierre solo.
	return 0;	
}
		
	int obtenerUltimoId(const char *archivonombre){
		FILE *VerNum = fopen(archivonombre,"rb");
		if(VerNum == NULL){
			fprintf(stderr,"No se pudo abrir el archivo para ver el ultimo número.");
			return 0;
		}
		
		Empleados emp;
		int ultimoID = 0;
		
		while(fread(&emp,sizeof(Empleados),1,VerNum)==1){
				ultimoID = emp.empNum;
			}
			
		fclose(VerNum);
		return ultimoID;
	}
		
	void agregarDato(const char *archivonombre){
		FILE *ArchivoenUso = fopen(archivonombre,"ab+");
		if(ArchivoenUso == NULL){
			fprintf(stderr, "No se pudo abrir el archivo para agregar datos\n");
			exit(0);
		}
		
		Empleados addEmp;
		
		
		int ultimoid = obtenerUltimoId(ARCHIVONOMBRE);
		addEmp.empNum = ultimoid +1;
		
		if(addEmp.empNum > CANT_ADMIT){
			printf("No se puede agregar mas datos.");
			exit(0);
		}
		
			printf("\nEmpleado N°: %i\n",addEmp.empNum);
			printf("Nombre_Apellido: ");
			scanf("%s",&addEmp.apeynom);
			getchar();
			
			printf("Dirección: ");
			scanf("%s",&addEmp.direccion);
			getchar();
			
			printf("Sueldo: ");
			scanf("%d",addEmp.sueldo);
			getchar();	

		printf("\n-Fin de petición de datos.");
		
		fwrite(&addEmp,sizeof(Empleados),1,ArchivoenUso);
		
		fclose(ArchivoenUso);
	}
		
		void leerDato(){
			FILE *ArchivoenUso = fopen(ARCHIVONOMBRE,"rb");
			if(ArchivoenUso == NULL){
				fprintf(stderr, "No se pudo abrir el archivo para leer datos\n");
				exit(0);
			}
			
			Empleados leerEmp;
			while(fread(&leerEmp,sizeof(Empleados),1,ArchivoenUso)==1){
				printf("___________________");
				printf("\nEmpleado N°: [ %i ]\n",leerEmp.empNum);
				printf("Nombre/Apellido: [ %s ]\n",leerEmp.apeynom);
				printf("Dirección: [ %s ]\n",leerEmp.direccion);
				printf("Sueldo: [ %f ]\n",leerEmp.sueldo);
			}
			printf("\n\n-Fin de lectura de datos.");
			fclose(ArchivoenUso);
		}
	
	
	
