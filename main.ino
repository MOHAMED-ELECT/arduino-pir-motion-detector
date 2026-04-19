// Détecteur de mouvement avec capteur PIR

int CAP_INFRAROUGE = 0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);

  pinMode(7, OUTPUT);   // LED rouge
  pinMode(6, OUTPUT);   // LED verte
  pinMode(11, OUTPUT);  // Buzzer
}

void loop()
{
  // Lecture du capteur
  CAP_INFRAROUGE = digitalRead(A0);
  Serial.println(CAP_INFRAROUGE);

  // Détection de mouvement
  if (CAP_INFRAROUGE == HIGH)
  {
    digitalWrite(7, LOW);   // LED rouge OFF
    digitalWrite(6, HIGH);  // LED verte ON
    tone(11, 1000);         // Buzzer ON 
  }
  else
  {
    digitalWrite(7, HIGH);  // LED rouge ON
    digitalWrite(6, LOW);   // LED verte OFF
    noTone(11);             // Buzzer OFF
  }

  delay(10);
}