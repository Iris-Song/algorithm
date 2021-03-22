# DIVIDE & CONQUER  
## pseudocode
```
divide-and-conquer(P)
  {  
    if ( | P | <= n0) adhoc(P);   //解决小规模的问题  
    divide P into smaller subinstances P1,P2,...,Pk；//分解问题  
    for (i=1,i<=k,i++)  
      divide-and-conquer(Pi);  //递归的解各子问题  
    return merge(y1,...,yk);  //将各子问题的解合并为原问题的解  
  }
```
## time complexity
　　一个分治法将规模为n的问题分成k个规模为n／m的子问题去解。设分解阈值n0=1，且adhoc解规模为1的问题耗费1个单位时间。再设将原问题分解为k个子问题以及用merge将k个子问题的解合并为原问题的解需用f(n)个单位时间。用T(n)表示该分治法解规模为|P|=n的问题所需的计算时间，则有：  
　　<img src=https://user-images.githubusercontent.com/58033867/111931117-7a651e80-8af5-11eb-9c9f-abddd2d5d3b9.png width="30%">
 
 　　<img src=https://user-images.githubusercontent.com/58033867/111931976-5efb1300-8af7-11eb-87a5-30663406c3f3.png width="30%">

## problem
1.二分搜索技术

2.大整数乘法
