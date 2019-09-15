- [勾股数](#勾股数)
  - [理论](#理论)
- [组合数](#组合数)
  - [实现](#实现)
- [卡特兰数列](#卡特兰数列)
  - [理论](#理论-1)
  - [应用](#应用)
  - [实现](#实现-1)
- [斐波那契数列](#斐波那契数列)
  - [公式](#公式)
  - [矩阵快速幂实现](#矩阵快速幂实现)
- [环形染色问题](#环形染色问题)
  - [理论](#理论-2)
- [贝尔数](#贝尔数)
  - [理论](#理论-3)
  - [性质](#性质)
- [第一类斯特林数](#第一类斯特林数)
  - [理论](#理论-4)
  - [实现](#实现-2)
- [第二类斯特林数(待完善)](#第二类斯特林数待完善)
  - [理论](#理论-5)
  - [实现](#实现-3)

## 勾股数
### 理论
> Base:<br>
> $a=m^{2}-n^{2},\ \,b=2mn,\ \,c=m^{2}+n^{2}$
>
> All:<br>
> $a=k\cdot (m^{2}-n^{2}),\ \,b=k\cdot (2mn),\ \,c=k\cdot (m^{2}+n^{2})$
>
> Informal:<br>
> $a=2n+1, b=2n^{2}+2n,  c=2n^{2}+2n+1.     n\in \left \{ 1,2,3,4.......\right \}$    
> $a=2n+2,  b=n^{2}+2n,  c=n^{2}+2n+2.   n\in \left \{ 1,2,3,4.......\right \}$
## 组合数
### 实现
1. 暴力求解，$C_n^m=\frac{n*(n-1)*...*(n-m+1)}{m!}\,\, (n\leq15)$
```cpp
const int M = 10007;
int C(int n, int m) 
{ 
    int ans = 1; 
    for(int i=n; i>=(n-m+1); --i) 
        ans *= i; 
    while(m) 
        ans /= m--; 
    return ans % M; 
} 
```
1. 打表，$C_n^m=C_{n-1}^{m-1}+C_{n-1}^m\,\,(n\leq10,000)$
```cpp
const int M = 10007; 
const int maxn = 1000; 
int C[maxn+1][maxn+1]; 
void init() 
{ 
    int i,j; 
    for(i=0; i<=maxn; ++i) 
    { 
        C[0][i] = 0; 
        C[i][0] = 1; 
    } 
    for(i=1; i<=maxn; ++i) 
    { 
        for(j=1; j<=maxn; ++j) 
        C[i][j] = (C[i-1][j] + C[i-1][j-1]) % M; 
    } 
}
```
3. Lucas定理      
   求$C_n^mmod\,p的时候可以化作C_n^m=C_{n/p}^{m/p}∗C_{n\%p}^{m\%p}，那么只要递归C_{n/p}^{m/p}$即可。
```cpp
#include <stdio.h>
const int M = 2013;
int ff[M+5];  //打表，记录n!，避免重复计算
 
//求最大公因数
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
 
//解线性同余方程，扩展欧几里德定理
int x,y;
void Extended_gcd(int a,int b)
{
    if(b==0)
    {
        x=1;
        y=0;
    }
    else
    {
        Extended_gcd(b,a%b);
        long t=x;
        x=y;
        y=t-(a/b)*y;
    }
}
 
//计算不大的C(n,m)
int C(int a,int b)
{
    if(b>a)
        return 0;
    b=(ff[a-b]*ff[b])%M;
    a=ff[a];
    int c=gcd(a,b);
    a/=c;
    b/=c;
    Extended_gcd(b,M);
    x=(x+M)%M;
    x=(x*a)%M;
    return x;
}
 
//Lucas定理
int Combination(int n, int m)
{
    int ans=1;
    int a,b;
    while(m||n)
    {
        a=n%M;
        b=m%M;
        n/=M;
        m/=M;
        ans=(ans*C(a,b))%M;
    }
    return ans;
}
 
int main()
{
    int i,m,n;
    ff[0]=1;
    for(i=1; i<=M; i++) //预计算n!
        ff[i]=(ff[i-1]*i)%M;
    while(~scanf("%d%d",&n, &m))
    {
        printf("%d\n",Combination(n,m));
    }
    return 0;
}
```

## 卡特兰数列

$1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, ......$
### 理论
> 1. $f(n) = \frac{1}{n+1}\tbinom{2n}{n}$
> 
> 2. $f(n) = \tbinom{2n}{n}-\tbinom{2n}{n-1}$ <- 推荐
> 
> 3. $f(n) = \sum_{i=0}^{n-1}f(i)×f(n-i-1)$
> 
> 4. $f(n) = \frac{f(n-1)×(4n-2)}{n+1}$
> 

### 应用
* 二叉树的计数问题：已知二叉树有 $n$ 个结点，求能构成多少种不同的二叉树   
* 括号化问题：一个合法的表达式由()包围，()可以嵌套和连接，如：(())()也是合法表达式，现给出 $n$ 对括号，求可以组成的合法表达式的个数    
* 划分问题：将一个凸 $n+2$ 多边形区域分成三角形区域的方法数    
* 出栈问题：一个栈的进栈序列为 $1,2,3,..n$，求不同的出栈序列有多少种    
* 路径问题：在 $n*n$ 的方格地图中，从一个角到另外一个角，求不跨越对角线的路径数有多少种    
* 握手问题：$2n$ 个人均匀坐在一个圆桌边上，某个时刻所有人同时与另一个人握手，要求手之间不能交叉，求共有多少种握手方法    

### 实现
```cpp
long long cat[50];
long long Catl(int n)
{
    memset(cat, 0, sizeof(cat));
    cat[0] = cat[1] = 1;
    for(int i = 2; i <= n; ++i) {
        for(int j = 0; j < i; ++j)
            cat[i] += cat[j] * cat[i-j-1];
    }
    return cat[n];
}

```

## 斐波那契数列
### 公式
$fib_n = \frac{1}{\sqrt5}*[(\frac{1+\sqrt5}{2})^n-(\frac{1-\sqrt5}{2})^n]$
### 矩阵快速幂实现
```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=10000;
struct mat
{
    ll a[2][2];
};
mat mat_mul(mat x,mat y)
{
    mat res;
    memset(res.a,0,sizeof(res.a));
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
        for(int k=0;k<2;k++)
        res.a[i][j]=(res.a[i][j]+x.a[i][k]*y.a[k][j])%MOD;
    return res;
}
void mat_pow(int n)
{
    mat c,res;
    c.a[0][0]=c.a[0][1]=c.a[1][0]=1;
    c.a[1][1]=0;
    memset(res.a,0,sizeof(res.a));
    for(int i=0;i<2;i++) res.a[i][i]=1;
    while(n)
    {
        if(n&1) res=mat_mul(res,c);
        c=mat_mul(c,c);
        n=n>>1;
    }
    printf("%lld\n",res.a[0][1]);
}
int main()
{
    int n;
    while(~scanf("%d",&n)&&n!=-1)
    {
        mat_pow(n);
    }
    return 0;
}
```


## 环形染色问题
### 理论
> $n$块区域的环，用$m$种不同颜色去涂，相邻格子颜色不同，共有$(m-1)^n+(-1)^n×(m-1)$种涂法

## 贝尔数
$1, 1, 2, 5, 15, 52, 203, 877, 4140, 21147, 115975, 678570, 4213597, 27644437...$
### 理论
> 第$n个Bell数表示集合{1,2,3,...,n}$的划分方案数  
> 
> $Bell_{n+1} = \sum_{k=0}^n\tbinom{n}{k}Bell_k$

### 性质
> 1. 适合$B_n = \frac{1}{e}\sum_{k=0}^{inf}\frac{k^n}{k!}$期望值为1的泊松分数的$n$次矩。
>    
> 2. 若$p$为质数，$B_{p+n} \equiv B_n + B_{n+1} (mod \,\,p)$
> 
> 3. 每个贝尔数都是第二类斯特林数的和 $B_n = \sum_{k=1}^{n}S(n, k)$
> 4. 贝尔三角形
> ```cpp
>       1
>       1 2
>       2 3 5
>       5 7 10 15
>       15 20 27 37 52
>       52 67 87 114 151 203
> ```
> 规律：$(1)\, a_{1,1} = 1 \,\,(2) \, a_{n,1} = a_{n-1,n-1} \,\, (3) \,a_{n,m} = a_{n,m-1} + a_{n-1, m-1}$
## 第一类斯特林数
### 理论
> $S1[n][m]表示把n个元素划分成m$个非空循环排列集合的方案数
### 实现
```cpp
void GetStirling() {
    for(int i = 0; i <= n; i ++) S1[i][i] = 1;//注意s1[i][1]（i > 1）不等于1
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m && j <= i; j ++)//j从1开始，理由同上
            S1[i][j] = (S1[i - 1][j - 1]  +   (i - 1) * S1[i - 1][j])%mod;
}
```
## 第二类斯特林数(待完善)
### 理论
> $S2[n][m]表示把n个元素划分成m$个非空集合的方案数
### 实现
```cpp
void GetsStirling2() {
    for(int i = 1; i <= n; i ++) S2[i][1] = 1;//S2[i][i] = 1
    for(int i = 1; i <= n; i ++)
        for(int j = 2; i <= i && j <= m; j ++)
            S2[i][j] = (S2[i - 1][j - 1] + j * S2[i - 1][j]) % mod;
}
```