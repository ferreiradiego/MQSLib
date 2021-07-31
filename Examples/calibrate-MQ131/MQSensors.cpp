#include "MQSensors.h"

/**
 * Constructor, nothing special to do
 * It is not indicated use it, it recommended use the begin() function to setup the values
 */
MQSensorsClass::MQSensorsClass(uint32_t _RL) {

  valueRL = _RL; 

}

/**
 * Destructor, nothing special to do
 */
MQSensorsClass::~MQSensorsClass() {
}

/**
 * Initialize core variables
 */
 void MQSensorsClass::begin(uint8_t _pinPower, uint8_t _pinSensor, MQSensor_Model _model, uint32_t _RL) { 

 	// Set the model
 	model = _model;

 	// Store the circuit info (pin and load resistance)
 	pinPower = _pinPower;
 	pinSensor = _pinSensor;
 	valueRL = _RL;

  // Setup default calibration value
  switch(model) {
    case MQ3:
      setR0(MQ3_DEFAULT_R0);
      setTimeToRead(MQ3_DEFAULT_TIMETOREAD);
      setA(MQ3_DEFAULT_A);
      setB(MQ3_DEFAULT_B);
      setTempHum(MQ3_DEFAULT_TEMPERATURE_CELSIUS, MQ3_DEFAULT_HUMIDITY_PERCENT);
      break;
    case MQ4:
      setR0(MQ4_DEFAULT_R0);
      setTimeToRead(MQ4_DEFAULT_TIMETOREAD);
      setA(MQ4_DEFAULT_A);
      setB(MQ4_DEFAULT_B);
      setTempHum(MQ4_DEFAULT_TEMPERATURE_CELSIUS, MQ4_DEFAULT_HUMIDITY_PERCENT);
      break;
    case MQ6:
      setR0(MQ6_DEFAULT_R0);
      setTimeToRead(MQ6_DEFAULT_TIMETOREAD);
      setA(MQ6_DEFAULT_A);
      setB(MQ6_DEFAULT_B);
      setTempHum(MQ6_DEFAULT_TEMPERATURE_CELSIUS, MQ6_DEFAULT_HUMIDITY_PERCENT);
      break;
    case MQ7:
      setR0(MQ7_DEFAULT_R0);
      setTimeToRead(MQ7_DEFAULT_TIMETOREAD);
      setA(MQ7_DEFAULT_A);
      setB(MQ7_DEFAULT_B);
      setTempHum(MQ7_DEFAULT_TEMPERATURE_CELSIUS, MQ7_DEFAULT_HUMIDITY_PERCENT);
      break;
    case MQ8:
      setR0(MQ8_DEFAULT_R0);
      setTimeToRead(MQ8_DEFAULT_TIMETOREAD);
      setA(MQ8_DEFAULT_A);
      setB(MQ8_DEFAULT_B);
      setTempHum(MQ8_DEFAULT_TEMPERATURE_CELSIUS, MQ8_DEFAULT_HUMIDITY_PERCENT);
      break;                  
    case MQ131:
      setR0(MQ131_DEFAULT_R0);
      setTimeToRead(MQ131_DEFAULT_TIMETOREAD);
      setA(MQ131_DEFAULT_A);
      setB(MQ131_DEFAULT_B);
      setTempHum(MQ131_DEFAULT_TEMPERATURE_CELSIUS, MQ131_DEFAULT_HUMIDITY_PERCENT);
      break;
    case MQ136:
      setR0(MQ136_DEFAULT_R0);
      setTimeToRead(MQ136_DEFAULT_TIMETOREAD);
      setA(MQ136_DEFAULT_A);
      setB(MQ136_DEFAULT_B);
      setTempHum(MQ136_DEFAULT_TEMPERATURE_CELSIUS, MQ136_DEFAULT_HUMIDITY_PERCENT);
      break;
    case MQ137:
      setR0(MQ137_DEFAULT_R0);
      setTimeToRead(MQ137_DEFAULT_TIMETOREAD);
      setA(MQ137_DEFAULT_A);
      setB(MQ137_DEFAULT_B);
      setTempHum(MQ137_DEFAULT_TEMPERATURE_CELSIUS, MQ137_DEFAULT_HUMIDITY_PERCENT);
      break;
  }

 	// Setup pin mode
 	pinMode(pinPower, OUTPUT);
 	pinMode(pinSensor, INPUT);

  // Switch off the heater as default status
  digitalWrite(pinPower, LOW);
 }

/**
 * Do a full cycle (heater, reading, stop heater)
 * The function gives back the hand only at the end
 * of the read cycle!
 */
 void MQSensorsClass::sample() {
 	
   startHeater();

 	while(!isTimeToRead()) {
 		delay(1000);
 	}

 	lastValueRs = readRs();
 	stopHeater();

 }

/**
 * Start the heater
 */
 void MQSensorsClass::startHeater() {
 	
  digitalWrite(pinPower, HIGH);
 	secLastStart = millis()/1000;
 
 }

/**
 * Check if it is the right time to read the Rs value
 */
 bool MQSensorsClass::isTimeToRead() {
 	// Check if the heater has been started...
 	if(secLastStart < 0) {
 		return false;
 	}
 	// OK, check if it's the time to read based on calibration parameters
 	if(millis() / 1000 >= secLastStart + getTimeToRead()) {
 		return true;
 	}
 	return false;
 } 

/**
 * Stop the heater
 */
 void MQSensorsClass::stopHeater() {
 	digitalWrite(pinPower, LOW);
 	secLastStart = -1;
 }

/**
 * Get parameter time to read
 */
 long MQSensorsClass::getTimeToRead() {
 	return secToRead;
 }

/**
 * Set parameter time to read (for calibration or to recall
 * calibration from previous run)
 */
 void MQSensorsClass::setTimeToRead(uint32_t sec) {
 	secToRead = sec;
 }

/**
 * Read Rs value
 */
 float MQSensorsClass::readRs() {
 	// Read the value
 	uint16_t valueSensor = analogRead(pinSensor);
 	// Compute the voltage on load resistance (for 5V Arduino)
 	float vRL = ((float)valueSensor) / 1023.0 * 5.0;
 	// Compute the resistance of the sensor (for 5V Arduino)
  if(!vRL) 
    return 0.0f; //division by zero prevention

 	float rS = (5.0 / vRL - 1.0) * valueRL;
 	return rS;
 }

/**
 * Set environmental values
 */
 void MQSensorsClass::setTempHum(int8_t _tempCelsius, uint8_t _humPercent) {
 	this->temperatureCelsius = _tempCelsius;
 	this->humidityPercent = _humPercent;
 }

// Get correction to apply on Rs depending on environmental conditions

 float MQSensorsClass::getEnvCorrectRatio() {

 	// Select the right equation based on humidity and temperature
 	// If default value, ignore correction ratio
 	if(humidityPercent == 60 && temperatureCelsius == 20) {
 		return 1.0;
 	}
 	// For humidity > 75%, use the 85% curve
 	if(humidityPercent > 75) {
 		// R^2 = 0.9986
 		return -0.0141 * temperatureCelsius + 1.5623;
 	}
 	// For humidity > 50%, use the 60% curve
 	if(humidityPercent > 50) {
 		// R^2 = 0.9976
 		return -0.0119 * temperatureCelsius + 1.3261;
 	}

 	// Humidity < 50%, use the 30% curve
 	// R^2 = 0.996
 	return -0.0103 * temperatureCelsius + 1.1507;
 }

 /**
 * Get gas concentration for some sensor in ppm or ppb
 */
 float MQSensorsClass::getGas(MQSensorUnit unit) {
  // If no value Rs read, return 0.0
 	if(lastValueRs < 0) {
 		return 0.0;
 	}

  float ratio = 0.0;

  switch (model)
  {
  
  case MQ131:
      //Use the equation to compute the 03 concentration in ppb
      // R² = 0.9987
      // Compute the ration Rs/R0 and apply the environmental correction
      ratio = lastValueRs / valueR0 * getEnvCorrectRatio();
      return convert(9.4783 * pow(ratio, 2.3348), PPB, unit); 
      break;
  // The others MQ Sensors the unit is in PPM
  default:
      //Use the equation to compute the gas concentration in ppm
      // R² = 0.9987
      // Compute the ration Rs/R0 and apply the environmental correction
      ratio = lastValueRs / valueR0 * getEnvCorrectRatio();
      return convert(coef_a * pow(ratio, coef_b), PPM, unit); 
  }
}

 /**
  * Convert unit of gas concentration
  */
 float MQSensorsClass::convert(float input, MQSensorUnit unitIn, MQSensorUnit unitOut) {
  if(unitIn == unitOut) {
    return input;
  }

  float concentration = 0.0;

  switch(unitOut) {
    case PPM :
      // We assume that the unit IN is PPB as the sensor provide only in PPB and PPM
      // So, convert PPB to PPM
      return input / 1000.0;
    case PPB :
      // We assume that the unit IN is PPM as the sensor provide only in PPB and PPM
      // So, convert PPM to PPB
      return input * 1000.0;
    case MG_M3 :
      if(unitIn == PPM) {
        concentration = input;
      } else {
        concentration = input / 1000.0;
      }
      return concentration * 48.0 / 22.71108;
    case UG_M3 :
      if(unitIn == PPB) {
        concentration = input;
      } else {
        concentration = input * 1000.0;
      }
      return concentration * 48.0 / 22.71108;
    default :
      return input;
  }
}

 /**
  * Calibrate the basic values (R0 and time to read)
  */
void MQSensorsClass::calibrate(Calibration_mode _mode) {

  // Take care of the last Rs value read on the sensor (forget the decimals)
  float lastRsValue = 0;
  // Count how many time we keep the same Rs value in a row
  uint8_t countReadInRow = 0;
  // Count how long we have to wait to have consistent value
  uint8_t count = 0;

  uint8_t timeToReadConsistency = MQ131_DEFAULT_STABLE_CYCLE;

  float value = 0.0;

  // Verify which calibration mode was selected

  switch (_mode)
  {
  case complete:
    
    // Start heater
    startHeater();
    
    while(countReadInRow <= timeToReadConsistency) {
      
      value = readRs();

      readTemperatureHumidity();

      /** 
       *  Verify whether the absolute error between the last and the current is less than 2%
       *  Case the error is greater than 2%: the current value is stored in the var lastRsValue and the countReadInRow is set to zero
       *  Case the error is less than 2%: the var countReadInRow is incremented
      */
      if((abs((float)lastRsValue - (float)value)/(float)value) > 0.02){
        Serial.println();
        Serial.println(value); // show the last value read
        Serial.print("Absolute error: "); Serial.print((abs(lastRsValue - value)/value)*100); Serial.println("%");
        Serial.println();
        lastRsValue = value;
        countReadInRow = 0; 
      }
      else{
        Serial.println(value); // show the last value read
        countReadInRow++;
      }

      count++;
      
      delay(1000);    // delay of 1 second between each reading
    }
    // Stop heater
    stopHeater();
    break;
  
  default:

    // Start heater
    startHeater();
    
    while(countReadInRow <= timeToReadConsistency) {
      
      value = readRs();

      /** 
       * Verify whether the absolute error between the last and the current is less than 2%
       * Case the error is greater than 2%: the current value is stored in the var lastRsValue and the countReadInRow is set to zero
       * Case the error is less than 2%: the var countReadInRow is incremented
      */
      if((abs((float)lastRsValue - (float)value)/(float)value) > 0.02){
        lastRsValue = value;
        countReadInRow = 0; 
      }
      else{
        countReadInRow++;
      }

      Serial.println(value); // show the last value read

      count++;
      
      delay(1000);    // delay of 1 second between each reading
    }
    // Stop heater
    stopHeater();

    break;
  }

  // We have our R0 and our time to read
  setR0(lastRsValue);
  setTimeToRead(count);
}
/**
  * Read temperature and humidity from DHT22 (as default)
  * Show the temperature and humidity on Serial Monitor
*/

/**
 * Set pin and type to DHT Sensor (DHT22, DHT11)
*/

void MQSensorsClass::setDHT_pin_type(uint8_t _dhtPin, uint8_t _dhtType){

  this->dhtPin = _dhtPin;
  this->dhtType = _dhtType;

}

void MQSensorsClass::readTemperatureHumidity(){

  // Setup the DHT Type/Pin
  DHT dht(dhtPin, dhtType);
  // Init DHT Sensor (Temperature and Humidity)
  dht.begin();
  
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float hum = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float temp = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(hum) || isnan(temp)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Print values by DHT Sensor (Humidity and Temperature)
  Serial.print(F("Humidity: "));
  Serial.print(hum);
  Serial.print(F("%  Temperature: "));
  Serial.print(temp);
  Serial.print(F("°C "));
  Serial.println("");

}

 /**
  * Store R0 value (come from calibration or set by user)
  */
  void MQSensorsClass::setR0(float _valueR0) {
  	this->valueR0 = _valueR0;
  }

 /**
 * Get R0 value
 */
 float MQSensorsClass::getR0() {
  return valueR0;
 }

/**
 * Store coefficent A (come from the graph of datasheet)
 */
 void MQSensorsClass::setA(float _valueA){
   this->coef_a = _valueA;
 }

/**
 * Store coefficent B (come from the graph of datasheet)
 */

  void MQSensorsClass::setB(float _valueB){
   this->coef_b = _valueB;
 }

MQSensorsClass MQSensor(MQ131_DEFAULT_RL);
