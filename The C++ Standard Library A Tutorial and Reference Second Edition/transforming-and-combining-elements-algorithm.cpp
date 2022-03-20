// p.592
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<list>
#include<iterator>
#include<functional>

using namespace std;

template<typename T>
inline void INSERT_ELEMENTS(T& coll, int first, int last){
    for(int i = first; i <= last; ++i)
        coll.insert(coll.end(), i);
}

// PRINT_ELEMENTS(): prints all elemes of the container that is passed as the first argument,separated by spaces.
// You can pass a second argument optionally for a string that is used as a prefix in front of the elements
template<typename T>
inline void PRINT_ELEMENTS(const T& coll, const string& optcstr=""){
    cout<<optcstr;
    for(auto elem : coll)
        cout<<elem<<" ";
    cout<<endl;
}

template<typename T>
inline void PRINT_MAPPED_ELEMENTS(const T& coll, const string& optcstr=""){
    cout<<optcstr;
    for(auto elem : coll)
        cout<<'['<<elem.first<<','<<elem.second<<"] ";
    cout<<endl;
}

int main()
{
    // <-- TRANSFORMING ELEMENTS -->
    vector<int> coll1;
    list<int> coll2;
    
    INSERT_ELEMENTS(coll1,1,9);
    PRINT_ELEMENTS(coll1,"coll1:    ");
    
        // negate all elems in coll1
    transform(coll1.cbegin(), coll1.cend(), coll1.begin(), negate<int>());
    PRINT_ELEMENTS(coll1,"negated:  ");
    
        // transform elems of coll1 into coll2 with 10 times their value
    transform(coll1.cbegin(), coll1.cend(), back_inserter(coll2), bind(multiplies<int>(), placeholders::_1, 10));
    PRINT_ELEMENTS(coll2,"coll2:    ");
    
    transform(coll2.crbegin(), coll2.crend(), ostream_iterator<int>(cout," "), [](int elem){
        return -elem;
    });
    cout<<endl;
    
    // <-- COMBINING ELEMENTS OF TWO SEQUENCES -->
    coll1.clear();
    coll2.clear();
    
    INSERT_ELEMENTS(coll1,1,9);
    PRINT_ELEMENTS(coll1,"coll1:    ");
    
    transform(coll1.cbegin(), coll1.cend(), coll1.cbegin(), coll1.begin(), multiplies<int>());
    PRINT_ELEMENTS(coll1,"squared:  ");
    
        // add each elem traversed forward with each elem traversed backward and insert result into coll2
    transform(coll1.cbegin(), coll1.cend(), coll1.crbegin(), back_inserter(coll2), plus<int>());
    PRINT_ELEMENTS(coll2,"coll2:    ");
    
        // print differences of two corresponding elems
    cout<<"diff:    ";
    transform(coll1.cbegin(), coll1.cend(), coll2.cbegin(), ostream_iterator<int>(cout," "), minus<int>());
    cout<<endl;
    return 0;
}
