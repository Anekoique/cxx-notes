# ***常用函数***

## **1.pow**

```c
int pow(m,n)
{
    int j,s=1;
    for(j=1;j<=n;j++){
        s*=m;
    }
    return s;
}
```

## 2.快速排序(stdlib)

```c
int main()
{
    int arr[10] = {9,8,7,6,5,4,3,2,1};
    int sz = sizeof(arr) / sizeof(arr[0]);
    qsort(arr,sz,sizeof(arr[0]),cmp);
}
int cmp(const void* a,const void* b)
{
    return *(int*) b - *(int*) a;
}
```

## 3.快速排序

```c
void quickSort(int* arr, int low, int high) {
	int i = low;
	int j = high;
	int temp = arr[low];
	if (i >= j)
		return;
	while (i != j) {
		while (i < j && arr[j]>=temp)
			j--;
		while (i < j && arr[i] <= temp)
			i++;
		if (i < j)
			swap(arr[i], arr[j]);
	}
	swap(arr[low], arr[i]);
	quickSort(arr, i + 1, high);
	quickSort(arr, low, i - 1);
}
```

## 4.选择排序

```c
void select_sort(int* arr, int n)
{
    int max,tmp;
    for (int i = 0; i < n - 1; i++)
    {
        max = i;
        for (j = i + 1; j < n ; j++)
        {
            if (arr[j] > arr[max])
            {
                max = j;
            }
        }
        if (i != max)
        {
            tmp = arr[i];
            arr[i] = arr[max];
            arr[max] = tmp;
        }
    }
}
```

## 5.冒泡排序

~~~c
void bubble_sort(int* arr, int n)
{
    int tmp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}
~~~

## 6.任意数据类型冒泡排序

```c
void bubble_sort(void* arr, int sz, int width, int(*cmp)(const void* e1, const void* e2))
{
	for (int i = 0; i < sz - 1; i++) {
		for (int j = 0; j < sz - i - 1; j++) {
			if (cmp((char*)arr + j * width, (char*)arr + (j + 1) * width)<0) {
				swap((char*)arr + j * width, (char*)arr + (j + 1) * width,width);
			}
		}
	}
}
int cmp(const void* e1, const void* e2) {
	return *(int*)e1 - *(int*)e2;
}
void swap(char* bf1, char* bf2, int width) {
	for (int i = 0; i < width; i++) {
		char e = *bf1;
		*bf1 = *bf2;
		*bf2 = e;
		bf1++;
		bf2++;
	}
}
```

## 7.判断素数

```c
int Isprime(int x) {
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0)
			return 0;
	return 1;
}
```

## 8.<math.h>

- log(a)   /   log10(a)
- exp(a)
- sqrt(a)
- round(a)  //  (int)(a+0.5)
- ceil  /  floor
- fabs()

## 9.<string.h>

- strcat
- strcpy   /   strncpy (str1,str2,n)
- strcmp    ==返回为 0 ；/  strncmp
- strlen  不包括 ’\0' 
- strlwr  /   strupr
- strstr

## 10.文件操作

- fopen("FILE Path","w")   /  w, r, a, rb, wb, ab,  (+)
- fclose
- fwrite(ptr,size,count,stream)
- fread(ptr,size,count,stream)

## 11.最大公约数

```c
int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a%b);
}
```

***

# C-常见错误

## 1.switch()

执行条件为真后不执行break会继续执行后面的case知道break；

## 2.printf()

打印的优先级问题。

## 3.const与指针

- 常量指针 //指向地址可以改变，值不可以改变

```c
const int *p;
int a = 4;
int b = 5;
p = &a;
*p = 5;  /*错误，不能通过指针p来改变值*/
a = 5;  /*正确，*p这时候也等于5*/
p = &b;  /*常量指针可以指向其他的地址*/
```

- 指针常量 //指向地址不能改变，值可以改变

```c
int *const p;
int a = 4;
int *const p = &a;/*要马上初始化，之后无法赋值*/
p = &b;/*错误，无法赋值*/
*p = 5;/*正确*/
```

## 4.ascll码

'A' = 65  /  'a' = 97  /  ’0‘ = 48

## 5.if()

if() 括号内为赋值语句 ：表达式右侧为0 不执行语句 1；表达式右侧不为0 执行语句 1；

## 6.转义字符

- \ddd 1-3位8进制数   /   \xhh 1-2位16进制数
- ’  ，“  ，？ 是转义字符

## 7.gets/fgets

- gets / gets_s / scanf 丢弃换行符
- fgets 若读入<=size-2 则保留换行符

## 8.scanf

- scanf结束输入后不会舍弃回车符（残留在缓冲区
- getchar()在缓冲区读入数据  /  输入设备->内存缓冲区->getchar()
- 如果不同getchar取走scanf留下的‘\n'，接下来的scanf会直接读入

~~~c
#include <stdio.h>
int main(void){
    char m[40];
    char n;
    printf("please input first str:\n");
    scanf("%s",m);
    printf("you input str is :%s\n",m); 
    printf("input second char :\n"); 
    scanf("%c",&n);   //程序将未输入而直接输出
    printf("now you input second char is :%c\n",n);
    return 0; 
}
~~~

- scanf读入字符串时遇到空格不会将其之后存入str，但都残留在缓冲区

## 9.字符串比较

不能用 == ; strcmp

## 10.fclose与feof

- fclose / 文件关闭，成功关闭返回值为0
- feof 在文件读取已经结束的时候，判断文件为何结束（与ferror搭配）

到达文件末尾结束读取时返回非0值；

```c
if (ferror(fp))
{
    puts("I/O error when reading");
}
else if (feof(fp))
{
    puts("End of the file reached successfully");
}
```

# C++

## 一、指针

### 1、动态分配

~~~c++
T *p = new T;
T *p = new T(parameter);
T *p2 = new T[];
delete p;
delete []p2;
~~~

### 2、引用

| 引用         | 指针         |
| ------------ | ------------ |
| 必须初始化   | 可以不初始化 |
| 不能为空     | 可以为空     |
| 不能更换目标 | 可以更换目标 |

```c++
// 引用传参
void func(const vector<int> & data);
// 引用返回值
vector<int> v(10);
v[5] = 10;    //[]操作符返回引用，然后vector对应元素才能被修改
              //如果[]操作符不返回引用而是指针的话，赋值语句则需要这样写
*v[5] = 10;   //这种书写方式，完全不符合我们对[]调用的认知，容易产生误解
```

### 3、const

```c++
const int * ptr; // 指向常量的指针
int const * ptr; // 指向常量的指针
int * const ptr = &num；// 指向对象的常指针，必须初始化
void func(const A &a); // 函数传参：& 提高效率, const 防止修改
```

```C++
// 类中的const成员变量必须通过初始化列表进行初始化
// const对象只能访问const成员函数,而非const对象可以访问任意的成员函数,包括const成员函数
// const对象默认调用const成员函数
class Apple
{
private:
    int people[100];
public:
    Apple(int i); 
    const int apple_number;
    void take(int num) const;
    int add(int num);
    int add(int num) const;
    int getCount() const;	
};
Apple::Apple(int i):apple_number(i) {

}
int Apple::add(int num) {
    take(num);
}
int Apple::add(int num) const {
    take(num);
}
void Apple::take(int num) const {
    cout<<"take func "<<num<<endl;
}
int Apple::getCount() const {
    take(1);
//    add(); //error
    return apple_number;
}
```

### *4、内联

```c++
class A
{
public:
    void Foo(int x,int y) // 定义即隐式内联函数！
    {

    };
    void f1(int x); // 声明后，要想成为内联函数，必须在定义处加inline关键字。  
};
// 定义处加inline关键字
inline void A::f1(int x){

}
```

内联是以代码膨胀(复制)为代价，仅仅省去了函数调用的开销，从而提高函数的执行效率。

- 如果执行函数体内代码的时间相比于函数调用的开销较大
- 另一方面，每一处内联函数的调用都要复制代码，将使程序的总代码量增大，消耗更多的内存空间。

以下情况不宜用内联：

- 如果函数体内的代码比较长，使得内联将导致内存消耗代价比较高。

- 如果函数体内出现循环，那么执行函数体内代码的时间要比函数调用的开销大。

## 二、封装

实现->类->对象->构造（复制构造，复制赋值，移动构造，移动赋值，析构函数）【动态分配】->成员->友员；

编译器提供默认构造函数、复制构造函数、复制赋值运算符、析构函数、移动构造函数、移动赋值运算符；

提供析构函数、复制构造、复制赋值不会提供移动；

提供移动不会提供赋值构造和复制构造；

### 1、构造

#### （1）构造函数

返回类型只能是void

```c++
// 默认构造函数
A::A() {} // 未提供构造函数，编译器默认
A::A()    // 显性定义默认构造函数
{
    a = 0;
    ...
}
A(int i = 0) { a = i } // 带参默认构造
```

```c++
// 初始化列表构造
class Test
{
    public:
        Test(int a):x(a),y(2){}
        int x;
        int y；
};
```

#### （2）析构函数

```c++
// 析构函数的作用并不是删除对象，而是在撤销对象占用的内存之前完成一些清理工作
// 定义类时没写析构函数，则编译器生成缺省析构函数
class A
{
private :
    char * p;
public:
    A ( )
    {
        p = new char[10];
    }
    ~ A ( )
    {
        delete [] p;
    }
};
```

```c++
// 私有析构函数
// 实现自我销毁
// 被声明为私有析构函数的类对象只能在堆上创建，并且该类不能被继承
#include <iostream>
using namespace std;
class A
{
public:
    A()
    {
        cout<<"A"<<endl;
    }
    void destroy() const
    {
        cout<<"delete A"<<endl;
        delete this;
    }
private:
    ~A() {}
};
int main( )
{
    A *pa = new A;
    pa->destroy();
    return 0;
}
```

#### （3）复制构造

```c++
class Test
{
    public:
        Test(const Test &ob){
            x = ob.x;
            y = ob.y;
        }
    private:
        int x;
        int y；
};
```

#### （4）复制赋值

```c++
// 重载赋值运算符
class Test
{
    public:
        Test& operator=(const Test &ob){
            x = ob.x;
            y = ob.y;
            return this;
        }
    private:
        int x;
        int y;
};
```

#### （4）*默认拷贝构造【内存分配】

```c++
Test ob1;
Test ob2(ob1);
Test ob3 = ob2;
```

```c++
// error,指向相同地址，重复delete内存
class Test
{
    public:
        Test(){p = new int(4);}
        ~Test(){delete p;}
        int *p;
};
Test ob1;
Test ob2 = ob1;
```

```c++
// 深度复制 / 赋值
// 例：
String::String(const String & st)
{
    num_strings++; // handle static menmber update if necessary
    len = st.len;
    str = new char [len + 1];
    std::strcpy(str, st.str);
}
String & String::operator=(const String & st)
{
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char [len + 1];
    std::strcpy(str, st.str);
    return *this;
}
```

#### （5）移动构造

https://www.cnblogs.com/KillerAery/p/12802771.html

```c++
// && 右值引用
int x = 30;
int &r = x;  //正确，左值引用
int &&r = x; //错误，x为左值，&&r为右值引用
int &&r = 3; //正确，右值引用
const int &r = 3;  //正确，const左值可以对右值引用
```

```c++
class Test
{
    public:
        Test(){p = new int(10);}
        ~Test(){delete p;}
        Test(Test &&ob) noexcept{
            p = ob.p;
            ob.p = nullptr;
        }
        int *p;
};
```

#### （6）移动赋值

```c++
class Test
{
    public:
    	Test() { p = new int(10); }
    	~Test() { delete p; }
    	Test & operator=(Test && ob) noexcept {
        	p = ob.p;
            ob.p = nullptr;
            return *this;
        }
    	int *p;
}
```

#### （7）隐性转换构造【explicit】

### 2、作用域

### 3、静态成员

```c++
// i 由对象共享
// 类中的静态变量应由用户使用类外的类名和范围解析运算符显式初始化
// 静态函数仅访问静态数据成员或静态成员函数
class Apple 
{ 
public: 
    static int i; 
    Apple() 
    { 
        // Do nothing 
    }; 
    static void printMsg() 
    {
        cout<<"Welcome to Apple!"; 
    	cout<<i;
    }
}; 
int Apple::i = 1; 
```

### 3*、静态对象

```c++
#include<iostream> 
using namespace std; 

class Apple 
{ 
    int i; 
    public: 
        Apple() 
        { 
            i = 0; 
            cout << "Inside Constructor\n"; 
        } 
        ~Apple() 
        { 
            cout << "Inside Destructor\n"; 
        } 
}; 

int main() 
{ 
    int x = 0; 
    if (x==0) 
    { 
        static Apple obj; 
    } 
    cout << "End of main\n"; 
}
```

```c++
// 在main结束后调用析构函数,静态对象的范围是贯穿程序的生命周期
Inside Constructor
End of main
Inside Destructor
```

### 4、友元

- 友元关系没有继承性 假如类B是类A的友元，类C继承于类A，那么友元类B是没办法直接访问类C的私有或保护成员。
- 友元关系没有传递性 假如类B是类A的友元，类C是类B的友元，那么友元类C是没办法直接访问类A的私有或保护成员，也就是不存在“友元的友元”这种关系。

#### （1）友员类

友元类的声明在该类的声明中，而实现在该类外。

```c++
friend class <友元类名>;
```

#### （2）友员函数

```c++
friend <类型><友员函数>(<参数>);
```

友元函数只是一个普通函数，并不是该类的类成员函数，它可以在任何地方调用，友元函数中通过对象名来访问该类的私有或保护成员

#### （3）*嵌套类

类嵌套 != 类包含

| 声明位置 | 类使用权 | 派生类使用权 | 外部使用权 |
| -------- | -------- | ------------ | ---------- |
| 私有部分 | 是       | 否           | 否         |
| 保护部分 | 是       | 是           | 否         |
| 公有部分 | 是       | 是           | 是         |

### *5、运算符重载

不能重载的运算符： .  \  .*  \  ::  \  sizeof  \  ?:  

```c++
// 左结合性
c3 = c1 + c2;
c3 = c1.operator(c2);
```

- 重载不能改变运算符的优先级和结合性
- 重载不会改变运算符的用法，原有几个操作数、操作数在左边还是在右边，这些都不会改变
- 运算符重载函数不能有默认的参数，否则就改变了运算符操作数的个数
- 箭头运算符->、下标运算符[ ]、函数调用运算符( )、赋值运算符=只能以成员函数的形式重载

### *6、封装(?)

```c++
// 类内可以访问同类对象私有变量
class Test
{
public:
    Test(){};
    void func(const Test& ob){
        std::cout<<ob.x<<std::endl;
    }

private:
    int x=2;
};
// 类外不能访问
void func(const AnotherClass& ob){
	std::cout<<ob.x<<std::endl;  // error
}
```

## 三、继承

public、private、protect继承

### 1、公有继承

### 2、私有继承

### 3、保护继承

### 4、多重继承

## 四、多态

继承->虚函数

模板

### 1、函数模板

### 2、类模板

## 五、异常处理

### 1、处理方式

### （1）abort()

直接退出程序

```c++
if (a == -b) {
    std::cout << "error";
    std::abort();
}
```

### （2）返回错误

函数返回值，指出错误

### （3）异常机制

```c++
try {
    ...
    throw type;
}
catch (type) {
    ...
}
```

### （4）传递对象

```c++
class EXCEPT
{
   	...
}
catch(EXCEPT & except) {
 	...   
}
```

### 2、~~异常规范~~

c++11删除

### 3、exception类

```c++
// exception 作为其它异常类的基类
// what()虚函数 重新定义
#include <exception>
class new_exc : public std::exception
{
public:
    const char * what() { return "str"; }
};
// usage
try {
    ...
}
catch(std::exception & e) {
    cout << e.what() << endl;
}

// 基于exception的异常类型
// - stdexcept 
// - bad_alloc
// - ...
```

## 六、STL

vector \ deque \ list \ string \ stack \ priority_queue \ set

algorithm

### 1、容器

### （1）vector

```c++
// 初始化
// 一维
vector<int> vec;
vector<int> vec = { 1, 2, 3 };
vector<int> vec(copied_vec); / vector<int> vec = copied_vec;
vector<int> vec(*start, *end);

vec.resize(num) // num个 0 来初始化
vec.resize(n, num) // n 个 num 来初始化
// 二维
vector< vector<int> > tvec;
vector< vector<int> > tvec(dim1, vec);
vector< vector<int> > tvec(*tvec_begin, *tvec_end);

tvec.resize(dim1);
for (int i = 0; i < dim1; i++) tvec[i].resize(dim2);

for (int i = 0; i < tvec.size(); i++) 
    for (int j = 0; j < tvec[i].size(); j++)
        cin >> tvec[i][j];
// 访问元素
pos1 = vec[0];

// 获取大小
size = vec.size();
size = vec.capacity();

// 添加 / 去除元素
vec.push_back(digit);
vec.insert(pos, digit);
vec.pop_back();

vector<int>::iterate it = vec.begin() + pos
vec.erase(it);
vec.erase(remove(vec.begin(), vec.end(), digit), vec.end());

// 查找元素
vector<int>::iterator it = find(vec.begin(), vec.end(), digit);
for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) if () cout << "find";

// 清空容器
vec.clear();

// 遍历容器
for (int i = 0; i < vec.size(); i++) cout << vec[i];
for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) cout << vec[i];
for (type it : vec) cout << it; / for (auto it : vec) cout << it;
```

### （2）map

```c++
// 构造
map<type1, type2> obj;

// 插入
// insert 构造定义， 返回pair对象
pair<iterator, bool> insert (const value_type& val);
// 插入1
obj.insert(pair<type1, type2>(value1, value2));
// 插入2
obj.insert(map<type1, type2>::value_type(value1, value2));
// 插入3 + 覆盖
obj[value1] = value2;
// 插入1/2 是否成功
pair<map <type1, type2>::iterator, bool> Insert_Pair;
Insert_Pair = obj.insert(map<int, string>::value_type(value1, value2));
if (!Insert_Pair.second)
    cout << "Error!" << endl;

// 查找
iter = obj.find("type1");
cout << iter->second << endl;

// 删除
// 迭代器删除
iter = obj.find("type1");
obj.erase(iter);
// 关键字删除
int n = obj.erase("type1"); // 删除成功返回1
// 迭代器范围删除
obj.erase(obj.begin(), obj.end());
// =
obj.clearthist
```

### （3）string

```c++
// 构造
string str("string");
string str{"string"};
string str(num, 'a'); // str:"aaa..."
string str2(str);
string str = "string";

// 获取长度
int len1 = string.length();
int len2 = string.size();

// + .append() push_back()
// == > ...

// 获取字串
string subStr = str.substr(3, 5);

// 查找 
// 未找到返回 string::npos
size_type find (const string& str, size_type pos = 0) const;
size_type find (const char *s, size_type pos, size_type n); 
size_type find (char ch, size_type pos = 0) const;
size_type rfind (char ch, size_type pos = str.length()-1) const;
// string.find_first_of()
// string.find_last_of()
// string.find_first_not_of()
// string.find_last_not_of()

// 交换
str1.swap(str2);

// 转化
std::string str = std::to_string(value);
int num = std::stoi(stringValue);
double num = std::stod(stringValue);
```

### （4）queue

### 2、迭代器

### 3、算法

### 4、智能指针

一个shared_ptr和n个weak_ptr搭配使用而不是n个shared_ptr。
因为一般模型中，最好总是被一个指针控制生命周期，然后可以被n个指针控制访问。

逻辑上，大部分模型的生命在直观上总是受某一样东西直接控制而不是多样东西共同控制。
程序上，能够完全避免生命周期互相控制引发的 循环引用问题。

### （1）~~auto_ptr~~

```c++
// auto_ptr源码
// c++11 弃用，仅用于理解智能指针
template<class X> 
class auto_ptr {
private:
    X* ptr;
    mutable bool owns;
public:
    typedef X element_type;
    explicit auto_ptr(X* p = 0) __STL_NOTHROW : ptr(p), owns(p) {}
    auto_ptr(const auto_ptr& a) __STL_NOTHROW : ptr(a.ptr), owns(a.owns) {
        a.owns = 0;
    }
    template<class T> auto_ptr(const auto_ptr<T>& a) __STL_NOTHROW 
        : ptr(a.ptr), owns(a.owns) {
        a.owns = 0;
    }

    auto_ptr& operator=(const auto_ptr& a) __STL_NOTHROW {
        if (&a != this) {
            if (owns) 
                delete ptr;
            owns = a.owns;
            ptr = a.ptr;
            a.owns = 0;
        }
    }
    template<class T> auto_ptr& operator=(const auto_ptr<T>& a) __STL_NOTHROW {
        if (&a &= this) {
            if (owns)
                delete ptr;
            owns = a.owns;
            ptr = a.ptr;
            a.owns = 0;
        }
    }
    ~auto_ptr() {
        if (owns)
            delete ptr;
    }

    X& operator*() const __STL_NOTHROW { return *ptr; }
    X* operator->() const __STL_NOTHROW { return ptr; }
    X* get() const __STL_NOTHROW { return ptr; }
    X* release() const __STL_NOTHROW { owns = false; return ptr; }
};

// 会引发的问题
void runGame(){
    std::auto_ptr<Monster> monster1(new Monster());//monster1 指向 一个怪物
    monster1->doSomething();//怪物做某种事
    std::auto_ptr<Monster> monster2 = monster1;//转移指针
    monster2->doSomething();//怪物做某种事
    monster1->doSomething();//Oops!monster1智能指针指向了nullptr，运行期崩溃。
}
```

### （2）unique_ptr

但是unique_ptr的名字能更好的体现它的语义，而且在语法上比auto_ptr更安全（尝试复制unique_ptr时会编译期出错，而auto_ptr能通过编译期从而在运行期埋下出错的隐患）

假如你真的需要转移所有权（独占权），那么你就需要用std::move(std::unique_ptr对象)语法，尽管转移所有权后 还是有可能出现原有指针调用（调用就崩溃）的情况。
但是这个语法能强调你是在转移所有权，让你清晰的知道自己在做什么，从而不乱调用原有指针。

```c++
void runGame(){
　　std::unique_ptr<Monster> monster1(new Monster());//monster1 指向 一个怪物
　　std::unique_ptr<Monster> monster2 = monster1;//Error!编译期出错，不允许复制指针指向同一个资源。
　　std::unique_ptr<Monster> monster3 = std::move(monster1);//转移所有权给monster3.
　　monster1->doSomething();//Oops!monster1指向nullptr，运行期崩溃
}
```

```c++
// make_unique<type>
```



### （3）shared_ptr

多个shared_ptr指向同一处资源，当所有shared_ptr都全部释放时，该处资源才释放。
（有某个对象的所有权（访问权，生命控制权） 即是 强引用，所以shared_ptr是一种强引用型指针）

```c++
// shared计数放在这个结构体里面，实际上结构体里还应该有另一个weak计数。下文介绍weak_ptr时会解释。
struct SharedPtrControlBlock{
　　int shared_count;
};
// 大概长这个样子（化简版）
template<class T>
class shared_ptr{
　　T* ptr;
　　SharedPtrControlBlock* count;
};

// 可能会产生的问题：互相/环 引用
class Monster{
　　std::shared_ptr<Monster> m_father;
　　std::shared_ptr<Monster> m_son;
public:
　　void setFather(std::shared_ptr<Monster>& father);
　　void setSon(std::shared_ptr<Monster>& son);　　　 
　　~Monster(){std::cout << "A monster die!";}　　　　//析构时发出死亡的悲鸣
};
void runGame(){
    std::shared_ptr<Monster> father = new Monster();
    std::shared_ptr<Monster> son = new Monster();
    father->setSon(son);
    son->setFather(father);
}
```

```c++
// make_shared<type> 
```



### （4）weak_ptr

weak_ptr是为了辅助shared_ptr的存在，它只提供了对管理对象的一个访问手段，同时也可以实时动态地知道指向的对象是否存活。

（只有某个对象的访问权，而没有它的生命控制权 即是 弱引用，所以weak_ptr是一种弱引用型指针）

```c++
// shared引用计数和weak引用计数
// 之前的计数区域实际最终应该长这个样子
struct SharedPtrControlBlock{
　　int shared_count;  // 被管理资源释放取决与shared_count
　　int weak_count; // weak_ptr 构造析构引起变化
};
// 大概长这个样子（化简版）
template<class T>
class weak_ptr{
　　T* ptr;
　　SharedPtrControlBlock* count;
};

// 局限性
void runGame(){
　　std::shared_ptr<Monster> monster1(new Monster());
　　std::weak_ptr<Monster> r_monster1 = monster1;
　　r_monster1->doSomething();//Error! 编译器出错！weak_ptr没有重载* 和 -> ，无法直接当指针用
　　std::shared_ptr<Monster> s_monster1 = r_monster1.lock();//OK!可以通过weak_ptr的lock方法获得shared_ptr。
}
```

## 七、IO流

## 八、C++ 11

### 1、random

```c++

```

### 2、function

### 3、lambda

```c++
// [capture list] (params list) mutable exception-> return type { function body }
// capture list：捕获外部变量列表
// params list：形参列表
// mutable指示符：用来说用是否可以修改捕获的变量
// exception：异常设定
// return type：返回类型
// function body：函数体
```

### 4、initializer_list

### 5、default/delete

```c++
// =delete 显式的禁用某个函数
class X3 {
public:
    X3();
    X3(const X3&) = delete;  // 声明拷贝构造函数为 deleted 函数
    X3& operator = (const X3 &) = delete; // 声明拷贝赋值操作符为 deleted 函数
};

// =default 生成编译器默认构造函数
```

### 6、variadic template

```c++
// Args 是一个模板参数包；rest 是一个函数参数包
// Args 表示零个或多个模板类型参数
// rest 表示零个或多个函数参数
template <typename T, typename... Args>
void foo(const T &t, const Args& ... rest);
```

### 7、regex

std::regex默认使用是ECMAScript文法，这种文法比较好用，且威力强大，常用符号的意义如下：

| 符号  | 意义                           |
| ----- | ------------------------------ |
| ^     | 匹配行的开头                   |
| $     | 匹配行的结尾                   |
| .     | 匹配任意单个字符               |
| […]   | 匹配[]中的任意一个字符         |
| (…)   | 设定分组                       |
| \     | 转义字符                       |
| \d    | 匹配数字[0-9]                  |
| \D    | \d 取反                        |
| \w    | 匹配字母[a-z]，数字，下划线    |
| \W    | \w 取反                        |
| \s    | 匹配空格                       |
| \S    | \s 取反                        |
| +     | 前面的元素重复1次或多次        |
| *     | 前面的元素重复任意次           |
| ?     | 前面的元素重复0次或1次         |
| {n}   | 前面的元素重复n次              |
| {n,}  | 前面的元素重复至少n次          |
| {n,m} | 前面的元素重复至少n次，至多m次 |
| \|    | 逻辑或                         |

- 匹配

```c++
 1  std::regex reg("<.*>.*</.*>");
 2  bool ret = std::regex_match("<html>value</html>", reg);
 3  assert(ret);
 4  
 5  ret = std::regex_match("<xml>value<xml>", reg);
 6  assert(!ret);
 7  
 8  std::regex reg1("<(.*)>.*</\\1>");
 9  ret = std::regex_match("<xml>value</xml>", reg1);
10  assert(ret);
11  
12  ret = std::regex_match("<header>value</header>", std::regex("<(.*)>value</\\1>"));
13  assert(ret);
14  
15  // 使用basic文法
16  std::regex reg2("<\\(.*\\)>.*</\\1>", std::regex_constants::basic);
17  ret = std::regex_match("<title>value</title>", reg2);
18  assert(ret);
```

- 搜索
- 分词
- 替换
## 九、C++ 17

### 1、string_view







