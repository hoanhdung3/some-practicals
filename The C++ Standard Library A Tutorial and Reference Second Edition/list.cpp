// p.327
#include<iostream>
#include<list>
#include<algorithm>
#include<iterator>
using namespace std;

void PRINT_LISTS(const list<int>& l1, const list<int>& l2){
    cout<<"list1: ";
    copy(l1.cbegin(), l1.cend(), ostream_iterator<int>(cout," "));
    cout<<endl;
    
    cout<<"list2: ";
    copy(l2.cbegin(), l2.cend(), ostream_iterator<int>(cout," "));
    cout<<endl;
}

int main()
{
    list<int> l1, l2;
    for(int i=0;i<=6;++i){
        l1.push_back(i);
        l2.push_front(i);
    }
    PRINT_LISTS(l1,l2);
    
    // insert all elems of l1 before the first elem with value 3 of l2
    // find() returns an iterator to the first elem with value 3
    l2.splice(find(l2.begin(), l2.end(), 3), l1);
    PRINT_LISTS(l1,l2);
    
    // move first elem of l2 to the end
    l2.splice(l2.end(), //destination
                l2,  // source list
                l2.begin()); // source position
    PRINT_LISTS(l1,l2);
    
    // sort second list, assign to l1 and remove duplicates
    l2.sort();
    l1 = l2;
    l2.unique();
    PRINT_LISTS(l1,l2);
    
    // merge both sorted lists into the first list
    l1.merge(l2);
    PRINT_LISTS(l1,l2);
    return 0;
}
