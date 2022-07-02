#include "Sort.h"

void Sort::Swap(TestClass &tc1, TestClass &tc2)
{
    TestClass temp = tc1;
    tc1 = tc2;
    tc2 = temp;
}

void Sort::SelectSort(vector<TestClass> &v)
{
    if (v.size() <= 1)
        return;
    int size = (int)v.size();
    for (int i = 0; i < size; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
            minIndex = (v[minIndex] > v[j] ? j : minIndex);
        Swap(v[minIndex], v[i]);
    }
}

void Sort::BubbleSort(vector<TestClass> &v)
{
    if (v.size() <= 1)
        return;
    int size = (int)v.size();
    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[j] > v[j + 1])
                Swap(v[j], v[j + 1]);
        }
    }
}

void Sort::InsertSort(vector<TestClass> &v)
{
    if (v.size() <= 1)
        return;
    int size = (int)v.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j > 0 && v[j] < v[j - 1]; j--)
            Swap(v[j], v[j - 1]);
    }
}

void Sort::QuickSort(vector<TestClass> &v)
{
    if (v.size() <= 1)
        return;
    _QuickSort(v, 0, v.size() - 1);
}

void Sort::Partition(vector<TestClass> &v, int l, int r, int &sr, int &lr, int pos)
{
    sr = l - 1, lr = r + 1;
    int i = l;
    TestClass val = v[pos];
    while (i < lr)
    {
        // 小于区
        if (v[i] < val)
            Swap(v[i++], v[sr++ + 1]);
        // 等于区
        else if (v[i] == val)
            i++;
        // 大于区
        else
            Swap(v[i], v[lr-- - 1]);
    }
}

void Sort::_QuickSort(vector<TestClass> &v, int l, int r)
{
    if (l < r)
    {
        int pos = rand() % (r - l) + l;
        int sr = 0, lr = 0;
        Partition(v, l, r, sr, lr, pos);
        _QuickSort(v, l, sr);
        _QuickSort(v, lr, r);
    }
}

void Sort::Merge(vector<TestClass> &v, int l, int r, int mid)
{
    vector<TestClass> temp;
    int i = l, j = mid + 1, cur = 0;
    while (i <= mid && j <= r)
    {
        if (v[j] < v[i])
            temp.push_back(v[j++]);
        else
            temp.push_back(v[i++]);
    }
    while (i <= mid)
        temp.push_back(v[i++]);
    while (j <= r)
        temp.push_back(v[j++]);
    ::copy(temp.begin(), temp.end(), v.begin() + l);
}

void Sort::_MergeSort(vector<TestClass> &v, int l, int r)
{
    if (l < r)
    {
        int mid = l + ((r - l) >> 1);
        _MergeSort(v, l, mid);
        _MergeSort(v, mid + 1, r);
        Merge(v, l, r, mid);
    }
}

void Sort::MergeSort(vector<TestClass> &v)
{
    if (v.size() <= 1)
        return;
    _MergeSort(v, 0, v.size() - 1);
}

void Sort::Heapify(vector<TestClass> &v, int pos, int heapSize)
{
    int l = pos * 2 + 1, r = l + 1;
    while (l < heapSize)
    {
        int maxIndex = (r < heapSize && v[r] > v[l]) ? r : l;
        maxIndex = (v[pos] > v[maxIndex]) ? pos : maxIndex;
        if (pos == maxIndex)
            return;
        Swap(v[pos], v[maxIndex]);
        pos = maxIndex;
        l = pos * 2 + 1;
        r = l + 1;
    }
}

void Sort::HeapSort(vector<TestClass> &v)
{
    int size = (int)v.size();
    for (int i = size - 1; i >= 0; i--)
        Heapify(v, i, size);

    while (size > 0)
    {
        Swap(v[0], v[size - 1]);
        Heapify(v, 0, --size);
    }
}

int Sort::GetMaxBit(const vector<TestClass> &v)
{
    int max = ::max_element(v.begin(), v.end())->num;
    int count = 0;
    while (max)
    {
        max /= 10;
        count++;
    }
    return count;
}

int Sort::GetBitVal(int num, int k)
{
    int count = 0, res = 0;
    while (count < k)
    {
        res = num % 10;
        num /= 10;
        count++;
    }
    return res;
}

void Sort::RadixSort(vector<TestClass> &v)
{
    // 获取最大位数
    int d = GetMaxBit(v);

    // 初始化桶
    vector<queue<TestClass>> buckets(10, queue<TestClass>());
    int size = (int)v.size();

    
    for (int i = 0; i < d; i++)
    {
        int index = 0;
        // 入桶
        for (int j = 0; j < size; j++)
            buckets[GetBitVal(v[j].num, i + 1)].push(v[j]);
        // 出桶
        for (int j = 0; j < 10; j++)
        {
            while (!buckets[j].empty())
            {
                v[index++] = buckets[j].front();
                buckets[j].pop();
            }
        }
    }
}