#include <iostream>
#include <algorithm>
#include "Six.hpp"

Six::Six() : size{0}, data{nullptr} {}

Six::Six(const size_t & n, unsigned char t) : size{n} {
    this->data = new unsigned char[n];
    for (size_t i = 0; i < n; ++i) {
        this->data[i] = t;
    }
}

Six::Six(const std::initializer_list<unsigned char> &t) {
    this->size = t.size();
    this->data = new unsigned char[this->size];
    size_t i{0};
    for (auto c : t) {
        this->data[i++] = c;
    }
}

Six::Six(const std::string &t) {
    this->size = t.size();
    this->data = new unsigned char[this->size];
    for(size_t i{0}; i < this->size; ++i) {
        this->data[i] = t[i];
    }
}

Six::Six(Six&& other) noexcept {
    this->size  = other.size;
    this->data = new unsigned char[this->size];

    other.size = 0;
    other.data = nullptr; 
}

bool Six::operator==(const Six &other) {
    bool isEqual = this->size == other.size;
    if (isEqual) {
        for (size_t i{0}; i < this->size; ++i) {
            if (this->data[i] != other.data[i]) {
                isEqual = false;
                break;
            }
        }
    } 
    return isEqual;
}

bool Six::operator!=(const Six &other) {
    if (*this == other) {return 0;}
    return 1;
}

bool Six::operator>(const Six &other) {
    if (this->size == other.size) {
        for (size_t i = 0; i < this->size; ++i) {
            if (this->data[i] > other.data[i]) {
                return true;
            } else {
                return false;
            }
        }
    }

    return 0;
}

bool Six::operator<(const Six &other) {
    if (this->size == other.size) {
        for (size_t i = 0; i < this->size; ++i) {
            if (this->data[i] < other.data[i]) {
                return true;
            } else {
                return false;
            }
        }
    }

    return 0;
}

bool Six::operator>=(const Six &other) {
    if (*this < other) {return 0;}
    return 1;
}

bool Six::operator<=(const Six &other) {
    if (*this > other) {return 0;}
    return 1;
}

Six Six::operator+(const Six &other) {
    size_t resultSize = std::max(this->size, other.size) + 1;
    std::string result(resultSize, '0');
    int carry = 0;

    for (size_t i = 0; i < resultSize; ++i) {
        int bit1 = (i < this->size) ? (this->data[i]) - '0' : 0;
        int bit2 = (i < other.size) ? (other.data[i]) - '0' : 0;

        int sum = bit1 + bit2 + carry;
        result[i] = (sum % 6) + '0';
        carry = sum / 6;
    }

    if (carry > 0) {
        result[resultSize - 1] = carry + '0';
    }

    while (result[resultSize - 1] == '0'){
        result.erase(resultSize - 1, 1);
        resultSize--;
    }
    std::reverse(result.begin(), result.end());

    return Six(result);
}

Six Six::operator-(const Six &other) {
    size_t resultSize = std::max(this->size, other.size) + 1;
    std::string result(resultSize, '0');
    int carry = 0;

    for (size_t i = 0; i < resultSize; ++i) {
        int bit1 = (i < this->size) ? (this->data[i]) - '0' : 0;
        int bit2 = (i < other.size) ? (other.data[i]) - '0' : 0;

        int diff = bit1 - bit2 - carry;
        if (diff < 0) {
            diff += 6;
            carry = 1;
        } else {
            carry = 0;
        }
        result[i] = diff + '0';
    }
    

    while (result[resultSize - 1] == '0'){
        result.erase(resultSize - 1, 1);
        resultSize--;
    }
    
    std::reverse(result.begin(), result.end());
    return Six(result);
}

void Six::operator=(const Six &other) {
    if (&other != this) {
        delete[] this->data;
        this->data = new unsigned char[other.size];
        for (size_t i = 0; i < other.size; ++i) {
            this->data[i] = other.data[i];
        }
    }
}

Six::~Six() noexcept{
    if (size > 0) {
        size = 0;
        delete[] data;
        data = nullptr;
    }
}

std::ostream &operator<<(std::ostream &os, const Six &other) {
    for (size_t i = 0; i < other.size; ++i) {
        os << other.data[i];
    }
    return os;
}
