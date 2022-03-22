// p.711
#include<iostream>
#include<string>
#include<limits>
#include<exception>

using namespace std;

int main()
{
    try{
        cout<<stoi("  77")<<endl;
        cout<<stod("  77.7")<<endl;
        cout<<stoi("-0x77")<<endl;
        
        // use index of characters not processed
        std::size_t idx;
        cout<<stoi("  42 is the truth", &idx)<<endl;
        cout<<" idx of 1st unprocessed char: "<<idx<<endl;
        
        // use bases 16 and 8
        cout<<stoi(  "42", nullptr, 16)<<endl;
        cout<<stol("789", &idx, 8)<<endl;
        cout<<" idx of 1st unprocessed char: "<<idx<<endl;
        
        // convert numeric value to string
        long long ll = numeric_limits<long long>::max();
        string s = to_string(ll);
        cout<<s<<endl;
        
        // try to convert back
        cout<<stoi(s)<<endl; // throws out_of_range
    }
    catch(const exception& e){
        cout<<e.what()<<endl;
    }
    return 0;
}
