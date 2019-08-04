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
v.swap(v) |  将s与另一个vector对象v进行交换
v.assign(first, last) |  将序列替换成由迭代器first和last所指定的序列[first, last), [first, last)不能是原序列中的一部分



