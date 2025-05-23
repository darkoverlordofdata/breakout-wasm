#pragma once
#include <stdint.h>
#include <unistd.h>
#include <assert.h>
#include <emscripten.h>
#define GL_GLEXT_PROTOTYPES
#define EGL_EGLEXT_PROTOTYPES
#include <GLFW/glfw3.h>
#include "../libs/corefx/corefx.h"      // IWYU pragma: keep
#include "../libs/corefw/corefw.h"      // IWYU pragma: keep

extern CFClassRef Demo;

typedef struct __Demo* DemoRef;
struct DemoVtbl;
typedef enum {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
} GameState;


typedef struct __Demo {
    __CFObject obj;
    void* subclass;
    CFXGameVtblRef  virtual;
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

    GameState State;
    CFArrayRef Levels;
    int Level;
    int Lives;
} __Demo;


extern CFXResourceManagerRef ResourceManager;


extern void* Ctor(
    DemoRef this, 
    char* title, 
    int width, 
    int height);

extern method void SetKey(
    DemoRef this, 
    int key, 
    bool value);

extern method void SetState(
    DemoRef this, 
    GameState state);
    
extern method void Initialize(DemoRef this);
extern method void LoadContent(DemoRef this);
extern method void Update(DemoRef this);
extern method void Draw(DemoRef this);
extern method void Run(DemoRef this);
extern method void Start(DemoRef this);
extern method void ResetLevel(DemoRef this);
extern method void ResetPlayer(DemoRef this);
extern method void Dispose(DemoRef this);
extern method void DoCollisions(DemoRef this);

static inline DemoRef NewDemo(char* title, int width, int height)
{
    return Ctor((DemoRef)CFCreate(Demo), title, width, height);
}

