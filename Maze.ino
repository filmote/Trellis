#define MAZE_WIDTH  31
#define MAZE_HEIGHT  15




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
    
    for (uint8_t geni = 1; geni < MAZE_WIDTH-1; geni++) {
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
    
    for (uint8_t geni = 2; geni < MAZE_WIDTH - 2; geni += 2) {

        for (uint8_t genj = 3; genj < MAZE_HEIGHT - 1; genj += 2) {

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

    for(j=0;j<=MAZE_HEIGHT;j++){
        for(i=0;i<=MAZE_WIDTH;i++){
    
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

    bool wall;

    switch (mazeVars.mode) {

        case Mode_Maze::Init:

            generateMaze();
            drawMazeSerial();
            mazeVars.mode = Mode_Maze::Play;
            drawMaze();
            [[fallthrough]]

        case Mode_Maze::Play:

            controls(key);
            break;

    }

    delay(10);

}



void controls(uint8_t key){

bool wall;

    /* ------- BUTTON 1 - LEFT ------- */
    if (key == 30) {//arduboy.justPressed(LEFT_BUTTON)){
        //generateMaze();
        if(mazeVars.posx-1 >= 0){
            wall = readPixel(mazeVars.posx-1,mazeVars.posy);
            if(!wall){
            --mazeVars.posx;
                printMazeSerial();
                drawMaze();
            }
        }    
    }

    /* ------- BUTTON 2 - RIGHT ------- */
    if (key == 31){//} arduboy.justPressed(RIGHT_BUTTON)){
        if (mazeVars.posx+1 <= MAZE_WIDTH+1){
            wall = readPixel(mazeVars.posx+1,mazeVars.posy);
            if(!wall){
                ++mazeVars.posx;
                printMazeSerial();
                drawMaze();
            }
        }
    }

    /* ------- BUTTON 3 - UP ------- */
    if (key == 16) {//arduboy.justPressed(UP_BUTTON)){
        if(mazeVars.posy-1 >= 2){
            wall = readPixel(mazeVars.posx,mazeVars.posy-1);
            if(!wall){
                --mazeVars.posy;
                printMazeSerial();
                drawMaze();
            }
        }
    }

    /* ------- BUTTON 4 - DOWN ------- */
    if(key== 24){//arduboy.justPressed(DOWN_BUTTON)){
        if( mazeVars.posy+1 <= MAZE_HEIGHT){
            wall = readPixel(mazeVars.posx,mazeVars.posy+1);
            if(!wall){
                ++mazeVars.posy;
                printMazeSerial();
                drawMaze();
            }
        }
    }

}


void printMazeSerial() { 

    Serial.print("printMazeSerial ");
    Serial.print(mazeVars.posx);
    Serial.print(",");
    Serial.println(mazeVars.posy);
    uint8_t i, j;
    bool dot;

    for(j=0;j<=MAZE_HEIGHT;j++){

        for(i=0;i<=MAZE_WIDTH;i++){

            dot = readPixel(i,j);
            if (dot){
                Serial.print("X");
            }
            else if (mazeVars.posx == i && mazeVars.posy == j) {
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



void drawMaze(){


    // Clear maze first ..

    for (uint x = 0; x < 32; x++) {
        trellis.setPixelColor(x, 0x000000);
        }

    int16_t xStart = (mazeVars.posx - 4);
    int16_t yStart = (mazeVars.posy - 1);

    uint8_t xOffset, yOffset;
    Serial.print("mazeVars.posx: ");
    Serial.print(mazeVars.posx);
    Serial.print(", mazeVars.posy: ");
    Serial.print(mazeVars.posy);
    Serial.print(", xStart: ");
    Serial.print(xStart);
    Serial.print(", yStart: ");
    Serial.print(yStart);

    if (xStart < 0) {
        xOffset = -xStart;
        xStart = 0;
    }
    else  if (xStart >= MAZE_WIDTH - 8) {
        xOffset = MAZE_WIDTH - xStart;
        xStart = MAZE_WIDTH - 8;
    }
    Serial.print(", xStart: ");
    Serial.print(xStart);
    if (yStart < 0) {
        yOffset = -yStart;
        yStart = 0;
    }
    else  if (yStart >= MAZE_HEIGHT - 3) {
        yOffset = MAZE_HEIGHT - yStart;
        yStart = MAZE_HEIGHT - 3;
    }
    Serial.print(", yStart: ");
    Serial.println(yStart);

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

    i = (mazeVars.posx - xStart) + ((mazeVars.posy - yStart) * 8);
    trellis.setPixelColor(i, 0x00ff00);


    // Render buttons ..

    trellis.setPixelColor(16, 0x0000ff);
    trellis.setPixelColor(24, 0x0000ff);
    trellis.setPixelColor(30, 0x0000ff);
    trellis.setPixelColor(31, 0x0000ff);

}
