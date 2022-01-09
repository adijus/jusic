#ifndef PIPE_H
#define PIPE_H

#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class Pipe {
    std::queue<T> backend;
    std::mutex mtx;
    std::condition_variable not_empty;
    bool closed{false};
  public:
    Pipe& operator<<(T value) {
        backend.push(value);
        return *this;
    }
    
    Pipe& operator>>(T& value) {
        while(!backend.empty()){
            if(backend.front() == value)
            std::cout << backend.front() << " ";
        }
        std::cout << std::endl;
        return *this;
    }

    void close() {
        std::unique_lock<std::mutex> lck(mtx);
        while(!closed) not_empty.wait(lck);

    }
    
    explicit operator bool() {
        while(backend >> backend.front()){
            std::cout << backend.front() << std::endl;
        }
        return *this;
    }
};
#endif
