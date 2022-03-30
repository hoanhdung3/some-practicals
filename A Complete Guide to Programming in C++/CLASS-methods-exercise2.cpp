// p.314
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

int main()
{
    Date today, birthday(12,9,2000);
    const Date d2010(1,1,2010);
    
    cout<<"\nDung's birthday: "<<birthday.asString()<<endl;
    today.setDate();
    cout<<"\nToday's date: "<<today.asString()<<endl;
    
    if(today.isLess(d2010))
        cout<<" Good luck for this decade \n"<<endl;
    else
        cout<<" See u next decade\n"<<endl;
        
    Date holiday;
    int m,d,y;
    char c;
    cout<<"\nWhen does your next vacation begin?\n"<<"Enter in Month-Day-Year format: ";
    
    if( !(cin>>m>>c>>d>>c>>y) )
        cerr<<"Invalid input!\n"<<endl;
    else if( !holiday.setDate(m,d,y) )
        cerr<<"Invalid date!\n"<<endl;
    else{
        cout<<"\nYour 1st vacation: ";
        holiday.print();
        if(today.getYear()<holiday.getYear())
            cout<<"You should go on vacation this year!\n"<<endl;
        else
            cout<<"Have a nice trip!\n"<<endl;
    }
    return 0;
}
