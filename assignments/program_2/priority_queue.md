```cpp
//////////////////////////////////////////////////////////
// Title: Priority Queue
// Files: input_data.txt
// Semester: CMPS 1063 Spring 2018
//
// Author: Blake Hernandez
// Email:  hernandez.blake.54123@gmail.com
// Description:
//    
// Structure : creates node data type to create a list
// based Queue.
// Class : Queue implements the node structues, making a
// lined list based Queue.
// The class also includes funtions to push, pop, sort, and
// print the list's data values.
// Main :
// A while loop then reads in a comand word from an input file
// an if and else if inside of the while loop determines the
// action to be taken with the comand word.
// With the if and if else statements, either the push or pop
// method is called, and as long as there is more than one
// item on the list the sort method is called.
// Each time the while loop is executed, the list is printed to
// the screen.
//////////////////////////////////////////////////////////

/////////////////////////////////
// List Based Queue
// 
// First In First Out 
//
// Method:
//    void push()
//    string pop()
//    bool empty()
//	  int contLen()
//    void bubblesort()

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Structure: creates nodes with next as a pointer
struct Node
{	string val;
	Node* next;
	Node() // initializes node to empty and next pointer to null
	{	val = " ";
		next = NULL;
	}
	Node(string v)
	{	val = v;
		next = NULL;
	}
};

/**
*class Queue:
* Uses node struct to create a priority queue based linked 
* list, where shorter items are higher in priority than longer items
* Methods :
*-pop
*-pop
*-push
*-empty
*-print
*-bubbleSort
*/
class Queue
{
private:
	Node* Front;
	Node* Rear;
public:
	/**
	* Queue
	* constructor
	* params:
	*     - none
	*/
	Queue()
	{	Front = Rear = NULL;
	}

/**
* Function pop:
*      Pops an item off the queue.
* Params:
*      none
* Returns
*      string
*/
string pop()
	{	if (!empty())
		{	Node* temp = Front;   // temp pointer so we can delete node
			string v = temp->val; // grab value out of node
			Front = Front->next;  // move pointer to next node
			delete temp;          // give mem back to system
			return v;
		}
		else
		{	cout << "error: cannot pop off empty queue." << endl;
			return " ";
		}
	}



/**
* Function pop:
*      Popss an item off the queue.
* Params:
*      [string] v - value of item being pushed
* Returns
*      void
*/
	bool pop(string &v)
	{	if (!empty())
		{	Node* temp = Front;   // temp pointer so we can delete node
			string t = temp->val; // grab value out of node
			Front = Front->next;  // move pointer to next node
			delete temp;          // give mem back to system
			v = t;
			return true;
		}
		else
		{	cout << "error: cannot pop off empty queue." << endl;
			return false;
		}
	}

/**
* Function push:
*      Pushes an item onto the queue.
* Params:
*      [string] val - value of item being pushed
* Returns
*      void
*/
  void push(string v)
	{	Node* n = new Node(v);
		// handle the empty case
		if (empty())
		{	Front = n;
			Rear = n;
		}
		else
		{	// not empty add to rear
			Rear->next = n;
			Rear = n;
		}
	}

/**
* Function empty:
*      Checks if the list is empty.
* Params:
*      none
* Returns
*      bool
*/
  bool empty()
	{	return (Front == NULL);
	}

/**
* Function print:
*      Prints every item still on the queue.
* Params:
*      none
* Returns
*      void
*/
  void print()
	{	Node* temp = Front;
		while (temp)
		{	cout << temp->val << "->";
			temp = temp->next;
		}
		cout << '\n';
	}

/**
* Function bubbleSort:
*      Sorts the items in the queue based on length.
* Params:
*      none
* Returns
*      void
*/
  void bubbleSort()
	{	Node *temp = Front;

		if(empty())
		{  return;
		}

		while (temp->next != NULL)
		{	string word1 = temp->val;
			string word2 = temp->next->val;

			if (word1.length() > word2.length())
			{	//swaps the nodes' values 
				temp->val = word2;
				temp->next->val = word1;
			}

			// if TIE - handles words of same length by placing them
			// alphabetically
			else if (word1.length() == word2.length())
			{	if (word1 > word2)
				{	temp->val = word2;
					temp->next->val = word1;
				}
			}
			temp = temp->next;
		}
	}
	
/**
* Function returnFrontval:
*      Returns the front value of the list for easy access before popping item off list.
* Params:
*      none
* Returns
*      string
*/
  string returnFrontVal()
  { while (!empty())
    { return Front->val;
    }
    return "";
  }
  
/**
* Function outfileList:
*      prints list to output file.
* Params:
*      outfile
* Returns
*      void
*/
  void outfileList(ofstream &outfile)
  { int itemsoutfiled = 1;
    Node *temp = Front;
		while (temp)
		{	outfile << itemsoutfiled++ << " " << temp->val << '\n';
			temp = temp->next;
		}
  }
};

int main()
{	int itemspopped = 1;// for counting the number of items
                      // popped off the list.
  Queue Q;
	string animal, command; // command is either push or pop
	int nodecount = 0;      // keeps track of the number of nodes
	                        // in the list
	
  fstream infile;
	infile.open("input_data.txt");
	ofstream outfile;
	outfile.open("priority_out.txt");// items still on Queue when
	                                 // program ends
	outfile << "Animals Popped off the Queue:" << '\n' << '\n';
	
	while (infile >> command)
	{	if (command == "push")
		{	infile >> animal;
			Q.push(animal);
			nodecount++;
		} // end of if
    
		else if (command == "pop")
		{ if (Q.returnFrontVal() != "") // only prints and
		                                // increments itemspopped
		                                // it the list is not empty
		  { outfile << itemspopped++ << " " << Q.returnFrontVal() << '\n';
		  }
		  Q.pop(animal);
    	nodecount--;
			if (nodecount < 0)  // avoids making nodecount negative
			{  nodecount = 0;   // in for loop
			} // end of if
		} // end of else if

    if (nodecount > 1)    // only sorts list when there is more
    {                     // than one item
      for(int i = 0; i < nodecount - i ; i++) // loops the sort
                                              // function
                                              // enough times
                                              // for the
                                              // shortest items
                                              // in list to
                                              // move to the
                                              // front
      {  Q.bubbleSort();
      } // end for loop
    } // end of if
	} // end of while
	
	outfile << '\n' << "Animals Remaining on the Queue (in order of priority):" << '\n' << '\n';
	
	Q.outfileList(outfile);
	
	infile.close();
	outfile.close();
	return 0;
}
```
