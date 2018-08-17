#include <iostream>
#include <vector>

#include <future>
#include <chrono>

using namespace std;

int square(int x){
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << x << " in thread id " << this_thread::get_id() << endl;
    return x * x;
}

int main(){
    vector<future<int>> futures;
    for (int i = 1; i != 21; ++i){
        futures.push_back(async(launch::async, &square, i));
    }
    int accum = 0;

    for (auto& f : futures){
        accum += f.get();
    }

    cout << "this thread at id " << this_thread::get_id() << "returned " << accum << endl;
    return 0;
}