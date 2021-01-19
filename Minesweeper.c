#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<stdbool.h>
int N ,top=0 , mines = 0 ,temp_mines = 0,count;
int mat[30][30] , bool_mat[30][30];
int min,sec;

struct track
{
    int row;
    int col;
}stack[100];
void decorate(int N,char ch)
{
	int i;
	for(i = 0 ; i < N ; i++ )
	{
		printf("%c",ch);
	}
}
void make_bomb_visible()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(mat[i][j]==-1)
                bool_mat[i][j] = 1;
        }
    }
}
void recurse_open(int r,int c)
{
    top++;
    stack[0].row = r;
    stack[0].col = c;
    for(int i=0;i<top;i++)
    {

       int r = stack[i].row;
        int c = stack[i].col;

        if(mat[r-1][c-1]!=-1 && bool_mat[r-1][c-1]!=2 && r-1>=0 && c-1>=0)
        {
            bool_mat[r-1][c-1] = 1;
            if(mat[r-1][c-1]==0)
            {
                stack[top].row = r-1;
                stack[top].col = c-1;
                top++;
            }
        }
        if(mat[r-1][c]!=-1 && bool_mat[r-1][c]!=2 && r-1>=0)
        {
            bool_mat[r-1][c] = 1;
            if(mat[r-1][c]==0)
            {
                stack[top].row = r-1;
                stack[top].col = c;
                top++;
            }
        }
        if(mat[r-1][c+1]!=-1 && bool_mat[r-1][c+1]!=2 && r-1>=0 && c+1<N)
        {
            bool_mat[r-1][c+1] = 1;
            if(mat[r-1][c+1]==0)
            {
                stack[top].row = r-1;
                stack[top].col = c+1;
                top++;
            }
        }
        if(mat[r][c-1]!=-1 && bool_mat[r][c-1]!=2 && c-1>=0)
        {
            bool_mat[r][c-1] = 1;
            if(mat[r][c-1]==0)
            {
                stack[top].row = r;
                stack[top].col = c-1;
                top++;
            }
        }
        if(mat[r][c+1]!=-1 && bool_mat[r][c+1]!=2 && c+1<N)
        {
            bool_mat[r][c+1] = 1;
            if(mat[r][c+1]==0)
            {
                stack[top].row = r;
                stack[top].col = c+1;
                top++;
            }
        }
        if(mat[r+1][c-1]!=-1 && bool_mat[r+1][c-1]!=2 && r+1<N && c-1>=0)
        {
            bool_mat[r+1][c-1] = 1;
            if(mat[r+1][c-1]==0)
            {
                stack[top].row = r+1;
                stack[top].col = c-1;
                top++;
            }
        }
        if(mat[r+1][c]!=-1 && bool_mat[r+1][c]!=2 && r+1<N)
        {
            bool_mat[r+1][c] = 1;
            if(mat[r+1][c]==0)
            {
                stack[top].row = r+1;
                stack[top].col = c;
                top++;
            }
        }
        if(mat[r+1][c+1]!=-1 && bool_mat[r+1][c+1]!=2 && r+1<N && c+1<N)
        {
            bool_mat[r+1][c+1] = 1;
            if(mat[r+1][c+1]==0)
            {
                stack[top].row = r+1;
                stack[top].col = c+1;
                top++;
            }
        }
    }
}
void print_board(int N)
{

    decorate(1,'\n');
    decorate(10,'\t');
    decorate(21,'*');
    printf(" MINE-SWEEPER ");
    decorate(21,'*');
    decorate(2,'\n');
    decorate(7,'\t');
    printf("MINES REMAINING : %d ",mines);
    decorate(3,'\n');
    if(N!=24)
    {
        int space = N==8 ? 8 : 3;
        decorate(space,'\t');
        for(int i=0;i<N;i++)
        {
            printf("     %02d   ",i+1);
        }

        printf("\n\n");
        decorate(space,'\t');
        for(int i=0;i<N;i++)
        {
            printf("  ____ ___");
        }
        decorate(2,'\n');
        for(int i = 0; i < N; i++)
        {
            decorate(space-1,'\t');
            printf("   %02d   ",i+1);
            printf(" |  ");
            for(int j = 0; j < N; j++)
            {
                if(bool_mat[i][j] == 1&&mat[i][j]!=-1)
                    printf("  %d    |  ",mat[i][j]);
                else if(bool_mat[i][j] == 1 && mat[i][j] == -1)
                    printf("  *    |  ");
                else if(bool_mat[i][j] == 2)
                    printf("  F    |  ");
                else
                    printf("       |  ");

            }


            printf("\n");
            decorate(space,'\t');
            for(int j = 0; j <=N; j++)
            {
                printf(" |        ");
            }

            printf("\n");
            decorate(space,'\t');

            for(int j = 0; j < N; j++)
            {
            printf("  ____ ___");
            }

            printf("\n\n");
        }
    }
    else
    {
        decorate(4,'\t');
        for(int i=0;i<N;i++)
        {
            printf("  %02d   ",i+1);
        }
        printf("\n\n");
        for(int i=0;i<N;i++)
        {
            decorate(3,'\t');
            printf("  %02d  ",i+1);
            for(int j=0;j<N;j++)
            {
                if(bool_mat[i][j]== 1&&mat[i][j]!=-1)
                    printf("  %d ",mat[i][j]);
                else if(bool_mat[i][j]==1&&mat[i][j]==-1)
                    printf("   * ");
                else if(bool_mat[i][j] == 2)
                    printf("  F ");
                else
                    printf("    -  ");
            }
            printf("\n\n");
        }

    }
}
void result ()              /* Display Result screen */
{
	system("cls");
	int i , j;
	decorate(12,'\n');

	for(i = 0 ; i <= 10; i++)
	{
		printf("\t\t\t\t\t\t\t\t");
		if(i !=0 && i !=10)
		{
			printf("*");
		}
		for(j = 0; j < 5; j++)
		{
			if(i == 2)
			{
				printf("\t\t\t\t\t!!! YOU WON THE GAME !!!\t\t\t\t     ")	;
				break;
			}
			else if(i == 5)
			{
				printf("           Time Taken  : %02d Min %02d Sec\t\t\t            Mines discoverd : %02d\t    ",min,sec,count);
				if(mines < 100)
				{
					printf(" ");
				}
				break;
			}
			else if(i == 0 || i == 10)
			{
				if(j == 0)
				{
					printf(" ");
				}
				printf("* * * * * * * * * * ");
			}
			else
			{
				printf("                    ");
			}
		}
		printf("*\n");
	}
}
void result_fail()
{
    system("cls");
	int i , j;
	decorate(12,'\n');

	for(i = 0 ; i <= 10; i++)
	{
		printf("\t\t\t\t\t\t\t\t");
		if(i !=0 && i !=10)
		{
			printf("*");
		}
		for(j = 0; j < 5; j++)
		{
			if(i == 5)
			{
				printf("\t\t\t\t\t!!! YOU LOST THE GAME :( !!!\t\t\t\t     ")	;
				break;
			}
			else if(i == 0 || i == 10)
			{
				if(j == 0)
				{
					printf(" ");
				}
				printf("* * * * * * * * * * ");
			}
			else
			{
				printf("                    ");
			}
		}
		printf("*\n");
	}
}
void create_mines(int N)
{
    int bomb = ((N==8) ? 10 : ((N==16) ? 40 : 99));

    while(bomb)
    {
        int row,col;
        do{
         row = N - (rand()%(N-1)) -1;
         col = rand()%(N-1);
        }while(mat[row][col]==-1);
        if(mat[row][col] != -1){
            mat[row][col] = -1;
            bomb--;
        }

        if(mat[row][col+1]!=-1)
            mat[row][col+1]+=1;

        if(mat[row+1][col]!=-1)
            mat[row+1][col]+=1;

        if(mat[row+1][col+1]!=-1)
            mat[row+1][col+1]+=1;

        if(mat[row][col-1]!=-1)
            mat[row][col-1]+=1;

        if(mat[row-1][col]!=-1)
            mat[row-1][col]+=1;

        if(mat[row-1][col-1]!=-1)
            mat[row-1][col-1]+=1;

        if(mat[row-1][col+1]!=-1)
            mat[row-1][col+1]+=1;

        if(mat[row+1][col-1]!=-1)
            mat[row+1][col-1]+=1;
    }


}

bool check_board(int choice,int row,int col)
{
    if(choice == 1)
    {
        if(mat[row][col]==-1)
        {
            make_bomb_visible();
            return false;
        }
        if(mat[row][col]==0)
        {
            recurse_open(row,col);
            return true;
        }
        if(mat[row][col]>0)
        {
            bool_mat[row][col] = 1;
            return true;
        }

    }
    if(choice == 2)
    {
        bool_mat[row][col] = 2;
        mines-=1;
        if(mat[row][col]==-1)
            temp_mines-=1;
        return true;
    }
    if(choice == 3)
    {
        bool_mat[row][col] = 0;
        return true;
    }
}
void main()
{
    srand(time(0));
    decorate(3,'\n');
    decorate(8,'\t');
    decorate(25,'*');
    printf(" WELCOME TO MINE_SWEEPER GAME ");
    decorate(25,'*');
    decorate(3,'\n');
    decorate(6,'\t');
    printf(" CHOOSE THE DIFFICULTY :\n\n");
    decorate(9,'\t');
    printf(" 1. Easy   - 10  Mines\n\n");
    decorate(9,'\t');
    printf(" 2. Medium - 40  Mines\n\n");
    decorate(9,'\t');
    printf(" 3. Hard   - 99  Mines\n\n");

    scanf("%d",&N);
    N*=8;
    int row,col;
    memset(mat,0,sizeof(mat));
    memset(bool_mat,0,sizeof(bool_mat));

    create_mines(N);

    int choice = 1;
    mines = ((N==8) ? 10 : ((N==16) ? 40 : 99));
    temp_mines = ((N==8) ? 10 : ((N==16) ? 40 : 99));
    count = mines;
    time_t seconds;
	seconds = time(NULL);
	decorate(5,'\n');
    while(1)
    {
        system("cls");
        printf("\n\n");
        print_board(N);
        decorate(4,'\t');
        printf(" Enter Row Col( Eg: 2 3  ) : ");
        int flag = 1;

        do
        {
            scanf("%d %d",&row,&col);
            if(row>N||col>N)
            {
                decorate(4,'\t');
                printf(" Enter Row Col (in range %d X %d) :",N,N);
                flag = 1;
            }
            else
            flag = 0;
        }while(flag);

        row-=1;col-=1;
        printf("\n\n");
        decorate(5,'\t');
        printf(" Press 1 to open the block \n\n");
        decorate(5,'\t');
        if(bool_mat[row][col]==2)
            printf(" Press 3 to Unflag the block");
        else
            printf(" Press 2 to Flag the block");
        scanf("%d",&choice);
        if(check_board(choice,row,col)==false)
        {
            system("cls");
            print_board(N);
            decorate(10,'\t');
            printf("OHHH NO YOU STEP INTO THE BOMB\n\n\n\n");
            usleep(3000000);
            result_fail();
            break;
        }
        if(temp_mines==0)
        {
            seconds -=time(NULL);
			seconds*=-1;
			min = seconds/60;
			sec = seconds %60;
            result();
            printf("\n\n\\n\n\n");
            break;
        }
    }
}
