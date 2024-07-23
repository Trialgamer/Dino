// Ausführen mit ./upload.bat

// TODO: Änimäschions

#include "aelements.h"
#include <LiquidCrystal_I2C.h>
#include <stdint.h>

#define I2C_ADDR 0x27
// Die Display Adresse
#define LCD_COLUMNS 20
// Anzahl der Spalten
#define LCD_LINES 4
// Anzahl der Zeilen
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

uint16_t score = 0;

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

#define CHAR_SEL_SCREEN 0
#define GAME_SCREEN 1
#define END_SCREEN 2

// 0 = character selector
// 1 = game
// 2 = end screen
uint8_t curScreen = 0;

uint8_t cacti[LCD_COLUMNS];
uint8_t cacti_amount = 0;

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

  char_sel = true;
}

void loop() {
  createElements();

  if (curScreen == CHAR_SEL_SCREEN) {
    handleInput();
    charSelScreen();
  } else if (curScreen == GAME_SCREEN) {
    // Handle stuff
    handleInput();
    handleJump();
    handleCollision();
    // General tasks
    score++;
    listenForJoystickInput();
    // Draw tasks
    drawGround();
    drawCacti();
    drawPlayer();
    drawScore();
    // Delay so the game is playable
    delay(200);
  } else if (curScreen == END_SCREEN) {
    handleInput();
    endscreen();
  }
}

void createElements() {
  // Erstellen der Custom Chars
  lcd.createChar(0, grossKak);
  lcd.createChar(1, kleinKak);
  lcd.createChar(2, boden);
  lcd.createChar(3, skull);
  lcd.createChar(4, figurnoface);
  lcd.createChar(5, drittefigur);
  lcd.createChar(6, ardolino);
  lcd.createChar(10, boden);
  lcd.createChar(11, arrow);
  lcd.createChar(12, geist);
}

void listenForJoystickInput() {
  if (up && !jumping) {
    startJump();
  }
}

void drawGround() {
  for (uint8_t x = 0; x < LCD_COLUMNS; x++) {
    lcd.setCursor(x, LCD_LINES - 1);
    lcd.write(byte(2));
  }
}

void drawCacti() {
  // Generate new cacti based on a random chance
  uint8_t rand_int = random(0, 6);

  if (rand_int == 1) {
    cacti[cacti_amount] = LCD_COLUMNS - 1;
    cacti_amount++;
  }

  // Draw cacti
  uint8_t removed_amount = 0;

  clearLine(2);
  for (uint8_t x = 0; x < cacti_amount; x++) {
    lcd.setCursor(cacti[x], 2);
    lcd.write(0);
    if (cacti[x] <= 0) {
      removed_amount++;
    }
    cacti[x]--;
  }

  cleanup_array(cacti, cacti_amount, removed_amount);
  cacti_amount -= removed_amount;
}

void drawPlayer() {
  lcd.setCursor(3, playerPos);
  lcd.write(selectedPlayerSkin);
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

  bool pressed = digitalRead(SEL_PIN) == LOW;

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
  if (jumping) {
    velocity -= 1;
  }

  if (velocity <= 0) {
    playerPos = 2;
    clearLine(1);
    jumping = false;
  }
}

void press() {}

void cleanup_array(uint8_t *arr, uint8_t arr_len, uint8_t offset) {
  for (uint8_t i = offset; i < arr_len; i++) {
    arr[i - offset] = arr[i];
  }
}

void handleCollision() {
  if (cacti_amount != 0 && cacti[0] == 3 && !jumping) {
    curScreen = END_SCREEN;
  }
}

void endscreen() {
  lcd.clear();
  lcd.setCursor(4, 1);
  lcd.print("Game Over");
  lcd.setCursor(4, 2);
  lcd.print(score);
  lcd.setCursor(4, 3);
  lcd.print("Retry");
  lcd.setCursor(8, 0);
  lcd.write(13);
  if (push) {
    curScreen = CHAR_SEL_SCREEN;
    clearLine(1);
    resetAll();
  }
  delay(500);
}

void clearLine(uint8_t line) {
  lcd.setCursor(0, line);
  lcd.print("                     ");
}
void resetAll() {
  lcd.clear();
  cacti_amount = 0;
  score = 0;
  playerPos = 2;
}

// CHARACTERSELECTION
typedef char *string_t;

string_t names[] = {"", "", "", "Geist", "Mate", "Anselm", "Big Man"};

uint8_t selCharacter = 3;

void charSelScreen() {
  // Printet die auswählbaren Characters
  lcd.setCursor(2, 3);
  lcd.write(byte(12));
  lcd.setCursor(4, 3);
  lcd.write(byte(4));
  lcd.setCursor(6, 3);
  lcd.write(byte(5));
  lcd.setCursor(8, 3);
  lcd.write(byte(6));

  // Verschiebt Arrow
  if (left) {
    selCharacter--;
    if (selCharacter > 6) {
      selCharacter = 3;
    }
    lcd.setCursor(selCharacter * 2 - 4, 2);
    lcd.write(11);
  } else if (right) {
    selCharacter++;
    if (selCharacter > 6) {
      selCharacter = 6;
    }
    lcd.clear();
    lcd.setCursor(selCharacter * 2 - 4, 2);
    // Draw arrow
    lcd.write(11);
  } else {
    lcd.setCursor(selCharacter * 2 - 4, 2);
    // Draw arrow
    lcd.write(11);
  }

  // Print CharName
  lcd.setCursor(10, 0);
  lcd.print(names[selCharacter]);

  // Select
  if (push) {
    lcd.clear();
    lcd.setCursor(8, 1);
    lcd.print("Selected");
    lcd.setCursor(10, 2);
    lcd.write(selCharacter);
    selectedPlayerSkin = selCharacter;
    lcd.setCursor(10, 0);
    lcd.print(names[selCharacter]);
    delay(TIME_BEFORE_GAME_START);
    curScreen = GAME_SCREEN;
  }

  delay(100);
  lcd.clear();
}

/*
void triggerEnd() {
  bool but = digitalRead(BUT_PIN);

  if (but == LOW) {
    end = true;
  }
}
*/