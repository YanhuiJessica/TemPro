### 小数点精度控制

#### 方法

以保留小数点后 2 位为例

1. ```py
   "%.2f" % x
   ```
2. ```py
   "{:.2f}".format(x)   # 当涉及到同一变量重复输出时可以考虑使用 format
   ```
3. ```py
   # 适用于 Python 3.8 及以上
   f"{x:.2f}"
   ```
4. ```py
   round(x, 2) # 数 x,保留小数点后 2 位
   ```

#### 注意

并非完全的四舍五入，当小数部分出现 5 时，如 2.5，取**最近的偶数**。

### 输入

#### 获取命令行参数

```py
import sys

print(type(sys.argv), sys.argv)
```

#### 未知数量的多组输入,EOF结束

```py
while True:
    try:
        a, b = map(int, input().split())
        print(a + b)
    except EOFError:
        break
```

#### 未知数量的多组输入,结束符给定

```py
while True:
    a = int(input())
    if a == 0:
        break
    print(a)
```

#### 每行第一个数代表该行数的个数

```py
data = list(map(int,input().split()))
n, a = data[0], data[1:]

sum = 0
for i in range(n):
    sum += a[i]
print(sum)
```

### 二维数组
```py
a = [[0] * m for i in range(n)] # n * m矩阵
```