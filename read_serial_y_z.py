# -*- coding: utf-8 -*-
"""
Created on Sun Jan 19 21:29:16 2020

@author: Veronique Lankar

We are reading data from the serial USB (arduino). We are reading 2 values. y and z
In arduino we have: 
Serial.println(String(y)+";"+String(z));
we have a baud rate of 115200 (to report below)
You also need to report the USB port. check the PORT with the Arduino IDE tools->port
Report the port in this code

"""

import serial # install pyserial with pip
import numpy
arduinoData=serial.Serial('COM1',115200) # check tools/port to find out the PORT attached to arduino
arduinoData.flush() #flush the buffer
# baud rate is 115200
plt.ion() # to tell matplotlib we want live graph. used in another code. 


j=0
while j<100:
    while (arduinoData.inWaiting()==0): # wait till data are streming
        pass
    arduinoString=str(arduinoData.readline()) # read a string
   # print(arduinoString)
    arduinoString=arduinoString[2:] # the string has undesired characters
    arduinoString=arduinoString[:-5] # popping out those characters
   # print(arduinoString)
    dataArray=arduinoString.split(';',1) # splitting the string
   # print(dataArray)
    label=float(dataArray[0])
    number=float(dataArray[1])
    print(label,number)
    j=j+1
    

        
