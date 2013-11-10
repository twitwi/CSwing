
#include "javahelper.h"
#include <jni.h>
#include <stdlib.h>

#ifdef __linux__
#include <dlfcn.h>
#define VVVVVM \
    const char* jvmdllpath = getenv("JVMDLL"); \
    fprintf(stderr, "Opening JVMDLL: '%s'\n", jvmdllpath); \
    void* lib = dlopen(jvmdllpath, RTLD_NOW|RTLD_GLOBAL); \
    typedef jint (*fpCJV)(JavaVM**, void**, void*); \
    fpCJV CreateJavaVM; \
    CreateJavaVM = dlsym(lib, "JNI_CreateJavaVM"); \
    /*JNI_*/CreateJavaVM(&jvm, (void **)&env, &args);
#else
#include <windows.h>
#define VVVVVM \
    HINSTANCE hVM; \
    const char* jvmdllpath = getenv("JVMDLL") ? getenv("JVMDLL") : "C:\\Program Files\\Java\\jre7\\bin\\client\\jvm.dll"; \
    fprintf(stderr, "Opening JVMDLL: '%s'\n", jvmdllpath); \
    hVM = LoadLibrary(jvmdllpath); \
    if (hVM == NULL) { \
    	    DWORD dwe = GetLastError(); \
    	    return (JNIEnv*)-1; \
    } \
    typedef jint	(CALLBACK *fpCJV)(JavaVM**, void**, JavaVMInitArgs*); \
    fpCJV CreateJavaVM; \
    CreateJavaVM = (fpCJV)GetProcAddress(hVM, "JNI_CreateJavaVM"); \
    CreateJavaVM(&jvm, (void**)&env, &args); 
    
#endif

JNIEnv* globalEnv = NULL;

JNIEnv* a___createJVM() {
    JavaVM* jvm;
    JNIEnv* env;
    JavaVMInitArgs args;
    JavaVMOption options[1];
    
    /* There is a new JNI_VERSION_1_4, but it doesn't add anything for the purposes of our example. */
    args.version = JNI_VERSION_1_2;
    args.nOptions = 1;
    //options[0].optionString = "-Djava.class.path=c:\\projects\\local\\inonit\\cls";
    //options[0].optionString = "-Djava.class.path=*";
    const char* cswingjar = getenv("CSWINGJAR") ? getenv("CSWINGJAR") : "cswing/CSwingJava-1.1-SNAPSHOT.jar";
    char* buff = malloc(4096);
    fprintf(stderr, "Using CSWINGJAR: '%s'\n", cswingjar);
    snprintf(buff, 4000, "-Djava.class.path=%s", cswingjar);
    options[0].optionString = buff;
    args.options = options;
    args.ignoreUnrecognized = JNI_FALSE;

    VVVVVM;
    return env;
}

JNIEnv *a___ensureInited() {
    if (globalEnv == NULL) {
        globalEnv = a___createJVM();
    }
    return globalEnv;
}

// API
A___JavaObject a___createObject(const char* _cl) {
    JNIEnv* e = a___ensureInited();
    jclass cl = (*e)->FindClass(e, _cl);
    jmethodID constructor = (*e)->GetMethodID(e, cl, "<init>", "()V");
    A___JavaObject res = (*e)->NewObject(e, cl, constructor);
    return res;
}

#define A___INVOKE(sig, ...)                                     \
    JNIEnv* e = a___ensureInited();                                \
    jclass cl = (*e)->GetObjectClass(e, o);               \
    jmethodID meth = (*e)->GetMethodID(e, cl, _meth, sig);       \
    (*e)->CallVoidMethod(e, o, meth, __VA_ARGS__);

void a___invoke(A___JavaObject o, const char* _meth) {
    JNIEnv* e = a___ensureInited();
    jclass cl = (*e)->GetObjectClass(e, o);
    jmethodID meth = (*e)->GetMethodID(e, cl, _meth, "()V");
    (*e)->CallVoidMethod(e, o, meth);
}

int a___invokeReturnInt(A___JavaObject o, const char* _meth) {
    JNIEnv* e = a___ensureInited();
    jclass cl = (*e)->GetObjectClass(e, o);
    jmethodID meth = (*e)->GetMethodID(e, cl, _meth, "()I");
    return (*e)->CallIntMethod(e, o, meth);
}

int a___invokeReturnBoolean(A___JavaObject o, const char* _meth) {
    JNIEnv* e = a___ensureInited();
    jclass cl = (*e)->GetObjectClass(e, o);
    jmethodID meth = (*e)->GetMethodID(e, cl, _meth, "()Z");
    return 0x1 & (*e)->CallBooleanMethod(e, o, meth);
}

int a___invokeIReturnBoolean(A___JavaObject o, const char* _meth, int p1) {
    JNIEnv* e = a___ensureInited();
    jclass cl = (*e)->GetObjectClass(e, o);
    jmethodID meth = (*e)->GetMethodID(e, cl, _meth, "(I)Z");
    return 0x1 & (*e)->CallBooleanMethod(e, o, meth, p1);
}

void a___invokeI(A___JavaObject o, const char* _meth, int p1) {
    A___INVOKE("(I)V", p1);
}

void a___invokeII(A___JavaObject o, const char* _meth, int p1, int p2) {
    A___INVOKE("(II)V", p1, p2);
}

void a___invokeFFF(A___JavaObject o, const char* _meth, float p1, float p2, float p3) {
    A___INVOKE("(FFF)V", p1, p2, p3);
}

void a___invokeFFFS(A___JavaObject o, const char* _meth, float p1, float p2, float p3, const char* p4) {
    A___INVOKE("(FFFLjava/lang/String;)V", p1, p2, p3, (*e)->NewStringUTF(e, p4));
}

void a___invokeFFFF(A___JavaObject o, const char* _meth, float p1, float p2, float p3, float p4) {
    A___INVOKE("(FFFF)V", p1, p2, p3, p4);
}

void a___invokeS(A___JavaObject o, const char* _meth, const char* p1) {
    A___INVOKE("(Ljava/lang/String;)V", (*e)->NewStringUTF(e, p1));
}


