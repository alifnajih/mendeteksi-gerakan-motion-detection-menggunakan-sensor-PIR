int pirPin = 2; // Pin yang terhubung ke sensor PIR
int ledPin = 13; // Pin built-in LED pada Arduino Uno

void setup() {
  pinMode(pirPin, INPUT); // Mengatur pin sebagai input
  pinMode(ledPin, OUTPUT); // Mengatur pin sebagai output
  Serial.begin(9600); // Memulai komunikasi serial
  digitalWrite(ledPin, LOW); // Matikan LED awalnya
}

void loop() {
  int pirState = digitalRead(pirPin); // Baca nilai dari sensor PIR

  if (pirState == HIGH) {
    Serial.println("Gerakan Terdeteksi!");
    digitalWrite(ledPin, LOW); // Nyalakan LED jika gerakan terdeteksi
  } else {
    digitalWrite(ledPin, HIGH); // Matikan LED jika tidak ada gerakan
  }

  delay(1000); // Tunggu 1 detik sebelum membaca sensor lagi
}
