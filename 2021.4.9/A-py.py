tmp=[]
def sg(a,b,c,d):
    if(a==0 and b==0 and c==0 and d==0):
        return 0
    if(not tmp[a][b][c][d] == -1):
        return tmp[a][b][c][d]
    vis=[0,0,0,0,0,0,0,0,0,0]
    if(a>=1):
        vis[sg(a-1,b,c,d)]=1
    if(b>=2):
        vis[sg(a,b-2,c,d)]=1
    if(c>=3):
        vis[sg(a,b,c-3,d)]=1
    if(d>=4):
        vis[sg(a,b,c,d-4)]=1
    if(b>=1):
        vis[sg(a+2,b-1,c,d)]=1
    if(c>=1):
        vis[sg(a+1,b+1,c-1,d)]=1
    if(d>=1):
        vis[sg(a+1,b,c+1,d-1)]=1
        vis[sg(a,b+2,c,d-1)]=1
    for i in range(len(vis)):
        if(not vis[i]):
            tmp[a][b][c][d]=i
            return i

for i in range(50):
    tmp.append([])
    for j in range(50):
        tmp[i].append([])
        for k in range(50):
            tmp[i][j].append([])
            for _ in range(6):
                tmp[i][j][k].append(-1)

stdin=open("a.in","r")
stdout=open("a.out","w")
T=int(next(stdin))
for _ in range(T):
    a,b,c,d=next(stdin).split()
    if (sg(int(a)%6,int(b)%6,int(c)%6,int(d)%6)):
        stdout.write("1\n")
    else:
        stdout.write("0\n")
