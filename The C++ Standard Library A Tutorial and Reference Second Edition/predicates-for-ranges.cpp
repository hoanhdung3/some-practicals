// p.580
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<list>
#include<map>

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
    // <-- CHECK FOR (PARTIAL) SORTING -->
    vector<int> coll1 = {1,1,2,3,4,5,6,7,8,9};
    PRINT_ELEMENTS(coll1,"coll1:    ");
    
    (is_sorted(coll1.begin(), coll1.end())) ? cout<<"coll1 is sorted"<<endl : cout<<"coll1 is not sorted"<<endl;
    
    map<int,string> coll2;
    coll2 = { {1,"Bill"}, {2,"Jim"}, {3,"Nico"}, {4,"Liu"}, {5,"Ai"} };
    PRINT_MAPPED_ELEMENTS(coll2,"coll2:     ");
    
        // define predicate to compare names 
    auto compareName = [](const pair<int,string>& e1, const pair<int,string>& e2){
        return e1.second < e2.second;
    };
    
    (is_sorted(coll2.cbegin(), coll2.cend(), compareName)) ? cout<<"names in coll2 is sorted"<<endl : cout<<"names in coll2 is not sorted"<<endl;
    
    auto pos = is_sorted_until(coll2.cbegin(), coll2.cend(), compareName);
    if(pos!=coll2.end())
        cout<<"first unsorted name: "<<pos->second<<endl;
        
    // <<- CHECK FOR BEING PARTITIONED -->
    vector<int> coll = {5,3,9,1,3,4,8,2,6};
    PRINT_ELEMENTS(coll,"coll:  ");
    
        // define predicate: check whether elem is odd
    auto isOdd = [](int elem){
        return elem%2==1;
    };
    
        // check whether coll is partitioned in odd and even elems 
    if( is_partitioned(coll.cbegin(), coll.cend(), isOdd) ){
        cout<<"coll is partitioned"<<endl;
        auto pos = partition_point(coll.cbegin(), coll.cend(), isOdd);
        cout<<"first even elem: "<< *pos <<endl;
    }
    else
        cout<<"coll is not partitioned"<<endl;
    
    // <-- CHECK FOR BEING A HEAP (MAXIMUM ELEM FIRST) -->
    coll1.clear();
    vector<int> coll3 = {5,3,2,1,4,7,9,8,6};
    coll1 = {9,8,7,7,7,5,4,2,1};
    
    PRINT_ELEMENTS(coll1,"coll1:    ");
    PRINT_ELEMENTS(coll3,"coll3:    ");
    
        // check whether the collections are heaps
    cout<<boolalpha<<"coll1 is heap: "<<is_heap(coll1.cbegin(), coll1.cend())<<endl;
    cout<<"coll3 is heap: "<<is_heap(coll3.cbegin(), coll3.cend())<<endl;
    
    auto pos1 = is_heap_until(coll3.cbegin(), coll3.cend());
    if(pos1!=coll3.end())
        cout<<"first non-heap element: "<< *pos1<<endl;
        
    // <-- ALL, ANY OR NONE -->
    coll.clear();
    vector<int>::iterator pos_v;
    
    INSERT_ELEMENTS(coll,1,9);
    PRINT_ELEMENTS(coll,"coll:  ");
    
        // define an object for the predicate
    auto isEven = [](int elem){
        return elem%2==0;
    };
    
        // print whether all, any or none of the elems are/is even
    cout<<boolalpha<<"all even?: "<< all_of(coll.cbegin(), coll.cend(), isEven)<<endl;
    cout<<"any even?: "<< any_of(coll.cbegin(), coll.cend(), isEven)<<endl;
    cout<<"none even?: "<<none_of(coll.cbegin(), coll.cend(), isEven)<<endl;
    return 0;
}
