#pragma comment(lib,"user32")
#include<iostream>
#include<ctime>
#include<windows.h>
using namespace std;
int main()
{
Sleep(10000);
keybd_event(VK_LSHIFT, 0, 0,0); 
keybd_event('3',(BYTE)0, 0 ,0); 
keybd_event('3', (BYTE)0, KEYEVENTF_KEYUP,0);
keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);
 
keybd_event('I',(BYTE)0, 0 ,0); 
keybd_event('I', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('N',(BYTE)0, 0 ,0); 
keybd_event('N', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('C',(BYTE)0, 0 ,0); 
keybd_event('C', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('L',(BYTE)0, 0 ,0); 
keybd_event('L', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('U',(BYTE)0, 0 ,0); 
keybd_event('U', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('D',(BYTE)0, 0 ,0); 
keybd_event('D', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('E',(BYTE)0, 0 ,0); 
keybd_event('E', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event(VK_LSHIFT, 0, 0,0); 
keybd_event(VK_OEM_COMMA,(BYTE)0, 0 ,0); 
keybd_event(VK_OEM_COMMA, (BYTE)0, KEYEVENTF_KEYUP,0);
keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);
 
keybd_event('B',(BYTE)0, 0 ,0); 
keybd_event('B', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('I',(BYTE)0, 0 ,0); 
keybd_event('I', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('T',(BYTE)0, 0 ,0); 
keybd_event('T', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('S',(BYTE)0, 0 ,0); 
keybd_event('S', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event(VK_OEM_2,(BYTE)0, 0 ,0); 
keybd_event(VK_OEM_2, (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('S',(BYTE)0, 0 ,0); 
keybd_event('S', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('T',(BYTE)0, 0 ,0); 
keybd_event('T', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('D',(BYTE)0, 0 ,0); 
keybd_event('D', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('C',(BYTE)0, 0 ,0); 
keybd_event('C', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event(VK_LSHIFT, 0, 0,0); 
keybd_event(VK_OEM_PLUS,(BYTE)0, 0 ,0); 
keybd_event(VK_OEM_PLUS, (BYTE)0, KEYEVENTF_KEYUP,0);
keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);
 
keybd_event(VK_LSHIFT, 0, 0,0); 
keybd_event(VK_OEM_PLUS,(BYTE)0, 0 ,0); 
keybd_event(VK_OEM_PLUS, (BYTE)0, KEYEVENTF_KEYUP,0);
keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);
 
keybd_event(VK_OEM_PERIOD ,(BYTE)0, 0 ,0); 
keybd_event(VK_OEM_PERIOD , (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('H',(BYTE)0, 0 ,0); 
keybd_event('H', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event(VK_LSHIFT, 0, 0,0); 
keybd_event(VK_OEM_PERIOD ,(BYTE)0, 0 ,0); 
keybd_event(VK_OEM_PERIOD , (BYTE)0, KEYEVENTF_KEYUP,0);
keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);
 

keybd_event(VK_RETURN, 0, 0 ,0);
keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP,0);
keybd_event('U',(BYTE)0, 0 ,0); 
keybd_event('U', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('S',(BYTE)0, 0 ,0); 
keybd_event('S', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('I',(BYTE)0, 0 ,0); 
keybd_event('I', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('N',(BYTE)0, 0 ,0); 
keybd_event('N', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('G',(BYTE)0, 0 ,0); 
keybd_event('G', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event(VK_SPACE, 0, 0 ,0); 
keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP,0);
 
keybd_event('N',(BYTE)0, 0 ,0); 
keybd_event('N', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('A',(BYTE)0, 0 ,0); 
keybd_event('A', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('M',(BYTE)0, 0 ,0); 
keybd_event('M', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('E',(BYTE)0, 0 ,0); 
keybd_event('E', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('S',(BYTE)0, 0 ,0); 
keybd_event('S', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('P',(BYTE)0, 0 ,0); 
keybd_event('P', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('A',(BYTE)0, 0 ,0); 
keybd_event('A', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('C',(BYTE)0, 0 ,0); 
keybd_event('C', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('E',(BYTE)0, 0 ,0); 
keybd_event('E', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event(VK_SPACE, 0, 0 ,0); 
keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP,0);
 
keybd_event('S',(BYTE)0, 0 ,0); 
keybd_event('S', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('T',(BYTE)0, 0 ,0); 
keybd_event('T', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('D',(BYTE)0, 0 ,0); 
keybd_event('D', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event(VK_OEM_1,(BYTE)0, 0 ,0); 
keybd_event(VK_OEM_1, (BYTE)0, KEYEVENTF_KEYUP,0);
 

keybd_event(VK_RETURN, 0, 0 ,0);
keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP,0);
keybd_event('I',(BYTE)0, 0 ,0); 
keybd_event('I', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('N',(BYTE)0, 0 ,0); 
keybd_event('N', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('T',(BYTE)0, 0 ,0); 
keybd_event('T', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event(VK_SPACE, 0, 0 ,0); 
keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP,0);
 
keybd_event('M',(BYTE)0, 0 ,0); 
keybd_event('M', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('A',(BYTE)0, 0 ,0); 
keybd_event('A', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('I',(BYTE)0, 0 ,0); 
keybd_event('I', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('N',(BYTE)0, 0 ,0); 
keybd_event('N', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event(VK_LSHIFT, 0, 0,0); 
keybd_event('9',(BYTE)0, 0 ,0); 
keybd_event('9', (BYTE)0, KEYEVENTF_KEYUP,0);
keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);
 
keybd_event(VK_LSHIFT, 0, 0,0); 
keybd_event('0',(BYTE)0, 0 ,0); 
keybd_event('0', (BYTE)0, KEYEVENTF_KEYUP,0);
keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);
 
keybd_event(VK_LSHIFT, 0, 0,0); 
keybd_event(VK_OEM_4,(BYTE)0, 0 ,0); 
keybd_event(VK_OEM_4, (BYTE)0, KEYEVENTF_KEYUP,0);
keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);
 

keybd_event(VK_RETURN, 0, 0 ,0);
keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP,0);

keybd_event(VK_RETURN, 0, 0 ,0);
keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP,0);
keybd_event(VK_SPACE, 0, 0 ,0); 
keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP,0);
 
keybd_event(VK_SPACE, 0, 0 ,0); 
keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP,0);
 
keybd_event(VK_SPACE, 0, 0 ,0); 
keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP,0);
 
keybd_event(VK_SPACE, 0, 0 ,0); 
keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP,0);
 
keybd_event('R',(BYTE)0, 0 ,0); 
keybd_event('R', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('E',(BYTE)0, 0 ,0); 
keybd_event('E', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('T',(BYTE)0, 0 ,0); 
keybd_event('T', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('U',(BYTE)0, 0 ,0); 
keybd_event('U', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('R',(BYTE)0, 0 ,0); 
keybd_event('R', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event('N',(BYTE)0, 0 ,0); 
keybd_event('N', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event(VK_SPACE, 0, 0 ,0); 
keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP,0);
 
keybd_event('0',(BYTE)0, 0 ,0); 
keybd_event('0', (BYTE)0, KEYEVENTF_KEYUP,0);
 
keybd_event(VK_OEM_1,(BYTE)0, 0 ,0); 
keybd_event(VK_OEM_1, (BYTE)0, KEYEVENTF_KEYUP,0);
 

keybd_event(VK_RETURN, 0, 0 ,0);
keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP,0);
keybd_event(VK_LSHIFT, 0, 0,0); 
keybd_event(VK_OEM_6,(BYTE)0, 0 ,0); 
keybd_event(VK_OEM_6, (BYTE)0, KEYEVENTF_KEYUP,0);
keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP,0);
 

keybd_event(VK_RETURN, 0, 0 ,0);
keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP,0);
return 0;
}