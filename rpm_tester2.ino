/*
    __  ___ ___     ____   ______ ______ __    ____     __  __ ____   _   __                                __         
   /  |/  //   |   / __ \ / ____// ____// /   / __ \   / / / // __ \ / | / /    _____ ____   ____ ___      / /_   _____
  / /|_/ // /| |  / /_/ // /    / __/  / /   / / / /  / /_/ // /_/ //  |/ /    / ___// __ \ / __ `__ \    / __ \ / ___/
 / /  / // ___ | / _, _// /___ / /___ / /___/ /_/ /  / __  // ____// /|  /  _ / /__ / /_/ // / / / / /_  / /_/ // /    
/_/  /_//_/  |_|/_/ |_| \____//_____//_____/\____/  /_/ /_//_/    /_/ |_/  (_)\___/ \____//_/ /_/ /_/(_)/_.___//_/     



Press "+" or "-" on serial monitor to increase or decrease rpm.

See attached schematic to drive the cluster rpm

                                                                                                                   
*/


#define tach 6

int rpm = 3000;
int freq;

void setup() {
  pinMode(rpm, OUTPUT);
  digitalWrite(rpm, LOW);
  Serial.begin(9600);
}

void loop() {
  
  handleSerial();

  freq = rpm * 4 / 120;
  tone(tach, freq);
  
}



void handleSerial() {
 while (Serial.available() > 0) {
   char incomingCharacter = Serial.read();
   switch (incomingCharacter) {
     case '+':
      rpm = rpm + 100;
      if (rpm > 10000) rpm = 10000;
      break;
 
     case '-':
      rpm = rpm - 100;
      if (rpm < 1000) rpm = 1000;
      break;
    }
    Serial.print("RPM: ");
    Serial.println(rpm);
 }
}
