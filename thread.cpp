#include <algorithm>
#include <iostream>
#include <vector>

#include <thread>

using namespace std;

void threadFunction(int i){
    cout << "in a seperate thread " << i << "!" << endl;
}

int main(){
    vector<thread> workers;
    
    for (int i = 0; i != 10; ++i){
        workers.push_back(thread(threadFunction&, i));
    }

    /*for (int i = 0; i != 10; ++i){
        workers.push_back(thread([i]() // a closure. a lambda that captures an external variable and makes it a private data of the lambda function object
        {
            cout << "in separate thread from " << i << " is done " << endl;
        }));
    } */
    // While these 10 threads are being generated, 

    cout << "main func" << endl;

    for_each(workers.begin(), workers.end(), [](thread& th)
    {
        th.join();
    });


    return 0;
}