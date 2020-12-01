#include "SortedList.h"
#include <iostream>

using namespace std;


template <class ItemType>
void SortedList<ItemType>::merge(SortedList& list) {

  Node<ItemType>* first = listData;
  Node<ItemType>* second = list.listData;

  if (first == NULL) {
    listData = second;
    list.listData = NULL;
  }

  else if (second == NULL) {
    listData = first;
    list.listData = NULL;
  }
  else {
    while (second != NULL) {
      putItem(second->info);
      second = second->next;
    }
    list.listData = NULL;
  }
}


  

template <class ItemType>
bool SortedList<ItemType>::findItem(ItemType item, Node<ItemType> *& predecessor) {

  Node<ItemType>* location = listData;
  predecessor = NULL;

  while (location != NULL) {

    if (location->info == item) {
      return true;
    }

    else if (location->info > item) {
      return false;
    }

    else {
      predecessor = location;
      location = location->next;
    }
  }
  return false;
}



template <class ItemType>
SortedList<ItemType>::SortedList() {

  listData = new Node<ItemType>;
  listData = NULL;
  Length = 0;
  
}



template <class ItemType>
SortedList<ItemType>::~SortedList() {
  
  Node<ItemType>* location;
    
  while (listData != NULL) {
    location = listData;
    listData = location->next;
    delete location;
  }
  
}



template <class ItemType>
void SortedList<ItemType>::makeEmpty() {
  
  Node<ItemType>* location;
  
  while (listData != NULL) {
    location = listData;
    listData = location->next;
    delete location;
  }
  
  Length = 0;
  
}



template <class ItemType>
void SortedList<ItemType>::putItem(ItemType newItem) {

  Node<ItemType>* newNode;
  Node<ItemType>* location;
  Node<ItemType>* predecessor;

  if (isFull()) {
    throw FullList();
  }
  
  else if (findItem(newItem,predecessor)) {
    throw DuplicateItem();
  }

  newNode = new Node<ItemType>;
  newNode->info = newItem;

  if (predecessor == NULL) {
    newNode->next = listData;
    listData = newNode;
  }

  else {
    location = predecessor->next;
    predecessor->next = newNode;
    newNode->next = location;
  }
  
  Length++;
}



template <class ItemType>
void SortedList<ItemType>::deleteItem(ItemType item) {

  Node<ItemType>* location = listData;
  Node<ItemType>* predecessor;

  if (findItem(item,predecessor)) {
    
    if (predecessor != NULL) {
      location = predecessor->next;
      predecessor->next = location->next;
      delete location;
      Length--;
    }

    else {
      listData = listData->next;
      Length--;
    } 
  }

  else {
    throw DeletingMissingItem();
  }
  
}



template <class ItemType>
void SortedList<ItemType>::printList(ofstream& outFile) {

  Node<ItemType>* location = listData;

  outFile << "List Items : ";
  
  while (location != NULL) {
    outFile << location->info << "->";
    location = location->next;
  }
  outFile << "NULL" << endl;
}



template <class ItemType>
bool SortedList<ItemType>::isFull() const {

  Node<ItemType>* location;

  try {
    location = new Node<ItemType>;
    delete location;
    return false;
  }

  catch (std::bad_alloc exception) {
    return true;
  }
  
}



template <class ItemType>
ItemType SortedList<ItemType>::getAt(int index) {

  Node<ItemType>* location = listData;

  if (index < 1 || index > Length) {
    throw OutOfBound();
  }
  
  for (int i = 1; i < index; i++) {
    location = location->next;
  }

  return location->info;
  
}



template <class ItemType>
int SortedList<ItemType>::getLength() const {

  return Length;
  
}



template <class ItemType>
bool SortedList<ItemType>::isEmpty() const {

  return bool(Length == 0);
  
}
