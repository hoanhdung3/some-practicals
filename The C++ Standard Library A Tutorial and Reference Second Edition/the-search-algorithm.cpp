// p.560
#include<iostream>
#include<algorithm>
#include<string>
#include<deque>
#include<iterator>
#include<functional>
#include<list>
#include<vector>

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

bool checkEven(int elem, bool even){
    if(even) return elem%2==0;
    else return elem%2==1;
}

int main()
{
    deque<int> coll;
    
    coll = {1,2,7,7,6,3,9,5,7,7,7,3,6};
    PRINT_ELEMENTS(coll);
    
    // find three consecutive elems with value 7
    deque<int>::iterator pos;
    pos = search_n(coll.begin(), coll.end(), 3, 7);
    
    if(pos != coll.end()){
        cout<<"three consecutive elems with value 7 start with "<<distance(coll.begin(), pos) +1<<". element"<<endl;
    }
    else
        cout<<"no four consecutive elems woth value 7 found"<<endl;
    
    // find 4 consecutive odd elems
    pos = search_n(coll.begin(), coll.end(), 4, 0, [](int elem, int value){
        return elem%2==1;
    });
    
    if(pos != coll.end()){
        cout<<"first 4 consecutive odd elems are: ";
        for(int i=0;i<4;++i,++pos)
            cout<<*pos<<" ";
    }
    else
        cout<<"no 4 consecutive elems with value > 3 found";
    cout<<endl;
    
    coll.clear();
    list<int> subcoll;
    
    INSERT_ELEMENTS(coll,1,7);
    INSERT_ELEMENTS(coll,1,7);
    INSERT_ELEMENTS(subcoll,3,6);
    
    PRINT_ELEMENTS(coll,"coll:      ");
    PRINT_ELEMENTS(subcoll,"subcoll:    ");
    
    // search first occurrence of subcoll in coll
    pos = search(coll.begin(), coll.end(), subcoll.begin(), subcoll.end());
    
    // loop while subcoll found as subrange of coll
    while(pos != coll.end()){
        cout<<"subcoll found starting with elem "<<distance(coll.begin(), pos) +1<<endl;
        
        // search next occurrence of subcoll
        ++pos;
        pos = search(pos, coll.end(), subcoll.begin(), subcoll.end());
    }
    
    vector<int> v;
    INSERT_ELEMENTS(v,1,9);
    PRINT_ELEMENTS(v,"v:    ");
    
    bool checkEvenArgs[3] = {true, false, true};
    
    vector<int>::iterator pos_v;
    pos_v = search(v.begin(), v.end(), checkEvenArgs, checkEvenArgs+3, checkEven);
    
    // loop while subrange found
    while(pos_v != v.end()){
        cout<<"subrange found starting with elem "<< distance(v.begin(), pos_v) + 1<<endl;
        
        // search next subrange in v 
        pos_v = search(++pos_v, v.end(), checkEvenArgs, checkEvenArgs+3,checkEven);
    }
    
    return 0;
}
