// p.524
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iterator>
#include<functional>

using namespace std;

template<typename T1, typename T2>
struct fopow{
    T1 operator() (T1 base, T2 exp) const{
        return std::pow(base,exp);
    }  
};

int main()
{
    vector<int> coll = {1,2,3,4,5,6,7,8,9};
    
    // print 3 raised to the power of all elems
    transform(coll.begin(), coll.end(),  // source
                ostream_iterator<float>(cout," "),  // destination
                bind(fopow<float,int>(), 3, placeholders::_1)); // operation
    cout<<endl;
    
    // print all elems raised to the power of 3 
    transform(coll.begin(), coll.end(),
                ostream_iterator<float>(cout," "),
                bind(fopow<float,int>(), placeholders::_1, 3));
    cout<<endl;
    return 0;
}
