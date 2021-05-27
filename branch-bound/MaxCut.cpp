/* 1954263 宋子铭 计科 */
#include <iostream>
#include <queue>
using namespace std;

int n, m; 


class Node
{
public:
    int level;  //当前层
    int cut;  //割边数量
    int e;    //剩余边的数量
    int* x;   //解向量

    Node(int d, int c, int ee)
    {
        x = new int[n + 1];
        level = d;
        cut = c;
        e = ee;
    };
    
    bool operator < (const Node& node) const
    {
        return cut < node.cut;
    }
};

priority_queue<Node> q;

//添加结点
void addNode(int**a,Node enode, bool ch)
{
    Node now(enode.level + 1, enode.cut, enode.e);
    copy(enode.x, enode.x + n + 1, now.x);
    if (ch)
    {
        now.x[now.level] = 1;
        for (int j = 1; j <= n; j++)
            if (a[now.level][j])
                if (now.x[j] == 0) //如果当前顶点在割集中，但边的另一个顶点不在割集
                {
                    now.cut++;  //割边的数量增加
                    now.e--;    //剩余边的数量减少
                }
                else
                    now.cut--;
    }
    else
    {
        now.x[now.level] = 0;
        now.e--;
    }
    q.push(now);
}

int search(int **a,int *bestx)
{
    Node enode(0, 0, m);
    for (int j = 1; j <= n; j++)
        enode.x[j] = 0;
    int best = 0;
    while (true)
    {
        if (enode.level > n)
        {
            if (enode.cut > best)
            {
                best = enode.cut;
                copy(enode.x, enode.x + n + 1, bestx);
                break;
            }
        }
        else{
            addNode(a,enode, true);
            if (enode.cut + enode.e > best)
                addNode(a,enode, false);
        }
        if (q.empty())
            break;
        else{
            enode = q.top();//取下一扩展结点
            q.pop();
        }
    }
    return best;
}

int main()
{
    int u, v, i;
    cin >> n >> m;
    int* bestx = new int[n + 2];
    int** a = new int* [n + 2];
	for (int i = 1; i <= n+1; i++)
		a[i] = new int[n + 2];
    for (int i = 1; i <= n+1; i++)
    {
        for (int j = 1; j <= n+1; j++)
        {
            a[i][j] = 0;
        }
    }
    for (i = 1; i <= m; i++)
    {
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }

    cout << search(a,bestx) << endl;

    for (i = 1; i <= n; i++) {
        cout << bestx[i]<<" ";
    }
    cout << endl;
    for (int i = 1; i <= n+1; i++)
    {
        delete[] a[i];
    }
    delete[]a;
    delete[]bestx;
    return 0;
}


