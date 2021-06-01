#include "./Kernal/Define.h"
#undef main
int main (int argc,char*argv[]){
    App app;
    while(1){ 
        app.doInput();
        app.presentScene();
    }
}