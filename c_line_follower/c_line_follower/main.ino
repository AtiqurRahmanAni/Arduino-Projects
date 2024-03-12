void linefollow()
{
   int error,delspeed;
   float p,d;
   error=readsensor();
   if(error==420)
   {
     if(lastsensor==1)
       wheel(-70,70);
     else if(lastsensor==2)
       wheel(70,-70);
   }

   else
   {
     p=kp*error;
     d=kd*(error-preverror);
     delspeed=p+d;
     wheel(leftbasespeed+delspeed,rightbasespeed-delspeed);
     preverror=error;
     //Serial.println(delspeed);
   }
}
