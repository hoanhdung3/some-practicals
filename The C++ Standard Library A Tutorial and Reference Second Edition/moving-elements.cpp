// p.591
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<list>
#include<iterator>

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
    vector<string> coll1 = {"Hello", "this", "is", "an", "example"};
    list<string> coll2;
    
    copy(coll1.cbegin(), coll1.cend(), back_inserter(coll2));
    
        // copy elems to cout using an ostream iterator
    copy(coll2.cbegin(), coll2.cend(), ostream_iterator<string>(cout," "));
    cout<<endl;
    
        // copy elems of coll1 into coll2 in reverse order
        // -now overwritting (coll2.size() still fits)
        // -use move() because these elems in coll1 are not used again
    move(coll1.crbegin(), coll1.crend(), coll2.begin());
    
        // use move() because the elems in coll2 are not used again
    move(coll2.cbegin(), coll2.cend(), ostream_iterator<string>(cout," "));
    cout<<endl;
    return 0;
}
