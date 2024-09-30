// lab5_starter.c
// Fur Elise, E155 Lab 5
// Updated Fall 2021

// Pitch in Hz, duration in ms

#include "../lib/FLASH.h"
#include "../lib/GPIO.h"
#include "../lib/RCC.h"
#include "../lib/TIM16.h"

const int notes[][2] = {
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{416,	125},
{494,	125},
{523,	250},
{  0,	125},
{330,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{523,	125},
{494,	125},
{440,	250},
{  0,	125},
{494,	125},
{523,	125},
{587,	125},
{659,	375},
{392,	125},
{699,	125},
{659,	125},
{587,	375},
{349,	125},
{659,	125},
{587,	125},
{523,	375},
{330,	125},
{587,	125},
{523,	125},
{494,	250},
{  0,	125},
{330,	125},
{659,	125},
{  0,	250},
{659,	125},
{1319,	125},
{  0,	250},
{623,	125},
{659,	125},
{  0,	250},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{416,	125},
{494,	125},
{523,	250},
{  0,	125},
{330,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{523,	125},
{494,	125},
{440,	500},
{  0,	0}};

void delay(int ms) {
   while (ms-- > 0) {
      volatile int x=1000;
      while (x-- > 0)
         __asm("nop");
   }
}

int main(void) {

    
    // Set LED_PIN as output
    RCC->AHB2ENR |= (0b1 << 0); // enable GPIOA
    RCC->APB2ENR |= (0b1 << 17); // enable tim16
    RCC->CFGR |= (0b1 << 13); // set AHBPRESC to 2
    RCC->CFGR |= (0b1 << 7); // set APB2PRESC to 2


    TIM16->TIM_PSC |= (0b1 << 1); // set clock prescaler
    TIM16->TIM_CR1 |= (0b1 << 7); // enable auto preload reload
    TIM16->TIM_ARR &= 0;
    TIM16->TIM_ARR = 50000; // set the auto reload register


    TIM16->TIM_CCER |= (0b1 << 0); // enable capture compare 1
    TIM16->TIM_CCR1 = TIM16->TIM_ARR / 2; // 50% duty cycle
    TIM16->TIM_CCMR1 &= ~(0b11 << 0); // set CC1 as output
    TIM16->TIM_CCMR1 |= (0b1 << 6); // setting to pwm mode 1
    TIM16->TIM_CCMR1 |= (0b1 << 5); 
    
    TIM16->TIM_BDTR |= (0b1 << 15); // enable main output enable 
    
    TIM16->TIM_CCMR1 |= (0b1 << 3); // enable pre load register

   
    
    TIM16->TIM_EGR |= (0b1 << 0); // enableUpdate generation
    TIM16->TIM_CR1 |= (0b1 << 0); //enable the counter for timer 16
    

    pinMode(6, GPIO_ALT);
    GPIO->AFRL &= ~(0b1111 << 24); // Clear bits 27:24
    GPIO->AFRL |= (0b1110 << 24);
    //GPIO->OSPEEDR |= (0b11 << 12);

    
    
    
    // Blink LED
    while(1) {
    //    digitalWrite(7,GPIO_HIGH);
      //TIM16->TIM_SR &= ~(0b1 << 1);
    }
    return 0;
	
}