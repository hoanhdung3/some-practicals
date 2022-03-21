// p.635
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
#include<iterator>

using namespace std;

template<typename T>
inline void INSERT_ELEMENTS(T& coll, int first, int last){
    for(int i = first; i <= last; ++i)
        coll.insert(coll.end(), i);
}

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


int main()
{
    vector<int> coll;
    
    INSERT_ELEMENTS(coll,3,7);
    INSERT_ELEMENTS(coll,5,9);
    INSERT_ELEMENTS(coll,1,4);
    
    PRINT_ELEMENTS(coll, "on entry:     ");
    
    // convert coll into a heap
    make_heap(coll.begin(), coll.end());
    PRINT_ELEMENTS(coll,"after make_heap(): ");
    
    pop_heap(coll.begin(), coll.end());
    coll.pop_back();
    PRINT_ELEMENTS(coll,"after pop_heap():  ");
    
    coll.push_back(17);
    push_heap(coll.begin(), coll.end());
    PRINT_ELEMENTS(coll,"after push_heap(): ");
    
    // convert heap into a sorted coll. After the call it is no longer a heap 
    sort_heap(coll.begin(), coll.end());
    PRINT_ELEMENTS(coll,"after sort_heap(): ");
    
    return 0;
}
