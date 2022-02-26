int sensorPin = 0;          //pin number
int sensorValue = 0;        //initialization of sensor variable, equivalent to EMA Y
float EMA_a = 0.1;          //initialization of EMA alpha
int EMA_S = 0;              //initialization of EMA S

void setup() {
  Serial.begin(9600);
  EMA_S = analogRead(sensorPin);
}
  
void loop() {
  sensorValue = analogRead(sensorPin);
  EMA_S = (EMA_a * sensorValue) + ((1 - EMA_a) * EMA_S); //Moving Average Aglorithm
  Serial.println(EMA_S);
  delay(10);
  Joystick.X(EMA_S);
  Joystick.send_now();
}
