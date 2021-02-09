#pragma once
#include "ListNode.h"

class TList
{
public:
	TList();
	~TList();

	//Retorna el numero de elementos
	int Size();
	//Añade la cadena a la lista
	int Push(IListElement* _pValue); 
	// Retorna el primer elemento de la lista
	IListElement* First(); 
	// Retorna el siguiente elemento de la lista
	IListElement* Next(); 
	//Elimina y retorna el primer elemento de la lista
	//Si se estaba iterando la lista y el utlimo elemnto devuelto era m_pFirst lo ponemos a null
	IListElement* Pop();
	//Elimina todos los elementos de la lista
	void Reset(); 

private:
	TListNode* m_pFirst;
	unsigned int m_uSize;
	//For iteration
	TListNode* m_pCurrent;
};

