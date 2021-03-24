#include<algorithm>
//求一个数组中最大的数
float MaxArray(float a[], int left, int right) {
    float max = a[left];
    for (int i = left+1; i <= right; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}
//求一个数组中最小的数
float MinArray(float a[], int left, int right) {
    float min = a[left];
    for (int i = left + 1; i <= right; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

//求一维点集S的最接近点对的算法，假设点的x坐标存储在数组a中，点的个数为right-left+1
//数组a自身已经从小到大排好序
//函数返回能否找到这样的两个点，d表示这两个点之间的距离
bool Cpair(float a[],int left,int right,float&d) {
    int n = right - left + 1;//点的个数
    if (n < 2) {
        d = INFINITY;
        return false;
    }
    int m = a[(n - 1) / 2];//各点坐标的中位数
    float p, q;
    Cpair(a, left, m, p);
    Cpair(a, m + 1, right,q);
    d = max(p, q, MinArray(a, m + 1, right) - MaxArray(a, 0, m));
}
