#include <iostream>
#include <vector>
#include <memory>

class tridiagonal_matrix
{
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;
    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) : m_down{ down }, m_upper{ upper }, m_middle{ middle } {};
  
    ~tridiagonal_matrix() { std::cout << "destructor called\n"; }

    std::unique_ptr<tridiagonal_matrix> clone() {

        //const std::vector<double> m_down = { 5.3, 2.4 };
        //const std::vector<double> m_upper = { 4.2, 0.6 };
        //const std::vector<double> m_middle = { 3.5, 5.1, 4.2 };
      
        auto ptr_ = std::make_unique<tridiagonal_matrix>(m_down, m_upper, m_middle);
       
        return ptr_;
    }
    friend void operator << (std::ostream& out, tridiagonal_matrix& tr_mat) {
        std::cout << "down: \t\t";
        auto it = tr_mat.m_down.cbegin();
        while (it != tr_mat.m_down.cend()) {
            if (it == (tr_mat.m_down.cend() - 1)) {
                std::cout << *it;}
            else{
                std::cout << *it << " , ";}
            it++;
        }
        std::cout << "\n";
        std::cout << "m_upper: \t";
        it = tr_mat.m_upper.cbegin();
        while (it != tr_mat.m_upper.cend()) {
            if (it == (tr_mat.m_upper.cend() - 1)) {
                std::cout << *it; }
            else {
                std::cout << *it << " , ";}
            it++;
        }
        std::cout << "\n";
        std::cout << "m_middle: \t";
        it = tr_mat.m_middle.cbegin();
        while (it != tr_mat.m_middle.cend()) {
            if (it == (tr_mat.m_middle.cend() - 1)) {
                std::cout << *it; }
            else {
                std::cout << *it << " , "; }
            it++;
        }
        std::cout << "\n";
    }

};

int main()
{
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0};
    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
    );

    auto matrix_clone = matrix->clone();

    std::cout << "matrix\n";
    std::cout << *matrix;
    std::cout << "\n";
    std::cout << "matrix_clone\n";
    std::cout << *matrix_clone;
    std::cout << "\n";
    return 0;
}