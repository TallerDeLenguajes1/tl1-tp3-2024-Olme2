#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*5) Modifique el ejercicio nro 3 para que, en lugar de ingresar un número fijo de nombres, el
usuario pueda indicar previamente la cantidad de nombres que ingresará a continuación.
*/

int main(){
    int cantidad;
    char *buff=(char*)malloc(100*sizeof(char));
    char **vector, vectori;
    printf("¿Cuantos nombres va a escribir?\n");
    scanf("%d",&cantidad);
    getchar();
    vector=(char**)malloc(cantidad*sizeof(char*));
    printf("Escriba %d nombres:\n",cantidad);
    for(int i=0; i<cantidad; i++){
        gets(buff);
        vector[i]=(char*)malloc((strlen(buff)+1)*sizeof(char));
        strcpy(vector[i], buff);
    }
    printf("Los nombres escritos son:\n");
    for(int i=0; i<cantidad;i++){
        printf("%d: %s\n",i+1,vector[i]);
        free(vector[i]);
    }
    free(buff);
    free(vector);
    return 0;
}