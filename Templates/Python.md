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

### 数组

```py
l = [[]] * 3 # 浅拷贝
l = [[] for _ in range(3)] # 深拷贝

a = [[0] * m for i in range(n)] # n * m 矩阵
```

### 进制/类型转换

```py
#!/usr/bin/python3

import codecs

codecs.encode(b'Python3','hex')
# b'507974686f6e33'

b'Python3'.hex()
# '507974686f6e33'

bytes.fromhex('507974686f6e33')
codecs.decode(b'507974686f6e33', 'hex')
# b'Python3'

int('0x33', 16)
# 51

hex(51)
# '0x33'

int('110011', 2)
# 51

bin(33)
# '0b100001'

# (ΦˋωˊΦ)＝З
f'{0b110011:#0}'
# '51'

# :#b -> converts to binary
# :#o -> converts to octal
# :#x -> converts to hexadecimal 
# :#0 -> converts to decimal as above
```