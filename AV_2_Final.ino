int sensorPin = 0;
int sensorValue = 0;
int EMA_S = 0;
int EMA_T = 0;
int totalx = 0;
int EMA_AV = 0;
int nSamp = 30;

void setup() {
  Serial.begin(9600); 
  for (int j = 0; j < 10000; j++) {
  EMA_S = analogRead(sensorPin);    
  EMA_T = EMA_S; 
      for (int i = 0; i < nSamp; i++) {
      EMA_S = analogRead(sensorPin);
      EMA_T = EMA_T + EMA_S;
    }
      EMA_AV = EMA_T / nSamp;
      Serial.println(EMA_AV);
  }
}
void loop() {
}
