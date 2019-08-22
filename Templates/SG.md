```cpp
// 渣渣写的自用SG函数，凑合自用
// 作用：Nim博弈打表，sg值为零时一方胜，多堆博弈取异或和
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int sg[maxn];
int f[] = { 1,2,4 }; //单次可以取的数
set<int> s;

int mex() //返回不在集合中的最小非负整数
{
	for (int i = 0; ; i++) {
		if (s.count(i) == 0) {
			s.clear();
			return i;
		}
	}
	s.clear();
}

void getSG(int n)
{
	memset(sg, 0, sizeof(sg));
	for(int i = 1; i <= n; i++) {
		for(int j = 0; f[j] <= i; j++) {
			if (f[j] == 0) break;
			s.insert(sg[i - f[j]]);
		}
//		printf("set[%d] = ", i); //用于查看当前set中的值
//		for(set<int> :: iterator it = s.begin(); it != s.end(); it++) printf("%d ", *it); printf("\n");
		sg[i] = mex();
	}
}

int main()
{
	getSG(10);
	for(int i = 0; i < 10; i++)
		cout << sg[i];
}
```