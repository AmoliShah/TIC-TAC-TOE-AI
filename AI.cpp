#include<iostream>
#define BOT 1
#define HUM -1
#define DRAW 0
using namespace std;

struct Board
{
    int mat[3][3];             
    Board()
    {
	
        for(int i=0;i<3;i++){
           for(int j=0;j<3;j++)
                mat[i][j]=0;
    }}

};

 
void display(Board m)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(m.mat[i][j]==5)
                cout<<'X'<<" ";
            else if(m.mat[i][j]==3)
                cout<<'O'<<" ";
            else
                cout<<'_'<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


int UserTurn(Board &m,int n)
{
    for(int i=0,k=1;i<3;i++)
    {
        for(int j=0;j<3;j++,k++)
        {
            if(k==n && m.mat[i][j]!=0)
                return -1;                 
            if(k==n && m.mat[i][j]==0)
                m.mat[i][j]=5;
        }
    }
    return 1;               
}


int CheckWin(Board m)
{
    int s;
    
    for(int i=0;i<3;i++)
    {
        s=0;
        for(int j=0;j<3;j++)
        {
            s+=m.mat[i][j];
        }
        if(s==15)
            return HUM;
        else if(s==9)
            return BOT;
    }


    
    for(int j=0;j<3;j++)
    {
        s=0;
        for(int i=0;i<3;i++)
        {
            s+=m.mat[i][j];
        }
        if(s==15)
            return HUM;
        else if(s==9)
            return BOT;
    }

   
    if(m.mat[0][0]+m.mat[1][1]+m.mat[2][2] == 15)
        return HUM;
    else if((m.mat[0][0]+m.mat[1][1]+m.mat[2][2] == 9))
        return BOT;

    
    if(m.mat[0][2]+m.mat[1][1]+m.mat[2][0] == 15)
        return HUM;
    else if(m.mat[0][2]+m.mat[1][1]+m.mat[2][0] == 9)
        return BOT;

    
    int flag=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(m.mat[i][j]==0)
                flag=1;
        }
    }
    if(flag)
        return -2;
    else
        return DRAW;
}



int CompTurn(Board m,char turn)
{
    int k=CheckWin(m);
    int temp;

    if(k==BOT)
        return BOT;                 
    else if(k==HUM)
        return HUM;                
    else if(k==DRAW)
        return DRAW;              

    if(turn=='c')                  
    {

        k=-99;                       
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(m.mat[i][j]==0)
                {
                    m.mat[i][j]=3;
                    temp=CompTurn(m,'h');
                    if( temp > k)
                        k=temp;
                    m.mat[i][j]=0;
                }
            }
        }
    }
    else
    {
        k=99;                   
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(m.mat[i][j]==0)
                {
                    m.mat[i][j]=5;
                    temp=CompTurn(m,'c');
                    if(temp < k)
                        k=temp;
                    m.mat[i][j]=0;
                }
            }
        }
    }

    return k;

}



int main()
{
    for(int i=0,k=1;i<3;i++)
    {
        for(int j=0;j<3;j++,k++)
        {
            cout<<k<<" ";
        }
        cout<<endl;
    }
    int n;
    Board m,change;
    display(m);
    int k,temp;
    while(true)
    {
        cout<<"Enter your choice : ";
        cin>>n;
        if(UserTurn(m,n)==-1)
        {
            cout<<"Invalid move!!\n";
            continue;
        }

        if(CheckWin(m)==BOT)
        {
            display(m);
            cout<<" Computer Wins!\n" ;
            break;
        }
        else if( CheckWin(m)==HUM)
        {
            display(m);
            cout<<" You Win!!\n" ;
            break;
        }
        else if( CheckWin(m)==DRAW)
        {
            display(m);
            cout<<" DRAW!!\n";
            break;
        }

        k=-99;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(m.mat[i][j]==0)
                {
                    m.mat[i][j]=3;              
                    temp=CompTurn(m,'h' );
                    if(temp>k)
                    {
                        k=temp;
                        change=m;           
                    }
                    m.mat[i][j]=0;             
                }
            }
        }

        m=change;                          
        display(m);
        if(CheckWin(m)==BOT)
        {
            cout<<" Computer Wins!\n" ;
            break;
        }
        else if( CheckWin(m)==HUM)
        {
            cout<<" You Win!!\n" ;
            break;
        }
        else if( CheckWin(m)==DRAW)
        {
            cout<<" DRAW!!\n";
            break;
        }
    }
    return 0;
}

