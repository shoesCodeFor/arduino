/*
 *  Simple Sunlight outlet controller.  
 *  Written By Schuyler Ankele - Busy Bee Information Technologies
 *  This would be ideal for an apartment with pets.   You
 *  could control an AC, evap. cooler or fans for daylight hours
 *  and then turn on a light for our friends when the sun goes down.
 *  You can also snip a line of code out of this to make it a 
 *  Christmas Light Controller
 * 
 *  How it works - We attach a solar panel or photoresistor as our
 *  sunlight sensor.  Calibrate to a daylight setting and voila.
 *  One outlet is on during day and one is on at night.
 * 
 * Define our pins 
 */
#define DAYLIGHT_PIN 2
#define NIGHT_PIN 3
#define SENSOR_PIN A0
long CURRENT_LIGHT = 0;
long LIGHT_THRESHOLD = 300; //This is a measurment between 1-1024

void setup() {
  // We setup our pin connections
  Serial.begin(115200);
  pinMode(SENSOR_PIN, INPUT);  
  pinMode(DAYLIGHT_PIN, OUTPUT);
  pinMode(NIGHT_PIN, OUTPUT);
  

  
} // END SETUP

void loop() {
  // 
  CURRENT_LIGHT = analogRead(SENSOR_PIN);
  Serial.println(CURRENT_LIGHT);
  if(CURRENT_LIGHT > LIGHT_THRESHOLD){
     Serial.println("DAYLIGHT OUTLET ON"); 
     digitalWrite(DAYLIGHT_PIN, HIGH);
     digitalWrite(NIGHT_PIN, LOW);
  }
  else{
      Serial.println("NIGHT OUTLET ON");
      digitalWrite(DAYLIGHT_PIN, LOW);
      digitalWrite(NIGHT_PIN, HIGH);
  } 
  
} // END LOOP
