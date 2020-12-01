#include<iostream>
#include<fstream>
#include<string>
using namespace std;
template <class ItemType>
struct Node {
	ItemType info;
	Node<ItemType>* next;
};
class OutOfBound {
};
class DeletingMissingItem {

};
class FullList{
};  

class EmptyList
{};

class DuplicateItem
{};
template <class ItemType>
class SortedList
{
public: 
    SortedList();
    // Class constructor.
    
    
   ~SortedList();
    // Class destructor.
    void makeEmpty();
    // Function: Initializes the list to an empty state.
    // Post: list is empty.
   
    bool isEmpty() const;
    // Function: Determines whether the list is empty.
    // Post: Function value = (list is empty)
   
   bool isFull() const;
    // Function: Determines whether the list is full.
    // Post: Function value = (list is full)
  
  void putItem(ItemType newItem);
    // Function: Adds newItem to the end of the list.
    // Post: If (List is full) FullList exception is thrown
    //       If item is already in the list DuplicateItem exception is thrown
    //       else newItem is in the list at the correct position based on key value.
  //         list maintains the sortedness property
  void deleteItem(ItemType Item);
  // Function: deletes Item from the list.
  // Post: If List is empty EmptyList exception is thrown
  //       If item is not in the list an exception is thrown
  //       else newItem is not in the list.
  

int getLength()const;
	// Function: returns the number of items in the list
ItemType getAt(int index);
//// add remaining functions
void merge(SortedList& list);
// merges two sorted linked lists in-place, removing duplicates
void printList(ofstream&);
private:
    Node<ItemType>* listData;
    int Length;
bool findItem(ItemType item, Node<ItemType> *& predecessor);
         // pre: list is initialized
         // post: If item is in the list then function value =  true 
	     //       predecessor points to the node before the node containg item's key
	             // if item is not in the list, function value is false
         //      // predecessor points to the node contains the predecessor of item in the list
	             // i.e. node with largest value < item's key.
         	      
};


