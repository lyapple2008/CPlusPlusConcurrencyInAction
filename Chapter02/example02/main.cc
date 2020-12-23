#include <iostream>
#include <thread>
#include <unistd.h>

void do_something(std::string& count)
{
    std::cout << "sub-thread start" << std::endl;

    sleep(3);

    std::cout << "Hello, World!" << std::endl;
    count = "5";
    std::cout << "sub-thread: modify count = " << count << std::endl;
    std::cout << "sub-thread end" << std::endl;
}

class X
{
    public:
    void do_lengthy_work() {
        std::cout << "X: do_lengthy_work" << std::endl;
    }
};

int main(int argc, char* argv[])
{
    std::cout << "std::thread::hardware_concurrency() = " << std::thread::hardware_concurrency() << std::endl;

    std::string count = "1";
    std::cout << "main thread start" << std::endl;
    // std::thread t(do_something, std::ref(count));

    X my_x;
    std::thread t(&X::do_lengthy_work, &my_x);

    if (t.joinable()) {
        t.join();
    }

    std::cout << "count = " << count << std::endl;
    std::cout << "main thread end" << std::endl;
    return 0;
}