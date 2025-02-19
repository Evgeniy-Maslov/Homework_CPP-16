#pragma once
#include <iostream>
#include <format>
//#include ""

void Source_array(int* pyramid, int size);
int level(int n, int h); // ÂÛ×ÈÑËÅÍÈÅ ÓĞÎÂÍß ÏÈĞÀÌÈÄÛ
int parent_index(int n); // ÈÍÄÅÊÑ ĞÎÄÈÒÅËß
int child_index(int n); // ÈÍÄÅÊÑ ĞÅÁ¨ÍÊÀ
void print_pyramid(int* pyramid, int index, int size);
void Travel_po_pyramide(std::string command, int* pyramid, int& index, int size);
