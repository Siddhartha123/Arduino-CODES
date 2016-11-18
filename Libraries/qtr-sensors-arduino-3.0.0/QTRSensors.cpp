#include <stdlib.h>
#include "QTRSensors.h"
#include <Arduino.h>

// Operates the same as read calibrated, but also returns an
// estimated position of the robot with respect to a line. The
// estimate is made using a weighted average of the sensor indices
// multiplied by 1000, so that a return value of 0 indicates that
// the line is directly below sensor 0, a return value of 1000
// indicates that the line is directly below sensor 1, 2000
// indicates that it's below sensor 2000, etc.  Intermediate
// values indicate that the line is between two sensors.  The
// formula is:
//
//    0*value0 + 1000*value1 + 2000*value2 + ...
//   --------------------------------------------
//         value0  +  value1  +  value2 + ...
//
// By default, this function assumes a dark line (high values)
// surrounded by white (low values).  If your line is light on
// black, set the optional second argument white_line to true.  In
// this case, each sensor value will be replaced by (1000-value)
// before the averaging.

int QTRSensorsAnalog::readline(unsigned int *sensor_values)
{
    unsigned char i, on_line = 0;
    unsigned long avg; // this is for the weighted total, which is long
                       // before division
    unsigned int sum; // this is for the denominator which is <= 64000


    avg = 0;
    sum = 0;

    for(i=0;i<_numSensors;i++) {
        int value = sensor_values[i];//white line
        // keep track of whether we see the line at all
        if(value > 200) {//change this value to reading on white
            on_line = 1;
        }

        // only average in values that are above a noise threshold
       // if(value > 50) {
            avg += (long)(value) * (i * 1000);
            sum += value;
        //}
    }
	/*
    if(!on_line)
    {
        // If it last read to the left of center, return 0.
        if(_lastValue < (_numSensors-1)*1000/2)
            return 0;

        // If it last read to the right of center, return the max.
        else
            return (_numSensors-1)*1000;

    }
	*/
    _lastValue = avg/sum;

    return _lastValue;
}
// the array 'pins' contains the Arduino analog pin assignment for each
// sensor.  For example, if pins is {0, 1, 7}, sensor 1 is on
// Arduino analog input 0, sensor 2 is on Arduino analog input 1,
// and sensor 3 is on Arduino analog input 7.
// 'numSensors' specifies the length of the 'analogPins' array (i.e. the
// number of QTR-A sensors you are using).  numSensors must be
// no greater than 16.
// 'numSamplesPerSensor' indicates the number of 10-bit analog samples
// to average per channel (i.e. per sensor) for each reading.  The total
// number of analog-to-digital conversions performed will be equal to
// numSensors*numSamplesPerSensor.  Note that it takes about 100 us to
// perform a single analog-to-digital conversion, so:
// if numSamplesPerSensor is 4 and numSensors is 6, it will take
// 4 * 6 * 100 us = ~2.5 ms to perform a full readLine().
// Increasing this parameter increases noise suppression at the cost of
// sample rate.  The recommended value is 4.
// Reads the sensor values into an array. There *MUST* be space
// for as many values as there were sensors specified in the constructor.
// Example usage:
// unsigned int sensor_values[8];
// sensors.read(sensor_values);
// The values returned are a measure of the reflectance in terms of a
// 10-bit ADC average with higher values corresponding to lower
// reflectance (e.g. a black surface or a void).
QTRSensorsAnalog::QTRSensorsAnalog(int a,int b,int c,int d,int e)
{
	_pins[0] = a;
	_pins[1] = b;
	_pins[2] = c;
	_pins[3] = d;
	_pins[4] = e;
}
void QTRSensorsAnalog::readPrivate(unsigned int *sensor_values)
{
    unsigned char i;
	memset(sensor_values, 0, sizeof(sensor_values));
		/*for (i = 0; i < _numSensors; i++)
		{
			sensor_values[i] = analogRead(_pins[i]);  
		}*/
	sensor_values[0] = analogRead(A0);
	sensor_values[1] = analogRead(A1);
	sensor_values[2] = analogRead(A2);
	sensor_values[3] = analogRead(A3);
	sensor_values[4] = analogRead(A4);

}