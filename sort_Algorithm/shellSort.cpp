#include <iostream>

using namespace std;

void print(int [], int, int);
void shellInstertSort(int [], int, int);
void shellSort(int [], int);

int main()
{
    int a[8] = {3, 1, 5, 7, 2, 4, 9, 6};
    shellSort(a, 8);
}

// 打印数组
void print(int a[], int n, int j)
{
    cout << j << ":";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

// 希尔排序中的直接插入排序
void shellInstertSort(int a[], int n, int dk)
{
    // 遍历每一个元素
    for (int i = dk; i < n; i++)
    {
        if (a[i] < a[i - dk])
        {
            // 设置哨兵元素
            int j = i - dk;
            int x = a[i];
            // 元素后移
            a[i] = a[i - dk];
            while (x < a[j])
            {
                a[j + dk] = a[j];
                j -= dk;
            }
            a[j + dk] = x;  // 找到正确的位置
        }
        print(a, n, i);
    }
}

// 缩短比较间隔
void shellSort(int a[], int n)
{
    int dk = n / 2;
    while (dk >= 1)
    {
        shellInstertSort(a, n, dk);
        dk /= 2;
    }
}


