#include "Define.h"

SDL_Texture* loadTexture(SDL_Renderer*,char*);

class App
{
private:
    SDL_Renderer *rendererWindow;
    SDL_Window *window;

    long then;
    float remainder;//小数部分

    long frameTime;//while循环的时间
    long wait;

    int keyboard[maxKeyboardKeys] = {0};

    void close(void);
    void doKeyUp(SDL_KeyboardEvent*);
    void doKeyDown(SDL_KeyboardEvent*);

public:

    App(void);//初始化SDL+初始化前背景内容

    void doInput(void);
    void cupFrameRate(void);
    void presentScene(void);//逻辑处理的三个函数

    SDL_Renderer* getRender(void){return rendererWindow;}
    const int* getkeyboard(void){return keyboard;};

    ~App(void);
};
