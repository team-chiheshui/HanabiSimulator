#pragma once
//硬件
#define maxKeyboardKeys 350
//窗口
#define windowWidth 800
#define windowHeight 600



//自机
#define playerSpawnX 400
#define playerSpawnY 100

//灵梦A机体数据宏
#define reimuAPictureFile "./../../UI/Replayer/ReimuA.png"
#define reimuASpeedX 4
#define reimuASpeedY 3

#define reimuABulletPictureFile "./../../UI/Replayer/ReimuABullet_Orange.png"
#define reimuABulletSpeedx 8
#define reimuABulletSpeedY 6



#include <iostream>

#ifdef __cplusplus
    extern "C"{
#endif

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

#ifdef __cplusplus
    }
#endif


#include "Kernal.h"
#include "./../Replayer/Plane.h"