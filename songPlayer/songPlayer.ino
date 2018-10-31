pla#include <Tone.h>

 Tone tone1;
 Tone tone2;
 
 float tempo = 394; // get tempo by doing 60 000 / number of 8th notes per min

const float notes1[]  =  {2000000.0, 2000000.0, 2000000.0, 2000000.0, 392.0, 440.0, 349.28, 329.6, 349.28, 392.0, 493.92, 523.2, 523.2, 349.28, 349.28, 523.2, 659.2, 784.0, 698.56, 587.2, 440.0, 493.92, 493.92, 784.0, 698.56, 587.2, 440.0, 493.92, 493.92, 440.0, 329.6, 329.6, 261.6, 329.6, 440.0, 523.2, 523.2, 587.2, 523.2, 440.0, 329.6, 659.2, 349.28, 698.56, 349.28, 698.56, 587.2, 587.2, 493.92, 523.2, 587.2, 523.2, 587.2, 698.56, 523.2, 246.96, 220.0, 246.96, 246.96, 784.0, 698.56, 659.2, 587.2, 659.2, 587.2, 659.2, 698.56, 698.56, 659.2, 880.0, 784.0, 659.2, 493.92, 392.0, 329.6, 659.2, 493.92, 392.0, 329.6, 246.96, 2000000.0, 2000000.0,  };
const int times1[]  = { 8,   8,   8,   8,   6,   2,   6,   1,   1,   6,   1,   1,   1,   1,   4,   1,   1,   3,   1,   2,   1,   1,   8,   2,   2,   2,   1,   1,   6,   2,   8,   4,   1,   1,   1,   1,   4,   3,   1,   2,   1,   1,   1,   1,   1,   1,   1,   4,   1,   1,   2,   1,   2,   3,   6,   1,   1,   8,   8,   1,   1,   1,   1,   1,   1,   1,   1,   1,   3,   4,   1,   1,   1,   1,   4,   1,   1,   1,   1,   4,   8,   8,   };
const float notes2[]  =  {110.0, 130.8, 220.0, 246.96, 261.6, 246.96, 220.0, 164.8, 146.8, 174.64, 261.6, 329.6, 261.6, 220.0, 220.0, 110.0, 130.8, 220.0, 246.96, 261.6, 246.96, 220.0, 164.8, 146.8, 174.64, 261.6, 329.6, 261.6, 220.0, 220.0, 110.0, 130.8, 220.0, 246.96, 261.6, 246.96, 220.0, 164.8, 146.8, 174.64, 261.6, 329.6, 261.6, 220.0, 220.0, 110.0, 130.8, 220.0, 246.96, 261.6, 246.96, 220.0, 164.8, 146.8, 174.64, 261.6, 329.6, 261.6, 220.0, 220.0, 98.0, 123.48, 146.8, 174.64, 220.0, 174.64, 146.8, 123.48, 98.0, 123.48, 146.8, 174.64, 220.0, 98.0, 123.48, 146.8, 174.64, 220.0, 174.64, 146.8, 123.48, 98.0, 123.48, 146.8, 174.64, 220.0, 110.0, 130.8, 220.0, 246.96, 261.6, 246.96, 220.0, 164.8, 110.0, 130.8, 220.0, 246.96, 2000000.0, 2000000.0, 123.48, 146.8, 174.64, 220.0, 261.6, 123.48, 146.8, 174.64, 220.0, 261.6, 98.0, 123.48, 146.8, 174.64, 220.0, 110.0, 164.8, 82.4, 98.0, 123.48, 164.8, 196.0, 164.8, 123.48, 98.0, 82.4, 98.0, 123.48, 164.8, 196.0, 164.8, 110.0, 98.0, 123.48, 146.8, 174.64, 220.0, 174.64, 146.8, 123.48, 110.0, 130.8, 164.8, 220.0, 261.6, 246.96, 220.0, 164.8, 82.4, 98.0, 123.48, 164.8, 196.0, 82.4, 98.0, 123.48, 164.8, 196.0, 82.4, 98.0, 123.48, 164.8, 164.8, 82.4, 98.0, 123.48, 164.8, 123.48,  };
const int times2[]  = { 1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   2,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   2,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   2,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   2,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   4,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   4,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   4,   4,   1,   1,   1,   1,   4,   1,   1,   1,   1,   4,   1,   1,   1,   1,   4,   8,   8,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   2,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   4,   1,   1,   1,   1,   4,   1,   1,   1,   1,   4,   1,   1,   1,   1,   4,   };


unsigned long currentMillis;
unsigned long count1Millis = 0;
unsigned long count2Millis = 0;



 int count1 = 0;
 int count2 = 0;
 void setup() {
 tone2.begin(13);
 tone1.begin(12);
  
Serial.begin(9600);
Serial.print("Hello!");
delay(500);


// tempo 394 Minecraft theme
/*
 for(int i = 0; i < 70 ; i++)
  {

    

    if(notes[i] == "Z")
      {
        delay(times[i] * tempo);
        
      }

      else
      {
    

      playNote(notes[i], octaves[i], times[i] );
      delay(times[i] * tempo);
      }


    
  }
  */

  tone1.play(notes1[count1],  times1[1] );
  tone2.play(notes2[count2], times2[2]);

}

void loop() {
  // put your main code here, to run repeatedly:
  //tone(4, 2800, 300);
  // delay(1000);

 currentMillis = millis();
















  
  if(currentMillis - count1Millis >= tempo * times1[count1])
   {  count1++;
      count1Millis = currentMillis;
      //Serial.println("increasing count 1");
      tone1.play(notes1[count1],  times1[1] * tempo );
      //playNote(notes1[count1], octaves1[count1], times1[count1], 1);
     
   }


 if(currentMillis - count2Millis >= tempo * times2[count2])
   {  count2++;
      count2Millis = currentMillis;
      tone2.play(notes2[count2], times2[2] * tempo);

      //Serial.println("increasing count 2");
      //playNote(notes2[count2], octaves2[count2], times2[count2], 2);
   }
   
    
  
 

 



 

 // delay(5000);

 
  
}

/*
void playSong(String[] notes, int[] duration)
{
  

  
}
*/

//Duration needs to be a float 
/*
void playNote(String note, int octave, float duration, int part) //Quarter note = 1
{ 
  
  float freq = 0.0;
  
  if(note.equals("C"))
    freq = 16.35;

  else if(note.equals("C#"))
    freq = 17.32;

  else if(note.equals("D"))
    freq = 18.35;

  else if(note.equals("Eb"))
    freq = 19.45;
    
  else if(note.equals("E"))
    freq = 20.6;

  else if(note.equals("F"))
    freq = 21.83;

  else if(note.equals("F#"))
     freq = 23.12;

  else if(note.equals("G"))
      freq = 24.50;

  else if(note.equals("G#"))
      freq = 25.96;

  else if(note.equals("A"))
      freq = 27.50;
  else if(note.equals("Bb"))
      freq = 29.14;

  else if(note.equals("B"))
      freq = 30.87;

  else if(note.equals("Z"))
     { freq = 100000;
      octave = 10;
     }

  else if(note.equals("Ab"))
  {
      freq = 25.96;
      //octave--;
  }

  else if(note.equals("Gb"))
    freq = 23.12;
  

  else 
    freq = 0;
  
      
  freq = freq * (pow(2, octave));

  Serial.print(freq);
  Serial.println("1");

  if(part == 1)
    tone1.play(freq, (tempo * duration));
  else
    tone2.play(freq, (tempo * duration)); 
    }
 */

  

    
  


  




