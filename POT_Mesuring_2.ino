
int sensorPin = 0;
int sensorValue = 0;
float EMA_a = 0.1;
float EMA_b = 1;
int EMA_S = 0;
int EMA_T = 0;
int totalx = 0;
int total = 0;

void setup() {
  Serial.begin(9600);
  EMA_S = analogRead(sensorPin);
  
  for (int i = 0; i < 1; i++) {
    for (int i = 0; i < 10000; i++) {
      sensorValue = analogRead(sensorPin);
      EMA_S = (EMA_a * sensorValue) + ((1 - EMA_a) * EMA_S);
      EMA_T = (EMA_b * sensorValue) + ((1 - EMA_b) * EMA_S);       
      total = total + 1;
  
        if (EMA_S != EMA_T) {
        totalx = totalx + 1;
        Serial.println("x"); 
        }
        else{
        Serial.println(EMA_S);
        }
      }
      Serial.println("==============================");
  }
      Serial.println(total);
      Serial.println(totalx);
      Serial.println(totalx / 10);
      Serial.println(total-totalx);
      Serial.println((total-totalx)/10);    
}

void loop() {
}

  
