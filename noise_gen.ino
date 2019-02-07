/*
* Arduino Noise Gen
*
* by Hugo Rezende, www.hugorezende.com.br
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN

void setup() {
  radio.begin();
  radio.setPALevel(RF24_PA_HIGH);
  radio.setChannel(22);
  radio.stopListening();
}
void loop() {
  for(int i=16; i<38; i++){
    radio.setChannel(i);
    const char text[] = "320939210nsdf";
    radio.write(&text, sizeof(text));
  }
}
