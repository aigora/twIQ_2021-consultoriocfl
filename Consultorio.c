#include <stdio.h>

int main () {
	
	system ("COLOR FD");
	
	printf("                    ________________________________________________________________\n");
	printf("                                                                                    \n");
	printf("                                             CONSULTORIO CFL                        \n");
	printf("                    ________________________________________________________________\n");
	
    printf("\n");		
	int opcion=0;
	char nombre[50], primer_apellido[50], segundo_apellido[50], usuario[50], correo_electronico[50], contrasennya[50];
	int dia, mes, annyo;
	while (opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4) {
		
	    printf("Bienvenidos al cuestionario mas entretenido y con mayor variedad de opciones, asi descubriras para lo que estas hecho.\n");
	    printf("\n");	
	    printf("Elige una opcion para continuar:\n");
	    printf("   1-Registrarse.\n");
	    printf("   2-Iniciar sesion para comenzar.\n");
	    printf("   3-Instrucciones.\n");
	    printf("   4-Salir.\n");
	    scanf("%d", &opcion);
    }	  
	switch (opcion) {
		    case 1: 
		        printf("Registrarse.\n");
			 printf("Nombre:\n");
			scanf("%s", nombre);
			
			printf("Primer apellido:\n");
			fflush(stdin);
			scanf("%s", primer_apellido);
			
			printf("Segundo apellido:\n");
			fflush(stdin);
			scanf("%s", segundo_apellido);
			
			printf("Fecha de nacimiento (dia mes annyo)\n");
			fflush(stdin);
			scanf("%d %d %d", &dia, &mes, &annyo);
			
			printf("Correo electronico\n");
			fflush(stdin);
		        scanf("%s", correo_electronico);
		    
		        printf("Nombre de usuario:\n");
		        fflush(stdin);
			scanf("%s", usuario);		
			
			printf("Contrasennya:\n");
			fflush(stdin);
			scanf("%s", contrasennya);
		        break;
		    case 2:
			    printf("Iniciar sesion para comenzar.\n");
			    break;
		    case 3: 
			    printf("Instrucciones.\n");
			    break;
		    case 4:
			    printf("Salir.\n");
			    break;
	} 
	 
	return 0;
}
