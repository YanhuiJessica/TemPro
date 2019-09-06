- [定义](#定义)
- [实现](#实现)
  - [分解质因数 $O(NlogN)$](#分解质因数-onlogn)
  - [埃拉托斯特尼筛求欧拉函数 $O(NlogN)$](#埃拉托斯特尼筛求欧拉函数-onlogn)
  - [欧拉筛 $O(N)$](#欧拉筛-on)
- [性质](#性质)
- [应用](#应用)
### 定义
> 欧拉函数$\varphi (n) 的定义为严格小于 n 的整数中，与 n 互质的数的个数$

### 实现
#### 分解质因数 $O(NlogN)$ 
```cpp
int phii(int n)
{
	int ans = n;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			ans = ans / i * (i - 1);
			while (n % i == 0) n /= i;
		}
	}
	if (n > 1) ans = ans / n * (n - 1);
	return ans;
}
```
#### 埃拉托斯特尼筛求欧拉函数 $O(NlogN)$ 
```cpp
void euler(int n)
{
	for (int i = 1; i <= n; i++) phi[i] = i;
	for (int i = 2; i <= n; i++)
	{
		if (phi[i] == i)//i是质数
		{
			for (int j = i; j <= n; j += i)
			{
				phi[j] = phi[j] / i * (i - 1);//把i的倍数更新掉
			}
		}
	}
}
```
#### 欧拉筛 $O(N)$ 
```cpp
int flag[maxn], prime[maxn];
int num = 0;
void euler2(int n)
{
	phi[1] = 1;//1要特判，这里与定义不符合
	for (int i = 2; i <= n; i++)
	{
		if (flag[i] == 0)//这代表i是质数 
		{
			prime[++num] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= num && prime[j] * i <= n; j++) 
		{
			flag[i * prime[j]] = 1;//先把这个合数标记掉 
			if (i % prime[j] == 0)
			{
				phi[i * prime[j]] = phi[i] * prime[j];//若prime[j]是i的质因子，则根据计算公式，i已经包括i*prime[j]的所有质因子 
				break;//保证每个数只会被自己最小的因子筛掉一次 
			}
			else phi[i * prime[j]] = phi[i] * phi[prime[j]];//积性函数
		}
	}
}
```
### 性质
* $∀n>1, [1, n] 中与 n 互质的数的和为\,n∗φ(n)/2$  
* $∑_{d|n}φ(d)=n$
### 应用
[NOI2010-能量采集](https://www.luogu.org/problem/P1447) (欧拉筛/莫比乌斯反演 + 整除分块)
> 求$∑_{i=1}^n∑_{j=1}^m gcd(i,j)\,\,\, (n,m\leq10^6)$

等价于求$∑_{i=1}^n∑_{j=1}^m∑_{d|i \& d|j}φ(d)$  

等价于求$∑_{d=1}^{min(n,m)}φ(d)⌊\frac{n}{i}⌋⌊\frac{m}{i}⌋$

欧拉筛处理出前缀和，然后整除分块加速，中间过程可能爆long long