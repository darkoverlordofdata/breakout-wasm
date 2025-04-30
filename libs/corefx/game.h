#pragma once
#include <emscripten.h>
#include <emscripten/html5.h>
#define GL_GLEXT_PROTOTYPES
#define EGL_EGLEXT_PROTOTYPES
#include <GLFW/glfw3.h>
#include "../corefw/corefw.h"   // IWYU pragma: keep

extern CFClassRef CFXGame;

typedef struct __CFXGame* CFXGameRef;
struct CFXGameVtbl;

extern CFXGameRef CFXGame_instance;

typedef void (*CFXGameProc)(void* self);
struct CFXGameVtbl {
    void (*Initialize)(void* self);
    void (*LoadContent)(void* self);
    void (*Update)(void* self);
    void (*Draw)(void* self);
};

typedef struct __CFXGame {
    __CFObject obj;
    void* subclass;
    struct CFXGameVtbl const* override;
    GLFWwindow* window;
    char* title;
    int len;
    bool* keys;
    double delta;
    double factor;
    uint64_t targetElapsedTime;
    uint64_t accumulatedElapsedTime;
    uint64_t maxElapsedTime;
    uint64_t totalGameTime;
    uint64_t elapsedGameTime;
    uint64_t currentTime;
    long previousTicks;
    int x;
    int y;
    int width;
    int height;
    uint32_t flags;
    int mouseX;
    int mouseY;
    bool mouseDown;
    int sdlVersion;
    int frameSkip;
    int gl_major_version;
    int gl_minor_version;
    bool isRunning;
    int ticks;
    int fps;
    bool isFixedTimeStep;
    bool isRunningSlowly;
    int updateFrameLag;
    bool shouldExit;
    bool suppressDraw;
} __CFXGame;


extern method void* Ctor(
    CFXGameRef this, 
    char* cstr, 
    int width, 
    int height, 
    void* subclass, 
    struct CFXGameVtbl* vptr);

extern method void HandleEvents(
    CFXGameRef const this);

extern method char* ToString(
    CFXGameRef this);

extern method void Start(
    CFXGameRef const this);

extern method void Tick(
    CFXGameRef const this);

extern method void RunLoop(
    CFXGameRef const this);

extern method void Run(
    CFXGameRef const this);

extern method void Initialize(
    CFXGameRef const this);

extern method void LoadContent(
    CFXGameRef const this);

extern method void Update(
    CFXGameRef const this);

extern method void Draw(
    CFXGameRef const this);

static inline CFXGameRef NewCFXGame(char* cstr, int width, int height, void* subclass, struct CFXGameVtbl* vptr)
{
    return Ctor((CFXGameRef)CFCreate(CFXGame), cstr, width, height, subclass, vptr);
}

EM_BOOL onclick_handler_dpad_up(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData);
EM_BOOL onclick_handler_dpad_down(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData);
EM_BOOL onclick_handler_dpad_left(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData);
EM_BOOL onclick_handler_dpad_right(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData);
EM_BOOL onclick_handler_button_a(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData);

EM_BOOL touchstart_handler_dpad_up(int eventType, const EmscriptenTouchEvent *touchEvent, void *userData);
EM_BOOL touchstart_handler_dpad_down(int eventType, const EmscriptenTouchEvent *touchEvent, void *userData);
EM_BOOL touchstart_handler_dpad_left(int eventType, const EmscriptenTouchEvent *touchEvent, void *userData);
EM_BOOL touchstart_handler_dpad_right(int eventType, const EmscriptenTouchEvent *touchEvent, void *userData);
EM_BOOL touchstart_handler_button_a(int eventType, const EmscriptenTouchEvent *touchEvent, void *userData);

EM_BOOL touchend_handler_dpad_up(int eventType, const EmscriptenTouchEvent *touchEvent, void *userData);
EM_BOOL touchend_handler_dpad_down(int eventType, const EmscriptenTouchEvent *touchEvent, void *userData);
EM_BOOL touchend_handler_dpad_left(int eventType, const EmscriptenTouchEvent *touchEvent, void *userData);
EM_BOOL touchend_handler_dpad_right(int eventType, const EmscriptenTouchEvent *touchEvent, void *userData);
EM_BOOL touchend_handler_button_a(int eventType, const EmscriptenTouchEvent *touchEvent, void *userData);

EM_BOOL touchcancel_handler_dpad_up(int eventType, const EmscriptenTouchEvent *touchEvent, void *userData);
EM_BOOL touchcancel_handler_dpad_down(int eventType, const EmscriptenTouchEvent *touchEvent, void *userData);
EM_BOOL touchcancel_handler_dpad_left(int eventType, const EmscriptenTouchEvent *touchEvent, void *userData);
EM_BOOL touchcancel_handler_dpad_right(int eventType, const EmscriptenTouchEvent *touchEvent, void *userData);
EM_BOOL touchcancel_handler_button_a(int eventType, const EmscriptenTouchEvent *touchEvent, void *userData);
