#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

class SymbString
{
public:
    SymbString(string val)
    {
        this->val_ = val;
    }
    ~SymbString()
    {
        cout << "Symb string is free\n";
    }
    void show()
    {
        cout << this->val_ << endl;
    }
    string getVal()
    {
        return this->val_;
    }
    void setVal(string val)
    {
        this->val_ = val;
    }
private:
    string val_;
};
class BinString
{
public:
    BinString(string binSeq)
    {
        this->val_ = binSeq;
    }
    ~BinString()
    {
        cout << "Bin String is free\n";
    }
    void show()
    {
        cout << this->val_ << endl;
    }
    string getVal()
    {
        return this->val_;
    }
    void setVal(string binSeq)
    {
        this->val_ = binSeq;
    }
private:
    string val_;
};

string operator+ (SymbString& symS, BinString& binS)
{
    return symS.getVal() + binS.getVal();
}

string operator+ (BinString& binS, SymbString& symS)
{
    return symS.getVal() + binS.getVal();
}
int main()
{
    BinString* a = new BinString("010");
    a->show();
    SymbString* b = new SymbString("Hello ");
    b->show();
    cout << *a + *b << endl;
    delete a;
    delete b;
    return 0;
}
