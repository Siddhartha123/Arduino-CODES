/**************************************
*FLOOD FILL GREEDY ALGORITHM
*MESHFLARE
*IITBOMBAY-TECHFEST-2K16  
*-------------------------------------------------------------------------------------
*Conventions:
*West-1, Northwest-2 and so on.
*not visited = 1;
*visited = some number other than 1,200,250;
*block = 200;
*boundaries = 250;
*****************************************/

#define gridX	13
#define gridY	15
#define WEST	1                               //For reference only
#define NORTHWEST	2
#define NORTH	3
#define NORTHEAST	4
#define EAST	5
#define SOUTHEAST	6
#define SOUTH	7
#define SOUTHWEST	8
#define end_row 8
#define end_col 3
#define start_row 5
#define start_col 11


//global variables declaration
int dx=5, dy=11;//present coordinate of bot
int revdir,w,way,mindir,mingridpoint,flag,prevdir=3,j;//revese direction,no. of turns,direction to turn,value of grid point to turn,previous direction,loop variable
int arr[2],brr[2];       

grid[][] = {
					                           250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,
					                                     250, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,250,
                                               250, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,250,
                                               250, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,250,
                                               250, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,250,
                                               250, 1 , 1 , 1 , 1,  1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,250,
                                               250, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,250,
                                               250, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,250,
                                               250, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,250,
                                               250, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,250,
                                               250, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,250,
                                               250, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,250, 
                                      250,250,250,250,250,250,250,250,250,250,250,250,250,250,250,
                                        };//initial grid



grid[dx][dy]=i;


void trialrun()
{


	
		
		arr[0]= arr[0]>arr[1]?arr[1]:arr[0];
		arr[1]=arr[0]>arr[1]?arr[0]:arr[1];
		mindir=0;
		mingridpoint=grid[dx][dy];
		for(int j=0;j<w;j++){
      brr[j]=arr[j];
			arr[j]=((arr[j]%8)+(((prevdir%8)-(3%8)+8)%8))%8;
			if(arr[j]==0) arr[j]=8;
		}
		for(int j=0;j<w;j++){
    way=brr[j];
			if(arr[j]==1){
				if(mingridpoint>grid[dx][dy-1]){
					mingridpoint=grid[dx][dy-1];
					mindir=arr[j];
				}
			}
			else if(arr[j]==2){
				if(mingridpoint>grid[dx-1][dy-1]){
					mingridpoint=grid[dx-1][dy-1];
					mindir=arr[j];
				}
			}
			else if(arr[j]==3){
				if(mingridpoint>grid[dx-1][dy]){
					mingridpoint=grid[dx-1][dy];
					mindir=arr[j];
				}
			}
			else if(arr[j]==4){
				if(mingridpoint>grid[dx-1][dy+1]){
					mingridpoint=grid[dx-1][dy+1];
					mindir=arr[j];
				}
			}
			else if(arr[j]==5){
				if(mingridpoint>grid[dx][dy+1]){
					mingridpoint=grid[dx][dy+1];
					mindir=arr[j];
				}
			}
			else if(arr[j]==6){
				if(mingridpoint>grid[dx+1][dy+1]){
					mingridpoint=grid[dx+1][dy+1];
					mindir=arr[j];
				}
			}
			else if(arr[j]==7){
				if(mingridpoint>grid[dx+1][dy]){
					mingridpoint=grid[dx+1][dy];
					mindir=arr[j];
				}
			}
			else if(arr[j]==8){
				if(mingridpoint>grid[dx+1][dy-1]){
					mingridpoint=grid[dx+1][dy-1];
					mindir=arr[j];
				}
			}
		}
		if(mingridpoint==grid[dx][dy] && w!=0){
			if(w==1){
				mindir=arr[0];
				grid[dx][dy]=200;
				switch(mindir){
					case 1:
						dx=dx;
						dy=dy-1;
						break;
					case 2:
						dx=dx-1;
						dy=dy-1;
						break;
					case 3:
						dx=dx-1;
						dy=dy;
						break;
					case 4:
						dx=dx-1;
						dy=dy+1;
						break;
					case 5:
						dx=dx;
						dy=dy+1;
						break;
					case 6:
						dx=dx+1;
						dy=dy+1;
						break;
					case 7:
						dx=dx+1;
						dy=dy;
						break;
					case 8:
						dx=dx+1;
						dy=dy-1;
						break;
				}
				i=grid[dx][dy];
			}
			else if(w==2){
				mingridpoint=200;
				for(int j=0;j<w;j++){
					if(arr[j]==1){
						if(mingridpoint>grid[dx][dy-1]){
							mingridpoint=grid[dx][dy-1];
							mindir=arr[j];
						}
					}
					else if(arr[j]==2){
						if(mingridpoint>grid[dx-1][dy-1]){
							mingridpoint=grid[dx-1][dy-1];
							mindir=arr[j];
						}
					}
					else if(arr[j]==3){
						if(mingridpoint>grid[dx-1][dy]){
							mingridpoint=grid[dx-1][dy];
							mindir=arr[j];
						}
					}
					else if(arr[j]==4){
						if(mingridpoint>grid[dx-1][dy+1]){
							mingridpoint=grid[dx-1][dy+1];
							mindir=arr[j];
						}
					}
					else if(arr[j]==5){
						if(mingridpoint>grid[dx][dy+1]){
							mingridpoint=grid[dx][dy+1];
							mindir=arr[j];
						}
					}
					else if(arr[j]==6){
						if(mingridpoint>grid[dx+1][dy+1]){
							mingridpoint=grid[dx+1][dy+1];
							mindir=arr[j];
						}
					}
					else if(arr[j]==7){
						if(mingridpoint>grid[dx+1][dy]){
							mingridpoint=grid[dx+1][dy];
							mindir=arr[j];
						}
					}
					else if(arr[j]==8){
						if(mingridpoint>grid[dx+1][dy-1]){
							mingridpoint=grid[dx+1][dy-1];
							mindir=arr[j];
						}
					}
				}
				grid[dx][dy]=200;
				switch(mindir){
					case 1:
						dx=dx;
						dy=dy-1;
						break;
					case 2:
						dx=dx-1;
						dy=dy-1;
						break;
					case 3:
						dx=dx-1;
						dy=dy;
						break;
					case 4:
						dx=dx-1;
						dy=dy+1;
						break;
					case 5:
						dx=dx;
						dy=dy+1;
						break;
					case 6:
						dx=dx+1;
						dy=dy+1;
						break;
					case 7:
						dx=dx+1;
						dy=dy;
						break;
					case 8:
						dx=dx+1;
						dy=dy-1;
						break;
				}
				i=grid[dx][dy];
				
			}
		}
		else{
		flag=0;
		if(w==0)
			mindir=0;
		switch(mindir){
			case 0:
				grid[dx][dy]=200;
				flag=1;
				if(prevdir==4)
					revdir=8;
				else
					revdir=(prevdir+4)%8;
				switch(revdir){
					case 1:
						dx=dx;
						dy=dy-1;
						break;
					case 2:
						dx=dx-1;
						dy=dy-1;
						break;
					case 3:
						dx=dx-1;
						dy=dy;
						break;
					case 4:
						dx=dx-1;
						dy=dy+1;
						break;
					case 5:
						dx=dx;
						dy=dy+1;
						break;
					case 6:
						dx=dx+1;
						dy=dy+1;
						break;
					case 7:
						dx=dx+1;
						dy=dy;
						break;
					case 8:
						dx=dx+1;
						dy=dy-1;
						break;
				}
				i=grid[dx][dy];
				break;
			case 1:
				i=i-1;
				grid[dx][dy-1]=i;
				dx=dx;
				dy=dy-1;
				break;
			case 2:
				i=i-1;
				grid[dx-1][dy-1]=i;
				dx=dx-1;
				dy=dy-1;
				break;
			case 3:
				i=i-1;
				grid[dx-1][dy]=i;
				dx=dx-1;
				dy=dy;
				break;
			case 4:
				i=i-1;
				grid[dx-1][dy+1]=i;
				dx=dx-1;
				dy=dy+1;
				break;
			case 5:
				i=i-1;
				grid[dx][dy+1]=i;
				dx=dx;
				dy=dy+1;
				break;
			case 6:
				i=i-1;
				grid[dx+1][dy+1]=i;
				dx=dx+1;
				dy=dy+1;
				break;
			case 7:
				i=i-1;
				grid[dx+1][dy]=i;
				dx=dx+1;
				dy=dy;
				break;
			case 8:
				i=i-1;
				grid[dx+1][dy-1]=i;
				dx=dx+1;
				dy=dy-1;
				break;
				
		}
		if(flag==1)
			mindir=revdir;
		}
		prevdir=mindir;
		showgrid();
		Serial.println();
   Serial.println(dx+"    " +dy+"    "+way);
   if(way==1 || way==2)
   {
    goLeft();
    Front();
   }
   else if(way==3) Front();
   else if(way==4 || way==5)
   {
    goRight();
    Front();
   }
		
	
}


void shortest_path()
{
  int i=start_row,j=start_col;
  int gridpt=100,flag=0;
  while(i!=end_row || j!=end_col)
  {
    //cout<<1<<" ";
    if(grid[i][j-1]==gridpt-1)
    {
      flag++;
      j-=1;
      gridpt=grid[i][j];
    }
    else if(grid[i-1][j-1]==gridpt-1)
    {
      flag++;
      j-=1;i-=1;
      gridpt=grid[i][j];
    }
    else if(grid[i-1][j]==gridpt-1)
    {
      flag++;
      i-=1;
      gridpt=grid[i][j];
    }
    else if(grid[i-1][j+1]==gridpt-1)
    {
      flag++;
      j+=1;i-=1;
      gridpt=grid[i][j];
    }
    else if(grid[i][j+1]==gridpt-1)
    {
      flag++;
      j+=1;
      gridpt=grid[i][j];
    }
    else if(grid[i+1][j+1]==gridpt-1)
    {
      flag++;
      j+=1;i+=1;
      gridpt=grid[i][j];
    }
    else if(grid[i+1][j]==gridpt-1)
    {
      flag++;
      i+=1;
      gridpt=grid[i][j];
    }
    else if(grid[i+1][j-1]==gridpt-1)
    {
      flag++;
      j-=1;i+=1;
      gridpt=grid[i][j];
    }
    if(flag==0)
    {
      //cout<<"csyjehfshsjvjknvjkhvjrhivjjlhiub";
      if(grid[i][j-1]==gridpt+1)
        {
        grid[i][j]=200;
          j-=1;
          gridpt=grid[i][j];
        }
        else if(grid[i-1][j-1]==gridpt+1)
        {
        grid[i][j]=200;
          j-=1;i-=1;
          gridpt=grid[i][j];
        }
        else if(grid[i-1][j]==gridpt+1)
        {
        grid[i][j]=200;
          i-=1;
          gridpt=grid[i][j];
        }
        else if(grid[i-1][j+1]==gridpt+1)
        {
        grid[i][j]=200;
          i-=1;j+=1;
          gridpt=grid[i][j];
        }
        else if(grid[i][j+1]==gridpt+1)
        {
        grid[i][j]=200;
          j+=1;
          gridpt=grid[i][j];
        }
        else if(grid[i+1][j+1]==gridpt+1)
        {
        grid[i][j]=200;
          j+=1;i+=1;
          gridpt=grid[i][j];
        }
        else if(grid[i+1][j]==gridpt+1)
        {
        grid[i][j]=200;
          i+=1;
          gridpt=grid[i][j];
        }
        else if(grid[i+1][j-1]==gridpt+1)
        {
        grid[i][j]=200;
          j-=1;i+=1;
          gridpt=grid[i][j];
        }
    }
    flag=0;
  }
   
}


void showgrid()
{
	int i, j;
        for(i=0;i<gridX;i++)
        {
                for(j=0;j<gridY;j++)
			                  Serial.print( grid[i][j]+"   ");
		            Serial.println("");
        }
}

