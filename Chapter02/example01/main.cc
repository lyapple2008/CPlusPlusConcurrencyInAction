#include <iostream>
#include <thread>
#include <unistd.h>

void do_something()
{
    std::cout << "sub-thread start" << std::endl;

    sleep(3);

    std::cout << "Hello, World!" << std::endl;

    std::cout << "sub-thread end" << std::endl;
}

int main(int argc, char* argv[])
{
    std::cout << "main thread start" << std::endl;
    std::thread t(do_something);

    t.detach();

    std::cout << "main thread end" << std::endl;
    return 0;
}