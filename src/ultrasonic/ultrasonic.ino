#include <HCSR04.h>
#define trigPin 7
#define echoPin 8
#define buttonPin 12   
#define executePin 13   //pin execute device
#define ledColibrPin 6  //pin info of process colibration
#define ledErrorPin 5   //pin info error of ground level 
#define levelEquel 5    //response threshold

UltraSonicDistanceSensor distanceSensor(trigPin, echoPin);  // Initialize sensor 
int level;            //level of ground
int distance;
int dDistance;       //delta distance
boolean button, lastButton;   //value button colibration
bool    executeVal;           //value  execute device
bool    ledColibr;

void setup () 
{
  pinMode(buttonPin, INPUT);
  pinMode(executePin, OUTPUT);
  pinMode(ledColibrPin, OUTPUT);
  pinMode(ledErrorPin, OUTPUT);
  Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
  level = int (distanceSensor.measureDistanceCm()*10);
  colibrLed();
}

void loop () 
{    
    button = digitalRead(buttonPin);
    if (button)
    {
      if (!lastButton)
      {
        lastButton = true;
        level = int (distanceSensor.measureDistanceCm()*10);
        colibrLed();
        delay(5);
      };
    }
    else
    {
      lastButton = false;  
    }
            
    digitalWrite(executePin, isExecuteBurn());  //control execute device
    digitalWrite(ledErrorPin, isError()); //control device inform error of ground level
}

//method return - is burning to execute device
bool isExecuteBurn()
{  
  if (millis()%1000 == 0) // Every 1 second, do a measurement using the sensor and print the distance in centimeters.
  {
    distance = int (distanceSensor.measureDistanceCm()*10);  //translate to millimeter
    dDistance = level - distance;
    Serial.println(dDistance);              //debug info at console    
  }
  return dDistance > levelEquel;
}

//method return - is Error of ground level
bool isError()
{ 
  return dDistance < -levelEquel;
}

//procedure turn on led - it's OK 
void colibrLed (){
  for(int i=0; i<5; i++){
    digitalWrite(ledColibrPin, HIGH);
    delay(300);
    digitalWrite(ledColibrPin, LOW);
    delay(100);
  }
}
