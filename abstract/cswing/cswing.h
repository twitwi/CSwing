

typedef void* A___Fenetre; // identifiant de fenêtre

A___Fenetre a___create(int w, int h);
A___Fenetre a___create2(int w, int h);

void a___erase(A___Fenetre f);
void a___waitFor(A___Fenetre f, int ms);
int a___waitWithEvent(A___Fenetre f, int ms);
int a___firedEvent(A___Fenetre f);
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


// 
void a___addButton(A___Fenetre f, int a___event, int x1, int y1, int x2, int y2, const char* txt);

int a___addSlider(A___Fenetre f, int a___event, int x1, int y1, int x2, int y2);
int a___getSlider(A___Fenetre f, int id);
void a___setSlider(A___Fenetre f, int id, int a___sliderValue);

int a___addTextField(A___Fenetre f, int a___event, int x1, int y1, int x2, int y2);
void a___getTextField(A___Fenetre f, int id, char* out);
void a___setTextField(A___Fenetre f, int id, const char* txt);
