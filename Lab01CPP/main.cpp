#include <iostream>
#include <fstream>

using namespace std;

class binNode
{
public:
    setVal(string value)
    {
        this->val_ = value;
    }
    string getVal() const
    {
        return this->val_;
    }
    setKey(string key)
    {
        this->key_ = key;
    }
    string getKey() const
    {
        return this->key_;
    }
private:
    string val_;
    string key_;
friend ostream& operator<<(ostream& os, binNode& n);
friend istream& operator>>(istream& os, binNode& n);
};

class binTree
{
    binTree(binNode[] elem)
    {
    }

};

ostream& operator<<(ostream& os, binNode& n)
{
    os << n.val_ << " - " << n.key_;
    return os;
}

istream& operator>>(istream& is, binNode& n)
{
    string value;
    string key;
    getline(is,value, '-');
    getline(is,key);
    n.val_ = value; n.key_ = key;
    return is;
}

int main()
{
    binNode a;
    cin >> a;
    cout << a;
}
