#include<bits/stdc++.h>
#ifdef WIN32
#include<windows.h>
#endif
#undef WIN32
//#undef WIN32
using namespace std;
int n,m,numX;
vector<char>brand;
void hurts(int s,int from,int type);
int getblood(int s);
int getjump(int s);
int getlike(int s);
int gettype(int s);
void clears(int s);
void add3s(int s);
void duels(int pos,int from);
bool works(int s,int t,int tt,int pos);
void setss(int s);
void win(int s);
struct pig{
	int type;
	int blood=4;
	int jump;
	int id;
	int like;
	bool arms;
	vector<int>hand;
	void init(int i){
		id=i;
		string s;
		cin>>s;
		if(s=="MP"){
		type=1;jump=2;
		DEBUGLOG();
		}
		else if(s=="ZP")type=2;
		else type=3,numX++;
		char c;
		for(int i=1;i<=4;i++){
			cin>>c;
			hand.push_back(c);
		}
	}
	void DEBUGLOG(){
		#ifdef WIN32
		printf("id:%d type:%d like:%d jump:%d blood:%d\n",id,type,like,jump,blood);;
		for(int i=0;i<hand.size();i++){
			printf("%c ",hand[i]);
		}
		putchar(10);
		Sleep(1000);
		#endif
	}
	bool die(int from){
		#ifdef WIN32
		cout<<"from:"<<from<<endl;
		#endif
		blood--;
		#ifdef WIN32
		cout<<id<<" "<<blood<<endl;
		#endif 
		if(blood<=0){
		for(int i=0;i<hand.size();i++){
			if(hand[i]=='P'){
				hand.erase(hand.begin()+i);
				#ifdef WIN32
				cout<<"P "<<id<<endl;
				#endif
				blood++;
				break;
			}
		}
		}
		if(blood<=0){
			if(type==1){
				win(1);
			}
			else if(type==2){
				if(gettype(from)==1){
					clears(from);
				}
			}
			else if(type==3){
				numX--;
				if(numX==0)
				win(0);
				if(from!=id)
				add3s(from);
			}
		} 
	}
	int findjd(){
		int nxt=id+1;
		if(nxt==n+1)nxt=1;
		if(type==1){
			while(nxt!=id){
				if(getblood(nxt)!=0&&(getjump(nxt)==1||getlike(nxt)==1)){
					break;
				}
				nxt=nxt+1;
				if(nxt==n+1)nxt=1;
			}
			return nxt==id?-1:nxt;
		}
		else if(type==2){
			while(nxt!=id){
				if(getblood(nxt)!=0&&getjump(nxt)==1){
					break;
				}
				nxt++;
				if(nxt==n+1)nxt=1;
			}
			return nxt==id?-1:nxt;
		}
		else{
			return 1;
		}
	}
	int findkill(){
		if(type==1){
					int nxt=id+1;
					if(nxt==n+1)nxt=1;
					while(getblood(nxt)==0){
						nxt++;
						if(nxt==n+1)nxt=1;
					}
					if(getjump(nxt)==1||getlike(nxt)==1){
						return nxt;
					}
					return -1;
				}
				else if(type==2){
					int nxt=id+1;
					if(nxt==n+1)nxt=1;
					while(getblood(nxt)==0){
						nxt++;
						if(nxt==n+1)nxt=1;
					}
					if(getjump(nxt)==1){
						return nxt;
					}
					return -1;
				}
				else{
					int nxt=id+1;
					if(nxt==n+1)nxt=1;
					while(getblood(nxt)==0){
						nxt++;
						if(nxt==n+1)nxt=1;
					}
					if(getjump(nxt)==2){
						return nxt;
					}
					return -1;
				}
	}
	bool work(int t,int tt,int pos){
		//cout<<"WORK\n";
		//return 0;
		if(pos==1){
//			cout<<"ssss******ssss\n";
		}
		if(getjump(pos)==0)return 0;
		if(type==3){
			if(tt==1&&getjump(pos)==1)return 0;
			if(tt==0&&getjump(pos)!=1)return 0;
		}
		if(type==2){
			if(tt==1&&getjump(pos)==2)return 0;
			if(tt==0&&getjump(pos)!=2)return 0;
		}
		if(type==2&&id==3){
			#ifdef WIN32
			cout<<t<<" "<<tt<<" "<<pos<<endl;
			#endif
		}
		if(type==1){
			if(tt==1&&getjump(pos)!=1&&getlike(pos)!=1)return 0;
			if(tt==0&&getjump(pos)!=2)return 0;
		}
//		cout<<"GO "<<id<<endl;
		for(int i=0;i<hand.size();i++){
			if(hand[i]=='J'){
				if(type==2)jump=2,like=0;
				if(type==3)jump=1;
				hand.erase(hand.begin()+i);
				#ifdef WIN32
				cout<<"J "<<id<<endl;
				#endif
				return 1;
			}
		} 
		return 0;
	}
	void start(){
		for(int i=1;i<=2;i++){
			hand.push_back(brand[0]);
			if(brand.size()!=1)
			brand.erase(brand.begin());
		}
		bool flag1=0;
		int use=0;
		int bf=hand.size();
		for(int i=0;i<bf;i++){
			char first=hand[i-use];
			#ifdef WIN32
			cout<<"TTT"<<first<<id<<" "<<hand.size()<<endl;
			#endif
			if(first=='P'&&blood!=4){
			#ifdef WIN32
			cout<<"P "<<id<<endl;
			#endif
			hand.erase(hand.begin()+i-use);
			blood++;	
			use++;
			}
			if((flag1==0||arms)&&first=='K'){
				int pos=findkill();
				if(pos!=-1){
					flag1=1;
					if(type==2)jump=2,like=0;
					else if(type==3)jump=1;
					#ifdef WIN32
					cout<<"K "<<id<<endl;
					#endif
					hand.erase(hand.begin()+i-use);
					use++;
					hurts(pos,id,1);
				}
			}
			if(first=='F'){
				int pos=findjd();
				if(pos!=-1){
					if(type==2)jump=2,like=0;
					else if(type==3)jump=1;
					#ifdef WIN32
					cout<<"F "<<id<<" "<<pos<<endl;
					#endif
					hand.erase(hand.begin()+i-use);
					use++;
					int nxt=id+1;
					if(nxt==n+1)nxt=1;
					bool flag=0,num=0;
					do{
						flag=0;
						int bf=nxt;
						do{
							//cout<<"***"<<nxt<<" "<<type<<" "<<num%2<<" "<<pos<<"***\n";
							if(works(nxt,type,num%2,pos)){
								flag=1;
								nxt++;
								break;
							}
							nxt++;
							if(nxt==n+1)nxt=1;
						}while(nxt!=bf);
						if(nxt==n+1)nxt=1;
						num++;
					}
					while(flag);
					if(num%2==1)
					duels(pos,id);
					#ifdef WIN32
					system("pause");
					#endif
				}
			}
			if(first=='Z'){
				arms=1;
				#ifdef WIN32
				cout<<"Z "<<id<<endl;
				#endif
				hand.erase(hand.begin()+i-use);
				use++;
			}
			if(first=='N'){
				#ifdef WIN32
				cout<<"N "<<id<<endl;
				#endif
				hand.erase(hand.begin()+i-use);
				use++;
				int nxtt=id+1;
				while(nxtt!=id){
					if(getblood(nxtt)==0){
					nxtt++;
					if(nxtt==n+1)nxtt=1;
					continue;	
					}
					if(nxtt==n+1)nxtt=1;
					int nxt=nxtt+1;
					if(nxt==n+1)nxt=1;
					bool flag=0;
					int num=0;
					do{
					 	flag=0;
						int bf=nxt;
						//if(bf>n)exit(-1);
						do{
							if(works(nxt,type,num,nxtt)){
								flag=1;
								nxt++;
								break;
							}
							nxt++;
							if(nxt==n+1)nxt=1;
						}while(nxt!=bf);
						if(nxt==n+1)nxt=1;
						num++;
					}
					while(flag);
					if(num%2==1)
					hurts(nxtt,id,2);
					nxtt=nxtt+1;
					if(nxtt==n+1)nxtt=1; 
				}
		}
		if(first=='W'){
			#ifdef WIN32
			cout<<"W "<<id<<endl;
			#endif
			hand.erase(hand.begin()+i-use);
			use++;
			int nxtt=id+1;
			if(nxtt==n+1)nxtt=1;
				while(nxtt!=id){
					if(getblood(nxtt)==0){
					nxtt++;
					if(nxtt==n+1)nxtt=1;
					continue;	
					}
					if(nxtt==n+1)nxtt=1;
					int nxt=nxtt+1;
					if(nxt==n+1)nxt=1;
					#ifdef WIN32
					cout<<"nxtt=="<<nxtt<<endl;
					#endif
					if(nxt==n+1)nxt=1;
					bool flag=0;
					int num=0;
					do{
						flag=0;
						int bf=nxt;
						do{
							#ifdef WIN32
							cout<<"X "<<nxt<<" "<<type<<" "<<num%2<<" "<<nxtt<<endl;
							#endif 
							if(works(nxt,type,num%2,nxtt)){
								flag=1;
								nxt++;
								break;
							}
							nxt++;
							if(nxt==n+1)nxt=1;
						}while(nxt!=bf);
						num++;
					}
					while(flag);
					if(num%2==1)
					hurts(nxtt,id,1);
					nxtt=nxtt+1;
				if(nxtt==n+1)nxtt=1; 
			}
		}
		if(blood<=0)return;
	}
		use=0;
		bf=hand.size();
		for(int i=0;i<bf;i++){
			char first=hand[i-use];
			#ifdef WIN32
			cout<<"TTT"<<first<<id<<" "<<hand.size()<<endl;
			#endif
			if(first=='P'&&blood!=4){
			#ifdef WIN32
			cout<<"P "<<id<<endl; 
			#endif
			hand.erase(hand.begin()+i-use);
			blood++;	
			use++;
			}
			else{
			#ifdef WIN32
			cout<<blood<<endl;
			#endif 
			}
			if((flag1==0||arms)&&first=='K'){
				int pos=findkill();
				if(pos!=-1){
					flag1=1;
					if(type==2)jump=2,like=0;
					else if(type==3)jump=1;
					#ifdef WIN32
					cout<<"K "<<id<<endl;
					#endif
					hand.erase(hand.begin()+i-use);
					use++;
					hurts(pos,id,1);
				}
			}
			if(first=='F'){
				int pos=findjd();
				if(pos!=-1){
					if(type==2)jump=2,like=0;
					else if(type==3)jump=1;
					#ifdef WIN32
					cout<<"F "<<id<<" "<<pos<<endl;
					#endif
					hand.erase(hand.begin()+i-use);
					use++;
					int nxt=id+1;
					if(nxt==n+1)nxt=1;
					bool flag=0,num=0;
					do{
						flag=0;
						int bf=nxt;
						do{
							//cout<<"***"<<nxt<<" "<<type<<" "<<num%2<<" "<<pos<<"***\n";
							if(works(nxt,type,num%2,pos)){
								flag=1;
								nxt++;
								break;
							}
							nxt++;
							if(nxt==n+1)nxt=1;
						}while(nxt!=bf);
						if(nxt==n+1)nxt=1;
						num++;
					}
					while(flag);
					if(num%2==1)
					duels(pos,id);
					#ifdef WIN32
					system("pause");
					#endif
				}
			}
			if(first=='Z'){
				arms=1;
				#ifdef WIN32
				cout<<"Z "<<id<<endl;
				#endif
				hand.erase(hand.begin()+i-use);
				use++;
			}
			if(first=='N'){
				#ifdef WIN32
				cout<<"N "<<id<<endl;
				#endif
				hand.erase(hand.begin()+i-use);
				use++;
				int nxtt=id+1;
				while(nxtt!=id){
					if(getblood(nxtt)==0){
					nxtt++;
					if(nxtt==n+1)nxtt=1;
					continue;	
					}
					if(nxtt==n+1)nxtt=1;
					int nxt=nxtt+1;
					if(nxt==n+1)nxt=1;
					bool flag=0;
					int num=0;
					do{
					 	flag=0;
						int bf=nxt;
						//if(bf>n)exit(-1);
						do{
							if(works(nxt,type,num,nxtt)){
								flag=1;
								nxt++;
								break;
							}
							nxt++;
							if(nxt==n+1)nxt=1;
						}while(nxt!=bf);
						if(nxt==n+1)nxt=1;
						num++;
					}
					while(flag);
					if(num%2==1)
					hurts(nxtt,id,2);
					nxtt=nxtt+1;
					if(nxtt==n+1)nxtt=1; 
				}
		}
		if(first=='W'){
			#ifdef WIN32
			cout<<"W "<<id<<endl;
			#endif
			hand.erase(hand.begin()+i-use);
			use++;
			int nxtt=id+1;
			if(nxtt==n+1)nxtt=1;
				while(nxtt!=id){
					if(getblood(nxtt)==0){
					nxtt++;
					if(nxtt==n+1)nxtt=1;
					continue;	
					}
					if(nxtt==n+1)nxtt=1;
					int nxt=nxtt+1;
					if(nxt==n+1)nxt=1;
					#ifdef WIN32
					cout<<"nxtt=="<<nxtt<<endl;
					#endif
					if(nxt==n+1)nxt=1;
					bool flag=0;
					int num=0;
					do{
						flag=0;
						int bf=nxt;
						do{
							#ifdef WIN32
							cout<<"X "<<nxt<<" "<<type<<" "<<num%2<<" "<<nxtt<<endl;
							#endif 
							if(works(nxt,type,num%2,nxtt)){
								flag=1;
								nxt++;
								break;
							}
							nxt++;
							if(nxt==n+1)nxt=1;
						}while(nxt!=bf);
						num++;
					}
					while(flag);
					if(num%2==1)
					hurts(nxtt,id,1);
					nxtt=nxtt+1;
				if(nxtt==n+1)nxtt=1; 
			}
		}
	}
	}
	void duel(int pos){
		#ifdef WIN32
		cout<<"duel "<<id<<" "<<pos<<endl;
		#endif
		if(type==2&&gettype(pos)==1){
				hurts(id,pos,3);
				return;
		}
		for(int i=0;i<hand.size();i++){
			
			
			if(hand[i]=='K'){
				hand.erase(hand.begin()+i);
				duels(pos,id);
				return;
			}
		}
		hurts(id,pos,3);
	}
	void hurt(int from,int typ){
		#ifdef WIN32
		cout<<"HURT "<<from<<" "<<id<<" "<<typ<<" "<<blood<<endl;
		#endif
		if(type==1){
			#ifdef WIN32
			cout<<"HURTed "<<from<<endl;
			#endif
			setss(from);
		}
		if(typ==3){
			die(from);
		}
		else if(typ==1){
			for(int i=0;i<hand.size();i++){
				if(hand[i]=='D'){
					#ifdef WIN32
					cout<<"D"<<" "<<id<<endl;
					#endif 
					hand.erase(hand.begin()+i);
					return;
				}
			}
			die(from);
		}
		else if(typ==2){
			for(int i=0;i<hand.size();i++){
				if(hand[i]=='K'){
					#ifdef WIN32
					cout<<"K"<<" "<<id<<endl;
					#endif 
					hand.erase(hand.begin()+i);
					return;
				}
			}
			die(from);
		}
	}
	
	void clear(){
		hand.clear();
		arms=0;
	}
	void add3(){
		for(int i=1;i<=3;i++){
			hand.push_back(brand[0]);
			if(brand.size()!=1)
			brand.erase(brand.begin()); 
		}
	}
	void print(){
		if(blood==0){
			printf("DEAD\n");
			return;
		}
		for(int i=0;i<hand.size();i++){
			printf("%c ",hand[i]);
		}
		putchar(10);
	}
}a[11];

int main(){
	//freopen("4.in","r",stdin);
	//freopen("4.out.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		a[i].init(i);
	}
	char c;
	for(int i=1;i<=m;i++){
		cin>>c;
		brand.push_back(c);
	}
	int now=1;
	while(1){
		if(a[now].blood!=0){
		a[now].start();
		for(int j=1;j<=n;j++)
		a[j].DEBUGLOG();
		}
		now++;
		if(now==n+1)now=1; 
	}
	return 0;
}
void hurts(int s,int from,int type){
	a[s].hurt(from,type);
}
int getblood(int s){
	return a[s].blood;
}
int getjump(int s){
	return a[s].jump;
}
int getlike(int s){
	return a[s].like;
}
void duels(int pos,int from){
	a[pos].duel(from);
}
int gettype(int s){
	return a[s].type;
}
bool works(int s,int t,int tt,int pos){
	if(pos==1){
	//	cout<<"----*********---\n";
	//	cout<<s<<" "<<t<<" "<<tt<<" "<<pos<<endl;
	//	cout<<"----*********---\n";
	}
	return a[s].work(t,tt%2,pos);
}
void add3s(int s){
	a[s].add3();
}
void clears(int s){
	a[s].clear();
}
void win(int s){
	for(int i=1;i<=n;i++){
		#ifdef WIN32
		a[i].DEBUGLOG();
		#endif
	}
	if(s==0){
		printf("MP\n");
	}
	else{
		printf("FP\n");
	}
	for(int i=1;i<=n;i++){
		a[i].print();
	}
	exit(0);
}
void setss(int s){
	if(a[s].jump){
	#ifdef WIN32
	cout<<"SET_ERROR\n";
	#endif
	return;
	}
	a[s].like=1;
	#ifdef WIN32
	cout<<"SET_FINISH\n";
	#endif
}