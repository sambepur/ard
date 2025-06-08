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
        reset();
    }
    if (digitalRead(DISP)) {
        delay(3000);
        blink(random(RED, BLUE), score, 500);
        delay(3000);
    }
    n = random(RED, BLUE);
    diff = BLUE - n;
    digitalWrite(n, HIGH);
    delay(1000);
    st = digitalRead(BLUE_C - diff);
    delay(1000);
    if (st == HIGH) {
        score++;
        digitalWrite(n ,LOW);
        blink(LED_BUILTIN, 3, 500);
    }
    else {
        digitalWrite(n ,LOW);
        blink(LED_BUILTIN, 1, 3000);
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
