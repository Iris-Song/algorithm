# Union Find
## template
```
class UnionFind:
    def __init__(self, n):
        self.rank = [1]*n
        self.par = list(range(n))

    def find(self, x):
        while x != self.par[x]:
            self.par[x] = self.par[self.par[x]]
            x = self.par[x]
        return x

    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px == py:
            # no need to merge
            return False
        if self.rank[px] > self.rank[py]:
            self.rank[px] += self.rank[py]
            self.par[py] = px
        else:
            self.rank[py] += self.rank[px]
            self.par[px] = py
        return True
```

### Leetcode
[Valid Tree](https://github.com/doocs/leetcode/blob/main/solution/0200-0299/0261.Graph%20Valid%20Tree/README.md)

### [Reference](https://github.com/labuladong/fucking-algorithm/blob/master/%E7%AE%97%E6%B3%95%E6%80%9D%E7%BB%B4%E7%B3%BB%E5%88%97/UnionFind%E7%AE%97%E6%B3%95%E8%AF%A6%E8%A7%A3.md)
