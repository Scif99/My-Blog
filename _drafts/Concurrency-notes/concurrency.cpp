#include <iostream>
#include <thread>

void hello() {
    std::cout<<"Hello, woncurrent world"<<'\n';
}
void goodbye() {
    std::cout<<"Goodbye, woncurrent world!"<<'\n';
}

struct mytype {

    void operator() () const {
        hello();
        goodbye();
    }
};


class thread_guard {
    std::thread& t;
public:
    thread_guard(std::thread& t_) 
        :t{t_} {}

    ~thread_guard() {
        if(t.joinable()) {
            t.join();
        }
    }

};



int main() {

    // mytype m;
    // std::thread thr{ [m]() { m();}}; //'Capture' m from surrounding scope, then call it in the lambda
    // std::cout<<"Hello, world!"<<'\n';
    // thr.join(); //the calling thread (main) now waits for thr.



    
}
