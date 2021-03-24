//quick sort
int Partition(int a[], int low, int high,int pivotkey) {
    while (low < high) {
        while (low < high && a[high] >= pivotkey)--high;
        swap(a[low], a[high]);
        while (low < high && a[low] <= pivotkey)++low;
        swap(a[low], a[high]);
    }
    return low;
}
void QSort(int a[], int low, int high) {
    if (low < high) {
        int pivotloc = Partition(a, low, high,a[low]);
        QSort(a, low, pivotloc - 1);
        QSort(a, pivotloc + 1, high);
    }
}

void SelectSort(int a[], int len) {
    int j;
    for (int i = 1; i <= len; i++) {
        int min = i;
        for (j = i + 1; j < len; j++)     //走訪未排序的元素
            if (a[j] < a[min])    //找到目前最小值
                min = j;    //紀錄最小值
        if (min != i) {
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }

}

int select(int a[], int left, int right, int k) {
    if (right - left < 75) {
        QSort(a, 1, right-left+1);//快速排序
        return a[left + k - 1];
    }
    for (int i = 0; i <= (right - left - 4) / 5; i++) {
        //将a[p+5*i]至a[p+5*i+4]的中位数与a[p+i]交换位置
        SelectSort(a + left + 5 * i, 5);
        swap(a[left + 5 * i + 2], a[left + i]);
        //找中位数的中位数
        int x = select(a, left, left + (right - left - 4) / 5, (right - left - 4) / 10);
        int ii = Partition(a, left, right, x);
        int j = ii - left + 1;
        if (k <= j)
            return select(a, left, i, k);
        else
            return select(a, i + 1, right, k - j);
    }
    
}
