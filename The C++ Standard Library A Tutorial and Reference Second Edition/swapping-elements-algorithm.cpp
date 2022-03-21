// p.596
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>

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
using namespace std;

int main()
{
    vector<int> coll1;
    deque<int> coll2;
    
    INSERT_ELEMENTS(coll1,1,9);
    INSERT_ELEMENTS(coll2,11,23);
    
    PRINT_ELEMENTS(coll1,"coll1:    ");
    PRINT_ELEMENTS(coll2,"coll2:    ");
    
    // swap elems of coll1 with corresponding elems of coll2
    deque<int>::iterator pos = swap_ranges(coll1.begin(), coll1.end(), coll2.begin());
    
    PRINT_ELEMENTS(coll1,"\ncoll1:    ");
    PRINT_ELEMENTS(coll2,"coll2:    ");
    
    if(pos!=coll2.end())
        cout<<"first elem not modified: "<< *pos<<endl;
    
    // mirror first 3 with last 3 elems in coll2
    swap_ranges(coll2.begin(), coll2.begin()+3, coll2.rbegin());
    PRINT_ELEMENTS(coll2,"\ncoll2:    ");
    return 0;
}
