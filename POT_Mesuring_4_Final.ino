int sensorPin = 0;
int sensorValue = 0;
float EMA_a = 0.3;
int EMA_S = analogRead(sensorPin);

void setup() {
  Serial.begin(9600);
    for (int j = 0; j < 10201; j++) {   
    sensorValue = analogRead(sensorPin);
    EMA_S = (EMA_a * sensorValue) + ((1 - EMA_a) * EMA_S);
    if (j > 200) {
    Serial.println(EMA_S);
    }
  }
}

void loop() {

}
