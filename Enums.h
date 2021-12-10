
enum class Mode_Maze : uint8_t {
    Init,
    Play,
    EOG,
};

#define __MAZE_WIDTH  31
#define __MAZE_WIDTH  15
#define __MAZE_HEIGHT  15

struct Maze {

    uint8_t level = 0;
    uint8_t counter = 0;
    int8_t xPos = 0;
    int8_t yPos = 2; // Where you are in the Maze

    int8_t mazeWidth = 15;
    int8_t mazeHeight = 15;

    Mode_Maze mode = Mode_Maze::Init;

    uint16_t maze[33] = {
        0b1100000000000001,
        0b1101010101010101,
        0b1100000000000001,
        0b1101010101010101,
        0b1100000000000001,
        0b1101010101010101,
        0b1100000000000001,
        0b1101010101010101,
        0b1100000000000001,
        0b1101010101010101,
        0b1100000000000001,
        0b1101010101010101,
        0b1100000000000001,
        0b1101010101010101,
        0b1100000000000001,
        0b1101010101010101,
        0b1100000000000001,
        0b1101010101010101,
        0b1100000000000001,
        0b1111111111111101,
        0b1100000000000101,//exit
        0b0000000000000000
    };

    void init() {

        switch (level) {

            case 0:
                this->mazeWidth = 15;
                this->maze[0] = 0b1101111111111111;
                this->maze[1] = 0b1100000000000001;
                this->maze[2] = 0b1101010101010101;
                this->maze[3] = 0b1100000000000001;
                this->maze[4] = 0b1101010101010101;
                this->maze[5] = 0b1100000000000001;
                this->maze[6] = 0b1101010101010101;
                this->maze[7] = 0b1100000000000001;
                this->maze[8] = 0b1101010101010101;
                this->maze[9] = 0b1100000000000001;
                this->maze[10] = 0b1101010101010101;
                this->maze[11] = 0b1100000000000001;
                this->maze[12] = 0b1101010101010101;
                this->maze[13] = 0b1100000000000001;
                this->maze[14] = 0b1111111111111101;
                this->maze[15] = 0b1100000000000101;//exit
                this->maze[16] = 0b0000000000000000;
                break;

            case 1:
                this->mazeWidth = 23;
                this->maze[0] = 0b1101111111111111;
                this->maze[1] = 0b1100000000000001;
                this->maze[2] = 0b1101010101010101;
                this->maze[3] = 0b1100000000000001;
                this->maze[4] = 0b1101010101010101;
                this->maze[5] = 0b1100000000000001;
                this->maze[6] = 0b1101010101010101;
                this->maze[7] = 0b1100000000000001;
                this->maze[8] = 0b1101010101010101;
                this->maze[9] = 0b1100000000000001;
                this->maze[10] = 0b1101010101010101;
                this->maze[11] = 0b1100000000000001;
                this->maze[12] = 0b1101010101010101;
                this->maze[13] = 0b1100000000000001;
                this->maze[14] = 0b1101010101010101;
                this->maze[15] = 0b1100000000000001;
                this->maze[16] = 0b1101010101010101;
                this->maze[17] = 0b1100000000000001;
                this->maze[18] = 0b1101010101010101;
                this->maze[19] = 0b1100000000000001;
                this->maze[20] = 0b1101010101010101;
                this->maze[21] = 0b1100000000000001;
                this->maze[22] = 0b1111111111111101;
                this->maze[23] = 0b1100000000000101;//exit
                this->maze[24] = 0b0000000000000000;
                break;

            case 2:
                this->mazeWidth = 31;
                this->maze[0] = 0b1101111111111111;
                this->maze[1] = 0b1100000000000001;
                this->maze[2] = 0b1101010101010101;
                this->maze[3] = 0b1100000000000001;
                this->maze[4] = 0b1101010101010101;
                this->maze[5] = 0b1100000000000001;
                this->maze[6] = 0b1101010101010101;
                this->maze[7] = 0b1100000000000001;
                this->maze[8] = 0b1101010101010101;
                this->maze[9] = 0b1100000000000001;
                this->maze[10] = 0b1101010101010101;
                this->maze[11] = 0b1100000000000001;
                this->maze[12] = 0b1101010101010101;
                this->maze[13] = 0b1100000000000001;
                this->maze[14] = 0b1101010101010101;
                this->maze[15] = 0b1100000000000001;
                this->maze[16] = 0b1101010101010101;
                this->maze[17] = 0b1100000000000001;
                this->maze[18] = 0b1101010101010101;
                this->maze[19] = 0b1100000000000001;
                this->maze[20] = 0b1101010101010101;
                this->maze[21] = 0b1100000000000001;
                this->maze[22] = 0b1101010101010101;
                this->maze[23] = 0b1100000000000001;
                this->maze[24] = 0b1101010101010101;
                this->maze[25] = 0b1100000000000001;
                this->maze[26] = 0b1101010101010101;
                this->maze[27] = 0b1100000000000001;
                this->maze[28] = 0b1101010101010101;
                this->maze[29] = 0b1100000000000001;
                this->maze[30] = 0b1111111111111101;
                this->maze[31] = 0b1100000000000101;//exit
                this->maze[32] = 0b0000000000000000;
                break;                

        }

        this->xPos = 0, 
        this->yPos = 2;
        this->mode = Mode_Maze::Init;

    }

};


enum class Mode_TicTacToe : uint8_t {
    Selection,
    PlayComputer
};

struct Banner {
    uint8_t counter = 0;
};

struct TicTacToe {

    byte board[3][3];

    uint8_t whosTurn = 1;
    uint8_t playerX = 1;
    uint8_t playerY = 1;
    uint8_t showWinner = 0;
    uint8_t player1Counter = 0;
    uint8_t player2Counter = 0;
    uint8_t highlight = 0;

    Mode_TicTacToe gameMode = Mode_TicTacToe::Selection;

    void reset() {

        for (uint8_t y = 0; y < 3; y++) {

            for (uint8_t x = 0; x < 3; x++) {
                
                this->board[x][y] = 0;
                
            }

        }

        this->playerX = 1;
        this->playerY = 1;
        this->showWinner = 0;
        this->player1Counter = 0;
        this->player2Counter = 0;

        this->gameMode = Mode_TicTacToe::Selection;

    }

};

struct RGB {

    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;

    uint32_t getColorCode() {

        return r * 256 * 256 + g * 256 + b;

    }

};


enum class Mode : uint8_t {
    Startup,
    Setup,
    Banner,
    Photoshop,
    TicTacToe,
    Maze,
};

inline Mode &operator++(Mode &c ) {
    c = static_cast<Mode>( (static_cast<uint8_t>(c) + 1) % 4 );
    return c;
}

inline Mode operator++(Mode &c, int ) {
    Mode result = c;
    ++c;
    return result;
}

inline Mode &operator--(Mode &c ) {
    if (static_cast<uint8_t>(c) > 0) {
        c = static_cast<Mode>( (static_cast<uint8_t>(c) - 1) % 4 );
    }
    else {
        c = static_cast<Mode>( 3 );
    }
    return c;
}

inline Mode operator--(Mode &c, int ) {
    Mode result = c;
    --c;
    return result;
}
