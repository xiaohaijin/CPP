## auto类型说明符

C++11新标准引入了**auto**类型说明符，用它就能让编译器替我们去分析表达式所属的类型，显然，auto定义的变量必须有初始值。

* 一条声明语句只能有一种基本数据类型，该语句所有变量的初始基本数据类型都必须一样。
```C++
auto i = 0, *p = &i; /*!< 正确 */
auto sz = 0, pi = 3.14; /*!< 错误 */
```

### 复合类型、常量和auto
编译器推断出来的auto类型有时候和初始值的类型并不完全相同。对于以引用对象的类型作为auto的类型，此时的类型是原类型，而不包含引用。

auto一般会忽略掉顶层的const，同时底层的const则会保留。
