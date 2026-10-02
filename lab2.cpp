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
    void addition(int len2){
        printf("Addition\n");
        len = len + len2;
    }
    void subtraction(int len3);
};

void Line::subtraction(int len3) {
    printf("Substraction\n");
    len = len - len3;
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    Line *b = new Line(24);
    Line *b2 = new Line(35);

    // b->len нельзя т.к. протектед

    b->addition(63);
    b2->subtraction(13);

    delete b;
    delete b2;

    return 0;

}