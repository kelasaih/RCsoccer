// --- KOD PENGUJIAN BUTANG ---

#define bttnA        26  // Butang untuk mengawal Roda Kanan
#define bttnB        32  // Butang untuk mengawal Roda Kiri

void setup() {
  // Mulakan Serial Monitor untuk melihat output
  Serial.begin(115200);
  Serial.println("--- Ujian Diagnostik Butang Dimulakan ---");
 
  // Tetapkan pin butang kepada mod INPUT_PULLUP
  pinMode(bttnA, INPUT_PULLUP);
  pinMode(bttnB, INPUT_PULLUP);
 
  Serial.println("Sila perhatikan bacaan di bawah. Sepatutnya '0' jika tidak ditekan.");
}

void loop() {
  // Baca status semasa kedua-dua butang
  int statusButangA = digitalRead(bttnA);
  int statusButangB = digitalRead(bttnB);

  // Cetak status ke Serial Monitor
  Serial.print("Status Butang A (Pin 26): ");
  Serial.print(statusButangA);
  Serial.print("  |  ");
  Serial.print("Status Butang B (Pin 32): ");
  Serial.println(statusButangB);
 
  delay(500); // Lengah masa supaya mudah dibaca
}

