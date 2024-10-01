# Sweep Line
## condition
1. sorted order list/array...

    startTime = 1, endTime = -1
    ```
    customer = [[1,2],         [3,4],         [2,5]  ···   ]
    events =   [[1,1], [2,-1], [3,1], [4,-1], [2,1], [5,-1] ···   ]
    events.sort(lambda x:x[0])
    ```

## time complexity
O(n)

## problem
[218. The Skyline Problem](https://leetcode.cn/problems/the-skyline-problem/description/)
[391. Perfect Rectangle](https://leetcode.com/problems/perfect-rectangle/description/)
[850. Rectangle Area II](https://leetcode.com/problems/rectangle-area-ii/description/)
[1851. Minimum Interval to Include Each Query](https://leetcode.com/problems/minimum-interval-to-include-each-query/description/)