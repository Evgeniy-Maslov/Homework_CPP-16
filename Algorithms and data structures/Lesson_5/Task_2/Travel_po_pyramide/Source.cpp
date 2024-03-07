#include "Header.h"

void Source_array(int* pyramid, int size)
{
    std::cout << "Source array: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << std::format("{} ", pyramid[i]);
    }
    std::cout << std::endl;
}

int level(int n, int h) // ÂÛ×ÈÑËÅÍÈÅ ÓÐÎÂÍß ÏÈÐÀÌÈÄÛ
{
    if (n == 0) { return h; }
    else { h++; level((n - 1) / 2, h); }
}

int parent_index(int n) // ÈÍÄÅÊÑ ÐÎÄÈÒÅËß
{
    return (n - 1) / 2;
}

int child_index(int n) // ÈÍÄÅÊÑ ÐÅÁ¨ÍÊÀ
{
    return  2 * (n - 1) / 2 + 1;
}

void print_pyramid(int* pyramid, int index, int size)
{
    int h{}; // ÇÍÀ×ÅÍÈÅ ÓÐÎÂÍß ÏÈÐÀÌÈÄÛ
    if (index == 0)
    {
        std::cout << std::format("{} root {}\n", 0, pyramid[index]);
    }
    else if (index < size)
    {
        std::cout << std::format("{} {}({}) {}\n",
            level(index, h), child_index(index) % 2 ? "left" : "right",
            pyramid[parent_index(index)], pyramid[child_index(index)]);
    }
    else
    {
        std::cout << std::endl;
        return;
    }
}

void Travel_po_pyramide(std::string command, int* pyramid, int& index, int size)
{
    if (command == "up")
        if (index == 0)
        {
            std::cout << "Error! Missing parent\n";
            std::cout << "You are here: ";
            print_pyramid(pyramid, index, size);
        }
        else
        {
            std::cout << "Ok\n";
            std::cout << "You are here: ";
            print_pyramid(pyramid, index = parent_index(index), size);
        }
    else if (command == "left")
        if (2 * index + 1 >= size)
        {
            std::cout << "Error! Missing left child\n";
            std::cout << "You are here: ";
            print_pyramid(pyramid, index, size);
        }
        else
        {
            std::cout << "Ok\n";
            std::cout << "You are here: ";
            print_pyramid(pyramid, index = 2 * index + 1, size);
        }
    else if (command == "right")
        if (2 * index + 2 >= size)
        {
            std::cout << "Error! Missing right child\n";
            std::cout << "You are here: ";
            print_pyramid(pyramid, index, size);
        }
        else
        {
            std::cout << "Ok\n";
            std::cout << "You are here: ";
            print_pyramid(pyramid, index = 2 * index + 2, size);
        }
    else if (command == "exit")
    {
        std::cout << std::endl;
        return;
    }
    else { std::cout << "You have entered an unknown command.\n"; }

}