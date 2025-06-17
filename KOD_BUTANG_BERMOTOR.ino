// --- KOD PENGUJIAN BUTANG BERMOTOR ---

#define mtrA01       18
#define mtrA02       19
#define mtrB01       17
#define mtrB02       12
#define bttnA        26
#define bttnB        32

void setup() {
  Serial.begin(115200);
  pinMode(mtrA01, OUTPUT);
  pinMode(mtrA02, OUTPUT);
  pinMode(mtrB01, OUTPUT);
  pinMode(mtrB02, OUTPUT);
 
  // Menggunakan perintang pull-up dalaman. Litar: Pin -> Butang -> GND
  pinMode(bttnA, INPUT_PULLUP);
  pinMode(bttnB, INPUT_PULLUP);
 
  // Hentikan motor semasa mula
  digitalWrite(mtrA01, LOW);
  digitalWrite(mtrA02, LOW);
  digitalWrite(mtrB01, LOW);
  digitalWrite(mtrB02, LOW);
}

void loop() {
  // Apabila butang ditekan, pin bersambung ke GND, jadi bacaan adalah LOW
  int butangA_ditekan = (digitalRead(bttnA) == HIGH);
  int butangB_ditekan = (digitalRead(bttnB) == HIGH);

  // Kawalan Roda Kanan
  if (butangA_ditekan) {
    digitalWrite(mtrA01, HIGH);
    digitalWrite(mtrA02, LOW);
  } else {
    digitalWrite(mtrA01, LOW);
    digitalWrite(mtrA02, LOW);
  }

  // Kawalan Roda Kiri
  if (butangB_ditekan) {
    digitalWrite(mtrB01, LOW);
    digitalWrite(mtrB02, HIGH);
  } else {
    digitalWrite(mtrB01, LOW);
    digitalWrite(mtrB02, LOW);
  }
 
  delay(20);
}

