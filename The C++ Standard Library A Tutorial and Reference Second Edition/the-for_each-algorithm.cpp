// p.548
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

template<typename T>
inline void INSERT_ELEMENTS(T& coll, int first, int last){
    for(int i = first; i <= last; ++i)
        coll.insert(coll.end(), i);
}


// PRINT_ELEMENTS(): prints all elemes of the container that is passed as the first argument,separated by spaces.
// You can pass a second argument optionally for a string that is used as a prefix in front of the elements
template<typename T>
inline void PRINT_ELEMENTS(const T& coll, const string& optcstr=""){
    cout<<optcstr;
    for(auto elem : coll)
        cout<<elem<<" ";
    cout<<endl;
}

template<typename T>
inline void PRINT_MAPPED_ELEMENTS(const T& coll, const string& optcstr=""){
    cout<<optcstr;
    for(auto elem : coll)
        cout<<'['<<elem.first<<','<<"] ";
    cout<<endl;
}

// func obj that adds the value with it is initialized
template<typename T>
class AddValue{
    private:
        T theValue;
    public:
        // constructor initializes the value to add 
        AddValue(const T& v) : theValue(v){}
        // the func call for the elem adds the value 
        void operator() (T& elem) const{
            elem += theValue;
        }
};

// func obj to process the mean value 
class MeanValue{
    private:
        long num;
        long sum;
    public:
        // constructor
        MeanValue () : num(0), sum(0){}
        
        // process one more elem of the sequence
        void operator() (int elem){
            num++;
            sum+=elem;
        }
        
        // return mean value (implicit type conversion)
        operator double(){
            return static_cast<double>(sum) / static_cast<double>(num);
        }
};

int main()
{
    vector<int> coll;
    INSERT_ELEMENTS(coll,1,9);
    
    for_each(coll.cbegin(), coll.cend(), [](int elem){
                                            cout<<elem<<" "; 
                                            });
    cout<<endl;
    
    for_each(coll.begin(), coll.end(), [](int& elem){
        elem+=10;
    });
    PRINT_ELEMENTS(coll);
    
    // add value of first elem to each elem 
    for_each(coll.begin(), coll.end(), [=](int& elem){ // define the capture [=] to be able to add a copy of the first elem
        elem += *coll.begin();
    });
    PRINT_ELEMENTS(coll);
    
    
    for_each(coll.begin(), coll.end(), AddValue<int>(10));
    PRINT_ELEMENTS(coll);
    
    for_each(coll.begin(), coll.end(), AddValue<int>(*coll.begin()));
    PRINT_ELEMENTS(coll);
    
    coll.clear();
    INSERT_ELEMENTS(coll,1,8);
    
    double mv = for_each(coll.begin(), coll.end(), MeanValue());
    cout<<"mean value: "<<mv<<endl;
    
    return 0;
}
