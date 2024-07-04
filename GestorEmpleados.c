#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h>
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
int actualizarDatos();
	
	int main(){
		int selec, id, errorSalida=0;
		do{
		printf("\n    ----Gestor de Empleados----\n");
		printf("Nombre del archivo: %s\n\n",ARCHIVONOMBRE);	
		printf("Opciones:\n");
		printf("[1]:'leer.' ");
		printf("[2]:'Agregar Empleado.' ");
		printf("[3]:'borrar' ");
		printf("[4]:'Actualizar.' ");
		printf("[5]:'Salir.'\n\n");
		
		scanf("%i",&selec);
			switch(selec){
			case 1:
				getchar();
				leerDato();
				getchar();
				break;  
			case 2: 
				agregarDato(ARCHIVONOMBRE,&errorSalida);
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
			case 4:
				printf("Ingrese ID para actualizar: ");
				scanf("%i",&id);
				actualizarDatos(ARCHIVONOMBRE,id);
				if(errorSalida == 1){
					fprintf(stderr,"No se puede abrir el archivo para actualizar datos.\n");
				}
				getchar();
				//getchar();
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
	
		
	int agregarDato(const char *archivonombre,int *errorSalida){
		FILE *ArchivoenUso = fopen(archivonombre,"ab+");
		if(ArchivoenUso == NULL){
			fprintf(stderr,"No se puede abrir archivo para agregar.");
			*errorSalida=1;
			return *errorSalida;
		}
		
		Empleados addEmp;
		
		
		int ultimoid = obtenerUltimoId(ARCHIVONOMBRE);
		addEmp.empNum = ultimoid +1;
		
		if(addEmp.empNum > CANT_ADMIT){
			printf("-No se puede agregar más datos.");
			*errorSalida=2;
			return *errorSalida;
		}
		
		printf("\nEmpleado N°: %d\n", addEmp.empNum);
		getchar();
		printf("Nombre y Apellido: ");
		fgets(addEmp.apeynom, sizeof(addEmp.apeynom), stdin); // Evitar desbordamiento en el buffer.
		addEmp.apeynom[strcspn(addEmp.apeynom, "\n")] = 0;  // Eliminar el carácter de nueva línea, acompaña a fgets.
		fflush(stdin);
		printf("Dirección: ");
		fgets(addEmp.direccion, sizeof(addEmp.direccion), stdin); 
		addEmp.direccion[strcspn(addEmp.direccion, "\n")] = 0;
		
		printf("Sueldo: ");
		scanf("%lf", &addEmp.sueldo);
		//getchar(); // Consumir el carácter de nueva línea
		
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
				printf("\nEmpleado N°: [ %d ]\n",leerEmp.empNum);
				printf("Nombre/Apellido: [ %s ]\n",leerEmp.apeynom);
				printf("Dirección: [ %s ]\n",leerEmp.direccion);
				printf("Sueldo: [ %.2f ]\n",leerEmp.sueldo);
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
			
			int actualizarDatos(const char *archivonombre, int id, int *errorSalida) {
				FILE *ArchivoenUso = fopen(archivonombre, "rb+");
				if (ArchivoenUso == NULL) {
					*errorSalida = 1;
					return *errorSalida;
				}
				
				Empleados emp;
				int encontrado = 0;
				
				while (fread(&emp, sizeof(Empleados), 1, ArchivoenUso) == 1) {
					if (emp.empNum == id) {
						encontrado = 1;
						
						printf("Actualizando datos del empleado con ID %d:\n", id);
						printf("Nombre/Apellido actual: %s\n", emp.apeynom);
						printf("Nuevo Nombre/Apellido: ");
						getchar();
						fgets(emp.apeynom, sizeof(emp.apeynom), stdin);
						emp.apeynom[strcspn(emp.apeynom, "\n")] = 0;
						
						printf("Dirección actual: %s\n", emp.direccion);
						printf("Nueva Dirección: ");
						fgets(emp.direccion, sizeof(emp.direccion), stdin);
						emp.direccion[strcspn(emp.direccion, "\n")] = 0;
						
						printf("Sueldo actual: %.2f\n", emp.sueldo);
						printf("Nuevo Sueldo: ");
						scanf("%lf", &emp.sueldo);
						getchar();
						
						/*debido a que fread posiciona al cursor en el siguiente registro luego de leer
						y Se necesita sobreescribir el ultimo registro leido (que es igual a "id"), posicionamos al cursor en su
						anterior posición.*/
						fseek(ArchivoenUso, -sizeof(Empleados), SEEK_CUR); //Se desplaza desde la posición, un registro hacia atras.
						fwrite(&emp, sizeof(Empleados), 1, ArchivoenUso);
						break;
					}
				}
				
				fclose(ArchivoenUso);
				
				if (encontrado != 1) {
					printf("-No se encontró un registro con el ID %d\n", id);
					return 2;
				} else {
					printf("-Datos actualizados correctamente.\n");
					return 0;
				}
			}
				

			
	
	
	
