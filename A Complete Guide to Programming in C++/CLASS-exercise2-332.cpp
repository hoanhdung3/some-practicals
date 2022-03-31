// p.332
#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include<ctime>
using namespace std;

class Date{
    private:
        short m, d, y;
    public:
        Date(){
            m = d = y = 1;
        }
        Date(int m, int d, int y){
            if(!setDate(m, d, y))   // if Date is invalid
                m = d = y = 1;  
        }
        void setDate();             // Set the current Date
        bool setDate(int m, int d, int y);
        int getMonth() const {return m;}
        int getDay() const {return d;}
        int getYear() const {return y;}
        bool isEqual(const Date& dd) const{
            return m == dd.m && d == dd.d && y == dd.y;
        }
        bool isLess(const Date& dd) const;
        const string& asString() const;
        void print(void) const;
};

inline bool Date::isLess(const Date& dd) const{
    if(y!=dd.y)
        return y<dd.y;
    else if(m!=dd.m)
        return m<dd.m;
    else
        return d<dd.d;
}

inline bool isLeapYear(int year){
    return (year%4==0 && year%100!=0) || year%400==0;
}

void Date::setDate(){
    struct tm *dur;
    time_t sec;
    time(&sec);
    dur = localtime(&sec);
    d = (short) dur->tm_mday;
    m = (short) dur->tm_mon + 1;
    y = (short) dur->tm_year + 1900;
}

bool Date::setDate(int mn, int da, int yr){
    if(mn<1 || mn>12)
        return false;
    if(da<1 || da>31)
        return false;
    switch(mn){
        case 2: if(isLeapYear(yr)){
            if(da>29)
                return false;
            }
            else if(da>28)
                return false;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
                 if(da>30)
                    return false;
    }
    m = (short) mn;
    d = (short) da;
    y = (short) yr;
    return true;
}

void Date::print() const{
    cout<<asString()<<endl;
}

const string& Date::asString() const{
    static string dateString;
    stringstream iostream;      // for conversion number -> string 
    iostream<<setfill('0')
            <<setw(2)<<m<<'-'
            <<setw(2)<<d<<'-'<<y;
    iostream >> dateString;
    return dateString;
}

class Member{
    private:
        int nr;
        string name;
        const Date birth;
        static Member* ptrBoss;
    public:
        Member(long m_nr, const string& m_name, const Date& m_birth) : nr(m_nr), birth(m_birth){
            if(!setName(m_name))
                name = "Unknown";
        }
        
        Member(long m_nr, const string& m_name, int day, int month, int year) : nr(m_nr), birth(day,month,year){
            if(!setName(m_name))
                name = "Unknown";
        }
        int getNr() const {return nr;}
        const string& getName() const {return name;}
        const Date& getBirthday() const {return birth;}
        
        void setNr(int n) {nr = n;}
        bool setName(const string& s){
            if(s.size() < 1)
                return false;
            name = s;
            return true;
        }
        void display() const;
        
        static Member* getBoss(){
            return ptrBoss;
        }
        static void setBoss(Member* ptrMem){
            ptrBoss = ptrMem;
        }
};

Member* Member::ptrBoss = NULL;

void Member::display() const{
    string line(50,'-');
    cout<<line
        <<"\n Member number: "<<nr 
        <<"\n Member:        "<<name
        <<"\n Birthday:      "<<birth.asString()<<'\n'<<line<<endl;
}

int main()
{
    Date today;
    today.setDate();
    cout<<"Date:    "<<today.asString()<<endl;
    
    Member dung(0, "Anh, Dung", 12, 9, 100),
            anh(2222, "Ho, Anh", Date(9,12,106));
    dung.setNr(1111);
    cout<<"\n2 members of the sports club:\n"<<endl;
    dung.display();
    anh.display();
    cout<<"\nSomething changed!"<<endl;
    dung.setName("Paige-Dung");
    dung.display();
    Member benny(1122, "Paige-Benny", 1, 1, 2000);
    cout<<"The youngest member of the sports club: \n";
    benny.display();
    
    int nr;
    Member *ptr = NULL;
    cout<<"\nWho is the boss of the sports club?\n"
        <<"Enter the member number: ";
    if(cin>>nr){
        if(nr == dung.getNr())
            ptr = &dung;
        else if(nr == anh.getNr())
            ptr = &anh;
        Member::setBoss(ptr);
    }
    cout<<"\nThe boss of the sports club:"<<endl;
    ptr = Member::getBoss();
    if(ptr != NULL)
        ptr->display();
    else
        cout<<"No bos existing!"<<endl;
    return 0;
}
