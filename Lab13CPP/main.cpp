#include <iostream>
#include <array>
#include <algorithm>
#include <functional>
#include <fstream>
#include <iterator>
using namespace std;

class Student
{
friend ostream& operator<< (ostream& os, Student& st);
friend istream& operator>> (istream& is, Student& st);
private:
    string name_;
    unsigned short group_;
    array <int, 5> marks_;
public:
    Student():
        name_(" ")
        ,group_(0)
        {this->marks_.fill(-1);}
    Student(string name, unsigned short group):
        name_(name)
        ,group_(group)
        {this->marks_.fill(-1);}
    void setName(string name)
    {
        this->name_ = name;
    }
    void setGroup(short group)
    {
        this->group_ = group;
    }
    void setMarks(istream& is)
    {
        auto iter = this->marks_.begin();
        for(auto &i : this->marks_)
        {
            is >> i;
            if(iter++ != this->marks_.end()-1)
            {
                is.ignore(1,',');
            }
        }
    }
    void setMarks(array<int, 5> ar)
    {
        copy(ar.begin(), ar.end(), this->marks_.begin());
    }
    string getName()
    {
        return this->name_;
    }
    short getGroup()
    {
        return this->group_;
    }
    array<int, 5> getMarks()
    {
        return this->marks_;
    }

    float getAverageMark()
    {
        float res = 0;
        for(auto i : this->marks_)
        {
            res += i;
        }
        return (res /= 5);
    }

    void printMarks()
    {
        auto iter = this->marks_.begin();
        for(auto i: this->marks_)
        {
            cout << i;
            iter++ != this->marks_.end()-1? cout << ", ": cout << endl;
        }
    }
    bool findMark(int val)
    {
        for(auto i: this->getMarks())
        {
            if(i == val)
            {
                return 1;
            }
        }
        return 0;
    }
};
ostream& operator<< (ostream& os, Student& st)
{
    os << st.name_ << " - " << st.group_ << " - " << st.getAverageMark() << endl << "Marks are: \t";
    st.printMarks();
    return os;
}

istream& operator>> (istream& is, Student& st)
{
    char BUFF[500];
    is.getline(BUFF, sizeof(BUFF), '-');
    st.name_ = BUFF;
    is >> st.group_;
    is.ignore(1,'-');
    st.setMarks(is);
    return is;
}
bool operator<(Student s1, Student s2)
{
    return s1.getAverageMark() < s2.getAverageMark();
}

bool comp(Student t1, Student t2)
{
    return t1.getAverageMark() > t2.getAverageMark();
}


void menu()
{
    char usInput;
    cout << "You need to print array of 10 Students" << endl << "Press 'f' to read from file or 'c' to print in console";
    cin >> usInput;
    array <Student, 10> st;
    if(usInput == 'f')
    {
        char path [] = "students.txt";
        ifstream is(path);
        for(auto& i: st)
        {
            is >> i;
        }
        is.close();
    }
    else if (usInput == 'c')
    {
        for(auto &i: st)
        {
            cin >> i;
        }
    }
    else
    {
        throw "ERROR. CAN'T READ STUDENTS";
    }
    while(usInput != 'q')
    {
        cout << "menu" << endl;
        switch(usInput)
        {
        case 's':
            sort(st.begin(), st.end(), comp);
            for(auto i: st)
            {
                cout << i;
            }
            break;
        case 'f':
            {
            char check = 'N';
            for(auto i: st)
            {
                if(i.findMark(4) || i.findMark(5))
                {
                    check = 'Y';
                    cout << i;
                }
            }
            if(check == 'N')
            {
                cout << "There isn't any students with this marks" << endl;
            }
            break;
            }
        case 'q':
            break;
        default:
            cout << "Unknown operation";
            break;
        }
    }
}
int main()
{
      cout << "Template for printing of students:" << endl << "\tBayev V A-105-5,4,3,2,1" << endl << "\t Name-groupNum-marks" << endl << "If you do smth wrong program will crush" << endl;
//    array <Student, 10> arr;
//    for(auto &i: arr)
//    {
//        cin >> i;
//    }
//    cout << endl;
//    /*sort(arr.begin(), arr.end(), comp);
//    for(auto i: arr)
//    {    char usInput;

//        cout << i;
//    */
//    char check = 'N';
//    for(auto i: arr)
//    {
//        if(i.findMark(4) || i.findMark(5))
//        {
//            check = 'Y';
//            cout << i;
//        }
//    }
//    if(check == 'N')
//    {
//        cout << "There isn't any students with this marks" << endl;
//    }
    cout << "You need to print array of 10 Students" << endl << "Press 'f' to read from file or 'c' to print in console   ";
    char usInput;
    cin >> usInput;
    array <Student, 10> st;
    if(usInput == 'f')
    {
        char path [] = "students.txt";
        ifstream is(path);
        for(auto& i: st)
        {
            is >> i;
        }
        is.close();
    }
    else if (usInput == 'c')
    {
        for(auto &i: st)
        {
            cin >> i;
        }
    }
    else
    {
        throw "ERROR. CAN'T READ STUDENTS";
    }
    while(usInput != 'q')
    {
        cout << "What do you want to do?\n\t[s] - Sort students by average mark\n\t[f] - Print students which have 4 or 5" << endl;
        cin >> usInput;
        switch(usInput)
        {
        case 's':
            sort(st.begin(), st.end(), comp);
            for(auto i: st)
            {
                cout << i;
            }
            break;
        case 'f':
            {
            char check = 'N';
            for(auto i: st)
            {
                if(i.findMark(4) || i.findMark(5))
                {
                    check = 'Y';
                    cout << i;
                }
            }
            if(check == 'N')
            {
                cout << "There isn't any students with this marks" << endl;
            }
            break;
            }
        case 'q':
            break;
        default:
            cout << "Unknown operation";
            break;
        }
    }
    return 0;
}
