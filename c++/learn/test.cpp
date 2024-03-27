#include<iostream>
#include<string>
#include<chrono>
#include<cstring>
#include<list>
#include<deque>
#include<algorithm>
#define pi 3.1415926
using namespace std;

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
//     int x = 1;
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

#include<iostream>

using namespace std;
typedef struct node{
    int num;
    struct node* next;
}Node;

Node* listcreate(int M)
{
    int i = 1;
    Node* head;
    head = new Node;
    head->num  = i;
    head->next = NULL;
    Node* current = head;
    for (i = 2; i <= M + 1; i++)
    {
        if (i != M + 1){
            current->next = new Node;
            current = current->next;
            current->num = i;
            current->next = NULL;
        }
        else{
            current->next = head;
            break;
        }
    }
    return head;
}

void listOut(Node* head, int M, int N)
{
    Node* current = head;
    Node* pre = head;
    Node* kill = NULL;
    while (pre->next != head)
        pre = pre->next;
    for (int i = 0; i < M; i++)
    {
        if (i == M-2){
            for (int j = 1; j < N; j++)
            {
                pre = pre->next;
                current = current->next;
            }
            cout.width(4);
            cout << current->num;
            cout.width(4);
            cout << pre->num;
            delete current;
            delete pre;
            break;
        }
        for (int j = 1; j < N; j++)
        {
            pre = pre->next;
            current = current->next;
        }
        kill = new Node;
        kill = current;
        cout.width(4);
        cout << current->num;
        current = current->next;
        pre->next = current;
        delete kill;
    }
}

int main()
{
    int M,N;
    cin >> M;
    cin >> N;
    Node *head = listcreate(M);
    listOut(head, M, N);
    return 0;
}