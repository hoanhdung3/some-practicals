// p.208
#include <iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    multimap<int,string> coll;
    coll = {
        { 5, "tagged" },
        { 2, "a" },
        { 1, "this" },
        { 4, "of" },
        { 6, "strings" },
        { 1, "is" },
        { 3, "multimap" }
    };
    for(auto i : coll) cout<<i.second<<" ";
    return 0;
}
