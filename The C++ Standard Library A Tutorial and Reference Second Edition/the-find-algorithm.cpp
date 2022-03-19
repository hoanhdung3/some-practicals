// p.555
#include<iostream>
#include<algorithm>
#include<string>
#include<list>
#include<iterator>
#include<functional>
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

bool absLess(int elem1, int elem2){
    return abs(elem1) < abs(elem2);
}

int main()
{
    list<int> coll;
    INSERT_ELEMENTS(coll,1,9);
    INSERT_ELEMENTS(coll,1,9);
    
    PRINT_ELEMENTS(coll,"coll:  ");
    
    list<int>::iterator pos1;
    pos1 = find(coll.begin(), coll.end(), 4);
    
    // find 2nd elem with value 4, continue the search behind the first 4
    list<int>::iterator pos2;
    if(pos1 != coll.end()){
        pos2 = find(++pos1, coll.end(), 4);
    }
    
    // print all elems from 1st to 2nd 4
    if(pos1!=coll.end() && pos2!=coll.end()){
        copy(--pos1, ++pos2, ostream_iterator<int>(cout," "));
        cout<<endl;
    }
    
    vector<int> v;
    vector<int>::iterator pos;
    
    INSERT_ELEMENTS(v,1,9);
    PRINT_ELEMENTS(v, "v: ");
    
    pos = find_if(v.begin(), v.end(), bind(greater<int>(), placeholders::_1, 3));
    cout<<"the "<<distance(v.begin(), pos) +1<<". elem is the first greater than 3"<<endl;
    
    pos = find_if(v.begin(), v.end(), [](int elem){
        return elem%3==0;
    });
    
    cout<<"the "<<distance(v.begin(), pos)+1<<". element is the first divisible by 3"<<endl;
    
    pos = find_if_not(v.begin(), v.end(), bind(less<int>(), placeholders::_1, 5));
    cout<<"first value >=5: "<<*pos<<endl;
    
    return 0;
}
