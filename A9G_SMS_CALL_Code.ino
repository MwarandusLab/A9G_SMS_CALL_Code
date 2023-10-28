#include <SoftwareSerial.h>

static const int RXPin = 3, TXPin = 4;
String phoneNumber = "+254748613509"; // Replace this with the recipient's phone number
String message = "Hello, this is a test SMS from A9G!";

SoftwareSerial ss(RXPin, TXPin);

void setup() {
  Serial.begin(9600);
  ss.begin(9600);

  delay(1000);
  Serial.println("Starting...");

  makeCall();
  delay(1000);
  // Enable SMS text mode
  ss.println("AT+CMGF=1");
  delay(100);

  // Set SMS recipient phone number
  ss.print("AT+CMGS=\"");
  ss.print(phoneNumber);
  ss.println("\"");
  delay(100);

  // Send the SMS message
  ss.print(message);
  ss.write(26); // ASCII code for CTRL+Z (message termination)
  delay(1000);
}

void loop() {
  // Empty loop, as we only want to send the SMS once during setup
}
void makeCall() {
  Serial.println("Making a call...");
  ss.println("ATD+254748613509;"); // Replace +1234567890 with the phone number you want to call
  delay(10000); // You can adjust the delay according to your requirements (5 seconds here)
  ss.println("ATH"); // Hang up the call
  Serial.println("Call ended.");
}