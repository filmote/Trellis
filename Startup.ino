#include "Adafruit_NeoTrellisM4.h"
#include "Keyboard.h"

// ---------------------------------------------------------------------------------------------


const uint8_t startup_T1[] = { 0, 1, 2, 3, 4, 12, 20, 28, 29, 30, 31,      24, 25, 26, 27, 28, 20, 12, 4, 5, 6, 7 }; 
const uint8_t startup_T2[] = { 31, 30, 29, 28, 27, 19, 11, 3, 2, 1, 0,     7, 6, 5, 4, 3, 11, 19, 27, 26, 25, 24 };
const uint8_t startup_T3[] = { 24, 25, 26, 27, 28, 20, 12, 4, 5, 6, 7 };
const uint8_t startup_T4[] = { 7, 6, 5, 4, 3, 11, 19, 27, 26, 25, 24 };

void loop_Startup() {

    trellis.setPixelColor(startup_T1[bannerVars.counter], 0x000000);
    trellis.setPixelColor(startup_T2[bannerVars.counter], 0x000000);

    bannerVars.counter++;

    if (bannerVars.counter >= 22) {
        mode = nextMode;
    }
    else {

        trellis.setPixelColor(startup_T1[bannerVars.counter], 0x00FF00);
        trellis.setPixelColor(startup_T2[bannerVars.counter], 0xFF0000);

    }

    delay(40);

}