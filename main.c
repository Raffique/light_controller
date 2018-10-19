/*
 * GccApplication8.c
 *
 * Created: 12/1/2017 4:25:21 PM
 * Author : Raffique
 */ 

/*
 * GccApplication4.c
 *
 * Created: 11/10/2017 7:29:55 AM
 * Author : Raffique
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>
//#include <asf.h>


int seconds = 0, As0 = 10, As1 = 10, As2 = 10, As3 = 10, As4 = 10, As5 = 10, As6 = 10;
int limit = 20;
int shut_off = 9, check_others = 9;
const int d_time = 700;






int main()
{
	
	DDRB = 0xFF;
	DDRD = 0x00;
	
	// Buttons
	PORTD |= (1<<6);
	PORTD |= (1<<5);
	PORTD |= (1<<4);
	PORTD |= (1<<3);
	PORTD |= (1<<2);
	PORTD |= (1<<1);
	PORTD |= (1<<0); 
	
	
	
 /*	EICRA &= ~(1 << ISC00);    // set INT0 to trigger on ANY logic change
	EIMSK |= (1 << INT0);     // Turns on INT0  */
	
	// Set the Timer Mode to CTC
    // Set the Timer Mode to CTC
    OCR1A = 0x3CF;
   

    TCCR1B |= (1 << WGM12);
    // Mode 4, CTC on OCR1A

    TIMSK |= (1 << OCIE1A);
    //Set interrupt on compare match

    TCCR1B |= (1 << CS12) | (1 << CS10);
    // set prescaler to 1024 and start the timer

    sei();
	
	 //light relays
	 PORTB |= (1<<7);
	 PORTB |= (1<<6);
	 PORTB |= (1<<5);
	 PORTB |= (1<<4);
	 PORTB |= (1<<3);
	 PORTB |= (1<<2);
	 PORTB |= (1<<1);
	 
	 // this is for the chime
	 PORTB |= (1<<0);
		
	while (1)
	{
		//-------------------------------------------------button 1
		if( (!(PIND & (1<<0))) )
		{
			As0 = 0;
			PORTB &= ~(1<<1);
			PORTB &= ~(1<<0);
			_delay_ms(d_time);
			PORTB |= (1<<0);
			
		}
		
		/*
		//--------------------------------------------------- button 2
		if( (!(PIND & (1<<1))) )
		{
			As1 = 0;
			//PORTB &= ~(1<<2);
			PORTB &= ~(1<<0); 
			_delay_ms(d_time);
			PORTB |= (1<<0); 
		}
		
		//---------------------------------------------------- button 3
		if( (!(PIND & (1<<2))) )
		{
			As2 = 0;
			PORTB &= ~(1<<3);
			PORTB &= ~(1<<0);
			_delay_ms(d_time);
			PORTB |= (1<<0);
		}
		//----------------------------------------------------- button 4
		if( (!(PIND & (1<<3))) )
		{
			As3 = 0;
			PORTB &= ~(1<<4);
			PORTB &= ~(1<<0);
			_delay_ms(d_time);
			PORTB |= (1<<0);
		}
		//----------------------------------------------------- button 5
		if( (!(PIND & (1<<4))) )
		{
			As4 = 0;
			PORTB &= ~(1<<5);
			PORTB &= ~(1<<0);
			_delay_ms(d_time);
			PORTB |= (1<<0);
		}
		//----------------------------------------------------- button 6
		if( (!(PIND & (1<<5))) )
		{
			As5 = 0;
			PORTB &= ~(1<<6);
			PORTB &= ~(1<<0);
			_delay_ms(d_time);
			PORTB |= (1<<0);
		}
		//----------------------------------------------------- button 7
		if( (!(PIND & (1<<6))) )
		{
			As6 = 0;
			PORTB &= ~(1<<7);
			PORTB &= ~(1<<0);
			_delay_ms(d_time);
			PORTB |= (1<<0);
		}
		*/
		//----------------------------------------------------------------------------------------------------//
		//----------------------------------------------------------------------------------------------------//
		
		
		if(As0>shut_off) { PORTB |= (1<<1); }
			
		
		if(As1>shut_off) { PORTB |= (1<<2); }
		
		
		if(As2>shut_off) { PORTB |= (1<<3); }
		
		
		if(As3>shut_off) { PORTB |= (1<<4); }
		
		
		if(As4>shut_off) { PORTB |= (1<<5); }
		
		
		if(As5>shut_off) { PORTB |= (1<<6); }
		
		
		if(As6>shut_off) { PORTB |= (1<<7); }
		
	}
		
/*-------------------------------------------------------------------------------------------------------------*/
					
}



ISR (TIMER1_COMPA_vect)
{
	
	As0++; As1++; As2++; As3++; As4++; As5++; As6++;
	/*
	if(As0<shut_off) { PORTB ^= (1<<1); }
	if(As1<shut_off) { PORTB ^= (1<<2); }	
	if(As2<shut_off) { PORTB ^= (1<<3); }
	if(As3<shut_off) { PORTB ^= (1<<4); }
	if(As4<shut_off) { PORTB ^= (1<<5); }
	if(As5<shut_off) { PORTB ^= (1<<6); }
	if(As6<shut_off) { PORTB ^= (1<<7); }
	*/
	if(As0 > limit)
	{
		As0 = limit;
	}
	
	if(As1 > limit)
	{
		As1 = limit;
	}
	
	if(As2 > limit)
	{
		As2 = limit;
	}
	
	if(As3 > limit)
	{
		As3 = limit;
	}
	
	if(As4 > limit)
	{
		As4 = limit;
	}
	
	if(As5 > limit)
	{
		As5 = limit;
	}
	
	if(As6 > limit)
	{
		As6 = limit;
	}		
}

// && (As1>check_others) && (As2>check_others) && (As3>check_others) && (As4>check_others) && (As5>check_others) && (As6>check_others)



