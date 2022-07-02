#include "TestClass.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Test
{
private:
    vector<TestClass> base;
    int testCount; // 测试次数

public:
    Test(int testCount)
    {
        this->testCount = testCount;
        for (int i = 0; i < testCount; i++)
        {
            string str = ::to_string(rand() % 10000);
            base.push_back(TestClass(rand() % 1000, str));
        }
    }

    // 测试函数
    template <typename SortMethod>
    bool TestSort(SortMethod s)
    {
        // 拷贝数据 用于测试
        vector<TestClass> copy1 = vector<TestClass>(base);
        vector<TestClass> copy2 = vector<TestClass>(base);

        // 标准库函数作为对照组
        ::sort(copy1.begin(), copy1.end());
        // 传入排序方法作为实验组
        s(copy2);

        // 比较
        for (int i = 0; i < (int)base.size(); i++)
        {
            if (copy1[i] != copy2[i])
                return false;
        }

        return true;
    }

    // 排序并打印测试数组
    template <typename SortMethod>
    void SortAndPrint(SortMethod s)
    {
        // 排序
        s(base);
        // 打印
        for (auto elem : base)
            cout << "{" << elem.num << " , " << elem.str << "}" << endl;
    }
};