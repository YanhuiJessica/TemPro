- [排列](#排列)
	- [Cycle notation](#cycle-notation)
- [二次剩余](#二次剩余)
	- [理论](#理论)
	- [应用](#应用)
- [扩展欧几里得算法](#扩展欧几里得算法)
	- [通解](#通解)
	- [应用](#应用-1)
- [欧拉函数](#欧拉函数)
	- [定义](#定义)
	- [实现](#实现)
	- [性质](#性质)
	- [应用](#应用-2)
- [欧拉降幂](#欧拉降幂)
	- [原理](#原理)
	- [例题](#例题)
- [拓展中国剩余定理](#拓展中国剩余定理)
	- [原理](#原理-1)
	- [实现](#实现-1)

## 排列

### Cycle notation

Cycle notation 描述了排列对集合元素造成的影响。对于同一排列，通常存在多种 cycle notations。

$\left( \begin{matrix} 1 & 2 & 3 & 4 & 5 \\ 2 & 5 & 4 & 3 & 1 \end{matrix} \right) = \left( \begin{matrix} 1 & 2 & 5 \end{matrix} \right)\left( \begin{matrix} 3 & 4 \end{matrix} \right) = \left( \begin{matrix} 3 & 4 \end{matrix} \right)\left( \begin{matrix} 5 & 1 & 2 \end{matrix} \right)$

> In general, a cycle of length k, that is, consisting of k elements, is called a k-cycle.

2-cycle: $\left( \begin{matrix} 3 & 4 \end{matrix} \right)$

## 二次剩余
### 理论
> $\exists x, 使 x^2\equiv d (mod \, p)成立, 称"d是模p的二次剩余"(d^{(p-1)\over 2}\equiv 1 (mod \, p))$
>
> $\forall x, x^2\equiv d (mod \, p) 不成立时,称"d是模p的二次非剩余"(d^{(p-1)\over 2}\equiv -1 (mod \, p))$
> 
> $if\, p\equiv 3(mod\, 4), x\equiv \pm a^{(n+1)\over 4} (mod \, p)$
### 应用
  * [Quadratic equation](https://ac.nowcoder.com/acm/contest/889/B)<!-- 做除法时使用逆元：除2 -> 乘2(mod p)的逆元 -->



## 扩展欧几里得算法
### 通解
$x=\frac{c}{d}x_0+k\frac{b}{d},y=\frac{c}{d}y0+k\frac{a}{d} ,\, k$取遍整数集合
### 应用
求解线性同余方程
```cpp
//exgcd求出方程的一组特解并返回gcd(a,b)
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll m = exgcd(b, a%b, y, x);
    y  -= a/b * x;
    return m;
}
ll solve(ll a, ll b, ll n)//求解模线性方程 ax = b(mod n) 或 ax + ny = b
{
    ll x, y, x0;
    ll d = exgcd(a, n, x, y);
    if(b % d) //无解
        return -1;
    x0 = (x * (b/d)) % n; //特解
    ll ans = x0, s = n / d;
    ans = (ans%s + s) % s;  //ans为最小非负整数解
    return ans;
}
```
## 欧拉函数

### 定义
> 欧拉函数$\varphi (n) 的定义为严格小于 n 的整数中，与 n 互质的数的个数$

### 实现
1. 分解质因数 $O(NlogN)$ 
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
2. 埃拉托斯特尼筛求欧拉函数 $O(NlogN)$ 
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
3. 欧拉筛 $O(N)$ 
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

## 欧拉降幂
### 原理
> $a^b \equiv \begin{cases}
    a^b&  b < \varphi(p) \\
    a^{b \, mod \,\varphi(p)+\varphi(p) } & b \geq \varphi(p)
    \end{cases} \,\,\, mod \, p$
### 例题

* [2019ICPC南京网络赛 - B SuperLog](https://nanti.jisuanke.com/t/41299)
> 求 $a^{a^{a^{...}}}(b次) \, mod \,\, p$ 的值

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod(ll a, ll b)
{
	return a <= b ? a : (a % b) + b; //欧拉降幂
}
ll pow_mod(ll a, ll n, ll m)
{
    ll ans = 1;
    while(n) {
        if(n&1) {
            ans = mod(ans * a, m);
        }
        a = mod(a * a, m);
        n >>= 1;
    }
    return ans;
}

ll phi(ll n)
{
    ll ans = n;
    for(ll i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            ans -= ans/i;
            while(n % i == 0)
                n /= i;
        }
    }
    if(n > 1) ans -= ans/n;
    return ans;
}

ll f(ll a, ll b, int m)
{
	if(m == 1 || b == 0) return 1;
	return pow_mod(a, f(a, b-1, phi(m)), m); //注意欧拉函数值的变化
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		ll a, b, m;
		scanf("%lld%lld%d", &a, &b, &m);
		cout << f(a, b, m) % m << endl;
	}
}
```

## 拓展中国剩余定理
### 原理
[洛谷P4777题解](https://www.luogu.org/problemnew/solution/P4777)

### 实现
```cpp
#include<iostream>
using namespace std;
typedef __int128 ll;

void exgcd(ll a, ll b, ll& g, ll& x, ll& y) {
	if (b == 0) {
		g = a;
		x = 1;
		y = 0;
		return;
	}
	exgcd(b, a % b, g, y, x);
	y -= (a / b) * x;
}

bool flag = false;
ll a1, a2, n1, n2;

ll abs(ll x) {
	return x > 0 ? x : -x;
}

void china() {
	ll d = a2 - a1;
	ll g, x, y;
	exgcd(n1, n2, g, x, y);
	if (d % g == 0) {
		x = ((x * d / g) % (n2 / g) + (n2 / g)) % (n2 / g);
		a1 = x * n1 + a1;
		n1 = (n1 * n2) / g;
	}
	else
		flag = true;
}

int n;
long long as[100001];
long long ns[100001];

ll realchina() {
	a1 = as[0];
	n1 = ns[0];
	for (ll i = 1; i < n; i++) {
		a2 = as[i];
		n2 = ns[i];
		china();
		if (flag)
			return -1; //无解 
	}
	return a1;
}

int main() {
	cin >> n;
	flag = false;
	for (ll i = 0; i < n; i++)
		cin >> ns[i] >> as[i];
	cout << (long long)realchina() << endl; //不到输出不换int128 
}
```
* 注意：返回的是最小非负整数解，有些题目需要特判