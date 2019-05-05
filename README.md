# Room DHT11 Monitoring
This is a system dht11 based for monitoring temperature and humidity indoor. 
It has been developed to report bad conditions based on the humidity that should be between 40-60% and temp between 21-22°C.

There is a button to turn ON the LCD display (you have to press it for 1s) and it turns off automatically after 5s(+1). 

* Blue led: Humidity over 55% 

* Orange led: Humidity under 35%

* White led: Temperature under 20°C 

* Red led: Temperature over 23°C 

## Prototype Layout
If you want to run sketch in this repository, you can connect components like this.

![prototype_layout](https://user-images.githubusercontent.com/14968550/57195431-920f7a00-6f52-11e9-9e8e-ed82d3c28bfc.PNG)

## Config
You can change the range of led action simply edit conditions like this and replace the number
```c++
 if(sensor.temperature >= 23.00){
    delay(delayTime);
    analogWrite(ROSSO, 5);
  }
```
I recommend leaving the operation of the button unchanged, both for energy saving and to ensure the long-lasting operation of the prototype.

## Limitations and future developments

There are too many cables! One of future developments is surely draw and print a PCB with software like Altium to remove this terrible connection. 
The actual limit of this project is that it doesn't communicate data on a smartphone app for example. 

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
This software is free.
[GPL](http://www.gnu.org/licenses/gpl.html)
