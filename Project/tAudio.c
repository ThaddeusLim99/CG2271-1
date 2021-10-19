#include "MKL25Z4.h"                    // Device header
#include "cmsis_os2.h"                  // ::CMSIS:RTOS2
#include "tAudio.h"

int len[5] = {duration, duration/2, duration/4, duration/6, duration/8};
int freq[SIZE] = {0, 
																					 196, 208, 	    233,
									262, 294, 311, 330, 349, 392, 415, 440, 466, 494,
									523, 587, 622, 659, 698, 784, 831, 880, 932, 988,
									1047}; 

static void delay(volatile uint32_t nof) {
  while(nof!=0) {
    __asm("NOP");
    nof--;
  }
}

void play_note(notes note, lengths length)
{
	TPM0->MOD = ClockFreq / freq[note];
	TPM0_C0V = TPM0->MOD * 0.3;
	delay(0x80000);
	//osDelay(len[length]);
}

void off_audio()
{
	TPM0_C0V = 0;
}

void connected_tune(void)
{
	play_note(D4, semiquaver);
	for (int i = 0; i < 2; i++) {
		play_note(D4, semiquaver);
		play_note(A4, semiquaver);
	}
	off_audio();
}

void background_tune(void)
{
	//intro
	//bar 1
	play_note(E5, 2*triplet);
	play_note(D4, triplet/2);
	play_note(Rest, triplet/2);
	
	play_note(D4, 2*triplet);
	play_note(E5, triplet/2);
	play_note(Rest, triplet/2);
	
	play_note(E5, 2*triplet);
	play_note(D4, triplet/2);
	play_note(Rest, triplet/2);
	
	play_note(D4, 2*triplet);
	play_note(G5, triplet/2);
	play_note(Rest, triplet/2);
	
	//bar 2
	play_note(G5, 2*triplet);
	play_note(G4, triplet/2);
	play_note(Rest, triplet/2);
	
	play_note(G4, 2*triplet);
	play_note(G5, triplet/2);
	play_note(Rest, triplet/2);
	
	play_note(G5, crotchet);
	
	play_note(G4, crotchet);
	
	//melody loop
	while(1) {
		//bar 3
		play_note(E5, triplet);
		play_note(Rest, triplet);
		play_note(G5, triplet);
		
		play_note(A5, triplet);
		play_note(Rest, triplet);
		play_note(G5, triplet);
		
		play_note(G5, crotchet);
		
		play_note(Rest, 2*triplet);
		play_note(A5, triplet);
		
		//bar 4
		play_note(B5, triplet);
		play_note(Rest, triplet);
		play_note(C6, triplet);
		
		play_note(B5, triplet);
		play_note(Bb5, triplet);
		play_note(A5, triplet);
		
		play_note(A5, crotchet);
		
		play_note(Rest, 2*triplet);
		play_note(Eb5, triplet);
		
		//bar 5
		play_note(E5, 2*triplet);
		play_note(G5, triplet);
		
		play_note(A5, triplet);
		play_note(Rest, triplet);
		play_note(G5, triplet);
		
		play_note(G5, crotchet);
		
		play_note(Rest, 2*triplet);
		play_note(Ab5, triplet);
		
		//bar 6
		play_note(A5, triplet);
		play_note(Rest, triplet);
		play_note(Bb5, triplet);
		
		play_note(A5, triplet);
		play_note(Ab5, triplet);
		play_note(G5, triplet);
		
		play_note(G5, crotchet);
		
		play_note(Rest, 2*triplet);
		play_note(Ab5, triplet);
		
		//bar 7
		play_note(A5, triplet);
		play_note(Rest, triplet);
		play_note(B5, triplet);
		
		play_note(C6, triplet);
		play_note(Rest, triplet);
		play_note(A5, triplet);
		
		play_note(A5, crotchet);
		
		play_note(Rest, 2*triplet);
		play_note(Ab5, triplet);
		
		//bar 8
		play_note(G5, triplet);
		play_note(Rest, triplet);
		play_note(Ab5, triplet);
		
		play_note(A5, triplet);
		play_note(Rest, triplet);
		play_note(E5, triplet);
		
		play_note(E5, crotchet);
		
		play_note(Rest, crotchet);
		
		//bar 9
		play_note(E5, triplet);
		play_note(Rest, triplet);
		play_note(C5, triplet);
		
		play_note(A4, triplet);
		play_note(Rest, triplet);
		play_note(E5, triplet);
		
		play_note(C5, triplet);
		play_note(Rest, triplet);
		play_note(A4, triplet);
		
		play_note(C5, triplet);
		play_note(Rest, triplet);
		play_note(G5, triplet);
		
		//bar 10
		play_note(G5, minim);
		
		play_note(G5, crotchet);
		
		play_note(Rest, crotchet);
	}
}

void ending_tune(void)
{
	//bar 1
	play_note(G3, triplet);
	play_note(C4, triplet);
	play_note(E4, triplet);
	
	play_note(G4, triplet);
	play_note(C5, triplet);
	play_note(E5, triplet);
	
	play_note(G5, crotchet);
	
	play_note(E4, crotchet);
	
	//bar 2
	play_note(Ab3, triplet);
	play_note(C4, triplet);
	play_note(Eb4, triplet);
	
	play_note(Ab4, triplet);
	play_note(C5, triplet);
	play_note(Eb5, triplet);
	
	play_note(Ab5, crotchet);
	
	play_note(Eb5, crotchet);
	
	//bar 3
	play_note(Bb3, triplet);
	play_note(D4, triplet);
	play_note(F4, triplet);
	
	play_note(Bb4, triplet);
	play_note(D5, triplet);
	play_note(F5, triplet);
	
	play_note(Bb5, crotchet);
	
	play_note(Bb5, triplet);
	play_note(Bb5, triplet);
	play_note(Bb5, triplet);
}

void initPWM(void)
{
	// Enable clock for PortD
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
	
	// TPM - Timer/PWM Module
	// Clear MUX Mask, then setting it to TPM0_CH0
	// Port D Pin 0
	PORTD->PCR[PTD0_Pin] &= ~PORT_PCR_MUX_MASK;
	PORTD->PCR[PTD0_Pin] |= PORT_PCR_MUX(4);
	
	// Clear MUX Mask, then setting it to TPM0_CH1
	// Port D Pin 1
	PORTD->PCR[PTD1_Pin] &= ~PORT_PCR_MUX_MASK;
	PORTD->PCR[PTD1_Pin] |= PORT_PCR_MUX(4);
	
	// Enable clock for TPM0
	SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK;
	
	// Clear TPMSRC, then setting it to MCGFLLCLK or MCGFLLCLK/2
	//Multipurpose Clock Generator Fixed Frequency Loop Clock
	SIM->SOPT2 &= ~SIM_SOPT2_TPMSRC_MASK;
	SIM->SOPT2 |= SIM_SOPT2_TPMSRC(1);
	
	//48MHz / 128 = 375kHz
	//375kHz / 50Hz = 7500
	TPM0->MOD = 7500;
	
	// 80% Duty Cycle
	// MOD Count * 0.8 = 6000
	TPM0_C0V = 0;
		
	// Clear CMOD and PS, then setting CMOD to increment counting
	// and PS to divide by 128
	TPM0->SC &= ~((TPM_SC_CMOD_MASK) | (TPM_SC_PS_MASK));
	TPM0->SC |= (TPM_SC_CMOD(1) | TPM_SC_PS(7));
	
	// Clear Centre Aligned PWM which sets LPTPM to up counting mode
	// LPTPM - Low Power TPM
	TPM0->SC &= ~(TPM_SC_CPWMS_MASK);
	
	// Clearing TPM1_C0SC, then setting MSB:MSA and ELSB:ELSA to 10
	// which is Edge-Aligned PWM with High true pulses (clear output on match, set output on reload)
	TPM0_C0SC &= ~((TPM_CnSC_ELSB_MASK) | (TPM_CnSC_ELSA_MASK) | (TPM_CnSC_MSB_MASK) | (TPM_CnSC_MSA_MASK));
	TPM0_C0SC |= (TPM_CnSC_ELSB(1) | TPM_CnSC_MSB(1));
}
