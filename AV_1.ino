int sensorPin = 0;
int sensorValue = 0;
int EMA_S = 0;
int EMA_T = 0;
int totalx = 0;
int EMA_AV = 0;
int nSamp = 10;

void setup() {
  Serial.begin(9600); 
  EMA_S = analogRead(sensorPin);
  EMA_T = EMA_S;     
  
  for (int i = 0; i < 960; i++) {
    for (int i = 0; i < nSamp; i++) {
      EMA_S = analogRead(sensorPin);
      EMA_T = EMA_T + EMA_S;
    }
  
    EMA_AV = EMA_T / nSamp;
  
      if (EMA_AV != EMA_S) {
      totalx = totalx + 1;
      Serial.println("x"); 
      }
      else{
      Serial.println(EMA_AV);
      }
  }
    Serial.println(EMA_T); 
    Serial.println(totalx);
}



void loop() {
}


  
