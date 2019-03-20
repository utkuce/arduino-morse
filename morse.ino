unsigned short unit_time = 100; //ms

enum led_length : byte {
  DOT = 1,
  DASH = 3,
};

String characters = "abcdefghijklmnopqrstuvwxyz0123456789 ";

String morse_characters[37] = {
        {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."},
        {"--."}, {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."},
        {"--"}, {"-."}, {"---"}, {".--."}, {"--.-"}, {".-."}, 
        {"..."}, {"-"}, {"..-"}, {"...-"}, {".--"}, {"-..-"},
        {"-.--"}, {"--.."}, {".----"}, {"..---"}, {"...--"}, 
        {"....-"}, {"....."}, {"-...."}, {"--..."}, {"---.."}, 
        {"---."}, {"-----"}, {"//"}
    };

String message = "sos";

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  //Serial.begin(9600); // uncomment to enable serial
}

// the loop function runs over and over again forever
void loop() {
  
  for(char& c : message) {
    
    String morse_char = morse_characters[characters.indexOf(c)];
    for (char& m : morse_char) {
  
      Serial.print(m);
      switch(m) {
       case '-':
        lled(DASH);
        break;
      case '.':
        lled(DOT);
        break;
      case '/':
        delay(unit_time*7 - unit_time);  
      }
        
    }

    Serial.print(' ');
    delay(unit_time*3 - unit_time);
  }

  Serial.println();
  delay(unit_time*7 - unit_time);
}

void lled (byte on_time) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(unit_time*on_time);
  digitalWrite(LED_BUILTIN, LOW); 
  delay(unit_time);
}
