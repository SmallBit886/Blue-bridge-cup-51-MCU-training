#include <STC15F2K60S2.H>
#include "LED.h"
#include "buzz.h"
#include "relay.h"
#include "SMG.h"
#include "key.h"
#include "exit.h"

unsigned char code daunma[];
void Delay(unsigned int ms);	
void Init_HC138(unsigned char n);