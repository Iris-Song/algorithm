/*x是要找的数字，l和r是左右两侧的下标,函数返回下标位置，若没有找到，返回-1*/
int BinarySearch(int a[], const int& x, int l, int r)
{
    while (r >= l) {
        int m = (l + r) / 2;
        if (x == a[m]) return m;
        if (x < a[m]) r = m - 1; 
        else l = m + 1;
    }
    return -1;
}
int BinarySearch(int a[], const int& x, int l, int r)
{
    if (r < l)
        return -1;
    int mid = (r + l) / 2;
    if (a[mid] == x)
        return mid;
    if (x < a[mid])
        return BinarySearch(a, x, l, mid - 1);
    else
        return BinarySearch(a, x, mid + 1, r);
}
