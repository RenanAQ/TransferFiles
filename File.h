#ifndef NAMESPACE_FILE_H // replace with relevant names
#define NAMESPACE_FILE_H

#include "ShoppingRec.h"

bool openFileForRead();
bool openFileForOverwrite();
void closeFile();
bool freadShoppingRec(ShoppingRec* rec);
void fwriteShoppintRec(const ShoppingRec* rec);

#endif