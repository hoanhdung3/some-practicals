// p.253
#include<iostream>
#include<list>
#include<algorithm>
#include<cstdlib> // for abs()

using namespace std;

// predicate, which returns whether an integer is a prime number
bool isPrime(int n){
    n = abs(n);
    if(n==0 || n==1) return false; // 0 and 1 are no prime numbers
    // find divisor that divides without a remainder
    int divisor;
    for(divisor = n/2; n%divisor!=0; --divisor){
        ;
    }
    // if no divisor greater than 1 is found, it is a prime number
    return divisor ==1;
}

int main()
{
    list<int> coll;
    for(int i=24;i<=30;++i) coll.push_back(i);
    
    // search for prime number
    auto pos = find_if(coll.cbegin(), coll.cend(), // range
                        isPrime);  // predicate
    if(pos!=coll.end())
        cout<<*pos<<" is first prime number found"<<endl;
    else
        cout<<"No prime number found"<<endl;
    return 0;
}
