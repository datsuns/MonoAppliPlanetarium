#include <Bounce/Bounce.h>

Bounce bouncer = Bounce( 2, 5 ); 
void isr_1()
{
  if (Serial.available() ) {
  //Serial.write("INT\r\n");
  }
  if ( bouncer.update() ) {
    if ( bouncer.read() == LOW) {
      if (Serial.available() ) {
        Serial.write("hello\r\n");
      }
    }
  }
}

void setup()
{
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  pinMode( 2, INPUT );
  digitalWrite(2, HIGH );
  attachInterrupt( 0, isr_1, CHANGE );
}

void loop()
{
}
