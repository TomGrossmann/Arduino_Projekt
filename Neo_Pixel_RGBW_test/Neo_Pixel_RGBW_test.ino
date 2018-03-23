// ## Neo_Pxel_RGBW-test ###########################################################################
#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
#include <avr/power.h>
#endif

// ## Konstanten ###################################################################################
#define PIN 9 // Pin an den die WS2812 LEDs bzw. NeoPixel angeschlossen sind
#define NUMPIXELS 7 // Anzahl der angeschlossenen WS2812 LEDs bzw. NeoPixel

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

// ## globale Variablen ############################################################################
int pause = 200; // ms Pause
int i = 0; // Laufvariable

// -- Variablen für Farbwerte ----------------------------------------------------------------------
int r = 0; // rot
int g = 0; // grün
int b = 0; // blau
int w = 0; // weiß

// -- Variablen für Switch Case Anweisung ----------------------------------------------------------
int swich_var = 5; // Variable für Haupt-Switch-Case-Anweisung
int auf_ab = 1; // 1 ist auf , 0 ist ab
int farben = 0; // {0, 1, 2, 3}
int bewegung = 0; //

// ## Main Setup ###################################################################################
void setup() { // put your setup code here, to run once:
  pixels.begin(); // Initialisierung der NeoPixel
  pixels.show(); // Initialisierung aller Pixel auf 'off'
}
// ## ENDE Main Setup ##############################################################################

// ## Main Loop ####################################################################################
void loop() { // put your main code here, to run repeatedly:

  // ## Switch Case ################################################################################
  switch(swich_var) {
    // -- case 0 -----------------------------------------------------------------------------------
    case 0: // Verschiedene Farben einschalten
      pixels.setPixelColor(0, 0, 0, 0, 50); // Pixel1 0 leuchtet
      pixels.setPixelColor(1, 0, 0, 50, 0); // Pixel1 1 leuchtet
      pixels.setPixelColor(2, 0, 50, 0, 0); // Pixel1 2 leuchtet
      pixels.setPixelColor(3, 50, 0, 0, 0); // Pixel1 3 leuchtet
      pixels.setPixelColor(4, 0, 0, 50, 0); // Pixel1 4 leuchtet
      pixels.setPixelColor(5, 0, 50, 0, 0); // Pixel1 5 leuchtet
      pixels.setPixelColor(6, 50, 0, 0, 0); // Pixel1 6 leuchtet
      
      pixels.show(); // Durchführen der Pixel-Ansteuerung
      delay(pause); // warten
    break;
    // -- case 1 -----------------------------------------------------------------------------------
    case 1: // // Farben nacheinander durchschalten
      switch(farben) {
        case 0:
          r = 255;
          g = 0;
          b = 0;
          w = 0;
          farben = 1;
        break;
        case 1:
          r = 0;
          g = 255;
          b = 0;
          w = 0;
          farben = 2;
        break;
        case 2:
          r = 0;
          g = 0;
          b = 255;
          w = 0;
          farben = 3;
        break;
        case 3:
          r = 0;
          g = 0;
          b = 0;
          w = 255;
          farben = 0;
        break;
      }
      for ( int n = 0; n < 7; n++) {
        pixels.setPixelColor(n, r, g, b, w); // Pixel1 n leuchtet
      }
      
      pixels.show(); // Durchführen der Pixel-Ansteuerung
      delay(pause); // warten
    break;
    // -- case 2 -----------------------------------------------------------------------------------
    case 2: // Pixel nacheinander einschalten
      switch(farben) {
        case 0:
          r = 255;
          g = 0;
          b = 0;
          w = 0;
        break;
        case 1:
          r = 0;
          g = 255;
          b = 0;
          w = 0;
        break;
        case 2:
          r = 0;
          g = 0;
          b = 255;
          w = 0;
        break;
        case 3:
          r = 0;
          g = 0;
          b = 0;
          w = 255;
        break;
      }
      if (i == NUMPIXELS) {
        if (farben == 3) farben = 0;
        else farben++;
        i = 0;
        for ( int n = 0; n < 7; n++) {
          pixels.setPixelColor(n, 0, 0, 0, 0); // alle Pixel auf 'off'
        }
      } else {
        for ( int n = 0; n < i + 1; n++) {
          pixels.setPixelColor(n, r, g, b, w); // Pixel1 n leuchtet
        }
        i++;
      }
      
      pixels.show(); // Durchführen der Pixel-Ansteuerung
      delay(pause); // warten
    break;
    // -- case 3 -----------------------------------------------------------------------------------
    case 3:
      pixels.setPixelColor(i, 0, 255, 0, 0); // Pixel leuchtet in der Farbe Grün 
      if (i==0) {
        pixels.setPixelColor(NUMPIXELS - 1, 0, 0, 0, 0); // Im Fall von Pixel "0" muss die vorherige (NUMPIXELS - 1) ausgeschaltet werden.
      } else {
        pixels.setPixelColor(i - 1, 0, 0, 0, 0); // Der vorherige Pixel wird abgeschaltet
      }
      i++; // Die Variable "i" wird um eine Zahl vergrößert. Die neue Zahl "i" ist dann die nächste LED im Led-Ring
      if (i==NUMPIXELS) i=0; // Wenn die Variable den Wert NUMPIXELS erreicht hat, wird die Variable auf den Wert "0" zurück gesetzt.
      
      pixels.show(); // Durchführen der Pixel-Ansteuerung
      delay(pause); // warten
    break;
    // -- case 4 -----------------------------------------------------------------------------------
    case 4:
      switch(auf_ab) {
        case 0:
          w++;
          r = w / 5;
          b = 0;
          if (w == 50) auf_ab = 1;
        break;
        case 1:
          w--;
          r = 0;
          b = w / 5;
          if (w == 1) auf_ab = 0;
        break;
      }
      for ( int n = 0; n < 7; n++) {
        pixels.setPixelColor(n, r, g, b, w); // Pixel1 n leuchtet
      }
      
      pixels.show(); // Durchführen der Pixel-Ansteuerung
      delay(pause); // warten
    break;
    // -- case 5 -----------------------------------------------------------------------------------
    case 5:
      pixels.setPixelColor(0, 0, 0, 0, 50); // Pixel1 n leuchtet
      
      switch(bewegung) {
        case 0:
          pixels.setPixelColor(1, 0, 0, 50, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(2, 0, 50, 0, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(3, 50, 0, 0, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(4, 0, 0, 50, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(5, 0, 50, 0, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(6, 50, 0, 0, 0); // Pixel1 n leuchtet
          bewegung = 1;
        break;
        case 1:
          pixels.setPixelColor(1, 0, 50, 0, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(2, 50, 0, 0, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(3, 0, 0, 50, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(4, 0, 50, 0, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(5, 50, 0, 0, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(6, 0, 0, 50, 0); // Pixel1 n leuchtet
          bewegung = 2;
        break;
        case 2:
          pixels.setPixelColor(1, 50, 0, 0, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(2, 0, 0, 50, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(3, 0, 50, 0, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(4, 50, 0, 0, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(5, 0, 0, 50, 0); // Pixel1 n leuchtet
          pixels.setPixelColor(6, 0, 50, 0, 0); // Pixel1 n leuchtet
          bewegung = 0;
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
