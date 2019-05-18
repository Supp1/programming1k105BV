#include <iostream>
#include <cstring>
#include <locale>
#include <fstream>
#define CHECK
using namespace std;
class BinTree
{
public:
    friend bool operator> (BinTree&, BinTree&);
    friend bool operator< (BinTree&, BinTree&);
    friend bool operator== (BinTree&, BinTree&);
    friend ostream& operator<<(ostream&, const BinTree&);
    friend ostream& operator<<(ostream&, const BinTree*);
    friend istream& operator>> (istream&, BinTree&);
    friend ifstream& operator>> (ifstream&, BinTree&);

    //CONSTRUCTORS
    BinTree() : val_(), key_() {};
    BinTree(string val, string key)
    {
        this-> val_ = val;
        this-> key_ = key;
    }
    ~BinTree()
    {
        cout << "Deleting" << endl;
    }
    //ADD AND LINK ELEMENTS
    BinTree* addElem(string val, string key)
    {
        if(val > this->val_)
        {
            if(this->right_ == NULL)//CHECKING FOR CHILDS
            {
                BinTree* res = new BinTree(val, key);
                this->right_ = res;
                this->right_->parent_ = this;
                return res;
            }
            else
            {
                this->right_->addElem(val,key);
            }
        }
        else if(val < this->val_)
        {
            if(this->left_ == NULL)//CHECKING FOR CHILDS
            {
                BinTree* res = new BinTree(val, key);
                this->left_ = res;
                this->left_->parent_ = this;
                return res;
            }
            else
            {
                this->left_->addElem(val,key);
            }
        }
    }
    //PRINT TREE
    void print () const
    {
        if(this)
        {
            this->left_->print(); //Рекурсивная функция для левого поддерева
            cout << (*this) << endl; //Отображаем корень дерева
            this->right_->print(); //Рекурсивная функция для правого поддерева
        }
    }
    void print (ofstream& os) const
    {
        if(this)
        {
            this->left_->print(); //Рекурсивная функция для левого поддерева
            os << (*this) << endl; //Отображаем корень дерева
            this->right_->print(); //Рекурсивная функция для правого поддерева
        }
    }
    //DELETE ELEMENTS FROM TREE
    void del()
    {
        if(this->left_ != NULL)//CHECKING FOR CHILDS
        {
            this->left_->del();
        }
        if(this->right_ != NULL)//CHECKING FOR CHILDS
        {
            this->right_->del();
        }
        if(this->parent_ != NULL)//IF THERE ARE PARENT, DELETE POINTERS
        {
            (this->compare(this->parent_) == 1 ? (this->parent_->right_ = NULL) : (this->parent_->left_ = NULL));
        }
        delete this;
    }
    //DELETE ELEMENTS BY VALUE
    void del(string val)
    {
        this->treeSearch(val)->del();
    }
    //SEARCH ELEMENTS
    BinTree* treeSearch (string val)
    {
        if(val == this->val_)
        {
            #ifdef CHECK
            cout << "Compare " << val << " and" << this->val_ <<" ravno" << endl;
            cout << this << endl;
            #endif // CHECK
            return this;
        }
        else if(val < this->val_)
        {
            #ifdef CHECK
            cout << "Compare " << val << " and " << this->val_ << " less" <<endl;
            #endif // CHECK
            this->left_->treeSearch(val);
        }
        else if (val > this->val_)
        {
            #ifdef CHECK
            cout << "Compare " << val << " and " << this->val_ << " more" <<endl;
            #endif //CHECK
            this->right_->treeSearch(val);
        }
        else
            throw "SEARCH ERROR";

    }

    //COMPARE ELEMENTS IN TREE
    short compare (BinTree* t) const
    {
        if(this->val_ < t->val_)
        {
            return -1;
        }
        if(this->val_ > t->val_)
        {
            return 1;
        }
        return 0;
    }
    //GETTERS AND SETTERS
    string getVal () const
    {
        return this->val_;
    }
    void setVal(string val)
    {
        this->val_ = val;
    }
    string getKey () const
    {
        return this->key_;
    }
    void setKey(string key)
    {
        this->key_ = key;
    }
    //SOME FIELDS
protected:
    BinTree* parent_ = NULL;
    BinTree* left_ = NULL;
    BinTree* right_= NULL;
private:
    string val_;
    string key_;

};

bool operator> (BinTree& t1, BinTree& t2)
{
    short i = 0;
    while(tolower(t1.val_[i]) == tolower(t2.val_[i])){
        if(i == strlen(t1.val_.c_str()) || i == strlen(t2.val_.c_str()))
        {
            return 0;
        }
        ++i;
    }
    return t1.val_[i] > t2.val_[i];
}

bool operator< (BinTree& t1, BinTree& t2)
{
    short i = 0;
    while(tolower(t1.val_[i]) == tolower(t2.val_[i])){
       if(i == strlen(t1.val_.c_str()) || i == strlen(t2.val_.c_str()))
        {
            return 0;
        }
        ++i;
    }
    return t1.val_[i] < t2.val_[i];
}

bool operator== (BinTree& t1, BinTree& t2)
{
    if (strlen(t1.val_.c_str()) != strlen(t2.val_.c_str()))
    {
        return 0;
    }
    short i = 0;
    while(tolower(t1.val_[i]) == tolower(t2.val_[i])){
       if(i == strlen(t1.val_.c_str()))
        {
            return 1;
        }
        ++i;
    }
    return 0;
}

ostream& operator<< (ostream& os,const BinTree& t)
{
    os << t.val_ << " - " << t.key_;
    return os;
}

ostream& operator<< (ostream& os,const BinTree* t)
{
    os << t->val_ << " - " << t->key_;
    return os;
}

ifstream& operator>> (ifstream& fis, BinTree& t)
{
    string value;
    string key;
    getline(fis, value, '-');
    getline(fis, key);
    t.val_ = value; t.key_ = key;
    while(!fis.eof())
    {
        getline(fis, value,'-');
        getline(fis, key, '\n');
        t.addElem(value, key);
    }
    return fis;
}

BinTree readTree (string path)
{
    ifstream fis(path.c_str());
    if(!fis)
    {
        throw "Can't open the file";
    }
    BinTree a;
    fis >> a;
    fis.close();
    return a;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    short userInput = 0;
    string path = "Vocabulary.txt";
    BinTree a = readTree(path);
    a.print();
    //cout << a.getVal() << "\"" << endl;
    //a.print();
    //a.del("Pen");
    //BinTree a("bapple", "яблоко");
    //BinTree b("Apple", "нублоко");
    //cout << (a > b);
    //BinTree a = readTree(path);
    //a.print();
//    while(true)
//    {
//        cout << "This is vocabulary with binary tree. Choose, what to do?" << endl << "\t";
//        cin >> userInput;
//        switch(userInput)
//        {
//        case 1:
//        {
//            cin >> path;
//            break;
//        }
//        case 2:
//        {
//            cout << "Path is: \"" << path  << "\""<< endl;
//            a.print();
//            break;
//        }
//        case 3:
//        {
//            string value;
//            if(cin >> value)
//            {
//                a.del(value);
//            }
//            a.del();
//            break;
//        }
//        case 4:
//        {
//
//            break;
//        }
//        case 5:
//        {
//
//            break;
//        }
//        }
        /*Функционал:
            1.Изменить путь к дереву
            2.Показать дерево
            3.Удалить элемент
            4.Поиск элемента
        */
    //}

    return 0;
}
