# -*- coding: utf-8 -*-
"""
Created on Sun Jan 19 21:29:16 2020

@author: Veronique Lankar

We are reading data from arduino. We are reading 2 values. y and z
In arduino we have: 
Serial.println(String(j)+";"+String(sensorValue)); with arduino
we have a baud rate of 115200
check the PORT with tools->port
Report the port in this code
This program save data in a file
"""

import serial # install pyserial with pip
import numpy
import matplotlib.pyplot as plt
from drawnow import *  # to draw life data
arduinoData=serial.Serial('COM1',115200) # check tools/port to find out the PORT attached to arduino
arduinoData.flush() #flush the buffer
# baud rate is 115200
plt.ion() # to tell matplotlib we want life graph
y=[]
z=[]

def makeFig(): 
    plt.plot(z,'ro-')


file=open("data_python.txt",mode='w')

j=0
while j<100:
    while (arduinoData.inWaiting()==0): # wait till data are streming
        pass
    arduinoString=str(arduinoData.readline()) # read a string
   # print(arduinoString)
    arduinoString=arduinoString[2:] # the string has undesired characters
    arduinoString=arduinoString[:-5] # popping out those characters
   # print(arduinoString)
    file.write(arduinoString) # writing in a text file with ; deliminiter
    file.write('\n')
    dataArray=arduinoString.split(';',1) # splitting the string
   # print(dataArray)
    label=float(dataArray[0])
    number=float(dataArray[1])
    print(label,number)


    j=j+1
file.close()   

        
