#include <mutex>
#include <memory>

class SingleTon {
public:
    static SingleTon& GetInstance() {
        static std::once_flag s_flag;
        std::call_once(s_flag, [&](){
            instance_.reset(new SingleTon());
        });

        return *instance_;
    }

    ~SingleTon() = default;
private:
    SingleTon() = default;
    SingleTon(const SingleTon&) = delete;
    SingleTon& operateor=(const SingleTon&) = delete;

private:
    static std::unique_ptr<SingleTon> instance_;
};