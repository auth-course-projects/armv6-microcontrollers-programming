#include <stdio.h>
#include "LedSwitch.h"
#include "Utils.h"

/**
 * Experiment Types:
 * 		- 0: Average Response Time from LED turns ON
 * 		- 1: Average Response Time from LED turns OFF
 */
#define EXP_TYPE 0

/**
 * Total Number of experiments
 */
#define EXP_TOTAL 5

uint32_t experiment(void);

int main()
{
	uint8_t exp_i;
	uint32_t resTime, resTimesSum;
	double avgResTime;
	
	ledSwitchInit();
	
	for( exp_i = 0, resTimesSum = 0; exp_i < EXP_TOTAL; exp_i++ )
	{
		// - perform "experiment"
		resTime = experiment();
		resTimesSum += resTime;
		
		// - post-experiment blinking
		// ...		
	}
	
	avgResTime = ( (double) resTimesSum ) / (double) EXP_TOTAL;
	avgResTime /= 1000;		// to ms
	printf("Average Response Time: %.2f ms", avgResTime);
	
	return 0;
}

uint32_t experiment()
{
	return 0 == EXP_TYPE ? 
		captureResponseTimeFromTurnedOn() :
		captureResponseTimeFromTurnedOff();
}
