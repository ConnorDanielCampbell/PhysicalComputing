  /*
Virtual Ball to Real Ball 
Connor Campbell 
DIGF 2B03 - Physical Computing
OCAD University Created on 24 March 2014
Based on:
Physical Pixel, David A. Melis, http://www.arduino.cc/en/Tutorial/PhysicalPixel
Bouncy Ball Array, Connor Campbell
*/ 
 
 import processing.serial.*; 
 
 float boxX;
 float boxY;
 int boxSize = 20;
 boolean mouseOverBox = false;
 
 Serial port; 

int dots = 1;
int nextcolor = 25;

float [] x = new float[dots];
float [] y = new float[dots];
float [] velocityX = new float[dots];
float [] velocityY = new float[dots];
//int [] angle = new int[dots];
 
float [] radius = new float[dots];
float [] girth = new float[dots];
color [] ballcolor = new color[nextcolor];
  
  
  
void setup()
{
  size(450,450);
  noStroke();
  boxX = width/2.0;
 boxY = height/2.0;
 rectMode(RADIUS); 
   
  for (int i=0 ; i<dots; i++)
  {
   
  //radius[i] = 20;
  //girth[i] = 20;
  //ballcolor[i] = color(random(0,50),random(0,255),random(0,255));
  //rotatecircle [i] = PI/4;
  x[i] = random(0,width/2);
  y[i] = random(height/2,height);
  velocityX[i] = (random(0,10));
  velocityY[i] = (random(0,10));
  //float angle = 0;
}
}
  
  
  
void draw(){
   
  fill(140,140,50,5);
  rect(0,0,width,height);
    
  for (int i=0 ; i<dots; i++)
  {
  x[i] += velocityX[i];
  y[i] += velocityY[i];
    
    
  //rotate(angle[i]++);
  //ellipse(x[i],y[i],radius[i],girth[i]);
    fill(100,0,255);
    ellipse(x[i],y[i],50,50);
  
  if((x[i]<0)||(x[i]>width))
  {
    velocityX[i] = -velocityX[i];
    port.write('H');  
    //girth[i] =girth[i]*2;
    //radius[i] =radius[i]/2;
  }
    
  if((y[i]<0)||(y[i]>height))
  {
    velocityY[i] = -velocityY[i];
    port.write('L'); 
    //girth[i] =girth[i]/2;
    //radius[i] = radius[i]*2;
  }
  


  
//  if((girth[i]>900) || (radius[i]>900))
//  {
//    girth[i] = 10;
//    radius[i] = 10;
//  }
 
}
}
