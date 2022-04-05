// p.437
#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>

using namespace std;

class Euro{
    private:
        long data;
    public:
        Euro(int euro=0, int cents=0){
            data = 100L * (long)euro + cents;
        }
        Euro(double x){
            x *= 100.0;     // Rounding
            data = (long)(x>=0.0 ? x+0.5 : x-0.5);  // ex: 9.7 -> 10
        }
        long getWholePart() const{
            return data/100;
        }
        int getCents() const{
            return (int)(data%100);
        }
        double asDouble() const{
            return (double)data/100.0;
        }
        string asString() const;
        void print(ostream& os) const{
            os<<asString()<<" Euro"<<endl;
        }
        
        Euro operator-() const{     // Negation (unary minus)
            Euro temp;
            temp.data = -data;
            return temp;
        }
        Euro operator/(double x){
            return (*this * (1.0/x));
        }
        friend Euro operator+(const Euro& e1, const Euro& e2);
        friend Euro operator-(const Euro& e1, const Euro& e2);
        friend Euro operator*(const Euro& e, double x){
            Euro temp(((double)e.data/100.0) * x);
            return temp;
        }
        friend Euro operator*(double x, const Euro& e){
            return e * x;
        }
        Euro operator+=(const Euro& e2){
            data += e2.data;
            return *this;
        }
        Euro operator-=(const Euro& e2){
            data -= e2.data;
            return *this;
        }
};

inline string Euro::asString() const{
    stringstream str;
    long temp = data;
    if(temp<0){
        str<<'-';
        temp = -temp;
    }
    str<<temp/100<<'-'<<setfill('0')<<setw(2)<<temp%100;
    return str.str();
}

inline Euro operator+(const Euro& e1, const Euro& e2){
    Euro temp;
    temp.data = e1.data + e2.data;
    return temp;
}

inline Euro operator-(const Euro& e1, const Euro& e2){
    Euro temp;
    temp.data = e1.data - e2.data;
    return temp;
}

int main()
{
    Euro wholesale(20,50), retail;
    retail = wholesale;
    retail += 9.49;
    
    cout<<"Wholesale price: ";
    wholesale.print(cout);
    cout<<"retail price: ";
    retail.print(cout);
    Euro discount(2,10);
    retail -= discount;
    cout<<"\nRetail price including discount: ";
    retail.print(cout);
    wholesale = 34.10;
    cout<<"\nNew wholesale price: ";
    wholesale.print(cout);
    Euro profit(retail - wholesale);
    cout<<"\nThe profit: ";
    profit.print(cout);
    return 0;
}
