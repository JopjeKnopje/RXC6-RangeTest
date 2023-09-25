#include <Arduino.h>

#define PIN_COUNT 4
#define PIN_TONE 3

#define BASE_TONE 220


static const int RADIO_PINS[] = {6, 7, 8, 9};
static const String PIN_NAMES[] = {"D0", "D1", "D2", "D3"};

void setup()
{
    Serial.begin(115200);
    for (size_t i = 0; i < PIN_COUNT; i++)
    {
        pinMode(RADIO_PINS[i], INPUT);
    }
}


void loop()
{
    for (size_t i = 0; i < PIN_COUNT; i++)
    {
        int status = digitalRead(RADIO_PINS[i]);
        if (i + 1 < PIN_COUNT)
            Serial.print(PIN_NAMES[i] + ": " + status + " | ");
        else
            Serial.println(PIN_NAMES[i] + ": " + status);

        if (status)
            // song(PIN_TONE);
            tone(PIN_TONE, BASE_TONE * (i + 1), 1000);

    }
    delay(100);
}
