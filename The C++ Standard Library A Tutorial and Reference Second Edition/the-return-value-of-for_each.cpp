// p.511
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class MeanValue{
    private:
        long num;
        long sum;
    public:
        // constructor
        MeanValue() : num(0), sum(0) {}
        
        // function call
        // -process one more elem of the sequence
        void operator() (int elem){
            ++num;
            sum += elem;
        }
        
        // return mean value 
        double value(){
            return static_cast<double>(sum) / static_cast<double>(num);
        }
};

int main()
{
    // for_each has the unique ability to return its func obj
    
    vector<int> coll = {1,2,3,4,5,6,7,8};
    
    MeanValue mv = for_each(coll.begin(), coll.end(), MeanValue());
    cout<< "mean value: "<<mv.value()<<endl;
    return 0;
}
