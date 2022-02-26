int sensorPin = 0;          //pin number
int sensorValue = 0;        //initialization of sensorValue
float EMA_a = 0.1;          //initialization of EMA alpha
float EMA_b = 1;            //initialization of EMA beta
int EMA_S = 0;              //initialization of EMA S
int EMA_T = 0;              //initialization of EMA T
int totalx = 0;
int total = 0;

void setup() {
  // you can print to the serial monitor while the joystick is active!
  Serial.begin(9600);
  EMA_S = analogRead(sensorPin);

float reference = 0;

reference = 401;
Serial.println(sensorValue);

for (int i = 0; i < 960; i++) {
    sensorValue = analogRead(sensorPin);                //read the sensor value using ADC
  EMA_S = (EMA_a * sensorValue) + ((1 - EMA_a) * EMA_S); //run the EMA
  Serial.println(EMA_S);                              //print digital value to serial
  //delay(10);
  Joystick.X(EMA_S);

  EMA_T = (EMA_b * sensorValue) + ((1 - EMA_b) * EMA_S);
  Serial.println(EMA_S);                            
  //delay(10);
  Joystick.X(EMA_S);
  
  total = total + 1;
  
    if (EMA_S != EMA_T) {
    totalx = totalx + 1;
    Serial.println("x"); 
    }
    }

  Serial.println(totalx);
  Serial.println(total);
}






void loop() {
  }

  
