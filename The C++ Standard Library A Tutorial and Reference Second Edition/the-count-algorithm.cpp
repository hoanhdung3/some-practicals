// p.553
#include<iostream>
#include<algorithm>
#include<string>
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


int main()
{
    vector<int> coll;
    int num;
    INSERT_ELEMENTS(coll,1,9);
    PRINT_ELEMENTS(coll,"coll: ");
    
    // count elems with value 4
    num = count(coll.cbegin(), coll.cend(), 4);
    cout<<"number of elems equal to 4:      "<<num<<endl;
    
    // count elems with even value
    num = count_if(coll.cbegin(), coll.cend(), [](int elem){
        return elem%2==0;
    });
    cout<<"nummber of elems with even value:    "<<num<<endl;
    
    // count elems that are greater than value 4
    num = count_if(coll.cbegin(), coll.cend(), [](int elem){
        return elem>4;
    });
    cout<<"number of elems greater than 4:  "<<num<<endl;
    return 0;
}
