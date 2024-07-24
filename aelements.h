typedef uint8_t BitTexture[];

// Alle animationen & andere bilder
// Datei braucht 'a', damit variablen benutzbar sind
BitTexture grossKak = {
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
BitTexture kleinKak = {
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
BitTexture boden = {
  B11111,
  B10110,
  B00101,
  B01000,
  B00010,
  B10000,
  B00000,
  B00000,
};
//Select Pfeil
BitTexture arrow = {
  B00100,
  B00100,
  B00100,
  B00100,
  B11111,
  B01110,
  B00100,
  B00000
};
//Geist
BitTexture geist = {
  B01110,  
  B11111,  
  B10101,  
  B11111,  
  B11111,  
  B10101,
  B10101,
  B00000
};
//Geist Laufanimation
BitTexture laufanimation2 = {  
  B01110,  
  B11111,  
  B10101,  
  B11111,  
  B11111,  
  B01010,
  B10100,
  B00000
};
//Geist Springanimation
BitTexture geistsprung = {  
  B11111,  
  B11111,  
  B10101,  
  B11111,  
  B11111,  
  B10101,
  B00000,
  B00000
};
//1.Figur(die ohne Gesicht)
BitTexture mate = {  
  B01110,
  B10001,  
  B10001,  
  B10001,  
  B01110, 
  B11011,
  B01110,
  B11011
};
//Laufanimation 1
BitTexture laufanimationka = {  
  B01110,  
  B10001,  
  B10001,  
  B10001,  
  B01110,  
  B11011,
  B01110,
  B11001
};
//Laufanimation 2
BitTexture cus = {  
  B01110,  
  B10001,  
  B10001,  
  B10001,  
  B01110,  
  B11011,
  B01110,
  B10011
};
//Springanimation
BitTexture laufmonika = {  
  B01110,  
  B10001,  
  B10001,  
  B10001,  
  B01110,  
  B11011,
  B11111,
  B00000
};
//3.Figur
BitTexture anselm = {  
  B11111,  
  B10101,  
  B11111,  
  B01110,  
  B11111,  
  B11111,
  B01010,
  B01010
};
//Laufanimation 1
BitTexture laufanimation31 = {  
  B11111,  
  B10101,  
  B11111,  
  B01110,
  B11111,  
  B01111,
  B01010,
  B11001
};
//Laufanimation 2
BitTexture laufanimation32 = {  
  B11111,  
  B10101,  
  B11111,  
  B01110,  
  B11111,  
  B11110,
  B01011,
  B10001
};
//Springanimation
BitTexture sprunganimation3 = {  
  B11111,  
  B10101,  
  B11111,  
  B01110,  
  B11111,  
  B11111,
  B01010,
  B10100
};
//4.Figur
BitTexture bigman = {  
  B11111,  
  B10101,  
  B11111,  
  B11111,  
  B11111,  
  B01010,
  B01010,
  B11011
};
//Laufanimation 1 von 4 Figur
BitTexture Laufgitti = {  
  B11111,  
  B10101,  
  B11111,  
  B11111,  
  B11111,  
  B01010,
  B01001,
  B10001
};
//Laufanimation 2 von der 4. Figur
BitTexture laufbertrut = {  
  B11111,  
  B10101,  
  B11111,  
  B11111,  
  B11111,  
  B01010,
  B01010,
  B10010
};
//Sprunganimation von der 4. Figur
BitTexture Sprungbrute = {  
  B11111,  
  B10101,  
  B11111,  
  B11111,  
  B11111,  
  B01010,
  B11011,
  B00000
};
//Totenschaedel
BitTexture skull = {  
  B00000,  
  B01110,  
  B11111,  
  B10101,  
  B11011,  
  B01110,
  B01110,
  B00000
};
//.I (Startscreen)
BitTexture dot_i = {
  B00111,
  B00010,
  B00010,
  B00010,
  B00010,
  B00010,
  B00010,
  B10111
};