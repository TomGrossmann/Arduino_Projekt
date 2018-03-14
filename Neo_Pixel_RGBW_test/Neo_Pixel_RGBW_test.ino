// ## Neo_Pxel_RGBW-test ###########################################################################
#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
#include <avr/power.h>
#endif

// ## Konstanten ###################################################################################
#define PIN 9 // Hier wird angegeben, an welchem digitalen Pin die WS2812 LEDs bzw. NeoPixel angeschlossen sind
#define NUMPIXELS 7 // Hier wird die Anzahl der angeschlossenen WS2812 LEDs bzw. NeoPixel angegeben
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

// ## globale Variablen ############################################################################
int pause = 200; // ms Pause
int i = 0;

// -- Variablen für Farbwerte ----------------------------------------------------------------------
int r = 0; // rot
int g = 0; // grün
int b = 0; // blau
int w = 0; // weiß

// -- Variablen für Switch Case Anweisung ----------------------------------------------------------
int swich_var = 5; // Var für Switch Case Anweisung
int auf_ab = 1; // 1 ist auf , 0 ist ab
int rotation = 1;

// ## Main Setup ###################################################################################
void setup() {
  // put your setup code here, to run once:
  pixels.begin(); // Initialisierung der NeoPixel
  pixels.show(); // Initialize all pixels to 'off'
}
// ## ENDE Main Setup ##############################################################################

// ## Main Loop ####################################################################################
void loop() {
  // put your main code here, to run repeatedly:

  // ## Switch Case ################################################################################
  switch(swich_var) {
    // -- case 0 -----------------------------------------------------------------------------------
    case 0:
      pixels.setPixelColor(0, 0, 0, 0, 50); // Pixel1 n leuchtet
      pixels.setPixelColor(1, 0, 0, 50, 0); // Pixel1 n leuchtet
      pixels.setPixelColor(2, 0, 50, 0, 0); // Pixel1 n leuchtet
      pixels.setPixelColor(3, 50, 0, 0, 0); // Pixel1 n leuchtet
      pixels.setPixelColor(4, 0, 0, 50, 0); // Pixel1 n leuchtet
      pixels.setPixelColor(5, 0, 50, 0, 0); // Pixel1 n leuchtet
      pixels.setPixelColor(6, 50, 0, 0, 0); // Pixel1 n leuchtet
      
      pixels.show(); // Durchführen der Pixel-Ansteuerung
      delay(pause); // warten
    break;
    // -- case 1 -----------------------------------------------------------------------------------
    case 1:
      for ( int n = 0; n < 7; n++) {
        pixels.setPixelColor(n, 255, 0, 0, 0); // Pixel1 n leuchtet
      }
      pixels.show(); // Durchführen der Pixel-Ansteuerung
    
      delay(pause); // warten
    
      for ( int n = 0; n < 7; n++) {
        pixels.setPixelColor(n, 0, 255, 0, 0); // Pixel1 n leuchtet
      }
      pixels.show(); // Durchführen der Pixel-Ansteuerung
    
      delay(pause); // warten
    
      for ( int n = 0; n < 7; n++) {
        pixels.setPixelColor(n, 0, 0, 255, 0); // Pixel1 n leuchtet
      }
      pixels.show(); // Durchführen der Pixel-Ansteuerung
    
      delay(pause); // warten
    
      for ( int n = 0; n < 7; n++) {
        pixels.setPixelColor(n, 0, 0, 0, 255); // Pixel1 n leuchtet
      }
      pixels.show(); // Durchführen der Pixel-Ansteuerung
    
      delay(pause); // warten
    break;
    // -- case 2 -----------------------------------------------------------------------------------
    case 2:
      // Pixel einzeln einschalten
      for ( int n = 0; n < 7; n++) {
        pixels.setPixelColor(n, 255, 0, 0, 0); // Pixel1 n leuchtet
        pixels.show(); // Durchführen der Pixel-Ansteuerung
        delay(pause); // warten
      }
      // Zurücksetzen aller Pixelfarben auf Stufe "0" (aus)
      for ( int n = 0; n < 7; n++) {
        pixels.setPixelColor(n, 0, 0, 0, 0); // Pixel1 n leuchtet
      }
      pixels.show(); // Durchführen der Pixel-Ansteuerung
      delay(pause); // warten
    break;
    // -- case 3 -----------------------------------------------------------------------------------
    case 3:
      pixels.setPixelColor(i, 0, 255, 0, 0); // Pixel leuchtet in der Farbe Grün 
      if (i==0) {
        pixels.setPixelColor(NUMPIXELS - 1, pixels.Color(0,0,0)); // Im Fall von Pixel "0" muss die vorherige (NUMPIXELS - 1) ausgeschaltet werden.
      } else {
        pixels.setPixelColor(i-1, 0,0,0); // Der vorherige Pixel wird abgeschaltet
      }
      pixels.show(); // Durchführen der Pixel-Ansteuerung
      delay (pause);
      
      i++; // Die Variable "i" wird um eine Zahl vergrößert. Die neue Zahl "i" ist dann die nächste LED im Led-Ring
      if (i==NUMPIXELS) i=0; // Wenn die Variable den Wert NUMPIXELS erreicht hat, wird die Variable auf den Wert "0" zurück gesetzt.
    break;
    // -- case 4 -----------------------------------------------------------------------------------
    case 4:
      for ( int n = 0; n < 7; n++) {
        pixels.setPixelColor(n, r, g, b, w); // Pixel1 n leuchtet
      }
      pixels.show(); // Durchführen der Pixel-Ansteuerung
      delay (pause);

      switch(auf_ab) {
        case 0:
          w++;
          r = w / 5;
          b = 0;
          if (w>50) auf_ab = 1;
        break;
        case 1:
          w--;
          r = 0;
          b = w / 5;
          if (w<1) auf_ab = 0;
        break;
      }
    break;
    // -- case 5 -----------------------------------------------------------------------------------
    case 5:
      pixels.setPixelColor(0, 0, 0, 0, 50); // Pixel1 n leuchtet
      
      switch(rotation) {
        case 0:
          pixels.setPixelColor(1, 0, 0, 50, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(2, 0, 50, 0, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(3, 50, 0, 0, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(4, 0, 0, 50, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(5, 0, 50, 0, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(6, 50, 0, 0, 0); // Pixel1 n leuchtet
          rotation = 1;
        break;
        case 1:
          pixels.setPixelColor(1, 0, 50, 00, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(2, 50, 0, 0, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(3, 0, 0, 50, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(4, 0, 50, 0, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(5, 50, 0, 0, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(6, 0, 0, 50, 0); // Pixel1 n leuchtet
          rotation = 2;
        break;
        case 2:
          pixels.setPixelColor(1, 50, 0, 0, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(2, 0, 0, 50, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(3, 0, 50, 0, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(4, 50, 0, 0, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(5, 0, 0, 50, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(6, 0, 50, 0, 0); // Pixel1 n leuchtet
          rotation = 0;
        break;
      }
      pixels.show(); // Durchführen der Pixel-Ansteuerung
      delay(pause); // warten
    break;
    // -- default ----------------------------------------------------------------------------------
    default:
      for ( int n = 0; n < 7; n++) {
        pixels.setPixelColor(n, 255, 255, 255, 255); // Pixel1 n leuchtet
      }
      pixels.show(); // Durchführen der Pixel-Ansteuerung
    break;
  }
  // ## ENDE Switch Case ###########################################################################

}
// ## ENDE Main Loop ###############################################################################
