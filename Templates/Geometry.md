## 目录 <!-- omit in toc -->
- [极角排序](#极角排序)
  - [基本](#基本)
  - [常用方法(默认排序从小到大)](#常用方法默认排序从小到大)
    - [atan2()函数](#atan2函数)
    - [叉乘](#叉乘)
    - [先按象限再按极角](#先按象限再按极角)
  - [例题](#例题)
    - [Atcoder ABC 139 F - Engines](#atcoder-abc-139-f---engines)

## 极角排序
### 基本
```cpp
struct point
{
    double x,y;
};
double cross(point a, point b)
{
    return a.x*b.y-a.y*b.x;
}
```
### 常用方法(默认排序从小到大)
#### atan2()函数
  * 相较于计算叉积速度快，但精度较低
```cpp
bool cmp1(point a,point b)
{
    if(atan2(a.y,a.x)!=atan2(b.y,b.x))
        return atan2(a.y,a.x)<atan2(b.y,b.x);
    else return a.x<b.x;
}
bool cmp2(point a,point b)
{
    return atan2(a.y,a.x)<atan2(b.y,b.x);
}
```
#### 叉乘
  * 叉积为0,两向量平行(重合)
  * 叉积大于0,向量a在向量b的顺时针方向
  * 叉积小于0,向量a在向量b的逆时针方向
```cpp
bool cmp1(point a,point b)
{
    if(cross(a,b)==0)return a.x<b.x;
    return cross(a,b)>0;
}
bool cmp2(point a,point b)
{
    if(cross(a,b)>0)return true;
    return false;
}
```
#### 先按象限再按极角
```cpp
int Quadrant(point a)   //象限排序,注意包含四个坐标轴
{
    if(a.x>0&&a.y>=0)  return 1;
    if(a.x<=0&&a.y>0)  return 2;
    if(a.x<0&&a.y<=0)  return 3;
    if(a.x>=0&&a.y<0)  return 4;
}
bool cmp(point a,point b)   //先按象限从小到大排序,再按极角排序
{
    if(Quadrant(a)==Quadrant(b))//返回值就是象限
        return cmp1(a,b);   //极角排序
    else Quadrant(a)<Quadrant(b);
}
```
### 例题
#### [Atcoder ABC 139 F - Engines](https://atcoder.jp/contests/abc139/tasks/abc139_f)
* 本题需要注意环形的情况
* atan2()可以处理各个象限的情况,但对于叉乘排序,对于单个象限的排序结果是正确的,但对于跨象限的情况无法正确处理,例如：(9,4),(-8,2),(7,-6),(4,3),显然(4,3)的极角是介于(9,4)和(-8,2)之间的,但由于(7,-6)在(4,3)的顺时针方向(即叉乘大于0),因而不会发生交换,故而排序错误