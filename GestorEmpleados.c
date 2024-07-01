#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#define CANT_ADMIT 10
#define ARCHIVONOMBRE "empleados.dat"

typedef struct{
	int empNum;
	char apeynom[20];
    char direccion[20];
    double sueldo;
}Empleados;

int obtenerUltimoId();
int agregarDato();
int errores(); //Pertenece a la de arriba.
void leerDato();
int borrarDatos();
	
	int main(){
		int selec, id, errorSalida=0;
		do{
		printf("\n    ----Gestor de Empleados----\n");
		printf("Nombre del archivo: %s\n\n",ARCHIVONOMBRE);	
		printf("Opciones:\n");
		printf("[1]:'leer.' ");
		printf("[2]:'Agregar Empleado.' ");
		printf("[3]:'borrar' ");
		printf("[5]:'Salir.'\n\n");
		
		scanf("%i",&selec);
			switch(selec){
			case 1:
				getchar();
				leerDato();
				getchar();
				break;  
			case 2: 
				agregarDato(ARCHIVONOMBRE,errorSalida);
				getchar();
				sleep(1);
				break;
			case 3:
				printf("Ingrese ID: ");
				scanf("%i",&id);
				borrarDatos(id);
				getchar();
				sleep(1);
				break;
			case 5:
				printf("-Salida.");
				break;
			default: 
				printf("operación inválida.");
				break;	
			}
			system("cls");
		} while(selec != 5);

		
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
	
		
	int agregarDato(const char *archivonombre,int errorSalida){
		FILE *ArchivoenUso = fopen(archivonombre,"ab+");
		if(ArchivoenUso == NULL){
			fprintf(stderr,"No se puede abrir archivo para agregar.");
			errorSalida=1;
			return errorSalida;
		}
		
		Empleados addEmp;
		
		
		int ultimoid = obtenerUltimoId(ARCHIVONOMBRE);
		addEmp.empNum = ultimoid +1;
		
		if(addEmp.empNum > CANT_ADMIT){
			printf("-No se puede agregar más datos.");
			errorSalida=2;
			return errorSalida;
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
			getchar(); //Evita que se lea "operación inválida" luego de usar caso 2.

		//printf("\n-Fin de petición de datos.");
		
		fwrite(&addEmp,sizeof(Empleados),1,ArchivoenUso);
		
		fclose(ArchivoenUso);
		return 0;
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
			
		
		int borrarDatos(int id){
			FILE *ArchivoenUso = fopen(ARCHIVONOMBRE,"rb");
			if(ArchivoenUso == NULL){
				fprintf(stderr,"No se puede abrir para buscar datos.");
				exit(1);
			}
			
			FILE *ArchivoTemp = fopen("temp.dat","wb");
			if(ArchivoTemp == NULL){
				printf("No se pudo crear archivo temporal.");
				exit(1);
			}
			Empleados borrarEmp;
			int encontrado = 0;
			while(fread(&borrarEmp,sizeof(Empleados),1,ArchivoenUso)==1){
				if(borrarEmp.empNum==id){
					encontrado = 1;
				}else{
						fwrite(&borrarEmp,sizeof(Empleados),1,ArchivoTemp);
					}
				}
			/*Cierro antes de la asignación de los archivos para que
			no se cancele el traspaso de información.*/
			fclose(ArchivoenUso);
			fclose(ArchivoTemp);
			if(encontrado == 1){
				remove(ARCHIVONOMBRE);
				rename("temp.dat",ARCHIVONOMBRE);
				printf("-\n-empleado N°: %i eliminado correctamente.",id);
			}else{
				remove("temp.dat");
				fprintf(stderr,"\n-No se pudo eliminar a %i",id);
			}
			return 0;
		}
			
			
	
	
	
