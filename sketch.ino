#include <LiquidCrystal.h>
#include <dht.h>

#define LCD_LIGHT_PIN A4

const int ROSSO = 9;
const int GIALLO = 13;
const int BLU = 10;
const int BIANCO = 6;
// tempo di transizione colore
const int delayTime = 20;

const int buttonPin = 8;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int greenPin = A0;
dht sensor;
int buttonState = 0;

void setup()
{

   // imposta il pin digitale come output
  pinMode(BIANCO, OUTPUT);
  pinMode(GIALLO, OUTPUT);
  pinMode(BLU, OUTPUT);
  pinMode(ROSSO, OUTPUT);
 
 
  // si impostano ad HIGH i pin VERDE, BLU, ROSSO
  // inizialmente il led RGB sarà spento
  digitalWrite(BIANCO, LOW);
  digitalWrite(BLU, LOW);
  digitalWrite(GIALLO, LOW);
  digitalWrite(ROSSO, LOW);
  
  lcd.begin(16,2); //16 by 2 character display
 // lcd.noDisplay();

  pinMode(buttonPin, INPUT);

   // Set the LCD display backlight pin as an output.
  pinMode(LCD_LIGHT_PIN, OUTPUT);

  // Turn off the LCD backlight.
  digitalWrite(LCD_LIGHT_PIN, LOW);

  
  Serial.begin(9600); //set baud rate
}

void loop()
{
  buttonState = digitalRead(buttonPin);
 
  sensor.read11(greenPin);
  String myString = String(sensor.temperature);
  //Serial.println(myString);

  if(sensor.temperature >= 23.00){
    delay(delayTime);
    analogWrite(ROSSO, 5);
  }
  else if(sensor.temperature <= 20.00){
    delay(delayTime);
    analogWrite(BIANCO, 5);
  }
  else{
      delay(delayTime);
      digitalWrite(ROSSO, LOW);
      digitalWrite(BIANCO, LOW);
  }

  Serial.println(sensor.humidity);

  if(sensor.humidity <= 35.00){
    delay(delayTime);
    digitalWrite(GIALLO, HIGH);
  }
  else if(sensor.humidity >= 55.00){
    delay(delayTime);
    analogWrite(BLU, 5);
  }
  else{
      delay(delayTime);
      digitalWrite(BLU, LOW);
      digitalWrite(GIALLO, LOW);

  }


  if (buttonState == HIGH)
  {
    
  lcd.display();

  lcd.clear();
  lcd.setCursor(0,0);
  digitalWrite(LCD_LIGHT_PIN, HIGH);
  
  lcd.print("Humidity = ");
  lcd.print(sensor.humidity);
  lcd.setCursor(0,1);
  lcd.print("Temp = ");
  lcd.print(sensor.temperature);
  
  delay(5000); //wait a sec (recommended for DHT11)
  lcd.noDisplay();
  digitalWrite(LCD_LIGHT_PIN, LOW);

  }
  delay(1000);
}
