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



int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    MyRectangle *b = new MyRectangle(4, 6);

    b->multiply(2);

    delete b;

    return 0;

}