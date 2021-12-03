#include <gb/gb.h>
#include <stdio.h>
#include "smiles.c"

//take in vertical blank screens..
void waiting(uint8_t numloops){
    uint8_t i;
    for(i = 0; i < numloops; i++){
        //and wait that many screen draws till the cpu is needed
        wait_vbl_done();
    }     
}

void move(uint8_t it){
    //put a smile on are chap now that he's been given the right to walk
    set_sprite_tile(0, 1);

    switch(joypad()){
        case J_LEFT:
            scroll_sprite(it,-10,0);
            break;
        case J_RIGHT:
            scroll_sprite(it,10,0);
            break;
        case J_UP:
            scroll_sprite(it,0,-10);
            break;
        case J_DOWN:
            scroll_sprite(it,0,10);
            break;
    }
    //for now lets put the cpu in low power mode
    waiting(10);
}

void main(){
    /**
     * Including stdio.h and using functions such as printf() 
     * will use a large number of the background tiles for font characters. 
     * If stdio.h is not included then that space will be available for use with other tiles instead.
     * 
     * You'll already lose 19 Tiles of vram to get the nintendo logo which is required to boot on official hardware
     * though i suppose you can overwrite those tiles once booted
     * 
     * seeing as the vram viewer has 00:7F tiles you'll have 8*16*6 tiles of vram, which is 768 tiles of 8*8 pixel tiles
     * oh, 768 is for color mode with double the vram... anyway i don't know what i'm doing so pressing onward!
     * 
     * I'd have said we should load our own font here, but then someone would come along and say why load all the alphabet too..
     * 
     **/
    printf("HELLO WORLD \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n PRESS START TO\n BEGIN MOVEMENT");
    //I've counted for you, and it is 18 lines that you get with printf..
    //any more and it scrolls up off the screen.
    
    // paste smiles main here and add a start button press wait... and get that working.

    //the smirking man has two states, frown we'll call in at index zero
    //uint8_t currentspriteindex = 0;

    //load the two faces from the smiles.c file where it's represented in assembly
    //thank Mulder for his GBTD for ma windows toolset
    set_sprite_data(0, 2, smiles);
    //set to a frown
    set_sprite_tile(0, 0);
    //set it's coordinates
    move_sprite(0, 88, 78);
    //show the sprite
    SHOW_SPRITES;
    //wait for the start button
    waitpad(J_START);
  


    while(1){
        //i've moved the joypad off to it's own method
        move(0);
   
    }

    //this while won't end, but it won't start until the previous waitpad sees the start button
    // while(1){
    //     if (currentspriteindex == 0) {
    //         currentspriteindex = 1;
    //     }
    //     else{
    //         currentspriteindex = 0;
    //     }
    //     set_sprite_tile(0, currentspriteindex);
    //     delay(1000);
    //     scroll_sprite(0, 8, 0);
    // }
    //once we've hit the start button our little chap will start smiling and scrolling along
        //he'll also go off screen for a bit but don't worry his just off panel and will come around
}