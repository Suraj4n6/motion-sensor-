// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;
char junk;
String inputString="";
// defines variables
long duration;
int distance;
int safetyDistance;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
Serial.begin(9600); // set the baud rate to 9600, same should be of your Serial Monitor
pinMode(13, OUTPUT);
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
safetyDistance = distance;
if (safetyDistance <= 15){
 digitalWrite(buzzer, HIGH);
 digitalWrite(ledPin, HIGH);
}
else{
 digitalWrite(buzzer, LOW);
 digitalWrite(ledPin, LOW);
}
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
if(Serial.available()){
 while(Serial.available())
 {
 char inChar = (char)Serial.read(); //read the input
 inputString += inChar; //make a string of the characters coming on serial
 }
 Serial.println(inputString);
 while (Serial.available() > 0)
 { junk = Serial.read() ; } // clear the serial buffer
 if(inputString == "a"){ //in case of 'a' turn the LED on
 digitalWrite(13, HIGH);
 }else if(inputString == "b"){ //incase of 'b' turn the LED off
 digitalWrite(13, LOW);
 }
 inputString = "";
 }
}
