// ASABE Robotics 2020
/*
 * ASABE Robotics 2020 Competition Code
 * 
 * Written By: Cody Kapka
 */


/*  
 *   Libraries included in code.
 */
// Pixy2 library 
#include <Pixy2.h>        

/*
 * Variable declaration
 */

// Declaring Pixy2
Pixy2 pixy;

// Pencil color variables
int orange = 1;
int pink = 2;

//Array or stored pencil values
const int rows = 4;
const int columns = 16;
int arr1[rows][columns];

//Plant imaging 
int plant[2];
int i = 1;
int j = 1;


//Initialization of code on startup
void setup()
{
  Serial.begin(115200);                   //baud rate required for communication between Pixy2 and monitor
  Serial.print("Starting...\n");

  pixy.init();
    
}

void loop()
{ 

/**
 * Testing of array construction
 */


  // grab blocks!
  pixy.ccc.getBlocks(true,3,1);
  
  // If there are detect blocks, print them!
  if (pixy.ccc.numBlocks)
  {
    Serial.print("Detected ");
    Serial.println(pixy.ccc.numBlocks);


    //Creation of "plant" object that contains signature of plant with index value
    plant[0] = pixy.ccc.blocks[0].m_signature;
//    Serial.println(plant[1]);
    plant[1] = pixy.ccc.blocks[0].m_index;
//    Serial.println(plant[2]);

    for (i = 0; i < 2; i++) {
      Serial.println(plant[i]);
    }

    Serial.println(plant[1] != plant[1]);

    
//    //Storing of plant in array1
//    if (plant[1] =! plant[1]) {
//      if (plant[0] == 1) {
//        Serial.println("Here");
////        arr1[i][j] = plant[0];
////        j++;
//      }
////      else {
////        arr1[i][j] = plant[0];
////        j++;
////      }
//    }

  j++;
//  
//    for (int i = 0; i < rows; i++){
//      for (int j = 1; j < columns; j++){
//        Serial.print(arr1[i][j]);
//      }
//      Serial.println(arr1[i][i]);
//    }
  }
}  
