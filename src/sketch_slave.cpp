// SLAVE sketch

#include <Arduino.h>
#include <Wire.h>

#define address 0x08
#define LED_PIN 13

int lighting_mode; 

void setup() {
  Serial.begin(9600);
  Wire.begin(0x08);           // join I2C bus as Slave with address 0x08
  // event handler initializations
  Wire.onReceive(dataRcv);    // register an event handler for received data
  Wire.onRequest(dataRqst);   // register an event handler for data requests
  
  pinMode(LED_PIN, OUTPUT);        // set pin 13 mode to output
}

void loop() {}


//received data handler function
void dataRcv(int numBytes)
{
  while(Wire.available()) { // read all bytes received
    lighting_mode = Wire.read();
    digitalWrite(LED_PIN, lighting_mode);}
}

// requests data handler function
void dataRqst()
{
  byte data = 255;
  Wire.write(data); // send potentiometer position
}