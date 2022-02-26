
int sensorPin = 0;
int sensorValue = 0;
float EMA_a = 1;
int EMA_S = 0;

void setup() {
  Serial.begin(9600);
  EMA_S = analogRead(sensorPin); 
}

void loop() {
    EMA_S = analogRead(sensorPin);        
    Serial.println(EMA_S);
    delay(10);
}

  
