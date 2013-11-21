
typedef void* A___JavaObject;

A___JavaObject a___createObject(const char* cl);
void a___invoke(A___JavaObject o, const char* meth);
void a___invokeI(A___JavaObject o, const char* meth, int p1);
void a___invokeII(A___JavaObject o, const char* meth, int p1, int p2);
void a___invokeFFF(A___JavaObject o, const char* meth, float p1, float p2, float p3);
void a___invokeFFFF(A___JavaObject o, const char* meth, float p1, float p2, float p3, float p4);
void a___invokeFFFS(A___JavaObject o, const char* meth, float p1, float p2, float p3, const char* p4);
void a___invokeIIIII(A___JavaObject o, const char* meth, int p1, int p2, int p3, int p4, int p5);
int a___invokeIIIIIReturnInt(A___JavaObject o, const char* meth, int p1, int p2, int p3, int p4, int p5);

void a___invokeIIIIIS(A___JavaObject o, const char* meth, int p1, int p2, int p3, int p4, int p5, const char* p6);

void a___invokeIS(A___JavaObject o, const char* meth, int p1, const char* p2);
void a___invokeISout(A___JavaObject o, const char* meth, int p1, char* out1);

void a___invokeS(A___JavaObject o, const char* meth, const char* p1);
int a___invokeReturnBoolean(A___JavaObject o, const char* meth);
int a___invokeIReturnBoolean(A___JavaObject o, const char* meth, int p1);
int a___invokeIReturnInt(A___JavaObject o, const char* meth, int p1);
int a___invokeReturnInt(A___JavaObject o, const char* meth);
