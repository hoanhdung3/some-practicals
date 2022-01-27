// p.174
#include<iostream>
#include<chrono>
#include<ratio>
using namespace std;

int main(){
    chrono::duration<int> twenty_seconds(20);
    chrono::duration<double,ratio<60>> half_minute(0.5);
    chrono::duration<long,ratio<1,1000>> one_millisecond(1);
    cout<<twenty_seconds.count()<<" "<<half_minute.count()<<" "<<one_millisecond.count()<<endl;
    
    chrono::seconds d1(42);
    chrono::milliseconds d2(10);
    auto a = d1-d2;
    cout<<a.count()<<endl;
    
    chrono::duration<int,ratio<1,3>> d3(1);
    chrono::duration<int,ratio<1,5>> d4(1);
    auto b = d3+d4;
    cout<<b.count()<<endl; // yields 8 ticks of 1/15 second
    
    chrono::hours a_day(24);
    chrono::milliseconds ms; // 0 milliseconds
    ms += twenty_seconds + a_day;
    --ms;
    ms *=2;
    cout<<ms.count() << " ms" <<endl;
    cout<<chrono::nanoseconds(ms).count()<< " ns"<<endl;
    return 0;
}
