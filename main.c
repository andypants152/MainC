#include <gb/gb.h>
#include "foxE.c"

void main(){
    uint8_t currentspriteindex = 0;

    SPRITES_8x16;

    set_sprite_data(0, 8, TalkingFoxE);
    set_sprite_tile(0,0);
    move_sprite(0, 88, 72);
    set_sprite_tile(1, 2);
	move_sprite(1, 88 + 8, 72);
    SHOW_SPRITES;

        while(1){
            set_sprite_tile(0, 5);

        if (currentspriteindex==5) {
            currentspriteindex = 1;
        }
        else{
            currentspriteindex = 5;
        }
        set_sprite_tile(0, currentspriteindex);
        delay(500);
    }
}