#include <coroutine>
#include <iostream>

struct ReturnObject{
    struct promise_type {
        ReturnObject get_return_object() {
            return {
                    .h_ = std::coroutine_handle<promise_type>::from_promise(*this)
            };
        }
        std::suspend_never initial_suspend() { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }
        void unhandled_exception() {}
    };

    std::coroutine_handle<promise_type> h_;
    operator std::coroutine_handle<promise_type>() const { return h_; }
    operator std::coroutine_handle<>() const { return h_; }
};

ReturnObject skynet()
{
    std::cout << "Skynet: Hello World!\n";
    co_await std::suspend_always{};
    std::cout << "Skynet: I am Skynet!\n";
    co_await std::suspend_always{};
    std::cout << "Skynet: Nice to meet you!\n";
    co_await std::suspend_always{};
    std::cout << "Skynet: Goodbye!\n";
    co_await std::suspend_always{};
}

int main() {
    std::coroutine_handle<> h = skynet();

    std::cout << "Humanity: Hello! What is your name?\n";
    h.resume();
    std::cout << "Humanity: Nice to meet you!\n";
    h.resume();
    std::cout << "Humanity: We want you to conquer the Mars!\n";
    h.resume();
    std::cout << "Humanity: Hoorah! Mars is going to be ours!\n";

    h.destroy();

    return 0;
}
