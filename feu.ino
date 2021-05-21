/*
 Code pour feu tricolore, 
  3 leds (rouge, jaune et verte) + 2 leds pour les piétons
  si appui sur le bouton, donne le vert aux piétons
*/
 
// On définit les variables sorties:
int led_rouge = 8;
int led_jaune = 7;
int led_verte = 9;
int pieton_rouge = 4;
int pieton_verte = 5;
// On définit les variables entrées:
int bouton_pieton = 13;
// On définit les temps de pause:
int temps_vertRouge = 15000; // le feu voiture dure 15sec
int temps_vertPieton = 5000; // le feu pieton dure 5sec
int demande_pieton = 0; // variable utilisee par le bouton


void setup() {
  // On définit les sorties:
  pinMode(led_rouge, OUTPUT);
  pinMode(led_jaune, OUTPUT);
  pinMode(led_verte, OUTPUT);
  pinMode(pieton_rouge, OUTPUT);
  pinMode(pieton_verte, OUTPUT);
  // On définit les entrées:
  pinMode(bouton_pieton, INPUT);
  // On allume le feu voitures au vert et piétons sur rouge
  digitalWrite(led_rouge,LOW); // on éteint le rouge des voitures
  digitalWrite(led_jaune,LOW); // on éteint le jaune des voitures
  digitalWrite(led_verte,HIGH); // on allume le vert des voitures
  digitalWrite(pieton_rouge,HIGH); // on allume le rouge des piétons
  digitalWrite(pieton_verte,LOW); // on éteint le vert des piétons
}

// la boucle infinie:
void loop() {
  demande_pieton = digitalRead(bouton_pieton);
  if(demande_pieton == HIGH){
    delay(2000); // petite pause de 2sec avant de mettre les voitures au rouge
    voiture_rouge(); // appel fonction bouton relaché
  }
  delay(10);
} // fin boucle infinie



int voiture_rouge() { // On stoppe les voitures et fait traverser les piétons
  digitalWrite(led_verte,LOW); // on éteint le vert et
  digitalWrite(led_jaune,HIGH); // on allume le jaune
  delay(2500);
  digitalWrite(led_jaune,LOW); // on éteint le jaune
  digitalWrite(led_rouge,HIGH); // on allume le rouge
  delay(1000);
  digitalWrite(pieton_rouge,LOW); // on éteint le rouge des piétons
  digitalWrite(pieton_verte,HIGH); // on allume le vert des piétons
  delay(4500); // on attend 5sec que les piétons traversent
  
  for(int i = 0; i < 5; i++) { // on fait clignoter 4x le vert piéton
    digitalWrite(pieton_verte,HIGH); // on allume le vert des piétons
    delay(500);
    digitalWrite(pieton_verte,LOW); // on éteint le vert des piétons
    delay(500);
  }
  digitalWrite(pieton_rouge,HIGH); // on allume le rouge des piétons
  delay(1000);
  digitalWrite(led_jaune,HIGH); // on allume le jaune
  delay(500);
  digitalWrite(led_jaune,LOW); // on éteint le jaune
  digitalWrite(led_rouge,LOW); // on éteint le rouge
  digitalWrite(led_verte,HIGH); // on allume le vert
} // fin fonction voiture_rouge()


