#include<iostream>
#include<algorithm>
#include<string>
#include<map>//int dx[4]={0,0,-1,1};int dy[4]={-1,1,0,0};
#include<set>//int gcd(int a,int b){return b?gcd(b,a%b):a;}
#include<vector>
#include<cmath>
#include<stack>
#include<string.h>
#include<stdlib.h>
#include<cstdio>
using namespace std;
vector<int> v;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
		v.clear();
        int n,m,p=0;
		scanf("%d%d",&n,&m);
		int l=0,r=n;
		for(int i=0;i<n;++i){
			int a;
			scanf("%d",&a);
			if(a==0)
				p++;
			else
				v.push_back(a);
		}
		if(p==n){
			cout<<min(m,p)<<endl;
			continue;
		}
		sort(v.begin(),v.end());
		n=unique(v.begin(),v.end())-v.begin();
		int mid;
		int ans;
		while(l<=r){
			mid=(l+r)/2;
			int a=0,b=0;
			if(min(m,p+1)>=mid){
				l=mid+1;
				ans=mid;
				continue;
			}
			int u=0;
			for(int i=1;i<n;++i){
				if((v[b]-v[a]+1)-(b-a+1)>p){
					a++;
					continue;
				}
				if((v[b+1]-v[a]+1)-((b+1)-a+1)>p){
					a++;
					b++;
					continue;
				}
				b++;
				int ss=p-((v[b]-v[a]+1)-(b-a+1));
				int sss=min(m,ss+(v[b]-v[a]+1));
				if(sss>=mid){
					u=1;
					l=mid+1;
					ans=mid;
					break;
				}
			}
			if(u==0)
				r=mid-1;
		}
		cout<<ans<<endl;
	}
	return 0;
}

