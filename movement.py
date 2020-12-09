
#    Laser Security System

# Name: Bhavya Patel

# MY reference python code is taken from the below link:
# https://learn.adafruit.com/arduino-lesson-17-email-sending-movement-detector/python-code

 #   This code will send a message to the phone

import time
import serial
import smtplib

TO = 'bhavyapatel12338@gmail.com'
GMAIL_USER = 'bhavyapatel12338@gmail.com'
GMAIL_PASS = '17112001'

SUBJECT = 'Alert!!'
TEXT = 'Movement has been dectected'
  
ser = serial.Serial('/dev/cu.usbmodem14201', 9600)

def send_email():
    print("Sending Email")
    smtpserver = smtplib.SMTP("smtp.gmail.com",587)
    smtpserver.ehlo()
    smtpserver.starttls()
    smtpserver.ehlo
    smtpserver.login(GMAIL_USER, GMAIL_PASS)
    header = 'To:' + TO + '\n' + 'From: ' + GMAIL_USER
    header = header + '\n' + 'Subject:' + SUBJECT + '\n'
    print(header)
    msg = header + '\n' + TEXT + ' \n\n'
    smtpserver.sendmail(GMAIL_USER, TO, msg)
    smtpserver.close()
    
while True:
    message = ser.readline().decode("utf-8")
    print(message)
    if 'MOVEMENT' in message :
        send_email()  
    time.sleep(0.5)
