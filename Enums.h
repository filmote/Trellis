

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

        return r * 256 * 256 * 4 + g * 256 * 4 + b * 4;

    }

};


enum class Mode : uint8_t {
    Banner,
    Photoshop,
    TicTacToe,
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
