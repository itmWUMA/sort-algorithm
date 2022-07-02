#pragma once
#include "TestClass.h"
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Sort
{
private:
    static void Swap(TestClass &tc1, TestClass &tc2);

    // 快排递归函数
    static void _QuickSort(vector<TestClass> &v, int l, int r);

    // 快排partition
    static void Partition(vector<TestClass> &v, int l, int r, int &sr, int &lr, int pos);

    // 归并递归函数
    static void _MergeSort(vector<TestClass> &v, int l, int r);

    // 归并
    static void Merge(vector<TestClass> &v, int l, int r, int mid);

    // 堆化
    static void Heapify(vector<TestClass> &v, int pos, int heapSize);

    // 获取数组中最大位数
    static int GetMaxBit(const vector<TestClass> &v);

    // 获取整数第k位的值
    static int GetBitVal(int num, int k);

public:
    // 选择排序
    static void SelectSort(vector<TestClass> &v);

    // 冒泡排序
    static void BubbleSort(vector<TestClass> &v);

    // 插入排序
    static void InsertSort(vector<TestClass> &v);

    // 快速排序
    static void QuickSort(vector<TestClass> &v);

    // 归并排序
    static void MergeSort(vector<TestClass> &v);

    // 堆排序
    static void HeapSort(vector<TestClass> &v);

    // 桶排序
    static void RadixSort(vector<TestClass> &v);
};