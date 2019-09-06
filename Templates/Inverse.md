- [逆元的定义与存在条件](#逆元的定义与存在条件)
- [逆元的求法](#逆元的求法)
  - [费马小定理](#费马小定理)
    - [使用条件](#使用条件)
    - [理论](#理论)
    - [实现](#实现)
  - [拓展欧几里得算法](#拓展欧几里得算法)
    - [使用条件](#使用条件-1)
    - [理论](#理论-1)
    - [实现](#实现-1)
  - [线性递推  $O(n)$](#线性递推-on)
    - [使用条件](#使用条件-2)
    - [理论](#理论-2)
    - [实现](#实现-2)
  - [阶乘递推](#阶乘递推)
    - [使用条件](#使用条件-3)
    - [理论](#理论-3)
  - [其他](#其他)
  
## 逆元的定义与存在条件
> $ax\equiv1 \pmod {b}，x就是a对b的逆元$  
> 当且仅当 $gcd(a,b) = 1$时逆元存在

## 逆元的求法
### 费马小定理
#### 使用条件
> $p为素数$
#### 理论
> $若p为素数，a为正整数，且a、p互质。 则有a^{p-1} \equiv 1 (mod \,p)$  

可推出$x≡a^{p−2}(mod\,p)$ ，即$a^{p−2}为a对p的逆元$
#### 实现
快速幂
### 拓展欧几里得算法
#### 使用条件
> $a、p互质，p可以不是素数$
#### 理论
$ax\equiv1 \pmod {b}$，即$ax+by=1$  
#### 实现
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

ll inv(ll a, ll b) 
{
	ll x, y;
	if(exgcd(a,b,x,y) == 1)
		return (x%b + b) % b;
	else return -1;
}
```

### 线性递推 &emsp;$O(n)$
#### 使用条件
> $p为素数$
#### 理论
>$首先我们有 1^{-1}\equiv 1 \pmod p$  
设 $p=k*i+r,(1<r<i<p)，k 是 p/i 的商，r 是余数$。  
再将这个式子放到$(mod\,p)$意义下就会得到：  
&emsp;&emsp;&emsp;$k*i+r \equiv 0 \pmod p$  
然后乘上$i^{-1},r^{-1}$ 就可以得到:  
&emsp;&emsp;&emsp;$k*r^{-1}+i^{-1}\equiv 0 \pmod p$  
&emsp;&emsp;&emsp;$i^{-1}\equiv -k*r^{-1} \pmod p$  
&emsp;&emsp;&emsp;$i^{-1}\equiv -\lfloor \frac{p}{i} \rfloor*(p \bmod i)^{-1} \pmod p$
#### 实现
 ```cpp
inv[1] = 1;
for(int i = 2; i < p; ++ i)
    inv[i] = (p - p / i) * inv[p % i] % p;
 ```
### 阶乘递推
#### 使用条件
> $p为素数$
#### 理论
$inv[i+1]=\frac{1}{(i+1)!}$  
$inv[i+1]*(i+1)=\frac{1}{i!}=inv[i]$

### 其他
* $对于当b和p不互素时，\frac{a}{b}\,mod\,p=\frac{a\,mod(bp)}{b}$
