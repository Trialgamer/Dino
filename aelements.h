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
//STARTSCREEN
//D Top (SC)
BitTexture D_Top = {
  B11100,
  B11110,
  B11011,
  B11001,
  B11001,
  B11001,
  B11001,
  B11001
};
//D Bottom (SC)
BitTexture D_Bot = {
  B11001,
  B11001,
  B11001,
  B11001,
  B11001,
  B11011,
  B11110,
  B11100
};
//.I (SC)
BitTexture dot_i_Top = {
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011
};
BitTexture dot_i_Bot = {
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B11011,
  B11011
};
//N (SC)
BitTexture N_Top = {
  B10001,
  B10001,
  B110001,
  B11001,
  B11001,
  B11001,
  B10101,
  B10101
};
BitTexture N_Bot = {
  B10101,
  B10101,
  B10011,
  B10011,
  B10011,
  B10011,
  B10001,
  B10001
};
//O (SC)
BitTexture O_Top = {
  B01110,
  B010,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
BitTexture O_Bot = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};