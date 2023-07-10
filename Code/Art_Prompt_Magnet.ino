/*********
  Original Starter Code OLED Display Hello World Program: Rui Santos
  Complete project details at https://randomnerdtutorials.com  
  
  New Code To make Prompter: Mphatso Simbao
*********/

/*********
Make sure to place connect the display's pins according to the tutorial below:

https://randomnerdtutorials.com/guide-for-oled-display-with-arduino/
*********/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Prompt Array
char *words[]={
"Clouds",
"Moon",
"Sunflower",
"Diversity",
"Butterfly",
"Heart",
"Flower",
"Freedom",
"Patience",
"Soul",
"Sparkles",
"Hero",
"Divine",
"Sky",
"Lace",
"Pattern",
"Leaves",
"Love",
"Center",
"Messy",
"Vintage",
"Secret",
"Wings",
"Cactus",
"Liberty",
"Bloom",
"Muse",
"Light",
"Black",
"Justice",
"Proud"

//Add more words with commas and double qoutation marks as needed.

}; 

//Index for Random Word
long randWordIndex;

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  
  //Random Seed
  randomSeed(analogRead(0));

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

}

void loop() {
    
  //Get Random Index
  randWordIndex = random(sizeof(words)/sizeof(char*));
  
  display.clearDisplay();
  display.setTextColor(WHITE);
  
  // Display static text
  display.setTextSize(1);
  display.setCursor(5, 10);
  display.println("Today's Prompt:");
  display.println("");
  
  //Print Random Word
  display.setTextSize(2);
  display.setCursor(5, 30);
  display.println(words[randWordIndex]);
  display.display(); 
  
  delay(86400000);
}