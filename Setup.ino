#include "Adafruit_NeoTrellisM4.h"
#include "Keyboard.h"

// ---------------------------------------------------------------------------------------------

void loop_Setup() {

    trellis.setPixelColor(2, 0xFF0000);
    trellis.setPixelColor(10, 0xFF0000);
    trellis.setPixelColor(17, 0xFF0000);
    trellis.setPixelColor(18, 0xFF0000);
    trellis.setPixelColor(19, 0xFF0000);
    trellis.setPixelColor(26, 0xFF0000);


    trellis.setPixelColor(5, 0x00ff00);
    trellis.setPixelColor(12, 0x00ff00);
    trellis.setPixelColor(13, 0x00ff00);
    trellis.setPixelColor(14, 0x00ff00);
    trellis.setPixelColor(21, 0x00ff00);
    trellis.setPixelColor(29, 0x00ff00);


   if (key == 2 || key == 10 || key == 17 || key == 18 || key == 19 || key == 26) {

       if (brightness > 5) brightness = brightness - 5;
       trellis.setBrightness(brightness);

   }


   if (key == 5 || key == 12 || key == 13 || key == 14 || key == 21 || key == 29) {

       if (brightness < 120) brightness = brightness + 5;
       trellis.setBrightness(brightness);

   }
Serial.println(brightness);

    delay(40);

}