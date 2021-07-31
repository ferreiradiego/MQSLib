#ifndef _MQSensors_H_
#define _MQSensors_H_

/**
 * @file MQSensors.h
 * @author Diego Ferreira (diego.ferreiraa@outlook.com)
 * @brief Librabry for MQ Serie Sensors
 * @version 0.1
 * @date 2021-01-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// Include Arduino library
#include <Arduino.h>

// It is essential to include DHT Sensor library by Adafruit
#include "DHT.h"


// ------------------------------------------ MQ-3 ------------------------------------------ //

/*!
 *  @brief  Definition of Defaults values MQ-3 (Gas sensor Alcohol)
 * 	
 *  @param  MQ3_DEFAULT_RL
 *          The load resistence indicated in the Datasheet is 4k7Ohms (4700 Ohms)
 *  @param  MQ3_DEFAULT_STABLE_CYCLE
 *          Number of cycles with low deviation to consider, the calibration as stable and realible
 * 	@param	MQ3_DEFAULT_DEVIATION
 * 			Deviation value (variation allowed between the previous value and the current value)
 */
#define MQ3_DEFAULT_RL                            	4700
#define MQ3_DEFAULT_STABLE_CYCLE                  	15
#define MQ3_DEFAULT_DEVIATION						0.02
/*!
 *  @brief  Definition of values obtained in the calibration process of the MQ-3 (Gas sensor for Alcohol)
 * 	
 *  @param  MQ3_DEFAULT_R0
 *          Default R0 for MQ-3
 *  @param  MQ3_DEFAULT_TIMETOREAD
 *          Default time to read before stable signal for MQ-3
 * 	@param	MQ3_DEFAULT_A
 * 			Default value of coefficient a (from graph avaliable at datasheet)
 * 	@param	MQ3_DEFAULT_B	
 * 			Default value of coefficient b (from graph avaliable at datasheet)
 * 	@param	MQ3_DEFAULT_TEMPERATURE_CELSIUS
 * 			Default temperature to correct environmental curve (must be obtained in the calibration)
 * 	@param	MQ3_DEFAULT_HUMIDITY_PERCENT
 * 			Default humidity to correct environmental curve (also must be obtained in the calibration)
 */
#define MQ3_DEFAULT_R0           						0
#define MQ3_DEFAULT_TIMETOREAD    						0
#define MQ3_DEFAULT_A									6.190421
#define MQ3_DEFAULT_B									-1.137087
#define MQ3_DEFAULT_TEMPERATURE_CELSIUS					20
#define MQ3_DEFAULT_HUMIDITY_PERCENT 					60

// ------------------------------------------ MQ-4 ------------------------------------------ //

/*!
 *  @brief  Definition of Defaults values MQ-4 (Gas sensor for Methane)
 * 	
 *  @param  MQ4_DEFAULT_RL
 *          The load resistence indicated in the Datasheet is 4k7Ohms (4700 Ohms)
 *  @param  MQ4_DEFAULT_STABLE_CYCLE
 *          Number of cycles with low deviation to consider, the calibration as stable and realible
 * 	@param	MQ4_DEFAULT_DEVIATION
 * 			Deviation value (variation allowed between the previous value and the current value)
 */
#define MQ4_DEFAULT_RL                            	4700
#define MQ4_DEFAULT_STABLE_CYCLE                  	15
#define MQ4_DEFAULT_DEVIATION						0.02
/*!
 *  @brief  Definition of values obtained in the calibration process of the MQ-4 (Gas sensor for Methane)
 * 	
 *  @param  MQ4_DEFAULT_R0
 *          Default R0 for MQ-4
 *  @param  MQ4_DEFAULT_TIMETOREAD
 *          Default time to read before stable signal for MQ-4
 * 	@param	MQ4_DEFAULT_A
 * 			Default value of coefficient a (from graph avaliable at datasheet)
 * 	@param	MQ4_DEFAULT_B	
 * 			Default value of coefficient b (from graph avaliable at datasheet)
 * 	@param	MQ4_DEFAULT_TEMPERATURE_CELSIUS
 * 			Default temperature to correct environmental curve (must be obtained in the calibration)
 * 	@param	MQ4_DEFAULT_HUMIDITY_PERCENT
 * 			Default humidity to correct environmental curve (also must be obtained in the calibration)
 */

#define MQ4_DEFAULT_R0           						0
#define MQ4_DEFAULT_TIMETOREAD    						0
#define MQ4_DEFAULT_A									24.4533
#define MQ4_DEFAULT_B									-1.66272
#define MQ4_DEFAULT_TEMPERATURE_CELSIUS					20
#define MQ4_DEFAULT_HUMIDITY_PERCENT 					60

// ------------------------------------------ MQ-6 ------------------------------------------ //

/*!
 *  @brief  Definition of Defaults values MQ-6 (Gas sensor for Propane)
 * 	
 *  @param  MQ6_DEFAULT_RL
 *          The load resistence indicated in the Datasheet is 4k7Ohms (4700 Ohms)
 *  @param  MQ6_DEFAULT_STABLE_CYCLE
 *          Number of cycles with low deviation to consider, the calibration as stable and realible
 * 	@param	MQ6_DEFAULT_DEVIATION
 * 			Deviation value (variation allowed between the previous value and the current value)
 */
#define MQ6_DEFAULT_RL                            	4700
#define MQ6_DEFAULT_STABLE_CYCLE                  	15
#define MQ6_DEFAULT_DEVIATION						0.02
/*!
 *  @brief  Definition of values obtained in the calibration process of the MQ-6 (Gas sensor for Propane)
 * 	
 *  @param  MQ6_DEFAULT_R0
 *          Default R0 for MQ-6
 *  @param  MQ6_DEFAULT_TIMETOREAD
 *          Default time to read before stable signal for MQ-6
 * 	@param	MQ6_DEFAULT_A
 * 			Default value of coefficient a (from graph avaliable at datasheet)
 * 	@param	MQ6_DEFAULT_B	
 * 			Default value of coefficient b (from graph avaliable at datasheet)
 * 	@param	MQ6_DEFAULT_TEMPERATURE_CELSIUS
 * 			Default temperature to correct environmental curve (must be obtained in the calibration)
 * 	@param	MQ6_DEFAULT_HUMIDITY_PERCENT
 * 			Default humidity to correct environmental curve (also must be obtained in the calibration)
 */

#define MQ6_DEFAULT_R0           						0
#define MQ6_DEFAULT_TIMETOREAD    						0
#define MQ6_DEFAULT_A									43.9671
#define MQ6_DEFAULT_B									-1.364845
#define MQ6_DEFAULT_TEMPERATURE_CELSIUS					20
#define MQ6_DEFAULT_HUMIDITY_PERCENT 					60

// ------------------------------------------ MQ-7 ------------------------------------------ //

/*!
 *  @brief  Definition of Defaults values MQ-7 (Gas sensor for Carbon Monoxide)
 * 	
 *  @param  MQ7_DEFAULT_RL
 *          The load resistence indicated in the Datasheet is 4k7Ohms (4700 Ohms)
 *  @param  MQ7_DEFAULT_STABLE_CYCLE
 *          Number of cycles with low deviation to consider, the calibration as stable and realible
 * 	@param	MQ7_DEFAULT_DEVIATION
 * 			Deviation value (variation allowed between the previous value and the current value)
 */
#define MQ7_DEFAULT_RL                            	4700
#define MQ7_DEFAULT_STABLE_CYCLE                  	15
#define MQ7_DEFAULT_DEVIATION						0.02
/*!
 *  @brief  Definition of values obtained in the calibration process of the MQ-7 (Gas sensor for Carbon Monoxide)
 * 	
 *  @param  MQ7_DEFAULT_R0
 *          Default R0 for MQ-7
 *  @param  MQ7_DEFAULT_TIMETOREAD
 *          Default time to read before stable signal for MQ-7
 * 	@param	MQ7_DEFAULT_A
 * 			Default value of coefficient a (from graph avaliable at datasheet)
 * 	@param	MQ7_DEFAULT_B	
 * 			Default value of coefficient b (from graph avaliable at datasheet)
 * 	@param	MQ7_DEFAULT_TEMPERATURE_CELSIUS
 * 			Default temperature to correct environmental curve (must be obtained in the calibration)
 * 	@param	MQ7_DEFAULT_HUMIDITY_PERCENT
 * 			Default humidity to correct environmental curve (also must be obtained in the calibration)
 */

#define MQ7_DEFAULT_R0           						0
#define MQ7_DEFAULT_TIMETOREAD    						0
#define MQ7_DEFAULT_A									0.75346
#define MQ7_DEFAULT_B									-1.82285
#define MQ7_DEFAULT_TEMPERATURE_CELSIUS					20
#define MQ7_DEFAULT_HUMIDITY_PERCENT 					60

// ------------------------------------------ MQ-8 ------------------------------------------ //

/*!
 *  @brief  Definition of Defaults values MQ-8 (Gas sensor for Hydrogen Gas)
 * 	
 *  @param  MQ8_DEFAULT_RL
 *          The load resistence indicated in the Datasheet is 4k7Ohms (4700 Ohms)
 *  @param  MQ8_DEFAULT_STABLE_CYCLE
 *          Number of cycles with low deviation to consider, the calibration as stable and realible
 * 	@param	MQ8_DEFAULT_DEVIATION
 * 			Deviation value (variation allowed between the previous value and the current value)
 */
#define MQ8_DEFAULT_RL                            	4700
#define MQ8_DEFAULT_STABLE_CYCLE                  	15
#define MQ8_DEFAULT_DEVIATION						0.02
/*!
 *  @brief  Definition of values obtained in the calibration process of the MQ-8 (Gas sensor for Hydrogen Gas)
 * 	
 *  @param  MQ8_DEFAULT_R0
 *          Default R0 for MQ-8
 *  @param  MQ8_DEFAULT_TIMETOREAD
 *          Default time to read before stable signal for MQ-8
 * 	@param	MQ8_DEFAULT_A
 * 			Default value of coefficient a (from graph avaliable at datasheet)
 * 	@param	MQ8_DEFAULT_B	
 * 			Default value of coefficient b (from graph avaliable at datasheet)
 * 	@param	MQ8_DEFAULT_TEMPERATURE_CELSIUS
 * 			Default temperature to correct environmental curve (must be obtained in the calibration)
 * 	@param	MQ8_DEFAULT_HUMIDITY_PERCENT
 * 			Default humidity to correct environmental curve (also must be obtained in the calibration)
 */

#define MQ8_DEFAULT_R0           						0
#define MQ8_DEFAULT_TIMETOREAD    						0
#define MQ8_DEFAULT_A									1.80843
#define MQ8_DEFAULT_B									-2.6622
#define MQ8_DEFAULT_TEMPERATURE_CELSIUS					20
#define MQ8_DEFAULT_HUMIDITY_PERCENT 					60

// ------------------------------------------ MQ-131 ------------------------------------------ //

/*!
 *  @brief  Definition of Defaults values MQ-131 (Ozone Sensor)
 * 	
 *  @param  MQ131_DEFAULT_RL
 *          The load resistence indicated in the Datasheet is 1MOhm (1000000 Ohm)
 *  @param  MQ131_DEFAULT_STABLE_CYCLE
 *          Number of cycles with low deviation to consider, the calibration as stable and realible
 * 	@param	MQ131_DEFAULT_DEVIATION
 * 			Deviation value (variation allowed between the previous value and the current value)
 */
#define MQ131_DEFAULT_RL                            	1000000
#define MQ131_DEFAULT_STABLE_CYCLE                  	15
#define MQ131_DEFAULT_DEVIATION							0.02
/*!
 *  @brief  Definition of values obtained in the calibration process of the MQ-131 (Ozone sensor)
 * 	
 *  @param  MQ131_DEFAULT_R0
 *          Default R0 for low concentration MQ131
 *  @param  MQ131_DEFAULT_TIMETOREAD
 *          Default time to read before stable signal for low concentration MQ131
 * 	@param	MQ131_DEFAULT_A
 * 			Default value of coefficient a (from graph avaliable at datasheet)
 * 	@param	MQ131_DEFAULT_B	
 * 			Default value of coefficient b (from graph avaliable at datasheet)
 * 	@param	MQ131_DEFAULT_TEMPERATURE_CELSIUS
 * 			Default temperature to correct environmental curve (must be obtained in the calibration)
 * 	@param	MQ131_DEFAULT_HUMIDITY_PERCENT
 * 			Default humidity to correct environmental curve (also must be obtained in the calibration)
 */
#define MQ131_DEFAULT_R0           						286792.53
#define MQ131_DEFAULT_TIMETOREAD    					60
#define MQ131_DEFAULT_A									8.68197
#define MQ131_DEFAULT_B									2.33593
#define MQ131_DEFAULT_TEMPERATURE_CELSIUS				20
#define MQ131_DEFAULT_HUMIDITY_PERCENT 					60

// ------------------------------------------ MQ-136 ------------------------------------------ //
/*!
 *  @brief  Definition of Defaults values MQ-136 (Gas Sensor for Hydrogen Sulfide)
 * 	
 *  @param  MQ136_DEFAULT_RL
 *          The load resistence indicated in the Datasheet is 4k7 Ohm (4700 Ohm)
 *  @param  MQ136_DEFAULT_STABLE_CYCLE
 *          Number of cycles with low deviation to consider, the calibration as stable and realible
 * 	@param	MQ136_DEFAULT_DEVIATION
 * 			Deviation value (variation allowed between the previous value and the current value)
 */
#define MQ136_DEFAULT_RL                            	4700
#define MQ136_DEFAULT_STABLE_CYCLE                  	15
#define MQ136_DEFAULT_DEVIATION							0.02
/*!
 *  @brief  Definition of values obtained in the calibration process of the MQ-137 (Gas Sensor for Hydrogen Sulfide)
 * 	
 *  @param  MQ136_DEFAULT_R0
 *          Default R0 for MQ136
 *  @param  MQ136_DEFAULT_TIMETOREAD
 *          Default time to read before stable signal for concentration of the MQ136
 * 	@param	MQ136_DEFAULT_A
 * 			Default value of coefficient a (from graph avaliable at datasheet)
 * 	@param	MQ136_DEFAULT_B	
 * 			Default value of coefficient b (from graph avaliable at datasheet)
 * 	@param	MQ136_DEFAULT_TEMPERATURE_CELSIUS
 * 			Default temperature to correct environmental curve (must be obtained in the calibration)
 * 	@param	MQ136_DEFAULT_HUMIDITY_PERCENT
 * 			Default humidity to correct environmental curve (also must be obtained in the calibration)
 */
#define MQ136_DEFAULT_R0           						11598.64
#define MQ136_DEFAULT_TIMETOREAD    					60
#define MQ136_DEFAULT_A									0.145073
#define MQ136_DEFAULT_B									-3.745874
#define MQ136_DEFAULT_TEMPERATURE_CELSIUS				20
#define MQ136_DEFAULT_HUMIDITY_PERCENT 					60

// ------------------------------------------ MQ-137 ------------------------------------------ //
/*!
 *  @brief  Definition of Defaults values MQ-137 (Ammonia Gas Sensor)
 * 	
 *  @param  MQ137_DEFAULT_RL
 *          The load resistence indicated in the Datasheet is 4k7 Ohm (4700 Ohm)
 *  @param  MQ137_DEFAULT_STABLE_CYCLE
 *          Number of cycles with low deviation to consider, the calibration as stable and realible
 * 	@param	MQ137_DEFAULT_DEVIATION
 * 			Deviation value (variation allowed between the previous value and the current value)
 */
#define MQ137_DEFAULT_RL                            	4700
#define MQ137_DEFAULT_STABLE_CYCLE                  	15
#define MQ137_DEFAULT_DEVIATION							0.02
/*!
 *  @brief  Definition of values obtained in the calibration process of the MQ-137 (Ammonia Gas Sensor)
 * 	
 *  @param  MQ137_DEFAULT_R0
 *          Default R0 for MQ137
 *  @param  MQ137_DEFAULT_TIMETOREAD
 *          Default time to read before stable signal for concentration MQ137
 * 	@param	MQ137_DEFAULT_A
 * 			Default value of coefficient a (from graph avaliable at datasheet)
 * 	@param	MQ137_DEFAULT_B	
 * 			Default value of coefficient b (from graph avaliable at datasheet)
 * 	@param	MQ137_DEFAULT_TEMPERATURE_CELSIUS
 * 			Default temperature to correct environmental curve (must be obtained in the calibration)
 * 	@param	MQ137_DEFAULT_HUMIDITY_PERCENT
 * 			Default humidity to correct environmental curve (also must be obtained in the calibration)
 */
#define MQ137_DEFAULT_R0           						1917.22
#define MQ137_DEFAULT_TIMETOREAD    					80
#define MQ137_DEFAULT_A									0.0966336
#define MQ137_DEFAULT_B									-4.4309
#define MQ137_DEFAULT_TEMPERATURE_CELSIUS				20
#define MQ137_DEFAULT_HUMIDITY_PERCENT 					60

/**
 * Enum for MQ Sensors Unit.
 * 
 * 	Available units:
 * 
 *	PPB - parts per billion 
 *	PPM - parts per million
 *	MG/M³ - milligram per cubic meter
 *	UG_M³ - microgram per cubic meter
 *   
 **/
enum MQSensorUnit {PPM, PPB, MG_M3, UG_M3};

/**
 * Enum for MQ Sensors Models
 *	
 *	Availables models:
 *	
 *	MQ-2 	- Propane C3H8 and Smoke
 *	MQ-3	- Alcohol Gas C2H5OH
 *	MQ-4	- Methane C2H5OH
 *	MQ-5	- Methane CH4 - Propane C3H8 - Butane C4H10
 *	MQ-6	- Propane C3H8
 *	MQ-7	- Carbon Monoxide CO
 *	MQ-8 	- Hydrogen Gas H2
 *	MQ-9	- Carbon Monoxide CO - Methane CH4 - Propane C3H8
 *	MQ-131	- Ozone O3 (Low Concentration)
 *	MQ-135	- Ammonia NH3 - Toluene C7H8 - Hydrogen Gas H2
 * 	MQ-136	- Hydrogen Sulfide H2S
 *	MQ-137	- Ammonia NH3
 *	MQ-138	- Alcohol Gas C2H5OH - Toluene C7H8 - Acetone C3H6O
 *
 **/
enum MQSensor_Model {MQ2, MQ3, MQ4, MQ5, MQ6, MQ7, MQ8, MQ9 ,MQ131, MQ135, MQ136, MQ137, MQ138};


/** 
 *	Enum for calibration mode
 * 
 *	- Simple: only the resistence is printed in the Serial Monitor
 *	- Complete: with complete informations including the values of temperature and humidity
 * 
*/

enum Calibration_mode {simple, complete};

// MQ Sensors Class Definition
class MQSensorsClass {
	public:
    // Constructor
    MQSensorsClass(uint32_t _RL);
    virtual ~MQSensorsClass();
  
		// Initialize the driver
		void begin(uint8_t _pinPower, uint8_t _pinSensor, MQSensor_Model _model, uint32_t _RL);

		// Manage a full cycle with delay() without giving the hand back to
		// the main loop (delay() function included)
		void sample();								

		// Read the concentration of gas
		// The environment should be set for accurate results
		float getGas(MQSensorUnit unit);

		// Set digital pin to DHT Sensor (DHT22, DHT11)
		void setDHT_pin_type(uint8_t _dhtPin, uint8_t _dhtType);

		// Define environment
		// Define the temperature (in Celsius) and humidity (in %) to adjust the
		// output values based on typical characteristics of the MQ131
		void setTempHum(int8_t _tempCelsius, uint8_t _humPercent);

		// Setup calibration: Time to read
		// Define the time to read after started the heater
		// Get function also available to know the value after calibrate()
		// (the time to read is calculated automatically after calibration)
		void setTimeToRead(uint32_t sec);
		long getTimeToRead();

		// Setup calibration: R0
		// Define the R0 for the calibration
		// Get function also available to know the value after calibrate()
		// (the time to read is calculated automatically after calibration)
		void setR0(float _valueR0);
		float getR0();

		/** 
		 * Metode to calibrate the sensor e get the R0 and the time to read consistently
		 * 
		 * Launch full calibration cycle
		 * Ideally, 20°C 65% humidity in clean fresh air (can take some minutes)
		 * For further use of calibration values, please use getTimeToRead() and getR0()
		 * 
		 * There are two ways to calibrate: simple and complete ways
		 * Simple way: just the resistence is printed in the Serial Monitor
		 * Complete way: the informations is more complete, the value of temperature and humidity is printed, the absolute error is also printed
		*/

		void calibrate(Calibration_mode _mode);

		// Read temperature and humidity from DHT22 or DHT11
		// Print the temperature and humidity
		void readTemperatureHumidity();

		// Set value of the coefficient A from the graphs
		void setA(float _valueA);

		// Set value of the coefficient B from the graphs
		void setB(float _valueB);

	private:
    // Internal helpers
		// Internal function to manage the heater
		void startHeater();
		bool isTimeToRead();
		void stopHeater();

		// Internal reading function of Rs
		float readRs();

		// Get environmental correction to apply on ration Rs/R0
		float getEnvCorrectRatio();

    // Convert gas unit of gas concentration
    float convert(float input, MQSensorUnit unitIn, MQSensorUnit unitOut);

    // Internal variables

		// Model of MQSensor
		MQSensor_Model model;

		// Details about the circuit: pins and load resistance value
		uint8_t pinPower = -1;
		uint8_t pinSensor = -1;
		uint32_t valueRL = -1;

		// Timer to keep track of the pre-heating
		uint32_t secLastStart = -1;
		uint32_t secToRead = -1;

		// Calibration of R0
		float valueR0 = -1;

		// Last value for sensor resistance
		float lastValueRs = -1;

		// Parameters for environment
		uint8_t temperatureCelsius;			// temperature in Celsius
		uint8_t humidityPercent;			// humidity in percent
		
		// Coefficient A. from the graphs
		float coef_a;
		// Coefficient B, from the graphs
		float coef_b;

		uint8_t dhtPin = 5; 				// Default pin 5 to DHT22
		uint8_t dhtType = DHT22;			// DHT22  (AM2302), AM2321

};

extern MQSensorsClass MQSensor;

#endif // _MQSensors_H_
