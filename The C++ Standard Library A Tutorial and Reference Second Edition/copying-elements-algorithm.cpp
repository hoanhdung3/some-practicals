// p.580
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
    
        // copy elems of coll1 into coll2 in reverse order
        // -noew overwritting
    cout<<endl;
    
    copy(coll1.crbegin(), coll1.crend(), coll2.begin());
    copy(coll2.cbegin(), coll2.cend(), ostream_iterator<string>(cout," "));
    cout<<endl;
    
        // initialize source collection with "........abcdef.........."
    vector<char> source(10,'.');
    for(int c='a'; c<='f'; c++)
        source.push_back(c);
    source.insert(source.end(),10,'.');
    PRINT_ELEMENTS(source,"source: ");
    
        // copy all letters three elems in front of the 'a'
    vector<char> c1(source.cbegin(), source.cend());
    copy(c1.cbegin()+10, c1.cbegin()+16, c1.begin()+7);
    PRINT_ELEMENTS(c1,"c1: ");
    
        // copy all letters three elems in behind of the 'f'
    vector<char> c2(source.cbegin(), source.cend());
    copy_backward(c2.cbegin()+10, c2.cbegin()+16, c2.begin()+19);
    PRINT_ELEMENTS(c2,"c2: ");
    return 0;
}
