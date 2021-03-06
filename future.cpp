#include <iostream>
#include <stdexcept>

#include <utility>
#include <thread>
#include <future>

using namespace std;

void thread_function(promise<string> && prms){
    try {
        string str = "hello from future\n";
        throw(logic_error("error thrown from the future"));
        prms.set_value(move(str));
    } catch(...){
        prms.set_exception(current_exception());
    }
}

int main() {
    promise<string> prms;
    future<string> ftr = prms.get_future();
    thread th(&thread_function, move(prms));
    
    try{
        string str = ftr.get();
        cout << "hello from main\n";
        cout << str;
    } catch (const logic_error& e){
        cout << e.what() << endl;
    }

    th.join();
        
    return 0;
}