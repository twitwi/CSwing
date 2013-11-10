
#include "cswing.h"
#include "javahelper.h"

#define DA printf("%d\n", __LINE__);

A___Fenetre a___create(int w, int h) {
    A___Fenetre res = (A___Fenetre) a___createObject("com/heeere/cswing/A___Fenetre");
    a___invokeII((A___JavaObject) res, "a___initialize", w, h);
    a___erase(res);
    return res;
}

A___Fenetre a___create2(int w, int h) {
    A___Fenetre res = a___create(w, h);
    a___invoke((A___JavaObject) res, "a___toggleLoopingMode");
    return res;
}

void a___erase(A___Fenetre f) {
    a___invoke((A___JavaObject) f, "a___erase");
}

void a___waitFor(A___Fenetre f, int ms) {
    a___invokeI((A___JavaObject) f, "a___waitFor", ms);
}

int a___waitWithKeyboard(A___Fenetre f, int ms) {
    return a___invokeIReturnBoolean((A___JavaObject) f, "a___waitWithKeyboard", ms);
}

int a___pressedKey(A___Fenetre f) {
    return a___invokeReturnInt((A___JavaObject) f, "a___pressedKey");
}

void a___color(A___Fenetre f, float a___red, float a___green, float a___blue) {
    a___invokeFFF((A___JavaObject) f, "a___color", a___red, a___green, a___blue);
}

void a___circle(A___Fenetre f, float a___cx, float a___cy, float r) {
    a___invokeFFF((A___JavaObject) f, "a___circle", a___cx, a___cy, r);
}

void a___disk(A___Fenetre f, float a___cx, float a___cy, float r) {
    a___invokeFFF((A___JavaObject) f, "a___disk", a___cx, a___cy, r);
}

void a___line(A___Fenetre f, float x1, float y1, float x2, float y2) {
    a___invokeFFFF((A___JavaObject) f, "a___line", x1, y1, x2, y2);
}
void a___frame(A___Fenetre f, float x1, float y1, float x2, float y2) {
    a___invokeFFFF((A___JavaObject) f, "a___frame", x1, y1, x2, y2);
}
void a___rectangle(A___Fenetre f, float x1, float y1, float x2, float y2) {
    a___invokeFFFF((A___JavaObject) f, "a___rectangle", x1, y1, x2, y2);
}
void a___text(A___Fenetre f, float a___left, float a___bottom, float a___size, const char* txt) {
    a___invokeFFFS((A___JavaObject) f, "a___text", a___left, a___bottom, a___size, txt);
}
void a___centeredText(A___Fenetre f, float a___center, float a___bottom, float a___size, const char* txt) {
    a___invokeFFFS((A___JavaObject) f, "a___centeredText", a___center, a___bottom, a___size, txt);
}

void a___exportImage(A___Fenetre f, const char* a___fileName) {
    a___invokeS((A___JavaObject) f, "a___exportImage", a___fileName);
}

int a___isClosed(A___Fenetre f) {
    return a___invokeReturnBoolean((A___JavaObject) f, "a___isClosed");
}

void a___waitClosing(A___Fenetre f) {
    a___invoke((A___JavaObject) f, "a___waitClosing");
}

void a___close(A___Fenetre f) {
    a___invoke((A___JavaObject) f, "a___close");
}


