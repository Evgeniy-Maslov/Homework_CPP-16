#pragma once
#include <iostream>
#include <format>
//#include ""

void Source_array(int* pyramid, int size);
int level(int n, int h); // ���������� ������ ��������
int parent_index(int n); // ������ ��������
int child_index(int n); // ������ �������
void print_pyramid(int* pyramid, int index, int size);
void Travel_po_pyramide(std::string command, int* pyramid, int& index, int size);
