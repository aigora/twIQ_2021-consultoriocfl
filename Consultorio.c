#include <stdio.h>
#include <string.h>
#define N 100
#define MAX_USUARIO 100

// Estructura Usuarios
struct Usuario {
	char nombre[N];
	char primer_apellido[N];
	char segundo_apellido[N];
	char correo_electronico[N];	
	char usuario[N];
	char contrasennya[N];
};

int main () {
	
	system ("COLOR FD");
	
	printf("                    ________________________________________________________________\n");
	printf("                                                                                    \n");
	printf("                                             CONSULTORIO CFL                        \n");
	printf("                    ________________________________________________________________\n");
	
    printf("\n");	
    
	FILE * fichero;
    struct Usuario usuarios[MAX_USUARIO];
	struct Usuario nuevo_usuario;
	int num_usuarios=0;
	int opcion, i, sesion_iniciada;
	char usuario[N], contrasennya[N];
	
	// CARGA DE DATOS
    fichero = fopen("usuarios.txt", "r");
    
    if(fichero == NULL) {
        printf("Error al cargar los datos\n");
        return 0;
    }
    
    while (num_usuarios < MAX_USUARIO && fscanf(fichero, "%s %s %s %s %s %s", usuarios[num_usuarios].nombre, usuarios[num_usuarios].primer_apellido, usuarios[num_usuarios].segundo_apellido, usuarios[num_usuarios].correo_electronico, usuarios[num_usuarios].usuario, usuarios[num_usuarios].contrasennya) != EOF) {
		num_usuarios++;
    }
    
    fclose(fichero);
    
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
		    	
		    	if (num_usuarios < MAX_USUARIO){
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
		            
		            i=0;
					do{
			        	printf("Nombre de usuario:\n");
			            fflush(stdin);
				        scanf("%s", nuevo_usuario.usuario);	
				        for (i=0; i<num_usuarios; i++){
				        	if (strcmp(usuarios[i].usuario, nuevo_usuario.usuario)==0){
				        		printf("Este nombre de usuario ya esta elegido.\nIntroduzca otro\n");
				        		break;
							}
						}
					} while (strcmp(usuarios[i].usuario, nuevo_usuario.usuario)==0 );
					
					if (strcmp(usuarios[i].usuario, nuevo_usuario.usuario)!=0){
						strcpy(usuarios[num_usuarios].usuario, nuevo_usuario.usuario);
					}
			
			        printf("Contrasennya:\n");
			        fflush(stdin);
			        scanf("%s", nuevo_usuario.contrasennya);
			
			        printf("\nBienvenido %s.\n", nuevo_usuario.usuario);
			        
			        num_usuarios++;
				    usuarios[num_usuarios - 1] = nuevo_usuario;
				    printf("Has sido la persona numero %d en registrarse.\n", num_usuarios);
				}
				
				else {
					printf("Lo sentimos, numero maximo de usuarios alcanzado.\n");
				}
		    
			break;
			
		    case 3: 
		        // Inicio de sesion para un usuario ya registrado 
		    	printf("Iniciar sesion para comenzar.\n");
			    printf("Introduce el nombre de usuario:");
			    fflush(stdin);
			    scanf("%s", usuario);
			    
			    printf("Introduce la contrasennya:");
			    fflush(stdin);
			    scanf("%s", contrasennya);
			    
			    sesion_iniciada=0;
			    for(i=0; i<num_usuarios; i++) {
			    	if( (strcmp(usuario, usuarios[i].usuario)==0) && (strcmp(contrasennya, usuarios[i].contrasennya)==0) )   {
			    		printf("\nBienvenido de nuevo %s\n", usuario);
			    		sesion_iniciada=1;
					}
				}
				
				if(sesion_iniciada==1) {
					// PREGUNTAS AQUI	
					printf("Primera Pregunta:\n");
				}
				
				else if (sesion_iniciada==0){
					printf("\nUsuario o contrasennya no validos\n");
				}
				
			break;
			
		    case 4:
		    	// Salida del programa
			    printf("Saliendo...\n");
			    
	            fichero = fopen("usuarios.txt", "w");
	
                if (fichero == NULL) {
		            printf("Error abriendo fichero para escritura.");
		            return 0;
	            }
	
                for(i=0; i<num_usuarios; i++) {
                    fprintf(fichero, "%s %s %s %s %s %s\n", usuarios[i].nombre, usuarios[i].primer_apellido, usuarios[i].segundo_apellido, usuarios[i].correo_electronico, usuarios[i].usuario, usuarios[i].contrasennya);
                }
                
                fclose(fichero);
                
			break;
	    }
	    
	} while (opcion!=4);
	
	return 0;
}
