// p.517
#include<iostream>
#include<functional>

using namespace std;

int main()
{
    auto plus10 = bind(plus<int>(), placeholders::_1, 10);
    // The placeholder_1 represents the first argument passed to the expression as a whole.
    cout<<"+10:     "<<plus10(7)<<endl;
    
    auto plus10times2 = bind(multiplies<int>(), bind(plus<int>(), placeholders::_1,10), 2);
    cout<<"+10 *2:  "<<plus10times2(7)<<endl;
    
    auto pow3 = bind(multiplies<int>(), bind(multiplies<int>(), placeholders::_1, placeholders::_1), placeholders::_1);
    cout<<"x*x*x:   "<<pow3(7)<<endl;
    
    auto inversDivide = bind(divides<double>(), placeholders::_2, placeholders::_1);
    cout<<"invdiv:  "<<inversDivide(49,7)<<endl;
    return 0;
}
