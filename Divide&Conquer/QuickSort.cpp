int Partition(int a[], int low, int high)
{
    int pivotkey = a[low];
    while (low < high) {
        while (low < high && a[high] >= pivotkey)--high;
        swap(a[low], a[high]);
        while (low < high && a[low] <= pivotkey)++low;
        swap(a[low], a[high]);
    }
    return low;
}
void QSort(int a[], int low, int high)
{
    if (low < high) {
        int pivotloc = Partition(a, low, high);
        QSort(a, low, pivotloc - 1);
        QSort(a, pivotloc + 1, high);
    }
}
void QuickSort(int a[]) 
{
    QSort(a, 1, n);
}
