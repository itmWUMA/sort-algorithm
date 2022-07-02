#include "Sort.h"
#include "Test.hpp"
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand((unsigned int)time(NULL));

    Test t(1000);

    // bool res = t.TestSort(Sort::SelectSort);
    // bool res = t.TestSort(Sort::BubbleSort);
    // bool res = t.TestSort(Sort::InsertSort);
    bool res = t.TestSort(Sort::RadixSort);
    cout << "RadixSort : " << (res ? "PASS" : "FAIL") << endl;

    t.SortAndPrint(Sort::RadixSort);

    return 0;
}