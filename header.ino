/*
Schematics:
GND -> GND
VCC -> 3.5V
SCL -> A5
    \_ 1Kohm -> 3.5V
SDA -> A4
    \_ 1Kohm -> 3.5V
*/

#include <Adafruit_SSD1306.h>  // Include Adafruit_SSD1306 library to drive the display

int game = 1;  // Create a variable to have something dynamic to show on the display
int generation = 0;

int getGame(){
  return game;
}

int getGen(){
  return generation;
}

void increment(){
  generation++;
  delay(50);
  if(generation > 999){
    generation = 1;
    game++;
  }
}

void drawHeader(){
  generation++;
  delay(50);
  if(generation > 999){
    generation = 1;
    game++;
  }
  
  // Print text:
  display.setCursor(3, 5);  // (x,y)
  String gameStr = String(game);
  String genStr = String(generation);
  String str = ("Game " + gameStr + " Gen " + genStr);
  display.println(str);

  // draw header border
  display.drawRect(0, 0, 128, 15, WHITE);
}
