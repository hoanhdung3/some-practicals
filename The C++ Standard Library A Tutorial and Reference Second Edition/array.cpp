// p.298

#include<iostream>
#include<array>
#include<algorithm>
#include<numeric>
#include<functional>
#include<iterator>
using namespace std;

void PRINT_ELEMENT(array<int,10> a){
    copy(a.cbegin(), a.cend(), ostream_iterator<int>(cout," "));
    cout<<endl;
}

int main()
{
    array<int,10> a = {11,22,33,44};
    PRINT_ELEMENT(a);
    a.back() = 9999999;
    a[a.size()-2] = 42;
    PRINT_ELEMENT(a);
    
    cout<<"sum: "<< accumulate(a.begin(), a.end(), 0)<<endl;
    
    transform(a.begin(), a.end(), // source
                a.begin(),  // destination
                negate<int>() ); // operation
    PRINT_ELEMENT(a);
    return 0;
}
