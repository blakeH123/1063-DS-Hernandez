 ```cpp
 //assumptions are list is >= length(2);
 // swaps sets of neighbors
 // 1: head->A->B->C->D->E->NULL
 // 2: head->B->A->D->C->E->NULL
 void swapNeighbors()
{ node* prev = Head;
  node* temp = Head->next;
  int tempvar;
   
  while(prev->next)
  { tempvar = temp->data;
    temp->data = prev->data;
    prev->data = tempvar;
    prev = temp->next;// same as prev ->next->next
    if (prev) // after is incremented if statement checks if
              // prev points to NULL. If it does it fails if
              // statement and returns.
    { temp = temp->next->next;
      cout << "5" << '\n';
      cout << "prev->data is : " << prev->data << '\n';
      cout << "temp->data is : " << temp->data << '\n';
    }
    else
    { return;
    }
  }
}
```
