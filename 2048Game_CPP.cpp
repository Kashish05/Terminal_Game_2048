#include<bits/stdc++.h>
using namespace std;


int currentScore = 0;
int prevScore = 0;
int undo_limit = 0;


class game{
        public :
        stack<vector<vector<int>>> prevGridStack;
        stack<int> prevScoreStack;
        int grid[4][4];

        void startDisplay();
        void initialize();
        void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
        int checkFull();
	int randomIndex(int x);
	void sumUp();
	void sumDown();
	void sumLeft();
	void sumRight();
	void generateNewIndex();
        int calculateMax();
	void instructions();
	int gameEnds();
	void endDisplay();
	void winDisplay();
	void loseDisplay();
	void restart();

    public:
	void playGame();
};


void game :: startDisplay(){
    cout << "\n\n\t\t\t\tWelcome to 2048 Game\n";
    cout << "\nYour Score = " << currentScore << endl<<endl;

    for(int i = 0; i < 4; i++){
        cout << "\t\t|\t";
        for(int j = 0; j < 4; j++){
            cout << grid[i][j] << "\t" << "|" << "\t";
        }
        cout <<"\n\n";
    }
    cout << "\n\n";
    cout << "\tMoves :\t\t\t\t\t\t\t\tr-restart\n\tw - ^ \t\t\t\t\t\t\t\ti-instructions\na - <\ts - v\td - >\t\t\t\t\t\t\tq-quit\n\t\t\t\t\t\t\t\t\tu-undo\n\n";
}

void game :: initialize(){
    for(int i = 0; i < 4; i++){
		for(int j = 0;j < 4; j++){
			grid[i][j]=0;
		}
	}
	int i = randomIndex(4);
	int j = randomIndex(4);
	grid[i][j] = 2;
	i=randomIndex(4);
	j=randomIndex(4);
	grid[i][j] = 2;
	startDisplay();
}


void game :: moveUp(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(!grid[j][i]){
				for(int k = j+1; k < 4; k++){
					if(grid[k][i]){
						grid[j][i] = grid[k][i];
						grid[k][i] = 0;
						break;
					}
				}
			}
		}
	}
}


void game :: moveDown(){
	for(int i = 0; i < 4; i++){
		for(int j = 3; j >= 0; j--){
			if(!grid[j][i]){
				for(int k = j-1; k >= 0; k--){
					if(grid[k][i]){
						grid[j][i] = grid[k][i];
						grid[k][i] = 0;
						break;
					}
				}
            }
        }
    }
}


void game :: moveLeft(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(!grid[i][j]){
				for(int k = j+1; k < 4; k++){
					if(grid[i][k]){
						grid[i][j] = grid[i][k];
						grid[i][k] = 0;
						break;
					}
				}
			}
		}
	}
}


void game :: moveRight(){
	for(int i = 0; i < 4; i++){
		for(int j = 3; j >= 0; j--){
			if(!grid[i][j]){
				for(int k = j-1; k >= 0; k--){
					if(grid[i][k]){
						grid[i][j] = grid[i][k];
						grid[i][k] = 0;
						break;
					}
				}
			}
		}
	}
}


int game :: checkFull(){
	int full=1;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(grid[i][j]==0){
				full=0;
				break;
			}
		}
	}
	return full;
}


int game :: randomIndex(int x){
	int index;
	index = rand()%x + 0;
	return index;
}


void game :: sumUp(){
	for(int i = 0 ; i < 4; i++){
		for(int j = 0; j < 3; j++){
			if(grid[j][i] && grid[j][i] == grid[j+1][i]){
				grid[j][i] = grid[j][i] + grid[j+1][i];
				grid[j+1][i] = 0;
				currentScore += grid[j][i];
				prevScore += grid[j][i];
			}
		}
	}
}


void game :: sumDown(){
	for(int i = 0 ; i < 4; i++){
		for(int j = 3; j > 0; j--){
			if(grid[j][i] && grid[j][i] == grid[j-1][i]){
				grid[j][i] = grid[j][i] + grid[j-1][i];
				grid[j-1][i] = 0;
				currentScore += grid[j][i];
				prevScore += grid[j][i];
			}
		}
	}
}


void game :: sumLeft(){
	for(int i = 0 ; i < 4; i++){
		for(int j = 0; j < 3; j++){
			if(grid[i][j] && grid[i][j] == grid[i][j+1]){
				grid[i][j] = grid[i][j] + grid[i][j+1];
				grid[i][j+1] = 0;
				currentScore += grid[i][j];
				prevScore += grid[i][j];
			}
		}
	}
}


void game :: sumRight(){
	for(int i = 0; i < 4; i++){
		for(int j = 3; j > 0; j--){
			if(grid[i][j] && grid[i][j] == grid[i][j-1]){
				grid[i][j] = grid[i][j] + grid[i][j-1];
				grid[i][j-1] = 0;
				currentScore += grid[i][j];
				prevScore += grid[i][j];
			}
		}
	}
}


void game :: generateNewIndex(){
	int flag = 1;
	if(!checkFull()){
		while(flag){
			int i = randomIndex(4);
			int j = randomIndex(4);
			if(grid[i][j] == 0){
				int y = rand()%10 + 0;
				if(y<8){
					grid[i][j] = 2;
					cout << grid[i][j] << i << j << " ";
				}else{
					grid[i][j] = 4;
				}
				flag = 0;
			}
		}
	}
}


int game :: calculateMax(){
	int i,j;
	int max=0;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if(grid[i][j] > max){
				max = grid[i][j];
			}
		}
	}
	return max;
}


void game :: instructions(){
	cout << "\nHow to Play? \n"<<endl;
	cout << "Moves :\nw-move up/na-move left\nd-move right\ns-move down\n"<<endl;
    cout << "How to Win?"<<endl;
	cout << "When two blocks with same number touch, they value gets added up to become one. \nWhen value in any one block becomes 2048, the player wins!\n"<<endl;
	cout << "Undo Limit : 10\n";
	startDisplay();
}


int game :: gameEnds(){
	int i,j,flag=1;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 3; j++){
			if(grid[i][j] == grid[i][j+1]){
				flag = 0;
				break;
			}
		}
		if(flag == 0){
				break;
		}
	}
	if(flag == 1){
		for(i = 0; i < 3; i++){
			for(j = 0; j < 4; j++){
				if(grid[i][j] == grid[i+1][j]){
					flag = 0;
					break;
				}
			}
			if(flag == 0){
				break;
			}
		}
	}
	return flag;
}


void game :: endDisplay(){
	
	cout<<"\nYour final score is :: "<<currentScore<<endl<<endl;
	cout<<"Bye Bye!!!\n"<<endl;
	exit(0);
}


void game :: winDisplay(){
	char c;
	cout<<"\t\t\tYOU WON!!!\n\n";
	cout<<"You made a perfect 2048 Game\n\n";
	cout<<"Do you wish to continue???\n";
	cout<<"Enter y to continue and n to quit\n\n";
	cin>>c;
	if(c == 'n'){
		endDisplay();
	}
}


void game :: loseDisplay(){
	system("clear");
	cout<<"\t\t\tGAME OVER\n\n";
	cout<<"Your final score is "<<currentScore<<"\n\n";
	cout<<"Better Luck Next Time!!!\n\n";
	exit(0);
}


void game :: restart(){
	char c;
	cout << "\nAre you sure to restart the game??\n\n";
	cout << "enter y to restart and n to continue.\n\n";
	cin >> c;
	if(c == 'y'){
		currentScore = 0;
		prevScore = 0;
		prevGridStack = stack<vector<vector<int>>>();
		prevScoreStack = stack<int>();
		initialize();
	}
}


void game :: playGame(){
    char choice, c;
    initialize();
	cout<<"enter choice: "<<endl;
	cin >> choice;

    while((choice=='w' || choice=='a' || choice=='s' || choice=='d' || choice=='q' || choice=='i' || choice=='u' || choice=='r')){
        if(choice != 'u'){
			vector<vector <int> > copyToStore(4, vector <int>(4));
			
			for(int m = 0;m < 4; m++){
				for(int n = 0; n < 4; n++){
					copyToStore[m][n] = grid[m][n];
				}
			}
			prevGridStack.push(copyToStore);
		}

		switch(choice){

			case 'i':
			        instructions();
			        break;
		
		    case 'r':
			        restart();
			        break;

			case 'q':
			        cout<<"Are you sure you want to quit??\nEnter y to quit and n to continue!\n"<<endl;
			        cin>>c;
			        if(c == 'y' || c == 'Y'){
				    endDisplay();
			        }
			        startDisplay();
			        break;

			case 'w':
			        prevScore = 0;
			        moveUp();
			        sumUp();
			        moveUp();
			        generateNewIndex();
			        system("clear");
			        startDisplay();
			        prevScoreStack.push(prevScore);
			        break;
		
		    case 's':
			        prevScore = 0;
			        moveDown();
			        sumDown();
			        moveDown();
			        generateNewIndex();
			        system("clear");
			        startDisplay();
			        prevScoreStack.push(prevScore);
			        break;
		
		    case 'a':
			        prevScore = 0;
			        moveLeft();
			        sumLeft();
			        moveLeft();
			        generateNewIndex();
			        system("clear");
			        startDisplay();
			        prevScoreStack.push(prevScore);
			        break;
		
		    case 'd':
			        prevScore = 0;
			        moveRight();
			        sumRight();
			        moveRight();
			        generateNewIndex();
			        system("clear");
			        startDisplay();
			        prevScoreStack.push(prevScore);
			        break;

			case 'u':
			if(undo_limit < 10){
				if(!prevGridStack.empty()){
					vector<vector<int> > previousGrid = prevGridStack.top();
					prevGridStack.pop();
					for(int m = 0; m < 4; m++){
						for(int n = 0; n < 4; n++){
							grid[m][n] = previousGrid[m][n];
						}
					}
					
					currentScore -= prevScoreStack.top();
					prevScoreStack.pop();
					undo_limit++;
					system("clear");
					startDisplay();
				}
			
			}
			else{
				system("clear");
				startDisplay();
				cout<<"\n\nYou cannot undo the matrix more than 10 times.\n\nSorry!!!\n"<<endl;
			}		
		}


	    int find_max = calculateMax();
	    if(find_max == 2048){
		    winDisplay();
	    }

		if(checkFull()){
			if(gameEnds()){
				loseDisplay();
			}
		}
		cout<<"enter choice: "<<endl;
		cin>>choice;
		while(choice!='w'  && choice!='s'  && choice!='d'  && choice!='a' && choice!='q' && choice!='i' && choice!='u' && choice!='r'){
			cout<<"\nPlease enter a valid move or choice to continue!"<<endl;
			cin>>choice;
		}
	  }
}


int main(){

game a;
srand(time(NULL));
a.playGame();
return 0;

}