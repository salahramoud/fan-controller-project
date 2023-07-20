/*
 * main.c
 *
 *  Created on: ٠٨‏/١٠‏/٢٠٢٢
 *      Author: salah ramoud
 */
#include "lcd.h"
#include "adc.h"
#include "DCmotor.h"
#include "lm35_sensor.h"



int main(void)
{

	uint8 temp;
	LCD_init();
	DcMotor_Init();
	ADC_ConfigType adc_config={INTERNAL,F_CPU_8};
	ADC_init(&adc_config);
	LCD_moveCursor(0,3);
	LCD_displayString("FAN IS    ");  //10
	LCD_moveCursor(1,3);
	LCD_displayString("Temp =    C"); //10





	while(1)
	{
		/*get the temperature value*/
    	temp = LM35_getTemperature();
		LCD_moveCursor(1,10);
		if(temp >= 100)
			{
				LCD_intgerToString(temp);
			}
		else
			{

			  LCD_intgerToString(temp);
			  LCD_displayCharacter(' ');
			}
		LCD_moveCursor(0,10);
		if(temp<30)
		{
			LCD_displayString("off");
			DcMotor_Rotate(STOP,0);
		}
		else if((temp>=30)&&(temp<=60))
			{
			LCD_displayString("on");
			  LCD_displayCharacter(' ');
			DcMotor_Rotate(CLOCKWISE,25);
			}
		else if((temp>60)&&(temp<=90))
		{
			LCD_displayString("on");
			  LCD_displayCharacter(' ');
			DcMotor_Rotate(CLOCKWISE,50);
		}
		else if((temp>90)&&(temp<=120))
		{
			LCD_displayString("on");
			  LCD_displayCharacter(' ');
			DcMotor_Rotate(CLOCKWISE,75);
		}
		else if(temp>120)
		{
			LCD_displayString("on");
			  LCD_displayCharacter(' ');
			DcMotor_Rotate(CLOCKWISE,100);
		}






	}


}

