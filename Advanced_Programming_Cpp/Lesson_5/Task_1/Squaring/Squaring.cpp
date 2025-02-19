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
T pow_2(const T& a) {
     return  a * a;
}
template<class V>
std::vector<V> pow_2(const std::vector<V>& a) {
    std::vector<V> b = a;
    std::for_each(b.begin(), b.end(), [](V& i) {i *= i;});
    return b;
}

int main()
{
    int n = 4;
    std::vector<int> vec = { -1, 4, 8 };
    std::cout << "[IN]: ";
    print(n);
    std::cout << std::endl;
    int b = pow_2(n);
    std::cout << "[OUT]: ";
    print(b);
    std::cout << std::endl;
    
    std::cout << "[IN]: ";
    print(vec);
    std::cout << std::endl;
    std::vector<int> vec_b = pow_2(vec);
    std::cout << "[OUT]: ";
    print(vec_b);
    std::cout << std::endl;
    
    return 0;
}

