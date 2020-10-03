#include<bits/stdc++.h>
#define __SCMDVERSION__ 0
#define __SCMDBUILD__ 1
#define DEBUG
#define MAX_FILE_SIZE 100
#ifndef WIN32
#error scmd only support Windows
#endif
#include<windows.h>
using namespace std;
namespace cmd{
    void runCmd(string s){
        system(s.c_str());
    }
}
namespace scmd{
    enum authoritys {guest,user,root};
    unsigned HASH_BAS=17823;
    unordered_map<string,bool>usernames;
    bool autoReload=0;
    unsigned int getHash(string s){
        unsigned int sum=0;
        for(int i=0;i<s.length();i++){
            sum+=s[i]*HASH_BAS;
        }
        return sum;
    }
    class File{
        private:
        fstream fs;
        public:
        string dir;
        int authority;
        int type;
        enum types {file,directory};
        File* father;
        bool isRoot=false;
        vector<File*>child;
        File(string newDir,int newType){
            isRoot=true;
            type=newType;
            dir=newDir;
            authority=authoritys::user;
        }
        File(string newDir,int newType,File *newFather){
            type=newType;
            dir=newDir;
            father=newFather;
            authority=authoritys::user;
        }
        File(){}
        bool isOpen(){
            return type==types::file&&fs.is_open();
        }
        /*bool canOpen(User &user){
            return type==types::file&&user.authority>=0;
        }*/
    }rootDir,tmpDir;
    File database[MAX_FILE_SIZE];
    int tot;
    File* newFile(){
        if(tot+1<MAX_FILE_SIZE)
        return &database[tot++];
        return NULL;
    }
    class User{
        private:
        unsigned int password;
        public:
        string username;
        int authority;
        bool isLogin=false;
        File *atDir;
        void goTo(File &dir){
            atDir=&dir;
        }
        User(string newUsername,string unsafePassword){
            username=newUsername;
            usernames[username]=1;
            password=getHash(unsafePassword);
            authority=authoritys::user;
            isLogin=true;
        }
        User(string newUsername,unsigned int safePassword){
            username=newUsername;
            usernames[username]=1;
            password=safePassword;
            authority=authoritys::user;
            isLogin=true;
            goTo(rootDir);
        }
        User(){
            username="guest";
            usernames[username]=1;
            authority=authoritys::guest;
        }
        bool checkPassword(){
            cout<<"Please input password:";
            string unsafePassword;
            cin>>unsafePassword;
            if(getHash(unsafePassword)!=password){
                cout<<"Password Wrong!";
                return false;
            }
            return true;
        }
        unsigned getPasswordHash(){
            return password;
        }
        void toRoot(){
            checkPassword();
            authority=authoritys::root;
        }
    }system,active;
    void save(){
        ofstream data;
        data.open("user.scm");
        if(!data){
            puts("Error:Can't save data(can't open user.scm)");
            cmd::runCmd("pause");
            return;
        }
        data<<active.username<<endl;
        data<<active.getPasswordHash()<<endl;
        data<<autoReload<<endl;
    }
    bool read(bool load=false){
        ifstream data;
        data.open("user.scm");
        if(!data)return 0;
        if(data.eof())return 0;
        string tmp_username;
        unsigned int tmp_password;
        data>>tmp_username;
        data>>tmp_password;
        bool openAutoLoad;
        data>>openAutoLoad;
        if(load||openAutoLoad)
        active=User(tmp_username,tmp_password);
        if(openAutoLoad)return 0;
        return 1;
    }
    void initUser(){
        puts("Add new User to scmd...");
        cout<<"username:";
        string username;
        cin>>username;
        if(usernames[username]){
            puts("User Already Exit!");
            return;
        }
        cout<<"password:";
        string unsafePassword;
        cin>>unsafePassword;
        if(unsafePassword.length()<6){
            puts("Password too short");
            return;
        }
        if(unsafePassword.length()>18){
            puts("Password too long");
            return;
        }
        cout<<"try to reLogin...";
        active=User(username,unsafePassword);
        active.goTo(rootDir);
    }
    bool loop(istream &in){
        cout<<active.username<<"@"<<(*active.atDir).dir<<">";
        if(!active.isLogin){
            initUser();
            return 1;
        }
        string cmd;
        getline(in,cmd);
        if(cmd=="ls"){
            cout<<"File belong "<<(*active.atDir).dir<<" ("<<(*active.atDir).child.size()<<"):"<<endl;
            if(!active.atDir->isRoot){
                puts("..");
            }
            for(auto i:(*active.atDir).child){
                cout<<(*i).dir<<endl;
            }
            cout<<endl;
        }
        else if(cmd.substr(0,5)=="mkdir"){
            string fileName=cmd.substr(6,cmd.length()-6);
            auto fileIdx=newFile();
            (*fileIdx)=File((*active.atDir).dir+"/"+fileName,File::types::directory,active.atDir);
            (*active.atDir).child.push_back(fileIdx);
        }
        else if(cmd.substr(0,2)=="cd"){
            string fileName=cmd.substr(3,cmd.length()-3);
            if(fileName==".."){
                if(active.atDir->isRoot){
                    puts("can not go back from root!");
                }
                else{
                    active.atDir=active.atDir->father;
                }
                return 1;
            }
            for(auto i:(*active.atDir).child){
                if((*i).dir==(*active.atDir).dir+"/"+fileName){
                    if(i->type==File::directory)
                    active.atDir=i;
                    else{
                        cout<<fileName<<" is a file!"<<endl;
                    }
                    return 1;
                }
            }
            cout<<fileName<<" not found!"<<endl;
        }
        else if(cmd.substr(0,5)=="start"){
            string serviceName=cmd.substr(6,cmd.length()-6);
            if(serviceName=="auto"){
                autoReload=1;
                save();
            }
            else{
                cout<<"Can't find service \""<<serviceName<<"\""<<endl;
            }
        }
        else if(cmd.substr(0,4)=="stop"){
            string serviceName=cmd.substr(5,cmd.length()-5);
            if(serviceName=="auto"){
                autoReload=0;
                save();
            }
            else{
                cout<<"Can't find service \""<<serviceName<<"\""<<endl;
            }
        }
        else if(cmd=="clear"){
            cmd::runCmd("cls");
        }
        else if(cmd=="help"){
            puts("swift cmd,A fast, in-memory bash\nbased on Windows CMD\ndevelop by swift-zym(https://github.com/swift-zym)");
        }
        else if(cmd=="exit"){
            puts("save files...");
            save();
            exit(0);
        }
        else{
            cout<<"\""<<cmd<<"\" not found,try to run in cmd..."<<endl;
            cmd::runCmd(cmd);
        }
        if(in.eof()){
            return 0;
        }
        return 1;
    }
    void log(string s){
        #ifdef DEBUG
            puts(("LOG:"+s).c_str());
        #endif
    }
    void init(){
        log("Init file systems...");
        rootDir=File("~",File::directory);
        tmpDir=File("~/guest",File::directory);
        log("Init users...");
        system=User("root","");
        #ifdef ALWAYS_ROOT
        active=system;
        #endif
        active.goTo(tmpDir);
        cout<<"Welcome to scmd V["<<__SCMDVERSION__<<"]build("<<__SCMDBUILD__<<")"<<endl;
        if(read()){
            cout<<"found user data file,do you want do load it?[Y/N]";
            char c=getchar();
            while(c!='Y'&&c!='N'){
                c=getchar();
                cout<<endl<<"please input (Y)es or (N)o:"<<endl;
            }
            if(c=='Y'){
                read(true);
            }
        }
        while(true){
            loop(cin);
        }
    }
}
int main(){
    scmd::init();
    return 0;
}