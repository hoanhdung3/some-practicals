// p.211
#include <iostream>
#include<unordered_set>
#include<string>
using namespace std;

int main()
{
    unordered_multiset<string> cities{
        "Braunshweig", "Hanover", "Frankfurt", "New Youk", "Chicago", "Toronto", "Paris", "Frankfurt"
    };
    for(const auto &i : cities) cout<<i<<" ";
    cout<<endl;

    cities.insert({"London", "Munich", "Hanover", "Braunshweig"});
    for(const auto &i : cities) cout<<i<<" ";
    cout<<endl;
    return 0;
    return 0;
}
