#include <iostream>
#include <ctime>
#include <cmath>

#include "Board.h"

using namespace std;

    Board::Board(){
        for(i=0; i<4; i++)
            for(j=0; j<4; j++)
                tiles[j][i] = ' ';
        srand(time(NULL));
        
        for(i=0; i<2; i++){   
            ran1 = rand()%4;
            ran2 = rand()%4;
            if(tiles[ran1][ran2] != ' ')
                i--;
            else tiles[ran1][ran2] = 'A';
        
        }
        displayBoard(tiles);
    }

    void Board::displayBoard(const char tiles[4][4]) const{

        cout << "+---+---+---+---+" << endl;
    
            for(int j=0; j<4; j++){ 
                cout << "|";
                for(int i=0; i<4; i++){
                    cout << " ";
                    if(tiles[i][j] != '*'){
                        cout << tiles[i][j]; 
                    }
                    else {
                        cout << " ";
                    }
                    cout << " ";
                    cout << "|";
            
                }
                cout << endl;
            
                cout << "+---+---+---+---+";
                cout << endl;
        
            }
    }
    
    
    
    
    
    int moveSingleLine(const char line[4], char new_line[4]){
        int pt = 0;
        for(int i=0; i<4; i++){
            new_line[i] = ' ';

            if (line[i] == ' '){
                for(int k=1; i+k<4; k++){
                    if(line[i+k] != ' '){
                        new_line[i] = line[i+k];
                        k = 4;
                        pt += pow(2, int(new_line[i]-64));

                    }
                }
            }
            else {
                for(int k=1; i+k<4; k++){
                    if(line[i+k] == line[i]){
                        new_line[i] = char(int(line[i+k]+1));
                        pt += pow(2, int(new_line[i]-64));
                        k = 4;
                    }
                    else if((line[i+k] != line[i]) && (line[i+k]!= ' '))
                        new_line[i] = line[i];
                        k = 4;
                    
                }
            }    
        }
        return pt;
        
    }
    
int Board::moveBoard(char tiles[4][4], Direction dir) {

    int reward = 0;
    
    
    bool found = false;
    if(dir == UP){
       
        for(int j = 0; j<4; j++){
            for(int i=0; i<4; i++){
                char num1 = tiles[j][i];
                if(num1 != ' ') {
                    for(int k=1; i+k<4; k++){
                        if(tiles[j][i+k] == num1){
                            tiles[j][i+k] = ' ';
                            tiles[j][i] = char(int(num1)+1);
                            reward += pow(2, int(num1)-63);

                            if(i == 0){
                                if(tiles[j][2] != ' '){
                                    i = 2;
                                    num1 = tiles[j][i];
                                    if(num1 == tiles[j][i+1]){
                                        tiles[j][i] = char(int(num1)+1);
                                        tiles[j][i+1] = ' ';
                                        reward += pow(2, int(num1)-63);
                                    
                                    }
                                
                                }
                            
                            }
                        
                        }
                        else if(tiles[j+k][i] != ' '){
                                k = 4;
                        }
                        
                    
                    }
                
                }
                
            
            }   
        
        }
        for(int j=0; j<4; j++){
            for(int i=0; i<4; i++){

                if(tiles[j][i] == ' '){
                    for(int k=1; i+k<4; k++){
                        
                        if(tiles[j][i+k] !=  ' '){
                            //cout << 
                            tiles[j][i] = tiles[j][i+k];
                            tiles[j][i+k] = ' ';
                            
                            k = 4;
                            i --;
                        
                        }
                    
                    }
                
                }
            
            }
        
        }
        

    
    }

    //DOOWN

    if(dir == DOWN){
        for(int j = 0; j<4; j++){
            for(int i=3; i>=0; i--){
                char num1 = tiles[j][i];
                if(num1 != ' ') {

                    for(int k=1; i-k>=0; k++){
                        if(tiles[j][i-k] == num1){
                            tiles[j][i] = char(int(num1)+1);
                            tiles[j][i-k] = ' ';
                            reward += pow(2, int(num1)-63);

                            if(i == 3){
                                if(tiles[j][1] != ' '){
                                    i = 1;
                                    num1 = tiles[j][i];
                                    if(num1 == tiles[j][i-1]){
                                        tiles[j][i] = char(int(num1)+1);
                                        tiles[j][i-1] = ' ';
                                        reward += pow(2, int(num1)-63);
                                    
                                    }
                                
                                }
                            
                            }
                        
                        }
                        else if(tiles[j+k][i] != ' '){
                                k = 4;
                                
                                
                                
                        
                        }
                    
                    }
                
                }
                
            
            }   
        
        }

        for(int j=0; j<4; j++){
            for(int i=3; i>=0; i--){

                if(tiles[j][i] == ' '){
                    for(int k=1; i-k>=0; k++){
                        
                        if(tiles[j][i-k] !=  ' '){
                            //cout << "i: " << i << " j: " << j << endl;
                            //cout << 
                            tiles[j][i] = tiles[j][i-k];
                            tiles[j][i-k] = ' ';
                            
                            k = 4;
                            i ++;
                        
                        }
                    
                    }
                
                }
            
            }
        
        }
        
    

    
    }
    //LEFT

    if(dir == LEFT){
       //cout << tiles[3][2] << endl;
        //cout << tiles[3][3] << endl;
        for(int i = 0; i<4; i++){

            for(int j=0; j<4; j++){
                char num1 = tiles[j][i];

                if(num1 != ' ') {
                    //cout << "i: " << i << " j: " << j << endl;
                    for(int k=1; j+k<4; k++){
                        
                        if(tiles[j+k][i] == num1){
                            //cout << num1 << " " << tiles[j+k][i]<<endl;
                            //cout << "j: " << j << " k: " << k << endl;

                            tiles[j+k][i] = ' ';
                            tiles[j][i] = char(int(num1)+1);
                            reward += pow(2, int(num1)-63);

                            if(j == 0){
                                if(tiles[2][i] != ' '){
                                    j = 2;
                                    char num2 = tiles[j][i];
                                    if(num2 == tiles[j+1][i]){
                                        tiles[j][i] = char(int(num2)+1);
                                        tiles[j+1][i] = ' ';
                                        reward += pow(2, int(num2)-63);
                                    
                                    }
                                
                                }
                            
                            }
                        }
                        else if(tiles[j+k][i] != ' '){
                                k = 4;
                                //j --;
                                
                        
                        }
                        
                    
                    }
                
                }
                
            
            }   
        
        }

        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){

                if(tiles[j][i] == ' '){
                    for(int k=1; j+k<4; k++){
                        if(tiles[j+k][i] !=  ' '){
                            //cout << "i: " << i << " j: " << j << endl;
                            //cout << 
                            tiles[j][i] = tiles[j+k][i];
                            tiles[j+k][i] = ' ';
                            k = 4;
                            j --;
                            
                            //k--;                    //????
                        
                        }
                    
                    }
                
                }
            
            }
        
        }
        
    
    }
    
    if(dir == RIGHT){
        //cout << tiles[3][2] << endl;
        //cout << tiles[3][3] << endl;
        for(int i = 0; i<4; i++){

            for(int j=3; j>=0; j--){
                char num1 = tiles[j][i];

                if(num1 != ' ') {
                    //cout << "i: " << i << " j: " << j << endl;
                    for(int k=1; j-k>=0; k++){
                        
                        if(tiles[j-k][i] == num1){
                            //cout << num1 << " " << tiles[j-k][i]<<endl;
                            //cout << "j: " << j << " k: " << k << endl;

                            tiles[j-k][i] = ' ';
                            tiles[j][i] = char(int(num1)+1);
                            reward += pow(2, int(num1)-63);

                            

                            if(j == 3){
                                if(tiles[1][i] != ' '){
                                    j = 1;
                                    char num2 = tiles[j][i];
                                    if(num2 == tiles[j-1][i]){
                                        tiles[j][i] = char(int(num2)+1);
                                        tiles[j-1][i] = ' ';
                                        reward += pow(2, int(num2)-63);
                                    
                                    }
                                
                                }
                            
                            }
                        
                        }
                        else if(tiles[j-k][i] != ' '){
                                k = 4;
                                //j --;
                                
                        
                        }
                        
                    
                    }
                
                }
                
            
            }   
        
        }

        for(int i=0; i<4; i++){
            for(int j=3; j>=0; j--){

                if(tiles[j][i] == ' '){
                    for(int k=1; j-k>=0; k++){
                        if(tiles[j-k][i] !=  ' '){
                            //cout << "i: " << i << " j: " << j << endl;
                            //cout << 
                            tiles[j][i] = tiles[j-k][i];
                            tiles[j-k][i] = ' ';
                            k = 4;
                            j ++;
                            
                            //k--;                    //????
                        
                        }
                    
                    }
                
                }
            
            }
        
        }
        
    
    }
        
    return reward;

}

bool Board::checkGameOver(char tiles[4][4]) const{
    
	bool space  = false;
	bool conti = false;

	for(int j=0; j<4; j++){
		for(int i=0; i<4; i++){

			if( int(tiles[i][j]) == ' '){
				//cout << "space" << endl;
				space = true;
				conti = true;
				i = 4;
				j = 4;
			}
		}
	}

	if(!space){
		char self = tiles[0][0];

		for(int j=0; j<4; j++){
			for(int i=0; i<4; i++){
				self = tiles[i][j];

				if((self == tiles[i+1][j]) && (i+1 < 4)){
					conti = true;
					i = 4;
					j = 4;
				}
				else if((self == tiles[i-1][j]) && (i-1 >= 0)){
					conti = true;
					i = 4;
					j = 4;
				}
				else if((self == tiles[i][j+1]) && (j+1 < 4)){
					conti = true;
					i = 4;
					j = 4;
				}
				else if((self == tiles[i][j-1]) && (j-1 >= 0)){
					conti = true;
					i = 4; 
					j = 4;
				}
			}
		}
	}
	
	if(conti) return false;
	else return true;

}