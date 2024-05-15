#ifndef NAMESPACE_W1P1_H // replace with relevant names
#define NAMESPACE_W1P1_H

const int MAX_TITLE_LENGTH = 50;
struct ShoppingRec {
   char m_title[MAX_TITLE_LENGTH + 1];
   int m_quantity;
   bool m_bought;
};


ShoppingRec getShoppingRec();
void displayShoppingRec(const ShoppingRec* shp);
void toggleBoughtFlag(ShoppingRec* rec);
bool isShoppingRecEmpty(const ShoppingRec* shp);

#endif