// Copyright (C) 2024 Yuriy Magus

#include <iostream>
#include "../include/MyString.h"

using namespace std;

void testConstructors();
void testLengthAndGetFunctions();
void testMathFunctions();
void testEqualityFunctions();
void testInequalityFunctions();
void testOtherFunctions();
void testIOFunctions();

int main() {
    testConstructors();
    testLengthAndGetFunctions();
    testMathFunctions();
    testEqualityFunctions();
    testInequalityFunctions();
    testOtherFunctions();
    testIOFunctions();

    return 0;
}

void testConstructors() {
    // create from const char *
    MyString greeting("Hello,");
    cout << "MyString from char array: '" << greeting << "'" << endl;

    // create from cString
    string stringCPlusPlus = "C++";
    MyString cPlusPlus(stringCPlusPlus);
    cout << "MyString from cString: '" << cPlusPlus << "'" << endl;

    // use default value
    MyString emptyString;
    cout << "Empty MyString: '" << emptyString << "'" << endl;

    // move constructor
    MyString programmingLang;
    programmingLang = std::move(cPlusPlus);
    cout << "cPlusPlus MyString is now '" << cPlusPlus << "'" << endl;
    cout << "programmingLang MyString is now '" << programmingLang << "'" << endl;

    MyString javaLang("Java");
    programmingLang = std::move(javaLang);
    cout << "javaLang MyString is now '" << javaLang << "'" << endl;
    cout << "programmingLang MyString is now '" << programmingLang << "'" << endl;
}

void testLengthAndGetFunctions() {
    MyString greeting("Hello,");
    string stringCPlusPlus = "C++";
    MyString cPlusPlus(stringCPlusPlus);
    MyString emptyString;

    // .length() usage
    cout << "MyString '" << greeting << "' length is " << greeting.length()  << endl;
    cout << "MyString '" << cPlusPlus << "' length is '" << cPlusPlus.length() << "'" << endl;
    cout << "MyString '" << emptyString << "' length is " << emptyString.length() << endl;

    // .get() usage
    printf("First string pointer is %p, value it points on is %c\n", greeting.get(), *(greeting.get()));
}

void testMathFunctions() {
    MyString greeting("Hello,");
    MyString cPlusPlus("C++");

    // '+' operation
    MyString result;
    result = greeting + cPlusPlus;
    cout << "'" << greeting << "' + '" << cPlusPlus << "' = '" << result << "'" << endl;

    // '-' operation
    MyString subtractIt("l+");
    cout << "'" << result << "' - '" << subtractIt << "' = '" << result - subtractIt << "'" << endl;

    // '*' operation
    cout << "'" << result << "' * 3 = '" << result * 3 << endl;
}

void testEqualityFunctions() {
    MyString cPlusPlus("C++");

    MyString javaLang("Java");
    cout << "'" << cPlusPlus << "' = '" << javaLang << "'. Now cPlusPlus variable = '";
    cPlusPlus = javaLang;
    cout << cPlusPlus << "'" << endl;

    MyString pythonLang("Python");
    cout << "'" << cPlusPlus << "' == '" << javaLang << "'? Answer: " << (cPlusPlus == javaLang) << endl;
    cout << "'" << javaLang << "' == '" << pythonLang << "'? Answer: " << (javaLang == pythonLang) << endl;
}

void testInequalityFunctions() {
    MyString string1("abcde");
    MyString string2("abcde");
    MyString string3("abcfe");
    MyString string4("abcdef");

    cout << "'" << string1 << "' < '" << string3 << "' is " << (string1 < string3) << endl;
    cout << "'" << string1 << "' > '" << string3 << "' is " << (string1 > string3) << endl;
    cout << "'" << string1 << "' < '" << string2 << "' is " << (string1 < string2) << endl;
    cout << "'" << string1 << "' <= '" << string2 << "' is " << (string1 <= string2) << endl;
    cout << "'" << string1 << "' < '" << string4 << "' is " << (string1 < string4) << endl;
    cout << "'" << string4 << "' > '" << string1 << "' is " << (string4 > string1) << endl;
}

void testOtherFunctions() {
    MyString hse("HSE university 2024");
    cout << "hse = '" << hse << "', !hse = '" << !hse << "'" << endl;

    cout << "Initial string: " << hse << endl;
    cout << "Char at 0 is '" << hse[0] << "'" << endl;
    cout << "Char at 5 is '" << hse[5] << "'" << endl;
    cout << "Char at 15 is '" << hse[15] << "'" << endl;

    cout << "Find 'HSE' in '" << hse << "' result: " << hse("HSE") << endl;
    cout << "Find 'uni' in '" << hse << "' result: " << hse("uni") << endl;
    cout << "Find 'Lobach' in '" << hse << "' result: " << hse("Lobach") << endl;
    cout << "Find 'hse' in '" << hse << "' result: " << hse("hse") << endl;
}

void testIOFunctions() {
    MyString programmingLanguage;
    cout << "Enter programming language: " << endl;
    cin >> programmingLanguage;
    cout << "You've entered '" << programmingLanguage << "'" << endl;
}