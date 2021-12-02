#include <gb/gb.h>
#include <stdio.h>

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
    printf("HELLO WORLD");

}