#include <iostream>
#include <windows.h>

using namespace std;

class Line{
protected:
    int len;
public:
    Line() {
        printf("Line()\n");
        len = 0;
    }
    Line(int len){
        printf("Line(int len)\n");
        this->len = len;
    }
    Line(const Line &a) {
        printf("Line(const Line &a)\n");
        len = a.len;
    }
    ~Line() {
        printf("%d\n", len);
        printf("~Line()\n");
    }
    void addition(int add){
        printf("Addition\n");
        len = len + add;
    }
    void subtraction(int sub);
};

void Line::subtraction(int sub) {
    printf("Substraction\n");
    len = len - sub;
};

class MyRectangle : public Line {
protected:
    int len2;
public:
    MyRectangle() : Line(){
        printf("MyRectangle()\n");
        len2 = 0;
    }
    MyRectangle(int len, int len2): Line(len){
        printf("MyRectangle(int len)\n");
        this->len2 = len2;
    }
    MyRectangle(const MyRectangle &a) {
        printf("MyRectangle(const MyRectangle &a)\n");
        len2 = a.len2;
        len = a.len;
    }
    ~MyRectangle() {
        printf("%d len2=%d\n", len, len2);
        printf("~MyRectangle()\n");
    }
    void multiply(int mul){
        printf("Multiply\n");
        len = len * mul;
        len2 = len2 * mul;
    }
};

class Triangle{
protected:
    Line *l1;
    Line *l2;
    Line *l3;
public:
    Triangle() {
        printf("Triangle()\n");
        l1 = new Line;
        l2 = new Line;
        l3 = new Line;
    }
    Triangle(int len1, int len2, int len3){
        printf("Triangle(int len1, int len2, int len3)\n");
        l1 = new Line(len1);
        l1 = new Line(len2);
        l1 = new Line(len3);

    }
    Triangle(const Triangle &t) {
        printf("Triangle(const Triangle &t)\n");
        // l1 = t.l1; // Почему выходит ошибка
        // l2 = t.l2;
        // l3 = t.l3;
        l1 = new Line(*(t.l1));
        l2 = new Line(*(t.l2));
        l3 = new Line(*(t.l3));
    }
    ~Triangle() {
        // printf("%d\n", len);
        delete l1;
        delete l2;
        delete l3;
        printf("~Triangle()\n");
    }
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    Triangle *t1 = new Triangle; 
    Triangle *t2 = new Triangle(*t1);
    Triangle *t3 = new Triangle(*t2);

    delete t1;
    delete t2;
    delete t3;

    return 0;

}