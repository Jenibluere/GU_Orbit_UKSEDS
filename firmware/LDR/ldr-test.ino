#include <Wire.h>
int P[8] = {0}; //Array to store all the values from the LDRs
int pins[8] = {A0 , A1, A2, A3, A4, A5, A6, A7}; //Array to store the pin numbers so they can be looped

void sendData() { //Function to send data to the Raspberry Pi
   for (int i=0;i<7;i++){
    Wire.write(P[i]);
   }
}

void setup() {
  Serial.begin(9600); //This is to enable SPI connection between the main RaspberryPi and the Arduino, with a 9600 baud 
  Wire.begin(8);      
  Wire.onRequest(sendData); //This calls the sendData() function in order to send 
}                          //the latest data from the LDRs to the main RaspberryPi


void loop() {
  for (int y = 0; y<8; y++){
   P[y] = analogRead(pins[y]); //This loop reads the ADC ports connected to the LDRs
  }
 for (int i = 0; i<7; i++) {     //This loop is used to plot the data using the Serial Plotter 
  Serial.print(P[i]);
  Serial.print(" ");
  
 }
 Serial.print("\n");
}
