/**
耗时统计类

g++ -Wall -std=c++11 main.cpp 

命名空间太长了。。。
*/

#include <chrono>

class CTimer
{
public:
    CTimer() : m_begin(std::chrono::high_resolution_clock::now()){}
    void reset() { m_begin = std::chrono::high_resolution_clock::now(); }

    //默认输出毫秒
    double ms() const
    {
      return std::chrono::duration_cast<std::chrono::duration<double>>
             (std::chrono::high_resolution_clock::now() - m_begin).count();
    }

    //微秒
    int64_t us() const
    {
        return std::chrono::duration_cast<std::chrono::microseconds>
               (std::chrono::high_resolution_clock::now() - m_begin).count();
    }

    //纳秒
    int64_t ns() const
    {
        return std::chrono::duration_cast<std::chrono::nanoseconds>
               (std::chrono::high_resolution_clock::now() - m_begin).count();
    }

    //秒
    int64_t s() const
    {
        return std::chrono::duration_cast<std::chrono::seconds>
               (std::chrono::high_resolution_clock::now() - m_begin).count();
    }

    //分
    int64_t m() const
    {
        return std::chrono::duration_cast<std::chrono::minutes>
               (std::chrono::high_resolution_clock::now() - m_begin).count();
    }

    //时
    int64_t h() const
    {
        return std::chrono::duration_cast<std::chrono::hours>
               (std::chrono::high_resolution_clock::now() - m_begin).count();
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_begin;
};