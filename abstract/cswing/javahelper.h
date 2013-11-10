
typedef void* A___JavaObject;

A___JavaObject a___createObject(const char* cl);
void a___invoke(A___JavaObject o, const char* meth);
void a___invokeI(A___JavaObject o, const char* meth, int p1);
void a___invokeII(A___JavaObject o, const char* meth, int p1, int p2);
void a___invokeFFF(A___JavaObject o, const char* meth, float p1, float p2, float p3);
void a___invokeFFFF(A___JavaObject o, const char* meth, float p1, float p2, float p3, float p4);
void a___invokeFFFS(A___JavaObject o, const char* meth, float p1, float p2, float p3, const char* p4);
void a___invokeS(A___JavaObject o, const char* meth, const char* p1);
int a___invokeReturnBoolean(A___JavaObject o, const char* meth);
int a___invokeIReturnBoolean(A___JavaObject o, const char* meth, int p1);
int a___invokeReturnInt(A___JavaObject o, const char* meth);
