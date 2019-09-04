## 目录 <!-- omit in toc -->
- [二分图](#二分图)
  - [无向图的最大独立集](#无向图的最大独立集)
    - [概念](#概念)
  - [无向图的最大团](#无向图的最大团)
    - [概念](#概念-1)
    - [实现](#实现)
  - [定理](#定理)

## 二分图
### 无向图的最大独立集
#### 概念
"任意两点之间都没有边相连"的点集被称为无向图的独立集,包含点数最多的一个就是图的最大独立集

### 无向图的最大团
#### 概念
"任意两点之间都有一条边相连"的子图被称为无向图的团,点数最多的团被称为图的最大团
#### 实现
```cpp
//邻接矩阵存图
int n;  //点的个数
int mp[N][N];
int cnt[N],vis[N];  //cnt[i]当前最大团的节点数,vis记录当前最大团的节点
int ans,group[N];   //ans记录最大团的节点数,group记录答案最大团的所有节点
bool dfs(int u, int dep)    //当前点u,搜索深度dep
{
    int j;
    for(int i=u+1;i<=n;i++)
    {
        if(cnt[i]+dep<=ans) //剪枝
            return false;
        if(mp[i][u])
        {
            for (j = 0; j < dep; j++)   //判断是否与当前最大团中各个点相连
                if (!matrix[i][vis[j]])
                    break;
            if(j == dep)
            {
                vis[dep]=i;
                if(dfs(i,dep+1))return true;
            }
        }
    }
    if(dep > ans)
    {
        for(int i=0;i<dep;i++)group[i]=vis[i];
        ans=dep;
    }
    return false;
}
```
### 定理
* 无向图的最大团等于其补图的最大独立集