int Ackerman(int n, int m) {
    if (n == 1&&m == 0)
        return 2;
    if (n == 0 && m >= 0)
        return 1;
    if (n >= 2 && m == 0)
        return n + 2;
    if (n >= 1 && m >= 1)
        return Ackerman(Ackerman(n - 1, m), m - 1);
    else return -1;//n,m²»·ûºÏ·¶Î§
}
