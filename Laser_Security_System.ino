/*

      Laser Security System

Name: Bhavya Patel

      This code is required to run the Laser Security System:
 
*/
// Variable Declaration 

int led_pins1 = 3;  // Emergency lights 
int led_pins2 = 4; 
int led_pins3 = 5;
int led_pins4 = 6; 

int digits;        // Readings from LDR photo resistor 

int minSecsBetweenEmails = 60;   // Sending email after some time interval
long lastSend = -minSecsBetweenEmails * 1000l;

// Variable Declaration using constant

const int BUZZER_PIN = 12;  // Buzzer 

const int Button = 10;      // Button

const int analogPin = A1;   // Analogpin

const int red = 7;          // ON-OFF leds
const int green = 8;

// usnig threshold value according to the serial monitor readings

const int threshold = 600;


void setup()
{
  
  pinMode(red, OUTPUT);        // setting the ON-OFF lights as the Output
  pinMode(green, OUTPUT);
  
  pinMode(analogPin, INPUT);   // setting the analogpin as the input
  
  Serial.begin(9600);          // just to see the readings on the serial monitors

 pinMode(led_pins1, OUTPUT);   // setting Emergency lights as the Output
 pinMode(led_pins2, OUTPUT);   
 pinMode(led_pins3, OUTPUT);
 pinMode(led_pins4, OUTPUT);

 
 pinMode(Button, INPUT);       // setting Button as th input
 
}

void loop()
{
  digits = analogRead(analogPin);      // to read the values from A1
  
  Serial.println(digits);              // just to print the values as a reading on the serial monitor

  int buttonVal = 0;                   // initializing the button value 

  digitalWrite(green, HIGH);           // turn the green light ON
  
  
  
  while(digits <= threshold)    // if the readings are less than the threshold START the laser security system 
  {
  
   long now = millis();         // it will send the message to the phone
    
    if (now > (lastSend + minSecsBetweenEmails * 1000l))
    {
      Serial.println("MOVEMENT");
      lastSend = now;
    }
    else
    {
      Serial.println(" Message already been sent ");
    }

  
  digitalWrite( green, LOW);    // turn the green light OFF
  
  digitalWrite( red, HIGH);     // turn the red light ON
  
  
 // Turning the Emergency lights ON with the Pattern   
 
  digitalWrite ( led_pins1 , HIGH );
  delay(150);
  digitalWrite ( led_pins2 , HIGH );
  delay(150);
  digitalWrite ( led_pins3 , HIGH );
  delay(150);
  digitalWrite ( led_pins4 , HIGH );
  delay(150);

  digitalWrite ( led_pins1 , LOW );
  delay(150);
  digitalWrite ( led_pins2 , LOW );
  delay(150);
  digitalWrite ( led_pins3 , LOW );
  delay(150);
  digitalWrite ( led_pins4 , LOW );
  delay(150);

// The buzzer will start ringing

  tone(BUZZER_PIN, 196 , 250 );


  buttonVal = digitalRead(Button); // The state of button is read
  Serial.println(buttonVal);

// If the button state is low then it will turn the red light off and will end the Laser security system working

  if (buttonVal == LOW)
  {
     digitalWrite(red, LOW);
   break;
  } 

  }

  delay(500);    // just for blocking half second from going to next line
}
