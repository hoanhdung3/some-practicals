// p.308
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int count = 0;

class Article{
    private:
        long nr;
        string name;
        double price;
    public:
        Article(long nr=0, const string& name="noname", double price=0.0);
        ~Article();
        void print();
        const string& getName() const{
            return name;
        }
        long getNumber() const{
            return nr;
        }
        double getPrice() const{
            return price;
        }
        bool setName(const string& s){
            if(s.size()<1)
                return false;
            name = s;
            return true;
        }
        void setNr(long n){
            nr = n;
        }
        void setPrice(double v){
            price = v>0 ? v : 0.0;
        }
};

Article::Article(long nr, const string& name, double price){
    setNr(nr);
    setName(name);
    setPrice(price);
    ++count;
    cout<<"An object"<<name<<"of type Article is created.\nThis is the "<<count<<" Article\n"<<endl;
}

Article::~Article(){
    cout<<"An object"<<name<<"of type Article is destroyed.\nThere are still the "<<--count<<" Article\n"<<endl;
}

void Article::print(){
    // To mark the flags of cout
    cout<<fixed<<setprecision(2)
        <<"------------------------------------\n"
        <<"Article data:\n"
        <<" Number ....:    "<<nr<<"\n"
        <<" Name   ....:    "<<name<<"\n"
        <<" Sales price:    "<<price<<"\n"
        <<"------------------------------------\n";
           // To restore old flags 
    cout<<" ---Go on with return --- ";
    cin.get();
}

void test(){
    Article shirt(3333,"T-Shirt", 29.9);
    shirt.print();
    static Article net(4444, "volley ball net", 99.0);
    net.print();
    cout<<"\nLast statement in function test()"<<endl;
}

Article Article1(1111,"volley ball", 59.9);

int main()
{
    cout<<"The first statement in main() .\n"<<endl;
    Article Article2(2222, "gym-shoes", 199.99);
    Article1.print();
    Article2.print();
    Article shoes = Article2;   // another name 
    shoes.setNr(2233);
    shoes.setName("jogging-shoes");
    shoes.setPrice(shoes.getPrice() - 50.0);
    
    cout<<"\nThe new values of the shoes object: \n";
    shoes.print();
    cout<<"\nThe first ca;; to test() ."<<endl;
    test();
    cout<<"\nThe 2nd call to test() ."<<endl;
    test();
    return 0;
}
