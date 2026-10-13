  static bool led_stare = false;

  if (!(PINB & (1 << PINB0)))
  {
    delay(30); // Debounce

    if (!(PINB & (1 << PINB0)))
    {
      led_stare = !led_stare;

      if (led_stare)
        PORTD |= (1 << PORTD0);
      else
        PORTD &= ~(1 << PORTD0);

      // Asteptam eliberarea butonului
      while (!(PINB & (1 << PINB0)))
      {
      }

      delay(30);
    }
  }
}
