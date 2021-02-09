
#include "list.h"
#include <assert.h>
#include <iostream>


TList::TList()
	: m_pFirst(nullptr)
	, m_uSize(0)
	, m_pCurrent(nullptr)
{
}

TListNode::TListNode( const char *_sValue) 
	: m_sValue(_sValue)
	, m_pNext(nullptr)
{

}

TList::~TList() 
{

}

int TList::Size() 
{
	return m_uSize;
}

void TList::Push(const char *_sValue) 
{
	if (m_pFirst == nullptr)
	{
		m_pFirst = new TListNode(_sValue); // Reservo espacio en memoria para un nuevo nodo
	}
	else
	{
		TListNode *pNewListNode = new TListNode(_sValue); //Creo un nuevo nodo 
		pNewListNode->m_pNext = m_pFirst; //Le paso la dirección del anterior nodo al puntero que referencia el siguiente nodo
		m_pFirst = pNewListNode; //Hacemos que m_pCurrent se iguale al último nodo de la lista.
	
	}
		++m_uSize;
}

const char* TList::First()
{
	m_pCurrent = m_pFirst;
	return m_pFirst->m_sValue;
}

const char* TList::Next()
{
	if (m_pCurrent->m_pNext == nullptr)
	{
		return nullptr;
	}
	
	m_pCurrent = m_pCurrent->m_pNext;
	return m_pCurrent->m_sValue;
}

const char* TList::Pop()
{
	const char* pRetValue(nullptr);
	if (m_pFirst)
	{
		// Store the return value
		pRetValue = m_pFirst->m_sValue;
		// FIX iterator
		m_pCurrent = nullptr;
		// Delete the first and point m_pFirst to the next
		TListNode* pFirst(m_pFirst);
		m_pFirst = m_pFirst->m_pNext;
		delete pFirst;
		// Decrement size
		m_uSize--;
	}
	return pRetValue;
}

void TList::Reset() //Elimina todo
{
	m_pCurrent = nullptr;
	while (Pop() != nullptr){}
}