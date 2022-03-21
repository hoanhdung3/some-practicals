// p.638
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
    // <-- CHECKING WHETHER 1 ELEM IS PRESENT -->
    list<int> coll;
    
    INSERT_ELEMENTS(coll,1,9);
    PRINT_ELEMENTS(coll);
    
    if( binary_search(coll.cbegin(), coll.cend(), 5) )
        cout<<"5 is present"<<endl;
    else
        cout<<"5 is not present"<<endl;
    
    // <-- CHECKING WHETHER SEVERAL ELEMS ARE PRESENT -->
    coll.clear();
    vector<int> search;
    
    INSERT_ELEMENTS(coll,1,9);
    PRINT_ELEMENTS(coll,"coll:  ");
    
    search.push_back(3);
    search.push_back(4);
    search.push_back(7);
    PRINT_ELEMENTS(search,"search:  ");
    
    if( includes(coll.cbegin(), coll.cend(), search.cbegin(), search.cend()) )
        cout<<"all elems of search are also in coll"<<endl;
    else
        cout<<"not all elems of search are also in coll"<<endl;
    return 0;
}
