#include <stdio.h>
#define N 100

int main () {
	
	system ("COLOR FD");
	
	printf("                    ________________________________________________________________\n");
	printf("                                                                                    \n");
	printf("                                             CONSULTORIO CFL                        \n");
	printf("                    ________________________________________________________________\n");
	
    printf("\n");		
	int opcion=0;
	char nombre[N], primer_apellido[N], segundo_apellido[N], usuario[N], correo_electronico[N], contrasennya[N];
	int dia, mes, annyo;
	
	do {
		
	    printf("Bienvenidos al cuestionario mas entretenido y con mayor variedad de opciones, asi descubriras para lo que estas hecho.\n");
	    printf("\n");
	    printf("Elige una opcion para continuar:\n");
	    printf("   1-Instrucciones.\n");
	    printf("   2-Regitrarse.\n");
	    printf("   3-Iniciar sesion para comenzar.\n");
	    printf("   4-Salir.\n");
	    scanf("%d", &opcion);

	    switch (opcion) {
		    case 1: 
		        printf("Instrucciones.\n");
		        printf("\n");
			    printf("Bienvenido al Consultorio CFL. En este consultorio seras capaz de realizar un test sobre tus gustos, aficiones y personalidad para guiarte en tu futuro.\n");
			    printf("El cuestionario consta de 10 preguntas que se reparten en dos bloques: el primero acerca de tus habilidades y el segundo bloque de como te ves en un futuro.\n");
			    printf("Son preguntas rapidas y sencillas que deben ser respondidas con si o no.\n ");
			    
			break;
		        
		    case 2:
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
			
			    printf("Bienvenido %s.\n", usuario);
			    
			break;
		  
		    case 3: 
		    	printf("Iniciar sesion para comenzar.\n");
			    printf("Introduce el nombre de usuario:");
			    scanf("%s", usuario);
			    
			    printf("Introduce la contrasennya:");
			    scanf("%s",contrasennya);
			    
			    printf("Bienvenido de nuevo %s", usuario);
		
			break;
			    
		    case 4:
			    printf("Salir.\n");
			    
			break;
			    
	    }
	    
	} while (opcion!=4);
	 
	return 0;
}
