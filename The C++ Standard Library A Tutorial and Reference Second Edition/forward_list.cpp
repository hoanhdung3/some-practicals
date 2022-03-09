// p.341
#include<iostream>
#include<forward_list>
#include<algorithm>
#include<iterator>
#include<string>
using namespace std;

void PRINT_LISTS(const string& s, const forward_list<int>& l1, const forward_list<int>& l2){
    cout<<s<<endl;
    cout<<"list1: ";
    copy(l1.cbegin(), l1.cend(), ostream_iterator<int>(cout," "));
    cout<<endl<<"list2: ";
    copy(l2.cbegin(), l2.cend(), ostream_iterator<int>(cout," "));
    cout<<endl;
}

int main()
{
    forward_list<int> l1 = {1,2,3,4};
    forward_list<int> l2 = {77,88,99};
    
    l2.insert_after(l2.before_begin(), 99);
    l2.push_front(10);
    l2.insert_after(l2.before_begin(), {10,11,12,13});
    PRINT_LISTS("6 new elems: ",l1,l2);
    
    l1.insert_after(l1.before_begin(), l2.begin(), l2.end());
    PRINT_LISTS("l2 into l1: ",l1, l2);
    
    //delete second elem and elems after elem with value 99
    l2.erase_after(l2.begin());
    l2.erase_after(find(l2.begin(), l2.end(), 99), l2.end());
    PRINT_LISTS("delete 2nd and after 99: ",l1,l2);
    
    l1.sort();
    l2 = l1;
    l2.unique();
    PRINT_LISTS("sorted and unique: ",l1,l2);
    
    l1.merge(l2);
    PRINT_LISTS("merge: ",l1,l2);
    return 0;
}
