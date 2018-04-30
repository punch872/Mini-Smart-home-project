const int GPIO_0 = A6;
const int GPIO_2 = A7; 

void setup() {
  // put your setup code here, to run once:
  digitalWrite(GPIO_0,HIGH);
  digitalWrite(GPIO_2,HIGH);
  Serial.begin(9600);
  pinMode(GPIO_0,INPUT);
  pinMode(GPIO_2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int wifiValue1 = analogRead(GPIO_0);
  int wifiValue2 = analogRead(GPIO_2);
  Serial.print("GPIO_0 (pin A6) = ");
  Serial.println(wifiValue1);
  Serial.print("GPIO_1 (pin A7) = ");
  Serial.println(wifiValue2);
}
