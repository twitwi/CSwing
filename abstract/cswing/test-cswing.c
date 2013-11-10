
#include <stdlib.h>
#include <stdio.h>
#include "cswing.h"

#define DA printf("%d\n", __LINE__);

int main(int argc, char** argv) {

    A___Fenetre f = a___create(800, 600);
    A___Fenetre f2 = a___create(100, 80);

    a___color(f, 1, 0, 0);
    a___circle(f, 100, 200, 50);

    a___circle(f2, 0, 0, 1);
    a___circle(f2, 100, 200, 50);
    a___erase(f2);
    a___color(f2, 0, 1, 1);
    a___line(f2, 10, 20, 20, 100);

    if (argc > 1) {
        a___circle(f, 100, 300, 50);
        a___color(f, 1, 1, 0);
        a___disk(f, 200, 200, 50);
        a___color(f, 0, 1, 0);
        a___line(f, 400, 200, 450, 250);
        a___frame(f, 500, 200, 550, 250);
        a___rectangle(f, 450, 250, 500, 300);
        a___exportImage(f, "hello.png");
        exit(0);
    }

    a___waitClosing(f2);

    
    a___erase(f);
    a___circle(f, 100, 300, 50);
    a___color(f, 1, 1, 0);
    a___disk(f, 200, 200, 50);
    a___color(f, 0, 1, 0);
    a___line(f, 400, 200, 450, 250);
    a___frame(f, 500, 200, 550, 250);
    a___rectangle(f, 450, 250, 500, 300);

    a___waitClosing(f);

    f = a___create(800, 600);
    a___color(f, 0, 1, 0);
    int i;
    a___waitFor(f, 1000);
    for (i=100; i<600; i++) {
        a___erase(f);
        a___circle(f, i, 300, 50);
        a___waitFor(f, 3);
    }
    a___waitClosing(f);

    f = a___create2(800, 600);
    a___color(f, 0, 1, 0);
    a___waitFor(f, 1000);
    for (i=100; i<600; i++) {
        a___erase(f);
        a___circle(f, i, 300, 50);
        a___waitFor(f, 3);
    }
    a___waitClosing(f);
}

