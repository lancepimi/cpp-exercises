
#include <iostream>

class CParentNoVirtual
{
public:
	CParentNoVirtual() {  }
	~CParentNoVirtual() { }

	void Initialize() { Prueba(); }
	void Prueba() { printf("Llamando a Prueba() en CParentNoVirtual\n"); }

	int i = 2;
};

class CParent
{
public:
	CParent() { printf("Creando CParent\n"); }
	virtual ~CParent() { printf("Destruyendo CParent\n"); }

	void Initialize() { Prueba(); }
	virtual void Prueba() { printf("Llamando a Prueba() en CParent\n"); }

	int i = 2;
};

class CA : public CParent
{
public:
	CA() { printf("Creando CA\n"); }
	virtual ~CA() { printf("Destruyendo CA\n"); }

	virtual void Prueba() override { printf("Llamando a Prueba() en CA\n"); }

	float f = 37.f;
};

class CB : public CA
{
public:
	CB() { printf("Creando CB\n"); }
	virtual ~CB() { printf("Destruyendo CB\n"); }

	virtual void Prueba() override { printf("Llamando a Prueba() en CB\n"); }

	int j = 967;
};

int main()
{
	printf("\nPRACTICA 14\n\n");

	printf("EJERCICIO A\n");
	//Esto depende del compilador. En 32 bits tenemos los siguientes resultados
	printf("sizeof CParentNoVirtual = %d\n", sizeof(CParentNoVirtual)); // vpointer Solamente guarda la iunformación de la clase
	printf("sizeof CParent = %d\n", sizeof(CParent)); // necesita 4 bytes para su tabla de vpointer y otros 4 para su informació
	printf("sizeof CParent = %d\n", sizeof(CA)); // necesita 4 bytes su información, otros 4 para los datos heredados de CParent y otros 4 para su tabla de vpointer
	printf("sizeof CParent = %d\n", sizeof(CB)); // 4 bytes para información, 8 para los datos heredados de CParent y CA, y 4 para su tabla de vpointer
	
	printf("\nEJERCICIO B\n");
	printf("La localizacion de tabla de funciones virtuales depende del compilador pero por lo general suele ser el primer elemento (offset 0) del struct o clase generado. \n");
	
	printf("\nEJERCICIO C\n");
	printf("Depende del compilador. En este caso 4 bytes pero en 64 bits serian 8 bytes. \n");
	
	printf("\nEJERCICIO D\n");
	printf("Se invocaran las funciones al crearse el objeto. Esto puede provocar errores si se ejecuta algo que aun no esta creado. Es bastante peligroso. \n");
	
	printf("\nEJERCICIO D\n");
	CB* pB = new CB();
	CParentNoVirtual* pNoVir = new CParentNoVirtual();
	printf("\nPor nuestra parte, en la virtual hay que definir la funcion en la base e implementarla en la derivada. \n");
	printf("Por parte del compilador, debe crear cada clase para despues ejecutar la funcion que le hayamos pedido. \n\n");

	pNoVir->Prueba();
	pB->Prueba();

	printf("\n");

	delete pB;
}
