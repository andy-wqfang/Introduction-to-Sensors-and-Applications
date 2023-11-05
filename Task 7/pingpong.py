import pygame
import random
import serial
 
arduinoData = serial.Serial('COM6', 115200)
 
# Initialize Pygame
pygame.init()
pygame.display.set_caption("Accelerometer Game by Osman Gul")
# Set the screen size
screen_width = 400
screen_height = 400
screen = pygame.display.set_mode((screen_width, screen_height))
 
# Set the game clock
clock = pygame.time.Clock()
 
# Set the colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
 
# Set the font
font = pygame.font.SysFont('Arial', 30)
 
# Set the ball properties
ball_pos = [screen_width // 2, screen_height // 2]
ball_radius = 10
ball_speed = [5, 5]
 
# Set the paddle properties
paddle_width = 100
paddle_height = 10
paddle_speed = 5
 
paddle_pos = [(screen_width - paddle_width) // 2, screen_height - paddle_height]
 
# Set the score
score = 0
 
# Main game loop
running = True
while running:
    while (arduinoData.inWaiting() == 0):  # Wait here until there is data
        pass  # do nothing
    arduinoString = arduinoData.readline()  # read the line of text from the serial port
    arduinoString = arduinoString.decode('UTF-8').strip()
    data = int(arduinoString)
    #print(data)
 
    #data = ser.readline().decode().strip()
 
    # Handle events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
 
    # Move the paddle
    if data< 0:
        paddle_pos[0] -= paddle_speed
    if data> 0:
        paddle_pos[0] += paddle_speed
 
    # Move the ball
    ball_pos[0] += ball_speed[0]
    ball_pos[1] += ball_speed[1]
 
    # Check for ball collision with the walls
    if ball_pos[0] <= ball_radius or ball_pos[0] >= screen_width - ball_radius:
        ball_speed[0] = -ball_speed[0]
    if ball_pos[1] <= ball_radius:
        ball_speed[1] = -ball_speed[1]
 
    # Check for ball collision with the paddle
    if ball_pos[1] >= paddle_pos[1] - ball_radius and paddle_pos[0] <= ball_pos[0] <= paddle_pos[0] + paddle_width:
        ball_speed[1] = -ball_speed[1]
        score += 1
 
    # Check for game over
    if ball_pos[1] >= screen_height:
        running = False
 
    # Draw the game objects
    screen.fill(BLACK)
    pygame.draw.circle(screen, WHITE, ball_pos, ball_radius)
    pygame.draw.rect(screen, WHITE, (paddle_pos[0], paddle_pos[1], paddle_width, paddle_height))
    score_text = font.render('Score: ' + str(score), True, WHITE)
    screen.blit(score_text, (20, 20))
    #print(data)
    # Update the screen
    pygame.display.flip()
 
    # Set the game speed
    clock.tick(60)
 
print("Score =", score)
 
# Quit Pygame
pygame.quit()
