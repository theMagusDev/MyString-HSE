// Copyright (C) 2024 Yuriy Magus

#include <set>
#include <iostream>
#include "../include/MyString.h"

#define INITIAL_INPUT_BUFFER_SIZE 10

size_t getStrLength(const char * str);

MyString::MyString(const char *str) {
    if (str == nullptr) {
        this->arraySize = 0;
        return;
    }

    this->arraySize = getStrLength(str);
    this->charArray = new char[arraySize];

    for (int i = 0; i < arraySize; i++) {
        this->charArray[i] = str[i];
    }
}

MyString::MyString(std::string cString) {
    if (cString.empty()) {
        this->arraySize = 0;
        return;
    }

    this->arraySize = cString.length();
    this->charArray = new char[arraySize];

    for (int i = 0; i < arraySize; i++) {
        this->charArray[i] = cString.at(i);
    }
}

MyString::MyString(const MyString& ref) {
    if (ref.arraySize == 0) {
        this->arraySize = 0;
        return;
    }

    this->arraySize = ref.arraySize;
    this->charArray = new char[arraySize];

    for (int i = 0; i < arraySize; i++) {
        this->charArray[i] = ref.charArray[i];
    }
}

MyString::MyString(MyString&& ref) {
    if (this->arraySize != 0) {
        delete [] this->charArray;
    }

    this->arraySize = ref.arraySize;
    this->charArray = ref.charArray;
    ref.charArray = nullptr;
    ref.arraySize = 0;
}

MyString::~MyString() {
    if (this->length() != 0) {
        delete[] charArray;
    }
}

size_t MyString::length() {
    return this->arraySize;
}

char * MyString::get() {
    return this->charArray;
}

MyString MyString::operator+(const MyString& other) const {
    MyString concatenatedString;
    concatenatedString.arraySize = this->arraySize + other.arraySize;
    concatenatedString.charArray = new char[concatenatedString.arraySize];
    int i = 0;

    for (int j = 0; j < this->arraySize; j++) {
        concatenatedString.charArray[i] = this->charArray[j];
        i++;
    }

    for (int j = 0; j < other.arraySize; j++) {
        concatenatedString.charArray[i] = other.charArray[j];
        i++;
    }

    return concatenatedString;
}

MyString MyString::operator-(const MyString& other) const {
    std::set <char> otherStringChars;
    for (int j = 0; j < other.arraySize; j++) {
        otherStringChars.insert(other.charArray[j]);
    }

    int resultingStringSize = 0;
    for (int j = 0; j < this->arraySize; j++) {
        if (!otherStringChars.count(this->charArray[j])) {
            resultingStringSize++;
        }
    }

    MyString resultingString;
    resultingString.arraySize = resultingStringSize;
    resultingString.charArray = new char[resultingString.arraySize];

    int i = 0;
    for (int j = 0; j < this->arraySize; j++) {
        if (!otherStringChars.count(this->charArray[j])) {
            resultingString.charArray[i] = this->charArray[j];
            i++;
        }
    }

    return resultingString;
}

MyString MyString::operator*(int multiplier) const {
    MyString resultingString;
    resultingString.arraySize = this->arraySize * multiplier;
    resultingString.charArray = new char[resultingString.arraySize];
    for (int i = 0; i < resultingString.arraySize; i++) {
        resultingString.charArray[i] = this->charArray[i % this->arraySize];
    }

    return resultingString;
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete [] this->charArray;
        this->arraySize = other.arraySize;
        this->charArray = new char[this->arraySize];

        for (int i = 0; i < this->arraySize; i++) {
            this->charArray[i] = other.charArray[i];
        }
    }

    return *this;
}

MyString& MyString::operator=(MyString&& other) {
    if (this != &other) {
        if (this->arraySize != 0) {
            delete[] this->charArray;
        }

        this->arraySize = other.arraySize;
        this->charArray = other.charArray;

        other.charArray = nullptr;
        other.arraySize = 0;
    }

    return *this;
}

bool MyString::operator==(const MyString& other) const {
    if (this->arraySize != other.arraySize) {
        return false;
    }

    for (int i = 0; i < this->arraySize; i++) {
        if (this->charArray[i] != other.charArray[i]) {
            return false;
        }
    }

    return true;
}

bool MyString::operator!=(const MyString& other) const {
    if (this->arraySize != other.arraySize) {
        return true;
    }

    for (int i = 0; i < this->arraySize; i++) {
        if (this->charArray[i] != other.charArray[i]) {
            return true;
        }
    }

    return false;
}

bool MyString::operator>(const MyString& other) const {
    if (this->arraySize > other.arraySize) {
        for (int i = 0; i < other.arraySize; i++) {
            if (this->charArray[i] == other.charArray[i]) {
                continue;
            } else {
                if (this->charArray[i] > other.charArray[i]) {
                    return true;
                } else {
                    return false;
                }
            }
        }

        return true;
    } else {
        for (int i = 0; i < this->arraySize; i++) {
            if (this->charArray[i] == other.charArray[i]) {
                continue;
            } else {
                if (this->charArray[i] > other.charArray[i]) {
                    return true;
                } else {
                    return false;
                }
            }
        }

        return false;
    }
}

bool MyString::operator<(const MyString& other) const {
    if (this->arraySize > other.arraySize) {
        for (int i = 0; i < other.arraySize; i++) {
            if (this->charArray[i] == other.charArray[i]) {
                continue;
            } else {
                if (this->charArray[i] < other.charArray[i]) {
                    return true;
                } else {
                    return false;
                }
            }
        }

        return false;
    } else {
        for (int i = 0; i < this->arraySize; i++) {
            if (this->charArray[i] == other.charArray[i]) {
                continue;
            } else {
                if (this->charArray[i] < other.charArray[i]) {
                    return true;
                } else {
                    return false;
                }
            }
        }

        if (this->arraySize == other.arraySize) {
            return false;
        } else {
            return true;
        }
    }
}

bool MyString::operator>=(const MyString& other) const {
    if (this->arraySize > other.arraySize) {
        for (int i = 0; i < other.arraySize; i++) {
            if (this->charArray[i] == other.charArray[i]) {
                continue;
            } else {
                if (this->charArray[i] > other.charArray[i]) {
                    return true;
                } else {
                    return false;
                }
            }
        }

        return true;
    } else {
        for (int i = 0; i < this->arraySize; i++) {
            if (this->charArray[i] == other.charArray[i]) {
                continue;
            } else {
                if (this->charArray[i] > other.charArray[i]) {
                    return true;
                } else {
                    return false;
                }
            }
        }

        if (this->arraySize == other.arraySize) {
            return true;
        } else {
            return false;
        }
    }
}

bool MyString::operator<=(const MyString& other) const {
    if (this->arraySize > other.arraySize) {
        for (int i = 0; i < other.arraySize; i++) {
            if (this->charArray[i] == other.charArray[i]) {
                continue;
            } else {
                if (this->charArray[i] < other.charArray[i]) {
                    return true;
                } else {
                    return false;
                }
            }
        }

        return false;
    } else {
        for (int i = 0; i < this->arraySize; i++) {
            if (this->charArray[i] == other.charArray[i]) {
                continue;
            } else {
                if (this->charArray[i] < other.charArray[i]) {
                    return true;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
}

MyString MyString::operator!() const {
    MyString resultingString;
    resultingString.arraySize = this->arraySize;
    resultingString.charArray = new char[this->arraySize];
    char tempChar = -1;

    for (int i = 0; i < this->arraySize; i++) {
        if (this->charArray[i] >= 97 && this->charArray[i] <= 122) {
            tempChar = static_cast<char>(this->charArray[i] - 32);
            resultingString.charArray[i] = tempChar;
            continue;
        }
        if (this->charArray[i] >= 65 && this->charArray[i] <= 90) {
            tempChar = static_cast<char>(this->charArray[i] + 32);
            resultingString.charArray[i] = tempChar;
            continue;
        }
        resultingString.charArray[i] = this->charArray[i];
    }

    return resultingString;
}

char MyString::operator[](int index) const {
    if (index >= this->arraySize || index < 0) {
        return '\0';
    }
    return this->charArray[index];
}

int MyString::operator()(const std::string& substr) const {
    bool isSubstring = true;
    bool outOfRange = false;

    for (int start = 0; start < this->arraySize; start++) {
        isSubstring = true;
        for (int i = 0; i < substr.size(); i++) {
            outOfRange = start + i >= this->arraySize;
            if (outOfRange || this->charArray[start + i] != substr.at(i)) {
                isSubstring = false;
                break;
            }
        }

        if (isSubstring) {
            return start;
        }
    }

    return -1;
}

std::istream& operator>>(std::istream& in, MyString& myStr) {
    char inputChar = '?';
    char * inputBuffer = new char[INITIAL_INPUT_BUFFER_SIZE];
    char * tempBuffer;
    int bufferSize = INITIAL_INPUT_BUFFER_SIZE;

    in >> inputChar;
    int inputSize = 0;

    while (inputChar != '\n') {
        inputSize++;
        inputBuffer[inputSize - 1] = inputChar;
        if (inputSize >= bufferSize) {
            tempBuffer = inputBuffer;
            bufferSize += 100;
            inputBuffer = new char[bufferSize];
            for (int i = 0; i < bufferSize - 100; i++) {
                inputBuffer[i] = tempBuffer[i];
            }
            delete [] tempBuffer;
        }

        in.get(inputChar);
    }

    inputBuffer[inputSize++] = '\0';

    myStr.arraySize = bufferSize;
    myStr.charArray = inputBuffer;

    return in;
}

std::ostream& operator<<(std::ostream& out, const MyString& myStr) {
    for (int i = 0; i < myStr.arraySize; i++) {
        if (myStr.charArray[i] == '\0') {
            break;
        }
        out << myStr.charArray[i];
    }

    return out;
}

size_t getStrLength(const char * str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }

    return i;
}
