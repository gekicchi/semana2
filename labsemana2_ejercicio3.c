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

void definirMaximos(int ca, int max[ca]) // pregunta por la cantidad maxima de cada objeto que puede tener el jugador
{
	int limite=0;
	
	for (i=0; i<ca; i++)
	{
		printf("Cuantas copias existen del objeto %d?\n",i+1);
		printf("Cantidad: ");
		scanf("%d",&limite);
		
		max[i] = limite;
	}
}

void preguntarItems(int ca, int inv[ca], int max[ca]) // for loop que pregunta cuantos objetos se tiene en cada posicion
{
	int cantInv, validez;
	for (i=0; i<ca; i++)
	{
		printf("Cuantos objetos tiene en la posicion %d?\n",i+1);
		do{
			printf("Cantidad: ");
			scanf("%d",&cantInv);
			
			if (cantInv > max[i]) // comprueba que no se sobrepase el limite
			{
				validez = 0;
				printf("SUPERA EL LIMITE ACTUAL DEL OBJETO (%d)\n",max[i]); // avisa al jugador de cual es el limite que puede tener del objeto
			}
			else
				validez = 1;
		} while(validez==0); // vuelve a preguntar en caso que supere el maximo
		
		inv[i] = cantInv;
	}
}

void mostrarInventario(int ca, int inv[ca]) // imprime el arreglo
{
	for (i=0; i<ca; i++)
		printf("Inv. slot %d: %d\n",i+1, inv[i]);
}

void agregarObjeto(int ca, int inv[ca], int max[ca]) // +1 al objeto deseado
{
	int obj;
	do{
		printf("Que objeto querria conseguir?\n"); // pregunta la posicion del objeto a aumentar
		printf("Objeto: ");
		scanf("%d",&obj);
		if (obj <= 0|| obj > ca)
			printf("OBJETO FUERA DE RANGO\n");
	} while (obj > 0 && obj <= ca); // comprueba que el objeto indicado se encuentre dentro del inventario usado
	
	if (inv[obj-1]+1 <= max[obj-1]) // comprueba que agregar 1 del tipo de objeto no sobrepase el limite
	{
		inv[obj-1]++;
		printf("Jugador ha recibido objeto en posicion %d\n",obj);
	}
	else
		printf("RECIBIR MAS OBJETOS DE ESTE TIPO SOBREPASA EL LIMITE (%d)\n",max[obj-1]);
}

void eliminarObjeto(int ca, int inv[ca]) // -1 al objeto deseado
{
	int obj;
	do{
		printf("Que objeto querria eliminar?\n"); // pregunta la posicion del objeto a disminuir
		printf("Objeto: ");
		scanf("%d",&obj);
		if (obj <= 0|| obj > ca)
			printf("OBJETO FUERA DE RANGO\n");
	} while (obj > 0 && obj <= ca); // comprueba que el objeto se encuentre dentro del inventario usado
	
	if (inv[obj-1]-1 >= 0) // comprueba que restar 1 del tipo de objeto no vaya a los numeros negativos
	{
		inv[obj-1]--;
		printf("Jugador ha eliminado objeto en posicion %d\n",obj);
	}
	else
		printf("NO PUEDE ELIMINAR OBJETO PUES CARECE DE ESTE\n");
}

int main()
{
	int inventario[MAX] = {0};
	int maximos[MAX] = {0};
	int cantItems = tamanoInventario();
	
	definirMaximos(cantItems, maximos);
	
	preguntarItems(cantItems,inventario,maximos);
	mostrarInventario(cantItems, inventario);
	
	agregarObjeto(cantItems, inventario, maximos);
	eliminarObjeto(cantItems, inventario);
	
	mostrarInventario(cantItems, inventario);
	
	return 0;
}
