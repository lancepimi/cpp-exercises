#include "ListNode.h"

TListNode::TListNode(IListElement* _pValue)
	: m_pValue(_pValue)
	, m_pNext(nullptr)
{
}