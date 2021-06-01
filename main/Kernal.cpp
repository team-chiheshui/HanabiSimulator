#include "Kernal/Define.h"

App::App(void)
{
    remainder = 0.667;
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    int windowsFlags = 0;
    int renderFlags = SDL_RENDERER_ACCELERATED;
    window = SDL_CreateWindow("HanabiSimulator",
    SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
    windowWidth,windowHeight,windowsFlags);
    rendererWindow = SDL_CreateRenderer(window,-1,renderFlags);
    //initSDL
    SDL_SetRenderDrawColor(rendererWindow,96,52,255,255);
    SDL_RenderPresent(rendererWindow);
    //prapareScene
    then = SDL_GetTicks();
}
void App::cupFrameRate(void){

    wait = 16+remainder+0.5;//四舍五入
    frameTime = SDL_GetTicks() - then;
    wait -= frameTime;
    remainder -= (int)remainder;
    remainder += 0.667;
    
    SDL_Delay(wait);
    then = SDL_GetTicks();
}
void App::presentScene(void){
    cupFrameRate();
    
    SDL_RenderPresent(rendererWindow);
    SDL_RenderClear(rendererWindow);
}
void App::doKeyDown(SDL_KeyboardEvent *event){
    if(event->repeat == 0 && event->keysym.scancode<maxKeyboardKeys){
        keyboard[event->keysym.scancode] = 1;
    }
}
void App::doKeyUp(SDL_KeyboardEvent *event){
    if(event->repeat == 0 && event->keysym.scancode<maxKeyboardKeys){
        keyboard[event->keysym.scancode] = 0;

    }
}
void App::doInput(void){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                exit(0);
                break;
            
            case SDL_KEYDOWN:
                doKeyDown(&event.key);
                break;
            
            case SDL_KEYUP:
                doKeyUp(&event.key);
                break;

            default:
                break;
        }
    }
}

SDL_Texture* loadTexture(SDL_Renderer*renderer,char*picPath){
    SDL_Texture *texture;
    texture = IMG_LoadTexture(renderer,picPath);
    return texture;
}

App::~App(void){}