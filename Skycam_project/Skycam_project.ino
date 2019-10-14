/*
 * Copyright 2019 Zakaria Madaoui. All rights reserved.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

int pin[17];
int t = 16 ;

void setup() {
 
for(int i = 0;i<=16;i++){
  pin[i]=i+21;}
  
for(int i = 0;i<=16;i++){
  pinMode(pin[i],OUTPUT);}

  
//--------------- just for debug -------------------
  Serial.begin(9600);

  for(int i =0; i<=16;i++){Serial.println(pin[i]);}
//--------------------------------------------------
}

void loop() {

//-------------camera in position 1-----------------
if(Readx()>900 && Ready() >900){
  while(Readx()>900 && Ready() >900){
             qStep(t,1,8,12,16);
             qStep(t,2,7,11,15);
             qStep(t,3,6,10,14);
             qStep(t,4,5,9,13);}
Stop();}


//------------camera in position 2------------------


else if(Readx()>900 && Ready()<10){
  while(Readx()>900 && Ready()<10){
                  qStep(t,4,5,12,16);
                  qStep(t,3,6,11,15);
                  qStep(t,2,7,10,14);
                  qStep(t,1,8,9,13);}
Stop();
}


//------------camera in position 3------------------


else if(Readx()<10 && Ready()<10){
  while(Readx()<10 && Ready()<10){
                  qStep(t,4,8,9,16);
                  qStep(t,3,7,10,15);
                  qStep(t,2,6,11,14);
                  qStep(t,1,5,12,13);}
Stop();}


//------------camera in position 4------------------


else if(Readx()<10 && Ready()>900){
  while(Readx()<10 && Ready()>900){
                  qStep(t,4,8,12,13);
                  qStep(t,3,7,11,14);
                  qStep(t,2,6,10,15);
                  qStep(t,1,5,9,16);}
Stop();}


//------------camera in position 5------------------


else if(Readx()>900){
  while(Readx()>900){
                  qStep(t,1,5,12,16);
                  qStep(t,2,6,11,15);
                  qStep(t,3,7,10,14);
                  qStep(t,4,8,9,13);}
Stop();}


//------------camera in position 6------------------


else if(Ready()<10){
  while(Ready()<10){
                  qStep(t,4,5,9,16);
                  qStep(t,3,6,10,15);
                  qStep(t,2,7,11,14);
                  qStep(t,1,8,12,13);}
Stop();}


//------------camera in position 7------------------


else if(Readx()<10){
  while(Readx()<10){
                  qStep(t,4,8,9,13);
                  qStep(t,3,7,10,14);
                  qStep(t,2,6,11,15);
                  qStep(t,1,5,12,16);}
Stop();}


//------------camera in position 8------------------


else if(Ready() >900){
  while(Ready() >900){
                  qStep(t,1,8,12,13);
                  qStep(t,2,7,11,14);
                  qStep(t,3,6,10,15);
                  qStep(t,4,5,9,16);}
Stop();}


//------------------- Camera UP ---------------------


else if(Readz()<10){
  while(Readz()<10){
                  qStep(t,1,5,9,13);
                  qStep(t,2,6,10,14);
                  qStep(t,3,7,11,15);
                  qStep(t,4,8,12,16);}
Stop();}


//----------------- Camera DOWN ---------------------


else if(Readz()>900){
  while(Readz()>900){
                  qStep(t,4,8,12,16);
                  qStep(t,3,7,11,15);
                  qStep(t,2,6,10,14);
                  qStep(t,1,5,9,13);}
Stop();}
//---------------- None of the above ----------------

else {Stop();}

//---------------------------------------------------


}

void qStep(int x,int a,int b,int c,int d){
 digitalWrite(pin[a],HIGH);
 digitalWrite(pin[b],HIGH);
 digitalWrite(pin[c],HIGH);
 digitalWrite(pin[d],HIGH);
 delay(x);
 
 digitalWrite(pin[a],LOW);
 digitalWrite(pin[b],LOW);
 digitalWrite(pin[c],LOW);
 digitalWrite(pin[d],LOW);}

 
void Stop(){
 for(int i=1 ; i<= 16;i++){
 digitalWrite(pin[i],LOW); 
}
}

int Readx(){
return analogRead(1); }

int Ready(){
return analogRead(2); }

int Readz(){
return analogRead(3); }
