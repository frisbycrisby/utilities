
//// Keyboard Header File...

int val = 0;
int key_delay = 80;
int array_counter = 4; 
char * keyboard_layout [4][4];

void pin_mode_setting(int pins[4][2]){
     // State is 0 --> Input. 
     // State is 1 --> Ouput.
     
     for (int count = 0; count < array_counter ; count++)  {
         if(pins[count][1]) {
           pinMode(pins[count][0], OUTPUT);        
         }else{
           pinMode(pins[count][0], INPUT);
         }   
     }
}

void digital_write_mode_setting(int pins[4][2]){
     // State is 0 --> LOW. 
     // State is 1 --> HIGH.
     
     for (int count = 0; count < array_counter ; count++)  {
         if(pins[count][1]) {
            digitalWrite(pins[count][0], HIGH);        
         }else{
            digitalWrite(pins[count][0], LOW);
         }   
     }
}

//void keyboard_setup(int Col_set[4][2],int Row_set[4][2]){
  //int pin_set[4][2] = {{2,1},{3,1},{4,1},{5,1}};
  //pin_mode_setting(Col_set);
  //int pin_set1[4][2] = {{8,0},{9,0},{10,0},{11,0}};
  //pin_mode_setting(Row_set);
  //keyboard_loop();
//}


//void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  //int pin_set[4][2] = {{2,1},{3,1},{4,1},{5,1}};
  //pin_mode_setting(pin_set);
  //int pin_set1[4][2] = {{8,0},{9,0},{10,0},{11,0}};
  //pin_mode_setting(pin_set1);
  
//}

//void loop() {
//void keyboard_loop(){
  // put your main code here, to run repeatedly:
  //   val = 0;
    // int digital_key1[4][2] =  {{2,1},{3,0},{4,0},{5,0}};
    // digital_write_mode_setting(digital_key1);
    // delay(key_delay);
    // read_row(2); 

    // int digital_key2[4][2] =  {{2,0},{3,1},{4,0},{5,0}};
     //digital_write_mode_setting(digital_key2);
     //delay(key_delay);
     //read_row(3); 

     //int digital_key3[4][2] =  {{2,0},{3,0},{4,1},{5,0}};
     //digital_write_mode_setting(digital_key3);
     //delay(key_delay);
     //read_row(4); 

     //int digital_key4[4][2] =  {{2,0},{3,0},{4,0},{5,1}};
     //digital_write_mode_setting(digital_key4);
     //delay(key_delay);
     //read_row(5);    
//}

int read_row(int col){
   val = 0;
   
   val = digitalRead(11);
   pinMode(11, OUTPUT);
   digitalWrite(11, LOW); 
   pinMode(11, INPUT);
   
   if(col == 2 && val == 1)
   {
      Serial.print("A");
      return 0;  
   }
   if(col == 3 && val == 1)
   {
      Serial.print("3");
      return 0;  
   }
   if(col == 4 && val == 1)
   {
      Serial.print("2");
      return 0;  
   }
   if(col == 5 && val == 1)
   {
      Serial.print("1");
      return 0;  
   }
   //Serial.print(col);
   //Serial.print(val);   

   //////
   val = digitalRead(10);
   pinMode(10, OUTPUT);
   digitalWrite(10, LOW);    
   pinMode(10, INPUT);
      
   if(col == 2 && val == 1)
   {
      Serial.print("B");
      return 0;  
   }
   if(col == 3 && val == 1)
   {
      Serial.print("6");
      return 0;  
   }
   if(col == 4 && val == 1)
   {
      Serial.print("5");
      return 0;  
   }
   if(col == 5 && val == 1)
   {
      Serial.print("4");
      return 0;  
   }

   val = digitalRead(9);
      pinMode(9, OUTPUT);
   digitalWrite(9, LOW); 
   //Serial.print("Port 9 :- ");
   //Serial.println(val);
   pinMode(9, INPUT);
    
   if(col == 2 && val == 1)
   {
      Serial.print("C");
      return 0;
   }
   if(col == 3 && val == 1)
   {
      Serial.print("9");
      return 0; 
   }
   if(col == 4 && val == 1)
   {
      Serial.print("8");
      return 0; 
   }
   if(col == 5 && val == 1)
   {
      Serial.print("7");
      return 0;  
   }


   val = digitalRead(8);
      pinMode(8, OUTPUT);
   digitalWrite(8, LOW); 
   //Serial.print("Port 8 :- ");
   //Serial.println(val);
   pinMode(8, INPUT);
    
   
   if(col == 2 && val == 1)
   {
      Serial.print("D");
      return 0;   
   }
   if(col == 3 && val == 1)
   {
      Serial.print("#");
      return 0; 
   }
   if(col == 4 && val == 1)
   {
      Serial.print("0");
      return 0; 
   }
   if(col == 5 && val == 1)
   {
      Serial.print("*");
      return 0; 
   }


   val = 0; 
}

void keyboard_loop(){
  // put your main code here, to run repeatedly:
     val = 0;
     int digital_key1[4][2] =  {{2,1},{3,0},{4,0},{5,0}};
     digital_write_mode_setting(digital_key1);
     delay(key_delay);
     read_row(2); 

     int digital_key2[4][2] =  {{2,0},{3,1},{4,0},{5,0}};
     digital_write_mode_setting(digital_key2);
     delay(key_delay);
     read_row(3); 

     int digital_key3[4][2] =  {{2,0},{3,0},{4,1},{5,0}};
     digital_write_mode_setting(digital_key3);
     delay(key_delay);
     read_row(4); 

     int digital_key4[4][2] =  {{2,0},{3,0},{4,0},{5,1}};
     digital_write_mode_setting(digital_key4);
     delay(key_delay);
     read_row(5);    
}

void keyboard_setup(int Col_set[4][2],int Row_set[4][2]){
  //int pin_set[4][2] = {{2,1},{3,1},{4,1},{5,1}};
  pin_mode_setting(Col_set);
  //int pin_set1[4][2] = {{8,0},{9,0},{10,0},{11,0}};
  pin_mode_setting(Row_set);
  keyboard_loop();
}
