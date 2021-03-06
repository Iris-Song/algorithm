# BACKTRACKING
## pseudocode
```
t:递归深度
output(x):记录或输出得到的可行解
f(n,t):当前扩展结点处未搜索过的子树的起始编号
g(n,t):当前扩展结点处未搜索过的子树的终止编号
Constraint(t):当前扩展结点处的约束函数
Bound(t):当前扩展结点处的限界函数
Solution(t):当前扩展结点处是否已得到问题的可行解
```
```
/*recursive backtracking*/
void Backtrack(int n){
   if(t>n)
     Output(x);
   else{
     for(int i=f(n,t);i<g(n,t);i++){
       x[t]=h(i);
       if(Constraint(t)&&Bound(t))
         Backtrack(t+1);
     }
  }
}
```
```
/*iterative backtracking*/
void Backtrack(){
   int t=1;
   while(t>0){
      if(f(n,t)<=g(n,t)){
        for(int i=f(n,t);i<=g(n,t);i++){
           x[t]=h(i);
           if(Constraint(t)&&Bound(t)){
              if(Solution(t))
                 Output(x);
              else
                 t++;
           }       
         }
       }
       else
         t--;
   }
}
```
```
/*backtrack subtree*/
void Backtrack(int t){
  if(t>n)
     Output(x);
   else{
     for(int i=0;i<=n;i++){
       x[t]=i;
       if(Constraint(t)&&Bound(t))
         Backtrack(t+1);
      }
   }
}
```
```
/*backtrack permutation tree*/
void Backtrack(int t){
  if(t>n)
     Output(x);
   else{
     for(int i=t;i<=n;i++){
       swap(x[t],x[i]);
       if(Constraint(t)&&Bound(t))
         Backtrack(t+1);
       swap(x[t],x[i]);
      }
   }
}
```
## problem
1.Maxloading 最优装载

　[recursion](https://github.com/Iris-Song/algorithm/blob/main/Backtracking/Maxloading-recur.cpp)　
 
　[iteration](https://github.com/Iris-Song/algorithm/blob/main/Backtracking/Maxloading-iteration.cpp)

2.[Triangle signal](https://github.com/Iris-Song/algorithm/blob/main/Backtracking/Triangle%20signal.cpp)

3.[JobFlow 批处理作业调度](https://github.com/Iris-Song/algorithm/blob/main/Backtracking/JobFlow.cpp)

4.[nQueen](https://github.com/Iris-Song/algorithm/blob/main/Backtracking/nQueen.cpp)

5.[0-1 bag problem](https://github.com/Iris-Song/algorithm/blob/main/Backtracking/bag0-1.cpp)

6.[MaxClique 最大团问题](https://github.com/Iris-Song/algorithm/blob/main/Backtracking/MaxClique.cpp)

7.[mColoring 图的m着色问题](https://github.com/Iris-Song/algorithm/blob/main/Backtracking/mColoring.cpp)


8.[TravelingSeller 旅行售货员问题](https://github.com/Iris-Song/algorithm/blob/main/Backtracking/Traveling.cpp)

9.[CirclePerm 圆排列问题](https://github.com/Iris-Song/algorithm/blob/main/Backtracking/CirclePerm.cpp)

10.[MaxStamp 最大邮资问题](https://github.com/Iris-Song/algorithm/blob/main/Backtracking/MaxStamp.cpp)
