void blink(int pin, int times, int del) {
    for (; times != 0; times--) {
        Serial.println("BLINK");
        digitalWrite(pin, HIGH);
        delay(del);
        digitalWrite(pin, LOW);
        delay(del);
    }  
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  blink(LED_BUILTIN, 3, 1000);

}

void loop() {
  // put your main code here, to run repeatedly:

}
