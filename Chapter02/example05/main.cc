#include <thread>
#include <iostream>

void do_something()
{
    std::thread::id id = std::this_thread::get_id();
    std::cout << "sub-thread: id = " << id << std::endl;
}

int main(int argc, char* argv[])
{
    std::thread::id id = std::this_thread::get_id();
    std::cout << "main-thread: id = " << id << std::endl;
    std::thread t(do_something);

    if (t.joinable()) {
        t.join();
    }

    return 0;
}