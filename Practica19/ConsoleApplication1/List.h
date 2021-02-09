#pragma once
#include "ListNode.h"
#include <assert.h>

template <typename T>
class TList
{
public:
	TList()
		: m_pFirst(nullptr)
		, m_uSize(0)
		, m_pCurrent(nullptr)
	{
	};

	~TList()
	{
	};

	//Retorna el numero de elementos
	int Size()
	{
		unsigned int uSize(0);
		TListNode<T>* pCurrentNode(m_pFirst);
		while (pCurrentNode)
		{
			++uSize;
			pCurrentNode = pCurrentNode->m_pNext;
		}
		assert(m_uSize == uSize);
		return m_uSize;
	};

	//Añade la cadena a la lista
	int Push(T* _pValue)
	{
		TListNode<T>* pNewListNode = new TListNode<T>(_pValue);
		pNewListNode->m_pNext = m_pFirst;
		m_pFirst = pNewListNode;
		return ++m_uSize;
	};

	// Retorna el primer elemento de la lista
	T* First()
	{
		m_pCurrent = m_pFirst;
		return m_pFirst->m_pValue;
	};

	// Retorna el siguiente elemento de la lista
	T* Next()
	{
		//Modo Pro:
		//m_pCurrent = m_pCurrent ? m_pCurrent->m_pNext : nullptr;
		//return m_pCurrent ? m_pCurrent->m_pValue : nullptr;

		if (m_pCurrent == nullptr)
		{
			return nullptr;
		}

		m_pCurrent = m_pCurrent->m_pNext;

		if (m_pCurrent == nullptr)
		{
			return nullptr;
		}

		return m_pCurrent->m_pValue;
	};

	//Elimina y retorna el primer elemento de la lista
	//Si se estaba iterando la lista y el utlimo elemnto devuelto era m_pFirst lo ponemos a null
	T* Pop()
	{
		T* pRetValue(nullptr);
		if (m_pFirst)
		{
			//Store the return value
			pRetValue = m_pFirst->m_pValue;
			//FIX iterator
			m_pCurrent = nullptr;
			//Delete the first and pint m_pFirst to the next
			TListNode<T>* pFirst(m_pFirst);
			m_pFirst = m_pFirst->m_pNext;
			delete pFirst;
			//Decrement size
			m_uSize--;
		}
		return pRetValue;
	};

	//Elimina todos los elementos de la lista
	void Reset()
	{
		//FIX iterator
		m_pCurrent = nullptr;
		while (Pop() != nullptr);
	};

private:
	TListNode<T>* m_pFirst;
	unsigned int m_uSize;
	//For iteration
	TListNode<T>* m_pCurrent;
};