## decltype类型指示符

C++11新标准引入了第二种类型说明符**decltype**，它的作用是选择并反回操作数的数据类型，在此过程中，编译器分析表达式并得到它的类型，却不实际计算表达式的值：
```C++
decltype(f()) sum = x; /\*!< sum的类型就是函数f的返回类型 */
```

如果**decltype**使用的表达式是一个变量，则**decltype**返回该变量的类型(包括顶层const和引用在内)：
```C++
const int ci = 0, &cj = ci;
decltype(ci) x = 0;  // x 的类型是const int
decltype(cj) y = x;  // y 的类型是const int &, y绑定到变量x.
decltype(cj) z;      // 错误：z 是一个引用，必须初始化。
```
