#include <iostream>
using namespace std;

int merge(int a[], int l, int mid, int r)
{
    int inv = 0;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a1[n1], a2[n2];
    for (int i = 0; i < n1; i++)
    {
        a1[i] = a[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        a2[i] = a[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (a1[i] <= a2[j])
        {
            a[k] = a1[i];
            i++;
        }
        else
        {
            a[k] = a2[j];
            j++;
            inv += (n1 - i); // Count inversions here
        }
        k++;
    }

    // Copy the remaining elements of a1[], if there are any
    while (i < n1)
    {
        a[k] = a1[i];
        i++;
        k++;
    }

    // Copy the remaining elements of a2[], if there are any
    while (j < n2)
    {
        a[k] = a2[j];
        j++;
        k++;
    }
    return inv;
}

int mergesort(int a[], int l, int r)
{
    int inv = 0;
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        inv += mergesort(a, l, mid);
        inv += mergesort(a, mid + 1, r);
        inv += merge(a, l, mid, r);
    }
    return inv;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << mergesort(a, 0, n - 1);
    return 0;
}
