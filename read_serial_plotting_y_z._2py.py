# -*- coding: utf-8 -*-
"""
Created on Sun Jan 19 21:29:16 2020

@author: Veronique Lankar

reference: Paul McWhorter (youtube) see the series Arduino - Python

to plot USB serial data (Arduino) live
We are reading data from arduino. We are reading 2 values y and z
by default y is an index 0,1,2,3 .. and z random static (between 0 and 600) 
Serial.println(String(y)+";"+String(z)); 
we have a baud rate of 115200
check the PORT with tools->port 
"""

import serial # install pyserial with pip
import numpy
import matplotlib.pyplot as plt
from drawnow import *  # to draw live data
arduinoData=serial.Serial('COM1',115200) # check tools/port to find out the PORT attached to arduino
arduinoData.flush() #flush the buffer
# baud rate is 115200
plt.ion() # to tell matplotlib we want life graph
y=[] 
z=[]

def makeFig(): 
    plt.plot(z,'b^-',label='random')
    plt.legend(loc='upper left')
    plt.title('my graph')
    plt.xlabel(' my x-axis')
    plt.ylabel('my y-axis')
    plt.axis([0,50,0,600])
    plt.grid(True)




j=0
while j<100:
    while (arduinoData.inWaiting()==0): # wait till data are streming
        pass
    arduinoString=str(arduinoData.readline()) # read a string
    print(arduinoString)
    arduinoString=arduinoString[2:] # the string has undesired characters
    arduinoString=arduinoString[:-5] # popping out those characters
    print(arduinoString)
    dataArray=arduinoString.split(';',1) # splitting the string
    print(dataArray)
    label=float(dataArray[0])
    number=float(dataArray[1])
    print(label,number)
    y.append(label) # make an array with variable y
    z.append(number) # make an array with variable z
    print(y)
    drawnow(makeFig,show_once=True) # drawing life data
    if j>50: # we only keep the 50 last values. we pop all values before that.
        y.pop(0)
        z.pop(0)
    plt.pause(0.000001)
    j=j+1
    

        
