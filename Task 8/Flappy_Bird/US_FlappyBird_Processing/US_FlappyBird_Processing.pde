import processing.serial.*;
int DistanceUltra;
int IncomingDistance;
Serial myPort ;
String DataIn;
Pipe p1 = new Pipe();
Pipe p2 = new Pipe();
Pipe p3 = new Pipe();
Pipe p4 = new Pipe();
Pipe p5 = new Pipe();
Pipe p6 = new Pipe();

//bird height and width location
float birdy = 46;
float birdx = 56;
float gravity = 2;
 
//the speed of the pipes
int speed;
 
//score and game state
boolean gameOver = false;
int score = 0;
int highscore = 0;
 
int point = 1;
 
color birdColor = color(255, 0, 0);
 
 
void setup(){
  size(700,700);
  p1.x = width + 50;
  p2.x = width + 220;
  p3.x = width + 370;
  p4.x = width + 470;
  p5.x = width + 570;
  p6.x = width + 670;
  
  
  myPort = new Serial(this, "COM6", 9600);
  myPort.bufferUntil(10);
}
void serialEvent (Serial myPort){
DataIn = myPort.readString();
println(DataIn);
IncomingDistance = int(trim(DataIn));
println("Presure level="+IncomingDistance);
if (IncomingDistance>1 && IncomingDistance<100 ) { DistanceUltra = IncomingDistance; //save the value only if its in the range 1 to 100 } }
}
}
 
void draw(){
 
  background(255,255,204);
  p1.pipe();
  p2.pipe();
  p3.pipe();
  p4.pipe();
  p5.pipe();
  p6.pipe();
 
 
  fill(birdColor);
  ellipse(birdx, birdy, 45,45);
 // birdy += gravity;
  play();
  success(p1);
  success(p2);
  success(p3);
  success(p4);
  success(p5);
  success(p6); 
 
  if (IncomingDistance>15)
  {
    //birdy -= jumpForce;
    birdy -= gravity;
  }    
  else
  {
    birdy += gravity;
  }
  
}
 
 
void play(){
 
  if(gameOver == false)
  {
    speed = 2;
    p1.x -= speed;
    p2.x -= speed;
    p3.x -= speed;
    p4.x -= speed;
    p5.x -= speed;
    p6.x -= speed;
   
   
   
    textSize(24);
    fill(0,0,0);
    text(score, width/2, 30);  
  }
 
  if(gameOver == true)
  {
    speed = 0;
    p1.x -= speed;
    p2.x -= speed;
    p3.x -= speed;
    p4.x -= speed;
    p5.x -= speed;
    p6.x -= speed;
   
    if( highscore < score)
    {
       highscore = score;
    }
   
    textSize(16);
    fill(0, 102, 153);
    textAlign(CENTER);
    text("Click : Play Again", width/2, height/2);
    text("Score: " + score, width/2, height/2 - 20);
    text("High-Score: " + highscore, width/2, height/2 - 40);
   
    if (mousePressed)
    {
       delay(900);
       score = 0;
       gameOver = false;
       birdy = 100;
       birdx = 56;
       p1.x = width + 50;
       p2.x = width + 220;
       p3.x = width + 370;
       p4.x = width + 470;
       p5.x = width + 570;
       p6.x = width + 670;
       
       
       p1.top = random(height/2);
       p1.bottom = random(height/2);
       p2.top = random(height/2);
       p2.bottom = random(height/2);
       p3.top = random(height/2);
       p3.bottom = random(height/2);
       p4.top = random(height/2);
       p4.bottom = random(height/2);
       p5.top = random(height/2);
       p5.bottom = random(height/2);
       p6.top = random(height/2);
       p6.bottom = random(height/2);
       
       
       
    }  
  }
 
}
 
void success(Pipe test){
 
  if(birdy < test.top || birdy > height - test.bottom)
  {
    if(birdx > test.x && birdx < test.x + test.w)
    {
      gameOver = true;
    }
  }
}
class Pipe
{
  float top = random(height/3 + 150);
  float bottom = random(height/3 +200);
 
 
  float x = width + 150;
  float w = 50;
  color pipeColor = color(255, 178, 102);
 
  void pipe()
  {
    fill(pipeColor);
    rect(x, 0, w, top);
    rect(x, height-bottom, w, bottom);
   
    if(x < -100)
    {
     score += point;
     x = width;
     top = random(height/2);
     bottom = random(height/2);
    }
 
   
  }
 
 
}
