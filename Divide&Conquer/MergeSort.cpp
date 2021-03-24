//solution 1
template <class Type>
void Merge(Type c[], Type d[], int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    while ((i <= m) && (j <= r))
        if (c[i] < c[j])d[k++] = c[i++];
        else d[k++] = c[j++];
    if (i > m)for (int q = j; q <= r; q++)d[k++] = c[q];
    else for (int q = i; q <= m; q++)d[k++] = c[q];
}
template <class Type>
void MergeSort(Type a[], int left, int right) 
{
    if (left < right) {
        int i = (left + right) / 2;
        MergeSort(a, left, i);
        MergeSort(a, i + 1，right);
        //定义变量b
        Merge(a, b, left, i, right);
        copy(a, b, left, right);
    }
}

//solution 2
int min(int x, int y) {
    return x < y ? x : y;
}
void merge_sort(int arr[], int len) {
    int* a = arr;
    int* b = (int*)malloc(len * sizeof(int));
    int seg, start;
    for (seg = 1; seg < len; seg += seg) {
        for (start = 0; start < len; start += seg * 2) {
            int low = start, mid = min(start + seg, len), high = min(start + seg * 2, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        int* temp = a;
        a = b;
        b = temp;
    }
    if (a != arr) {
        int i;
        for (i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    free(b);
}
