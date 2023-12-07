# LM35-Temperature-Sensor

emperature sensors are widely used in domestic and industrial applications such as: refrigerators; ovens; HVAC environmental control; in the automotive industry to monitor air intake, coolant or cylinder head temperatures. Even your television has a temperature sensor to shut it down if the internal temperature rises above a certain limit.

The goal of these sensors is to measure heat and ensure that a process is either: staying within a certain range, providing safe use of that application, or meeting a mandatory condition when dealing with extreme heat, hazards, or inaccessible measuring points.

For this project I used a LM35CAZ temperature sensor from Texas Instruments [datasheet](resources/LM35.pdf). The LM35 series are precision integrated-circuit temperature sensors with an output voltage linearly proportional to the Celsius temperature: 0mV + 10mV/ºCelsius. That is, for each 1ºCelsius increase, the temperature sensor output voltage will raise 10mV. This is when the Arduino and one of its analog inputs comes in.

This is why I love working with this development tool. To build a thermometer you just need:

– 1x Arduino Nano 3.0
– 1x LM35 temperature sensor
– Breadboard and wires

Now you have to replicate the circuit below:<br/>
<br/>
![alt text](resources/LM35-Temperature-Sensor_bb.png?raw=true)

Upload the [code](LM35_Temperature_Sensor.ino) to the board.

Now open the serial monitor and watch the magic.<br/>
<br/>
![alt text](resources/SerialMonitor.jpg?raw=true)

Keep in mind that, depending on which Arduino Nano hardware revision you own, there are two analog pin sequences. Confused? Well, an image worth more than a thousand words:<br/>
<br/>
![alt text](resources/AnalogPins.jpg?raw=true)

If you prefer to work with temperatures in Fahrenheit, you can use the formula below to convert the temperature from Celsius to Fahrenheit:
°F = °C x 1.8 + 32