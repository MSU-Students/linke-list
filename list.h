#ifndef LIST_H
#define LIST_H
//Create Read Update Delete
class CListItem {
  public:
  double m_fValue; //value
  CListItem * m_pNext; //link
};

class CList {
  CListItem * m_pHead;
  public:
  CList();
  ~CList();
  void insert(double value);
  //void insert(double value, int index);
  void set(double value, int index);
  double get(int index);
  void remove(int index);
  int size();
  bool isEmpty();
};
#endif