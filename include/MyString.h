// Copyright (C) 2024 Yuriy Magus

#ifndef INCLUDE_MYSTRING_H_
#define INCLUDE_MYSTRING_H_

#include <string>

class MyString {
 private:
    char * charArray;
    size_t arraySize;
    size_t getStrLength(const char * str);

 public:
    explicit MyString(const char * str = nullptr);
    explicit MyString(std::string cString);
    MyString(const MyString& ref);
    MyString(MyString&& ref);
    ~MyString();

    size_t length();
    char * get();

    MyString operator+(const MyString& other) const;
    MyString operator-(const MyString& other) const;
    MyString operator*(int multiplier) const;
    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other);
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator>=(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    MyString operator!() const;
    char operator[](int index) const;
    int operator()(const std::string& other) const;

    friend std::istream& operator >>(std::istream& in, MyString& myStr);
    friend std::ostream& operator <<(std::ostream& out, const MyString& myStr);
};

#endif  // INCLUDE_MYSTRING_H_