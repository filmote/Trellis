#include "Adafruit_NeoTrellisM4.h"
#include "Keyboard.h"

                                    //                               1                             2                             3                             4                             5                             6
                                    // 0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  
const uint8_t Banner_Photoshop_1[] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_Photoshop_2[] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_Photoshop_3[] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_Photoshop_4[] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_Photoshop_Len = 52;
const uint32_t Banner_Photoshop_Col = 0x00FF00;


                                    //                               1                             2                             3                             4                             5                             6
                                    // 0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  
const uint8_t Banner_TicTacToe_1[] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_TicTacToe_2[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_TicTacToe_3[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_TicTacToe_4[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, };
const uint8_t Banner_TicTacTow_Len = 52;
const uint32_t Banner_TicTacTow_Col = 0x0000FF;


void loop_Banner() {

    switch (nextMode) {

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

            if (bannerVars.counter == Banner_TicTacTow_Len - 8) {
                mode = nextMode;
            }
            else {

                uint8_t x2 = 0;

                for (uint8_t x = bannerVars.counter; x < bannerVars.counter + 8; x++) {
                    
                    trellis.setPixelColor(x2, 0x000000);
                    trellis.setPixelColor(x2 +  8, 0x000000);
                    trellis.setPixelColor(x2 + 16, 0x000000);
                    trellis.setPixelColor(x2 + 24, 0x000000);
                    
                    if (Banner_TicTacToe_1[x] == 1)    { trellis.setPixelColor(x - bannerVars.counter, Banner_TicTacTow_Col); }
                    if (Banner_TicTacToe_2[x] == 1)    { trellis.setPixelColor(x - bannerVars.counter +  8, Banner_TicTacTow_Col); }
                    if (Banner_TicTacToe_3[x] == 1)    { trellis.setPixelColor(x - bannerVars.counter + 16, Banner_TicTacTow_Col); }
                    if (Banner_TicTacToe_4[x] == 1)    { trellis.setPixelColor(x - bannerVars.counter + 24, Banner_TicTacTow_Col); }

                    x2++;

                }

            }

            break;
    }

    delay(50);
}