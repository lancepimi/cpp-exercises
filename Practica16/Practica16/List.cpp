#include "List.h"
#include <assert.h>

TList::TList()
	: m_pFirst(nullptr)
	, m_uSize(0)
	, m_pCurrent(nullptr)
{
}

TList::~TList()
{
}

int TList::Size()
{
	unsigned int uSize(0);
	TListNode* pCurrentNode(m_pFirst);
	while (pCurrentNode)
	{
		++uSize;
		pCurrentNode = pCurrentNode->m_pNext;
	}
	assert(m_uSize == uSize);
	return m_uSize;
}

int TList::Push(IListElement* _pValue)
{
	TListNode* pNewListNode = new TListNode(_pValue);
	pNewListNode->m_pNext = m_pFirst;
	m_pFirst = pNewListNode;
	return ++m_uSize;
}

IListElement* TList::First()
{
	m_pCurrent = m_pFirst;
	return m_pFirst->m_pValue;
}

IListElement* TList::Next()
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
}

IListElement* TList::Pop()
{
	IListElement *pRetValue(nullptr);
	if (m_pFirst)
	{
		//Store the return value
		pRetValue = m_pFirst->m_pValue;
		//FIX iterator
		m_pCurrent = nullptr;
		//Delete the first and pint m_pFirst to the next
		TListNode* pFirst(m_pFirst);
		m_pFirst = m_pFirst->m_pNext;
		delete pFirst;
		//Decrement size
		m_uSize--;
	}
	return pRetValue;
}

void TList::Reset()
{
	//FIX iterator
	m_pCurrent = nullptr;
	while (Pop() != nullptr);
}
