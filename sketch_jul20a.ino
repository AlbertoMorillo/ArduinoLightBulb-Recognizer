#include <SoftwareSerial.h>

int relayPin = 7;

#define SOFTSERIAL_RX_PIN  2
#define SOFTSERIAL_TX_PIN  3
 
SoftwareSerial softSerial(SOFTSERIAL_RX_PIN,SOFTSERIAL_TX_PIN);
 
const char *voiceBuffer[] =
{
    "Turn on the light",
    "Turn off the light",
    "Play music",
    "Pause",
    "Next",
    "Previous",
    "Up",
    "Down",
    "Turn on the TV",
    "Turn off the TV",
    "Increase temperature",
    "Decrease temperature",
    "What's the time",
    "Open the door",
    "Close the door",
    "Left",
    "Right",
    "Stop",
    "Start",
    "Mode 1",
    "Mode 2",
    "Go",
    "Blink"
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    softSerial.begin(9600);
    softSerial.listen();
  pinMode(relayPin, OUTPUT);
}

void loop() {
  char cmd;
  // put your main code here, to run repeatedly:
  if(softSerial.available())
  {
      cmd = softSerial.read();
      Serial.println(voiceBuffer[cmd - 1]);
      if(voiceBuffer[cmd - 1] == "Turn on the light"){
        digitalWrite(relayPin, LOW);
      }
      if(voiceBuffer[cmd - 1] == "Turn off the light"){
        digitalWrite(relayPin, HIGH);
        }

      if(voiceBuffer[cmd - 1] == "Go"){
        for(int i = 0; i <=5; i++){
          digitalWrite(relayPin, HIGH);
          delay(500);
          digitalWrite(relayPin, LOW);
          delay(500);
        }
      }
  }
}
