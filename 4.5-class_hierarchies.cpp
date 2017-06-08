#include <iostream>
#include <vector>

using namespace std;

class Point {
    private:
        int x, y;
};

class shape {
    public:
        virtual Point center() const =0;
        virtual void move(Point to) =0;

        virtual void draw() const =0;
        virtual void rotate(int angle) =0;

        virtual ~shape(){}
};

void roate_all(vector<shape*>& v, int angle)
{
    for(auto p:v)
        p->rotate(angle);
}

class circle:public shape{
    public:
        circle(Point p, int rr);

        Point center() const { return x; }
        void move(Point to) { x = to; }
        void draw() const;
        void rotate(int i) {}
    private:
        Point x;
        int r;
};

class smiley:public circle{
    public:
        smiley(Point p, int r):
            circle{p,r}, mouth{nullptr} {}
        ~smiley(){
            delete mouth;
            for(auto p:eyes)
                delete p;
        }
        void add_eye(shape* s) { eyes.push_back(s); }
        void draw()
        {

            circle::draw();
            for(auto p:eyes)
                p->draw();
            mouth->draw();
        }
    private:
        vector<shape*> eyes;
        shape* mouth;
};

int main()
{
    return 1;
}
