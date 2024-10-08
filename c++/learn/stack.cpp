#include <iostream>

void check2(int a, int b)
{
    if (a == -b) throw "error2";
}
void check(int a, int b)
{
    try {
        check2(a, b);
    }
    catch(std::string str) {
        std::cout << str << " part";
    }
    catch(const char * str) {
        std::cout << str << " part";
    }
    if (a == -b) throw "error";
    check2(a, b);
}


int main()
{
    int a = 1, b = -1;
    try {
        try {
            check(a, b);
        }
        catch(std::string str) {
            std::cout << str << " part";
        }
        catch(const char * str) {
            std::cout << str << " part";
        }
        check(a, b);
        check2(a, b);
    }
    catch(std::string str) {
        std::cout << str;
    }
    catch(const char * str) {
        std::cout << str;
    }

    return 0;
}
