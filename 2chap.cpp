#include <iostream>

using namespace std;

class Vector {
public:
    Vector(int s):elem{new double[s]},sz{s} {}
    double& operator[](int i) { return elem[i]; }
    int size() { return sz; }
private:
    double* elem;
    int sz;
};


enum Type { str, num };
union Value {
    char* s;
    int i;
};

struct Entry{
    char *ame;
    Type t;
    Value v;
};

enum class Color { r, g, b };

Color col = Color::r;

inline Color& operator++(Color& t){ // ++ prefix
    cout << "prefix";
    switch(t){
        case Color::r: return t=Color::g;
        case Color::g: return t=Color::b;
        case Color::b: return t=Color::r;
    }
}

inline Color operator++(Color& t, int){ // postfix ++
    cout << "postfix";
    ++t;
    return t;

    switch(t){
        case Color::r: return t=Color::g;
        case Color::g: return t=Color::b;
        case Color::b: return t=Color::r;
    }
}

void checkcol(enum Color t){
    switch(t){
        case Color::r: cout << "'r'" << endl; break;
        case Color::g: cout << "'g'" << endl; break;
        case Color::b: cout << "'b'" << endl; break;
    }
}

void checkint(int i){
    cout << i << endl;
}

int main()
{
    Vector v(3);

    v[0] = 2;
    v[1] = 3;
    v[2] = 5;

    //cout << v[2] << v.size();

    checkcol(col++);
    checkcol(++col);
    checkcol(++col);
    checkcol(col++);
    checkcol(col);

    int i = 3;
    cout << i << ++i << ++i << i << i << i++ << i++ << i << i++ << endl;

    i = 3;
    checkint(i);
    checkint(i++);
    checkint(i);
    checkint(++i);
    checkint(i);
    checkint(++i);

    return 1;
}
