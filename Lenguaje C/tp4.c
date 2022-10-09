/*

Santiago Julián Chacón - @santichac - 2022
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#include <stdio.h>
#define CADENA_SIN_TERMINADOR -1
#define MEMORIA 50
#define TRUE 1
#define FALSE 0

int largo_cadena(char cadena[], int capacidad);
char insercion (char cadena[], int posicion, char nueva[]);
int copia_cadenas(char cadena[], char copiada[]);
int limpieza (char cadena[]);
char inversor(char cadena[], char destino[]);
int comparativa (char cadena[], char nueva[]);
int contador_alfanumerico(char cadena[]);
int contador_no_alfanumerico(char cadena[]);
char minimizar(char cadena[], char destino[]);
int palindromo(char cadena[], int inicio, int fin);

int main(int argc, char *argv[]){
    int contar = largo_cadena(argv[1], MEMORIA);
    int posicion;
    char destino[MEMORIA];
    int opcion;

    printf("Oprima 1 si quiere medir el largo de su cadena\n"
    "Oprima 2 si quiere insertar una cadena dentro de otra\n"
    "Oprima 3 si quiere reemplazar una cadena por otra\n"
    "Oprima 4 si quiere limpiar una cadena de caracteres raros\n"
    "Oprima 5 si quiere invertir su cadena\n"
    "Oprima 6 si quiere comparar sus cadenas\n"
    "Oprima 7 si quiere ver cuantos caracteres alfanumericos tiene su cadena\n"
    "Oprima 10 si quiere saber si su cadena es palindromo o no\n");
    scanf("%d", &opcion);
    
    if(opcion == 1){
        if(contar == 1){
            printf("Tu cadena tiene %d caracter\n", contar);
        } else{
            printf("Tu cadena tiene %d caracteres\n", contar);
        }
    } else if(opcion == 2){
        printf("Indique en que posicion quiere introducir una cadena: ");
        scanf("%d", &posicion);
        insercion(argv[1], posicion+1, argv[2]);
        printf("Tu nueva cadena es: %s\n", argv[1]);
    } else if(opcion == 3){
        printf("El largo de su nueva cadena es: %d\n", copia_cadenas(argv[1], argv[2]));
    } else if(opcion == 4){
        printf("Su cadena limpia tiene '%d' caracteres\n", limpieza(argv[1]));
    } else if(opcion == 5){
        inversor(argv[1], destino);
        printf("Tu cadena invertida es: %s\n", destino);
    } else if(opcion == 6){
        printf("Si las cadenas son iguales veras un '0' en pantalla, si la primera va antes que la segunda alfabeticamente veras un '-1' , de los contrario un '1': %d", comparativa(argv[1], argv[2]));
    } else if(opcion == 7){
        printf("El recuento de su cadena solo contando los caracteres alfanumericos es: %d\n", contador_alfanumerico(argv[1]));
    } else if(opcion == 8){
        printf("El recuento de su cadena sin contar sus caracteres alfanumericos es: %d\n", contador_no_alfanumerico(argv[1]));
    } else if(opcion == 9){
        minimizar(argv[1], destino);
        printf("Tu cadena en minusculas es: %s\n", destino);
    }else if(opcion == 10){
        printf("Es palindromo si el resultado es '1', no lo es si es '0': %d\n", palindromo(argv[1], 0, contar-1));
    }
    return 0;
}

int largo_cadena(char cadena[], int capacidad){
    /**
    * La funcion cuenta los caracteres de la cadena sin exceder la capacidad del arreglo indicada.
    *  @param cadena es la direccion de la cadena con la que se contaran los caracteres
    *  @pre cadena es un puntero no nulo
    *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
        y es el tamaño en memoria del arreglo
    *  @pre es un valor numerico entero positivo mayor a uno
    *  @returns int en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
        y los valores negativos, las siguientes situaciones de error:
        CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual 
        a la capacidad indicada por el argumento
    *  @post devuelve el largo de la cadena en numeros positivos, si es del mismo tamaño que
        la capacidad la funcion devolvera -1
    */
    int largo = 0;

    while(largo < capacidad && (cadena[largo] != '\0')){
        largo++;
    }
    if(largo >= capacidad){
        largo = CADENA_SIN_TERMINADOR;
    }

    return largo;
}

char insercion (char cadena[], int posicion, char nueva[]){
    /**
    * La funcion insertar una cadena de caracteres dentro de otra y devuelve la cantidad de caracteres de esta,
    * sin exceder la capacidad. Si se excede, dara como resultado -1.
    *  @param cadena es la direccion de la cadena con la que se contaran los caracteres
    *  @pre cadena es un puntero no nulo
    *  @param posicion la capacidad es un número distinto a el largo de la cadena en si 
        y es el tamaño en memoria del arreglo
    *  @pre es un valor numerico entero positivo mayor a uno
    *  @returns int en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
        y los valores negativos, las siguientes situaciones de error:
        CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual 
        a la capacidad indicada por el argumento
    *  @post devuelve el largo de la cadena en numeros positivos, si es del mismo tamaño que
        la capacidad la funcion devolvera -1
    */
    int limite = largo_cadena(cadena, MEMORIA);
    int contador = 0;
    int largo = largo_cadena(nueva, MEMORIA);
    int pega = posicion;
    char letra[MEMORIA];
    int longitud = limite + largo;

    largo = largo +posicion;

    while(contador < limite-posicion){
        letra[contador] = cadena[pega];
        pega++;
        contador++;
    }

    contador = 0;

    while(contador < largo){
        cadena[posicion] = nueva[contador];
        posicion++;
        contador++;
    }
    pega = 0;
    while(contador < longitud){
        cadena[contador] = letra[pega];
        contador++;
        pega++;
    }
    
    return *cadena;
}

int copia_cadenas(char cadena[], char copiada[]){
    int limite = largo_cadena(cadena, MEMORIA);
    int largo = largo_cadena(copiada, MEMORIA);
    int nuevo_largo;
    int contador = 0;
    int longitud;

    if(limite > largo){
        longitud = limite - largo;
        cadena = cadena+longitud;
    }

    while(contador < largo){
        cadena[contador] = copiada[contador];
        limite++;
        contador++;
    }
    nuevo_largo = largo_cadena(cadena, MEMORIA);

    if(nuevo_largo > MEMORIA){
        nuevo_largo = CADENA_SIN_TERMINADOR;
    }

    return nuevo_largo;
}

int limpieza (char cadena[]){
    int largo = largo_cadena(cadena, MEMORIA);
    int contador = 0;
    int contador_2 = 0;
    char destino[MEMORIA];

    while(contador < largo){
        if((cadena[contador] >= 65) && (cadena[contador] <= 90)){
            destino[contador_2] = cadena[contador];
            contador_2++;
        } else if((cadena[contador] >= 97) && (cadena[contador] <= 122)){
            destino[contador_2] = cadena[contador];
            contador_2++;
        } else if((cadena[contador] >= 48) && (cadena[contador] <= 57)){
            destino[contador_2] = cadena[contador];
            contador_2++;
        } else if(cadena[contador] == 32){
            destino[contador_2] = cadena[contador];
            contador_2++;    
        } else{
        }
        contador++;
    }
    destino[contador_2] = '\0';
    largo = largo_cadena(destino, MEMORIA);
    return largo;
}

char inversor(char cadena[], char destino[]){
    char largo = largo_cadena(cadena, MEMORIA);
    int contador = 0;
    int contador_2 = largo;

    while(contador < largo){
        destino[contador] = cadena[contador_2-1];
        contador++;
        contador_2--;
    }

    return *destino;
}

int comparativa (char cadena[], char nueva[]){
    int largo = largo_cadena(cadena, MEMORIA);
    int longitud = largo_cadena(nueva, MEMORIA);
    int limite;
    int contador = 0;
    int resultado = 0;

    if(largo == longitud){
        limite = largo;
    } else if(largo > longitud){
        limite = longitud;
    } else if(largo < longitud){
        limite = largo;
    }

    while(contador < limite && resultado == 0){
        if(cadena[contador] == nueva[contador]){
            contador++;
        }
        if((cadena[contador]) < (nueva[contador])){
            resultado = -1;
        } 
        if((cadena[contador]) > (nueva[contador])){
            resultado = 1;
        }
        contador++;
    }
    return resultado;
}

int contador_alfanumerico(char cadena[]){
    int largo = largo_cadena(cadena, MEMORIA);
    int contador = 0;
    int contador_2 = 0;
    char destino[MEMORIA];

    while(contador < largo){
        if((cadena[contador] >= 65) && (cadena[contador] <= 90)){
            destino[contador_2] = cadena[contador];
            contador_2++;
        } else if((cadena[contador] >= 97) && (cadena[contador] <= 122)){
            destino[contador_2] = cadena[contador];
            contador_2++;
        } else if((cadena[contador] >= 48) && (cadena[contador] <= 57)){
            destino[contador_2] = cadena[contador];
            contador_2++;
        } else if(cadena[contador] == 32){
            destino[contador_2] = cadena[contador];
            contador_2++;    
        } else{
        }
        contador++;
    }
    destino[contador_2] = '\0';
    largo = largo_cadena(destino, MEMORIA);
    return largo;
}

int contador_no_alfanumerico (char cadena[]){
    int largo = largo_cadena(cadena, MEMORIA);
    int contador = 0;
    int contador_2 = 0;
    char destino[MEMORIA];

    while(contador < largo){
        if((cadena[contador] >= 33) && (cadena[contador] <= 47)){
            destino[contador_2] = cadena[contador];
            contador_2++;
        } else if((cadena[contador] >= 91) && (cadena[contador] <= 96)){
            destino[contador_2] = cadena[contador];
            contador_2++;
        } else if((cadena[contador] >= 58) && (cadena[contador] <= 64)){
            destino[contador_2] = cadena[contador];
            contador_2++;
        } else if((cadena[contador] >= 123) && (cadena[contador] <= 255)){
            destino[contador_2] = cadena[contador];
            contador_2++;    
        } else{
        }
        contador++;
    }
    destino[contador_2] = '\0';
    largo = largo_cadena(destino, MEMORIA);
    return largo;
}

char minimizar(char texto[], char nuevoTexto[]){
    int contador = 0;
    int largo = largo_cadena(texto, MEMORIA);

    while (contador < largo){
            if ((texto[contador] >= 65) && (texto[contador] <= 90)){
                nuevoTexto[contador] = nuevoTexto[contador] + (texto[contador]+32);
            }else{
                nuevoTexto[contador] = nuevoTexto[contador] + texto[contador];
            }
        contador++;
    }
    return *nuevoTexto;
}

int palindromo(char cadena[], int inicio, int fin){
/*
Esta función verifica si una palabra es palindromo o no.
Pre: cadena es una palabra que ingresa el usuario y que desea
saber si es palindromo o no.
Post: la función devolvera True si la palabra es palindromo y False
si no es palindromo.
*/
    int resultado;

    if(inicio >= fin){
        resultado = TRUE;
    }else if (cadena[inicio] == cadena[fin]){
        return palindromo(cadena, inicio + 1, fin - 1);
    }else{
        resultado = FALSE;
    }
    return resultado;
}