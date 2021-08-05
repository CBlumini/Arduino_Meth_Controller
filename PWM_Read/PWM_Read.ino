#define pulse_ip 7
int ontime,offtime,duty;
float freq,period;
const int pumpPin = 5; //Digital pin for for pump relay

#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  
   
void setup()
{
  pinMode(pulse_ip,INPUT);
  pinMode(pumpPin, OUTPUT);
  
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
  lcd.begin(16, 4);
  lcd.clear();
  lcd.print("Freq:");
  lcd.setCursor(0,1);
  lcd.print("Duty:");  
}



void loop()
{
  //read the duty
   ontime = pulseIn(pulse_ip,HIGH);
   offtime = pulseIn(pulse_ip,LOW);
   period = ontime+offtime;
   freq = 1000000.0/period;
   duty = (ontime/period)*100; 

 //trigger the pump
if (duty > 35)
{
  digitalWrite(pumpPin, LOW);
}
else
{
  digitalWrite(pumpPin, HIGH);
}

   
   
   //dispay the reading
   lcd.setCursor(5,0); 
   lcd.print(freq);
   lcd.print("Hz");
   lcd.setCursor(6,1);
   lcd.print(duty); 
   lcd.print('%'); 
   delay(1000);
}
