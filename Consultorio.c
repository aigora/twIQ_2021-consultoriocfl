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
void imprimirMenu();
int compararString(char cadena1[], char cadena2[]);
int longitudString(char cadena[]);


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
	char respuesta[2];
	int opcion2;
	
	
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
	     imprimirMenu();
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
				        	if (compararString(usuarios[i].usuario, nuevo_usuario.usuario)==0){
				        		printf("Este nombre de usuario ya esta elegido.\nIntroduzca otro\n");
				        		break;
							}
						}
					} while (compararString(usuarios[i].usuario, nuevo_usuario.usuario)==0 );
					
					if (compararString(usuarios[i].usuario, nuevo_usuario.usuario)!=0){
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
					//Preguntas
					printf("¿Que modalidad estas estudiando?\n");
					
					printf("1.Ciencias\n2.Humanidades y Ciencias Sociales\n3.Artes\n");
					scanf("%d",&opcion2);
					
					switch(opcion2){
						case 1:
							printf("¿Te desenvuelves bien con los ordenadores?(Si o No)\n");
							scanf("%s", respuesta);
							if (respuesta=='Si'|| respuesta=='si'){
								
								
							}
							else if (respuesta == 'No' || respuesta == 'no') {
									
							}
							
							break;
				
						case 2:
							printf("¿Te sientes comodo cuando hablas en publico?(Si o No)\n");
							scanf("%s",respuesta);
						    if (respuesta=='Si'|| respuesta=='si'){
						    	printf("¿");
						    	
			
								
							}
							else if (respuesta=='No'||respuesta=='no') {
									
							}
							
						
						
							break;
							
						case 3:
							printf("¿Sueles acudir a teatros, operas, danzas, conservatorios?(Si o No)\n");
							fflush(stdin);
							scanf("%s",respuesta);
							if(compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0) {
								printf("¿Te apasiona bailar?(Si o No)\n");
								fflush(stdin);
								scanf("%s",respuesta);
								if(compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0) {
									printf("GRADO DE DANZA\n");
								}
								else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0) {
									printf("¿Disfrutas componiendo obras y tocando instrumentos?(Si o No)\n");
									fflush(stdin);
									scanf("%s",respuesta);	
									if(compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0) {
										printf("GRADO EN MUSICOLOGIA\n");
									}
									else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0) {
										printf("¿Te interesa la evolucion artistica y cultural del ser humano?(Si o No)\n");
										fflush(stdin);
										scanf("%s",respuesta);
										if(compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0) {
											printf("HISTORIA DEL ARTE\n");
										}
										else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0) {
											printf("¿Tienes la capacidad de la creacion y analisis de las artes visuales?(Si o No)\n");
											fflush(stdin);
											scanf("%s",respuesta);	
											if(compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0) {
												printf("BELLAS ARTES\n");
											}
											else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0) {
												printf("ARTES ESCENICAS\n");	
											}
										}		
									}
								}
							}
							else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0) {
								printf("¿Eres capaz de trasmitir y representar valores a traves de diversos modos de comunicacion?(Si o No)\n");
								fflush(stdin);
								scanf("%s",respuesta);	
								if(compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0) {
									printf("DISEÑO GRAFICO\n");
								}
								else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0) {
									printf("¿Dedicas tu tiempo libre a la moda?(Si o No)\n");
									fflush(stdin);
									scanf("%s",respuesta);
									if(compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0) {
										printf("DISEÑO DE MODA\n");
									}
									else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0) {
										printf("¿Tu sueño es crear arte con la tecnologia?(Si o No)\n");
										fflush(stdin);
										scanf("%s",respuesta);	
										if(compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0) {
											printf("DISEÑO DIGITAL\n");
										}
										else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0) {
											printf("DISEÑO DE INTERIORES\n");	
										}
									}		
								}	
							}
							break;
					}
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

void imprimirMenu(){
	printf("\n");
	printf("Elige una opcion para continuar:\n");
	printf("   1-Instrucciones.\n");
	printf("   2-Regitrarse.\n");
	printf("   3-Iniciar sesion para comenzar.\n");
	printf("   4-Salir.\n");
}   


int compararString(char cadena1[], char cadena2[]){
	int resul = 0, i;
	
	if(longitudString(cadena1) != longitudString(cadena2)){
		return 1;
	}
	
	for(i = 0; i < strlen(cadena1); i++){
		if(cadena1[i] != cadena2[i]){
			resul = 1;
		}
	}
	
	return resul;
}

int longitudString(char cadena[]) {
	int longitud = 0;
	
	while(cadena[longitud] != '\0') {
		longitud++;
	}
	
	return longitud;
}
