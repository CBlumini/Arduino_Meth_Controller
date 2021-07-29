/*
  Analog input, analog output, serial output

  Reads an analog input pin, maps the result to a range from 0 to 255 and uses
  the result to set the pulse width modulation (PWM) of an output pin.
  Also prints the results to the Serial Monitor.

  The circuit:
  - potentiometer connected to analog pin 0.
    Center pin of the potentiometer goes to the analog pin.
    side pins of the potentiometer go to +5V and ground
  - LED connected from digital pin 9 to ground

  created 29 Dec. 2008
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInOutSerial
*/

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  // Pins D9 and D10 - 62.5 kHz
  //TCCR1A = 0b00000001; // 8bit
  //TCCR1B = 0b00001001; // x1 fast pwm
  // Pins D9 and D10 - 31.4 kHz
  //TCCR1A = 0b00000001; // 8bit
  //TCCR1B = 0b00000001; // x1 phase correct
  // Pins D9 and D10 - 7.8 kHz
  //TCCR1A = 0b00000001; // 8bit
  //TCCR1B = 0b00001010; // x8 fast pwm
  // Pins D9 and D10 - 4 kHz
  //TCCR1A = 0b00000001; // 8bit
  //TCCR1B = 0b00000010; // x8 phase correct
  // Pins D9 and D10 - 976 Hz
  //TCCR1A = 0b00000001; // 8bit
  //TCCR1B = 0b00001011; // x64 fast pwm
  // Pins D9 and D10 - 490 Hz - default
  //TCCR1A = 0b00000001; // 8bit
  //TCCR1B = 0b00000011; // x64 phase correct
  // Pins D9 and D10 - 244 Hz
  //TCCR1A = 0b00000001; // 8bit
  //TCCR1B = 0b00001100; // x256 fast pwm
  // Pins D9 and D10 - 122 Hz
  //TCCR1A = 0b00000001; // 8bit
  //TCCR1B = 0b00000100; // x256 phase correct
  // Pins D9 and D10 - 61 Hz
  //TCCR1A = 0b00000001; // 8bit
  //TCCR1B = 0b00001101; // x1024 fast pwm
  // Pins D9 and D10 - 30 Hz
  TCCR1A = 0b00000001; // 8bit
  TCCR1B = 0b00000101; // x1024 phase correct
}

void loop() {
  // read the analog in value:
  sensorValue = 750;
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}
