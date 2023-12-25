#include <iostream>
#include <fstream>

struct arr_address
{
    std::string City;
    std::string street;
    int house;
    int apartment;
};

class Addresses
{
    int n;

public:
    void overwrite_file()
    {
        read_Addresses();
    }
private:
    void read_Addresses()
    {
        std::ifstream fin("in.txt");
        fin >> n;
        arr_address* list = new arr_address[n];
        for (int i = 0; i < n; i++)
        {
            fin >> list[i].City
                >> list[i].street
                >> list[i].house
                >> list[i].apartment;
        }
        fin.close();
        sorting_city(n, list);
        write_Address(n, list);
    }
    void sorting_city(int n, arr_address* list)
    {
        for (int j = 0; j < n; j++) 
        {
            for (int i = n - 1; i > 0; i--) 
            {
                if (list[i].City < list[i - 1].City) 
                {
                    arr_address tmp = list[i];
                    list[i] = list[i - 1];
                    list[i - 1] = tmp;
                }
            }
        }
    }
    void write_Address(int n, arr_address* list)
    {
        std::ofstream fout("out.txt");
        fout << n << std::endl;
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
            {
            fout << list[i].City << ", "
                << list[i].street << ", "
                << list[i].house << ", "
                << list[i].apartment;
            }
            else
            {
                fout << list[i].City << ", "
                    << list[i].street << ", "
                    << list[i].house << ", "
                    << list[i].apartment << std::endl;
            }
        }
        fout.close();
        delete[] list;
    }
};

int main(int argc, char** argv)
{
    Addresses a;
    a.overwrite_file();
    return 0;
}