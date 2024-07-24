// Ausführen mit ./upload.bat

// TODO: Änimäschions

#include "aelements.h"
#include <LiquidCrystal_I2C.h>
#include <stdint.h>
#include <EEPROM.h>

#define I2C_ADDR 0x27
// Die Display Adresse
#define LCD_COLUMNS 20
// Anzahl der Spalten
#define LCD_LINES 4
// Anzahl der Zeilen
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

struct Cactus {
  uint8_t x;
  bool tall;
};

uint16_t score = 0;
uint16_t highscore = 0;

uint8_t gameDelay = 200;

uint8_t playerPos = 2;
bool jumping = false;

uint8_t velocity = 0;

uint8_t selectedPlayerSkin = 0;

bool right = false;
bool down = false;
bool left = false;
bool up = false;
bool push = false;

// time after character
// is selected until game starts (miliseconds)
#define TIME_BEFORE_GAME_START 2000

#define STARTSCREEN 0
#define CHAR_SEL_SCREEN 1
#define GAME_SCREEN 2
#define END_SCREEN 3

#define HIGH_SCORE_ADDR 0

#define DISTANCE_BEFORE_CACTUS 3

// 0 = character selector
// 1 = game
// 2 = end screen
uint8_t curScreen = 0;

Cactus cacti[LCD_COLUMNS];
uint8_t cacti_amount = 0;

uint8_t cactus_distance = 0;

#define VERT_PIN A0
#define HORZ_PIN A1
#define SEL_PIN 2
#define LED_PIN 9
#define BUT_PIN 3

void setup() {
  // Start des Displays
  lcd.init();
  lcd.backlight();

  // Joystick starten
  pinMode(VERT_PIN, INPUT);
  pinMode(HORZ_PIN, INPUT);
  pinMode(SEL_PIN, INPUT_PULLUP);

  // LED
  pinMode(LED_PIN, OUTPUT);

  // Button
  pinMode(BUT_PIN, INPUT_PULLUP);
}

void loop() {
  if (curScreen==STARTSCREEN) {
    startscreen();
    handleInput();
  } else if (curScreen == CHAR_SEL_SCREEN) {
    createGeneralElements();
    handleInput();
    charSelScreen();
  } else if (curScreen == GAME_SCREEN) {
    lcd.setCursor(10, 0);
    lcd.print(EEPROM.read(HIGH_SCORE_ADDR));
    if (score % 20 == 0){
      gameDelay -= 2;
    }
    createGeneralElements();
    // Handle stuff
    handleInput();
    handleJump();
    handleCollision();
    // General tasks
    score++;
    cactus_distance++;
    listenForJoystickInput();
    // Draw tasks
    drawGround();
    drawCacti();
    drawPlayer();
    //drawScore();
    lcd.setCursor(10, 0);
    lcd.print(highscore);
    // Delay so the game is playable
    delay(gameDelay);
  } else if (curScreen == END_SCREEN) {
    createEndElements();
    handleInput();
    endscreen();
  }
}

void createGeneralElements() {
  // Erstellen der Custom Chars
  lcd.createChar(0, geist);
  lcd.createChar(1, mate);
  lcd.createChar(2, anselm);
  lcd.createChar(3, bigman);
  lcd.createChar(4, arrow);

  lcd.createChar(5, boden);
  lcd.createChar(6, grossKak);
  lcd.createChar(7, kleinKak);
}

void createEndElements() {
  lcd.createChar(0, skull);
}

void listenForJoystickInput() {
  if (up && !jumping && velocity <= 0) {
    startJump();
  }
}

void drawGround() {
  for (uint8_t x = 0; x < LCD_COLUMNS; x++) {
    lcd.setCursor(x, LCD_LINES - 1);
    lcd.write(byte(5));
  }
}

void drawCacti() {
  // Generate new cacti based on a random chance
  uint8_t rand_int = random(0, 18);

  if (cactus_distance >= DISTANCE_BEFORE_CACTUS && rand_int == 1) {
    cacti[cacti_amount].x = LCD_COLUMNS - 1;
    cacti[cacti_amount].tall = true;
    cacti_amount++;
    cactus_distance = 0;
  } else if (cactus_distance >= DISTANCE_BEFORE_CACTUS && (rand_int == 2 || rand_int == 3)) {
    cacti[cacti_amount].x = LCD_COLUMNS - 1;
    cacti[cacti_amount].tall = false;
    cacti_amount++;
    cactus_distance = 0;
  }

  // Draw cacti
  uint8_t removed_amount = 0;

  clearLine(2);
  for (uint8_t x = 0; x < cacti_amount; x++) {
    lcd.setCursor(cacti[x].x, 2);
    if (cacti[x].tall) {lcd.write(byte(6));} else {lcd.write(byte(7));}
    if (cacti[x].x <= 0) {
      removed_amount++;
    }
    cacti[x].x--;
  }

  cleanup_array(cacti, cacti_amount, removed_amount);
  cacti_amount -= removed_amount;
}

void drawPlayer() {
  lcd.setCursor(3, playerPos);
  lcd.write(byte(selectedPlayerSkin));
}

void drawScore() {
  lcd.setCursor(0, 0);
  lcd.print(score);
}

void handleInput() {
  int horz = analogRead(HORZ_PIN);
  int vert = analogRead(VERT_PIN);
  bool pressed = digitalRead(SEL_PIN) == LOW;
  if (vert <= 200) {
    down = false;
    up = true;
  } else if (vert >= 1000) {
    down = true;
    up = false;
  } else {
    down = false;
    up = false;
  }

  if (horz <= 100) {
    right = false;
    left = true;
  } else if (horz >= 1000) {
    right = true;
    left = false;
  } else {
    right = false;
    left = false;
  }

  if (pressed) {
    push = true;
  } else {
    push = false;
  }
}

void startJump() {
  jumping = true;
  velocity = 3;
  playerPos = 1;
}

void handleJump() {
  if (velocity != 0) {
    velocity -= 1;
  }

  if (velocity <= 1) {
    playerPos = 2;
    clearLine(1);
    jumping = false;
  }
}

void press() {}

void cleanup_array(Cactus *arr, uint8_t arr_len, uint8_t offset) {
  for (uint8_t i = offset; i < arr_len; i++) {
    arr[i - offset] = arr[i];
  }
}

void handleCollision() {
  if (cacti_amount != 0 && cacti[0].x == 3 && !jumping) {
    curScreen = END_SCREEN;
  }
}
void startscreen(){
  lcd.setCursor(7,1);
  lcd.print("D.INO");
  lcd.setCursor(3,2);
  lcd.print("PRESS TO START");
  for (int x = 0; x < 4; x++) {
    lcd.setCursor(0,x);
    lcd.print("|");
  }
  for (int x = 0; x < 4; x++) {
    lcd.setCursor(19,x);
    lcd.print("|");
  }
  delay(255);
  clearLineStart(2);
  if (push || left || right || up || down) {
    highscore = EEPROM.read(HIGH_SCORE_ADDR);
    curScreen=CHAR_SEL_SCREEN;
    lcd.clear();
  }
}

void endscreen() {
  lcd.clear();
  lcd.setCursor(5, 1);
  lcd.print("Game Over");
  lcd.setCursor(8, 2);
  lcd.print(score);
  lcd.setCursor(6, 3);
  lcd.print("Restart");
  lcd.setCursor(9, 0);
  lcd.write(byte(0));
  if (score > highscore) {
    highscore = score;
  }
  if (push) {
    curScreen = STARTSCREEN;
    clearLine(1);
    EEPROM.write(HIGH_SCORE_ADDR, score);
    resetAll();
    push = false;
  }
  delay(500);
}

void clearLine(uint8_t line) {
  lcd.setCursor(0, line);
  lcd.print("                     ");
}
void clearLineStart(uint8_t line) {
  lcd.setCursor(3, line);
  lcd.print("              ");
}
void resetAll() {
  lcd.clear();
  cacti_amount = 0;
  score = 0;
  playerPos = 2;
}

// CHARACTERSELECTION
typedef char *string_t;

string_t names[] = {"Geist", "Mate", "Anselm", "Big Man"};

uint8_t selCharacter = 3;

void charSelScreen() {
  // Print CharName
  lcd.setCursor(7, 0);
  lcd.print(names[selCharacter]);
  
  // Printet die auswählbaren Characters
  lcd.setCursor(7, 3);
  lcd.write(byte(0));
  lcd.setCursor(9, 3);
  lcd.write(byte(1));
  lcd.setCursor(11, 3);
  lcd.write(byte(2));
  lcd.setCursor(13, 3);
  lcd.write(byte(3));

  // Verschiebt Arrow
  if (left) {
    selCharacter--;
    if (selCharacter > 3) {
      selCharacter = 0;
    }
    lcd.setCursor(selCharacter * 2 + 7, 2);
    lcd.write(byte(4));
    lcd.clear();
  } else if (right) {
    selCharacter++;
    if (selCharacter > 3) {
      selCharacter = 3;
    }
    lcd.setCursor(selCharacter * 2 + 7, 2);
    // Draw arrow
    lcd.write(byte(4));
    lcd.clear();
  } else {
    lcd.setCursor(selCharacter * 2 + 7, 2);
    // Draw arrow
    lcd.write(byte(4));
  }

  // Select
  if (push) {
    lcd.clear();
    lcd.setCursor(6, 1);
    lcd.print("Selected");
    lcd.setCursor(10, 2);
    lcd.write(byte(selCharacter));
    selectedPlayerSkin = selCharacter;
    lcd.setCursor(7, 0);
    lcd.print(names[selCharacter]);
    delay(TIME_BEFORE_GAME_START);
    curScreen = GAME_SCREEN;
    lcd.clear();
  }

  delay(100);
}

/*
void triggerEnd() {
  bool but = digitalRead(BUT_PIN);

  if (but == LOW) {
    end = true;
  }
}
*/