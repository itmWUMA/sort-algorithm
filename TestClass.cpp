#include "TestClass.h"

void TestClass::fun()
{
    
}

bool TestClass::operator<(const TestClass& tc) const
{
    return this->num < tc.num;
}

bool TestClass::operator>(const TestClass& tc) const
{
    return this->num > tc.num;
}

bool TestClass::operator==(const TestClass& tc) const
{
    return this->num == tc.num;
}

bool TestClass::operator!=(const TestClass& tc) const
{
    return !(*this == tc);
}
