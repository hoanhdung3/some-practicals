// p.291
#include<iostream>
#include<string>

using namespace std;

int count = 0;          // Number of objects
class Demo{
    private:
        string name;
    public:
        Demo(const string& );
        ~Demo();
};
Demo::Demo(const string& str){
    ++count;
    name = str;
    cout<<"I am the constructor of "<<name<<"\n"<<"This is the "<<count<<". object!\n";
}

Demo::~Demo(){
    cout<<"I am the destructor of "<<name<<"\n"<<"The "<<count<<". object will be destroyed"<<endl;
    --count;
}

Demo globalObject("the global object");

int main(){
    
    cout<<"The 1st statement and destroy in main() ."<<endl;
    Demo firstLocalObject("the 1. local object");
    {
        Demo secLocalObject("the static object");
        static Demo staticObject("the static object");
        cout<<"\nLast statement within the inner block"<<endl;
    }
    cout<<"Last statement in main() ."<<endl;
    return 0;
}
