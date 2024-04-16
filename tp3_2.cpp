#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*2) Una empresa necesita simular la producción de los próximos 5 años para tal fin necesita
generar una matriz (estática) de 5x12 donde cada fila corresponde a un año y cada columna
es un mes. Ud. debe realizar las siguientes tareas:
a. Cargue dicha matriz con valores aleatorios entre 10000 y 50000.
b. Muestre por pantalla los valores cargados
c. Saque el promedio de ganancia por año y muestrelos por pantalla
d. Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de
cuándo ocurrió.
*/

int main(){
    int produccion[5][12], i,j,mayor,ano, mes;
    float suma,promedio;
    srand(time(NULL));
    mayor=0;
    for(i=0; i<5; i++){
        printf("(");
        suma=0;
        for(j=0; j<12; j++){
            produccion[i][j]=10000+rand()%40001;
            printf(" %d ",produccion[i][j]);
            suma+=produccion[i][j];
            if(produccion[i][j]>mayor){
                mayor=produccion[i][j];
                ano=i+1;
                mes=j+1;
            }
        }
        
        printf(") Promedio de ganancia: %.2f \n", promedio=suma/12);
    }
    printf("La mayor ganancia se produjo en el mes %d del año %d", mes, ano);
    return 0;
}
