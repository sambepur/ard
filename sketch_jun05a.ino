#define BLUE 10
#define GREEN 9
#define RED 8
#define BLUE_C 7
#define GREEN_C 6
#define RED_C 5
#define RESET 4
#define DISP 3

void blink(int, int);
void reset();

int score = 0;
int n;
int diff;
int st;

void setup() {
  Serial.begin(9600);
  pinMode(DISP, INPUT);
  pinMode(RESET, INPUT);
  pinMode(BLUE_C, INPUT);
  pinMode(GREEN_C, INPUT);
  pinMode(RED_C, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);  
}

void loop() {
    if (digitalRead(RESET)) {
        Serial.println("RESET");
        reset();
    }
    if (digitalRead(DISP)) {
        Serial.print("SCORE: ");
        Serial.println(score, DEC);
    }
    n = random(RED, BLUE);
    Serial.println(n, DEC);
    diff = BLUE - n;
    Serial.println(diff, DEC);
    digitalWrite(n, HIGH);
    delay(3000);
    Serial.println(BLUE_C - diff, DEC);
    st = digitalRead(BLUE_C - diff);
    Serial.println(st, DEC);
    delay(1000);
    if (st == HIGH) {
        score++;
        Serial.println("INCR");
        digitalWrite(n ,LOW);
        blink(LED_BUILTIN, 3, 500);
    }
    else {
        Serial.println("MISS");
        digitalWrite(n ,LOW);
        blink(LED_BUILTIN, 1, 5000);
    }
}

void blink(int pin, int times, int del) {
    for (; times != 0; times--) {
        digitalWrite(pin, HIGH);
        delay(del);
        digitalWrite(pin, LOW);
        delay(del);
    }  
}

void reset() {
  score = 0;
  blink(LED_BUILTIN, 3, 1000);  
}
