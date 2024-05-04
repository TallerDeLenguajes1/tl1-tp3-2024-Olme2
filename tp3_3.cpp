#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*3) Escriba un programa que solicite 5 nombres, los cargue en un vector de punteros char y una
vez cargados sean listados por pantalla (Todo implementando reserva dinámica de memoria)
(Lea las notas 1 y 2)
*/

int main(){
    char *buff=(char*)malloc(100*sizeof(char));
    char *vector[5];
    printf("Escriba 5 nombres:\n");
    for(int i=0; i<5; i++){
        gets(buff);
        vector[i]=(char*)malloc((strlen(buff)+1)*sizeof(char));
        strcpy(vector[i], buff);
    }
    printf("Los nombres escritos son:\n");
    for(int i=0; i<5;i++){
        printf("%d: %s\n",i+1,vector[i]);
        free(vector[i]);
    }
    free(buff);
    return 0;
}