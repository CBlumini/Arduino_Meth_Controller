
const int analogOutPin = 9; // Analog output pin that the LED is attached to
const int buttonPin = 0; //Digital pin for duty cycle adjustment interface

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
int count = 0;              // value to adjust duty based on button push

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

  //set mode for button pin
  pinMode (buttonPin, INPUT_PULLUP);
  
  //set PWM frequency 
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
  // read if the button is pushed and adjust duty:
    if(digitalRead(buttonPin) == 0)
  {
    count=count+25;  // increment 'count' by 1
    sensorValue = count;
    if(count > 1026)
      count = 0;
    delay(200);  // wait 200 milliseconds
  }

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
