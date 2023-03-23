#include<stdio.h>
#define MAX 100
int i=0;

int tamanoInventario() // pide al usuario ingresar el tamaño del arreglo con el que trabajara
{
	int cantItems=0;

	printf("Cuantos items distintos tiene?(max.100)\n");
	do{
		printf("Cantidad: ");
		scanf("%d",&cantItems);
		if (cantItems  > 100)
			printf("PUEDE TENER MAXIMO 100 ITEMS DISTINTOS\n");
	} while (cantItems > 100);
	
	return cantItems;
}

void preguntarItems(int ca, int inv[ca]) // do-while loop que pregunta cuantos objetos tiene en cada posicion
{
	int cantInv;
	for (i=0; i<ca; i++)
	{
		printf("Cuantos objetos tiene en la posicion %d?\n",i+1);
		do{
			printf("Cantidad: ");
			scanf("%d",&cantInv);
			if (cantInv <= 0)
				printf("DEBERIA TENER AL MENOS 1 OBJETO\n");
		} while (cantInv <= 0); // en este caso no se permite al usuario tener 0 de un objeto
		
		inv[i] = cantInv;
	}
}

void mostrarInventario(int ca, int inv[ca]) // imprime el arreglo
{
	for (i=0; i<ca; i++)
		if (inv[i] > 0)
			printf("Inv. slot %d: %d\n",i+1,inv[i]);
}

int main()
{
	int inventario[MAX] = {0};
	int cantItems = tamanoInventario();
	
	preguntarItems(cantItems, inventario);
	mostrarInventario(cantItems, inventario);
	
	return 0;
}
