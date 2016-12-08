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



//global variables declaration
int dx=5, dy=11;//present coordinate of bot
int revdir,w,mindir,mingridpoint,flag,prevdir=3,j;//revese direction,no. of turns,direction to turn,value of grid point to turn,previous direction,loop variable
int arr[2];
uint8_t num_path;
int grid[gridX][gridY] = {
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




void path()
{
  memset(arr,9,sizeof(arr));
    for(int j=0;j<num_path;j++)
    {
    
    }
      //cin>>arr[j];
}
void trialrun()
{


	grid[dx][dy]=i;
		
		arr[0]= arr[0]>arr[1]?arr[1]:arr[0];
		arr[1]=arr[0]>arr[1]?arr[0]:arr[1];
		mindir=0;
		mingridpoint=grid[dx][dy];
		for(int j=0;j<w;j++){
			arr[j]=((arr[j]%8)+(((prevdir%8)-(3%8)+8)%8))%8;
			if(arr[j]==0) arr[j]=8;
		}
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
   Serial.println(dx+"    " +dy);
		
	
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

