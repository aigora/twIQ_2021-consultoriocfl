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
			    printf("El cuestionario consta varias preguntas que se reparten en tres bloques segun tu modalidad: ciencias, ciencias sociales y humanidades , y arte.\n");
			    printf("Son preguntas rapidas y sencillas que deben ser respondidas con si o no.\n ");
			    printf("Para poder registrarte unicamente necesitamos tus datos personales y correo electronico.\n");
				printf("Y recuerda no olvidar tu nombre de usuario y contraseña porque lo necesitaras para iniciar sesion.\n ");
			    
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
			    	if( (compararString(usuario, usuarios[i].usuario)==0) && (compararString(contrasennya, usuarios[i].contrasennya)==0) )   {
			    		printf("\nBienvenido de nuevo %s\n", usuario);
			    		sesion_iniciada=1;
					}
				}
				
				if(sesion_iniciada==1) {
					//Preguntas 	
					printf("¿Que modalidad estas estudiando?\n");
					printf("1.Ciencias\n2.Humanidades y Ciencias Sociales\n3.Artes\n");
					scanf("%d", &opcion2);
					
					switch(opcion2){
						case 1:				
					    printf("¿Consideras que te gusta ayudar a las personas?(Si o No)\n");
							fflush(stdin);
							scanf("%s",respuesta);
							if(compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0) {
								printf("¿Tratas de entender el comportamiento de tus amigos cuando surge un problema?(Si o No)\n");
								fflush(stdin);
								scanf("%s",respuesta);
								if(compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0) {
									printf("Podrias estudiar: PSICOLOGIA \n");
								}
								else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0) {
									printf("¿Te gustaria realizar experimentos quimicos y bioquimicos?(Si o No)\n");
									fflush(stdin);
									scanf("%s",respuesta);	
									if(compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0) {
										printf("Podrias estudiar: BIOQUIMICA o BIOQUIMICA Y BIOLOGIA MOLECULAR\n");
									}
									else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0) {
										printf("¿Te gustaria ser capaz de realizar diagnosticos y preparar tratamientos para una enfermedad?(Si o No)\n");
										fflush(stdin);
										scanf("%s",respuesta);
										if(compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0) {
											printf("Podrias estudiar:  MEDICINA \n");
										}
										 else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0) {
											printf("¿Te ves siendo capaz de estudiar el funcionamiento de maquinas nuevas?¿ Y de crearlas?(Si o No)\n");
											fflush(stdin);
											scanf("%s",respuesta);	
											if(compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0) {
												printf("Podrias estudiar: INGENIERIA INDUSTRIAL \n");
											}
											 else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0) {
												printf("Podrias estudiar: BIOTECNOLOGIA \n");}	
											}
										}		
									}
								}
								else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0) {
								printf("¿Tienes facilidad para resolver problemas numericos?(Si o No)\n");
								fflush(stdin);
								scanf("%s",respuesta);	
								if(compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0) {
									printf("Podrias estudiar:  MATEMATICAS \n");
								}
								else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0) {
									printf("¿Consideras que tienes una buena relacion con los animales? ¿ Te gusta ayudarles?(Si o No)\n");
									fflush(stdin);
									scanf("%s",respuesta);
									if(compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0) {
										printf("Podrias estudiar: VETERINARIA \n");
									}
									else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0) {
										printf("¿Te interesa saber como funcionan aparatos que usas a diario como el celular, la television o los ordenadores?(Si o No)\n");
										fflush(stdin);
										scanf("%s",respuesta);	
										if(compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0) {
											printf("Podrias estudiar:INGENIERIA INFORMATICA \n");
										}
										else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0) {
											printf("Podrias estudiar:  DISEÑO INDUSTRIAL Y DESAROLLO DE PRODUCTO  \n");	}	
									}
											
								}	
							}
						break;
						
						case 2:
							printf("Te interesa conocer el pasado para asi enterder el presente?(Si o No)\n");
							fflush(stdin);
							scanf("%s", respuesta);
							if (compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0){
								printf("¿Te gusta leer? ¿Dedicas tiempo a lectura?\n¿Te gustan las novelas clasicas como EL Quijote, La Casa de Bernanda Alba? (SI/NO)\n");
								fflush(stdin);
								scanf("%s", respuesta);
								if (compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0){
									printf("¿Te gustaria aprender otro idioma con profundidad?(Si O No)\n");
									fflush(stdin);
									scanf("%s", respuesta);
									if (compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0){
										printf("Podrias estudiar: ESTUDIOS INGLESES, ESTUDIOS SEMITICOS E ISLAMICOS, FILOLOGIA CLASICA  o TRADUCCION E INTERPRETACION \n");
									}
									else if (compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0){
										printf("Podrias estudiar:ESPANOL,LENGUA Y LITERATURA ,LENGUAS MODERNAS Y SUS LITERATURAS o LITERATURA GENERAL Y COMPARADA \n");
									}
								}
								else if (compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0){
									printf("¿Frecuentas museos historicos y/o arquelogicos?(Si o No)\n");
									fflush(stdin);
									scanf("%s", respuesta);
									if (compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0){
										printf("Podrias estudiar: HISTORIA O ARQUEOLOGIA \n");
									}
									else if (compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0){
										printf("Podrias estudiar: FILOSOFIA o CIENCIAS DE LAS RELIGIONES.\n");
									}
								}
							}
							else if (compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0){
								printf("¿Te consideras una persona creativa, imaginativa y curiosa?(Si o No)\n");
								fflush(stdin);
								scanf("%s", respuesta);
								if(compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0){
									printf("Podrias estudiar: PERIODISMO  o PUBLICIDAD Y RELACIONES PUBLICAS.\n");
								}
								else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0){
									printf("¿Te sientes comodo al hablar en publico?(Si o No)\n");
									fflush(stdin);
									scanf("%s", respuesta);
									if (compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0){
										printf("¿Te interesan los debates sobre temas de actualidad?(Si o No)\n");
										fflush(stdin);
										scanf("%s", respuesta);
										if(compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0){
											printf("Pordias estudiar: CIENCIAS POLITICAS o DERECHO.\n");
										}
										else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0){
											printf("Podrias estudiar: ANTROPOLOGIA SOCIAL Y CULTURAL, MAGISTERIO INFANTIL, MAGISTERIO EN EDUCACION PRIMARIA (opcion en bilingue), PEDAGOGIA, SOCIOLOGIA  o TRABAJO SOCIAL.\n");
										}
									}
									else if (compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0){
										printf("¿Te gustaria dirigir tu propia empresa?(Si o No)\n");
	     							    fflush(stdin);
										scanf("%s", respuesta);
										if (compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0){
											printf("¿Te manejas bien con cuentas matematicas?(Si o No)\n");
											fflush(stdin);
											scanf("%s", respuesta);
											if (compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0){
												printf("Podrias estudiar: ECONOMIA Y FINANZAS.\n");
											}
											else if (compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0){
												printf("Podrias estudiar: ADMINISTRACION Y DIRECCION DE EMPERESAS (opcion en ingles) o RELACIONES INTERNACIONALES\n");
											}
										}
										else if (compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0){
											printf("Podrias estudiar: COMERCIO o TURISMO.\n");
										}
									}
								}
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
									printf("Podrias estudiar: DANZA\n");
								}
								else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0) {
									printf("¿Disfrutas componiendo obras y tocando instrumentos?(Si o No)\n");
									fflush(stdin);
									scanf("%s",respuesta);	
									if(compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0) {
										printf("Podrias estudiar: MUSICOLOGIA\n");
									}
									else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0) {
										printf("¿Te interesa la evolucion artistica y cultural del ser humano?(Si o No)\n");
										fflush(stdin);
										scanf("%s",respuesta);
										if(compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0) {
											printf("Podrias estudiar: HISTORIA DEL ARTE\n");
										}
										else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0) {
											printf("¿Tienes la capacidad de la creacion y analisis de las artes visuales?(Si o No)\n");
											fflush(stdin);
											scanf("%s",respuesta);	
											if(compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0) {
												printf("Podrias estudiar: BELLAS ARTES\n");
											}
											else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0) {
												printf("Podrias estudiar: ARTES ESCENICAS\n");	
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
									printf("Podrias estudiar: DISEÑO GRAFICO\n");
								}
								else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0) {
									printf("¿Dedicas tu tiempo libre a la moda?(Si o No)\n");
									fflush(stdin);
									scanf("%s",respuesta);
									if(compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0) {
										printf("Podrias estudiar: DISEÑO DE MODA\n");
									}
									else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0) {
										printf("¿Tu sueño es crear arte con la tecnologia?(Si o No)\n");
										fflush(stdin);
										scanf("%s",respuesta);	
										if(compararString(respuesta, "Si") == 0 || compararString(respuesta, "si") == 0) {
											printf("Podrias estudiar: DISEÑO DIGITAL\n");
										}
										else if(compararString(respuesta, "No") == 0 || compararString(respuesta, "no") == 0) {
											printf("Podrias estudiar: DISEÑO DE INTERIORES\n");	
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
			    printf("Esperamos que te haya sido de gran ayuda este cuestionario.\n");
			    printf("Recuerda que la decision final es la tuya, la mas importante.\n");
			    
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
	
	for(i = 0; i < longitudString(cadena1); i++){
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
