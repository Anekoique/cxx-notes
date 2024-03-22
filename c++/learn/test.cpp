#include<iostream>
#include<string>
#include<chrono>
#include<cstring>
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

class Person{
public:
    typedef enum {
        BOY = 0, 
        GIRL 
    }SexType;
    Person(const char *n, int a,SexType s){
        name=new char[strlen(n)+1];
        strcpy(name,n);
        age=a;
        sex=s;
    }
    int get_age() const{

        return this->age; 
    }
    Person& add_age(int a){
        age+=a;
        return *this; 
    }
    ~Person(){
        delete [] name;
    }
private:
    char * name;
    int age;
    SexType sex;
};


int main(){
    Person p("zhangsan",20,Person::BOY); 
    cout<<p.get_age()<<endl;
    cout<<p.add_age(10).get_age()<<endl;
    return 0;
}
