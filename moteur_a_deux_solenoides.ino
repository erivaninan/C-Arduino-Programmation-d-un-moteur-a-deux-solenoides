int E1 = 6;
int M1 = 7;
int E2 = 5;
int M2 = 4;
int pinPot = 0; //variable pour définir le CAN où est connecté le potentiomètre
int valPot = 0; //variable pour récupérer la tension aux bornes du potentiomètre traduite par le CAN . On l’initialise à 0.


void setup()
{
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
  Serial.begin(9600); //Initialisation de la communication avec la console
}


void loop()

{
  analogRead(0);
  valPot = analogRead(A0); //lit la tension, la convertit en valeur numérique et la stocke dans valeurPot
  Serial.print("Valeur lue : ");
  Serial.println(valPot);

  {
    digitalWrite(M1, LOW);
    digitalWrite(E1, LOW);
    digitalWrite(M2, HIGH);
    digitalWrite(E2, HIGH);
    delay(valPot);
    digitalWrite(M1, HIGH);
    digitalWrite(E1, HIGH);
    digitalWrite(M2, LOW);
    digitalWrite(E2, LOW);
    delay(valPot);
  }

}


