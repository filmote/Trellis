#include "Adafruit_NeoTrellisM4.h"
#include "Keyboard.h"

                                    //                               1                             2                             3                             4                             5                             6
                                    // 0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  
const uint8_t Banner_Photoshop_1[] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_Photoshop_2[] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_Photoshop_3[] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_Photoshop_4[] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_Photoshop_Len = 52;
const uint32_t Banner_Photoshop_Col = 0x00FF00;


                                    //                               1                             2                             3                             4                             5                             6
                                    // 0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  
const uint8_t Banner_TicTacToe_1[] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_TicTacToe_2[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_TicTacToe_3[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_TicTacToe_4[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_TicTacToe_Len = 52;
const uint32_t Banner_TicTacToe_Col = 0x0000FF;


                                //                               1                             2                             3                             4                             5                             6
                                // 0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  
const uint8_t Banner_Setup_1[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_Setup_2[] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_Setup_3[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_Setup_4[] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_Setup_Len = 36;
const uint32_t Banner_Setup_Col = 0xFF0000;


                               //                               1                             2                             3                             4                             5                             6
                               // 0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  
const uint8_t Banner_Maze_1[] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_Maze_2[] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_Maze_3[] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_Maze_4[] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_Maze_Len = 32;
const uint32_t Banner_Maze_Col = 0x7F7F00;


void loop_Banner() {

    switch (nextMode) {

        case Mode::Banner: break;
        
        case Mode::Photoshop:

            bannerVars.counter++;

            if (bannerVars.counter == Banner_Photoshop_Len - 8) {
                mode = nextMode;
            }
            else {

                uint8_t x2 = 0;

                for (uint8_t x = bannerVars.counter; x < bannerVars.counter + 8; x++) {
                    
                    trellis.setPixelColor(x2, 0x000000);
                    trellis.setPixelColor(x2 +  8, 0x000000);
                    trellis.setPixelColor(x2 + 16, 0x000000);
                    trellis.setPixelColor(x2 + 24, 0x000000);
                    
                    if (Banner_Photoshop_1[x] == 1)    { trellis.setPixelColor(x - bannerVars.counter, Banner_Photoshop_Col); }
                    if (Banner_Photoshop_2[x] == 1)    { trellis.setPixelColor(x - bannerVars.counter +  8, Banner_Photoshop_Col); }
                    if (Banner_Photoshop_3[x] == 1)    { trellis.setPixelColor(x - bannerVars.counter + 16, Banner_Photoshop_Col); }
                    if (Banner_Photoshop_4[x] == 1)    { trellis.setPixelColor(x - bannerVars.counter + 24, Banner_Photoshop_Col); }

                    x2++;

                }

            }

            break;

        case Mode::TicTacToe:

            bannerVars.counter++;

            if (bannerVars.counter == Banner_TicTacToe_Len - 8) {
                mode = nextMode;
            }
            else {

                uint8_t x2 = 0;

                for (uint8_t x = bannerVars.counter; x < bannerVars.counter + 8; x++) {
                    
                    trellis.setPixelColor(x2, 0x000000);
                    trellis.setPixelColor(x2 +  8, 0x000000);
                    trellis.setPixelColor(x2 + 16, 0x000000);
                    trellis.setPixelColor(x2 + 24, 0x000000);
                    
                    if (Banner_TicTacToe_1[x] == 1)    { trellis.setPixelColor(x - bannerVars.counter, Banner_TicTacToe_Col); }
                    if (Banner_TicTacToe_2[x] == 1)    { trellis.setPixelColor(x - bannerVars.counter +  8, Banner_TicTacToe_Col); }
                    if (Banner_TicTacToe_3[x] == 1)    { trellis.setPixelColor(x - bannerVars.counter + 16, Banner_TicTacToe_Col); }
                    if (Banner_TicTacToe_4[x] == 1)    { trellis.setPixelColor(x - bannerVars.counter + 24, Banner_TicTacToe_Col); }

                    x2++;

                }

            }

            break;

        case Mode::Setup:

            bannerVars.counter++;

            if (bannerVars.counter == Banner_Setup_Len - 8) {
                mode = nextMode;
            }
            else {

                uint8_t x2 = 0;

                for (uint8_t x = bannerVars.counter; x < bannerVars.counter + 8; x++) {
                    
                    trellis.setPixelColor(x2, 0x000000);
                    trellis.setPixelColor(x2 +  8, 0x000000);
                    trellis.setPixelColor(x2 + 16, 0x000000);
                    trellis.setPixelColor(x2 + 24, 0x000000);
                    
                    if (Banner_Setup_1[x] == 1)    { trellis.setPixelColor(x - bannerVars.counter, Banner_Setup_Col); }
                    if (Banner_Setup_2[x] == 1)    { trellis.setPixelColor(x - bannerVars.counter +  8, Banner_Setup_Col); }
                    if (Banner_Setup_3[x] == 1)    { trellis.setPixelColor(x - bannerVars.counter + 16, Banner_Setup_Col); }
                    if (Banner_Setup_4[x] == 1)    { trellis.setPixelColor(x - bannerVars.counter + 24, Banner_Setup_Col); }

                    x2++;

                }

            }

            break;   

        case Mode::Maze:

            bannerVars.counter++;

            if (bannerVars.counter == Banner_Maze_Len - 8) {
                mode = nextMode;
            }
            else {

                uint8_t x2 = 0;

                for (uint8_t x = bannerVars.counter; x < bannerVars.counter + 8; x++) {
                    
                    trellis.setPixelColor(x2, 0x000000);
                    trellis.setPixelColor(x2 +  8, 0x000000);
                    trellis.setPixelColor(x2 + 16, 0x000000);
                    trellis.setPixelColor(x2 + 24, 0x000000);
                    
                    if (Banner_Maze_1[x] == 1)    { trellis.setPixelColor(x - bannerVars.counter, Banner_Maze_Col); }
                    if (Banner_Maze_2[x] == 1)    { trellis.setPixelColor(x - bannerVars.counter +  8, Banner_Maze_Col); }
                    if (Banner_Maze_3[x] == 1)    { trellis.setPixelColor(x - bannerVars.counter + 16, Banner_Maze_Col); }
                    if (Banner_Maze_4[x] == 1)    { trellis.setPixelColor(x - bannerVars.counter + 24, Banner_Maze_Col); }

                    x2++;

                }

            }

            break;               

    }

    delay(50);
}