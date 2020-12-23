#include <thread>
#include <iostream>
#include <future>
#include <chrono>
#include <ctime>
#include <iomanip>

int get_result()
{
    std::this_thread::sleep_for(std::chrono::seconds(10));

    return -1;
}

void do_something()
{
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

void out_cur_time()
{
    auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::cout << std::put_time(std::localtime(&t), "%Y-%m-%d %X") << std::endl;
}

int main(int argc, char* argv[])
{
    out_cur_time();
    std::cout << "main-thread: start" << std::endl;
    std::future<int> result = std::async(get_result);

    out_cur_time();
    std::cout << "main-thread: do_something" << std::endl;
    do_something();
    
    out_cur_time();
    std::cout << "main-thread: start get result" << std::endl;

    int ret = result.get();
    
    out_cur_time();
    std::cout << "main-thread: return result: " << ret << std::endl;

    return 0;
}