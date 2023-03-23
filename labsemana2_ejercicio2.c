#include<stdio.h>
#define MAX 100
int i=0;

int tamanoInventario() // pide al usuario ingresar el tamaño del arreglo con el que trabajara
{
	int cantItems=0;

	printf("Cual sera el tamano util del Inventario?(max.100)\n");
	do{
		printf("Cantidad: ");
		scanf("%d",&cantItems);
		if (cantItems  > 100)
			printf("PUEDE TENER MAXIMO 100 ITEMS DISTINTOS\n");
	} while (cantItems > 100);
	
	return cantItems;
}

void definirMaximos(int ca, int max[ca]) // pregunta por la cantidad maxima de cada objeto que pueden tener los jugadores en conjunto
{
	int limite=0;
	
	for (i=0; i<ca; i++) // for loop preguntando por los maximos de cada objeto
	{
		printf("Cuantas copias existen del objeto %d?\n",i+1);
		printf("Cantidad: ");
		scanf("%d",&limite);
		
		max[i] = limite;
	}
}

void preguntarItems(int ca, int inv[ca], int gral[ca], int max[ca]) // for loop que pregunta cuantos objetos se tiene en cada posicion
{
	int cantInv, validez;
	for (i=0; i<ca; i++)
	{
		printf("Cuantos objetos tiene en la posicion %d?\n",i+1);
		do{
			printf("Cantidad: ");
			scanf("%d",&cantInv);
			
			if (gral[i]+cantInv > max[i]) // comprueba que el valor ingresado mas el inventario del resto de jugadores no supere el valor maximo
			{
				validez = 0;
				printf("SUPERA EL LIMITE ACTUAL DEL OBJETO (%d)\n",max[i]-gral[i]); // de ser asi se le avisa al usuario cual es el maximo actual
			}
			else
				validez = 1; // de no ser asi se continua con el siguiente objeto
		} while(validez==0); // se le pregunta al usuario hasta que ingrese un valor valido
		
		inv[i] = cantInv; // si supera la validacion el valor se guarda en su posicion correspondiente
		gral[i] += cantInv; // ademas este valor se suma al inventario general de jugadores
	}
}

void mostrarInventario(int ca, int inv[ca]) // imprime el arreglo
{
	for (i=0; i<ca; i++)
		if (inv[i] > 0)
			printf("Inv. slot %d: %d\n",i+1, inv[i]);
}

int main()
{
	int inventario1[MAX] = {0};
	int inventario2[MAX] = {0};
	int inventarioGral[MAX] = {0};
	int maximos[MAX] = {0};
	int cantItems = tamanoInventario();
	
	definirMaximos(cantItems, maximos);
	
	printf("-----JUGADOR 1-----\n");
	preguntarItems(cantItems, inventario1, inventarioGral, maximos); // inventario del jugador 1
	printf("-----JUGADOR 2-----\n");
	preguntarItems(cantItems, inventario2, inventarioGral, maximos); // inventario del jugador 2
	
	printf("-----Inventario Jugador 1-----\n");
	mostrarInventario(cantItems, inventario1);
	
	printf("-----Inventario Jugador 2-----\n");
	mostrarInventario(cantItems, inventario2);

	return 0;
}
