#include <avr/sleep.h>

#define AH9246_PIN 0
#define LED_PIN 1

volatile bool state = false;

ISR(PCINT0_vect)
{
	state = !digitalRead(AH9246_PIN);
}

void setup()
{
	ADCSRA &= ~_BV(ADEN);
	GIMSK |= (1 << PCIE);
	PCMSK |= (1 << AH9246_PIN);
	pinMode(LED_PIN, OUTPUT);
	pinMode(AH9246_PIN, INPUT);
}

void loop()
{
	digitalWrite(LED_PIN, state? HIGH:LOW);
}
