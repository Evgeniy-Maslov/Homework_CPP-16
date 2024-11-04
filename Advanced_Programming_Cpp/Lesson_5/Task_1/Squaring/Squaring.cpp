#include <iostream>
#include <vector>
#include <algorithm>


template<class Pr>
void print(Pr value) {
    std::cout << value;
}
template<class Pr_V>
void print(std::vector<Pr_V>& value) {
    for (int i = 0; i < value.size(); i++)
    {
        std::cout << value[i] << (((value.size() - 1) == i) ? " " : ", ");
    }
}


template<class T>
void pow_2(T& a) {
     a *= a;
}
template<class V>
void pow_2(std::vector<V>&a) {
    std::for_each(a.begin(), a.end(), [](V& i) {i *= i; });   
}

int main()
{
    int n = 4;
    std::vector<int> vec = { -1, 4, 8 };
    std::cout << "[IN]: ";
    print(n);
    std::cout << std::endl;
    pow_2(n);
    std::cout << "[OUT]: ";
    print(n);
    std::cout << std::endl;
    
    std::cout << "[IN]: ";
    print(vec);
    std::cout << std::endl;
    pow_2(vec);
    std::cout << "[OUT]: ";
    print(vec);
    std::cout << std::endl;
    
    return 0;
}

