// p.937
#include<iostream>
#include<random>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    // create default engine as source of randomness
    default_random_engine dre;
    
    // use engine to generate integral numbers between 10 and 20
    uniform_int_distribution<int> di(10,20);
    for(int i=0; i<20; ++i)
        cout<<di(dre)<<" ";
    cout<<endl;
    
    // use engine to generate floating-point numbers between 10.0 and 20.0 (20.0 not included)
    uniform_real_distribution<double> dr(10,20);
    for(int i=0; i<8; ++i)
        cout<<dr(dre)<<" ";
    cout<<endl;
    
    // use engine to shuffle elems
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    shuffle(v.begin(), v.end(), dre);
    for(int i=0; i<v.size(); ++i)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}
