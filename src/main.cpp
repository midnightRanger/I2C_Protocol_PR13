// MASTER sketch

#include <Arduino.h>
#include <Wire.h>
#include "button.h"

#define address 0x08
button btn(2); 

int lighting_mode; 

void setup() {
  Serial.begin(9600);
  Wire.begin();
  lighting_mode = HIGH;

}

void loop() {
  // Wire.requestFrom(address, quantity); 
  if(btn.click()) {
    Serial.println("button pressed");
    Wire.beginTransmission(address);

    lighting_mode = lighting_mode == HIGH ? LOW : HIGH;

    Serial.println("Текущий режим: ");
    Serial.println(lighting_mode);
    Wire.write(lighting_mode);

    Wire.endTransmission();

    Wire.requestFrom(address, 1);

    if(Wire.available()) {
      Serial.println(Wire.read());
    }
  }
}