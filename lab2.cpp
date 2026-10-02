#include <iostream>
#include <windows.h>

using namespace std;

class Line{
public:
    int len;
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
};


int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    printf("СТАТИЧЕСКИ\n");
    // статически 
    Line a;
    Line a2(20);
    Line a3(a2);
    
    printf("\nДИНАМИЧЕСКИ\n");
    // динамически
    Line *b = new Line;
    Line *b2 = new Line(20);
    Line *b3 = new Line(*b2);

    delete b;
    delete b2;
    delete b3;

    return 0;

}