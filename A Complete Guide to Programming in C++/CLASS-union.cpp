// p.279
#include<iostream>

using namespace std;

union WordByte{
    private:
        unsigned short w;   // 16 bits
        unsigned char b[2]; // Two bytes: b[0], b[1]
    public:
        unsigned short& word(){
            return w;
        }
        unsigned char& lowByte(){
            return b[0];
        }
        unsigned char& highByte(){
            return b[1];
        }
};

int main(){
    
    WordByte wb;
    wb.word() = 256;
    cout<<"\nWord:      "<<(int)wb.word();
    cout<<"\nLow-byte:  "<<(int)wb.lowByte()
        <<"\nHigh-byte: "<<(int)wb.highByte()<<endl;
    
    return 0;
}
