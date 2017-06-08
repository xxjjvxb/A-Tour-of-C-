#include <iostream>
#include <list>

using namespace std;

class Vector {
public:
    Vector(int s):sz{s},elem{new double[s]} {
        for(int i=0;i<s;i++)
            elem[i]=0;
    }
    Vector(initializer_list<double> lst)
        :elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())}
    {
        copy(lst.begin(),lst.end(),elem);
    }
    ~Vector() {
        delete[] elem;
    }
    double& operator[](int i) { return elem[i]; }
    int size() const { return sz; }
    void push_back(double);
private:
    int sz;
    double* elem;
};

class Container {
public:
    virtual double & operator[](int) = 0;
    virtual int size() const = 0;
    virtual ~Container() {}
};

void use(Container& c)
{
    const int sz = c.size();

    for(int i=0; i<sz; i++){
        cout << c[i] << '\n';
    }
}

class V_container:public Container {
    Vector v;
public:
    V_container(int s):v(s) {}
    ~V_container() {}

    double& operator[](int i) { return v[i]; }
    int size() const { return v.size(); }
};

void g()
{
//    V_container vc ={10,9,8,7,6,5,4,3,2,1,0};
//    use(vc);
}

class L_container:public Container {
    list<double> ld;
public:
    L_container(){}
    L_container(initializer_list<double> il):ld{il}{}
    ~L_container(){}

    double& operator[](int i) {
        for (auto& x:ld){
            if(i==0) return x;
            --i;
        }

        throw out_of_range("List container");
    }
    int size() const { return ld.size(); }
};

void h()
{
    L_container lc = {1,2,3,4,5,6,7,8,9};
    use(lc);
}

int main()
{
    h();
    // g();
    Vector v{1,2,3,4,5};

    return 1;
}
