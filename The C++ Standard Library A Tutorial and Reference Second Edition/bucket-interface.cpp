// p.410
#include<iostream>
#include<iomanip>
#include<utility>
#include<typeinfo>
#include<iterator>
#include<unordered_set>
#include<unordered_map>
using namespace std;

// generic output for pairs (map elems)
template<typename T1, typename T2>
ostream& operator << (ostream& strm, const pair<T1,T2>& p){
    return strm << "[" << p.first << "," << p.second << "]";
}

template<typename T>
void PRINT_HASH_TABLE_STATE(const T& cont){
    // basic layout data
    cout<<"size:            "<<cont.size()<<"\n";
    cout<<"buckets:         "<<cont.bucket_count()<<"\n";
    cout<<"load factor:     "<<cont.load_factor()<<"\n";
    cout<<"max load factor: "<<cont.max_load_factor()<<"\n";
    
    // iterator category
    if(typeid(typename iterator_traits<typename T::iterator>::iterator_category)
            == typeid(bidirectional_iterator_tag)){
        cout<<"chaning style: doubly-linked"<<"\n";            
    }
    else
        cout<<"chaning style: singly-linked"<<"\n";
    
    // elems per bucket
    cout<<"data: "<<"\n";
    for(auto idx=0; idx!=cont.bucket_count(); ++idx){
        cout<<" b["<<setw(2)<<idx<<"]: ";
        for(auto pos=cont.begin(idx); pos!=cont.end(idx); ++pos)
            cout<<*pos<<" ";
        cout<<"\n";
    }
    cout<<endl;
}

int main()
{
    unordered_set<int> intset = {1,2,3,5,7,11,13,17,19};
    PRINT_HASH_TABLE_STATE(intset);
    
    intset.insert({-7,17,33,4});
    PRINT_HASH_TABLE_STATE(intset);
    
    unordered_multimap<string,string> dict = {
        {"day","Tag"},
        {"strange","fremd"},
        {"car","Auto"},
        {"smart","elegant"},
        {"trait","Merkmal"},
        {"strange","seltsam"} 
    };
    PRINT_HASH_TABLE_STATE(dict);
    
    dict.insert({
        {"smart","raffiniert"},
        {"smart","klug"},
        {"clever","raffiniert"} 
    });
    PRINT_HASH_TABLE_STATE(dict);
    
    // modify maximum load factor (might cause rehashing)
    dict.max_load_factor(0.7);
    PRINT_HASH_TABLE_STATE(dict);
    return 0;
}
