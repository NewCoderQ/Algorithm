#include <iostream>

using namespace std;

void selectSort(int [], int);

// 返回后面的子数组中的最小值的索引
int selectMinKey(int [], int, int);
void print(int[], int);

void print(int a[], int n, int i)
{
    cout << i << ":";
    for (int j = 0; j < n; j++)
    {
        cout << a[j] << " ";
    }
    cout << endl;
}

int selectMinKey(int a[], int n, int i)
{
    int k = i;
    for (int j = i + 1; j < n; j++)
    {
        if (a[k] > a[j]) k = j;
    }
    return k;
}

void selectSort(int a[], int n)
{
    int key, tmp;
    for (int i = 0; i < n; i++)
    {
        key = selectMinKey(a, n, i);
        if (key != i)
        {
            tmp = a[i];
            a[i] = a[key];
            a[key] = tmp;
        }
        print(a, n, i);
    }
}

int main()
{
    int a[8] = {3, 1, 5, 7, 2, 4, 9, 6};
    cout << "初始值为:";
    for  (int i = 0; i < 8; i++)
        cout << a[i] << " ";
    selectSort(a, 8);
    return 0;
}