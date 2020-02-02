/*
Schematics:
GND -> GND
VCC -> 3.5V
SCL -> A5
    \_ 1Kohm -> 3.5V
SDA -> A4
    \_ 1Kohm -> 3.5V
*/

#include <Adafruit_GFX.h>  // Include core graphics library for the display
#include <Adafruit_SSD1306.h>  // Include Adafruit_SSD1306 library to drive the display

Adafruit_SSD1306 display(128, 64);  // Create display

void setup(){                
  delay(100);  // This delay is needed to let the display to initialize
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize display with the I2C address of 0x3C
  display.clearDisplay();  // Clear the buffer
  display.setTextColor(WHITE);  // Set color of the text
  display.setRotation(0);  // Set orientation. Goes from 0, 1, 2 or 3
  display.setTextWrap(false);  // By default, long lines of text are set to automatically “wrap” back to the leftmost column.
                               // To override this behavior (so text will run off the right side of the display - useful for
                               // scrolling marquee effects), use setTextWrap(false). The normal wrapping behavior is restored
                               // with setTextWrap(true).
  display.dim(1);  //Set brightness (0 is maximun and 1 is a little dim)

}  // End of setup

void loop(){
  increment();
  display.clearDisplay();  // Clear the display so we can refresh
  display.setTextSize(0);  // Set text size. We are using a custom font so you should always use the text size of 0

  drawHeader();
  
  display.drawRect(0, 16, 128, (64-15-1), WHITE);
  display.display();  // Print everything we set previously

}  // End of loop
