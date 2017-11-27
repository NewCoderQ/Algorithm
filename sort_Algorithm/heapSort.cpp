#include <iostream>

using namespace std;

void print(int [], int);
void heapSort(int [], int);
void buildHeap(int [], int);    // 初始化堆
void heapAdjust(int[], int, int);

void heapAdjust(int h[], int s, int length)
{
    int tmp = h[s];
    int child = 2 * s + 1; // 左子节点的位置
                           // child + 1表示右子节点的索引
    while (child < length)
    {
        if (child + 1 < length && h[child] < h[child + 1])
        {
            child++;    // 此时的child指向右子节点
        }
        
        if (h[s] < h[child])
        {
            h[s] = h[child];
            s = child;  // 待调整的下一个节点的位置
            child = 2 * s + 1;
        } 
        else 
            break;
        h[s] = tmp; // 将原本的根节点的值赋值到新位置
    }
    print(h, length);
}


void buildHeap(int h[], int length)
{
    // 最后一个有孩子的节点的位置i = (length - 1) / 2
    for (int i = (length - 1) / 2; i >= 0; --i)
        heapAdjust(h, i, length);       // 小顶
}

void heapSort(int h[], int length)
{
    // 初始化堆
    buildHeap(h, length);
    for (int i = length - 1; i > 0; i--)
    {
        // 交换堆顶元素和堆中的最后一个元素
        int tmp = h[i];
        h[i] = h[0];
        h[0] = tmp;
        // 重新对堆进行调整
        heapAdjust(h, 0, i);
    }
}

void print(int a[], int n)
{
    for (int j = 0; j < n; j++)
    {
        cout << a[j] << " ";
    }
    cout << endl;
}



int main()
{
    int H[10] = {3,1,5,7,2,4,9,6,10,8};
    cout << "初始值:";
    print(H, 10);
    heapSort(H, 10);
}