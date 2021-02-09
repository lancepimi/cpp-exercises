

#include <iostream>
#include <stdarg.h>
using namespace std;

int AddThemAll(int numargs, ...) {

	va_list listPointer;
	va_start(listPointer, numargs);

	int iSum = 0;
	
	for (int i = 0; i < numargs; ++i) {

		int arg = va_arg(listPointer, int);

		printf("arg[%d] = %d\n", i, arg);

		iSum += arg;
		
	}

	pintf("TTOTAL = %d", iSum);
	iSUm += arg;
}

int main()
{
	AddThemAll(3, 4, 20, 10);
}
