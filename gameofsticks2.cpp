#include<bits/stdc++.h>
using namespace std;
int result=0;
int minmax(int n,int max){
	cout<<"n,max:"<<n<<max<<endl;
	int state,i=0;
	if(max==1){
        state=0;
		if(n==1) return 0;
		if(n==2) return 1;
		for(i=n-1;i>=n-3&&i>=1;i--){
			state=minmax(i,0);
			if(state==1){
				result=(n-i);
				break;
			}
		}
		return state;
	}
	else {
		state =1;
		if(n==1) return 1;
		if(n==2) return 0;
		for(i=n-1;i>=n-3&&i>=1;i--){
			state=minmax(i,1);
			if(state==0){
				break;
			}
		}
		return state;
	}
}
int main(){
	srand(time(0));
	int c=0,mode=0;
	do{
		cout<<"		  Welcome to game of sticks.\nselect the mode from the following:\n1.2 players\n2.single player.\n3.AI vs AI\n";
		cin>>mode;
		int n=0,toss=0,turn=0,v=0;
		cout<<"select number of sticks:";
		cin>>n;
		if(mode==1){
			toss=(rand()%2);
			turn=toss;
			while(1){
				cout<<"Number of sticks left:"<<n<<endl;
				cout<<"player "<<turn+1<<" It's your turn.\nEnter the no.of sticks to pick(from 1 to 3):";
				while(1){
					cin>>v;
					if(v>=1&&v<=3){
						n=(n-v);
						break;
					}
					cout<<"enter a value from 1 to 3:";
				}
				if(n==1){
					if(turn) cout<<"player 2 won the game\n";
					else {
						cout<<"player 1 won the game\n";
					}
					cout<<"press 1 to play again or zero to exit!:";
					cin>>c;
					break;
				}
				if(turn) turn=0;
				else turn=1;
			}
		}
		if(mode==2){
			toss=(rand()%2);
			if(toss) cout<<"you won the toss:)"<<endl;
			else cout<<"AI won the toss!"<<endl;
			turn=toss;
			while(1){
				cout<<"Number of sticks left:"<<n<<endl;
				int v=0;
				if(turn){
					cout<<"select the number of sticks(from 1 to3):";
					while(1){
						cin>>v;
						if(v>=1&&v<=3){
							n=(n-v);
							break;
						}
						cout<<"enter a value from 1 to 3:";
					}
					turn=0;
				}
				else {
					result=0;
					minmax(n,1);
					if(result!=0){
						n=n-result;
						cout<<"AI picked "<<result<<" sticks\n";
					}
					else{
						cout<<"AI picked 1 stick\n";
						n--;
					}
					turn=1;
				}
				if(n==1){
					if(turn) cout<<"You lost!AI won the game\n"<<endl;
					else cout<<"Yay! you won the game:)"<<endl;
					cout<<"press 1 to play again 0 to exit:";
					cin>>c;
					break;
				}
			}
		}
		if(mode==3){
			cout<<"AI VS AI"<<endl;
			toss=(rand()%2);
			turn=toss;
			while(1){
				cout<<"Number of sticks left: "<<n<<endl;
				if(turn==0){
					minmax(n,1);
					n=n-result;
					cout<<"AI"<<turn+1<<"picked "<<result<<" sticks"<<endl;
					turn=1;
				}
				else{
					minmax(n,1);
					n=n-result;
					cout<<"AI"<<turn+1<<"picked "<<result<<" sticks"<<endl;
					turn=0;
				}
				if(n==1){
					if(turn) cout<<"AI"<<turn+1<<" won the game\n";
					else cout<<"AI"<<turn+1<<" won the game\n";
					cout<<"press 1 to play again or zero to exit!:";
					cin>>c;
					break;
				}
			}			
		}
	}while(c!=0);
	return 0;
}
