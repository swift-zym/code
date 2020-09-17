//
// Created by swift on 2020/6/26.
//

#include <iostream>
#include <ctime>
#include <cstdio>
#include <cctype>
namespace FastIO
{
    char buf[1 << 21], buf2[1 << 21], a[20], *p1 = buf, *p2 = buf, hh = '\n';
    int p, p3 = -1;
    void read() {}
    void print() {}
    inline int getc()
    {
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
    }
    inline void flush()
    {
        fwrite(buf2, 1, p3 + 1, stdout), p3 = -1;
    }
    template <typename T, typename... T2>
    inline void read(T &x, T2 &... oth)
    {
        int f = 0;
        x = 0;
        char ch = getc();
        while (!isdigit(ch))
        {
            if (ch == '-')
                f = 1;
            ch = getc();
        }
        while (isdigit(ch))
        {
            x = x * 10 + ch - 48;
            ch = getc();
        }
        x = f ? -x : x;
        read(oth...);
    }
    template <typename T, typename... T2>
    inline void print(T x, T2... oth)
    {
        if (p3 > 1 << 20)
            flush();
        if (x < 0)
            buf2[++p3] = 45, x = -x;
        do
        {
            a[++p] = x % 10 + 48;
        } while (x /= 10);
        do
        {
            buf2[++p3] = a[p];
        } while (--p);
        buf2[++p3] = hh;
        print(oth...);
    }
} // namespace FastIO
#define read FastIO::read
#define print FastIO::print
//======================================
const int maxn = 1e5+5;
struct Node
{
    int fa,ch[2],val,res;   //res������?
    bool tag;               //��ת����?
}spl[maxn];
//��Ϊ���������ݿ���TLEһ���㣬����ȫ��������#define������������?
#define ls(x) (spl[x].ch[0])
#define rs(x) (spl[x].ch[1])
#define fa(x) (spl[x].fa)
#define ident(x,f) (rs(f)==x)       //�������connect����Splay�ĸ�����?
#define connect(x,f,s) spl[fa(x)=f].ch[s]=x
#define update(x) spl[x].res=spl[ls(x)].res^spl[rs(x)].res^spl[x].val
#define ntroot(x) (ls(fa(x))==x||rs(fa(x))==x)  //�жϽ���Ƿ�ΪSplay�ĸ�
#define reverse(x) std::swap(ls(x),rs(x)),spl[x].tag^=1
inline void pushdw(int x)           //�������?
{
    if(spl[x].tag)
    {
        if(ls(x)) reverse(ls(x));
        if(rs(x)) reverse(rs(x));
    }
    spl[x].tag=0;
}
void pushall(int x)                 //ͷ�ݹ飬���ϵ����´����������
{
    if(ntroot(x)) pushall(fa(x));
    pushdw(x);
}
inline void rotate(int x)           //Splay����
{
    int f=fa(x),ff=fa(f),k=ident(x,f);
    connect(spl[x].ch[k^1],f,k);
    fa(x)=ff;
    if(ntroot(f)) spl[ff].ch[ident(f,ff)]=x;//����Ҫ�����������жϣ���ϵ����ʵ?
    connect(f,x,k^1);
    update(f),update(x);
}
inline void splaying(int x)         //Splay���٣�������չ������?
{
    pushall(x);                     //Ҫ�Ȱ�����������ȫ����?
    while(ntroot(x))
    {
        int f=fa(x),ff=fa(f);
        if(ntroot(f)) ident(f,ff)^ident(x,f)?rotate(x):rotate(f);
        rotate(x);
    }
}
inline void access(int x)           //��x��ԭ���������һ��ʵ?
{
    for(int y=0;x;x=fa(y=x))        //yΪ��һ��Splay�ĸ�
    {
        splaying(x);                //��չ����ǰSplay�ĸ�
        rs(x)=y;                    //�Ҷ���������һ��Splay�ĸ�
        update(x);                  //�������£��n?
    }
}
inline void mkroot(int x)           //��ԭ����?
{
    access(x);                      //����ʵ�������ú�xһ����Splay�����ң�������
    splaying(x);                    //����չ����չ��x�ض�û���Ҷ�?
    reverse(x);                     //��ת����������ʵ����ʹ���˳��?
}
inline int findroot(int x)          //Ѱ�ҽ����ԭ����?
{
    access(x);                      //����ʵ��
    splaying(x);                    //����?
    while(ls(x))                    //��Ϊ�����ض������С�����Բ�ͣ�����Ҿ�OK?
    {
        pushdw(x);                  //�������´�����һ��������û����ĵ��ǵڶ�������?
        x=ls(x);
    }
    splaying(x);                    //������֤ʱ�临�Ӷȣ���ֹ����
    return x;
}
inline void link(int x,int y)       //���ߣ�����֤���ݺϷ�
{
    mkroot(x);                      //����
    if(findroot(y)==x) return;      //���y���ڵ����ĸ������x����˵��������һ����?
    fa(x)=y;
}
inline void cut(int x,int y)        //�ϱߣ�����֤���ݺϷ�
{
    mkroot(x);                      //����
    //? ���y��x����һ����?or x��y֮�䲻�ǽ������ŵģ�return
    //! ע������findroot�����ڱ�֤���Ӷȵ�һ����չ�����¸ղű����ɸ���x��Ϊ��Splay�ĸ����
    //* ����Ϊx��ԭ�����Ǹ���㣬�����С��������Splay��һ����xΪ�����yΪ���Ҷ�?
    if(findroot(y)!=x||fa(y)!=x||ls(y)) return;
    fa(y)=rs(x)=0;                  //˫��ϱ�
    update(x);                      //�������£��n?
}
inline void split(int x,int y)      //��x--y��·�������
{
    mkroot(x);                      //����
    access(y);                      //��ʵ?
    splaying(y);                    //��չ
    //? ��ʱy�ض�û���Ҷ������������һ����x��ʵ�������Է���y�Ϳ������κι����������Ĳ���?
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    clock_t c1 = clock();
    //======================================
    int n,m;
    read(n,m);
    //? �տ�ʼ��ʱ�����е�֮�䶼û����
    for(int i=1;i<=n;i++) read(spl[i].val);
    while(m--)
    {
        int opt,x,y;
        read(opt,x,y);
        switch(opt)
        {
            case 0:
                split(x,y);
                print(spl[y].res);      //����y���൱�ڷ�����������
                break;
            case 1:
                link(x,y);
                break;
            case 2:
                cut(x,y);
                break;
            case 3:
                splaying(x);            //ע��Ҫ����չ��������������?
                spl[x].val=y;
                update(x);              //������Ҳûɶ���⣬�Ӳ��Ӷ���
                break;
        }
    }
    //======================================
    FastIO::flush();
    std::cerr << "Time:" << clock() - c1 << "ms" << std::endl;
    return 0;
}
/*
 * ��������?  ���������Щ������Щ������Щ�����?���������Щ������Щ������Щ�����?���������Щ������Щ������Щ�����?���������Щ������Щ�����?
 * ��Esc?  ?F1?F2?F3?F4??F5?F6?F7?F8??F9��F10��F11��F12?��P/S��S L��P/B? ����    ����    ����
 * ��������?  ���������ة������ة������ة�����?���������ة������ة������ة�����?���������ة������ة������ة�����?���������ة������ة�����? ����    ����    ����
 * ���������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ�������������?���������Щ������Щ�����?���������Щ������Щ������Щ�����?
 * ��~ `? 1��@ 2? 3? 4? 5��^ 6? 7? 8? 9? 0��_ -? =?BacSp ?��Ins��Hom��PUp?��Num?/ ?* ?- ?
 * ���������ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ���������?���������੤�����੤����?���������੤�����੤�����੤����?
 * ?Tab ?Q ?W ?E ?R ?T ?Y ?U ?I ?O ?P ��{ [��} ]?| \ ?��Del��End��PDn??7 ?8 ?9 ?  ?
 * �������������ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ة���������?���������ة������ة�����?���������੤�����੤����?+ ?
 * ?Caps ?A ?S ?D ?F ?G ?H ?J ?K ?L ? ;? '?Enter  ?              ?4 ?5 ?6 ?  ?
 * ���������������ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة���������������?    ��������?    ���������੤�����੤�����੤����?
 * ?Shift  ?Z ?X ?C ?V ?B ?N ?M ? ,? .? /? Shift   ?    ???    ?1 ?2 ?3 ?  ?
 * �������������Щ����ة��Щ��ة����Щة������ة������ة������ة������ة������ة����Щة������੤�����ةЩ��������Щ�������?���������੤�����੤����?���������ة������੤����?E����
 * ?Ctrl?Win?Alt?        Space         ?Alt?Win��Menu��Ctrl?????????  0   ?. ����������
 * �������������ة��������ة��������ة����������������������������������������������ة��������ة��������ة��������ة�������?���������ة������ة�����?�����������������ة������ة�����?
 */