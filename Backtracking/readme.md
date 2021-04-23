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
## problem
1.
