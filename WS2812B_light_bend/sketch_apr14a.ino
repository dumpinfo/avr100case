#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>
#include <DynamicCommandParser.h>

#include <MPU6050_tockn.h>

#define ADD true
#define SUB false
int val1 = 0;
int valr = 25;
int valg = 25;
int valb = 25;
boolean stat = ADD;





 


int counter = 1000;
boolean countdownActive = false;
unsigned long last_count_time = 0;
unsigned long last_sens_time = 0;
int count_speed = 1000;
int sens_speed = 100;

int incomingByte = 0;
DynamicCommandParser dcp('^', '$', ',');

float threshold = 0.5;
int stepCounter = 0;
int stepDuration = 300;
long timer = 0;
MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(9600);
  dcp.addParser("start", startCommand);
  dcp.addParser("stop", stopCommand);
  dcp.addParser("set_light", lightCommand);
   dcp.addParser("set_red", redCommand);
     dcp.addParser("set_green", greenCommand);
       dcp.addParser("set_blue", blueCommand);
 



 
 
  // put your setup code here, to run once:
  Timer1.initialize();
  MFS.initialize(&Timer1);

  Wire.begin(); 
  mpu6050.begin();

}

void loop() {


  if (counter > 0 && countdownActive)
  
{   
 


  }

  while (Serial.available() > 0)
  {
    dcp.appendChar(Serial.read());
  }

  mpu6050.update();
  if(millis() - timer > stepDuration){
  if(abs(mpu6050.getAccY()) > threshold) { stepCounter++;
  Serial.print("Steps: "); 
  Serial.println(stepCounter);
  }
    timer = millis();
  }


  
}

  // Parser for the start command
void startCommand(char **values, int valueCount)
{

  countdownActive = true;
  valr=25;
  valg=25;
  valb=25;
}


// Parser for the start command

void stopCommand(char **values, int valueCount)
{
  countdownActive = false;

}


void lightCommand(char **values, int valueCount)
{
  valr= atoi(values[1]);
  valg= atoi(values[1]);
  valb= atoi(values[1]);

  
}

void redCommand(char **values, int valueCount)
{
  valr= atoi(values[1]);
}

void greenCommand(char **values, int valueCount)
{
  valg=atoi(values[1]);
}

void blueCommand(char **values, int valueCount)
{
  valb= atoi(values[1]);
}

void temperaturedownCommand(char **values, int valueCount)
{

valb=valb- atoi(values[1]);
  
}
// Parser for the set time command
void temperatureupCommand(char **values, int valueCount)
{
  valr=valb+atoi(values[1]);

 
}




