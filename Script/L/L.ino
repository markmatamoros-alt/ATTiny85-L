#include <CapacitiveSensor.h>

CapacitiveSensor   cs_4_2 = CapacitiveSensor(3,4);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired

int led_pin = 0;

bool is_touching() {
  long total1 =  cs_4_2.capacitiveSensor(30);
  
  if (total1 > 600) {
    return true;
  } else {
    return false;
  }
}

void setup() {
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF); 
  pinMode(led_pin, OUTPUT);
}

void loop() {  
  if (is_touching())
  {
    ledAnimation();
  }
  else
  {
    analogWrite(led_pin, 10);
    delay(160);
    analogWrite(led_pin, LOW);
    delay(160);
  }
}

void ledAnimation() {
  for(int i = 20; i > 0; i--)
  {
    analogWrite(led_pin, 150);
    delay(i * 5);
    analogWrite(led_pin, LOW);
    delay(i * 5);
    if (!is_touching()) {
      return;
    }
  }

  for(int i = 0; i < 20; i++)
  {
    analogWrite(led_pin, 150);
    delay(i * 5);
    analogWrite(led_pin, LOW);
    delay(i * 5);
    if (!is_touching()) {
      return;
    }
  }
}
