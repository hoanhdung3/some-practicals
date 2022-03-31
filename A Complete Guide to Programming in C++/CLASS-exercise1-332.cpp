// p.332
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class Article{
    private:
        long nr;
        string name;
        double sp;
        static int countObj;
    public:
        Article(long nr = 0, const string& name = "noname", double sp = 0.0);
        Article(const Article& anArticle);
        ~Article();
        void print();
        
        // Access methods:
        const string& getName() const {return name;}
        long getNr() const {return nr;}
        double getSp() const {return sp;}
        static int getCount() {return countObj;}
        bool setName(const string& s){
            if(s.size() < 1)
                return false;
            name = s;
            return true;
        }
        void setNr(long n){
            nr = n;
        }
        void setSp(double v){
            sp = v > 0.0 ? v : 0.0;
        }
};

int Article::countObj = 0;

Article::Article(long nr, const string& name, double sp){
    setNr(nr);
    setName(name);
    setSp(sp);
    ++countObj;
    cout<<"An Article \""<<name<<"\" is created.\n"<<"This is the "<<countObj<<". Article!"<<endl;
}

Article::Article(const Article& art) : nr(art.nr), name(art.name), sp(art.sp){
    ++countObj;
    cout<<"A copy pf the Article \""<<name<<"\" is generated.\n"<<"This is the "<<countObj<<". Article!"<<endl;
}

Article::~Article(){
    cout<<"The Article \""<<name<<"\" is destroyed.\n"<<"There are still "<< --countObj<<" Article!"<<endl;
}

void Article::print(){
    cout<<fixed<<setprecision(2)
        <<"------------------------------------\n"
        <<"Article data:\n"
        <<" Number ....:    "<<nr<<"\n"
        <<" Name   ....:    "<<name<<"\n"
        <<" Sales price:    "<<sp<<"\n"
        <<"------------------------------------\n";
}

void test(Article a);

Article article1(1111, "tent", 159.9);

int main()
{
    Article article2(2222, "jogging shoes", 199.99);
    test(article1);
    test(article2);
    cout<<"\nThere are still "<<Article::getCount()<<"object!"<<endl;
    return 0;
}

void test(Article a){
    cout<<"\nThe given object:"<<endl;
    a.print();
    
    static Article bike(3333, "bicycle", 999.0);
    cout<<"\nThe static object in func test():"<<endl;
    bike.print();
}
