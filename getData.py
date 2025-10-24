#script python      

import serial
import time 
import os

arduino_port ='COM4'
baUd_rate = 9600
ser = serial.serial
(arduino_port, baud_rate, timeout=1)
time.sleep(2)
while True
data=ser.readline().decode('utf-8').rstrip()
if data:
    print(data)
   # humidity,temperature=data.split(",")
    #print(f"humedad:{humidity}%, Temperatura: {temperature}°C")
    time.sleep(1)
    #STRIP: ELIMINA