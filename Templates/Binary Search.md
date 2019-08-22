```cpp
//ans>=mi,ans<=ma
l=mi,r=ma,mid;
while(l<=r)
{
    mid=(l+r)>>1;
    if(isOk(mid))
    {
        //求最大值
        l=mid+1;
        ans=max(ans,mid);
        //求最小值
        r=mid-1;
        ans=min(ans,mid);
    }
    else
    {
        //求最大值
        r=mid-1;
        //求最小值
        l=mid+1;
    }
}
```