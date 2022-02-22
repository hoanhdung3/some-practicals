// p.213
#include <iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main()
{
    unordered_map<string,double> coll{
        { "tim", 9.9 },
        { "struppi", 11.77 }
    };
    
    // use const string to not modify the key member first in the element
    for(pair<const string,double> &i : coll) i.second *= i.second;
    
    for(const auto &i : coll) cout<<i.first<<": "<<i.second<<endl;
    return 0;
}
