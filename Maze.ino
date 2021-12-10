void renderGameOver() {

    while (mazeVars.counter < 12) {

        for (int8_t y = 0; y < 4; y++) {

            for (int8_t x = 0; x < mazeVars.counter - y; x++) {

                if (x< 8) {

                    uint8_t i = x + (y * 8);
                    trellis.setPixelColor(i, 0x00ff00);
                
                }

            }

        }

        delay(20);
        mazeVars.counter++;

    }

    mazeVars.counter = 0;

    while (mazeVars.counter < 12) {

        for (int8_t y = 0; y < 4; y++) {

            for (int8_t x = 0; x < mazeVars.counter - y; x++) {

                if (x< 8) {

                    uint8_t i = x + (y * 8);
                    trellis.setPixelColor(i, 0x000000);
                
                }

            }

        }

        delay(20);
        mazeVars.counter++;

    }

    if (mazeVars.level < 2) mazeVars.level++;
    mazeVars.init();
    mazeVars.mode = Mode_Maze::Init;

}

bool readPixel(uint8_t i, uint8_t j) {

    uint16_t Data = mazeVars.maze[i];
    byte Hi = (Data & 0xFF00)>>8;
    byte Lo = Data & 0x00FF;  
    
    if(j>7){
        return bitRead(Lo, 7 - (j % 8));
    }
    else{
        return bitRead(Hi, 7 - (j % 8));
    }

}


void generateMaze(){
    //return;
    bool alternate=false;
    
    for (uint8_t geni = 1; geni < mazeVars.mazeWidth-1; geni++) {
        if (!alternate){
            mazeVars.maze[geni] = 0b1100000000000001;
        }
        else{
            mazeVars.maze[geni] = 0b1101010101010101;
        }
        alternate=!alternate;
    }

    uint8_t genmod = 4;
    uint8_t genx = 0;
    uint8_t geny = 0;
    
    for (uint8_t geni = 2; geni < mazeVars.mazeWidth - 2; geni += 2) {

        for (uint8_t genj = 3; genj < mazeVars.mazeHeight - 1; genj += 2) {

            mazeVars.maze[geni] |= (0x8000 >> genj);

            do {
                uint8_t genval = (uint8_t)(random(10000) & 0x00FF) % genmod;
                genx = 0;
                geny = 0;
                if (genval == 0)geny = 1;
                if (genval == 1)genx = -1;
                if (genval == 2)genx = 1;
                if (genval == 3)geny = -1;
            }
            while ((mazeVars.maze[geni + geny] & (0x8000 >> (genj + genx)))); 
            mazeVars.maze[geni + geny] |= (0x8000 >> (genj + genx));
        }

        genmod = 3;

    }

}


void drawMazeSerial(){

    uint8_t i, j;
    bool dot;

    for(j=0;j<=mazeVars.mazeHeight;j++){
        for(i=0;i<=mazeVars.mazeWidth;i++){
    
            dot=readPixel(i,j);
    
            if (dot) {
                Serial.print("X");
            }
            else{
                Serial.print("-");
            }
        }
    
        Serial.println();
    
    }  

}


void loop_Maze(uint8_t key) {

    switch (mazeVars.mode) {

        case Mode_Maze::Init:

            generateMaze();
            drawMazeSerial();
            mazeVars.mode = Mode_Maze::Play;
            drawMaze();
            [[fallthrough]]

        case Mode_Maze::Play:

            controls(key);

            if (mazeVars.xPos == mazeVars.mazeWidth - 1 && mazeVars.yPos == mazeVars.mazeHeight - 1) {
 
                clearTrellis();
                mazeVars.counter = 0;
                mazeVars.mode = Mode_Maze::EOG;

            }
            break;

        case Mode_Maze::EOG:

            renderGameOver();
            break;

    }

    delay(10);

}



void controls(uint8_t key){

    bool wall;

    /* ------- BUTTON 1 - LEFT ------- */
    if (key == 30) {//arduboy.justPressed(LEFT_BUTTON)){
        //generateMaze();
        if(mazeVars.xPos-1 >= 0){
            wall = readPixel(mazeVars.xPos-1,mazeVars.yPos);
            if (!wall){
                --mazeVars.xPos;
                printMazeSerial();
                drawMaze();
            }
        }    
    }

    /* ------- BUTTON 2 - RIGHT ------- */
    if (key == 31){//} arduboy.justPressed(RIGHT_BUTTON)){
        if (mazeVars.xPos+1 <= mazeVars.mazeWidth+1){
            wall = readPixel(mazeVars.xPos+1,mazeVars.yPos);
            if (!wall){
                ++mazeVars.xPos;
                printMazeSerial();
                drawMaze();
            }
        }
    }

    /* ------- BUTTON 3 - UP ------- */
    if (key == 16) {//arduboy.justPressed(UP_BUTTON)){
        if (mazeVars.yPos-1 >= 2){
            wall = readPixel(mazeVars.xPos,mazeVars.yPos-1);
            if (!wall){
                --mazeVars.yPos;
                printMazeSerial();
                drawMaze();
            }
        }
    }

    /* ------- BUTTON 4 - DOWN ------- */
    if(key == 24){//arduboy.justPressed(DOWN_BUTTON)){
        if (mazeVars.yPos+1 <= mazeVars.mazeHeight){
            wall = readPixel(mazeVars.xPos,mazeVars.yPos+1);
            if (!wall){
                ++mazeVars.yPos;
                printMazeSerial();
                drawMaze();
            }
        }
    }

}


void printMazeSerial() { 

    Serial.print("printMazeSerial ");
    Serial.print(mazeVars.xPos);
    Serial.print(",");
    Serial.println(mazeVars.yPos);
    uint8_t i, j;
    bool dot;

    for(j=0;j<=mazeVars.mazeHeight;j++){

        for(i=0;i<=mazeVars.mazeWidth;i++){

            dot = readPixel(i,j);
            if (dot){
                Serial.print("X");
            }
            else if (mazeVars.xPos == i && mazeVars.yPos == j) {
                Serial.print("O");
            }
            else{
                Serial.print("-");
            }
        }
        Serial.println();
    }  
    Serial.println();
}

void clearTrellis() {

    for (uint x = 0; x < 32; x++) {
        trellis.setPixelColor(x, 0x000000);
    }

}

void drawMaze(){


    // Clear maze first ..

    clearTrellis();

    int16_t xStart = (mazeVars.xPos - 4);
    int16_t yStart = (mazeVars.yPos - 1);

    if (xStart < 0) {
        xStart = 0;
    }
    else  if (xStart >= mazeVars.mazeWidth - 8) {
        xStart = mazeVars.mazeWidth - 8;
    }

    if (yStart < 0) {
        yStart = 0;
    }
    else  if (yStart >= mazeVars.mazeHeight - 3) {
        yStart = mazeVars.mazeHeight - 3;
    }

    uint8_t x, y;
    uint8_t i = 0;

    bool wall;
    for(x=0;x<8;x++){
    
        for(y=0;y<4;y++){
    
            wall = readPixel(x + xStart,y + yStart);
            i = x + (y * 8);
    
            if(wall){
                trellis.setPixelColor(i, 0xFF0000);
            }
        }
    }  

    // Player ..

    i = (mazeVars.xPos - xStart) + ((mazeVars.yPos - yStart) * 8);
    trellis.setPixelColor(i, 0x00ff00);


    // Render buttons ..

    trellis.setPixelColor(16, 0x0000ff);
    trellis.setPixelColor(24, 0x0000ff);
    trellis.setPixelColor(30, 0x0000ff);
    trellis.setPixelColor(31, 0x0000ff);

}
