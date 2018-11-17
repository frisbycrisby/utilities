
#include <Arduino.h>
#include <USBAPI.h>

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);  
   //HardwareSerial.begin(9600);  
  	
}

void loop() {
  // put your main code here, to run repeatedly:
   //int Col_set[4][2] = {{2,1},{3,1},{4,1},{5,1}};
   //int Row_set[4][2] = {{2,1},{3,1},{4,1},{5,1}};
   //keyboard_setup(Col_set,Row_set); 
   Serial.println("test");
   Serial.println("");
   Serial.println("");
   //Serial.write("Testing Done...");
}

int  main(){
 	setup();	
	while(1) {
		loop();
	}
	return (0);

}
