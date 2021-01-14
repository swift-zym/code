#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n;
char s[1001][100001];
int main()
{
    freopen("shuru.txt","r",stdin);
    freopen("qwq.cpp","w",stdout);
    cout<<"#pragma comment(lib,\"user32\")\n#include<iostream>\n#include<ctime>\n#include<windows.h>\nusing namespace std;\nint main()\n{\nSleep(10000);\n";
    int i=0;
    while(cin.getline(s[i],100001))
    {
        int l=strlen(s[i]);
        for(int j=0;j<l;j++)
        {
            if(s[i][j]>='a'&&s[i][j]<='z')
                cout<<"keybd_event('"<<char(s[i][j]-'a'+'A')<<"',(BYTE)0, 0 ,0); \nkeybd_event('"<<char(s[i][j]-'a'+'A')<<"', (BYTE)0, KEYEVENTF_KEYUP,0);\n";
            else if(s[i][j]=='#')
            {
                cout<<"keybd_event(VK_LSHIFT, 0, 0,0); \nkeybd_event('3',(BYTE)0, 0 ,0); \nkeybd_event('3', (BYTE)0, KEYEVENTF_KEYUP,0);\nkeybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='!')
            {
                cout<<"keybd_event(VK_LSHIFT, 0, 0,0); \nkeybd_event('1',(BYTE)0, 0 ,0); \nkeybd_event('1', (BYTE)0, KEYEVENTF_KEYUP,0);\nkeybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='@')
            {
                cout<<"keybd_event(VK_LSHIFT, 0, 0,0); \nkeybd_event('2',(BYTE)0, 0 ,0); \nkeybd_event('2', (BYTE)0, KEYEVENTF_KEYUP,0);\nkeybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='$')
            {
                cout<<"keybd_event(VK_LSHIFT, 0, 0,0); \nkeybd_event('4',(BYTE)0, 0 ,0); \nkeybd_event('4', (BYTE)0, KEYEVENTF_KEYUP,0);\nkeybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='%')
            {
                cout<<"keybd_event(VK_LSHIFT, 0, 0,0); \nkeybd_event('5',(BYTE)0, 0 ,0); \nkeybd_event('5', (BYTE)0, KEYEVENTF_KEYUP,0);\nkeybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='^')
            {
                cout<<"keybd_event(VK_LSHIFT, 0, 0,0); \nkeybd_event('6',(BYTE)0, 0 ,0); \nkeybd_event('6', (BYTE)0, KEYEVENTF_KEYUP,0);\nkeybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='&')
            {
                cout<<"keybd_event(VK_LSHIFT, 0, 0,0); \nkeybd_event('7',(BYTE)0, 0 ,0); \nkeybd_event('7', (BYTE)0, KEYEVENTF_KEYUP,0);\nkeybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='*')
            {
                cout<<"keybd_event(VK_LSHIFT, 0, 0,0); \nkeybd_event('8',(BYTE)0, 0 ,0); \nkeybd_event('8', (BYTE)0, KEYEVENTF_KEYUP,0);\nkeybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='<')
            {
                cout<<"keybd_event(VK_LSHIFT, 0, 0,0); \nkeybd_event(VK_OEM_COMMA,(BYTE)0, 0 ,0); \nkeybd_event(VK_OEM_COMMA, (BYTE)0, KEYEVENTF_KEYUP,0);\nkeybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='>')
            {
                cout<<"keybd_event(VK_LSHIFT, 0, 0,0); \nkeybd_event(VK_OEM_PERIOD ,(BYTE)0, 0 ,0); \nkeybd_event(VK_OEM_PERIOD , (BYTE)0, KEYEVENTF_KEYUP,0);\nkeybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='(')
            {
                cout<<"keybd_event(VK_LSHIFT, 0, 0,0); \nkeybd_event('9',(BYTE)0, 0 ,0); \nkeybd_event('9', (BYTE)0, KEYEVENTF_KEYUP,0);\nkeybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]==')')
            {
                cout<<"keybd_event(VK_LSHIFT, 0, 0,0); \nkeybd_event('0',(BYTE)0, 0 ,0); \nkeybd_event('0', (BYTE)0, KEYEVENTF_KEYUP,0);\nkeybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='[')
            {
                cout<<"keybd_event(VK_OEM_4,(BYTE)0, 0 ,0); \nkeybd_event(VK_OEM_4, (BYTE)0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]==']')
            {
                cout<<"keybd_event(VK_OEM_6,(BYTE)0, 0 ,0); \nkeybd_event(VK_OEM_6, (BYTE)0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='-')
            {
                cout<<"keybd_event(VK_OEM_MINUS,(BYTE)0, 0 ,0); \nkeybd_event(VK_OEM_MINUS, (BYTE)0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='_')
            {
                cout<<"keybd_event(VK_LSHIFT, 0, 0,0); \nkeybd_event(VK_OEM_MINUS,(BYTE)0, 0 ,0); \nkeybd_event(VK_OEM_MINUS, (BYTE)0, KEYEVENTF_KEYUP,0);\nkeybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='=')
            {
                cout<<"keybd_event(VK_OEM_PLUS,(BYTE)0, 0 ,0); \nkeybd_event(VK_OEM_PLUS, (BYTE)0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='+')
            {
                cout<<"keybd_event(VK_LSHIFT, 0, 0,0); \nkeybd_event(VK_OEM_PLUS,(BYTE)0, 0 ,0); \nkeybd_event(VK_OEM_PLUS, (BYTE)0, KEYEVENTF_KEYUP,0);\nkeybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='\t')
            {
                cout<<"keybd_event(VK_TAB,(BYTE)0, 0 ,0); \nkeybd_event(VK_TAB, (BYTE)0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='`')
            {
                cout<<"keybd_event(VK_OEM_3,(BYTE)0, 0 ,0); \nkeybd_event(VK_OEM_3, (BYTE)0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='~')
            {
                cout<<"keybd_event(VK_LSHIFT, 0, 0,0); \nkeybd_event(VK_OEM_3,(BYTE)0, 0 ,0); \nkeybd_event(VK_OEM_3, (BYTE)0, KEYEVENTF_KEYUP,0);\nkeybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]==';')
            {
                cout<<"keybd_event(VK_OEM_1,(BYTE)0, 0 ,0); \nkeybd_event(VK_OEM_1, (BYTE)0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]==':')
            {
                cout<<"keybd_event(VK_LSHIFT, 0, 0,0); \nkeybd_event(VK_OEM_1,(BYTE)0, 0 ,0); \nkeybd_event(VK_OEM_1, (BYTE)0, KEYEVENTF_KEYUP,0);\nkeybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='{')
            {
                cout<<"keybd_event(VK_LSHIFT, 0, 0,0); \nkeybd_event(VK_OEM_4,(BYTE)0, 0 ,0); \nkeybd_event(VK_OEM_4, (BYTE)0, KEYEVENTF_KEYUP,0);\nkeybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='\'')
            {
                cout<<"keybd_event(VK_OEM_7,(BYTE)0, 0 ,0); \nkeybd_event(VK_OEM_7, (BYTE)0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='\"')
            {
                cout<<"keybd_event(VK_LSHIFT, 0, 0,0); \nkeybd_event(VK_OEM_7,(BYTE)0, 0 ,0); \nkeybd_event(VK_OEM_7, (BYTE)0, KEYEVENTF_KEYUP,0);\nkeybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='\\')
            {
                cout<<"keybd_event(VK_OEM_5,(BYTE)0, 0 ,0); \nkeybd_event(VK_OEM_5, (BYTE)0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='|')
            {
                cout<<"keybd_event(VK_LSHIFT, 0, 0,0); \nkeybd_event(VK_OEM_5,(BYTE)0, 0 ,0); \nkeybd_event(VK_OEM_5, (BYTE)0, KEYEVENTF_KEYUP,0);\nkeybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='/')
            {
                cout<<"keybd_event(VK_OEM_2,(BYTE)0, 0 ,0); \nkeybd_event(VK_OEM_2, (BYTE)0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='?')
            {
                cout<<"keybd_event(VK_LSHIFT, 0, 0,0); \nkeybd_event(VK_OEM_2,(BYTE)0, 0 ,0); \nkeybd_event(VK_OEM_2, (BYTE)0, KEYEVENTF_KEYUP,0);\nkeybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='}')
            {
                cout<<"keybd_event(VK_LSHIFT, 0, 0,0); \nkeybd_event(VK_OEM_6,(BYTE)0, 0 ,0); \nkeybd_event(VK_OEM_6, (BYTE)0, KEYEVENTF_KEYUP,0);\nkeybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='?')
            {
                cout<<"keybd_event(VK_LSHIFT, 0, 0,0); \nkeybd_event(VK_DIVIDE,(BYTE)0, 0 ,0); \nkeybd_event(VK_DIVIDE, (BYTE)0, KEYEVENTF_KEYUP,0);\nkeybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]==' ')
            {
                cout<<"keybd_event(VK_SPACE, 0, 0 ,0); \nkeybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]=='.')
            {
                cout<<"keybd_event(VK_OEM_PERIOD ,(BYTE)0, 0 ,0); \nkeybd_event(VK_OEM_PERIOD , (BYTE)0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]==',')
            {
                cout<<"keybd_event(VK_OEM_COMMA ,(BYTE)0, 0 ,0); \nkeybd_event(VK_OEM_COMMA , (BYTE)0, KEYEVENTF_KEYUP,0);\n";
            }
            else if(s[i][j]>='0'&&s[i][j]<='9')
                cout<<"keybd_event('"<<s[i][j]<<"',(BYTE)0, 0 ,0); \nkeybd_event('"<<s[i][j]<<"', (BYTE)0, KEYEVENTF_KEYUP,0);\n";
            else if(s[i][j]>='A'&&s[i][j]<='Z')
                cout<<"keybd_event(VK_LSHIFT, 0, 0,0);\nkeybd_event('"<<s[i][j]<<"',(BYTE)0, 0 ,0); \nkeybd_event('"<<s[i][j]<<"', (BYTE)0, KEYEVENTF_KEYUP,0);keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);\n";
            cout << " \n";
        }
        cout<<"\nkeybd_event(VK_RETURN, 0, 0 ,0);\nkeybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP,0);\n";
    }
    cout<<"return 0;\n}";
    return 0;
}