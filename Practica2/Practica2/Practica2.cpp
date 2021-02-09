
#include <iostream>

using namespace std;

int main()
{
	cout << "PRACTICA 2\n\n";

	cout << "EJERCICIO A";
	unsigned int uValue = 0xA4F012D4;
	unsigned char* pValue = reinterpret_cast<unsigned char*>(&uValue);

	unsigned char byte1 = *pValue;
	unsigned char byte2 = *(pValue + 1); 
	unsigned char byte3 = *(pValue + 2);
	unsigned char byte4 = *(pValue + 3);

	cout << hex << "integer: " << uValue << endl;
	printf("byte1: %02X\n", byte1);
	printf("byte2: %02X\n", byte2);
	printf("byte3: %02X\n", byte3);
	printf("byte4: %02X\n", byte4);


	cout << "\nEJERCICIO B\n";
	int tabla[] = { 1, 3, 2, 5, 3, static_cast<int>(0xFFFFFFFF), 2 };
	int* pInt = tabla;
	int totalSize = sizeof(tabla) / sizeof(int);
	int maxNum = 0;

	for (int i = 0; i < totalSize; i++)
	{
		if (*pInt > maxNum) {
			maxNum = *pInt;
		}
		pInt++;
	}
	cout << "El numero maximo es: " << maxNum << endl;


	cout << "\nEJERCICIO C\n";

	unsigned char* pValue2 = reinterpret_cast<unsigned char*>(&tabla); 
	int totalSize2 = sizeof(tabla) / sizeof(char);
	unsigned char uByteMax = *pValue2;

	for (int j = 0; j < totalSize2; j++)
	{
		printf("pValue : %02X\n", *pValue2); 

		if (*pValue2 > uByteMax) {

			uByteMax = *pValue2;
		}
		pValue2++;
	}
	printf("El numero maximo es: : %02X\n", uByteMax);


	cout << "\nEJERCICIO D\n";

	char table[] = "Hola";
	char* pStart = table;
	int size = sizeof(table);
	char* pEnd = table + (size - 2); //el sizeof no tiene en cuenta el 0. Por eso aquí es -2

	cout << "Original char array: " << table << endl;

	for (int i = 0; i < size; i++) {

		if (pStart < pEnd) {
			int temp = *pEnd;
			*pEnd = *pStart;
			*pStart = temp;
		}

		pStart++;
		pEnd--;
	}

	cout << "Reverse char array: " << table << endl;

}


