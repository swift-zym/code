#include<bits/stdc++.h>
using std::ios;
template<typename T>inline auto range(T i,T j){
    std::vector<T>ee;
    if(j>=i)for(T o=i;o<=j;++o)ee.push_back(o);
    else for(T o=i;o>=j;--o)ee.push_back(o);
    return ee;
}
template <typename T> struct Greater:std::greater<T>{};
template <typename T> struct Less:std::less<T>{};
std::string something;
bool input(std::ifstream&p){return 1;}
bool input(){return 1;}
void output(){}
void output(std::ofstream&p){}
template<typename fst,typename ...T> bool input(fst&w,T&...x){
    return (std::cin>>w)?input(x...):0;
}
template<typename fst,typename ...T> bool input(std::ifstream&u,fst&w,T&...x){
    return (u>>w)?input(u,x...):0;
}
template<typename fst,typename ...T> void output(fst w,T...x){
    std::cout<<w,output(x...);
}
template<typename fst,typename ...T> void output(std::ofstream&u,fst w,T...x){
    u<<w,output(u,x...);
}
#define Print print
#define setpnt setprecision
#define inputstream std::ifstream
#define outputstream std::ofstream
#define filestream std::fstream
#define Greater(x) greater<x>
#define Less(x) less<x>
#define print std::cout
#define In
#define out <<
#define Constructor(f) f
#define Destructor(f) ~f
#define read std::cin
#define Read read
#define in >>
#define begin int main(){
#define another
#define called
#define integer int
#define plus +
#define Let
#define let
#define be =
#define the
#define value
#define of
#define us
#define now
#define I
#define have
#define an
#define thing auto
#define Please
#define please
#define Now
#define Then
#define That
#define is
#define all return 0;
#define Thank
#define you
#define so
#define within :
#define much }
#define do )
#define each (
#define For for
#define word char
#define sentence string
#define Do do
#define While while(
#define array
#define Until until
#define some
#define integers integer
#define times *
#define minus -
#define divided /
#define by
#define mod %
#define Sort std::sort
#define equals ==
#define not_equals !=
#define stop break
#define Stop stop
#define If if(
#define to
#define Else else
#define boolean bool
#define one
#define is
#define from
#define different !=
#define function auto
#define with
#define as
#define well ,
#define nothing
#define address &
#define One one
#define also
#define An an
#define type struct
#define includes
#define which
#define way
#define Use
#define its this->
#define Return return
#define cpp std
#define itself *this;
#define that
#define means
#define Another another
#define but &&
#define Forever while(1
#define decimal double
#define greater >
#define less <
#define Skip continue
#define than
#define defination
#define Cpp cpp
#define arrays array
#define then
#define exception(x) x
#define Try try
#define please
#define Throw throw
#define forever Forever
#define append ios::app
#define binary ios::binary
#define Noticed catch
#define decimals double
#define nocreate ios::nocreate
#define norecreate ios::norecreate
#define toend ios::ate
#define Select switch
#define clearfile ios::trunc
#define according (
#define Otherwise default
