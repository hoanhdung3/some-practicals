// p.319
#include<iostream>
#include<iomanip>
#include<string>
#include<ctime>

using namespace std;

class DayTime{
    private:
        short hour, minute, second;
        bool overflow;
    public:
        DayTime(int h = 0, int m = 0, int s = 0){
            overflow = false;
            if(!setTime(h, m, s))       // this->setTime(...)
                hour = minute = second = 0;
        }
        bool setTime(int hour, int minute, int second = 0){
            if(hour>=0 && hour<24 && minute>=0 && minute<60 && second>=0 && second<60){
                this->hour = (short) hour;
                this->minute = (short) minute;
                this->second = (short) second;
                return true;
            }
            else
                return false;
        }
        int getHour() const {return hour;}
        int getMinute() const {return minute;}
        int getSecond() const {return second;}
        
        int asSecond() const{       // DayTime in seconds
            return (60*60*hour + 60*minute + second);
        }
        bool isLess(DayTime t) const{       // compare *this and t 
            return asSecond() < t.asSecond();
        }   // this->asSecond() < t.asSecond();
        
        void swap(DayTime& t){
            DayTime temp(t);
            t = *this;
            *this = temp;
        }
        void print() const{
            cout<<hour<<":"<<minute<<":"<<second<<endl;
        }
};

const DayTime& currentTime(){
    static DayTime curTime;
    time_t sec;
    time(&sec);     // Gets the present time 
    struct tm* time = localtime(&sec);
    curTime.setTime(time->tm_hour, time->tm_min, time->tm_sec);
    return curTime;
}

class Result{
    private:
        double val;
        DayTime time;
        static double min, max;
        static bool first;
        void setMinMax(double w);
    public:
        Result();
        Result(double w, const DayTime& z = currentTime());
        Result(double w, int hr, int min, int sec);
        double getVal() const {return val;}
        void setVal(double w) {val = w;}
        const DayTime& getTime() const {return time;}
        void setTime(const DayTime& z) {time = z;}
        bool setTime(int hr, int min, int sec) { return time.setTime(hr, min, sec); }
        void print(string s) const;
};

double Result::min = 0.0;
double Result::max = 0.0;
bool Result::first = true;
void Result::setMinMax(double w){
    if(first){
        min = max = w;
        first = false;
    }
    else if(w<min)
        min = w;
    else if(w>max)
        max = w;
}

Result::Result() : val(0.0){
    // .........
}

Result::Result(double w, int hr, int min, int sec) : val(w), time(hr, min, sec){
    setMinMax(w);
} 

Result::Result(double w, const DayTime& z) : val(w), time(z){
    setMinMax(w);
}

void Result::print(string s) const{
    cout<<"\nValue of "<<s<<" :   "<<val<<endl;
    cout<<"Time of "<<s<<" :    ";
    time.print();
    cout<<endl;
}

int main()
{
    DayTime morning(6,30);
    Result t1,
           t2(12.5, morning),
           t3(18.2, 12, 0, 0),
           t4(17.7);            // At currentTime
    
    cout<<"Default values:  ";
    t1.print("t1");
    cout<<"\n Temperature Time \n"
        <<"----------------------"<<endl;
    t2.print("t2");
    t3.print("t3");
    t4.print("t4");
    cout<<endl;
    return 0;
}
