//
// Copyright@2021 Yiming Zhang All Right Reversed
//
// testdata.h version 0.0.0 beta
//
#ifndef __testdata__
#define __testdata__
   #include "Color.h"
   namespace TestData
   {   
       #ifdef _STRING_
       class Logger{
           private:
           public:
           template<typename T>
           void error(T s){
               std::cerr<<red<<"Error: "<<white<<s<<std::endl;
           }
           template<typename  T>
           void warning(T s){
               std::cerr<<yellow<<"Warning: "<<white<<s<<std::endl;
           }
           template<typename  T>
           void log(T s){
               std::cout<<s<<std::endl;
           }
           template<typename  T>
           void corret(T s){
               std::cout<<green<<s<<white<<std::endl;
           }
       }Logger;
       #endif

       class Random{
           private:
           public:
           int Int(){
               int *tmp = new int;
               int value=int(tmp);
               if(value==0||value==-0)return Int();
               return value;
           }
           int Int(int min,int max){
               int tmp=Int();
               if(tmp<0)tmp=-tmp;
               return min+tmp%(max-min+1);
           }
           bool Bool(){
               int tmp=Int();
               if(tmp<0)tmp=-tmp;
               return tmp%2==0;
           }
           long long LongInt(){
               return (long long)Int()*Int();
           }
           #ifdef _STRING_
           char Char(std::string base="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJLZXCVBNM,;[]'/,\\=-0987654321`~!@#$%^&*()_+{}|\":>?<"){
               int index=Int(0,base.length()-1);
               return base[index];
           }
           std::string String(unsigned len=50){
               std::string str="";
               for(int i=1;i<=len;i++){
                   str+=Char();
               }
               return str;
           }
           #endif
       }Random;
       
       
   } // namespace td
#endif