// p.555
#include<iostream>
#include<algorithm>
#include<string>
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

bool absLess(int elem1, int elem2){
    return abs(elem1) < abs(elem2);
}

int main()
{
    deque<int> coll;
    
    INSERT_ELEMENTS(coll,2,6);
    INSERT_ELEMENTS(coll,-3,6);
    
    PRINT_ELEMENTS(coll);
    
    cout<<"minimum: "<< *min_element(coll.cbegin(), coll.cend())<<endl;
    cout<<"maximum: "<< *max_element(coll.cbegin(), coll.cend())<<endl;
    
    auto mm = minmax_element(coll.cbegin(), coll.cend());
    cout<<"min: "<< *(mm.first)<<endl;
    cout<<"max: "<< *(mm.second)<<endl;
    cout<<"distance: "<< distance(mm.first, mm.second)<<endl;
    
    // process and print minimum and maximum of abs values
    cout<<"minimum of absolute values: "<< *min_element(coll.cbegin(), coll.cend(), absLess)<<endl;
    cout<<"maximum of absolute values: "<< *max_element(coll.cbegin(), coll.cend(), absLess)<<endl;
    return 0;
}
