#pragma once
#include <string>

class TestClass
{
public:
    int num;
    std::string str;

    TestClass(int num, std::string str) : num(num), str(str) {}

    void fun();

    bool operator<(const TestClass& tc) const;
    bool operator>(const TestClass& tc) const;
    bool operator==(const TestClass& tc) const;
    bool operator!=(const TestClass& tc) const;
};