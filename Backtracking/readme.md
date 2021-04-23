# BACKTRACKING
## pseudocode
```
t:递归深度
output(x):记录或输出得到的可行解
f(n,t):当前扩展结点处未搜索过的子树的起始编号
g(n,t):当前扩展结点处未搜索过的子树的终止编号
Constraint(t):当前扩展结点处的约束函数
Bound(t):当前扩展结点处的限界函数
```
```
void Backtrack(int n){
   if(t>n)
     Output(x);
}
```
## problem
1.
