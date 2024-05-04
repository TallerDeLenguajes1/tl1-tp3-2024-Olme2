#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


const char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    const char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}Producto ;

int costoTotal(Producto *Productos);
typedef struct{
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
}Cliente;

int main(){
    int cantClientes;
    printf("Escriba la cantidad de clientes (hasta 5): ");
    scanf("%d", &cantClientes);
    Cliente *clientes=(Cliente*)malloc(cantClientes*sizeof(Cliente));
    char *buff=(char*)malloc(100*sizeof(char));
    time(NULL);
    for(int i=0; i<cantClientes; i++){
        printf("ID del cliente %d: ",i+1);
        scanf("%d", &clientes[i].ClienteID);
        getchar();
        printf("Nombre del cliente %d: ",i+1);
        gets(buff);
        clientes[i].NombreCliente=(char*)malloc((strlen(buff)+1)*sizeof(char));
        strcpy(clientes[i].NombreCliente,buff);
        clientes[i].CantidadProductosAPedir=rand()%5+1;
        printf("Cantidad de productos del cliente %d: %d\n",i+1,clientes[i].CantidadProductosAPedir);
        clientes[i].Productos=(Producto*)malloc(clientes[i].CantidadProductosAPedir*sizeof(Producto));
        for(int j=0; j<clientes[i].CantidadProductosAPedir; j++){
            clientes[i].Productos[j].ProductoID=j+1;
            clientes[i].Productos[j].Cantidad=rand()%11;
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand()%5];
            clientes[i].Productos[j].PrecioUnitario=rand()%91+10;
        }
    }
    for(int i=0;i<cantClientes;i++){
        int total=0;
        printf("\n\n\tInformación del cliente\nNOMBRE: ");
        puts(clientes[i].NombreCliente);
        printf("ID: %d\n",clientes[i].ClienteID);
        printf("CANTIDAD DE PRODUCTOS QUE LLEVA: %d\n",clientes[i].CantidadProductosAPedir);
        printf("LISTA DE PRODUCTOS:\n");
        for(int j=0;j<clientes[i].CantidadProductosAPedir;j++){
            int totalProd=costoTotal(&clientes[i].Productos[j]);
            printf("---------------------------------------\n\tID DEL PRODUCTO: %d\n",clientes[i].Productos[j].ProductoID);
            printf("NOMBRE DEL PRODUCTO: %s\n",clientes[i].Productos[j].TipoProducto);
            printf("PRECIO POR UNIDAD: $%.2f\n",clientes[i].Productos[j].PrecioUnitario);
            printf("CANTIDAD: %d\n",clientes[i].Productos[j].Cantidad);
            printf("TOTAL PRODUCTO: $%d\n",totalProd);
            total+=totalProd;
        }
        printf("---------------------------------------\n\tTOTAL A PAGAR: $%d",total);
        free(clientes[i].Productos);
        free(clientes[i].NombreCliente);
    }
    free(clientes);
    free(buff);
    return 0;
}

int costoTotal(Producto *Productos){
    return Productos->PrecioUnitario*Productos->Cantidad;
}