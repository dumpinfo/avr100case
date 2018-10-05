#ifndef WS2812_Drive
#define WS2812_Drive

sbit WS2812_DAT=P2^0;

#define      Pixel_Data_Num 25
extern void WS2812_Init();
extern void WS2812_Display_Ser();
extern u8 xdata WS2812_Write_Buffer[Pixel_Data_Num];


#endif