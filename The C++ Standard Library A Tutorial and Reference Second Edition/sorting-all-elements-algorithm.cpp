// p.626
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

bool lessLength(const string& s1, const string& s2){
    return s1.length() < s2.length();
}

int main()
{
    vector<string> coll1 = {"1xxx", "2x", "3x", "4x", "5xx", "6xxxx", "7xx", "8xxx",
                            "9xx", "10xxx", "11", "12", "13", "14xx", "15", "16", "17"
    };
    vector<string> coll2(coll1);
    PRINT_ELEMENTS(coll1,"on entry:\n ");
    
    sort(coll1.begin(), coll1.end(), lessLength);
    stable_sort(coll2.begin(), coll2.end(), lessLength);
    
    PRINT_ELEMENTS(coll1,"\nwith sort():\n ");
    PRINT_ELEMENTS(coll2,"\nwith stable_sort():\n ");
    return 0;
}
