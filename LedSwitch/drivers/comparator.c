#include "platform.h"
#include "comparator.h"
#include <stdlib.h>

//Note: the interrupt can be only triggered once!
void comparator_init(void) {
	adc_init(P_CMP_NEG);	
	adc_init(P_CMP_PLUS);	
}


int comparator_read(void) {	
	uint16_t comp_pos;
	uint16_t comp_neg = ( adc_read(P_CMP_NEG) & (uint16_t)0x0FFF ) ;
	int i;
	
	//Create some delay
	for (i=0; i < 1000;i++);
	
	comp_pos = ( adc_read(P_CMP_PLUS) & (uint16_t)0x0FFF) ;
	if (comp_pos > comp_neg) {
		return 1;
	}
	else {
		return 0;
	}
}


