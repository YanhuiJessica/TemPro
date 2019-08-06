## 目录
- [目录](#%e7%9b%ae%e5%bd%95)
- [vector](#vector)
    - [注意](#%e6%b3%a8%e6%84%8f)
- [set & multiset & unordered_set](#set--multiset--unorderedset)
    - [注意](#%e6%b3%a8%e6%84%8f-1)
- [stack](#stack)
    - [注意](#%e6%b3%a8%e6%84%8f-2)
- [queue](#queue)
    - [注意](#%e6%b3%a8%e6%84%8f-3)
- [priority_queue（优先队列）](#priorityqueue%e4%bc%98%e5%85%88%e9%98%9f%e5%88%97)
- [deque（双向队列）](#deque%e5%8f%8c%e5%90%91%e9%98%9f%e5%88%97)
- [map & multimap & unordered_map](#map--multimap--unorderedmap)
    - [三种插入操作示例](#%e4%b8%89%e7%a7%8d%e6%8f%92%e5%85%a5%e6%93%8d%e4%bd%9c%e7%a4%ba%e4%be%8b)
    - [注意](#%e6%b3%a8%e6%84%8f-4)
- [lower_bound & upper_bound](#lowerbound--upperbound)
    - [注意](#%e6%b3%a8%e6%84%8f-5)
- [pair](#pair)
    - [使用sort对pair类型进行排序](#%e4%bd%bf%e7%94%a8sort%e5%af%b9pair%e7%b1%bb%e5%9e%8b%e8%bf%9b%e8%a1%8c%e6%8e%92%e5%ba%8f)
## vector
用法 | 含义
---------| -------------
v[i] | 直接以下标方式访问容器中的元素
v.front() |  返回首元素
v.back() |  返回尾元素
v.push_back(x) |  向表尾插入元素x
v.pop_back() |  删除表尾元素
v.begin() |  返回指向首元素的迭代器
v.end() |  返回指向尾元素的下一个位置的迭代器
v.size() |  返回表长
v.empty() |  当表空时，返回真，否则返回假
v.clear() |  删除容器中的所有的元素
v.insert(it, val) |  向迭代器it指向的元素前插入新元素val
v.insert(it, n, x) |  向迭代器it指向的元素前插入n个x
v.insert(it, first, last) |  将由迭代器first和last所指定的序列[first, last)插入到迭代器it指向的元素前面
v.erase(it) |  删除由迭代器it所指向的元素
v.erase(first, last) |  删除由迭代器first和last所指定的序列[first, last)
v.resize(n) |  改变序列的长度，超出的元素将会被删除，如果序列需要扩展（原空间小于n），元素默认值将填满扩展出的空间
v.resize(n, val) |  改变序列的长度，超出的元素将会被删除，如果序列需要扩展（原空间小于n），将用val填满扩展出的空间
v.swap(v2) |  将s与另一个vector对象v2进行交换
v.assign(first, last) |  将序列替换成由迭代器first和last所指定的序列[first, last), [first, last)不能是原序列中的一部分
#### 注意
* vector不自带v.find()函数

## set & multiset & unordered_set
用法 | 含义
---------| -------------
s.begin() | 返回指向第一个元素的迭代器
s.end() | 返回指向最后一个元素的迭代器
s.clear() | 清除所有元素
s.empty() | 如果集合为空，返回true
s.count(val) | 返回值为val的元素的个数
s.erase(val) | 删除集合中**所有**值为val的元素
s.erase(it) | 删除集合中迭代器it指向的元素
s.erase(first,last) | 删除由迭代器first和last所指定的子集[first, last)
s.equal_range(val) | 返回有序/升序集合中val元素第一次和最后一次出现的位置 
s.find() | 返回一个指向被查找到元素的迭代器
s.insert(val) | 在集合中插入值为val的元素
s.max_size() | 返回集合能容纳的元素的最大限值
s.rbegin() | 返回指向集合中最后一个元素的反向迭代器
s.rend() | 返回指向集合中第一个元素的反向迭代器
s.size() | 集合中元素的数目
s.swap(s2) | 交换两个集合变量
s.upper_bound(val) | 返回大于val值元素的迭代器
s.lower_bound(val) | 返回指向大于（或等于）val值的第一个元素的迭代器
#### 注意
* set无法用下标访问
* set/multiset自动有序，无法使用排序函数
* unordered_set只能使用前向迭代器
* set、multiset头文件均为set，unordered_set头文件为unordered_set
* multiset的erase,**当传入的是值,将删除所有相同的值**;若传入的是迭代器,则只删除对应元素

## stack
用法 | 含义
---------| -------------
st.empty() | 堆栈为空则返回真
st.pop() | 移除栈顶元素
st.push(val) | 在栈顶增加元素val
st.size() | 返回栈中元素数目
st.top() | 返回栈顶元素
#### 注意
* 栈满足先入后出原则

## queue
用法 | 含义
---------| -------------
q.push() | 入队
q.pop() | 出队
q.front() | 返回首元素
q.back() | 返回末元素
q.size() | 输出现有元素的个数
q.empty() | 队列为空返回1，反之返回0
#### 注意
* 队列满足先入先出原则

## priority_queue（优先队列）
用法 | 含义
---------| -------------
p.empty() | 判断是否为空  
p.push(val) | 队列尾部增加元素val 
p.pop() | 队列头部数据出队 
p.top() | 返回头部数据 
p.size() | 返回栈中元素个数

## deque（双向队列）
用法 | 含义
---------| -------------
d.assign(first, last) | 将[first, last)区间中的元素赋值给d
d.assign(n,val) | 将n个val赋值给d
d.at(index) | 传回索引index所指的元素，如果index越界，抛出out_of_range
d.begin() | 返回首元素地址
d.end() | 返回尾元素地址
d.front() | 返回首元素
d.back() | 返回尾元素
d.clear() | 移除容器中所有元素
d.empty() | 判断容器是否为空
d.erase(pos) | 删除pos位置的元素，传回下一个元素的位置
d.erase(first, last) | 删除[first, last)区间的元素，传回下一个元素的位置
d.insert(pos,val) | 在pos位置插入val，传回新元素位置
d.insert(pos,n,val) | 在pos位置插入n个val元素，无返回值
d.insert(pos,first, last) | 在pos位置插入在[first, last)区间的元素，无返回值
d.pop_back() | 删除最后一个元素
d.pop_front() | 删除头部元素
d.push_back(val) | 在尾部加入一个元素
d.push_front(val) | 在头部插入一个元素
d.rbegin() | 传回一个逆向队列的第一个元素
d.rend() | 传回一个逆向队列的最后一个元素的下一个位置
d.resize(num) | 重新指定队列的长度
d.size() | 返回容器中实际元素的个数

## map & multimap & unordered_map
用法 | 含义
---------| -------------
mp[0] = x | 利用数组方式插入数据，0是键，x是值
mp.at(0) = x | 利用at执行插入操作
mp.insert(make_pair(key,x)) | 利用insert插入pair(键，值)数据
mp.emplace(make_pair(key,x)) | 在映射中不存在主键key时执行插入操作
mp.size() | 返回mp的大小
mp.count(key) | 统计键为key的元素存在的映射数，存在返回1，不存在返回0
mp.erase(it) | 根据迭代器删除元素
mp.clear() | 清空映射
mp.empty() | 判断映射是否为空
mp.find(key) | 根据键key查找元素，找到以后返回迭代器
mp.rbegin()  | 返回反向迭代器
mp.rend() | 返回反向迭代器
mp.swap(mp2) | 将mp和mp2进行交换
mp.lower_bound(key) | 返回map中第一个大于或等于key的迭代器指针
mp.upper_bound(key) | 返回map中第一个大于key的迭代器指针
<<<<<<< HEAD
##### 三种插入操作示例
=======
#### 三种插入操作示例
>>>>>>> 2661ff1f23aae9284b62becea865e2705d3c9a37
```cpp
    map<int, string> mapStudent;  
    mapStudent[0] = "student_zero";
    mapStudent.insert(pair<int, string>(1, "student_one")); 
    mapStudent.insert(map<int, string>::value_type (2, "student_two"));  
```
#### 注意
* map的键值key不可重复，具有严格的一一对应关系，而multimap可以一个键对应多个值
* map支持[ ]运算符，multimap不支持[ ]运算符
* map/multimap中的元素是自动按key升序排序，不能使用sort函数


## lower_bound & upper_bound
用法 | 含义
---------| -------------
lower_bound(first, last, val) | 在[first,last)区间进行二分查找，返回**大于或等于**val的第一个元素位置
upper_bound(first, last, val) | 在[first,last)区间进行二分查找，返回**大于**val的第一个元素位置
#### 注意
* 只能作用于有序序列
* 如果所有元素都小于val，函数返回last的位置，此时last的位置是**越界**的！
* set::lower_bound()由于省略了再建树的过程，速度快于lower_bound()

## pair
#### 使用sort对pair类型进行排序
* std::pair::operator< 按标准规定会在两个 std::pair 的第一个元素互不小于对方的情况下比较第二个元素
