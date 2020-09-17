#include<cstdio>

using namespace std;

bool vis[400],visor[400][400];
int num[400];
int counter,k,n;

void changer(int n)
{
	if(n==1)
	{
		visor[1][num[1]]=true;
		visor[9][num[1]]=true;
		visor[19][num[1]]=true;
		visor[22][num[1]]=true;
	}
	else if(n==2)
	{
		visor[1][num[2]]=true;
		visor[10][num[2]]=true;
		visor[20][num[2]]=true;
		visor[22][num[2]]=true;
	}
	else if(n==3)
	{
		visor[2][num[3]]=true;
		visor[8][num[3]]=true;
		visor[17][num[3]]=true;
		visor[23][num[3]]=true;
	}
	else if(n==4)
	{
		visor[2][num[4]]=true;
		visor[9][num[4]]=true;
		visor[18][num[4]]=true;
		visor[22][num[4]]=true;
		visor[23][num[4]]=true;
	}
	else if(n==5)
	{
		visor[2][num[5]]=true;
		visor[10][num[5]]=true;
		visor[19][num[5]]=true;
		visor[22][num[5]]=true;
	}
	else if(n==6)
	{
		visor[2][num[6]]=true;
		visor[11][num[6]]=true;
		visor[20][num[6]]=true;
		visor[22][num[6]]=true;
		visor[24][num[6]]=true;
	}
	else if(n==7)
	{
		visor[2][num[7]]=true;
		visor[12][num[7]]=true;
		visor[21][num[7]]=true;
		visor[24][num[7]]=true;
	}
	else if(n==8)
	{
		visor[3][num[8]]=true;
		visor[8][num[8]]=true;
		visor[16][num[8]]=true;
		visor[23][num[8]]=true;
	}
	else if(n==9)
	{
		visor[3][num[9]]=true;
		visor[9][num[9]]=true;
		visor[17][num[9]]=true;
		visor[23][num[9]]=true;
	}
	else if(n==10)
	{
		visor[3][num[10]]=true;
		visor[10][num[10]]=true;
		visor[18][num[10]]=true;
		visor[22][num[10]]=true;
		visor[23][num[10]]=true;
		visor[25][num[10]]=true;
	}
	else if(n==11)
	{
		visor[3][num[11]]=true;
		visor[11][num[11]]=true;
		visor[19][num[11]]=true;
		visor[22][num[11]]=true;
		visor[24][num[11]]=true;
		visor[25][num[11]]=true;
	}
	else if(n==12)
	{
		visor[3][num[12]]=true;
		visor[12][num[12]]=true;
		visor[20][num[12]]=true;
		visor[24][num[12]]=true;
	}
	else if(n==13)
	{
		visor[3][num[13]]=true;
		visor[13][num[13]]=true;
		visor[21][num[13]]=true;
		visor[24][num[13]]=true;
	}
	else if(n==14)
	{
		visor[4][num[14]]=true;
		visor[9][num[14]]=true;
		visor[16][num[14]]=true;
		visor[23][num[14]]=true;
		visor[26][num[14]]=true;
	}
	else if(n==15)
	{
		visor[4][num[15]]=true;
		visor[10][num[15]]=true;
		visor[17][num[15]]=true;
		visor[23][num[15]]=true;
		visor[25][num[15]]=true;
		visor[26][num[15]]=true;
	}
	else if(n==16)
	{
		visor[4][num[16]]=true;
		visor[11][num[16]]=true;
		visor[18][num[16]]=true;
		visor[25][num[16]]=true;
	}
	else if(n==17)
	{
		visor[4][num[17]]=true;
		visor[12][num[17]]=true;
		visor[19][num[17]]=true;
		visor[24][num[17]]=true;
		visor[25][num[17]]=true;
		visor[27][num[17]]=true;
	}
	else if(n==18)
	{
		visor[4][num[18]]=true;
		visor[13][num[18]]=true;
		visor[20][num[18]]=true;
		visor[24][num[18]]=true;
		visor[27][num[18]]=true;
	}
	else if(n==19)
	{
		visor[5][num[19]]=true;
		visor[9][num[19]]=true;
		visor[15][num[19]]=true;
		visor[26][num[19]]=true;
	}
	else if(n==20)
	{
		visor[5][num[20]]=true;
		visor[10][num[20]]=true;
		visor[16][num[20]]=true;
		visor[26][num[20]]=true;
	}
	else if(n==21)
	{
		visor[5][num[21]]=true;
		visor[11][num[21]]=true;
		visor[17][num[21]]=true;
		visor[25][num[21]]=true;
		visor[26][num[21]]=true;
		visor[28][num[21]]=true;
	}
	else if(n==22)
	{
		visor[5][num[22]]=true;
		visor[12][num[22]]=true;
		visor[18][num[22]]=true;
		visor[25][num[22]]=true;
		visor[27][num[22]]=true;
		visor[28][num[22]]=true;
	}
	else if(n==23)
	{
		visor[5][num[23]]=true;
		visor[13][num[23]]=true;
		visor[19][num[23]]=true;
		visor[27][num[23]]=true;
	}
	else if(n==24)
	{
		visor[5][num[24]]=true;
		visor[14][num[24]]=true;
		visor[20][num[24]]=true;
		visor[27][num[24]]=true;
	}
	else if(n==25)
	{
		visor[6][num[25]]=true;
		visor[10][num[25]]=true;
		visor[15][num[25]]=true;
		visor[26][num[25]]=true;
	}
	else if(n==26)
	{
		visor[6][num[26]]=true;
		visor[11][num[26]]=true;
		visor[16][num[26]]=true;
		visor[26][num[26]]=true;
		visor[28][num[26]]=true;
	}
	else if(n==27)
	{
		visor[6][num[27]]=true;
		visor[12][num[27]]=true;
		visor[17][num[27]]=true;
		visor[28][num[27]]=true;
	}
	else if(n==28)
	{
		visor[6][num[28]]=true;
		visor[13][num[28]]=true;
		visor[18][num[28]]=true;
		visor[27][num[28]]=true;
		visor[28][num[28]]=true;
	}
	else if(n==29)
	{
		visor[6][num[29]]=true;
		visor[14][num[29]]=true;
		visor[19][num[29]]=true;
		visor[27][num[29]]=true;
	}
	else if(n==30)
	{
		visor[7][num[30]]=true;
		visor[12][num[30]]=true;
		visor[16][num[30]]=true;
		visor[28][num[30]]=true;
	}
	else if(n==31)
	{
		visor[7][num[31]]=true;
		visor[13][num[31]]=true;
		visor[17][num[31]]=true;
		visor[28][num[31]]=true;
	}
}

void dfs(int d)
{
	if(vis[d])
	{	
		dfs(d+1);
		return;
	}
	if(d==1)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[1][i])&&(!visor[9][i])&&(!visor[19][i])&&(!visor[22][i]))
			{
				num[1]=i;
				visor[1][i]=true;
				visor[9][i]=true;
				visor[19][i]=true;
				visor[22][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[1]=0;
				visor[1][i]=false;
				visor[9][i]=false;
				visor[19][i]=false;
				visor[22][i]=false;
			}
		}
	}
	else if(d==2)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[1][i])&&(!visor[10][i])&&(!visor[20][i])&&(!visor[22][i]))
			{
				num[2]=i;
				visor[1][i]=true;
				visor[10][i]=true;
				visor[20][i]=true;
				visor[22][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[2]=0;
				visor[1][i]=false;
				visor[10][i]=false;
				visor[20][i]=false;
				visor[22][i]=false;
			}
		}
	}
	else if(d==3)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[2][i])&&(!visor[8][i])&&(!visor[17][i])&&(!visor[23][i]))
			{
				num[3]=i;
				visor[2][i]=true;
				visor[8][i]=true;
				visor[17][i]=true;
				visor[23][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[3]=0;
				visor[2][i]=false;
				visor[8][i]=false;
				visor[17][i]=false;
				visor[23][i]=false;
			}
		}
	}
	else if(d==4)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[2][i])&&(!visor[9][i])&&(!visor[18][i])&&(!visor[22][i])&&(!visor[23][i]))
			{
				num[4]=i;
				visor[2][i]=true;
				visor[9][i]=true;
				visor[18][i]=true;
				visor[22][i]=true;
				visor[23][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[4]=0;
				visor[2][i]=false;
				visor[9][i]=false;
				visor[18][i]=false;
				visor[22][i]=false;
				visor[23][i]=false;
			}
		}
	}
	else if(d==5)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[2][i])&&(!visor[10][i])&&(!visor[19][i])&&(!visor[22][i]))
			{
				num[5]=i;
				visor[2][i]=true;
				visor[10][i]=true;
				visor[19][i]=true;
				visor[22][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[5]=0;
				visor[2][i]=false;
				visor[10][i]=false;
				visor[19][i]=false;
				visor[22][i]=false;
			}
		}
	}
	else if(d==6)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[2][i])&&(!visor[11][i])&&(!visor[20][i])&&(!visor[22][i])&&(!visor[24][i]))
			{
				num[6]=i;
				visor[2][i]=true;
				visor[11][i]=true;
				visor[20][i]=true;
				visor[22][i]=true;
				visor[24][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[6]=0;
				visor[2][i]=false;
				visor[11][i]=false;
				visor[20][i]=false;
				visor[22][i]=false;
				visor[24][i]=false;
			}
		}
	}
	else if(d==7)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[2][i])&&(!visor[12][i])&&(!visor[21][i])&&(!visor[24][i]))
			{
				num[7]=i;
				visor[2][i]=true;
				visor[12][i]=true;
				visor[21][i]=true;
				visor[24][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[7]=0;
				visor[2][i]=false;
				visor[12][i]=false;
				visor[21][i]=false;
				visor[24][i]=false;
			}
		}
	}
	else if(d==8)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[3][i])&&(!visor[8][i])&&(!visor[16][i])&&(!visor[23][i]))
			{
				num[8]=i;
				visor[3][i]=true;
				visor[8][i]=true;
				visor[16][i]=true;
				visor[23][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[8]=0;
				visor[3][i]=false;
				visor[8][i]=false;
				visor[16][i]=false;
				visor[23][i]=false;
			}
		}
	}
	else if(d==9)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[3][i])&&(!visor[9][i])&&(!visor[17][i])&&(!visor[23][i]))
			{
				num[9]=i;
				visor[3][i]=true;
				visor[9][i]=true;
				visor[17][i]=true;
				visor[23][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[9]=0;
				visor[3][i]=false;
				visor[9][i]=false;
				visor[17][i]=false;
				visor[23][i]=false;
			}
		}
	}
	else if(d==10)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[3][i])&&(!visor[10][i])&&(!visor[18][i])&&(!visor[22][i])&&(!visor[23][i])&&(!visor[25][i]))
			{
				num[10]=i;
				visor[3][i]=true;
				visor[10][i]=true;
				visor[18][i]=true;
				visor[22][i]=true;
				visor[23][i]=true;
				visor[25][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[10]=0;
				visor[3][i]=false;
				visor[10][i]=false;
				visor[18][i]=false;
				visor[22][i]=false;
				visor[23][i]=false;
				visor[25][i]=false;
			}
		}
	}
	else if(d==11)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[3][i])&&(!visor[11][i])&&(!visor[19][i])&&(!visor[22][i])&&(!visor[24][i])&&(!visor[25][i]))
			{
				num[11]=i;
				visor[3][i]=true;
				visor[11][i]=true;
				visor[19][i]=true;
				visor[22][i]=true;
				visor[24][i]=true;
				visor[25][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[11]=0;
				visor[3][i]=false;
				visor[11][i]=false;
				visor[19][i]=false;
				visor[22][i]=false;
				visor[24][i]=false;
				visor[25][i]=false;
			}
		}
	}
	else if(d==12)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[3][i])&&(!visor[12][i])&&(!visor[20][i])&&(!visor[24][i]))
			{
				num[12]=i;
				visor[3][i]=true;
				visor[12][i]=true;
				visor[20][i]=true;
				visor[24][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[12]=0;
				visor[3][i]=false;
				visor[12][i]=false;
				visor[20][i]=false;
				visor[24][i]=false;
			}
		}
	}
	else if(d==13)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[3][i])&&(!visor[13][i])&&(!visor[21][i])&&(!visor[24][i]))
			{
				num[13]=i;
				visor[3][i]=true;
				visor[13][i]=true;
				visor[21][i]=true;
				visor[24][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[13]=0;
				visor[3][i]=false;
				visor[13][i]=false;
				visor[21][i]=false;
				visor[24][i]=false;
			}
		}
	}
	else if(d==14)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[4][i])&&(!visor[9][i])&&(!visor[16][i])&&(!visor[23][i])&&(!visor[26][i]))
			{
				num[14]=i;
				visor[4][i]=true;
				visor[9][i]=true;
				visor[16][i]=true;
				visor[23][i]=true;
				visor[26][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[14]=0;
				visor[4][i]=false;
				visor[9][i]=false;
				visor[16][i]=false;
				visor[23][i]=false;
				visor[26][i]=false;
			}
		}
	}
	else if(d==15)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[4][i])&&(!visor[10][i])&&(!visor[17][i])&&(!visor[23][i])&&(!visor[25][i])&&(!visor[26][i]))
			{
				num[15]=i;
				visor[4][i]=true;
				visor[10][i]=true;
				visor[17][i]=true;
				visor[23][i]=true;
				visor[25][i]=true;
				visor[26][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[15]=0;
				visor[4][i]=false;
				visor[10][i]=false;
				visor[17][i]=false;
				visor[23][i]=false;
				visor[25][i]=false;
				visor[26][i]=false;
			}
		}
	}
	else if(d==16)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[4][i])&&(!visor[11][i])&&(!visor[18][i])&&(!visor[25][i]))
			{
				num[16]=i;
				visor[4][i]=true;
				visor[11][i]=true;
				visor[18][i]=true;
				visor[25][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[16]=0;
				visor[4][i]=false;
				visor[11][i]=false;
				visor[18][i]=false;
				visor[25][i]=false;
			}
		}
	}
	else if(d==17)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[4][i])&&(!visor[12][i])&&(!visor[19][i])&&(!visor[24][i])&&(!visor[25][i])&&(!visor[27][i]))
			{
				num[17]=i;
				visor[4][i]=true;
				visor[12][i]=true;
				visor[19][i]=true;
				visor[24][i]=true;
				visor[25][i]=true;
				visor[27][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[17]=0;
				visor[4][i]=false;
				visor[12][i]=false;
				visor[19][i]=false;
				visor[24][i]=false;
				visor[25][i]=false;
				visor[27][i]=false;
			}
		}
	}
	else if(d==18)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[4][i])&&(!visor[13][i])&&(!visor[20][i])&&(!visor[24][i])&&(!visor[27][i]))
			{
				num[18]=i;
				visor[4][i]=true;
				visor[13][i]=true;
				visor[20][i]=true;
				visor[24][i]=true;
				visor[27][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[18]=0;
				visor[4][i]=false;
				visor[13][i]=false;
				visor[20][i]=false;
				visor[24][i]=false;
				visor[27][i]=false;
			}
		}
	}
	else if(d==19)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[5][i])&&(!visor[9][i])&&(!visor[15][i])&&(!visor[26][i]))
			{
				num[19]=i;
				visor[5][i]=true;
				visor[9][i]=true;
				visor[15][i]=true;
				visor[26][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[19]=0;
				visor[5][i]=false;
				visor[9][i]=false;
				visor[15][i]=false;
				visor[26][i]=false;
			}
		}
	}
	else if(d==20)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[5][i])&&(!visor[10][i])&&(!visor[16][i])&&(!visor[26][i]))
			{
				num[20]=i;
				visor[5][i]=true;
				visor[10][i]=true;
				visor[16][i]=true;
				visor[26][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[20]=0;
				visor[5][i]=false;
				visor[10][i]=false;
				visor[16][i]=false;
				visor[26][i]=false;
			}
		}
	}
	else if(d==21)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[5][i])&&(!visor[11][i])&&(!visor[17][i])&&(!visor[25][i])&&(!visor[26][i])&&(!visor[28][i]))
			{
				num[21]=i;
				visor[5][i]=true;
				visor[11][i]=true;
				visor[17][i]=true;
				visor[25][i]=true;
				visor[26][i]=true;
				visor[28][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[21]=0;
				visor[5][i]=false;
				visor[11][i]=false;
				visor[17][i]=false;
				visor[25][i]=false;
				visor[26][i]=false;
				visor[28][i]=false;
			}
		}
	}
	else if(d==22)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[5][i])&&(!visor[12][i])&&(!visor[18][i])&&(!visor[25][i])&&(!visor[27][i])&&(!visor[28][i]))
			{
				num[22]=i;
				visor[5][i]=true;
				visor[12][i]=true;
				visor[18][i]=true;
				visor[25][i]=true;
				visor[27][i]=true;
				visor[28][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[22]=0;
				visor[5][i]=false;
				visor[12][i]=false;
				visor[18][i]=false;
				visor[25][i]=false;
				visor[27][i]=false;
				visor[28][i]=false;
			}
		}
	}
	else if(d==23)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[5][i])&&(!visor[13][i])&&(!visor[19][i])&&(!visor[27][i]))
			{
				num[23]=i;
				visor[5][i]=true;
				visor[13][i]=true;
				visor[19][i]=true;
				visor[27][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[23]=0;
				visor[5][i]=false;
				visor[13][i]=false;
				visor[19][i]=false;
				visor[27][i]=false;
			}
		}
	}
	else if(d==24)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[5][i])&&(!visor[14][i])&&(!visor[20][i])&&(!visor[27][i]))
			{
				num[24]=i;
				visor[5][i]=true;
				visor[14][i]=true;
				visor[20][i]=true;
				visor[27][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[24]=0;
				visor[5][i]=false;
				visor[14][i]=false;
				visor[20][i]=false;
				visor[27][i]=false;
			}
		}
	}
	else if(d==25)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[6][i])&&(!visor[10][i])&&(!visor[15][i])&&(!visor[26][i]))
			{
				num[25]=i;
				visor[6][i]=true;
				visor[10][i]=true;
				visor[15][i]=true;
				visor[26][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[25]=0;
				visor[6][i]=false;
				visor[10][i]=false;
				visor[15][i]=false;
				visor[26][i]=false;
			}
		}
	}
	else if(d==26)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[6][i])&&(!visor[11][i])&&(!visor[16][i])&&(!visor[26][i])&&(!visor[28][i]))
			{
				num[26]=i;
				visor[6][i]=true;
				visor[11][i]=true;
				visor[16][i]=true;
				visor[26][i]=true;
				visor[28][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[26]=0;
				visor[6][i]=false;
				visor[11][i]=false;
				visor[16][i]=false;
				visor[26][i]=false;
				visor[28][i]=false;
			}
		}
	}
	else if(d==27)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[6][i])&&(!visor[12][i])&&(!visor[17][i])&&(!visor[28][i]))
			{
				num[27]=i;
				visor[6][i]=true;
				visor[12][i]=true;
				visor[17][i]=true;
				visor[28][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[27]=0;
				visor[6][i]=false;
				visor[12][i]=false;
				visor[17][i]=false;
				visor[28][i]=false;
			}
		}
	}
	else if(d==28)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[6][i])&&(!visor[13][i])&&(!visor[18][i])&&(!visor[27][i])&&(!visor[28][i]))
			{
				num[28]=i;
				visor[6][i]=true;
				visor[13][i]=true;
				visor[18][i]=true;
				visor[27][i]=true;
				visor[28][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[28]=0;
				visor[6][i]=false;
				visor[13][i]=false;
				visor[18][i]=false;
				visor[27][i]=false;
				visor[28][i]=false;
			}
		}
	}
	else if(d==29)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[6][i])&&(!visor[14][i])&&(!visor[19][i])&&(!visor[27][i]))
			{
				num[29]=i;
				visor[6][i]=true;
				visor[14][i]=true;
				visor[19][i]=true;
				visor[27][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[29]=0;
				visor[6][i]=false;
				visor[14][i]=false;
				visor[19][i]=false;
				visor[27][i]=false;
			}
		}
	}
	else if(d==30)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[7][i])&&(!visor[12][i])&&(!visor[16][i])&&(!visor[28][i]))
			{
				num[30]=i;
				visor[7][i]=true;
				visor[12][i]=true;
				visor[16][i]=true;
				visor[28][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[30]=0;
				visor[7][i]=false;
				visor[12][i]=false;
				visor[16][i]=false;
				visor[28][i]=false;
			}
		}
	}
	else if(d==31)
	{
		for(int i=1;i<=k;i++)
		{
			if((!visor[7][i])&&(!visor[13][i])&&(!visor[17][i])&&(!visor[28][i]))
			{
				num[31]=i;
				visor[7][i]=true;
				visor[13][i]=true;
				visor[17][i]=true;
				visor[28][i]=true;
				dfs(d+1);
				if(counter==n)return;
				num[31]=0;
				visor[7][i]=false;
				visor[13][i]=false;
				visor[17][i]=false;
				visor[28][i]=false;
			}
		}
	}
	else if(d==32)
	{
		counter++;
		if(counter==n)
		{
			printf("Found\n");
			for(int i=1;i<=31;i++)
			{
				if(i!=1)printf(" ");
				printf("%d",num[i]);
			}
		}
	}
}

int main()
{
	int tem,as,tol=0,a=0,ans=0,t;
	scanf("%d%d",&k,&n);
	for(int i=1;i<=31;i++)
	{
		scanf("%d",&num[i]);
		if(num[i]!=0)
		{
			vis[i]=true;
			changer(i);
		}
	}
	dfs(1);
	if(counter!=n)printf("No way");		
}
