#include <iostream>
#include <math.h>

using namespace std;

struct Vector2D {
    int x,y;
public:
    double length() {
        return sqrt(pow(this ->x, 2) + pow(this->y,2));
    }
};
Vector2D operator+(const Vector2D& v1, const Vector2D& v2)
{
    Vector2D v = {v1.x + v2.x, v1.y + v2.y};
    return v;
}

Vector2D operator-(const Vector2D& v1, const Vector2D& v2)
{
    Vector2D v = {v1.x - v2.x, v1.y - v2.y};
    return v;
}

float operator*(const Vector2D& v1, const Vector2D& v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

ostream& operator<<(ostream& os, const Vector2D& v)
{
    os << v.x << " " << v.y;
    return os;
}

int main()
{
    Vector2D v1 = {4, 1};
    Vector2D v2 = {5, 5};
    Vector2D vP = v1 + v2;
    Vector2D vM = v1 - v2;
    cout << vP << endl << vM << endl;
    return 0;
}


