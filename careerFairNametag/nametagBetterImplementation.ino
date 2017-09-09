
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~BEGIN CODE RETREIVED FROM~~~~~~~~~~~~~~~~~~
// http://wiki.sunfounder.cc/index.php?title=I2C_LCD2004
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 

/*****************************************
 * name: I2C LCD2004
 * function: You should now see your I2C LCD2004 display "Hello,world!","IIC/I2C LCD2004"
 * "20 cols, 4 rows","www.sunfounder.com"
 ********************************/
//Email:service@sunfounder.com
//Website:www.sunfounder.com

/********************************/
// include the library code

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
/*********************************************************/

//following comments added
//WE ARE ASSUMING THE FOURTH LINE TO PRINT WILL BE LARGER THAN 20 CHARS!!!!!!!
//Don't forget to include a space at the end of the message

static String bottomText = "Together we'll do ohmazing things :) ";
static int siize = bottomText.length();

void setup()
{
  lcd.init();  //initialize the lcd
  lcd.backlight();  //open the backlight 

  
  
  String sequence = bottomText.substring(0,20);

  
  lcd.setCursor ( 0, 0 );            // go to the top left corner
  lcd.print("      Tim Press     "); // write this string on the top row
  lcd.setCursor ( 0, 1 );            // go to the 2nd row
  lcd.print("Computer Engineering"); // pad string with spaces for centering
  lcd.setCursor ( 0, 2 );            // go to the third row
  lcd.print("     Spring 2019    "); // pad with spaces for centering
  lcd.setCursor ( 0, 3 );            // go to the fourth row
  lcd.print(sequence);
}
/*********************************************************/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~END CODE RETREIVED FROM~~~~~~~~~~~~~~~~~~
// http://wiki.sunfounder.cc/index.php?title=I2C_LCD2004
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//BEGIN CODE I WROTE
//ie, I implemented the scrollDisplayLeft method myself
//I did this because using scrollDisplayLeft resulted in text jumping lines
//from my understanding, it's a hardware issue with the display other people have also reported

String substringOfLengthTwnety(String longString, int startingIndex){

   /*see if the substring will "wrap around" to the front*/
  int len, endIndex; 
  len = longString.length();
  endIndex = startingIndex + 20;


  if (endIndex > len){
    //special case
    String str1 = longString.substring(startingIndex, len);

    int remainingChars = endIndex-len;
    String str2 = longString.substring(0, remainingChars);
    String retStr = str1+str2;
    return retStr;
  }
  else{
    //easier case
    String retStr = longString.substring(startingIndex, startingIndex + 20);
    return retStr;
  }

}
 
void loop() 
{

  for (int i = 0; i < siize; i++){
    String ummm = substringOfLengthTwnety(bottomText, i);
    lcd.setCursor(0,3);
    lcd.print(ummm);
    delay(500);
  }
  
  
}

//END CODE I WROTE
