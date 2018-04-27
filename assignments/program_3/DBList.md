```cpp
#include <iostream>
#include <string>
#include "DBList.h"

using namespace std;

//Public 
////////////////////////////////////////////

DBList::DBList()
{ Head = NULL;
  Tail = NULL;
  Current = NULL;
}

/**
 * InsertFront - 
 *     Inserts a value at the front of the list by calling 
 *     actual insert with a node.
 * Params:
 *     string : data element to be inserted
 */
void DBList::InsertFront(string Data)
{  Node* Temp = new Node(Data);
  InsertFront(Temp);
}

/**
 * InsertFront - 
 *     Inserts a value at the front of the list
 * Params:
 *     Node*& : node to be appended to front
 */
void DBList::InsertFront(Node* &Temp)
{ if(!Head)
  {
    Head = Temp;
    Tail = Temp;
    Tail->Next = Head;
    Current = Temp;
    Head->Prev = Tail;
  }
  else
  { Temp->Next = Head;
    Temp->Prev = Tail;
    Head->Prev = Temp;
    Tail->Next = Temp;
    Head = Temp;
    Current = Head;
  }
}


void DBList::InsertRear(Node* &Temp)
{ if(!Head)
  { DBList::InsertFront(Temp);
  }
  else
  { Tail->Next = Temp;
    Temp->Prev = Tail;
    Tail = Temp;
  }
}

/**
 * InsertRear - 
 *     Inserts a value at the rear of the list by calling 
 *     actual insert with a node.
 * Params:
 *     string : data element to be inserted
 */
void DBList::InsertRear(string Data)
{ if(!Head)
  { DBList::InsertFront(Data);
  }
  else
  { Node* Temp = new Node(Data);
    InsertRear(Temp);
  }
}

void DBList::InsertInOrder(string Data)
{ if(!Head)
  { DBList::InsertFront(Data);
  }
  else
  { Node* Temp = new Node(Data);
    //Node* Location = DBList::_Find(Data);
  }
}

bool DBList::Delete(string x)
{ //One node 
  if(Head == Tail && Head->Data==x)
  { delete Head;
    Head = NULL;
    Tail = NULL;
    return true;
  //Beginning of list
  }else if(Head->Data == x)
  { Head = Head->Next;
    delete Head->Prev;
    Head->Prev = NULL;
    return true;
  //End of list
  }else if(Tail->Data == x)
  { Tail = Tail->Prev;
    delete Tail->Next;
    Tail->Next = NULL;
    return true;
  //Middle of list
  }else{
    Node* Location = DBList::_Find(x);
    if(Location)
    { Location->Prev->Next = Location->Next;
      Location->Next->Prev = Location->Prev;
      delete Location;
      return true;
    }
  }
  return false; 
}

bool DBList::Find(string x)
{ return false;
}

bool DBList::Update(string x,string y)
{ return false;
}

void DBList::Print(int columns)
{ Node *Temp = Head;
  int count = 1;
  
  while(Temp != Tail)
  { cout<<Temp->Data<<" ";
    Temp = Temp->Next;
    if(columns && count % columns == 0)
      cout<<endl;
    count++;
  }
}

void DBList::Print()
{ DBList::Print(0);
}


void DBList::rPrint()
{ DBList::rPrint1(Tail);
}
//Private 
////////////////////////////////////////////

void DBList::rPrint(Node* Head)
{ if(Head == Tail)
  { return;
  }
  else
  { DBList::rPrint(Head->Next);
    cout<<Head->Data<<" ";
  }
}

void DBList::rPrint1(Node* Tail)
{ if(Tail == Head)
  { return;
  }
  else
  { cout<<Tail->Data<<" ";
    DBList::rPrint1(Tail->Prev);
  }
}



Node* DBList::_Find(string key){
  Node* Temp = Head;
  
  while(Temp)
  { if (Temp->Data == key)
    { return Temp;
    }
    Temp = Temp->Next;
  }
  return NULL;
}




/**
 * TraverseNext - 
 *     Traverses the list through nodes to the right multiplier times then delets the node it lands on.
 * Params:
 *     int multiplier the number of times next is used.
 * Return:
 *     string: tempdata used to store the data of a node just before deletion to print to outfile
 */
string DBList:: TraverseNext(int multiplier)
{ string tempdata;
  Node *Temp = Head;
  
  for (int i = 1 ; i < multiplier; i++)
  {  Temp = Temp->Next;
  }
  Temp = Temp->Next;//one last time to avoid loosing current pointer

  tempdata = Temp -> Prev -> Data;
  DBList::Delete(Temp -> Prev -> Data);
  return tempdata;
}

/**
 * TraversePrev - 
 *     Traverses the list through nodes to the left multiplier times then delets the node it lands on.
 * Params:
 *     int multiplier the number of times prev is used.
 * Return:
 *     string: tempdata used to store the data of a node just before deletion to print to outfile
 */
string DBList:: TraversePrev(int multiplier)
{ string tempdata;
  Node *Temp = Head;
  
  for (int i = 1 ; i < multiplier; i++)
  {  Temp = Temp->Prev;
  }
  Temp = Temp->Prev;//one last time to avoid loosing current pointer
  
  tempdata = Temp -> Next -> Data;
  DBList::Delete(Temp -> Next -> Data);
  return tempdata;
}

/**
 * Empty - 
 *     checks if list is empty 
 * Params:
 *     none
 * Return:
 *     bool: true if list is empty false if list is not empty 
 */
bool DBList:: Empty()
{ if (Head == NULL)
  { return true;
  }
  return false;
}
```
