const int I=9;
const int R=8;
const int T=7;
const int U=6;
const int E=5;
const int N=4;
const int H=3;
const int G=2;
const int delays = 500;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(I, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(T, OUTPUT);
  pinMode(U, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(N, OUTPUT);
  pinMode(H, OUTPUT);
  pinMode(G, OUTPUT);
  
}

// the loop function runs over and over again forever
void loop() {
  right();
  here();
  runn();
  everything();
  everything();
  everything();
  everything();
  everything();
  everything2();
  everything2();
  everything2();
  everything2();
  everything2();
}

void right() {
  digitalWrite(R, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delays);                       // wait for a second
  digitalWrite(R, LOW);    // turn the LED off by making the voltage LOW
  delay(delays);                       // wait for a second
  digitalWrite(I, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delays);                       // wait for a second
  digitalWrite(I, LOW);    // turn the LED off by making the voltage LOW
  delay(delays);                       // wait for a second
  digitalWrite(G, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delays);                       // wait for a second
  digitalWrite(G, LOW);    // turn the LED off by making the voltage LOW
  delay(delays);                       // wait for a second
  digitalWrite(H, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delays);                       // wait for a second
  digitalWrite(H, LOW);    // turn the LED off by making the voltage LOW
  delay(delays);                       // wait for a second
  digitalWrite(T, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delays);                       // wait for a second
  digitalWrite(T, LOW);    // turn the LED off by making the voltage LOW
  delay(delays);                       // wait for a second
}

void here() {
  digitalWrite(H, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delays);                       // wait for a second
  digitalWrite(H, LOW);    // turn the LED off by making the voltage LOW
  delay(delays);                       // wait for a second
  digitalWrite(E, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delays);                       // wait for a second
  digitalWrite(E, LOW);    // turn the LED off by making the voltage LOW
  delay(delays);                       // wait for a second
  digitalWrite(R, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delays);                       // wait for a second
  digitalWrite(R, LOW);    // turn the LED off by making the voltage LOW
  delay(delays);                       // wait for a second
  digitalWrite(E, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delays);                       // wait for a second
  digitalWrite(E, LOW);    // turn the LED off by making the voltage LOW
  delay(delays);                       // wait for a second
}

void runn() {
  digitalWrite(R, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delays);                       // wait for a second
  digitalWrite(R, LOW);    // turn the LED off by making the voltage LOW
  delay(delays);                       // wait for a second
  digitalWrite(U, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delays);                       // wait for a second
  digitalWrite(U, LOW);    // turn the LED off by making the voltage LOW
  delay(delays);                       // wait for a second
  digitalWrite(N, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delays);                       // wait for a second
  digitalWrite(N, LOW);    // turn the LED off by making the voltage LOW
  delay(delays);                       // wait for a second
}

void everything() {
  digitalWrite(R, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(I, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(G, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(H, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(T, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(E, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(N, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(U, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);
  digitalWrite(R, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(I, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(G, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(H, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(T, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(E, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(N, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(U, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(100);
}

void everything2() {
  digitalWrite(R, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(I, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(G, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(H, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(T, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(E, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(N, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(U, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);
  digitalWrite(R, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(I, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(G, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(H, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(T, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(E, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(N, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(U, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(50);
}
  


