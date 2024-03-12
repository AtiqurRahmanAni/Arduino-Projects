int readsensor()
{
  int i;
  for(i=0;i<num_sensors;i++)
  {
    if(analogRead(i)>thresholds[i])
      svalues[i]=0;
     else
      svalues[i]=1;

      /*Serial.print(analogRead(i));
      Serial.print(' ');*/
  }

  int error,sums,sumws,linepos;

  sums=svalues[0]+svalues[1]+svalues[2]+svalues[3]+svalues[4]+svalues[5];

  if(sums > 2)
  {
    while(svalues[0] != 1 || svalues[1] != 1)
    {
      
      \\turn left
    }
  }
  sums=svalues[0]+svalues[1]+svalues[2]+svalues[3]+svalues[4]+svalues[5];
  
  if(sums==0)
    return 420;
   sumws=(svalues[0]*10+svalues[1]*20+svalues[2]*30+svalues[3]*40+svalues[4]*50+svalues[5]*60);
   linepos=(sumws/sums);
   error=linepos-35;
   if(svalues[0]==1)
     lastsensor=1;
   else if(svalues[5]==1)
     lastsensor=2;
    return error;
   
}
