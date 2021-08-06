/**
 * A SIMPLE SKETCH TO READ MQ-7 (Gas Sensor for Carbon Monoxide)
 * 
 * To use another MQSensor you should change the following parameters:
 *  
 *  MQ_MODEL: the avaliable sensors are MQ2, MQ3, MQ4, MQ5, MQ6, MQ7, MQ8, MQ9 ,MQ131, MQ135, MQ136, MQ137, MQ138;
 *  MQ_RL: 1MOhm for MQ-131 and 4k7Ohm for the others;
 *  
 * 
*/

#include "MQSensors.h"

// - Heater control on pin 3
// - Sensor analog read on pin A0
// - Model MQ-131
// - Load resistance RL of 1E6Ohms (1000000 Ohms)

#define MQ_PINPOWER         5
#define MQ_PINSENSOR        A0
#define MQ_MODEL            MQ131
#define MQ_RL               1000000

#define DHTPIN              6
#define DHTTYPE             DHT22

#define PIN_LED             7

// Initialize MQSensor
MQSensorsClass mq(MQ_RL);

void setup() {

  // Init Serial Monitor
  Serial.begin(115200);

  pinMode(PIN_LED, OUTPUT);

}

void loop() {

  // Init the sensor
  mq.begin(MQ_PINPOWER, MQ_PINSENSOR, MQ_MODEL, MQ_RL);   

  mq.setR0(80000.0);                            // Set R0 value obtained from the calibration
  mq.setTimeToRead(60);                          // Set the time to read consistent values (from calibration)
  
  // Setup DHT22
  mq.setDHT_pin_type(DHTPIN, DHTTYPE);

  Serial.println("MQ131 - Calibration parameters");
  Serial.print("R0 = ");
  Serial.print(mq.getR0());
  Serial.println(" Ohms");
  Serial.print("Time to heat = ");
  Serial.print(mq.getTimeToRead());
  Serial.println(" s");

  Serial.println("Reading MQ131...");
  mq.sample();
  
  // Return the concentration value, after reading MQ-131
  Serial.print("Concentration O3 : ");
  Serial.print(mq.getGas(PPB));
  Serial.println(" ppb");

  // 10-second delay
  delay(10000);

}
