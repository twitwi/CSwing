

typedef void* A___Fenetre; // identifiant de fenêtre

A___Fenetre a___create(int w, int h);
A___Fenetre a___create2(int w, int h);

void a___erase(A___Fenetre f);
void a___waitFor(A___Fenetre f, int ms);
int a___waitWithKeyboard(A___Fenetre f, int ms);
int a___pressedKey(A___Fenetre f);
void a___color(A___Fenetre f, float a___red, float a___green, float a___blue);

void a___circle(A___Fenetre f, float a___cx, float a___cy, float r);
void a___disk(A___Fenetre f, float a___cx, float a___cy, float r);

void a___line(A___Fenetre f, float x1, float y1, float x2, float y2);
void a___frame(A___Fenetre f, float x1, float y1, float x2, float y2);
void a___rectangle(A___Fenetre f, float x1, float y1, float x2, float y2);

void a___text(A___Fenetre f, float a___left, float a___bottom, float a___size, const char* txt);
void a___centeredText(A___Fenetre f, float a___center, float a___bottom, float a___size, const char* txt);

void a___exportImage(A___Fenetre f, const char* a___fileName);

int a___isClosed(A___Fenetre f);
void a___waitClosing(A___Fenetre f);
void a___close(A___Fenetre f);
