#include "list.h"

CList::CList()
{
  m_pHead = 0;
}
CList::~CList()
{
  while(!isEmpty()) {
    remove(0);
  }
}
void CList::insert(double value)
{
  CListItem * pNewItem = new CListItem();
  pNewItem->m_fValue = value;
  pNewItem->m_pNext = 0;
  if(isEmpty()) {
    m_pHead = pNewItem;
  } else {
    //insert at head
    pNewItem->m_pNext = m_pHead;
    m_pHead = pNewItem;
  }
}
void CList::set(double value, int index)
{
  CListItem * pCursor = m_pHead;
  for (int nCursor = 0; pCursor != 0 && index > nCursor; nCursor++) {
    pCursor = pCursor->m_pNext;
  } 
  if (pCursor != 0) {
    pCursor->m_fValue = value;
  }
}
double CList::get(int index)
{
  CListItem * pCursor = m_pHead;
  for (int nCursor = 0; pCursor != 0 && index > nCursor; nCursor++) {
    pCursor = pCursor->m_pNext;
  } 
  if (pCursor != 0) {
    return pCursor->m_fValue;
  } else {
    return 0;
  }
}
void CList::remove(int index)
{
  CListItem *pPrev = 0,* pCursor = m_pHead;
  for (int nCursor = 0; pCursor != 0 && index != nCursor; nCursor++) {
    pPrev = pPrev;
    pCursor = pCursor->m_pNext;
  } 
  if (pPrev != 0) {
    pPrev->m_pNext = pCursor->m_pNext;
    delete pCursor;
  } else {
    m_pHead = pCursor->m_pNext; //=>m_pHead = m_pHead->m_pNext
    delete pCursor;
  }
  
}
int CList::size()
{
  int nSize = 0;
  CListItem * pCursor = m_pHead;
  while(pCursor != 0) {
    pCursor = pCursor->m_pNext;
    nSize++;   
  }
  return nSize;
}
bool CList::isEmpty()
{
  return m_pHead == 0;
}