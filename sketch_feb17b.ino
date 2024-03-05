const float pi=3.14159265358979323846;
const int frequency=1;
unsigned long previousMillis=0;
const long interval=10;



void setup() {
  // put your setup code here, to run once:
  for(int pin=2; pin<=9; pin++){
    pinMode(pin, OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis=millis();
  if(currentMillis-previousMillis >=interval){
    previousMillis= currentMillis;

    for(int pin=2;pin<=9;pin++){
      float phi=2*pi*(pin-2)/8;
      float value =sin(2*pin*frequency*currentMillis/1000+phi);
      int brightness = map((value+1)*127.5,0, 255, 0, 255);
      analogWrite(pin, brightness);
    }
  }

}
