//依x坐标排序的点
class PointX {
public:
    int operator<=(PointX a)const {
        return(x <= a.x);
    }
    int ID;//点标号
    float x, y;//点坐标
};

//依y坐标排序的点
class PointY {
public:
    int operator<=(PointY a)const {
        return(y <= a.y);
    }
    int ID;//在数组X中的坐标
    float x, y;//点坐标
};

//平面上任意两点的距离
template < class Type>
inline float distance(const Type& u, const Type& v)
{
    float dx = u.x - v.x;
    float dy = u.y - v.y;
    return sqrt(dx * dx + dy * dy);
}
void Merge(PointY Z[], PointY Y[], int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    while ((i <= m) && (j <= r))
        if (Z[i].y < Z[j].y) { 
            Y[k++].x = Z[i++].x;
            Y[k++].y = Z[i++].y; 
            Y[k++].ID = Z[i++].ID;
        }
        else {
            Y[k++].x = Z[j++].x;
            Y[k++].y = Z[j++].y;
            Y[k++].ID = Z[j++].ID;
        }
    if (i > m)for (int q = j; q <= r; q++){
        Y[k++].x = Z[q++].x;
        Y[k++].y = Z[q++].y;
        Y[k++].ID = Z[q++].ID;
    }
    else for (int q = i; q <= m; q++){
        Y[k++].x = Z[q++].x;
        Y[k++].y = Z[q++].y;
        Y[k++].ID = Z[q++].ID;
    }
}

void MergeSort(PointY Y[], int left, int right)
{
    if (left < right) {
        
        int mid = (left + right) / 2;
        MergeSort(Y, left, mid);
        MergeSort(Y, mid + 1,right);
        int f = left, g = mid + 1;
        PointY* Z = new PointY[right-left+2];
        for (int i = left; i <= right; i++) {
            if (Y[i].ID > mid) {
                Z[g].ID = Y[i].ID;
                Z[g].x = Y[i].x;
                Z[g].y = Y[i].y;
                g++;
            }
            else
            {
                Z[f].ID = Y[i].ID;
                Z[f].x = Y[i].x;
                Z[f].y = Y[i].y;
                f++;
            }
        }
        Merge(Z, Y, left, mid, right);
        for (int i = left; i <= right; i++) {
            Y[i].ID = Z[i].ID;
            Y[i].x = Z[i].x;
            Y[i].y = Z[i].y;
        }
        delete[]Z;
    }
}

void closet(PointX X[], PointY Y[], PointY Z[], int l, int r, PointX& a, PointX& b, float& d) {
    if (r - l == 1) {
        //两点的情形
        a = X[1];
        b = X[2];
        d = distance(X[1], X[2]);
        return;
    }
    if (r - 1 == 2) {
        //三点的情形
        float d1 = distance(X[1], X[2]);
        float d2 = distance(X[1], X[3]);
        float d3 = distance(X[3], X[2]);
        d=min(d1, d2, d3);
        return;
    }
    int m = (l + r) / 2;
    int f = l, g = m + 1;
    for (int i = l; i <= r; i++) {
        if (Y[i].ID > m) {
            Z[g].ID = Y[i].ID;
            Z[g].x = Y[i].x;
            Z[g].y = Y[i].y;
            g++;
        }
        else
        {
            Z[f].ID = Y[i].ID;
            Z[f].x = Y[i].x;
            Z[f].y = Y[i].y;
            f++;
        }
    }
    closet(X, Z, Y, l, m, a, b, d);
    float dr;
    PointX ar, br;
    closet(X, Z, Y, m + 1, r, ar, br, dr);
    if (dr < d) {
        a = ar;
        b = br;
        d = dr;
    }
    Merge(Z, Y, l, m, r);//重构数组Y
    int k = l;
    for (int i = l; i <= r; i++) {
        if (fabs(Y[m].x - Y[i].x) < d)Z[k++] = Y[i];
    }
    for (int i = l; i < k; i++) {
        for (int j = i + 1; j < k && Z[j].y - Z[i].y < d; j++) {
            float dp = distance(Z[i], Z[j]);
            if (dp < d) {
                d = dp;
                a = X[Z[i].ID];
                b = X[Z[j].ID];
            }
        }
    }
}

bool Cpair2(PointX X[], int n, PointX& a, PointX& b, float& d) {
    if (n < 2) {
        d = INFINITY;
        return false;
    }
    PointY* Y = new PointY[n];
    for (int i = 0; i < n; i++) {
        //将数组X中的点复制到数组Y中
        Y[i].ID = i;
        Y[i].x = X[i].x;
        Y[i].y = X[i].y;
    }
    MergeSort(Y, 1,n);
    PointY* Z = new PointY[n];
    closet(X, Y, Z, 0, n - 1, a, b, d);
    delete[]Y;
    delete[]Z;
    return true;
}
