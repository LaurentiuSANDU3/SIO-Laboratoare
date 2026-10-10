const int pinButon = 4;

const int pinRosu = 3;
const int pinAlbastru = 2;
const int pinVerde = 1;

int culoare = 0;
int stareVeche = LOW;

void setup()
{
  pinMode(pinRosu, OUTPUT);
  pinMode(pinAlbastru, OUTPUT);
  pinMode(pinVerde, OUTPUT);

  pinMode(pinButon, INPUT);

  digitalWrite(pinRosu, HIGH);
  digitalWrite(pinAlbastru, LOW);
  digitalWrite(pinVerde, LOW);
}

void loop()
{
  int stareButon = digitalRead(pinButon);

 
  if (stareButon == HIGH && stareVeche == LOW)
  {
    culoare++;

    if (culoare > 4)
      culoare = 0;

    switch (culoare)
    {
      case 0: // Roșu
        digitalWrite(pinRosu, HIGH);
        digitalWrite(pinVerde, LOW);
        digitalWrite(pinAlbastru, LOW);
        break;

      case 1: // Verde
        digitalWrite(pinRosu, LOW);
        digitalWrite(pinVerde, HIGH);
        digitalWrite(pinAlbastru, LOW);
        break;

      case 2: // Albastru
        digitalWrite(pinRosu, LOW);
        digitalWrite(pinVerde, LOW);
        digitalWrite(pinAlbastru, HIGH);
        break;

      case 3: // Galben 
        digitalWrite(pinRosu, HIGH);
        digitalWrite(pinVerde, HIGH);
        digitalWrite(pinAlbastru, LOW);
        break;

      case 4: // Mov 
        digitalWrite(pinRosu, HIGH);
        digitalWrite(pinVerde, LOW);
        digitalWrite(pinAlbastru, HIGH);
        break;
    }

    delay(50);
  }

  stareVeche = stareButon;
}