// --- KOD MOTOR KAWALAN BLUETOOTH ---

#include "BluetoothSerial.h"


// Definisi pin butang
#define bttnA        26
#define bttnB        32


// Definisi pin dan nama pemboleh ubah motor
const int motorkananA1 = 18;    
const int motorkananA2 = 19;    
const int motorkiriB1 = 17;    
const int motorkiriB2 = 12;    
const int buzzer = 25;


// Objek Bluetooth Serial dan nama Bluetooth
BluetoothSerial my_bluetooth;
const char* nama_bluetooth = "FoosBall KKSJaih";




void setup() {
  // --- Tetapan Pin Motor ---
  pinMode(motorkananA1, OUTPUT);
  pinMode(motorkananA2, OUTPUT);
  pinMode(motorkiriB1, OUTPUT);
  pinMode(motorkiriB2, OUTPUT);
 
  // --- Tetapan Pin Buzzer ---
  pinMode(buzzer, OUTPUT);


  // --- Tetapan Pin Butang (Amalan Terbaik) ---
  pinMode(bttnA, INPUT_PULLUP);
  pinMode(bttnB, INPUT_PULLUP);


  // --- Mulakan Komunikasi Serial (untuk debugging) & Bluetooth ---
  Serial.begin(115200);
  delay(100);
  my_bluetooth.begin(nama_bluetooth); // Memulakan Bluetooth
  Serial.println("Robot sedia menerima arahan melalui Bluetooth...");
}


void loop() {
  // Kod hanya akan bertindak jika ada data yang dihantar melalui Bluetooth
  if (my_bluetooth.available() > 0) {
    char dat = my_bluetooth.read(); // Membaca data dari Bluetooth
    Serial.print("Arahan Bluetooth diterima: ");
    Serial.println(dat);


    // Logik pergerakan motor dari kod terkini anda dimasukkan di sini
    if (dat == 'B') { // UNDUR
      digitalWrite(motorkananA1, LOW);
      digitalWrite(motorkananA2, HIGH);
      digitalWrite(motorkiriB1, HIGH);
      digitalWrite(motorkiriB2, LOW);
      Serial.println("Motor Gerak ke BELAKANG");
    }
    else if (dat == 'F') { // DEPAN
      digitalWrite(motorkananA1, HIGH);
      digitalWrite(motorkananA2, LOW);
      digitalWrite(motorkiriB1, LOW);
      digitalWrite(motorkiriB2, HIGH);
      Serial.println("Motor Gerak ke DEPAN");
    }
    else if (dat == 'S') { // BERHENTI
      digitalWrite(motorkananA1, LOW);
      digitalWrite(motorkananA2, LOW);
      digitalWrite(motorkiriB1, LOW);
      digitalWrite(motorkiriB2, LOW);
      Serial.println("Motor BERHENTI");
    }
    else if (dat == 'L') { // KIRI (Sweep Turn)
      digitalWrite(motorkananA1, HIGH);
      digitalWrite(motorkananA2, LOW);
      digitalWrite(motorkiriB1, LOW);
      digitalWrite(motorkiriB2, LOW);
      Serial.println("Motor Pusing ke KIRI");
    }
    else if (dat == 'R') { // KANAN (Sweep Turn)
      digitalWrite(motorkananA1, LOW);
      digitalWrite(motorkananA2, LOW);
      digitalWrite(motorkiriB1, LOW);
      digitalWrite(motorkiriB2, HIGH);
      Serial.println("Motor Pusing ke KANAN");
    }
  }
}
