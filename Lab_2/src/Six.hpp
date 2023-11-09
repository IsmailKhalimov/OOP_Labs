#pragma once
#include <iostream>

class Six {
    public:
        Six();
        Six(const size_t & n, unsigned char t);
        Six(const std::initializer_list<unsigned char> &t);
        Six(const std::string &t);
        Six(const Six& other);
        Six(Six&& other) noexcept;
        virtual ~Six() noexcept;

        Six operator+ (const Six &other);
        Six operator- (const Six &other);
        void operator= (const Six &other);
        bool operator> (const Six &other);
        bool operator< (const Six &other);
        bool operator== (const Six &other);
        bool operator!= (const Six &other);
        bool operator>= (const Six &other);
        bool operator<= (const Six &other);

        u_char* data;
        size_t size;
};

std::ostream &operator<<(std::ostream &os, const Six &other);
