#define R 13 //กำหนดขาที่นำไปต่อกับรีเลย์

#define L 12
char test ; //สร้างตัวแปรไว้สำหรับรอรับข้อมูล
void setup() 
{
// Open serial communications and wait for port to open:
Serial.begin(9600);
pinMode(R, OUTPUT); // กำหนดโหมดให้เป็น Output
pinMode(L, OUTPUT);
}
void loop() // run over and over
{
if (Serial.available()) // ตรวจสอบว่ามีข้อมูลเข้ามาหรือไม่
test = Serial.read();
else if (test == '1') // ถ้าข้อมูลที่เข้ามาคือ 1, 2, 3 ให้ทำงานตามที่กำหนด
{
digitalWrite(R, HIGH);
digitalWrite(L, LOW);
else if (test == '2')
{
digitalWrite(L, HIGH);
digitalWrite(R, LOW);
}
else if (test == '3')
{
digitalWrite(L, LOW);
digitalWrite(R, LOW);
}
}
