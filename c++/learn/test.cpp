#include<iostream>
#include<string>
#include<chrono>
#include<cstring>
#include<list>
#include<deque>
#include<algorithm>
#define pi 3.1415926

/*int main()
{
    string str;
    //cin >> str;
    //cout << str << endl;
    cin >> noskipws >>str;
    cout << str << endl;
    return 0;
}*/


// int change(const int &a) // int change(int a)
// {
//     return a+2;
// }
// int main()
// {
//     auto start = std::chrono::high_resolution_clock::now();
//     int x = 3;
//     cout << change(x) << endl;
//     auto end = std::chrono::high_resolution_clock::now();
//     std::chrono::duration<double> duration = end - start;
//     cout << duration.count() << " seconds" << endl;
//     return 0;
// }


// class Apple 
// { 
// public: 
//     static int i; 

//     Apple() 
//     { 
//         // Do nothing 
//     }; 
// }; 
// int Apple::i = 1; 

// int main() 
// { 
//     Apple obj; 
//     Apple obj2;
//     // prints value of i 
//     obj.i = 2;
//     obj2.i = 3;
//     cout << obj.i << " " << obj2.i <<endl; 
// } 

// class Apple 
// { 
//     public: 
//         static int i;
//         // static member function 
//         static void printMsg() 
//         {
//             cout<<"Welcome to Apple!" << i; 
//         }
// }; 
// int Apple::i = 1;

// // main function 
// int main() 
// { 
//     // invoking a static member function 
//     Apple::printMsg(); 
// } 

// class Circle {
// private:
//     double radius;

// public:
//     Circle(double r) : radius(r) {}

//     double getArea() const {
//         return 3.14 * radius * radius;
//     }
// };

// int main() {
//     Circle c(5); // 常对象c，半径为5

//     // 调用常成员函数getArea计算常对象c的面积
//     double area = c.getArea();

//     std::cout << "The area of the circle with radius 5 is: " << area << std::endl;

//     return 0;
// }

// class Person{
// public:
//     typedef enum {
//         BOY = 0, 
//         GIRL 
//     }SexType;
//     Person(const char *n, int a,SexType s){
//         name=new char[strlen(n)+1];
//         strcpy(name,n);
//         age=a;
//         sex=s;
//     }
//     int get_age() const{

//         return this->age; 
//     }
//     Person& add_age(int a){
//         age+=a;
//         return *this; 
//     }
//     ~Person(){
//         delete [] name;
//     }
// private:
//     char * name;
//     int age;
//     SexType sex;
// };


// int main(){
//     Person p("zhangsan",20,Person::BOY); 
//     cout<<p.get_age()<<endl;
//     cout<<p.add_age(10).get_age()<<endl;
//     return 0;
// }

// void Print_D(int x)
// {
// 	cout.width(5);			
// 	cout<<x;
// }
// int main()
// {
//     list<int> L;
//     int x;
//     while (cin >> x && x != 0){
//         if (x > 0)
//             L.push_front(x);
//         else
//             L.push_back(x);
//     }
//     for_each(L.begin(),L.end(),Print_D);
//     deque<int> D;
//     while (cin >> x && x != 0){
//         if (x > 0)
//             D.push_front(x);
//         else
//             D.push_back(x);
//     }
//     for_each(D.begin(),D.end(),Print_D);
// }
// #include <iomanip>

// class Circle
// {
// public:
//     Circle(float r) : R(r) {}
//     float S();
//     float C();
// private:
//     float R;
// };

// float Circle::S()
// {
//     float S = pi * R * R;
//     return S;
// }

// float Circle::C()
// {
//     float C = 2 * pi * R;
//     return C;
// }

// int main()
// {
//     float r;
//     std::cin >> r;
//     Circle c(r);
//     std::cout << std::fixed << std::setprecision(2) << c.S()*20 + c.C()*35 << std::endl;
//     return 0;
// }

// #include<iostream>

// using namespace std;
// typedef struct node{
//     int num;
//     struct node* next;
// }Node;

// Node* listcreate(int M)
// {
//     int i = 1;
//     Node* head;
//     head = new Node;
//     head->num  = i;
//     head->next = NULL;
//     Node* current = head;
//     for (i = 2; i <= M + 1; i++)
//     {
//         if (i != M + 1){
//             current->next = new Node;
//             current = current->next;
//             current->num = i;
//             current->next = NULL;
//         }
//         else{
//             current->next = head;
//             break;
//         }
//     }
//     return head;
// }

// void listOut(Node* head, int M, int N)
// {
//     Node* current = head;
//     Node* pre = head;
//     Node* kill = NULL;
//     while (pre->next != head)
//         pre = pre->next;
//     for (int i = 0; i < M; i++)
//     {
//         if (i == M-2){
//             for (int j = 1; j < N; j++)
//             {
//                 pre = pre->next;
//                 current = current->next;
//             }
//             cout.width(4);
//             cout << current->num;
//             cout.width(4);
//             cout << pre->num;
//             delete current;
//             delete pre;
//             break;
//         }
//         for (int j = 1; j < N; j++)
//         {
//             pre = pre->next;
//             current = current->next;
//         }
//         kill = new Node;
//         kill = current;
//         cout.width(4);
//         cout << current->num;
//         current = current->next;
//         pre->next = current;
//         delete kill;
//     }
// }

// int main()
// {
//     int M,N;
//     cin >> M;
//     cin >> N;
//     Node *head = listcreate(M);
//     listOut(head, M, N);
//     return 0;
// }

// class Boat;
 
// class Car
// {
// public:
// 	Car(int weight){
// 		this->weight=weight;
// 	}
 
// 	friend int getToalWeight(Car &c,Boat &b); 
// private:
// 	int weight;
// };
 
// class Boat
// {
// public:
// 	Boat(int weight){
// 		Boat::weight=weight;
// 	}
//     friend int getToalWeight(Car &c,Boat &b); 
// private:
// 	int weight;
// };
 
//     int getToalWeight(Car &c,Boat &b){
// 		return b.weight+c.weight;
// 	}
// int main(){
// 	Boat b(300);
// 	Car c(40);
 
// 	cout<<"总重量为:"<<getToalWeight(c,b)<<endl;
// 	return 0;
// }

// #include<iostream>
// #include<cstring>


// using namespace std;
// class Person{
// public:
//     typedef enum {
//         BOY = 0, 
//         GIRL 
//     }SexType;
//     Person(const char *n, int a,SexType s){
//         name=new char[strlen(n)+1];
//         strcpy(name,n);
//         age=a;
//         sex=s;
//     }
//     int get_age() const{

//         return this->age; 
//     }
//     Person add_age(int a){
//         age+=a;
//         return *this; 
//     }
//     ~Person(){
//         delete [] name;
//     }
// private:
//     char * name;
//     int age;
//     SexType sex;
// };


// int main(){
//     Person p("zhangsan",20,Person::BOY); 
//     cout<<p.get_age()<<endl;
//     cout<<p.add_age(10).get_age()<<endl;
//     return 0;
// }

// #include <iostream>

// using namespace std;

// class A
// {
// public:
//     A(int _a):a(_a){};
//     friend class B;
	
// private:
//     int a;
// };

// class B
// {
// public:
//     int getb(A ca) {
//         return  ca.a; 
//     };
// private:
// 	int b;
// };

// int main() 
// {
//     A a(3);
    
// 	B b;
	
//     cout<<b.getb(a)<<endl;
	
//     return 0;
// }

// #include<iostream>
// #include<vector>
// #include<queue>
// #include<stack>
// #include<cstdio>

// using namespace std;

// int main()
// {
//     int x;
//     vector<int> V;
//     queue<int> Q;
//     stack<int> S1, S2;
//     while(scanf("%d", &x) && x != 0)
//     {
//         if(x < 0)
//             V.push_back(x);
//         if (x>0)
//         {
//             int flag = 1;
//             for (int i = 2; i < x; i++){
//                 if (x%i == 0){
//                     flag = 0;
//                     break;
//                 }
//             }
//             if(flag)
//                 Q.push(x);
//             if (x % 2 == 0){
//                 S1.push(x);
//             }else{
//                 S2.push(x);
//             }
//         }
//     }
//     for (int i : V){
//         cout << i << '\t';
//     }
//     cout << endl;
//     while (!Q.empty()){
//         cout << Q.front() << '\t';
//         Q.pop();
//     }
//     cout << endl;
//     while(!S1.empty()){
//         cout << S1.top() << '\t';
//         S1.pop();
//     }
//     cout << endl;
//     while (!S2.empty()){
//         cout << S2.top() << '\t';
//         S2.pop();
//     }
//     cout << endl;
    
// }

// #include<iostream>
// #include<stack>
// #include<cstdio>

// using namespace std;

// int main()
// {
//     stack<int> s1, s2;
//     int flag, x;
//     while(scanf("%d%d", &flag, &x) != EOF)
//     {
//         if(flag == 1)
//             s1.push(x);
//         else
//             s2.push(x);
//     }
//     while(!s1.empty()){
//         cout << s1.top() << ' ';
//         s1.pop();
//     }
//     cout << endl;
//     while (!s2.empty()){
//         cout << s2.top() << ' ';
//         s2.pop();
//     }
// }

// int main()
// {
//     // char * str;
//     // cin >> str;
//     // cout << str << endl;
//     char string[15];
//     cin >> string;
//     cout << string <<endl;
//     char * str = string;
//     cout << str << endl;
// }

// #include<stdio.h>
// #include<stdlib.h>

// struct list
// {
//     int data;
//     struct list *next;
//     struct list *pre;
// };

// void stackPush(struct list *stack,int x)
// {
//     struct list *current = stack;
//     struct list *pre;
//     while (current->next != stack){
//         if (current->next == NULL)
//             break;
//         current = current->next;
//     }
//     current->next = (struct list*)malloc(sizeof(struct list));
//     current->next->pre = current;
//     current = current->next;
//     current->data = x;
//     current->next = stack;
//     stack->pre = current;
// }

// void queuePush(struct list *queue, int x)
// {
//     struct list *current = queue;
//     while (current->next != NULL){
//         current = current->next;
//     }
//     current->next = (struct list*)malloc(sizeof(struct list));
//     current = current->next;
//     current->data = x;
//     current->next = NULL;
// }

// void stackShow(struct list *stack)
// {
//     struct list *current = stack;
//     while (current->next != stack)
//         current = current->next;
//     while (current != stack){
//         printf("%5d", current->data);
//         current = current->pre;
//     }
// }

// void queueShow(struct list *queue)
// {
//     struct list *current = queue->next;
//     while(current->next != NULL)
//     {
//         printf("%5d", current->data);
//         current = current->next;
//     }
// }

// int main()
// {
//     int x;
//     struct list *stack;
//     struct list *queue;
//     stack = (struct list*)malloc(sizeof(struct list));
//     stack->next = NULL;
//     queue = (struct list*)malloc(sizeof(struct list));
//     queue->next = NULL;
//     while (scanf("%d", &x) != EOF)
//     {
//         if (x > 0)
//             stackPush(stack, x);
//         else if (x < 0)
//             queuePush(queue, x);
//     }
//     stackShow(stack);
//     queueShow(queue);
// }

// void add(int a, int b)
// {
//     printf("%d", a + b);
// }
// int main()
// {
//     int a = 1;
//     int b = 2;
//     int *ptr1 = &a;
//     int *ptr2 = &b;
//     add(a++, b++);
//     printf("%d%d", a, b);
//     printf("\n%d%d", )
// }

// #include<iostream>
// #include<cstdio>

// using namespace std;
// class Matrix
// {
// public:
//     Matrix(int m, int n);
//     void ReadMatrix();
//     void WriteMatrix();
//     void Transpose(Matrix& B);
// private:
//     int* M;
//     int row, column;
// };
// Matrix::Matrix(int m,int n)
// {
//     M = new int[m * n];
//     row = m;
//     column = n;
// }
// void Matrix::ReadMatrix()
// {
//     int t;
//     for (int i = 0; i < row; i++){
//         for (int j = 0; j < column; j++){
//             scanf("%d", &t);
//             M[i * row + j] = t;
//         }
//     }
// }
// void Matrix::WriteMatrix()
// {
//     for (int i = 0; i < row; i++){
//         for (int j = 0; j < column; j++){
//             printf("%d ", M[i * row + j]);
//         }
//         printf("\n");
//     }
// }
// void Matrix::Transpose(Matrix& B)
// {
//     for (int j = 0; j < column; j++){
//         for (int i = 0; i < row; i++){
//             B.M[j * column + i] = M[i * row + j];
//         }
//     }
// }
// int main()
// {
//     int m, n;
//     cin >> m >> n;
//     Matrix A(m, n);
//     A.ReadMatrix();
//     A.WriteMatrix();
//     Matrix B(n, m);
//     A.Transpose(B);
//     B.WriteMatrix();
//     system("pause");
//     return 0;
// }

// #include <iostream>
// using namespace std;
 
// class A {
// public:
// 	int x;
// 	A(int x) : x(x)
// 	{
// 		cout << "Constructor" << endl;
// 	}
// 	A(A& a) : x(a.x)
// 	{
// 		cout << "Copy Constructor" << endl;
// 	}
// 	A& operator=(A& a)
// 	{
// 		x = a.x;
// 		cout << "Copy Assignment operator" << endl;
// 		return *this;
// 	}
// 	A(A&& a) : x(a.x)
// 	{
// 		cout << "Move Constructor" << endl;
// 	}
// 	A& operator=(A&& a)
// 	{
// 		x = a.x;
// 		cout << "Move Assignment operator" << endl;
// 		return *this;
// 	}
// };
 
 
// int main()
// {
// 	A a(1);
// 	A b = a;
// 	A c(a);
// 	b = a;
// 	A e = move(a);
//     b = move(a);
// 	return 0;
// }
//
//class Base {
//public:
//	void fn1();
//	void fn2();
//};
//
//void Base::fn1() {
//	printf("hello fn1");
//}
//void Base::fn2() {
//	printf("hello fn2");
//}
//
//class Derived : public Base {
//		
//}
//
//
//int main() {
//	Derived a;
//	a.fn1();
//	return 0;
//}

//class Mammal {
//	int age; 
//public:
//	Mammal(int age=4) : age(age){
//		printf("the Mammal birth");
//	};
//	~Mammal(){
//		printf("the Mammal die\n");
//	}
//	void speak() {
//		printf("hello world\n");
//	}
//	int getAge() {
//		return age;
//	}
//};
//class Dog : public Mammal {
//public:
//	Dog() {
//		printf("the dog birth\n");
//	}
//	~Dog() {
//		printf("the dog die\n");
//	}
//	void wagTail() {
//		printf("this is the wagtail\n");
//	}
//};
//int main() {
//	Dog jack;
//	jack.speak();
//	jack.wagTail();
//	cout << "Jack is " << jack.getAge() << " years old\n";
//}
//
//
//class BaseClass {
//public:
//	void fn1() {
//		cout >> "hello fn1" >> endl;
//	}
//	void fn2() {
//		cout >> "hello fn2" >> endl;
//	}
//};
//
//class DerivedClass : public BaseClass {
//public:
//	void fn1() {
//		cout >> "fn1 too!" >> endl;
//	}
//	void fn2() {
//		cout >> "fn2 too!" >> endl;
//	}
//};
//
//int main() {
//	DerivedClass aDerivedClass;
//	DerivedClass * pDerivedClass = &aDerivedClass;
//	BaseClass *pBaseClass = &aDerivedClass;
//	aDerivedClass.fn1();
//	aDerivedClass.fn2();
//	pBaseClass->fn1();
//	pBaseClass->fn2();
//	pDerivedClass->fn1();
//	pDerivedClass->
//}
// int main() {
// 	int a;
// 	cin >> a;
// 	cout << a;
// 	int number = 1;
// 	cout << number;
// 	cout << number;
// 	cout << number;
// 	return number;
// }
//
#include <iostream>

void check(int a, int b)
{
    if (a == -b) throw "error";
}

int main()
{
    int a = 1, b = -1;
    try {
        check(a, b);
        try {
            check(a, b);
        }
        catch(std::string str) {
            std::cout << str;

        }
    }
    catch(std::string str) {
        std::cout << str;
    }
}
