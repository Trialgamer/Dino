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
//D Top (SC)
BitTexture D_Top = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
//D Top (SC)
BitTexture D_Bot = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
//.I (SC)
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
