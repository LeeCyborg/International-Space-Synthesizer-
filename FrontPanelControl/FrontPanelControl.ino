// pin digital 4 buttom 2 triangles
// pin digital 5 middle
// pin digital 6 top left
// pin digital 7 top right

int howFastInMiliseconds = 1000; // Change this for adjusting speed
// 1000 miliseocnds is 1 second
// probably need cloaser to 5000 each
void setup() {
  for (int i = 4; i > 7; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() { // will keep going forever
dance(); // Lights all up from bottom to top
// allOn(); // Uncomment for all on
// allOff(); // uncomment for all off
} // end of loop

// functions

void dance() {
  digitalWrite(4, HIGH); // turn on bottom
  delay(howFastInMiliseconds); // wait
  digitalWrite(5, HIGH); // turn on middle
  delay(howFastInMiliseconds);
  digitalWrite(4, LOW); // turn off bottom
  delay(howFastInMiliseconds);
  digitalWrite(6, HIGH); // turn on left
  delay(howFastInMiliseconds);
  digitalWrite(7, HIGH); // turn on right
  delay(howFastInMiliseconds);
  digitalWrite(5, LOW); // turn off middle
  delay(howFastInMiliseconds);
  digitalWrite(7, LOW); // turn off both tops
  digitalWrite(6, LOW);
  delay(howFastInMiliseconds); // chill and restart
}
void allOn() { // function for on
  for (int i = 4; i > 7; i++) {
    digitalWrite(i, HIGH); // loop through all, turn on
  }
}

void allOff() { // function for off
  for (int i = 4; i > 7; i++) {
    digitalWrite(i, LOW); // loop through all, turn off 
  }
}


