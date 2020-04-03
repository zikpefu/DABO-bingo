/*
Zachary Ikpefua
Project 1
ECE 222

Purpose: Create a bingo game with the greatest footbal
			coach ever using unique random numbers

Assumptions:	I estimated that this project would only take a few hours
					However this project took much longer (2 days)


Known Bugs:	I could not get the random number generator when calling for DABO to 
				not repeat the same number
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void createBoard(int [],int [],int[],int[]);
int randChoice();
void redrawBoard(int [], int [] ,int [], int [], int);
int DABOchecker(int [],int [],int [],int [],int,int);

int main(void){
	//Seed generator
	time_t t;
	srand((unsigned)time(&t));

	const int COL = 4;

	int D_Col[COL];
	int A_Col[COL];
	int B_Col[COL];
	int O_Col[COL];
	int dint = 0;
	int aint = 0;
	int bint = 0;
	int oint = 0;

	int wloop1 = 0;
	int wloop2 = 0;
	int wloop3 = 0;

	int quitGame = 0;
	int chosen = 0;
	int DABOcounter = 0;
	int programRestart = 0;
	int wasonBoard = 0;
	int gameTracker = 0;
	int w = 0;

	char userAnswer;
	char c;
	

	//While loop restarts program if the user types 'Y'
	while(programRestart == 0){
		wloop1 = 0;
		gameTracker++;

		//Generate random unique numbers for each column
		//For this method it replaces the top two numbers as the same
		//then replaces one of the two with a unique random number

		int i = 0, k, m;
		int numArray[20];

		for(i = 1; i < 21; i++) 
			numArray[i-1] = i;
		k = 21;

		for(dint = 3; dint >= 0; dint--){
			k--;
			m = rand()%k;
			D_Col[dint]= (numArray[m]);

			while(m < k - 1){
				numArray[m] = numArray[m+1];
				m++;
			}
		}

		for(i = 1; i < 21; i++) 
			numArray[i-1] = i;
		k = 21;

		for(aint = 3; aint >= 0; aint--){
			k--;
			m = rand()%k;
			A_Col[aint]= (numArray[m] + 20);
			while(m < k - 1){
				numArray[m] = numArray[m+1];
				m++;
			}
		}

		for(i = 1; i < 21; i++) 
			numArray[i-1] = i;
		k = 21;

		for(bint = 3; bint >= 0; bint--){
			k--;
			m = rand()%k;
			B_Col[bint]= (numArray[m] + 40);
			while(m < k - 1){
				numArray[m] = numArray[m+1];
				m++;
			}
		}

		for(i = 1; i < 21; i++) 
			numArray[i-1] = i;

		k = 21;

		for(oint = 3; oint >= 0; oint--){
			k--;
			m = rand()%k;
			O_Col[oint]= (numArray[m] + 60);
			while(m < k - 1){
				numArray[m] = numArray[m+1];
				m++;
			}
		}

	//Set value of 'Free' space to a win condition

		B_Col[2] = 81;

		createBoard(D_Col,A_Col,B_Col,O_Col);

	//User program begins

	//wloop1 will redraw random numbers until DABO is reached
		while(wloop1 == 0){
			wloop2 = 0;
			wloop3 = 0;
	//wloop2 checks the user input to see if it matches either an enter or quit
			while(wloop2 == 0){
				fprintf(stdout,"Press [Enter] to generate a square or press [q] to quit.\n");
				fgets(&c,100,stdin);

				 if(c == 113 || c == 10){
					wloop2 = 1;
				}
	
				else{
		
					fprintf(stdout,"\nInvalid choice: Please press either [Enter] to keep going or [q] to quit:\n");
				}
			}
			if(c == 10){ //Enter cooresponds to 10 in ACii
				chosen = randChoice();
				DABOcounter++;

				if(chosen < 21 && chosen > 0){
					fprintf(stdout,"%d: D - %d\n",DABOcounter,chosen);
					for(w = 0; w < 4;w++){
	
						if(chosen == D_Col[w]){ 
						//Because the numbers are unique, this if statment will tell if the number was on the board or not (same for all other columns)
							wasonBoard++;
						}
					}
					if(wasonBoard == 1){
						fprintf(stdout,"The number randomly picked WAS on the board!\n");
						redrawBoard(D_Col,A_Col,B_Col,O_Col,chosen);
					}
					else if (wasonBoard != 1){
						fprintf(stdout,"The number randomly picked WAS NOT on the board!\n");
					}
					wasonBoard = 0;
				}	
			
				if(chosen < 41 && chosen > 20){
					fprintf(stdout,"%d: A - %d\n",DABOcounter,chosen);

					for(w = 0; w < 4;w++){
						if(chosen == A_Col[w]){
							wasonBoard++;
						}
					}
					if(wasonBoard == 1){
						fprintf(stdout,"The number randomly picked WAS on the board!\n");
						redrawBoard(D_Col,A_Col,B_Col,O_Col,chosen);
					}
					else if(wasonBoard != 1){
						fprintf(stdout,"The number randomly picked WAS NOT on the board!\n");
					}
					wasonBoard = 0;
				}
			
				if(chosen < 61 && chosen > 40){
					fprintf(stdout,"%d: B - %d\n",DABOcounter,chosen);
					for(w= 0; w< 4;w++){
						if(chosen == B_Col[w]){
							wasonBoard++;
						}
					}
					if(wasonBoard == 1){
						fprintf(stdout,"The number randomly picked WAS on the board!\n");
						redrawBoard(D_Col,A_Col,B_Col,O_Col,chosen);
					}
					else if(wasonBoard != 1){
						fprintf(stdout,"The number randomly picked WAS NOT on the board!\n");
					}
					wasonBoard = 0;
				}
		
		
				if(chosen < 81 && chosen > 60){
					fprintf(stdout,"%d: O - %d\n",DABOcounter,chosen);
					for(w= 0; w< 4;w++){
						if(chosen == O_Col[w]){
							wasonBoard++;
						}
					}
					if(wasonBoard == 1){
						fprintf(stdout,"The number randomly picked WAS on the board!\n");
						redrawBoard(D_Col,A_Col,B_Col,O_Col,chosen);
		  			}
					else if(wasonBoard != 1){
						fprintf(stdout,"The number randomly picked WAS NOT on the board!\n");
					}
					wasonBoard = 0;
				}
		}	


		else if (c == 113){ //q corresponds to 113 in ASCii
			wloop1 = 1;
			programRestart = 1;
			quitGame = 1;
		}




		if(wloop1 != 1){
		//Exit conditon due by win in DABO game
			wloop1 = DABOchecker(D_Col,A_Col,B_Col,O_Col,gameTracker,DABOcounter);
		}
	}

		if(quitGame != 1){ 
			//This if statment is to prevent the program from asking the user to play again if they quit early
			while(wloop3 == 0){

				fprintf(stdout,"Would you like to play again? Type [Y] for Yes; [N] for No\n");
				fgets(&userAnswer,100,stdin);
				if(userAnswer == 89){
					programRestart = 0;
					wloop3 = 1;
					DABOcounter = 0;

				}
				else if(userAnswer == 78){
					programRestart = 1;
					fprintf(stdout,"\nThanks for playing!\n%d game(s) of DABO were played.\n\n",gameTracker);
					wloop3 = 1;
				}
				else if(userAnswer != 78 || userAnswer != 89){
					fprintf(stdout,"Invalid Choice: Please enter either [Y] for Yes or [N] for No:\n");
				}
			}
		}		

		if(quitGame == 1){
			fprintf(stdout,"\nThanks for playing!\n%d game(s) of DABO were played.\n\n",gameTracker);
		}	
	
	}
	return 0;
}


/*
FUNCTION:	createBoard
INPUTS:		Each column in DABO game[D_array,A_array,B_array,O_array]
OUTPUTS;		None: is void

PURPOSE:		Function will create a DABO board so that the user can see
				visually what numbers are marked on the board
*/
void createBoard(int array1[],int array2[],int array3[],int array4[]){
	int a = 0;
	char Fspace[5] = "Free";
	const int SIZE = 4;
	char cross = 'X';

	fprintf(stdout,"\n    D \t    A\t    B \t    O\n");
	fprintf(stdout,"---------------------------------\n"); 
	
	for(a = 0; a < SIZE;a++){
		if(a == 2){ //Third Column for free space
			if(array1[a]== 88){
				fprintf(stdout,"|%5c  ",cross);
			}
			else{
				fprintf(stdout,"|%5d  ",array1[a]);
			}
			if(array2[a] == 88){
				fprintf(stdout,"|%5c  ",cross);
			}
			else{
				fprintf(stdout,"|%5d  ",array2[a]);
			}
			if(array3[a] == 88){
				fprintf(stdout,"|%5c  ",cross);
			}
			else{
				fprintf(stdout,"|%5s  ",Fspace);
				 }
			if(array4[a] == 88){
				fprintf(stdout,"|%5c  |\n",cross);
			}
			else{
				fprintf(stdout,"|%5d  |\n",array4[a]);
			}	
		}

	

	else {
		if(array1[a]== 88){
			fprintf(stdout,"|%5c  ",cross);
		}
		else{
			fprintf(stdout,"|%5d  ",array1[a]);
		}
		if(array2[a] == 88){
			fprintf(stdout,"|%5c  ",cross);
		}
		else{
			fprintf(stdout,"|%5d  ",array2[a]);
		}
		if(array3[a] == 88){
			fprintf(stdout,"|%5c  ",cross);
		}
		else{ 
			fprintf(stdout,"|%5d  ",array3[a]);
			}
		if(array4[a] == 88){
			fprintf(stdout,"|%5c  |\n",cross);
		}
		else{
			fprintf(stdout,"|%5d  |\n",array4[a]);
			
		}
	}

	if(a != 3){
		fprintf(stdout,"|-------|-------|-------|-------|\n");
	}

	}
	fprintf(stdout,"---------------------------------\n");
}


/*
FUNCTION:		randChoice
INPUTS:			None
OUTPUTS:			randnum

PURPOSE:			Function randChoice will generate a random number between 1 and 80 and will be fed into 
					variable 'chosen' in main function

*/
int randChoice(){
	int randnum;

	randnum = rand() % 79  + 1;

	return randnum;
}


/*
FUNCTION:		redrawBoard
INPUTS:			Darray,Aarray,Barray,Oarray (DABO columns) and the 'chosen' variable in main()
OUTPUTS:			None: is void

PURPOSE:			To redraw the board with 'X's from the called number 'chosen'.
					After function executes it 'remakes' the new array and uses the
					createBoard function to draw board
*/
void redrawBoard(int Darray[],int Aarray[],int Barray[], int Oarray[],int num){
	int x = 0;
	char cross;
	cross = 88;

	if(num < 21 && num > 0){
		for(x = 0; x < 4;x++){
			if(num == Darray[x]){
			Darray[x] = cross;
			}
		}
	}

		else if(num < 41 && num > 20){
			for(x = 0; x < 4;x++){
				if(num == Aarray[x]){
					Aarray[x] = cross;
				}
			}
		}
		
		else if(num < 61 && num > 40){
			for(x = 0; x < 4;x++){
				if(num == Barray[x]){
					Barray[x] = cross;
				}
			}
		}
		
		else{
			for(x = 0; x < 4;x++){
				if(num == Oarray[x]){
				Oarray[x] = cross;
				}
			}
		}
		

	createBoard(Darray,Aarray,Barray,Oarray);
}
/*
FUNCTION:		DABOchecker
INPUTS:			DABO arrays, game number and number of tries for winning
OUTPUTS:			val, either a 1 or zero so that wloop1 will stop executing
					if game is won

PURPOSE:			To test the array if DABO is won by connecting four corresponding 
					squares and the free space (if needed)
*/
int  DABOchecker(int Darray[],int Aarray[],int Barray[],int Oarray[],int game,int attemps){
	int x = 0;
	int D_ColCheck = 0;
	int A_ColCheck = 0;
	int B_ColCheck = 0;
	int O_ColCheck = 0;
	int val = 0;
	const int WIN = 352;
	const int WIN_FREE = 345;

	for(x = 0; x < 4; x++){
		D_ColCheck += Darray[x];
		A_ColCheck += Aarray[x];
		B_ColCheck += Barray[x];
		O_ColCheck += Oarray[x];
	}

	if(D_ColCheck == WIN || A_ColCheck == WIN || B_ColCheck == WIN_FREE || O_ColCheck == WIN){
		fprintf(stdout,"<<<<<You got a DABO!>>>>>>>\n\nGame %d is complete and it only took %d times to get DABO!\n\n",game,attemps);
		val = 1;
	}

	else if(Darray[3] == 88 && Aarray[2] == 88 && Barray[1] == 88 && Oarray[0] == 88){
			fprintf(stdout,"<<<<<You got a DABO!>>>>>>>\n\nGame %d is complete and it only took %d times to get DABO!\n\n",game,attemps);
			val = 1;
	}

	else if(Darray[0] == 88 && Aarray[1] == 88 &&  Barray[2] == 81 && Oarray[3] == 88){
		fprintf(stdout,"<<<<<You got a DABO!>>>>>>>\n\nGame %d is complete and it only took %d times to get DABO!\n\n",game,attemps);
			val = 1;
	}

	for(x = 0; x < 4; x++){ 
		if(Barray[x] == 81){
			Barray[x] = 88;
		}

		if(Darray[x] == 88 && Aarray[x] == 88 && Barray[x] == 88 && Oarray[x] == 88){
			fprintf(stdout,"<<<<<You got a DABO!>>>>>>>\n\nGame %d is complete and it only took %d times to get DABO!\n\n",game,attemps);
			x = 4;
			val = 1;
		}
	}
	Barray[2] = 81;

return val;
}
