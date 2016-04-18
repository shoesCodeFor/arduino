/*  Simple Watering Controller - 
    Written By - Schuyler Ankele 
         */
/* Configure Our Soil Sensor - this is a little trickier
  We will define two pins - the power will be enabled intermittently
  only when readings are taken to preven oxidation on our sensor 
  One Analog PIn to read data and one Digital Pin to power the sensor */
  
#define SOIL_VCC  2
#define SOIL_PIN  A2

/* This pin will open our relay to turn on a water pump. */
#define HOT_LEAD 5
/* Timing variables */
long previousMillis = 0;
unsigned long currentMillis = 0;
long interval = 1000; // READING INTERVAL

long soilStatus = 0;
long runningTotal = 0;
int count= 0;

int targetMoisture = 200;
void setup() {
  Serial.begin(115200);
  pinMode(SOIL_VCC, OUTPUT);
  pinMode(SOIL_PIN, INPUT);
  pinMode(HOT_LEAD, OUTPUT);

}


void loop() {
    /*  Here we will test the soil before watering - 
    NOTE: We only power the pin when taking a reading to save power and shut off after for loop */
    digitalWrite(SOIL_VCC, HIGH);  
    /* Open for tips about accuracy on this.  
    Arduino.cc says Analog reads are up to 10,000 times per second.
    I think thins method only gets an average of 1,000 which is pretty 
    good for our purpose */
    for(int i=0; i < interval; i++){
      runningTotal += analogRead(SOIL_PIN);
      count++;
      Serial.print("We got ");
      Serial.print(count);
    }
  /* Create an average Total_of_All_Readings/Num_Of_Readings */
  digitalWrite(SOIL_VCC, LOW);
  soilStatus = runningTotal/count;
  /* Reset our counting variables */
  runningTotal=0;
  count=0;
  /*  If it's dry it dies! So water it....but not too much
  Lets try 1 second and recheck with our soil probe on the loop */
  if(soilStatus < targetMoisture){
    digitalWrite(HOT_LEAD, HIGH);
    delay(1000);
    digitalWrite(HOT_LEAD, LOW);
  }
Serial.println("Soil Status is:");
Serial.println(soilStatus);
delay(3000);
}
