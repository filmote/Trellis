#include "Adafruit_NeoTrellisM4.h"
#include "Keyboard.h"
#include "Enums.h"
#include <FlashStorage_SAMD.h>

Adafruit_NeoTrellisM4 trellis = Adafruit_NeoTrellisM4();
RGB lit_keys[32];
TicTacToe ticTacToeVars;
Banner bannerVars;
Maze mazeVars;

Mode mode = Mode::Startup; 
Mode nextMode = Mode::Photoshop;
uint8_t key = 255;
uint8_t brightness = 80;
uint16_t storedAddress = 0;

void setup(){

    EEPROM.get(storedAddress, brightness);

    if (brightness < 5 || brightness > 120) {
        brightness = 80;
        EEPROM.put(storedAddress, brightness);
    }
    
    Serial.begin(115200);

    trellis.begin();
    trellis.setBrightness(brightness);


    for (int i=0; i<trellis.num_keys(); i++) {
        lit_keys[i].r = 0;
        lit_keys[i].b = 0;
        lit_keys[i].g = 0;
    }

    Keyboard.begin();
    bannerVars.counter = 255;


}
  
void loop() {

    trellis.tick();

    while (trellis.available()) {

        keypadEvent e = trellis.read();


        // Handle key presses ..

        if (e.bit.EVENT == KEY_JUST_PRESSED) {

            key = e.bit.KEY; 

            if (key == 0) {

                switch (mode) {

                    case Mode::Setup:
                        nextMode = Mode::Photoshop;
                        mode = Mode::Banner;
                        bannerVars.counter = 0;
                        break;

                    case Mode::Photoshop:
                        ticTacToeVars.gameMode = Mode_TicTacToe::Selection;
                        nextMode = Mode::TicTacToe;
                        mode = Mode::Banner;
                        bannerVars.counter = 0;
                        break;

                    case Mode::TicTacToe:
                        nextMode = Mode::Maze;
                        mode = Mode::Banner;
                        mazeVars.level = 0;
                        mazeVars.init();
                        bannerVars.counter = 0;
                        break;

                    case Mode::Maze:
                        nextMode = Mode::Setup;
                        mode = Mode::Banner;
                        bannerVars.counter = 0;
                        break;

                    default: break;

                }

            }

        }

    }


    // Do stuff!

    switch (mode) {

        case Mode::Startup:
            loop_Startup();
            break;

        case Mode::Setup:
            loop_Setup();
            break;

        case Mode::Banner:
            loop_Banner();
            break;

        case Mode::Photoshop:
            loop_Photoshop(key);
            break;

        case Mode::TicTacToe:
            loop_TicTacToe();
            break;

        case Mode::Maze:
            loop_Maze(key);
            break;

    }

    key = 255;
    delay(10);
  
}
