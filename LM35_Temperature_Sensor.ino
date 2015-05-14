/*****************************************************************************
* Copyright (C) 2012 by Vasco Ferraz. All Rights Reserved.                   *
*                                                                            *
* This program is free software: you can redistribute it and/or modify       *
* it under the terms of the GNU General Public License as published by       *
* the Free Software Foundation, either version 3 of the License, or          *
* (at your option) any later version.                                        *
*                                                                            *
* This program is distributed in the hope that it will be useful,            *
* but WITHOUT ANY WARRANTY; without even the implied warranty of             *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the               *
* GNU General Public License for more details.                               *
*                                                                            *
* You should have received a copy of the GNU General Public License          *
* along with this program. If not, see <http://www.gnu.org/licenses/>.       *
*                                                                            *
*  Author:        Vasco Ferraz                                               *
*  Contact:       http://vascoferraz.com/contact/                            *
*  Description:   http://vascoferraz.com/tutorials/lm35-temperature-sensor/  *
*****************************************************************************/

const int analogtemp=0; // This is the analog pin which is measuring the input voltage from the LM35 temperature sensor
double temp=0, Vin=0, samples[250];
unsigned int j=0;
const double Vref=1100.0;

// The setup function runs only once when you power or reset the board
void setup ()
{
 Serial.begin(9600);
 analogReference(INTERNAL);
}

// The loop function runs indefinitely after the setup function ends
void loop ()
{
 Vin=0;
 temp=0;
  
  for(j=0 ; j<=249 ; j++)
  {
   samples[j] = (analogRead(analogtemp));    // Each sample is a value from 0 to 1023. Reading "j" values will help making the reading more accurate.
   Vin = Vin + ( samples[j] * Vref/1024.0);  // Here you convert from ADC to miliVolt -> Voltage = ADC*Vref/1024. ADC = [0;1023]
   // For a 10-bit ADC with an 1100mV reference, the most you can measure without saturating the ADC would be (1100mV - 1100mV/1024) = 1098.9mV.
   // In other words, a reading of 1023 from your ADC equals (1023 * 1100/1024mV) equals 1098.9 mV.
   // Remember, 10 bits can only represent a value as large as b1111111111 or decimal 1023.
  }

 Vin=Vin/250.0; // Calculate the average value from all "j" readings.
 temp = (Vin/10.0);
 Serial.print(temp,1);
 Serial.println(" degrees Celsius");
}
