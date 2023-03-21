# NodeMCU-I2C-with-Arduino-IDE-Project
The reference to this project can be found in the link https://www.electronicwings.com/nodemcu/nodemcu-i2c-with-arduino-ide.

The purpose of this project is to demonstrate my experience in,
  - Controlling and running multiple processes on multiple micro-controllers
  - Controlling access of multiple micro-controllers to a shared I2C bus.

In this project, I have built a prototype of two different micro-controllers.

Consider the image below,

![image](https://user-images.githubusercontent.com/105231479/226408126-d86e19d1-8a41-4cec-a0e8-fef521d9fcfb.png)

The image above shows how the protoype was connected.

The nodeMCU is the I2C master device and the Arduino Uno is the slave device.

In this project, the arduino as a slave has an address of 8.

Brief explanation about the serial bus interface connection protocol used in this project.

The serial bus interface connection protocol used in this project is the I2C. The I2C uses 2 wires for
communication. The two wires are serial clock(SCL) and serial data(SDA)

The I2C communication protocol is an acknowledgement based protocol i.e transmitter checks for an acknowledgement 
from receiver after transmitting data to check whether data is successfully received by the receiver.

The Inter-Integrated Circuit communication protocol works in 2 modes,

  a. Master mode.

  b. Slave mode.

The Serial data wire is used for exchange of data between the master and Slave. The serial clock wire is used 
for synchronous clock in between the slave and master devices.

In the protoype built in this project, 

1. The master device initiates communication with the slave device.

2. The slave address is required by the master to initiate communication. The slave responds with its address to the master.

In summary, This project shows how the Arduino uno and the ESP8266 or nodeMCU communicate via I2C protocol.

1. The nodeMCU as a master sends a "hello Arduino" string to the Arduino and the Arduino uno as a slave 
responds with the acknowledgement text of "hello nodeMCU".

Consider the image below.

![image](https://user-images.githubusercontent.com/105231479/226425984-779aa73b-ebf1-4349-bedb-f6a6e646a1b7.png)

The image above shows how the nodeMCU joins the I2C bus with the serial data connected at pin D1 and serial clock connected at D2 pins.

Transmission begins with the device address 8. The master sends "hello Arduino" string to the slave and then stops the transmission.

The nodeMCU then requests data of size 13 from the slave adress 8. While the data is available, read the data and store it in the character "c", then print the data on the serial monitor.

The sketch below shows how the slave sends, checks for received and requests data from the master.

![image](https://user-images.githubusercontent.com/105231479/226431942-dd55fe67-5573-473f-b0b9-f9a63e9b18bd.png)

![image](https://user-images.githubusercontent.com/105231479/226450057-d6926e27-b4c5-4686-ba63-ddac126798d7.png)

