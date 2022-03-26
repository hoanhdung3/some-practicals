// p.976
#include<iostream>
#include<thread>
#include<chrono>
#include<random>
#include<future>
#include<exception>

using namespace std;

int doSomething(char c){
    // random-number generator (use c as seed to get different sequences)
    default_random_engine dre(c);
    uniform_int_distribution<int> id(10,1000);
    
    // loop to print character after a random period of time
    for(int i=0; i<10; ++i){
        this_thread::sleep_for(chrono::milliseconds(id(dre)));
        cout.put(c).flush();
    }
    return c;
}

int func1(){
    return doSomething('.');
}

int func2(){
    return doSomething('+');
}

int main()
{
    cout<<"starting func1() in background"<<" and func2() in foreground:"<<endl;
    
    //start func1() asynchronously (now or later or never)
    future<int> result1(async(func1));
    
    int result2 = func2(); // call func2() synchronously (here and now)
    
    // print result (wait for func1() to finish and add its result to result2)
    int result = result1.get() + result2;
    
    cout<<"\nresult of func1()+func2(): "<<result<<endl;
    return 0;
}
