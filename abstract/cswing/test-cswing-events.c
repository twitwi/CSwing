
#include <stdlib.h>
#include <stdio.h>
#include <cswing.h>

#define DA printf("%d\n", __LINE__);

int main(int argc, char** argv) {
    
    A___Fenetre f = a___create2(800, 600);
    
    a___addButton(f, 38, 10, 10, 100, 30, "up");
    int txtId = a___addTextField(f, 99, 10, 30, 100, 50);
    a___addButton(f, 100, 10, 50, 100, 70, "magic");
    int slId = a___addSlider(f, 99, 10, 80, 100, 100);
    int rID = a___addSlider(f, 99, 10, 500, 400, 520);
    int gID = a___addSlider(f, 99, 10, 520, 400, 540);
    int bID = a___addSlider(f, 99, 10, 540, 400, 560);
    int x = 400;
    int y = 50;
    a___setSlider(f, slId, 200);
    a___setSlider(f, rID, 500);
    a___setSlider(f, gID, 500);
    a___setSlider(f, bID, 500);
    while (1) {
        do {
            switch (a___firedEvent(f)) {
            case 37: x -= 10; break;
            case 39: x += 10; break;
            case 38: y -= 10; break;
            case 40: y += 10; break;
            case 100: a___setTextField(f, txtId, "3.141592"); break;
            }
            a___erase(f);
            char txt[1000];
            a___getTextField(f, txtId, txt);
            a___color(f, a___getSlider(f, rID)/1000.f, a___getSlider(f, gID)/1000.f, a___getSlider(f, bID)/1000.f);
            a___disk(f, x, y, 20);
            a___color(f, 1, 1, 1);
            a___centeredText(f, x, y-22, a___getSlider(f, slId)/10.f, txt);
        } while (a___waitWithEvent(f, 1000));
        y = y + 10;
        if (a___isClosed(f)) break;
    }
    
    return 0;
}

