/*
 * Please check this project on GitHub for more information:
 * https://github.com/ProgrammerPeter2/LedTesterForArduinoNano
 */
  boolean onState = false;
  boolean LedMode = false;
  int LedLastState = LOW;
  int sens = 0;
  float volt = 3.3f;
//pins
  const int onOffSwitch = 2;
  const int onLed = 13;
  const int rele = 3;
  const int ledSwitch = 4;
  const int Led1 = 5;
  const int Led2 = 6;
  const int SysOut = 7;
void setup() {
  // set pin modes
  pinMode(onOffSwitch, INPUT);
  pinMode(onLed, OUTPUT);
  pinMode(rele, OUTPUT);
  pinMode(ledSwitch, INPUT);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(SysOut, OUTPUT);
}

void loop() {
  // get inputs
  int switchState = digitalRead(onOffSwitch);
  int ledState = digitalRead(ledSwitch);
  sens = analogRead(A0);
  //check main switch and set main led and the rele module
  if(switchState == HIGH){
    digitalWrite(onLed, HIGH);
    digitalWrite(rele, HIGH);
    onState = true;
  }else{
    digitalWrite(onLed, LOW);
    digitalWrite(rele, LOW);
    onState = false;
  }
  if(onState){
    //check led button
    if(ledState == LOW && LedLastState == HIGH){ //a simple button switch if
      LedMode = !LedMode; // set LedMode to it's opposite value
      if(LedMode){// turn leds to on/off 
        digitalWrite(Led1, HIGH);
        digitalWrite(Led2, HIGH);
      }else{
        digitalWrite(Led1, LOW);
        digitalWrite(Led2, LOW);
      }
    }
    LedLastState = ledState;//set LedSwitch last state to this value
    if(sens > 0){// if connected pottmeter to arduino
      volt = sens*(1023/5.0);
      analogWrite(SysOut, volt);
    }
  }
}
