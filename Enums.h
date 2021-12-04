

enum class Mode_TicTacToe : uint8_t {
    Selection,
    PlayComputer
};

struct TicTacToe {

    byte board[3][3];

    byte whosTurn = 1;
    byte playerX = 1;
    byte playerY = 1;
    byte showWinner = 0;
    byte player1Counter = 0;
    byte player2Counter = 0;

    byte menuSelection = 1;
    Mode_TicTacToe gameMode = Mode_TicTacToe::Selection;

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
    Keyboard,
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
