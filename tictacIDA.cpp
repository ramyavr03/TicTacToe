#include <iostream>
#include <stdlib.h>
using namespace std;

void makemove();
int min(int depth, int alpha, int beta);
int max(int depth, int alpha, int beta);
int evaluate();
int check4winner(int depth);
void checkGameOver(int depth);
void getamove();
void setup();
void printboard();
int count = 0;

int b[3][3], maxdepth=0;

int main()
{ setup();
  printboard();
  for (;;)
  {  getamove();
     checkGameOver(0);
     makemove();
     checkGameOver(0);
	 cout << "node count : " << count << endl;
  } 
}

void makemove()
{ int best=-20000,depth=0,score,mi,mj, alpha=-20000, beta=20000;
  for(int x=0; x<9; x++){
	  maxdepth=x;
	  best=-20000, alpha=-20000;
  for (int i=0; i<3; i++)
  { for (int j=0; j<3; j++)
    { if (b[i][j]==0)
      { b[i][j]=1; // make move on board
        score = min(depth+1, alpha, beta);
        if (score > best) { mi=i; mj=j; best=score; if(best>alpha)alpha=best;}
        b[i][j]=0; // undo movep
  } } }
  }
  cout << "my move is " << mi << " " << mj << endl;
  b[mi][mj]=1;
}

int min(int depth, int alpha, int beta)
{ int best=20000,score;
  if (check4winner(depth) != -1){
  count++;
	return (check4winner(depth));
  }
  if (depth >= maxdepth) return (evaluate());
  for (int i=0; i<3; i++)
  { for (int j=0; j<3; j++)
    { if (b[i][j]==0)
      { b[i][j]=2; // make move on board
        score = max(depth+1, alpha, beta);
        if (score < best){ best=score; if(best<beta)beta = best;}
        b[i][j]=0; // undo move
		if(alpha>=beta)
			return best;
  } } 
}
  return(best);
}

int max(int depth, int alpha, int beta)
{ int best=-20000,score;
  if (check4winner(depth) != -1){
  count++;
  return (check4winner(depth));
  }
  if (depth >= maxdepth) return (evaluate());
  for (int i=0; i<3; i++)
  { for (int j=0; j<3; j++)
    { if (b[i][j]==0)
      { b[i][j]=1; // make move on board
        score = min(depth+1, alpha, beta);
        if (score > best) { best=score; if(best>alpha)alpha=best;}
        b[i][j]=0; // undo movep
		if(alpha>=beta)
			return best;
  } } }
  return(best);
}

int evaluate()
{ count++; return 0; }  // stub

int check4winner(int depth)
{ if ((b[0][0]==1)&&(b[0][1]==1)&&(b[0][2]==1)
   || (b[1][0]==1)&&(b[1][1]==1)&&(b[1][2]==1)
   || (b[2][0]==1)&&(b[2][1]==1)&&(b[2][2]==1)
   || (b[0][0]==1)&&(b[1][0]==1)&&(b[2][0]==1)
   || (b[0][1]==1)&&(b[1][1]==1)&&(b[2][1]==1)
   || (b[0][2]==1)&&(b[1][2]==1)&&(b[2][2]==1)
   || (b[0][0]==1)&&(b[1][1]==1)&&(b[2][2]==1)
   || (b[0][2]==1)&&(b[1][1]==1)&&(b[2][0]==1))	return 5000-depth;  // computer wins
   
  if ((b[0][0]==2)&&(b[0][1]==2)&&(b[0][2]==2)
   || (b[1][0]==2)&&(b[1][1]==2)&&(b[1][2]==2)
   || (b[2][0]==2)&&(b[2][1]==2)&&(b[2][2]==2)
   || (b[0][0]==2)&&(b[1][0]==2)&&(b[2][0]==2)
   || (b[0][1]==2)&&(b[1][1]==2)&&(b[2][1]==2)
   || (b[0][2]==2)&&(b[1][2]==2)&&(b[2][2]==2)
   || (b[0][0]==2)&&(b[1][1]==2)&&(b[2][2]==2)
   || (b[0][2]==2)&&(b[1][1]==2)&&(b[2][0]==2))
	   return -5000+depth; // human wins
  for (int i=0; i<3; i++) for (int j=0; j<3; j++) {if (b[i][j]==0) return -1;}
  return 0; // draw
}

void printboard()
{ cout << endl;
  cout << b[0][0] << " " << b[0][1] << " " << b[0][2] << endl;
  cout << b[1][0] << " " << b[1][1] << " " << b[1][2] << endl;
  cout << b[2][0] << " " << b[2][1] << " " << b[2][2] << endl;
}

void setup()
{ for (int i=0; i<3; i++) for (int j=0; j<3; j++) { b[i][j]=0; } }

void getamove()
{ int i,j;
  cout << "Enter your move:  ";
  cin >> i >> j;
  b[i][j]=2;
}

void checkGameOver(int depth)
{ printboard();
  if (check4winner(depth) == -5000) { cout << "you win" << endl; exit(0); }
  if (check4winner(depth) ==  5000) { cout << "I win"   << endl; exit(0); }
  if (check4winner(depth) ==  0)    { cout << "draw"    << endl; exit(0); }
}


