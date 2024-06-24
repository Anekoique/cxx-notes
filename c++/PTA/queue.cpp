#include <iostream>
#include <deque>
#include <string>

template <typename T>
class MyQueue {
private:
    std::deque<T> data;

public:
    // 构造函数
    MyQueue() {}

    // 入队操作
    void push(T value) {
        data.push_back(value);
    }

    // 出队操作
    void pop() {
        if (!data.empty()) {
            data.pop_front();
        }
    }

    // 判断队列是否为空
    bool empty() const {
        return data.empty();
    }

    // 获取队首元素
    T front() const {
        if (!data.empty()) {
            return data.front();
        }
        throw std::runtime_error("Queue is empty");
    }

    // 复制构造函数
    MyQueue(const MyQueue& other) : data(other.data) {}

    // 赋值操作符
    MyQueue& operator=(const MyQueue& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }
};

// 指令执行函数模板
template <typename T>
void executeCommands(MyQueue<T>& queue1, MyQueue<T>& queue2, MyQueue<T>& queue3, int n) {
    for (int i = 0; i < n; ++i) {
        std::string command;
        std::cin >> command;
        if (command == "push") {
            int index;
            T value;
            std::cin >> index >> value;
            if (index == 1) queue1.push(value);
            else if (index == 2) queue2.push(value);
            else if (index == 3) queue3.push(value);
        } else if (command == "pop") {
            int index;
            std::cin >> index;
            if (index == 1) queue1.pop();
            else if (index == 2) queue2.pop();
            else if (index == 3) queue3.pop();
        } else if (command == "assign") {
            int i1, i2;
            std::cin >> i1 >> i2;
            if (i1 == 1 && i2 == 2) queue2 = queue1;
            else if (i1 == 1 && i2 == 3) queue3 = queue1;
            else if (i1 == 2 && i2 == 3) queue3 = queue2;
        }
    }
}
int main() {
    // 读取队列元素类型
    std::string type;
    std::cin >> type;
    if (type == "int") {
        MyQueue<int> queue1, queue2, queue3;
        int n;
        std::cin >> n;
        executeCommands(queue1, queue2, queue3, n);
        MyQueue<int> queue4(queue1); // 复制构造新队列
        std::cout << std::endl;
        // 去掉const限定符
        for (auto& q : {queue1, queue2, queue3, queue4}) {
            while (!q.empty()) {
                std::cout << q.front() << " ";
                q.pop(); // 现在可以调用pop函数
            }
            std::cout << std::endl;
        }
    } else if (type == "string") {
        MyQueue<std::string> queue1, queue2, queue3;
        int n;
        std::cin >> n;
        executeCommands(queue1, queue2, queue3, n);
        MyQueue<std::string> queue4(queue1); // 复制构造新队列
        std::cout << std::endl;
        // 去掉const限定符
        for (auto& q : {queue1, queue2, queue3, queue4}) {
            while (!q.empty()) {
                std::cout << q.front() << " ";
                q.pop(); // 现在可以调用pop函数
            }
            std::cout << std::endl;
        }
    }
    return 0;
}
