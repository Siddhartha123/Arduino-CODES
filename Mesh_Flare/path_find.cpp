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

using namespace std;
#define gridX	13
#define gridY	15
#define WEST	1
#define NORTHWEST	2
#define NORTH	3
#define NORTHEAST	4
#define EAST	5
#define SOUTHEAST	6
#define SOUTH	7
#define SOUTHWEST	8



//global variables declaration
int dx, dy;
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
                                        };
//Function prototypes
void showgrid();


int main()
{
	//local variables declaration
	int i, j;
	dx = 5;
	dy = 11;
	i=100;
	int revdir,w,mindir,mingridpoint,flag;
	int prevdir=3;
	grid[dx][dy]=i;
	while(true){
		cout<<"Enter no of ways"<<endl;
		cin>>w;
		vector<int>arr(w);
		for(int j=0;j<w;j++){
			cin>>arr[j];
		}
		sort(arr.begin(),arr.end());
		mindir=0;
		cout<<prevdir<<endl;
		mingridpoint=grid[dx][dy];
		for(int j=0;j<w;j++){
			arr[j]=((arr[j]%8)+(((prevdir%8)-(3%8)+8)%8))%8;
			if(arr[j]==0) arr[j]=8;
		}
		for(int j=0;j<w;j++)
			cout<<arr[j]<<" ";
		cout<<endl;
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
				//i=grid[dx][dy];
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
				//i=grid[dx][dy];
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
		cout<<mindir<<endl;
		flag=0;
		if(w==0)
			mindir=0;
		switch(mindir){
			case 0:
				//i=grid[dx][dy];
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

	}



}

void showgrid()
{
	int i, j;
        for(i=0;i<gridX;i++)
        {
                for(j=0;j<gridY;j++)
                {
			       printf("%d\t", grid[i][j]);
                }
		printf("\n");

        }


}
