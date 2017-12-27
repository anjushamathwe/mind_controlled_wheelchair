
String voice;
int brai;
#include "Brain.h"

Brain brain(Serial);

void setup() {
	// Start the hardware serial.
 
	Serial.begin(9600);
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT); 
  pinMode(11, OUTPUT);
}

void loop() {
  
  		
	if (brain.update()) {
                Serial.println(brain.readCSV());
  		Serial.println(brain.readErrors());
                Serial.println(brain.readDelta());
		Serial.println(brain.readTheta());
		Serial.println(brain.readLowAlpha());
		Serial.println(brain.readHighAlpha());
		Serial.println(brain.readLowBeta());
		Serial.println(brain.readHighBeta());
		Serial.println(brain.readLowGamma());
		Serial.println(brain.readMidGamma());
delay(2000);
	if((brain.readSignalQuality())> 10)
      {   
          digitalWrite(10,0);
          digitalWrite(11,1);
          digitalWrite(8,0);
          digitalWrite(9,1);
        
      } 
      else
       {  
          digitalWrite(10,0);
          digitalWrite(11,0);
          digitalWrite(8,0);
          digitalWrite(9,0);
       
       }
            Serial.println(brain.readSignalQuality());

	}
}

