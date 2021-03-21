//在n的划分中，最大加数k不大于m的划分个数记做DivideNum(n,m)
int DivideNum(int n, int m) {
    if (n < 1 || m < 1)
        return 0;
    if (n == 1 || m == 1)
        return 1;
    if (n < m)
        return DivideNum(n, n);
    if (n == m)
        return DivideNum(n, m - 1)+1;
    return DivideNum(n, m - 1) + DivideNum(n - m, m);
}
