// p.207
#include <iostream>
#include<set>
#include<string>
using namespace std;

int main()
{
    multiset<string> cities{
        "Braunshweig", "Hanover", "Frankfurt", "New Youk", "Chicago", "Toronto", "Paris", "Frankfurt"
    };
    for(const auto &i : cities) cout<<i<<" ";
    cout<<endl;
    // derive the type of the elements from the container 
    // and avoid having to create a copy for each element the body of the loop is called for.
    cities.insert({"London", "Munich", "Hanover", "Braunshweig"});
    for(const auto &i : cities) cout<<i<<" ";
    cout<<endl;
    return 0;
}
// set: not allowed duplicates
// multiset: allowed duplicates
