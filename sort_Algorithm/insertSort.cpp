#include <iostream>

using namespace std;

void print(int [], int, int);
void InsertSort(int [], int);

/*
    在直接插入排序中，哨兵元素的作用是将其
    与之前排序完成的元素进行比较，最终的到
    某元素应该的存放位置。
*/

int main()
{
    // 创建需要进行排序的原数组
    int a[8] = {3, 1, 5, 7, 2, 4, 9, 6};
    InsertSort(a, 8);
}

// 打印排序完成的数组
void print(int a[], int n, int i)
{
    cout << i << ":";

    for (int j = 0; j < 8; j++)
    {
        cout << a[j] << " ";
    }
    cout << endl;
}

// 对数组进行插入排序
// 第一个参数为需要排序的数据
// 第二个参数为该数组的长度
void InsertSort(int a[], int n)
{
    // 遍历数组的每一个元素，注意此处从第二个元素开始
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            int j = i - 1;
            int x = a[i];   // 复制为哨兵
            // 将元素调换为位置
            a[i] = a[i - 1];    // 元素后移
            // 查找哨兵元素需要插入的位置
            while (x < a[j])
            {
                // 将对应的元素后移动
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = x;
        }
        print(a, n, i);
    }
}





















