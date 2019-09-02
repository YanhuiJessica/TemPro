### 原理
> $a^b \equiv \begin{cases}
    a^b&  b < \varphi(p) \\
    a^{b \, mod \,\varphi(p)+\varphi(p) } & b \geq \varphi(p)
    \end{cases} \,\,\, mod \, p$
### 例题

#### [2019ICPC南京网络赛 - B SuperLog](https://nanti.jisuanke.com/t/41299)
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