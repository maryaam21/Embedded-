//   ___     ___    ____    ____            ___       ___     ___    ____    ____ 
// _/   \___/   \__/    \__/    \PWM Drawer/   \_____/   \___/   \__/    \__/    \


Drawing PWM using ATMega32 , 40*2 LCD and Keypad;

The project is separated into layers.
First layer  : Application Layer --> main.c
Second layer : Library layer --> files like: BIT_MATH, STD_TYPE and Error_State
Third layer  : Hardware Abstraction Layer -->  LCD_Driver and KEYPAD_DRIVER
FOURTH layer : Microcontroller Abstraction Layer --> DIO_Driver,EXTI_Driver,TIMERS_Driver and GIE_Driver 

//   ___     ___    ____    ____      ___      ___     ___    ____    ___   
// _/   \___/   \__/    \__/    \____/   \____/   \___/   \__/    \__/   \


