/* ***************************
 * GAMEBUINO game
 * Giovanni Gentile
 * www.projectg.it
 * The project is under CC-BY
 * Is derivated from Tap Tap game
 * from Gamebuino Academy
 * www.gamebuino.com
 */
 
 #include <Gamebuino-Meta.h>

const int LEFT = 1;
const int RIGHT = 2;
const int NO_DIRECTION = 3;
const int NUM_OF_BRICKS = 4;

int bricks[NUM_OF_BRICKS];
int arrow;
int score = 0;
int ticket = 0;

void setup() {
  gb.begin();
  bricks[0] = random(LEFT, RIGHT + 1);
  bricks[1] = random(LEFT, RIGHT + 1);
  bricks[2] = random(LEFT, RIGHT + 1);
  bricks[3] = random(LEFT, RIGHT + 1);
  
  arrow = NO_DIRECTION;
}

void loop() {
  while(!gb.update());
  // INPUTS
  
  if (gb.buttons.released(BUTTON_LEFT)) {
    arrow = LEFT;
    gb.sound.playTick();
    ticket++;
  }
  else if (gb.buttons.released(BUTTON_RIGHT)) {
    arrow = RIGHT;
    gb.sound.playTick();
    ticket++;
  }
  // LOGIC
  if (score > 0) {
    score -= 1;
  }
  if (arrow != NO_DIRECTION) {
    if (bricks[0] == arrow) {
      score += 15;
      bricks[0] = bricks[1];
      bricks[1] = bricks[2];
      bricks[2] = bricks[3];
      bricks[3] = random(LEFT, RIGHT + 1);
    }
    else {
      score = 0;
    }
    arrow = NO_DIRECTION;
  }
  // DRAW
  gb.display.clear();
  if (bricks[0] == LEFT) {
    gb.display.fillRect(20, 40, 20, 10);
  }
  else {
    gb.display.fillRect(40, 40, 20, 10);
  }
  if (bricks[1] == LEFT) {
    gb.display.drawRect(20, 30, 20, 10);
  }
  else {
    gb.display.drawRect(40, 30, 20, 10);
  }
  if (bricks[2] == LEFT) {
    gb.display.drawRect(20, 20, 20, 10);
  }
  else {
    gb.display.drawRect(40, 20, 20, 10);
  }
  if (bricks[3] == LEFT) {
    gb.display.drawRect(20, 10, 20, 10);
  }
  else {
    gb.display.drawRect(40, 10, 20, 10);
  }
  gb.display.setColor(YELLOW);
  gb.display.print(score);
  gb.display.fillRect(0, gb.display.height() - (score / 5), 4, (score/5));
  
  while (score > 199){
    gb.sound.playOK();
    for (int z = 0; z < 16; z++){
      if (gb.buttons.released(BUTTON_A)) {score = 0; ticket = 0;}
      gb.update();
      gb.display.clear();
      gb.display.setColor(RED);
      gb.display.setFontSize(2);
      gb.display.setCursor(z,15);
      gb.display.print("You Win!");

      gb.display.setFontSize(1);
      gb.display.setColor(WHITE);
      gb.display.setCursor(18,30);
      gb.display.print("Mosse: ");
      gb.display.setCursor(50,30);
      gb.display.print(ticket);
      
      gb.display.setFontSize(0.3);
      gb.display.setColor(WHITE);
      gb.display.setCursor(8,55);
      gb.display.print("Press A to game");
      delay(50);
    }if (gb.buttons.released(BUTTON_A)) {score = 0;ticket = 0;}
    for (int x = 16; x > 0; x--){
      if (gb.buttons.released(BUTTON_A)) {score = 0;ticket = 0;}
      gb.update();
      gb.display.clear();
      gb.display.setColor(RED);
      gb.display.setFontSize(2);
      gb.display.setCursor(x,15);
      gb.display.print("You Win!");
      
      gb.display.setFontSize(1);
      gb.display.setColor(WHITE);
      gb.display.setCursor(18,30);
      gb.display.print("Moves: ");
      gb.display.setCursor(50,30);
      gb.display.print(ticket);
      
      gb.display.setFontSize(0.3);
      gb.display.setColor(WHITE);
      gb.display.setCursor(8,55);
      gb.display.print("Press A to game");
      delay(50);
    }
  }
}
