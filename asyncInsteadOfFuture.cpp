#include <iostream>
#include <stdexcept>

#include <utility>
#include <thread>
#include <future>

using namespace std;

// instead of using so much boiler plate code of promise, 
// future, and setting/getting the value,
// we can create a task instead of a thread using async
// Added benfit of using regular functions without additional code

string func(){
    string str = "hello from future\n";
    return str;
}

int main() {
    /*promise<string> prms;
    future<string> ftr = prms.get_future();
    thread th(&thread_function, move(prms)); DONT NEED ANY OF THIS*/
    auto ftr = async(&func); // type of auto is future<string>

    string str = ftr.get();
    cout << "hello from main\n";
    cout << str;
    
    // th.join(); no thread, so don't need to join
        
    return 0;
}