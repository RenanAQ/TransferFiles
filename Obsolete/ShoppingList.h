#ifndef NAMESPACE_SHOPPINGLIST_H // replace with relevant names
#define NAMESPACE_SHOPPINGLIST_H

#include "ShoppingRec.h"

bool loadList();
void displayList();
void removeBoughtItems();
void removeItem(int index);
bool saveList();
void clearList();
void toggleBought();
void addItemToList();
void removeItemfromList();
bool listIsEmpty();


#endif