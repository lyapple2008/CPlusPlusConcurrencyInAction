#include <iostream>
#include <thread>

void do_something()
{
    std::cout << "Hello, World!" << std::endl;
}

int main(int argc, char* argv[])
{
    std::thread t(do_something);

    t.join();

    return 0;
}