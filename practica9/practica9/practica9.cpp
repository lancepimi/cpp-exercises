
// practica9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "list.h"

int main()
{
	printf("\nPRACTICA 9 \n\n");

	TList tList;

	//EJERCICIO B
	tList.Push("Uno");
	tList.Push("Dos");
	tList.Push("Tres");
	tList.Push("Cuatro");
	tList.Push("Cinco");

	printf("EJERCICIO A\n");
	printf("List Size = %d \n", tList.Size());

	printf("\nEJERCICIO C\n");
	printf("List First = %s \n", tList.First());

	printf("\nEJERCICIO D\n");
	printf("List Next = %s \n", tList.Next());
	printf("List Next = %s \n", tList.Next());
	printf("List Next = %s \n", tList.Next());
	printf("List Next = %s \n", tList.Next());

	printf("\nEJERCICIO E\n");
	const char *sPop = tList.Pop();
	printf("List First = %s \n", sPop);
	printf("List Size = %d \n", tList.Size());

	printf("\nEJERCICIO F\n");
	tList.Reset();
	printf("Size = %d (deberia ser 0)\n", tList.Size());
}


