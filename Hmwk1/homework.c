/*
****************************************************************************
	Name:	Combinatorial Testing
	Author: Jared Westmoreland
	Class:	CSCE 4444
	Date:	09/06/2018
	Assignment: 1
	
	Note: couldn't clean my program up to it would be more uniformed, but
	in my testings. I was quite successful, *for the most part
****************************************************************************
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//counts the tuples
int countT(int factorial, int level);
//swaps 10 time ex. 0123   3021
void swap(int factorial, int level, int *array3);

int main()
{	 clock_t start, end;
     double cpu_time_used;
	
	start = clock();
	//random
        srand(time(NULL));
        int level=0;
        int factorial=0;

	//prompt
	printf("How many level are needed? ");
	scanf("%d",&level);
	printf("How many factorial are needed? ");
	scanf("%d",&factorial);

	//variables
    int track = 0;
    int number2;
	int count = 1;
    int total = 0;
	int array1 [20000][3];
    int array2 [20000][3];
	int array3 [20000];
    int k = 0; //1
    int i = 0;
    int j = 0;
	int begin = 0;
    int column2 = level;
    int column1 = 0;
    
	
	

	//goes to tuples count
	total = countT(factorial, level);

	//gets the total amount of tuples
	for(i=0; i<total; i++)
	{
		//3 rows, I'm trying to use the 3 column to identify if the row is used
		for(j=0; j<2; j++)
		{
			if(j == 0)	//first column
			{
				array1[i][j] = column1; //gets the updated value
			}
			else if(j == 1)	//second column
			{
				 if(level%2 == 1)
				 {
					if(array1[i][0] < column2 && array1[i][0] < column2)// && array1[i][0]+(i%2) != column2)
                    {
						 array1[i][j] = column2; //gets the updated value
					 }
					 else
					 {
						 j--;
					}
					column2++;	//goes till level * factorial and resets
					}
					else if(level%2 == 0)
					{
                    if(array1[i][0] < column2 && array1[i][0] + begin%2 < column2)// && array1[i][0]+(i%2) != column2)
                    {
                        array1[i][j] = column2; //gets the updated value
                    }
                    else
                    {
						j--;
                    }
                    column2++;      //goes till level * factorial and resets
					begin++;
				}
			}
			for(k=0;k<total;k++)
			{
				if(k <= 1)
				{
					if(column2 == level*factorial  && column1 <= 1)
					{
						column2 = level;
	                                	column1++;
					}
				}
				else if(k>=2)
				{
					if(column2 == level*factorial  && column1 <= ((k-1)*level)+1)
                    {
                       column2 = k * level;
                       column1++;
                    }
				}
			}
			array1[i][2]= 0; //the 3rd column allows me to identify usage
		}
	}
	//goes to swap function
	//swap(factorial, level, array3);

	//provides me with a random number (0,1,2) if using 3^4
	//p1.number1 = rand() % factorial;
	int bigboy = 0;
	int biggerboy = 0;
	//variables
	int comp[level][2];
	int storage2[2000][factorial];
	int storage3[2000][factorial];
	int index = 0;
	
	
	for(i=0;i<level;i++)
	{
		for(j=0;j<factorial;j++)
		{
				storage2[j][i] == 99;
		}
	}

for(biggerboy = 0; biggerboy < 50; biggerboy++){
	//goes to swap function
	
	swap(factorial, level, array3);

	
	//gives me random first number in the 0 array spot
	//p1.number1 = rand() % level;
	//for(i = 0; i< level; i++)
	//{
	//	storage2[i][0] = p1.number1;
	//	//printf("NUMBER%d",p1.number1);
	//}
	
	//https://stackoverflow.com/questions/20332199/find-smallest-numbers-index
	

	//this is an algorithm to find the smallest integer in an 1-D array

for(bigboy = 0; bigboy < factorial; bigboy++)
{
	index = 0;
	int small = array3[0];
	for(i=0; i<factorial; i++)
	{
		if(small > array3[i])
		{
			small = array3[i];
			index = i;
		}
	}
	
	
	for(i=0; i<factorial; i++)
	{
		//printf("ARRAY %d", array3[i]);
	}
//	printf("INDEX%d \n",array3[index]);
	array3[index] = factorial+1; 

	int m = 0;
	int l =0;
	int help[level];
	//Variables
	for(i=0;i<level;i++)
	{
		help[i] = 0;
	}
	for(m = 0; m<level; m++)
	{
			 	
		count = 1; //resets to default
		//This compares the new storage with all the tuples and counts them separately to determine which is better
		for(j=0; j<level; j++)
		{
			storage2[j][index] = index*level+j;
		    //else
			//storage2[j][index+1] = (index+1)*3+j;
			for(i=0;i<factorial;i++)
			{
				printf("%d ",storage2[j][i]);
				for(k=0; k<total; k++)
				{
					for(l=0; l<factorial;l++)
					{
						if(storage2[j][i] == array1[k][0] && storage2[j][i+l] == array1[k][1])
						{
							//printf("[%d][%d] == [%d][%d]\n",storage2[j][i],storage2[j][i+l],array1[k][0],array1[k][1]);
							//this gathers data so I can determine with has the most pairs 
							if(array1[k][2] == 0)
							{
								help[j] = count;
							}					
						}				
					}
				}
			}
			printf("\n");
		}
	}
	//more variables
	int Bindex = 0;
	int large = help[0];
	int sum = 0;
	int jointsum=0;
	int integer =0;
	int recieve[1];
	int number1 = 0;
	
	//for(j=0; j<level;j++)
	//printf("HELP:%d\n",help[j]);
	
	for(i=0; i<level;i++)
	{
		sum = help[i] + sum;
	}
	
	//the same algorithm (smallest) but switched to largest to find the biggest and does so weird stuff like autofill 
	for(i=0; i<level; i++)
	{
		if(large < help[i] && sum > 0)
		{
			large = help[i];
			Bindex = i;
		}
		else if(sum == 0 && bigboy > 0)
		{
			for(l=0;l<factorial;l++)
			{
				for(k=0;k<total;k++)
				{
					if(array1[k][2] == 0)
					{
						recieve[0] = array1[k][0];
						recieve[1] = array1[k][1];
									
						storage2[i][recieve[0]/3] = recieve[0];
						storage2[i][recieve[1]/3] = recieve[1];
									
						break;
					}
				}
		}	}
		else if(large == help[i] && sum > 0)
		{
			number1 = rand()%level;
		}
	}
	//rewrites the storage2 so I can have randomness
	for(j=0; j<level; j++)
	{
		for(i=0;i<factorial;i++)
		{
			storage2[j][i] = storage2[number1][i];
		}
	}
	
	int storage4[2000][factorial];
	
	//basically helps with counting the amount in array1
	for(j=0; j<level; j++)
	{
		for(i=0;i<factorial;i++)
		{		track++;
				storage3[biggerboy][i] = storage2[j][i];
				//if(big bad storage4[2000][factorial]
			for(k=0; k<total; k++)
			{
				for(l=0; l<factorial;l++)
				{
					if(storage2[j][i] == array1[k][0] && storage2[j][i+l] == array1[k][1])
					{
						array1[k][2]=1;
					}
					
				}
			}
			
		}
	}	
	}
	//destroy the program so it can eliminate time wasted, potentially
    int destory = 0; 	
	for(k=0;k<total;k++)
	{
		for(j=0;j<factorial;j++)
		{
			if(array1[k][2] == 1)
				destory++;
		}
	}
	if(destory >= factorial*total)
		biggerboy = 50;		
}				
	printf("\n");
	
    //Display for checked off tuples
		for(i = 0; i<total; i++)
        {
		for(j = 0; j<3; j++)
		{
			printf("%d\t",array1[i][j]);
		}
		printf("\n");
	}

	//https://www.programiz.com/c-programming/c-file-input-output
	FILE *fptr;
	fptr = fopen("program.txt","w");
			
	if(fptr == NULL)
	{
		printf("Error!");   
		exit(1);             
	}

	//Displays storage ***I had problems with my output and limiting the amount outputted
	//So the logic behind it is sound but the output is buggy
	for(j=0; j<15; j++)
	{
		if(storage3[j][2] == 0)
			break;
		for(i=0; i<factorial; i++)
		{
        	fprintf(fptr, "%d ",storage3[j][i] );
		}
		fprintf(fptr,"\n");
	}
	fclose(fptr);
	
	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("%f\n",cpu_time_used);
	
	return 0;
}

//counts the tuples
int countT(int factorial, int level)
{
	//variables
	int j;
	int total;
	int print = 0;

	for(j = factorial; j>1; j--)
	{
		//this is the equation I calculated for 3^4
		total = j*level*level - level*level;
		print = total + print;
	}
	return(print);
}

//swaps variables around within the array
void swap(int factorial, int level, int *array3)
{
	//variables
	int number1;
	int number2;
	int i;
	int j;
	int k;
	int temp=0;

	// 0123
	for(i = 0; i<factorial; i++)
	{
		array3[i]= i;
	}

	// randomizes 10 time so is complete shuffled
	for(i = 0; i<10; i++)
	{
        for(j = 0; j<factorial; j++)
        {
			number1 = rand() % factorial;
			number2 = rand() % factorial;
			while(number1 == number2)
			{
				number2 = rand() % level;
			}
			temp = array3[number1];
			array3[number1] = array3[number2];
			array3[number2] = temp;
		}
	}	
}

