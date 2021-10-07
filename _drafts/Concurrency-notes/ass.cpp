#include <assert.h>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>

// void some_func() {};
// void some_other_func() {};

// std::thread t1(some_func); //construct t1 with some_func object
// //std::thread t2 = t1; //error, can't copy a thread!
// std::thread t2 = std::move(t1); // move ownership from t1 to t2
// auto t1 = std::thread(some_other_func);
// std::thread t3;
// auto t3 = std::move(t2);
// auto t1 = std::move(t3); //will terminate. t1 already owns a thread!


void do_work(unsigned i) {
    std::cout<<i;
}

void f() {
    std::vector<std::thread> threads;
    for(unsigned i = 0;i<10;++i) {
        threads.emplace_back(do_work,i);

    }
    for(auto& worker : threads) {
        worker.join();
    }
}

int main() {

    f();

}