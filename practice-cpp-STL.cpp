// Based on https://www.youtube.com/watch?v=g-1Cn3ccwXY
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

#define INT_MAX 2147483647

bool f(int x, int y){
    return x>y; // explained: https://www.cplusplus.com/reference/algorithm/sort/
}
void _vector_{ 
    vector<int> v = {4,2,1,6,3};
    
    bool present = binary_search(v.begin(),v.end(),2); cout<<present<<endl;
    present = binary_search(v.begin(),v.end(),7); cout<<present<<endl;
    
    v.push_back(100);
    v.push_back(100);
    v.push_back(100);
    v.push_back(112);
    vector<int>::iterator it = lower_bound(v.begin(),v.end(),100); //give the first >= 100
    //another way--> auto it = lower_bound(v.begin(),v.end(),100);
    vector<int>::iterator it2 = upper_bound(v.begin(),v.end(),100); //give the first > 100
    for(auto i : v) cout<<i<<" ";
    sort(v.begin(),v.end()); // algorithm
    cout<<"\nThe lower bound at the position: "<<(it-v.begin())<<endl;
    cout<<"The upper bound at the position: "<<(it2-v.begin())<<endl;
    
    sort(v.begin(),v.end(),f); // reverse sort
    for(vector<int>::iterator it3 = v.begin(); it3 != v.end();++it3){ // another way to print vector
        cout<<*it3<<" ";
    }
    cout<<endl;
}

void _set_(){
     // set is always maintain the ascending order sequence
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(-1);
    s.insert(-10);
    for(auto i : s) cout<<i<<" ";
    cout<<endl;
    
    set<int>::iterator it = s.find(-1);
    cout<<*it<<endl; // return -1
    set<int>::iterator it2 = s.find(3);
    if(it2 == s.end()){
        cout<<"not present"<<endl; // if find false, return s.end()
    }
    
    set<int>::iterator it3 = s.lower_bound(-1); // return first >= -1
    cout<<*it3<<endl;
    set<int>::iterator it4 = s.upper_bound(2); // return first > 2
    if(it4 == s.end()) cout<<"cant find "<<endl; // if false return end()
}

void _map_(){
    map<int,int> m;
    m[1] = 100;
    m[2] = -1;
    m[3] = 200;
    m[12345] = 0;
    
    map<char,int> dung;
    string s = "hoanhdungdeptrai";
    for(auto i : s){
        dung[i]++; //count how many times the character exist
    }
    cout<<dung['h']<<" "<<dung['a']<<endl;
}

void power_of_stl(){
    set< pair<int,int> > s;
    s.insert({2,3});
    s.insert({10,20});
    s.insert({30,400});
    s.insert({401,450});
    // pair {a,b} is smaller than {c,d} if (a<c) || (a==c && b<d)
    int point = 12;
    set< pair<int,int> >::iterator it = s.upper_bound({point,INT_MAX});
    if(it == s.begin()) cout<<"no";
    it--;
    pair<int,int> current = *it;
    if(current.first <= point && point<=current.second) cout<<"yes";
    else cout<<"no";
}

int main(){
    _vector_();
    _set_();
    _map_();
    power_of_stl();
    return 0;
}
