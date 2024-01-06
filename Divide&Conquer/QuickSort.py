def partition(nums, low, high):
    # 进行分区操作，选取第一个值为基准
    pivot = nums[low]
    i = low
    j = high
    while i < j:
        # j是从右向左走，如果值大于pivot则位置保持不变，j左移
        while i < j and nums[j] >= pivot:
            j -= 1
        # 不满足上述条件时，nums[j]<pivot,应该放在左边，所以将i位置赋值为j
        # 此时j位置空出
        nums[i] = nums[j]
        # I是从左向右走，如果值小于pivot则位置保持不变，i右移
        while i < j and nums[i] < pivot:
            i += 1
        # 不满足上述条件时，nums[i]>=pivot,应该放在右边，所以将h位置赋值为i
        # 此时j位置空出
        nums[j] = nums[i]
    # 将pivot的值放到正确的索引位置
    nums[i] = pivot
    return  i

# 快速排序函数
def quickSort(arr, low, high):
    # arr[] --> 排序数组
    # low  --> 起始索引
    # high  --> 结束索引
    if low < high:
        pi = partition(arr, low, high)   #pi为基准值的正确索引位置
        quickSort(arr, low, pi - 1)  #递归的排序子序列
        quickSort(arr, pi + 1, high) #递归的排序子序列
    return arr