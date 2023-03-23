#include<stdio.h>
#define MAX 100
int i=0;
int j=0;

int tamanoHospital() // pide al usuario ingresar el tamaño del arreglo con el que trabajara
{
	int cantPac=0;

	printf("Cuantas habitaciones cuentan con pacientes?(max.100)\n");
	do{
		printf("Cantidad: ");
		scanf("%d",&cantPac);
		if (cantPac  > 100)
			printf("EL HOSPITAL SOLO TIENE 100 HABITACIONES\n");
	} while (cantPac > 100);
	
	return cantPac; 
}

void registrarPacientes(int ca, int edad[ca], float tCel[ca], float tFah[ca], int fie[ca]) // pide edad y 
{	
	for (i=0; i<ca; i++)
	{
		int eleccion=0;
		float temperatura=0.0;
		float promedio=0.0;
		
		printf("----------PACIENTE HABITACION %d----------\n",i+1);
		// registro de edad validando que sea mayor a 0
		do{
			printf("Edad Paciente: ");
			scanf("%d",&edad[i]);
			if (edad[i] <= 0)
				printf("INGRESE EDAD REAL\n");
		} while (edad[i] <= 0);
		
		// pregunta si se trabajara con celsius o fahrenheit
		printf("Como Ingresara Temperaturas?\n");
		printf("[1] Celsius \t[2] Fahrenheit\n");
		do{
			printf("Eleccion: ");
			scanf("%d",&eleccion);
			if (eleccion != 1 && eleccion != 2)
				printf("ELECCION INVALIDA\n");
		} while (eleccion != 1 && eleccion != 2);
		
		// pide la temperatura de la semana
		for (j=0; j<7; j++)
		{
			printf("Temperatura dia %d: ",j+1);
			scanf("%f",&temperatura);
			
			if (temperatura != 37.5 && eleccion == 1)
				fie[i]++;
			else if (temperatura != 99.5 && eleccion == 2)
				fie[i]++;
			
			promedio += temperatura;
		}
		
		if (eleccion == 1) // si trabaja con celsius divide esta en 7 y la guarda, luego a transforma a fahrenheit y la guarda
		{
			tCel[i] = promedio/7;
			tFah[i] = (tCel[i] * 9/5) + 32;
		}
		else // al reves de arriba
		{
			tFah[i] = promedio/7;
			tCel[i] = (tFah[i]-32) * 5/9;
		}
	}
}

void mostrarPacientes(int ca, int edad[ca], float tCel[ca], float tFah[ca], int fie[ca]) // imprime el arreglo
{
	for (i=0; i<ca; i++)
	{
		printf("-------------------------PACIENTE HABITACION %d-------------------------\n",i+1);
		printf("Edad: %d \tTemp.Celsius: %.2f\tTemp.Fahrenheit: %.2f\tFiebre: %d dias\n\n",edad[i], tCel[i], tFah[i], fie[i]);
	}
}
int main()
{
	int edades[MAX] = {0};
	int fiebre[MAX] = {0};
	float tempCelsius[MAX] = {0.0};
	float tempFahren[MAX] = {0.0};
	int cantPacientes = tamanoHospital();
	
	registrarPacientes(cantPacientes, edades, tempCelsius, tempFahren, fiebre);
	mostrarPacientes(cantPacientes, edades, tempCelsius, tempFahren, fiebre);
	
	return 0;
}
