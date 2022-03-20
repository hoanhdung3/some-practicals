// p.572
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<list>
#include<deque>

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
        cout<<'['<<elem.first<<','<<"] ";
    cout<<endl;
}

bool bothEvenOrOdd(int elem1, int elem2){
    return elem1%2==elem2%2;
}

void printCollection(const list<int>& l){
    PRINT_ELEMENTS(l);
}

bool lessForCollection(const list<int>& l1, const list<int>& l2){
    return lexicographical_compare(l1.cbegin(), l1.cend(), l2.cbegin(), l2.cend());
}

int main()
{
    // <-- TESTING EQUALITY -->
    vector<int> coll1;
    list<int> coll2;
    
    INSERT_ELEMENTS(coll1,1,7);
    INSERT_ELEMENTS(coll2,3,9);
    
    PRINT_ELEMENTS(coll1,"coll1:    ");
    PRINT_ELEMENTS(coll2,"coll2:    ");
    
    if( equal(coll1.begin(), coll1.end(), coll2.begin()) )
        cout<<"coll1 == coll2"<<endl;
    else
        cout<<"coll1 != coll2"<<endl;
    
        // check for corresponding even and odd elems 
    if( equal(coll1.begin(), coll1.end(), coll2.begin(), bothEvenOrOdd) )
        cout<<"even and odd elems correspond"<<endl;
    else
        cout<<"even and odd elems do not correspond"<<endl;
    
    // <--TESTING FOR UNORDERED EQUALITY -->
    coll1.clear();
    coll2.clear();
    deque<int> coll3;
    
    coll1 = {1,1,2,3,4,5,6,7,8,9};
    coll2 = {1,9,8,7,6,5,4,3,2,1};
    coll3 = {11,12,13,19,18,17,16,15,14,11};
    
    PRINT_ELEMENTS(coll1,"coll1:    ");
    PRINT_ELEMENTS(coll2,"coll2:    ");
    PRINT_ELEMENTS(coll3,"coll3:    ");
    
        // check whether both collections have equal elems in any order
    if( is_permutation(coll1.cbegin(), coll1.cend(), coll2.cbegin()) )
        cout<<"coll1 and coll2 have equal elems"<<endl;
    else
        cout<<"coll1 and coll2 don't have equal elems"<<endl;
    
        // check for corresponding number of even and odd elems 
    if( is_permutation(coll1.cbegin(), coll1.cend(), coll3.cbegin(), bothEvenOrOdd) )
        cout<<"numbers of even and odd elems match"<<endl;
    else
        cout<<"numbers of even and odd elems don't match"<<endl;

    // <-- SEARCH THE FIRST DIFFERENCE -->
    coll1.clear();
    coll2.clear();
    
    coll1 = {1,2,3,4,5,6};
    coll2 = {1,2,4,8,16,3};
    
    PRINT_ELEMENTS(coll1,"coll1:    ");
    PRINT_ELEMENTS(coll2,"coll2:    ");
    
        // find first mismatch
    auto values = mismatch(coll1.cbegin(), coll1.cend(), coll2.cbegin());
    if(values.first == coll1.end())
        cout<<"no mismatch"<<endl;
    else
        cout<<"first mismatch: "<< *values.first<<" and "<< *values.second<<endl;
        
        // find first position where the elem of coll1 is not less than the corresponding elem of coll2
    values = mismatch(coll1.cbegin(), coll1.cend(), coll2.cbegin(), less_equal<int>());
    if(values.first == coll1.end())
        cout<<"always less or equal"<<endl;
    else
        cout<<"not less or equal: "<< *values.first<<" and "<< *values.second<<endl;
        
    // <-- TESTING FOR "LESS THAN" -->
    list<int> c1,c2,c3,c4;
    INSERT_ELEMENTS(c1,1,5);
    c4 = c3 = c2 = c1;
    
    c1.push_back(7);
    c2.push_back(2);
    c3.push_back(0);
    c4.push_back(2);
    
    vector<list<int>> cc;
    cc.insert(cc.begin(), {c1,c2,c3,c4,c3,c1,c4,c2});
    
    for_each(cc.cbegin(), cc.cend(), printCollection);
    cout<<endl;
    
    sort(cc.begin(), cc.end(), lessForCollection);
    
    for_each(cc.cbegin(), cc.cend(), printCollection);
    cout<<endl;
    return 0;
}
