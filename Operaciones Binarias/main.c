#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

uint8_t leerNibble1(void);
uint8_t leerNibble2(void);
void mostrar(uint8_t valor);

int main(void)
{
    uint8_t nibble1;
    uint8_t nibble2;
    uint8_t resultadoAND;
    uint8_t resultadoOR;
    uint8_t resultadoXOR;
   
     // CONFIGURACIÓN DEL NIBBLE 1

    DDRC &= ~((1 << PC3) |
              (1 << PC2) |
              (1 << PC1) |
              (1 << PC0));

    // Pull-up internos
    PORTC |= (1 << PC3) |
             (1 << PC2) |
             (1 << PC1) |
             (1 << PC0);

    // CONFIGURACION DEL NIBBLE 2

    DDRB &= ~(1 << PB0);
    PORTB |= (1 << PB0);

    DDRD &= ~((1 << PD7) |
              (1 << PD6) |
              (1 << PD5));

    // Pull-up internos
    PORTD |= (1 << PD7) |
             (1 << PD6) |
             (1 << PD5);

    // CONFIGURACION DE LOS LEDs

    DDRD |= (1 << PD2) |
            (1 << PD1) |
            (1 << PD0) |
            (1 << PD3);


    while (1)
    {
        // Leer los dos nibbles
        nibble1 = leerNibble1();
        nibble2 = leerNibble2();

        // Operaciones
        resultadoAND = nibble1 & nibble2;
        resultadoOR  = nibble1 | nibble2;
        resultadoXOR = nibble1 ^ nibble2;

        mostrar(resultadoAND);
        _delay_ms(500);


        mostrar(resultadoOR);
        _delay_ms(500);



        mostrar(resultadoXOR);
        _delay_ms(500);
    }
}

uint8_t leerNibble1(void)
{
    uint8_t valor = 0;

    if (!(PINC & (1 << PC3)))
        valor |= 0x08;

    if (!(PINC & (1 << PC2)))
        valor |= 0x04;

    if (!(PINC & (1 << PC1)))
        valor |= 0x02;

    if (!(PINC & (1 << PC0)))
        valor |= 0x01;

    return valor;
}



uint8_t leerNibble2(void)
{
    uint8_t valor = 0;

    if (!(PINB & (1 << PB0)))
        valor |= 0x08;

    if (!(PIND & (1 << PD7)))
        valor |= 0x04;

    if (!(PIND & (1 << PD6)))
        valor |= 0x02;

    if (!(PIND & (1 << PD5)))
        valor |= 0x01;

    return valor;
}
void mostrar(uint8_t valor)
{
    // PD2 = bit 3
    if (valor & 0x08)
        PORTD |= (1 << PD2);
    else
        PORTD &= ~(1 << PD2);

    // PD1 = bit 2
    if (valor & 0x04)
        PORTD |= (1 << PD1);
    else
        PORTD &= ~(1 << PD1);

    // PD0 = bit 1
    if (valor & 0x02)
        PORTD |= (1 << PD0);
    else
        PORTD &= ~(1 << PD0);

    // PD3 = bit 0
    if (valor & 0x01)
        PORTD |= (1 << PD3);
    else
        PORTD &= ~(1 << PD3);
}
