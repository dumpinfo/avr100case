#ifndef __DMA_H
#define __DMA_H

#include "sys.h"

#define TIM2_CCR4_Address 0x40000040


void TIM2_DMA_Init(void);
void SPI2_DMA_Init(void);

#endif
