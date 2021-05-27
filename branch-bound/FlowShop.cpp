#include "Heap.cpp"

class FlowShop;
class MinHeapNode {
    friend FlowShop;
public:
    operator int()const { return bb; }
private:
    void Init(int);
    void NewNode(MinHeapNode, int, int, int, int);
    int s,//已安排作业数
        f1,//机器1上最后完成时间
        f2,//机器2上最后完成时间
        sf2,//当前机器2上完成时间和
        bb,//当前完成时间和下界
        * x;//当前作业调度
};
void MinHeapNode::Init(int n) {
    x = new int[n];
    for (int i = 0; i < n; i++)
        x[i] = i;
    s = 0;
    f1 = f2 = 0;
    sf2 = 0;
    bb = 0;
}
void MinHeapNode::NewNode(MinHeapNode E, int Ef1, int Ef2, int Ebb, int n) {
    x = new int[n];
    for (int i = 0; i < n; i++)
        x[i] = E.x[i];
    f1 = Ef1;
    f2 = Ef2;
    sf2 = E.sf2+f2;
    bb = Ebb;
    s = E.s + 1;
}
class FlowShop {
    friend int main();
public:
    int BBFlow(void);
private:
    int Bound(MinHeapNode, int&, int&, bool**);
    void Sort();
    int n,//作业数
        ** M,//各作业所需的处理时间数组
        ** b,//各作业所需的处理时间排序数组
        ** a,//数组M和b的对应关系数组
        * bestx,//,最优解
        bestc;//最小完成时间和
    bool** y;//工作数组
};
void FlowShop::Sort() {//从小到大排序
    int* c = new int[n];
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            b[i][j] = M[i][j];
            c[i] = i;
        }
        for (int i = 0; i < n - 1; i++) {
            for (int k = n - 1; k > i; k--) {
                if (b[k][j] < b[k - 1][j]) {
                    swap(b[k][j], b[k - 1][j]);
                    swap(c[k], c[k - 1]);
                }
                for (int i = 0; i < n; i++)
                    a[c[i]][j] = i;
            }
        }
    }
    delete[]c;
}
int FlowShop::Bound(MinHeapNode E, int& f1, int& f2, bool** y) {
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < 2; j++) {
            y[k][j] = false;
        }
    }
    for (int k = 0; k <= E.s; k++)
        for (int j = 0; j < 2; j++)
            y[a[E.x[k]][j]][j] = true;
    f1 = E.f1 + M[E.x[E.s]][0];
    f2 = ((f1 > E.f2) ? f1 : E.f2) + M[E.x[E.s]][1];
    int sf2 = E.sf2 + f2;
    int s1 = 0, s2 = 0, k1 = n - E.s, k2 = n - E.s, f3 = f2;
    for (int j = 0; j < n; j++) {
        if (!y[j][0]) {
            k1--;
            if (k1 == n - E.s - 1)
                f3 = (f2 > f1 + b[j][0]) ? f2 : f1 + b[j][0];
            s1 += f1 + k1 * b[j][0];
        }
    }
    for (int j = 0; j < n; j++) {
        if (!y[j][1]) {
            k2--;
            s1 += b[j][1];
            s2 += f3 + k2 * b[j][1];
        }
    }
    return sf2 + max(s1, s2);
}
int FlowShop::BBFlow() {
    Sort();
    MinHeap<MinHeapNode>H(1000);
    MinHeapNode E;
    E.Init(n);
    while (E.s <= n) {
        if (E.s == n) {
            if (E.sf2 < bestc) {
                bestc = E.sf2;
                for (int i = 0; i < n; i++) {
                    bestx[i] = E.x[i];
                }
            }
            delete[]E.x;
        }
        else {
            for (int i = E.s+1; i < n; i++) {
                swap(E.x[E.s], E.x[i]);
                int f1, f2;
                int bb = Bound(E, f1, f2, y);
                if (bb < bestc) {
                    MinHeapNode N;
                    N.NewNode(E, f1, f2, bb, n);
                    H.Insert(N);
                }
                swap(E.x[E.s], E.x[i]);
            }
            delete[] E.x;
        }
        if (H.Size() == 0)break;
        H.DeleteMin(E);  
    }
    return bestc;
}
