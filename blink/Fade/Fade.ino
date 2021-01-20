int leds[3] = {11, 10, 9};
int brightness[3];
int fadeAmount[3] = {10, 5, 5};
int fps = 4;
int lim = 255;
int delayAmount = (1000 / fps) / (lim / 5);
int diff = 100;

void setup()  { 
  Serial.begin(9600);
  for (int i = 0; i < sizeof(leds) / sizeof(int); i++){
    Serial.println(i);
    Serial.println(leds[i]);
    pinMode(leds[i], OUTPUT);
    brightness[i] = brightness[i] + diff * i;
    
  }
} 

void loop()  {
  for (int i = 0; i < sizeof(leds) / sizeof(int); i++) {
    analogWrite(leds[i], brightness[i]);
    brightness[i] = brightness[i] + fadeAmount[i];
    if (brightness[i] % lim == 0) {
      fadeAmount[i] = -fadeAmount[i]; 
    }
}
  
  delay(delayAmount);                         
}

