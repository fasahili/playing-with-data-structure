#pragma once
#include <string>

class LargeInteger {
public:
    LargeInteger(int size = 10);
    LargeInteger(const LargeInteger& L);
    ~LargeInteger();
    bool setNumber(std::string str);
    void read(std::istream& in);
    void write(std::ostream& out) const;
    LargeInteger operator+(const LargeInteger& L) const;
    LargeInteger operator-(const LargeInteger& L) const;
    LargeInteger operator*(const LargeInteger& L) const;
    const LargeInteger& operator=(const LargeInteger& L);
    bool operator==(const LargeInteger& L) const;
    bool operator<(const LargeInteger& L) const;
    bool operator>(const LargeInteger& L) const;
private:
    short int* number;
    int length;
    int maxSize;
};