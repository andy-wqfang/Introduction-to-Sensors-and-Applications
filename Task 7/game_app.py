import pygame
import numpy
import sys
import serial

arduinoData = serial.Serial('COM6', 115200)  # Creating our serial object named arduinoData
 
SCREEN_WIDTH = 640
SCREEN_HEIGHT = 480
 
white = (255, 255, 255)
black = (0, 0, 0)
 
pos_x = 200
pos_y = 200
 
color1 = (192, 192, 192)
color2 = (153, 0, 0)
 
 
pygame.init()
pygame.display.set_caption("Game by Osman Gul")
 
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
clock = pygame.time.Clock()
 
while True:  # While loop that loops forever
    while (arduinoData.inWaiting() == 0):  # Wait here until there is data
        pass  # do nothing
    arduinoString = arduinoData.readline()  # read the line of text from the serial port
    arduinoString = arduinoString.decode('UTF-8').strip()
    print("arduinoString: " + arduinoString)
    dataArray = arduinoString.split(',')  # Split it into an array called dataArray
    # for e in dataArray:
    #     if not isinstance(e, int):
    #         dataArray.remove(e)
    # print(dataArray)
    x = int(dataArray[0].strip())
    z = int(dataArray[1].strip())
 
    clock.tick()
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
 
 
    if z>0:
        pos_x += 5
 
    if z < 0:
        pos_x -= 5
 
    if x > 0:
        pos_y += 5
 
    if x < 0:
        pos_y -= 5
 
    screen.fill(color1)
    pygame.draw.circle(screen, color2, (pos_x, pos_y), 20)
    pygame.display.update()