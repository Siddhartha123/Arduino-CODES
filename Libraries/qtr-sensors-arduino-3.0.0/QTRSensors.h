#ifndef QTRSensors_h
#define QTRSensors_h

#define QTR_EMITTERS_OFF 0
#define QTR_EMITTERS_ON 1
#define QTR_EMITTERS_ON_AND_OFF 2

#define QTR_NO_EMITTER_PIN  255

#define QTR_MAX_SENSORS 16

class QTRSensorsAnalog
{
  public:
	  QTRSensorsAnalog(int, int, int, int, int);
	  void read(unsigned int *sensor_values, unsigned char readMode = QTR_EMITTERS_ON);

	  int _pins[5];
	  unsigned char _numSensors = 5;
	  int sensor_values[5];
	  int _lastValue;
    
	int readline(unsigned int *sensor_values);
    void readPrivate(unsigned int *sensor_values);
    unsigned char _numSamplesPerSensor;
};
#endif
