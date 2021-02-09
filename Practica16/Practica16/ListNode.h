#pragma once
#include "ListElement.h"
class TListNode
{
public:
	TListNode(IListElement* _pValue);
	IListElement* m_pValue;
	TListNode* m_pNext;

};

