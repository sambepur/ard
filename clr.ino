/* Blink
   Turns on an LED on for one second, then off for one second, repeatedly.
*/
#define BUTTON_PIN 2
#define YELL 4
#define RED 3
#define GRE 5
int curr_state = 0;
void setup() {
   pinMode(BUTTON_PIN, INPUT);
   //pinMode(LED_BUILTIN, OUTPUT);
   pinMode(YELL, OUTPUT);
   pinMode(RED, OUTPUT);
   pinMode(GRE, OUTPUT);
}

void loop() {
   if ((curr_state = digitalRead(BUTTON_PIN)) == HIGH) {
        delay(5000);
        digitalWrite(RED, LOW);
        digitalWrite(YELL, HIGH);
        delay(2000);
        digitalWrite(YELL, LOW);
        digitalWrite(GRE, HIGH);
        delay(5000);
        digitalWrite(GRE, LOW);
   }
   else {
      digitalWrite(RED, HIGH);
   }
}
