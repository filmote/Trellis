#include "Adafruit_NeoTrellisM4.h"
#include "Keyboard.h"

#define MODE_SELECTION 1
#define MODE_PLAY_COMPUTER 3

// ---------------------------------------------------------------------------------------------

void checkForWinner() {

    // Check columns to see if player has won ?

    for (int x = 0; x < 3; x = x + 1) {

        if (ticTacToeVars.board[x][0] == ticTacToeVars.whosTurn && ticTacToeVars.board[x][1] == ticTacToeVars.whosTurn && ticTacToeVars.board[x][2] == ticTacToeVars.whosTurn) {

            weHaveAWinner();
        }

    }

    // Check rows to see if player has won ?

    for (int y = 0; y < 3; y = y + 1) {

        if (ticTacToeVars.board[0][y] == ticTacToeVars.whosTurn && ticTacToeVars.board[1][y] == ticTacToeVars.whosTurn && ticTacToeVars.board[2][y] == ticTacToeVars.whosTurn) {

            weHaveAWinner();

        }

    }

    // Check diagonals to see if player has won ?

    if (ticTacToeVars.board[0][0] == ticTacToeVars.whosTurn && ticTacToeVars.board[1][1] == ticTacToeVars.whosTurn && ticTacToeVars.board[2][2] == ticTacToeVars.whosTurn) {

        weHaveAWinner();

    }

    if (ticTacToeVars.board[0][2] == ticTacToeVars.whosTurn && ticTacToeVars.board[1][1] == ticTacToeVars.whosTurn && ticTacToeVars.board[2][0] == ticTacToeVars.whosTurn) {

        weHaveAWinner();

    }

    // Is it a draw ?

    if (ticTacToeVars.showWinner == 0) {

        ticTacToeVars.showWinner = 3;

        for (int x = 0; x < 3; x = x + 1) {

            for (int y = 0; y < 3; y = y + 1) {

                if (ticTacToeVars.board[x][y] == 0) {
                    ticTacToeVars.showWinner = 0;
                }

            }

        }

    }

}

// ---------------------------------------------------------------------------------------------

void weHaveAWinner() {

    ticTacToeVars.showWinner = ticTacToeVars.whosTurn;

    if (ticTacToeVars.whosTurn == 1) {
        ticTacToeVars.player1Counter = ticTacToeVars.player1Counter + 1;
    }

    if (ticTacToeVars.whosTurn == 2){
        ticTacToeVars.player2Counter = ticTacToeVars.player2Counter + 1;
    }

}

// ---------------------------------------------------------------------------------------------

void drawBoard() {

    // Draw existing noughts and crosses ..

    for (int y = 0; y < 3; y = y + 1) {

        for (int x = 0; x < 3; x = x + 1) {

            uint8_t key = (y * 8) + x + 5;

            trellis.setPixelColor(key, 0x000000);

            if (ticTacToeVars.board[x][y] == 1) {

                trellis.setPixelColor(key, 0x0000FF);

            }

            if (ticTacToeVars.board[x][y] == 2) {

                trellis.setPixelColor(key, 0x00FF00);

            }

        }

    }

}

// ---------------------------------------------------------------------------------------------

void clearBoard() {

    // Clear the board ..

    for (int x = 0; x < 3; x++) {

        for (int y = 0; y < 3; y++) {

            ticTacToeVars.board[x][y] = 0;

        }

    }

}


// ---------------------------------------------------------------------------------------------

void loop_TicTacToe(uint8_t key) {

    if (ticTacToeVars.gameMode == Mode_TicTacToe::Selection) {
        ticTacToeVars.reset();
        clearBoard();
        ticTacToeVars.gameMode = Mode_TicTacToe::PlayComputer;
    }

    if (ticTacToeVars.gameMode == Mode_TicTacToe::PlayComputer) {
        loopPlayComputer();
    }

}


const uint8_t highlights[] = { 0, 1, 2, 3, 4, 12, 20, 28, 29, 30, 31, 24, 25, 26, 27, 28, 29, 30, 31 };

void loopPlayComputer() {


    byte someoneHadATurn = 0;

    // Draw the baord ..

    drawBoard();

    for (uint8_t i = 0; i < 19; i++) {
        if (ticTacToeVars.showWinner == 0 || i != 4) trellis.setPixelColor(highlights[i], 0x000000);
    }

    for (uint8_t i = 0; i < (ticTacToeVars.player1Counter < 4 ? ticTacToeVars.player1Counter : 4); i++) {
        trellis.setPixelColor(8 + i, 0x00007F);
    }

    for (uint8_t i = 0; i < (ticTacToeVars.player2Counter < 4 ? ticTacToeVars.player2Counter : 4); i++) {
        trellis.setPixelColor(16 + i, 0x007F00);
    }


    // Handle players buttons ..

    if (ticTacToeVars.showWinner == 0) {


        // draw Highlihgts ..

        ticTacToeVars.highlight++;
        if (ticTacToeVars.highlight == 19) ticTacToeVars.highlight = 0;


        trellis.setPixelColor(highlights[ticTacToeVars.highlight], 0x101010);


        if (key < 255) {
            
            switch (key) {

                case 5:
                    ticTacToeVars.playerX = 0;
                    ticTacToeVars.playerY = 0;
                    break;

                case 6:
                    ticTacToeVars.playerX = 1;
                    ticTacToeVars.playerY = 0;
                    break;

                case 7:
                    ticTacToeVars.playerX = 2;
                    ticTacToeVars.playerY = 0;
                    break;

                case 13:
                    ticTacToeVars.playerX = 0;
                    ticTacToeVars.playerY = 1;
                    break;

                case 14:
                    ticTacToeVars.playerX = 1;
                    ticTacToeVars.playerY = 1;
                    break;

                case 15:
                    ticTacToeVars.playerX = 2;
                    ticTacToeVars.playerY = 1;
                    break;

                case 21:
                    ticTacToeVars.playerX = 0;
                    ticTacToeVars.playerY = 2;
                    break;

                case 22:
                    ticTacToeVars.playerX = 1;
                    ticTacToeVars.playerY = 2;
                    break;

                case 23:
                    ticTacToeVars.playerX = 2;
                    ticTacToeVars.playerY = 2;
                    break;
                    
            }

            if (ticTacToeVars.board[ticTacToeVars.playerX][ticTacToeVars.playerY] == 0) {

                ticTacToeVars.board[ticTacToeVars.playerX][ticTacToeVars.playerY] = ticTacToeVars.whosTurn;
                someoneHadATurn = 1;

            }
            else {

                // arduboy.digitalWriteRGB(RED_LED, RGB_ON);
                // arduboy.delayShort(100);
                // arduboy.digitalWriteRGB(RED_LED, RGB_OFF);
            }

        }

        // Computers Turn ..

        // Can the cooputer win ?

        if (ticTacToeVars.whosTurn == 2) {

            byte moveX = 0;
            byte moveY = 0;
            byte winner = 0;
            byte block = 0;

            for (int x = 0; x < 3; x = x + 1) {

                if (ticTacToeVars.board[x][0] == 2 && ticTacToeVars.board[x][1] == 2 && ticTacToeVars.board[x][2] == 0) {
                    moveX = x;
                    moveY = 2;
                    winner = 1;
                }

                if (ticTacToeVars.board[x][0] == 2 && ticTacToeVars.board[x][1] == 0 && ticTacToeVars.board[x][2] == 2) {
                    moveX = x;
                    moveY = 1;
                    winner = 1;
                }

                if (ticTacToeVars.board[x][0] == 0 && ticTacToeVars.board[x][1] == 2 && ticTacToeVars.board[x][2] == 2) {
                    moveX = x;
                    moveY = 0;
                    winner = 1;
                }

            }

            for (int y = 0; y < 3; y = y + 1) {

                if (ticTacToeVars.board[0][y] == 2 && ticTacToeVars.board[1][y] == 2 && ticTacToeVars.board[2][y] == 0) {
                    moveX = 2;
                    moveY = y;
                    winner = 1;
                }

                if (ticTacToeVars.board[0][y] == 2 && ticTacToeVars.board[1][y] == 0 && ticTacToeVars.board[2][y] == 2) {
                    moveX = 1;
                    moveY = y;
                    winner = 1;
                }

                if (ticTacToeVars.board[0][y] == 0 && ticTacToeVars.board[1][y] == 2 && ticTacToeVars.board[2][y] == 2) {
                    moveX = 0;
                    moveY = y;
                    winner = 1;
                }

            }

            if (ticTacToeVars.board[2][0] == 2 && ticTacToeVars.board[1][1] == 2 && ticTacToeVars.board[0][2] == 0) {
                moveX = 0;
                moveY = 2;
                winner = 1;
            }

            if (ticTacToeVars.board[2][0] == 2 && ticTacToeVars.board[1][1] == 0 && ticTacToeVars.board[0][2] == 2) {
                moveX = 1;
                moveY = 1;
                winner = 1;
            }

            if (ticTacToeVars.board[2][0] == 0 && ticTacToeVars.board[1][1] == 2 && ticTacToeVars.board[0][2] == 2) {
                moveX = 2;
                moveY = 0;
                winner = 1;
            }

            if (ticTacToeVars.board[0][0] == 2 && ticTacToeVars.board[1][1] == 2 && ticTacToeVars.board[2][2] == 0) {
                moveX = 2;
                moveY = 2;
                winner = 1;
            }

            if (ticTacToeVars.board[0][0] == 2 && ticTacToeVars.board[1][1] == 0 && ticTacToeVars.board[2][2] == 2) {
                moveX = 1;
                moveY = 1;
                winner = 1;
            }

            if (ticTacToeVars.board[0][0] == 0 && ticTacToeVars.board[1][1] == 2 && ticTacToeVars.board[2][2] == 2) {
                moveX = 0;
                moveY = 0;
                winner = 1;
            }

            if (winner == 1) {

                ticTacToeVars.board[moveX][moveY] = 2;
                someoneHadATurn = 1;

            }
            else {

                for (int x = 0; x < 3; x = x + 1) {

                    if (ticTacToeVars.board[x][0] == 1 && ticTacToeVars.board[x][1] == 1 && ticTacToeVars.board[x][2] == 0) {
                        moveX = x;
                        moveY = 2;
                        block = 1;
                    }

                    if (ticTacToeVars.board[x][0] == 1 && ticTacToeVars.board[x][1] == 0 && ticTacToeVars.board[x][2] == 1) {
                        moveX = x;
                        moveY = 1;
                        block = 1;
                    }

                    if (ticTacToeVars.board[x][0] == 0 && ticTacToeVars.board[x][1] == 1 && ticTacToeVars.board[x][2] == 1) {
                        moveX = x;
                        moveY = 0;
                        block = 1;
                    }

                }

                for (int y = 0; y < 3; y = y + 1) {

                    if (ticTacToeVars.board[0][y] == 1 && ticTacToeVars.board[1][y] == 1 && ticTacToeVars.board[2][y] == 0) {
                        moveX = 2;
                        moveY = y;
                        block = 1;
                    }

                    if (ticTacToeVars.board[0][y] == 1 && ticTacToeVars.board[1][y] == 0 && ticTacToeVars.board[2][y] == 1) {
                        moveX = 1;
                        moveY = y;
                        block = 1;
                    }

                    if (ticTacToeVars.board[0][y] == 0 && ticTacToeVars.board[1][y] == 1 && ticTacToeVars.board[2][y] == 1) {
                        moveX = 0;
                        moveY = y;
                        block = 1;
                    }

                }

                if (ticTacToeVars.board[2][0] == 1 && ticTacToeVars.board[1][1] == 1 && ticTacToeVars.board[0][2] == 0) {
                    moveX = 0;
                    moveY = 2;
                    block = 1;
                }

                if (ticTacToeVars.board[2][0] == 1 && ticTacToeVars.board[1][1] == 0 && ticTacToeVars.board[0][2] == 1) {
                    moveX = 1;
                    moveY = 1;
                    block = 1;
                }

                if (ticTacToeVars.board[2][0] == 0 && ticTacToeVars.board[1][1] == 1 && ticTacToeVars.board[0][2] == 1) {
                    moveX = 2;
                    moveY = 0;
                    block = 1;
                }

                if (ticTacToeVars.board[0][0] == 1 && ticTacToeVars.board[1][1] == 1 && ticTacToeVars.board[2][2] == 0) {
                    moveX = 2;
                    moveY = 2;
                    block = 1;
                }

                if (ticTacToeVars.board[0][0] == 1 && ticTacToeVars.board[1][1] == 0 && ticTacToeVars.board[2][2] == 1) {
                    moveX = 1;
                    moveY = 1;
                    block = 1;
                }

                if (ticTacToeVars.board[0][0] == 0 && ticTacToeVars.board[1][1] == 1 && ticTacToeVars.board[2][2] == 1) {
                    moveX = 0;
                    moveY = 0;
                    block = 1;
                }

                if (block == 1) {

                    ticTacToeVars.board[moveX][moveY] = 2;
                    someoneHadATurn = 1;

                }
                else {

                    while (someoneHadATurn == 0)  {

                        byte randomX = random(0, 3); // a random number between 0 and 2
                        byte randomY = random(0, 3); // a random number between 0 and 2

                        if (ticTacToeVars.board[randomX][randomY] == 0) {

                            ticTacToeVars.board[randomX][randomY] = 2;
                            someoneHadATurn = 1;

                        }

                    }

                }

            }

        }

        if (someoneHadATurn == 1) {

            checkForWinner();

            // If the current player has not won then it's the other players turn ..

            if (ticTacToeVars.showWinner == 0) {

                if (ticTacToeVars.whosTurn == 1) {
                    ticTacToeVars.whosTurn = 2;
                }
                else {
                    ticTacToeVars.whosTurn = 1;
                }

            }

        }

    }

    // Should we show the winner or draw message ?

    if (ticTacToeVars.showWinner != 0) {

        if (ticTacToeVars.showWinner == 1 or ticTacToeVars.showWinner == 2) {

            trellis.setPixelColor(4, 0xff0000);
            // winner

        }
        else {

            trellis.setPixelColor(4, 0xff00ff);
            // Draw
        }

        if (key == 4) {

            ticTacToeVars.showWinner = 0;
            trellis.setPixelColor(4, 0x000000);
            clearBoard();

            // The loser can start the next game ..

            if (ticTacToeVars.whosTurn == 1) {
                ticTacToeVars.whosTurn = 2;
            }
            else {
                ticTacToeVars.whosTurn = 1;
            }

        }

    }

}