#include <stdio.h>
#include <string.h>
#define N 100
#define MAX_USUARIO 100

// Estructura Usuarios
struct Usuario {
	char nombre[N];
	char primer_apellido[N];
	char segundo_apellido[N];
	char usuario[N];
	char correo_electronico[N];
	char contrasennya[N];
};

int main () {
	
	system ("COLOR FD");
	
	printf("                    ________________________________________________________________\n");
	printf("                                                                                    \n");
	printf("                                             CONSULTORIO CFL                        \n");
	printf("                    ________________________________________________________________\n");
	
    printf("\n");	
	
	struct Usuario nuevo_usuario;
	int opcion=0;
	int num_usuarios=0;
	char usuario[N], contrasennya[N];
	
	printf("Bienvenidos al cuestionario mas entretenido y con mayor variedad de opciones, asi descubriras para lo que estas hecho.\n");
	
	do {
		
		do {
			// Menú de opciones
	        printf("\n");
	        printf("Elige una opcion para continuar:\n");
	        printf("   1-Instrucciones.\n");
	        printf("   2-Regitrarse.\n");
	        printf("   3-Iniciar sesion para comenzar.\n");
	        printf("   4-Salir.\n");
	        scanf("%d", &opcion);
		} while (opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);
	   
	    switch (opcion) {
		    case 1: 
		        printf("Instrucciones.\n");
		        printf("\n");
			    printf("Bienvenido al Consultorio CFL. En este consultorio seras capaz de realizar un test sobre tus gustos, aficiones y personalidad para guiarte en tu futuro.\n");
			    printf("El cuestionario consta de 10 preguntas que se reparten en dos bloques: el primero acerca de tus habilidades y el segundo bloque de como te ves en un futuro.\n");
			    printf("Son preguntas rapidas y sencillas que deben ser respondidas con si o no.\n ");
			    
			break;
		        
		    case 2:
		    	// Registro nuevo usuario
		    	printf("Registrarse.\n");
		    	
		    	
		        printf("Nombre:\n");
			    scanf("%s", nuevo_usuario.nombre);
			
			    printf("Primer apellido:\n");
			    fflush(stdin);
			    scanf("%s", nuevo_usuario.primer_apellido);
			
			    printf("Segundo apellido:\n");
			    fflush(stdin);
			    scanf("%s", nuevo_usuario.segundo_apellido);
			
			    printf("Correo electronico\n");
			    fflush(stdin);
		        scanf("%s", nuevo_usuario.correo_electronico);
		    
		        printf("Nombre de usuario:\n");
		        fflush(stdin);
			    scanf("%s", nuevo_usuario.usuario);		
			
			    printf("Contrasennya:\n");
			    fflush(stdin);
			    scanf("%s", nuevo_usuario.contrasennya);
			
			    printf("Bienvenido %s.\n", nuevo_usuario.usuario);
			        
			    num_usuarios++;
			        
			    // printf("Has sido la persona numero %d en unirse.\n", num_usuarios); (con ficheros)
			        
			break;
		  
		    case 3: 
		        // Inicio de sesion para un usuario ya registrado 
		    	printf("Iniciar sesion para comenzar.\n");
			    printf("Introduce el nombre de usuario:");
			    scanf("%s", usuario);
			    
			    printf("Introduce la contrasennya:");
			    scanf("%s", contrasennya);
			 
			    printf("Bienvenido de nuevo %s", usuario);
		
			break;
			
		    case 4:
		    	// Salida del programa
			    printf("Saliendo...\n");
			    
			break;
	    }
	    
	} while (opcion!=4);
	 
	return 0;
}
