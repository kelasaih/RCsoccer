// --- KOD MOTOR KAWALAN KEYBOARD ---

#define bttnA        26
#define bttnB        32




const int motorkananA1 = 18;    
const int motorkananA2 = 19;    
const int motorkiriB1 = 17;    
const int motorkiriB2 = 12;    
const int buzzer = 25;


void setup() {
  // --- Tetapan Pin Motor ---
  pinMode(motorkananA1, OUTPUT);
  pinMode(motorkananA2, OUTPUT);
  pinMode(motorkiriB1, OUTPUT);
  pinMode(motorkiriB2, OUTPUT);
 
  // --- Tetapan Pin Buzzer ---
  pinMode(buzzer, OUTPUT);


  // --- Tetapan Pin Butang
  pinMode(bttnA, INPUT_PULLUP);
  pinMode(bttnB, INPUT_PULLUP);


  // --- Mulakan Komunikasi Serial ---
  Serial.begin(115200);
  delay(100);
  Serial.println("Sistem Robot Mula");
}


void loop() {
  // Kod hanya akan bertindak jika ada data yang dihantar melalui Serial Monitor.
  if (Serial.available() > 0) {
    char dat = Serial.read();
    Serial.print("Arahan diterima: ");
    Serial.println(dat);


   
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
    else if (dat == 'L') { // KIRI
      digitalWrite(motorkananA1, HIGH);
      digitalWrite(motorkananA2, LOW);
      digitalWrite(motorkiriB1, LOW);
      digitalWrite(motorkiriB2, LOW);
      Serial.println("Motor Pusing ke KIRI");
    }
    else if (dat == 'R') { // KANAN
      digitalWrite(motorkananA1, LOW);
      digitalWrite(motorkananA2, LOW);
      digitalWrite(motorkiriB1, LOW);
      digitalWrite(motorkiriB2, HIGH);
      Serial.println("Motor Pusing ke KANAN");
    }
  }


}
