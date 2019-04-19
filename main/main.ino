/*********************************************************************
This is an example sketch for our Monochrome Nokia 5110 LCD Displays

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/338

These displays use SPI to communicate, 4 or 5 pins are required to
interface

Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// Software SPI (slower updates, more flexible pin options):
// pin 13 - Serial clock out (SCLK)
// pin 11 - Serial data out (DIN)
// pin 2 - Data/Command select (D/C)
// pin 7 - LCD chip select (CS)
// pin 8 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(13, 11, 2, 7, 8);

// Hardware SPI (faster, but must use certain hardware pins):
// SCK is LCD serial clock (SCLK) - this is pin 13 on Arduino Uno
// MOSI is LCD DIN - this is pin 11 on an Arduino Uno
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
// Adafruit_PCD8544 display = Adafruit_PCD8544(5, 4, 3);
// Note with hardware SPI MISO and SS pins aren't used but will still be read
// and written to during SPI transfer.  Be careful sharing these pins!

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16

static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

void setup()   {
  Serial.begin(9600);

  display.begin();
  // init done

  // you can change the contrast around to adapt the display
  // for the best viewing!
  display.setContrast(55);

  display.clearDisplay();   // clears the screen and buffer

  float ar1[5]={0.1,0.3,0.5,0.7,0.9};
  float ar2[5]={0.1,0.3,0.5,0.7,0.9};

//  if((int)(ar1[0]*10)%10==1)
//    p_zero(20,20);

  drawY_Axis();
  drawX_Axis();
  
//  drawY_Axis_Values();
  drawX_Axis_Values();
  drawY_Axis_ValuesNew(ar1);

//  int a[]={20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,40,41,42,43,44,45,46,47,48};
//  int b[]={10,11,12,13,14,15,16,17,18,20,21,21,21,22,22,22,23,24,24,24,25,25,25,25,26,26,26,26};
//  
//   for(int i=0;i<25;i++){
//   display.drawPixel(a[i], b[i], BLACK);
// }
  
  display.display();
  delay(2000);
  

}


void loop() {
  
}


void drawY_Axis(void) {
  //Arrow head Y axis
  display.drawPixel(10, 1, BLACK);
  display.drawPixel(12, 1, BLACK);
  display.drawPixel(9, 2, BLACK);
  display.drawPixel(13, 2, BLACK);

  //the line
  for(int i=0;i<40;i++){
    display.drawPixel(11, i, BLACK);
    if(i%7==0 && i!=0){
      display.drawPixel(10, i, BLACK);
      display.drawPixel(12, i, BLACK);
    }
  }

  // (V)
  display.drawPixel(1,0, BLACK);
  display.drawPixel(0,1, BLACK);
  display.drawPixel(0,2, BLACK);
  display.drawPixel(1,3, BLACK);

  display.drawPixel(3,0, BLACK);
  display.drawPixel(3,1, BLACK);
  display.drawPixel(3,2, BLACK);
  display.drawPixel(4,3, BLACK);
  display.drawPixel(5,2, BLACK);
  display.drawPixel(5,1, BLACK);
  display.drawPixel(5,0, BLACK);
  
  display.drawPixel(7,0, BLACK);
  display.drawPixel(8,1, BLACK);
  display.drawPixel(8,2, BLACK);
  display.drawPixel(7,3, BLACK);

  p_zero(0,43);
  p_dot(4,43);
  p_zero(6,43);
}


void drawX_Axis(void) {
  //Arrow head X axis
  display.drawPixel(82,39, BLACK); 
  display.drawPixel(82,41, BLACK); 
  display.drawPixel(81,38, BLACK); 
  display.drawPixel(81,42, BLACK); 
  
  //the line
  for(int i=11;i<84;i++){
    display.drawPixel(i, 40, BLACK);
    if(i%11==0 && i!=11 ){
      display.drawPixel(i, 41, BLACK);
      display.drawPixel(i, 39, BLACK);
    }
    
  }

  // (I)
  display.drawPixel(82,47, BLACK); 
  display.drawPixel(83,46, BLACK); 
  display.drawPixel(83,45, BLACK); 
  display.drawPixel(82,44, BLACK);

  display.drawPixel(80,47, BLACK); 
  display.drawPixel(80,44, BLACK); 
  display.drawPixel(79,47, BLACK); 
  display.drawPixel(79,46, BLACK); 
  display.drawPixel(79,45, BLACK); 
  display.drawPixel(79,44, BLACK); 
  display.drawPixel(78,47, BLACK); 
  display.drawPixel(78,44, BLACK); 

  display.drawPixel(76,47, BLACK); 
  display.drawPixel(75,46, BLACK); 
  display.drawPixel(75,45, BLACK); 
  display.drawPixel(76,44, BLACK);
}

void drawY_Axis_ValuesNew(float a[]) {
  
  for(int i=0;i<5;i++){
    if(i==0){
      switch((int)a[i]){
        case 0: p_zero(0,34);
        break;
        case 1: p_one(0,34);
        break;
        case 2: p_two(0,34);
        break;
        case 3: p_three(0,34);
        break;
        default: p_zero(0,34);
      }
      p_dot(4,34);
      switch((int)(a[i]*10)%10){
        case 0: p_zero(6,34);
        break;
        case 1: p_one(6,34);
        break;
        case 2: p_two(6,34);
        break;
        case 3: p_three(6,34);
        break;
        case 4: p_four(6,34);
        break;
        case 5: p_five(6,34);
        break;
        case 6: p_six(6,34);
        break;
        case 7: p_seven(6,34);
        break;
        case 8: p_eight(6,34);
        break;
        case 9: p_nine(6,34);
        break;
        default: p_zero(6,34);
      }
    }
    else if(i==1){
      switch((int)a[i]){
        case 0: p_zero(0,27);
        break;
        case 1: p_one(0,27);
        break;
        case 2: p_two(0,27);
        break;
        case 3: p_three(0,27);
        break;
        default: p_zero(0,27);
      }
      p_dot(4,27);
      switch((int)(a[i]*10)%10){
        case 0: p_zero(6,27);
        break;
        case 1: p_one(6,27);
        break;
        case 2: p_two(6,27);
        break;
        case 3: p_three(6,27);
        break;
        case 4: p_four(6,27);
        break;
        case 5: p_five(6,27);
        break;
        case 6: p_six(6,27);
        break;
        case 7: p_seven(6,27);
        break;
        case 8: p_eight(6,27);
        break;
        case 9: p_nine(6,27);
        break;
        default: p_zero(6,27);
      }
    }
    else if(i==2){
      switch((int)a[i]){
        case 0: p_zero(0,20);
        break;
        case 1: p_one(0,20);
        break;
        case 2: p_two(0,20);
        break;
        case 3: p_three(0,20);
        break;
        default: p_zero(0,20);
      }
      p_dot(4,20);
      switch((int)(a[i]*10)%10){
        case 0: p_zero(6,20);
        break;
        case 1: p_one(6,20);
        break;
        case 2: p_two(6,20);
        break;
        case 3: p_three(6,20);
        break;
        case 4: p_four(6,20);
        break;
        case 5: p_five(6,20);
        break;
        case 6: p_six(6,20);
        break;
        case 7: p_seven(6,20);
        break;
        case 8: p_eight(6,20);
        break;
        case 9: p_nine(6,20);
        break;
        default: p_zero(6,20);
      }
    }
    else if(i==3){
       switch((int)a[i]){
        case 0: p_zero(0,13);
        break;
        case 1: p_one(0,13);
        break;
        case 2: p_two(0,13);
        break;
        case 3: p_three(0,13);
        break;
        default: p_zero(0,13);
      }
      p_dot(4,13);
      switch((int)(a[i]*10)%10){
        case 0: p_zero(6,13);
        break;
        case 1: p_one(6,13);
        break;
        case 2: p_two(6,13);
        break;
        case 3: p_three(6,13);
        break;
        case 4: p_four(6,13);
        break;
        case 5: p_five(6,13);
        break;
        case 6: p_six(6,13);
        break;
        case 7: p_seven(6,13);
        break;
        case 8: p_eight(6,13);
        break;
        case 9: p_nine(6,13);
        break;
        default: p_zero(6,13);
      }
    }else if (i==4){
      switch((int)a[i]){
        case 0: p_zero(0,6);
        break;
        case 1: p_one(0,6);
        break;
        case 2: p_two(0,6);
        break;
        case 3: p_three(0,6);
        break;
        default: p_zero(0,6);
      }
      p_dot(4,6);
      switch((int)(a[i]*10)%10){
        case 0: p_zero(6,6);
        break;
        case 1: p_one(6,6);
        break;
        case 2: p_two(6,6);
        break;
        case 3: p_three(6,6);
        break;
        case 4: p_four(6,6);
        break;
        case 5: p_five(6,6);
        break;
        case 6: p_six(6,6);
        break;
        case 7: p_seven(6,6);
        break;
        case 8: p_eight(6,6);
        break;
        case 9: p_nine(6,6);
        break;
        default: p_zero(6,6);
      }
    }
    
  }

  
}
void drawY_Axis_Values() {
  p_zero(0,6);
  p_dot(4,6);
  p_five(6,6);
  
  p_zero(0,13);
  p_dot(4,13);
  p_four(6,13);

  p_zero(0,20);
  p_dot(4,20);
  p_three(6,20);

  p_zero(0,27);
  p_dot(4,27);
  p_two(6,27);
  
  p_zero(0,34);
  p_dot(4,34);
  p_one(6,34);
  
}

void drawX_Axis_Values(void) {
  
  p_zero(15,43);
  p_dot(19,43);
  p_one(21,43);
  
  p_zero(27,43);
  p_dot(31,43);
  p_two(33,43);

  p_zero(39,43);
  p_dot(43,43);
  p_three(45,43);

  p_zero(51,43);
  p_dot(55,43);
  p_four(57,43);
  
  p_zero(63,43);
  p_dot(67,43);
  p_five(69,43);
  
}


void p_zero(int x,int y) {
  display.drawPixel(x,y, BLACK); 
  display.drawPixel(x,y+1, BLACK);
  display.drawPixel(x,y+2, BLACK); 
  display.drawPixel(x,y+3, BLACK); 
  display.drawPixel(x,y+4, BLACK); 
  display.drawPixel(x+1,y, BLACK); 
  display.drawPixel(x+1,y+4, BLACK); 
  display.drawPixel(x+2,y, BLACK); 
  display.drawPixel(x+2,y+1, BLACK); 
  display.drawPixel(x+2,y+2, BLACK);
  display.drawPixel(x+2,y+3, BLACK); 
  display.drawPixel(x+2,y+4, BLACK);  
}
void p_one(int x,int y) {
  
  display.drawPixel(x+2,y, BLACK); 
  display.drawPixel(x+2,y+1, BLACK); 
  display.drawPixel(x+2,y+2, BLACK);
  display.drawPixel(x+2,y+3, BLACK); 
  display.drawPixel(x+2,y+4, BLACK);  
}
void p_two(int x,int y) {
  display.drawPixel(x,y, BLACK); 
  display.drawPixel(x,y+2, BLACK); 
  display.drawPixel(x,y+3, BLACK); 
  display.drawPixel(x,y+4, BLACK); 
  display.drawPixel(x+1,y, BLACK); 
  display.drawPixel(x+1,y+2, BLACK); 
  display.drawPixel(x+1,y+4, BLACK); 
  display.drawPixel(x+2,y, BLACK); 
  display.drawPixel(x+2,y+1, BLACK); 
  display.drawPixel(x+2,y+2, BLACK); 
  display.drawPixel(x+2,y+4, BLACK); 
}
void p_three(int x,int y) {
  
  display.drawPixel(x,y, BLACK); 
  display.drawPixel(x,y+2, BLACK); 
  display.drawPixel(x,y+4, BLACK); 
  display.drawPixel(x+1,y, BLACK); 
  display.drawPixel(x+1,y+2, BLACK); 
  display.drawPixel(x+1,y+4, BLACK); 
  display.drawPixel(x+2,y, BLACK); 
  display.drawPixel(x+2,y+1, BLACK); 
  display.drawPixel(x+2,y+2, BLACK);
  display.drawPixel(x+2,y+3, BLACK); 
  display.drawPixel(x+2,y+4, BLACK); 
}
void p_four(int x,int y) {
  display.drawPixel(x,y, BLACK); 
  display.drawPixel(x,y+1, BLACK); 
  display.drawPixel(x,y+2, BLACK); 
  display.drawPixel(x+1,y+2, BLACK); 
   display.drawPixel(x+2,y, BLACK); 
  display.drawPixel(x+2,y+1, BLACK); 
  display.drawPixel(x+2,y+2, BLACK); 
  display.drawPixel(x+2,y+3, BLACK); 
  display.drawPixel(x+2,y+4, BLACK); 
}
void p_five(int x,int y) {
  display.drawPixel(x,y, BLACK); 
  display.drawPixel(x,y+1, BLACK); 
  display.drawPixel(x,y+2, BLACK); 
  display.drawPixel(x,y+4, BLACK); 
  display.drawPixel(x+1,y, BLACK); 
  display.drawPixel(x+1,y+2, BLACK); 
  display.drawPixel(x+1,y+4, BLACK); 
  display.drawPixel(x+2,y, BLACK); 
  display.drawPixel(x+2,y+2, BLACK); 
  display.drawPixel(x+2,y+3, BLACK); 
  display.drawPixel(x+2,y+4, BLACK); 
}
void p_six(int x,int y) {
  display.drawPixel(x,y, BLACK); 
  display.drawPixel(x,y+1, BLACK); 
  display.drawPixel(x,y+2, BLACK); 
  display.drawPixel(x,y+3, BLACK); 
  display.drawPixel(x,y+4, BLACK); 
  display.drawPixel(x+1,y, BLACK); 
  display.drawPixel(x+1,y+2, BLACK); 
  display.drawPixel(x+1,y+4, BLACK); 
  display.drawPixel(x+2,y, BLACK); 
  display.drawPixel(x+2,y+2, BLACK); 
  display.drawPixel(x+2,y+3, BLACK); 
  display.drawPixel(x+2,y+4, BLACK); 
}
void p_seven(int x,int y) {
  display.drawPixel(x,y, BLACK);
  display.drawPixel(x+1,y, BLACK);
  display.drawPixel(x+2,y, BLACK); 
  display.drawPixel(x+2,y+1, BLACK); 
  display.drawPixel(x+2,y+2, BLACK);
  display.drawPixel(x+2,y+3, BLACK); 
  display.drawPixel(x+2,y+4, BLACK);  
}
void p_eight(int x,int y) {
  display.drawPixel(x,y, BLACK); 
  display.drawPixel(x,y+1, BLACK); 
  display.drawPixel(x,y+2, BLACK); 
  display.drawPixel(x,y+3, BLACK); 
  display.drawPixel(x,y+4, BLACK); 
  display.drawPixel(x+1,y, BLACK); 
  display.drawPixel(x+1,y+2, BLACK); 
  display.drawPixel(x+1,y+4, BLACK); 
  display.drawPixel(x+2,y, BLACK); 
  display.drawPixel(x+2,y+1, BLACK); 
  display.drawPixel(x+2,y+2, BLACK); 
  display.drawPixel(x+2,y+3, BLACK); 
  display.drawPixel(x+2,y+4, BLACK); 
}
void p_nine(int x,int y) {
  display.drawPixel(x,y, BLACK); 
  display.drawPixel(x,y+1, BLACK); 
  display.drawPixel(x,y+2, BLACK); 
  display.drawPixel(x,y+4, BLACK); 
  display.drawPixel(x+1,y, BLACK); 
  display.drawPixel(x+1,y+2, BLACK); 
  display.drawPixel(x+1,y+4, BLACK); 
  display.drawPixel(x+2,y, BLACK); 
  display.drawPixel(x+2,y+1, BLACK); 
  display.drawPixel(x+2,y+2, BLACK); 
  display.drawPixel(x+2,y+3, BLACK); 
  display.drawPixel(x+2,y+4, BLACK); 
}
void p_dot(int x,int y) {
  display.drawPixel(x,y+4, BLACK); 
  
}
