#include <iostream>
#include <vector>

#include <atomic> // atomic<int> creates an atomic container, evaluating 
#include <thread> // thread th = thread(&func, args) 
#include <mutex> // mutex foo; foo.lock() and foo.unlock() around the fetch and modify event
#include <future> // future object returned by async(&func, args), then call .get() on the future object
#include <chrono> // async returns a future object
using namespace std;

// mutex accum_mutex;



void square(atomic<int>& accum, int x){
    // execution of the 'expensive' calculation done outside of lock/unlock
    accum += x * x;

    // when a thread reaches a lock, all other threads that 
    // reach lock will simply halt, waiting for an unlock by
    // the first thread
    
    // inside the lock, just update the accum
    // accum_mutex.lock();
    // accum += temp;
    // accum_mutex.unlock();
}

int main() {
    vector<thread> ths;

    //int accum = 0;
    atomic<int> accum(0);

    for (int i = 1; i != 21; ++i){
        ths.push_back(thread(&square, ref(accum), i));
    }
    // cout << "done adding "<< endl;
    for (auto& th : ths){
        th.join();
    }

    cout << "Accum = " << accum << endl;

    return 0;
}