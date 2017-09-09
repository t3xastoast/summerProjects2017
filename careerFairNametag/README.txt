This digital nametage displays my name, major, expected graduation date and a scrolling message. It's powered using SparkFun's Arduino clone. There are four wires connected as follows:

--GND on the display goes to GND on the arduino
--VCC on the display goes to 5V on the arduino
--SDA on the display goes to A4 on the arduino
--SCL on the diplay goest to A5 on the arduino

The scrolling message on the bottom must be larger than 20 characters, and the first three lines muse each be less than 20 characters. The gray screw inside the blue box is a potentiometer that controls the brightness of the screen.

Portions of the code were retrieved from http://wiki.sunfounder.cc/index.php?title=I2C_LCD2004, and the rest was written by me (see code for details)


