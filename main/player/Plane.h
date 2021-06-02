#include "./../Kernal/Define.h"
class Plane{
protected:
SDL_Texture*texture;
int width,height;
int speedX,speedY;
int positionnWidth,positionHeight;
friend SDL_Texture* loadTexture(SDL_Renderer*,char*);
public:
Plane();
virtual void move(void) = 0;
//virtual void move(char*);//暂定
virtual void playerFireBullet(void) = 0;
virtual void logic(void) = 0;
virtual void draw(void) = 0;
~Plane();
};