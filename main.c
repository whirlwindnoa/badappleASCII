#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <unistd.h>

char charset[] = """ -':_,^=;><+!rc*/z?sLTv)J7(|Fi{C}fI31tlu[neoZ5Yxjya]2ESwqkP6h9d4VpOGbUAKXHm8RD#$Bg0MNWQ%&@""";

// gets ascii character according to brightness
char bgetch(int b) {
    int n = sizeof(charset)-10;
    int step = 255/n;
    
    return charset[b/step];
}

int main() {
    initscr();

    SDL_Init(SDL_INIT_VIDEO);

    for (int i = 0; i < 6572; i++) {
        char path[15];
        sprintf(path, "frames/%04d.bmp", i+1);

        SDL_Surface* image = SDL_LoadBMP(path);

        if (!image) {
            printf("Error occured while reading the image\n");
            SDL_Quit();
            return 0;
        }

        int width = image->w;
        int height = image->h;

        Uint8* pixels = (Uint8*)image->pixels;

        clear();
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int b = pixels[y * width + x];

                char ch = bgetch(b);
                printw("%c", ch);
            }
            printw("\n");
        }
        refresh();
        usleep(33400);

        SDL_FreeSurface(image);
    }

    SDL_Quit();
    endwin();
    return 0;
}