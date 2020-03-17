// ASABE Robotics 2020
/*
 * ASABE Robotics 2020 Competition Code
 * 
 * Written By: Cody Kapka
 * Date: 03/17/20
 */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LIBRARIES INCLUDED ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <Pixy2.h>      // Pixy2 library 


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ PIXY2 OBJECT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*
 * Pixy2 sensor is calibrated and configureated using Pixymon software. 
 * Pixy Documentation: https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:start
 * Pixy Object Detection API: https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:ccc_api
 */
Pixy2 pixy;

// Pencil test color variables
int orange = 1;
int pink = 2;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OBJECT STRUCTURE - PLANT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*
 * Plant is object set up as an array value. The object detected from the Pixy contains
 * several details about this object. The plant object stores the "signature" of the 
 * object detected (healthy, stressed, etc.). This signature is created in the Pixymon
 * Software for the Pixy sensor. The second element in the Plant Object is the index number
 * of the object. This communicates to the arduino if the object detected is a new object,
 * or the same object still in frame. Both the signature and index of the object are utilized
 * for processing of plant variation.
 */
//Array or stored pencil values
const int rows = 4;
const int columns = 16;
int arr1[rows][columns];

//Plant imaging 
int plant[2];
int currIndex = 0;
int preIndex = 0;

int i = 0;
int j = 0;
int k = 0;
int l = 0;

//Initialization of code on startup
void setup()
{
  Serial.begin(115200);                   //baud rate required for communication between Pixy2 and Arduino Interface monitor
  Serial.print("Starting...\n");

  pixy.init();
    
}

void loop()
{ 
  // grab blocks!
  pixy.ccc.getBlocks(true,3,1);


  //Creation of "plant" object that contains signature of plant followed by index value
  plant[0] = pixy.ccc.blocks[0].m_signature;
  //Serial.println(plant[0]);
  plant[1] = pixy.ccc.blocks[0].m_index;
  //Serial.println(plant[1]);

  currIndex = plant[1];

  while (currIndex != preIndex) {
    if (plant[0] == 1) {

      //Input value of plant to array
      arr1[i][j] = plant[0];
      if (j == 16) {
        i = i++;
      }
      j++;        //Index column in array
    
    }
    else if (plant[0] == 2) {
    
      //Input value of plant to array
      arr1[i][j] = plant[0];
      if (j == 16) {
        i = i++;
      }
      j++;        //Index column in array
    
    }

    //Output of array to screen
    for (k = 0; k < rows; k++) {
      for (l = 0; l < columns -1; l++) {
        Serial.print(arr1[k][l]);
      }
      Serial.println(arr1[k][l]);
    }

    //Update old index to reflect current index value
    preIndex = currIndex;
  }
  
}
  
