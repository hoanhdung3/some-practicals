// p.287
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class Account{
    private:
        string name;
        unsigned long nr;
        double state;
    public:
        Account(const string&, unsigned long, double);
        Account(const string&);
        bool init(const string&, unsigned long, double);
        void display();
};

Account::Account(const string& a_name, unsigned long a_nr, double a_state){
    nr = a_nr;
    name = a_name;
    state = a_state;
}

Account::Account(const string& a_name){
    name = a_name;
    nr = 1111111;
    state = 0.0;
}

void Account::display(){
    cout<<fixed<<setprecision(2)
        <<"------------------------------------\n"
        <<"Account holder:      "<<name<<"\n"
        <<"Account number:      "<<nr<<"\n"
        <<"Account state:       "<<state<<"\n"
        <<"------------------------------------\n"
        <<endl;
}

int main(){
    
    Account giro("Cheers, Mary", 1234567, -1200.99), save("Lucky, Luke");
    
    // Account depot;   // ERROR: no default constructor defined
    
    giro.display();
    save.display();
    
    Account temp("Funny, Susy", 7777777, 1000000.0);
    save = temp;
    save.display();
    return 0;
}
