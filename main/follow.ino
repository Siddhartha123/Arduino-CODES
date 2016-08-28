void setValues()
{
  int i;
  cmp="";
  for(i=0;i<9;i++)
  {
    
    if(b[i]==1)
    {
      cmp+="B";
    }
    else
    {
      cmp+="W";
    }
  }
  Serial.println(cmp+" ");
}


void processValues()
{
  
  if(cmp=="BWWWB")
  {
    goFront();
  }
  else if(cmp=="BWBBB"||cmp=="BBBWB")
  {
    goSlow();
  }
  else if(cmp=="BBBBB")
  {
    goReverse();
  }
  else if(cmp=="WWWWB")
  {
    hardLeft();
  }
  else if(cmp=="BWWWW")
  {
    hardRight();
  }
  else if(cmp=="BWWBB")
  {
    goLeft();
  }
  else if(cmp=="BBWWB")
  {
    goRight();
  }
  else if(cmp=="WWWWW")
  {
    goFront();
  }
  else if(cmp=="BBBWW"||cmp=="BBBBW"||cmp=="BBWWW")
  {
    softRight();
  }
  else if(cmp=="WWBBB"||cmp=="WBBBB"||cmp=="WWWBB")
  {
    softLeft();
  }
  else
   halt();
}
