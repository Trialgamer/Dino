// Ausführen mit ./upload.bat

#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27
//Die Display Adresse
#define LCD_COLUMNS 20
//Anzahl der Spalten
#define LCD_LINES 4
//Anzahl der Zeilen
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

#define VERT_PIN A0
#define HORZ_PIN A1
#define SEL_PIN 2
const int LED_PIN = 9
const int BUT_PIN = 3;

//Großer Kaktus
byte grossKak[] = {
  B00100,
  B10100,
  B10100,
  B01101,
  B00101,
  B00110,
  B00100,
  B00100
};
//Kleiner Kaktus
byte kleinKak[] = {
  B00000,
  B00000,
  B00000,
  B00100,
  B00101,
  B10110,
  B01100,
  B00100,
};
//Boden
byte boden[] = {
  B11111,
  B10110,
  B00101,
  B01000,
  B00010,
  B10000,
  B00000,
  B00000,
};
void setup() {
// Start des Displays

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Alesx gib a Ruhe");
  

  //Joystick starten
  pinMode(VERT_PIN, INPUT);
  pinMode(HORZ_PIN, INPUT);
  pinMode(SEL_PIN, INPUT_PULLUP);

  //LED
  pinMode(LED_PIN, OUTPUT);

  //Button
  pinMode(BUT_PIN, INPUT_PULLUP);

  //Erstellen der Custom Chars
  lcd.createChar(0, grossKak);
  lcd.createChar(1, kleinKak);
  lcd.createChar(2, boden);
  
  //TEst
  lcd.setCursor(3, 0);
  lcd.write(0);
  lcd.setCursor(3, 1);
  lcd.write(1);
  lcd.setCursor(3, 2);
  lcd.write(2);
}

void jump() {
    if(digitalRead(BUT_PIN) == LOW) {
    digitalWrite(LED_PIN, HIGH);
  }
  else {
    digitalWrite(LED_PIN, LOW);
  }
}

void loop() {
    
}
void punktestand(){
    
}