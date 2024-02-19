//   ___     ___    ____    ____    ____    ____    	   |	     	             |_     ___    ____    ____    ____    ____
// _/   \___/   \__/    \__/    \__/    \__/    \__/AUTHOR | MARIAM RAMADAN EL-Badri | \___/   \__/    \__/    \__/    \__/    \__
//																	Layer: HAL
/*LIB*/
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"

/*MCAL*/
#include "../../MCAL/DIO_DRIVER/DIO_interface.h"

/*HAL*/
#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"


u8 KPD_KEYS[4][4]={
	{'1','2','3','A'},
	{'4','5','6','B'},
	{'7','8','9','C'},
	{'*','0','#','D'}
};
void KEYPAD_Initiate(void){
	/* ROWS   --> INPUT */
	/*DIO_Vid_Set_Pin_Dir(KPD_ROW0_PORT,KPD_ROW0_PIN,INPUT);
	DIO_Vid_Set_Pin_Dir(KPD_ROW1_PORT,KPD_ROW1_PIN,INPUT);
	DIO_Vid_Set_Pin_Dir(KPD_ROW2_PORT,KPD_ROW2_PIN,INPUT);
	DIO_Vid_Set_Pin_Dir(KPD_ROW3_PORT,KPD_ROW3_PIN,INPUT);
	*/
	/* COLUMNS --> OUTPUT */
	/*DIO_Vid_Set_Pin_Dir(KPD_COL0_PORT,KPD_ROW0_PIN,OUTPUT);
	DIO_Vid_Set_Pin_Dir(KPD_COL1_PORT,KPD_ROW1_PIN,OUTPUT);
	DIO_Vid_Set_Pin_Dir(KPD_COL2_PORT,KPD_ROW2_PIN,OUTPUT);
	DIO_Vid_Set_Pin_Dir(KPD_COL3_PORT,KPD_ROW3_PIN,OUTPUT);
	*/
    u8 Loc_u8RArray[4]={KEYPAD_R0,KEYPAD_R1,KEYPAD_R2,KEYPAD_R3} ; 
    u8 Loc_u8CArray[4]={KEYPAD_C0,KEYPAD_C1,KEYPAD_C2,KEYPAD_C3} ; 	
	u8 Loc_u8_r=0 ; 
	u8 Loc_u8_c=0 ; 
		for(Loc_u8_r=0 ; Loc_u8_r<4;Loc_u8_r++){
			    /* Make all rows input */
			DIO_Vid_Set_Pin_Dir(KEYPAD_ROW_PORT,Loc_u8RArray[Loc_u8_r],INPUT) ; 
			/* Active pull up  */
			DIO_Vid_Set_Pin_Val(KEYPAD_ROW_PORT,Loc_u8RArray[Loc_u8_r],HIGH)  ;
		}   
	 
	 for(Loc_u8_c=0 ; Loc_u8_c<4;Loc_u8_c++){
		 
		 DIO_Vid_Set_Pin_Dir(KEYPAD_COL_PORT,Loc_u8CArray[Loc_u8_c],OUTPUT) ; 
		 DIO_Vid_Set_Pin_Val(KEYPAD_COL_PORT,Loc_u8CArray[Loc_u8_c],HIGH) ; 
	 }
	
	
}

u8 KEYPAD_GetKey(void){
	
	u8 ROWS_PINS[4]={KEYPAD_R0,KEYPAD_R1,KEYPAD_R2,KEYPAD_R3} ;
	u8 COLOs_PINS[4]={KEYPAD_C0,KEYPAD_C1,KEYPAD_C2,KEYPAD_C3} ;
	u8 Loc_u8_r=0 ;
	u8 Loc_u8_c=0 ;
	u8 Loc_u8_keyVAL=0xff ; 
	for(Loc_u8_c=0 ; Loc_u8_c<4;Loc_u8_c++){
		
		DIO_Vid_Set_Pin_Val(KEYPAD_COL_PORT,COLOs_PINS[Loc_u8_c],LOW) ;
		
		for(Loc_u8_r=0;Loc_u8_r<4;Loc_u8_r++){
			
			if(DIO_u8_Get_Pin_Val(KEYPAD_ROW_PORT,ROWS_PINS[Loc_u8_r])==0){
				
				Loc_u8_keyVAL=KPD_KEYS[Loc_u8_r][Loc_u8_c] ; 
				 while(DIO_u8_Get_Pin_Val(KEYPAD_ROW_PORT,ROWS_PINS[Loc_u8_r])==0) ;
				return Loc_u8_keyVAL ; 
				
			}
		}
			DIO_Vid_Set_Pin_Val(KEYPAD_COL_PORT,COLOs_PINS[Loc_u8_c],HIGH) ;
		}
		
		
		
		return Loc_u8_keyVAL ;
	}
	
	
	
	
	
	
