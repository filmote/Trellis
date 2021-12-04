#include "Adafruit_NeoTrellisM4.h"
#include "Keyboard.h"
#include "Enums.h"

#define BRIGHTNESS 80

Adafruit_NeoTrellisM4 trellis = Adafruit_NeoTrellisM4();
RGB lit_keys[32];
Mode mode = Mode::Keyboard;
TicTacToe ticTacToeVars;

void setup(){
//  Serial.begin(115200);
    
  trellis.begin();
  trellis.setBrightness(BRIGHTNESS);

  
  for (int i=0; i<trellis.num_keys(); i++) {
    lit_keys[i].r = 0;
    lit_keys[i].b = 0;
    lit_keys[i].g = 0;
  }

  Keyboard.begin();
  
}
  
void loop() {

    trellis.tick();

    while (trellis.available()) {

        keypadEvent e = trellis.read();


        // Handle key presses ..

        if (e.bit.EVENT == KEY_JUST_PRESSED) {

            uint8_t key = e.bit.KEY; 

            switch (key) {

                case 0:
                    ticTacToeVars.gameMode = Mode_TicTacToe::Selection;
                    mode++;
                    break;

            }

            lit_keys[key].r = random(0, 16);
            lit_keys[key].g = random(0, 16);
            lit_keys[key].b = random(0, 16);

            trellis.setPixelColor(key, lit_keys[key].getColorCode());

        }

    }


    // Do stuff!

    switch (mode) {

        case Mode::Keyboard:
            loop_Keyboard();
            break;

        case Mode::TicTacToe:
            loop_TicTacToe();
            break;

    }


  delay(10);
  
}
