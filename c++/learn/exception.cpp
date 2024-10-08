#include <iostream>
#include <cstdlib>  // for std::abort

int check(int a, int b);

int main()
{
    int a, b;
    std::cin >> a >> b;
    int c = check(a, b);
    return 0;
}

int check(int a, int b)
{
    if (a == -b) {
        std::cout << "Fatal error: a and b are opposites. Program will terminate.\n";
        std::abort();  // Terminates the program abruptly
    }
    return a * b;
}

