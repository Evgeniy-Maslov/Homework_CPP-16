#pragma once


class big_integer {
    std::vector<int> number_;
    const int a_digit_number = 4;
    const int base = pow_(10, a_digit_number);
public:
    big_integer(std::string&& x) {
        for (int i = static_cast<int>(x.length()); i > 0; i -= a_digit_number) {
            if (i < a_digit_number and i > 0) {
                number_.push_back(std::stoi(x.substr(0, i)));
            }
            else {
                number_.push_back(std::stoi(x.substr(i - a_digit_number, a_digit_number)));
            }
        }
    }
    big_integer(size_t x) {
        number_.clear();
        while (x != 0) {
            number_.push_back(0);
            x--;
        }
    }
    big_integer(const big_integer& x) : number_(x.number_) { }
    big_integer(big_integer&& x) noexcept : number_(x.number_) {
        x.number_.clear();
    }
    big_integer& operator = (const big_integer& x) {
        if (&x == this) {
            return *this;
        }
        number_.clear();
        number_ = x.number_;
        return *this;
    }
    big_integer& operator = (big_integer&& x) noexcept {
        if (&x == this) {
            return *this;
        }
        number_ = std::move(x.number_);
        return *this;
    }
    big_integer operator + (big_integer& other) {
        big_integer temp = *this;
        if (temp.number_.size() != other.number_.size()) {
            while (temp.number_.size() != other.number_.size()) {
                (temp.number_.size() > other.number_.size()) ? other.number_.push_back(0) : temp.number_.push_back(0);
            }
        }
        for (int i = 0; i < static_cast<int>(temp.number_.size()); i++) {
            temp.number_.data()[i] += other.number_.data()[i];
            if (temp.number_.data()[i] > base and i != temp.number_.size() - 1) {
                temp.number_.data()[i] -= base;
                temp.number_.data()[i + 1]++;
            }
        }
        return std::move(temp);
    }
    big_integer operator - (big_integer& other) {
        big_integer temp = *this;
        if (temp.number_.size() != other.number_.size()) {
            while (temp.number_.size() != other.number_.size()) {
                (temp.number_.size() > other.number_.size()) ? other.number_.push_back(0) : temp.number_.push_back(0);
            }
        }
        for (int i = 0; i < static_cast<int>(temp.number_.size()); i++) {
            temp.number_.data()[i] -= other.number_.data()[i];
            if (temp.number_.data()[i] < 0 and i != temp.number_.size() - 1) {
                temp.number_.data()[i] += base;
                temp.number_.data()[i + 1]--;
            }
        }
        return std::move(temp);
    }
    big_integer operator * (const int& x) {
        big_integer temp = *this;
        for (int i = 0; i < static_cast<int>(temp.number_.size()); i++) {
            temp.number_.data()[i] *= x;
        }
        for (int i = 0; i < static_cast<int>(temp.number_.size()); i++) {
            if (temp.number_.data()[i] / base and i != temp.number_.size() - 1) {
                temp.number_.data()[i + 1] += temp.number_.data()[i] / base;
                temp.number_.data()[i] %= base;
            }
            else if (temp.number_.data()[i] / base and i == temp.number_.size() - 1) {
                temp.number_.push_back(temp.number_.data()[i] / base);
                temp.number_.data()[i] %= base;
            }
            else {
                temp.number_.data()[i] %= base;
            }
        }
        return std::move(temp);
    }
    big_integer operator * (const big_integer& other) {
        big_integer temp(number_.size() + other.number_.size() - 1);
        for (int i = 0; i < static_cast<int>(number_.size()); i++) {
            for (int j = 0; j < static_cast<int>(other.number_.size()); j++) {
                temp.number_.data()[i + j] += number_.data()[i] * other.number_.data()[j];
            }
        }
        for (int i = 0; i < static_cast<int>(temp.number_.size()); i++) {
            if (temp.number_.data()[i] / base and i != temp.number_.size() - 1) {
                temp.number_.data()[i + 1] += temp.number_.data()[i] / base;
                temp.number_.data()[i] %= base;
            }
            else if (temp.number_.data()[i] / base and i == temp.number_.size() - 1) {
                temp.number_.push_back(temp.number_.data()[i] / base);
                temp.number_.data()[i] %= base;
            }
            else {
                temp.number_.data()[i] %= base;
            }
        }
        return std::move(temp);
    }
    int pow_(int a, int x) {
        int b = a;
        while (x > 1) {
            b *= a;
            x--;
        }
        return b;
    }
    ~big_integer() { }
    friend void operator << (std::ostream& out, big_integer& v) {
        std::cout << "result: ";
        for (int i = static_cast<int>(v.number_.size() - 1); i > -1; i--) {
            if (i == static_cast<int>(v.number_.size() - 1)) {
                out << v.number_.data()[i];
            }
            else {
                int count = 0;
                int base = v.base;
                while (count != v.a_digit_number) {
                    base /= 10;
                    if (v.number_.data()[i] / base) {
                        out << v.number_.data()[i];
                        break;
                    }
                    else {
                        out << "0";
                    }
                    count++;
                }
            }
        }
        std::cout << "\n";
    }
};