int sensorPin = 0;          //pin number
int sensorValue = 0;        //initialization of sensorValue
float EMA_a = 0.1;          //initialization of EMA alpha

void setup() {
  Serial.begin(9600);
}
  
void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  delay(10);
  Joystick.X(sensorValue);
  Joystick.send_now();
}
