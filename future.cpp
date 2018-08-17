#include <iostream>

#include <utility>
#include <thread>
#include <future>

using namespace std;

void thread_function(promise<string> && prms){
    string str = "hello from future\n";
    cout << "Str ptr : " << (void *)str.data() << endl;
    prms.set_value(move(str));
}

int main() {
    promise<string> prms;
    future<string> ftr = prms.get_future();
    thread th = thread(&thread_function, move(prms));
    
    cout << "hello from main\n";
    string str = ftr.get();
    cout << str;
    cout << "Str ptr : " << (void *)str.data() << endl;

    th.join();
        
    return 0;
}