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
1.[BinarySearch](https://github.com/Iris-Song/algorithm/blob/main/Divide%26Conquer/BinarySearch.cpp)

2.[LargeIntegerMul](https://github.com/Iris-Song/algorithm/blob/main/Divide%26Conquer/LargeIntegerMul.cpp)

>Karatsuba algorithm
 
　　<img src=https://user-images.githubusercontent.com/58033867/111934290-16922400-8afc-11eb-9584-9ae8aaff2429.png width="30%">

　　<img src=https://user-images.githubusercontent.com/58033867/111934527-87d1d700-8afc-11eb-8bcc-d76e502898a0.png width="30%">

　　<img src=https://user-images.githubusercontent.com/58033867/111934475-7092e980-8afc-11eb-8cd2-80305af1e3fc.png width="30%">

>time complexity
>
　　<img src=https://user-images.githubusercontent.com/58033867/111934657-d1babd00-8afc-11eb-8499-941339f88d5e.png width="30%">

　　<img src=https://user-images.githubusercontent.com/58033867/111934687-df704280-8afc-11eb-90d0-7715ec196374.png width="20%">

3.[MaxSubMax　最大字段和](https://github.com/Iris-Song/algorithm/blob/main/Divide%26Conquer/MaxSubSum.cpp)

4.[Strassen　matrix]()

　　　设A、B、C为三个矩阵，每个矩阵都是n×n矩阵
   
   <img src=https://user-images.githubusercontent.com/58033867/112094495-562d3e80-8bd6-11eb-8198-a10a113e24aa.png width="50%">
   
   
　　花费时间<img src=https://user-images.githubusercontent.com/58033867/112095281-2d597900-8bd7-11eb-9a53-7e4f27f0ca69.png width="5%">

   如下创建10个的矩阵
   
 　　<img src=https://user-images.githubusercontent.com/58033867/112095332-42360c80-8bd7-11eb-9294-72eed39d1e25.png width="20%">

   
　　花费时间 <img src=https://user-images.githubusercontent.com/58033867/112095347-511cbf00-8bd7-11eb-93fd-a2e2cb3844a9.png width="5%">。

   递归地计算7个矩阵积<img src=https://user-images.githubusercontent.com/58033867/112095505-950fc400-8bd7-11eb-90be-179d4bc914a3.png width="10%">
 ，每个矩阵 <img src=https://user-images.githubusercontent.com/58033867/112095520-9e992c00-8bd7-11eb-95e8-5bb8001b57c9.png width="2%">
都是<img src=https://user-images.githubusercontent.com/58033867/112095450-7d384000-8bd7-11eb-8503-11c650a0b164.png  width="5%">
 的。

　　<img src=https://user-images.githubusercontent.com/58033867/112095583-b7a1dd00-8bd7-11eb-9851-52e9d733b7a9.png width="60%">


　　注意，上述公式中只有中间一列需要计算。

　　通过<img src=https://user-images.githubusercontent.com/58033867/112095678-e324c780-8bd7-11eb-9a34-8d956c35fdf0.png width="4%">
 计算 <img src=https://user-images.githubusercontent.com/58033867/112095692-e91aa880-8bd7-11eb-9e8f-8b235d8f5b81.png width="10%">
 ，花费时间 <img src=https://user-images.githubusercontent.com/58033867/112095727-f6d02e00-8bd7-11eb-88cb-0ce5583d98ca.png width="5%"> 。

   <img src=https://user-images.githubusercontent.com/58033867/112095647-d43e1500-8bd7-11eb-936d-e8408e505ba4.png width="30%">

　　综合可得如下递归式：
   <img src=https://user-images.githubusercontent.com/58033867/112095804-19624700-8bd8-11eb-8374-7e9680767b85.png width="30%">
　　进而求出时间复杂度为:
  <img src=https://user-images.githubusercontent.com/58033867/112095662-dbfdb980-8bd7-11eb-8461-bd629a0bdc29.png width="20%"> 

5.[棋盘覆盖](https://github.com/Iris-Song/algorithm/blob/main/Divide%26Conquer/ChessBoard.cpp)

6.[MergeSort](https://github.com/Iris-Song/algorithm/blob/main/Divide%26Conquer/MergeSort.cpp)

7.[QuickSort](https://github.com/Iris-Song/algorithm/blob/main/Divide%26Conquer/QuickSort.cpp)

8.线性时间选择

　　给定线性集中序n个元素和一个整数k，要求找出这n个元素中第k小的数
  
　　[变式](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/)



