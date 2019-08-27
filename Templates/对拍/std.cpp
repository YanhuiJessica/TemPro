///这里是先把数对应到数组里，这样我们就可以知道哪里有空缺了，然后如果想到刘汝佳的计算前N项和的累加值的办法就会想到计算到这步要的0
///只需在脑子里想一想这个题的模型，很容易想到暴力，因为序列是连续的必属于其中一段，暴力左端点，二分右端点。
#include<stdio.h>
#include<string.h>
int a[110100],b[110100];
int erfen(int l,int r,int zero){
    int k=b[l-1];
    while(l<r){
        int mid=(l+r)>>1;
        if(b[mid]>k+zero){///如果比要找的值大的话，那我就往下找
            r=mid;
        }
        else{///否则相等或小于我们找下一个，相等找下个的目的是找的不消耗的最长的，这样我们就会找到第一个大于找到的，我们减一，
            l=mid+1;///不过有的时候会找到末尾没找完，所以我们比较是否大于，如大于减一，这样就全面了
        }
    }
    if(b[l]-k>zero)
    l--;
    return l;
}
int main()
{
    int t,n,m,temp,zero;
    scanf("%d",&t);
    while(t--){
        zero=0;
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++){
            scanf("%d",&temp);
            if(temp==0) zero++;
            else a[temp]=1;
        }
        memset(b,0,sizeof(b));
        for(int i=1;i<=m;i++){
            b[i]=b[i-1]+(!a[i]);
        }
        int maxn=0;
        for(int i=1;i<=m;i++){
            if(erfen(i,m,zero)-i+1>maxn)
                maxn=erfen(i,m,zero)-i+1;
        }
        printf("%d\n",maxn);
    }
}
