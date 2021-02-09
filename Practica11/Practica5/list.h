#pragma once
#define _CRT_SECURE_NO_WARNINGS

//Clase: Creación de una lista enlazada TList que tenga los siguientes metodos: 
//	   a. int Size(); // Retorna el número de elementos.
//	   b. int Push(const char *psz); // Añade la cadena a la lista.
//	   c. const char * First(); // retorna el primer elemento de la lista.
//	   d. const char *Next(); // retorna el siguiente elemento de la lista.
//	   e. const char * Pop(); // Elimina y retorna el primer elemento de la lista.
//	   f. void Reset(); // Elimina todos los elementos de la lista.


class TListNode
{
public:
	TListNode(const char* _sValue);
	~TListNode();

	const char * m_sValue;
	TListNode *m_pNext;
};

class TList
{
public:
	TList();
	~TList();

	int Size();
	void Push(const char *_sValue);
	const char* First();
	const char* Next();
	void ShowList();
	const char* Pop();
	void Reset();
	static void GetReverseList(TList& lstSrc, TList& nReturnList); //Devuelve la lista con las cadenas invertidas
	

private:
	TListNode *m_pFirst;
	TListNode *m_pCurrent;
	unsigned int m_uSize;
};