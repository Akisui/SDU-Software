#include <iostream>
using namespace std;

const int maxn = 20;
int a[maxn];
int temp[maxn];

void bubbleSort(int a[], int nums)
{
    int i, j, tmp;
    for (i = 0; i < nums - 1; ++i)
        for (j = 0; j < nums - 1 - i; ++j)
            if (a[j + 1] < a[j])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
    for (int i = 0; i < nums; ++i)
    {
        if (i == 0)
        {
            cout << a[i];
            continue;
        }
        cout << "，" << a[i];
    }
    cout << endl;
    return;
}

void insertSort(int a[], int nums)
{
    int i, j, tmp;
    for (i = 1; i < nums; ++i)
    {
        tmp = a[i];
        int j;
        for (j = i - 1; j >= 0 && a[j] > tmp; --j)
            a[j + 1] = a[j];
        a[j + 1] = tmp;
    }
    for (int i = 0; i < nums; ++i)
    {
        if (i == 0)
        {
            cout << a[i];
            continue;
        }
        cout << "，" << a[i];
    }
    cout << endl;
    return;
}

void mergeSort(int a[], int l, int r)
{
    if (l >= r) return;
    int mid = (l + r) >> 1;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (a[i] < a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
    for (int i = l, j = 0; i <= r; ++i, ++j) a[i] = temp[j];
}

int main()
{
    int x;
    int cnt = 18;
    cout << "Input" << endl;
    for (int i = 1;; ++i)
    {
        cin >> x;
        if (x == 0)
        {
            cnt = i - 1;
            break;
        }
        a[i - 1] = x;
    }
    cout << "1-Bubble Sort,2-Insert Sort,3-Merge Sort" << endl;
    int option;
    cin >> option;
    cout << "Output" << endl;
    if (option == 1)
    {
        cout << "Bubble Sort" << endl;
        bubbleSort(a, cnt);
    }
    else if (option == 2)
    {
        cout << "Insert Sort" << endl;
        insertSort(a, cnt);
    }
    else
    {
        cout << "Merge Sort" << endl;
        mergeSort(a, 0, cnt - 1);
        for (int i = 0; i < cnt; ++i)
        {
            if (i == 0)
            {
                cout << a[i];
                continue;
            }
            cout << "，" << a[i];
        }
        cout << endl;
    }
    cout << "End0" << endl;
    return 0;
}

