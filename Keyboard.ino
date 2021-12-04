#include "Adafruit_NeoTrellisM4.h"
#include "Keyboard.h"

void loop_Keyboard() {

    while (trellis.available()) {

        keypadEvent e = trellis.read();

        // Handle key presses ..

        if (e.bit.EVENT == KEY_JUST_PRESSED) {

            uint8_t key = e.bit.KEY;

            switch (key) {

                case 1:
                    Keyboard.println("Hello Ryan!");
                    break;

                case 2:
                    break;

                case 3:
                    break;

                case 4:
                    break;

                case 5:
                    Keyboard.print("7");
                    break;

                case 6:
                    Keyboard.print("8");
                    break;

                case 7:
                    Keyboard.print("9");
                    break;

                case 13:
                    Keyboard.print("4");
                    break;

                case 14:
                    Keyboard.print("5");
                    break;

                case 15:
                    Keyboard.print("6");
                    break;

                case 21:
                    Keyboard.print("1");
                    break;

                case 22:
                    Keyboard.print("2");
                    break;

                case 23:
                    Keyboard.print("3");
                    break;

                case 29:
                    Keyboard.print(".");
                    break;

                case 30:
                    Keyboard.print("0");
                    break;

                case 31:
                    Keyboard.println("");
                    break;

            }

            lit_keys[key].r = random(0, 16);
            lit_keys[key].g = random(0, 16);
            lit_keys[key].b = random(0, 16);

            trellis.setPixelColor(key, lit_keys[key].getColorCode());

        }

    }

    // Decay lights ..

    for (uint8_t i = 0; i < 32; i++) {

        if (lit_keys[i].r > 0)          lit_keys[i].r--;
        if (lit_keys[i].g > 0)          lit_keys[i].g--;
        if (lit_keys[i].b > 0)          lit_keys[i].b--;

        trellis.setPixelColor(i, lit_keys[i].getColorCode());
    }

}