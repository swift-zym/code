//
// Created by swift on 2020/8/4.
//

#include <iostream>#include <iostream>
#include <cstdio>#include <cstdio>
#include <cstring>#include <cstring>
#include <cstdlib>#include <cstdlib>
#include <algorithm>#include <algorithm>
#include <cassert>
#include <climits>
using namespace std;

const int INF = INT_MAX;

const int MaxN = 100000;

inline int getint()
{
    char c;
    while (c = getchar(), '0' > c || c > '9');

    int res = c - '0';
    while (c = getchar(), '0' <= c && c <= '9')
        res = res * 10 + c - '0';
    return res;
}

template <class T>
class BlockAllocator{
private:
    static const int BlockL = 10000;
    union TItem{
        char rt[sizeof(T)];
        TItem *next;
    };
    TItem *pool, *tail;TItem *unused;
public:
    BlockAllocator(){
        pool = NULL;
        unused = NULL;
    }
    T *allocate(){
        TItem *p;
        if (unused)
        {
            p = unused;
            unused = unused->next;
        }
        else
        {
            if (pool == NULL)
                pool = new TItem[BlockL], tail = pool;
            p = tail++;
            if (tail == pool + BlockL)
                pool = NULL;
        }
        return (T*)p;
    }
    void deallocate(T *pt){
        TItem *p = (TItem*)pt;
        p->next = unused, unused = p;
    }
};

struct edge
{
    int v, u, w;
    int totL;
};
struct lct_edge
{
    int w;
    edge *cirE;

    edge *getCirE()
    {
        return this ? this->cirE : NULL;
    }
};

struct lct_message
{
    int headL, midL, tailL;

    lct_edge *firstE, *lastE;

    bool hasCirE;

    void rev()
    {
        swap(firstE, lastE);
        swap(headL, tailL);
    }
    void coverCirE(edge *e, bool isSingle)
    {
        hasCirE = isSingle ? false : e != NULL;
    }

    friend inline lct_message operator+(const lct_message &lhs, const lct_message &rhs)
    {
        lct_message res;
        res.firstE = lhs.firstE, res.lastE = rhs.lastE;

        assert(lhs.lastE == rhs.firstE);
        lct_edge *e = lhs.lastE;
        res.hasCirE = lhs.hasCirE || e->cirE || rhs.hasCirE;
        if (lhs.tailL != -1 && rhs.headL != -1)
        {
            res.headL = lhs.headL;
            res.tailL = rhs.tailL;
            int trL = lhs.tailL + e->w + rhs.headL;
            res.midL = lhs.midL + min(trL, e->cirE->totL - trL) + rhs.midL;
        }
        else if (lhs.tailL != -1)
        {
            res.headL = lhs.headL;
            res.tailL = lhs.tailL + e->w + rhs.midL;
            res.midL = lhs.midL;
        }
        else if (rhs.headL != -1)
        {
            res.headL = lhs.midL + e->w + rhs.headL;
            res.tailL = rhs.tailL;
            res.midL = rhs.midL;
        }
        else
        {
            res.headL = lhs.headL;
            res.tailL = rhs.tailL;
            res.midL = lhs.midL + e->w + rhs.midL;
        }

        return res;
    }
};

struct lct_node
{
    lct_node *fa, *lc, *rc;

    lct_edge *prevE, *nextE;

    lct_message msg;

    bool hasRev;
    bool hasCoveredCirE;
    edge *coveredCirE;

    bool isRoot()
    {
        return !fa || (fa->lc != this && fa->rc != this);
    }

    void rotate()
    {
        lct_node *x = this, *y = x->fa, *z = y->fa;
        lct_node *b = x == y->lc ? x->rc : x->lc;
        x->fa = z, y->fa = x;
        if (b)
            b->fa = y;
        if (z)
        {
            if (y == z->lc)
                z->lc = x;
            else if (y == z->rc)
                z->rc = x;
        }
        if (x == y->lc)
            x->rc = y, y->lc = b;
        else
            x->lc = y, y->rc = b;
        y->update();
    }
    void allFaTagDown()
    {
        int anc_n = 0;
        static lct_node *anc[MaxN];

        anc[anc_n++] = this;
        for (int i = 0; !anc[i]->isRoot(); i++)
            anc[anc_n++] = anc[i]->fa;
        for (int i = anc_n - 1; i >= 0; i--)
            anc[i]->tag_down();
    }
    void splay()
    {
        allFaTagDown();
        while (!this->isRoot())
        {
            if (!fa->isRoot())
            {
                if ((fa->fa->lc == fa) == (fa->lc == this))
                    fa->rotate();
                else
                    this->rotate();
            }
            this->rotate();
        }
        this->update();
    }
    void splay_until(lct_node *target)
    {
        allFaTagDown();
        while (this->fa != target)
        {
            if (fa->fa != target)
            {
                if ((fa->fa->lc == fa) == (fa->lc == this))
                    fa->rotate();
                else
                    this->rotate();
            }
            this->rotate();
        }
        lct_node *x = this;
        while (!x->isRoot())
            x->update(), x = x->fa;
        x->update();
    }

    lct_node *lmost()
    {
        lct_node *x = this;
        while (x->tag_down(), x->lc)
            x = x->lc;
        return x;
    }

    void access()
    {
        for (lct_node *p = this, *q = NULL; p; q = p, p = p->fa)
        {
            p->splay();
            p->nextE = q ? q->msg.firstE : NULL;
            p->rc = q;
        }
        this->splay();
    }
    void makeRoot()
    {
        this->access();
        this->tag_rev();
        this->tag_down();
    }
    lct_node *findRoot()
    {
        this->access();
        lct_node *root = this->lmost();
        root->splay();
        return root;
    }

    void tag_rev()
    {
        hasRev = !hasRev;
        msg.rev();
    }
    void tag_coverCirE(edge *e)
    {
        hasCoveredCirE = true, coveredCirE = e;
        msg.coverCirE(e, !lc && !rc);
    }
    void tag_down()
    {
        if (hasRev)
        {
            swap(lc, rc);
            swap(prevE, nextE);

            if (lc)
                lc->tag_rev();
            if (rc)
                rc->tag_rev();
            hasRev = false;
        }
        if (hasCoveredCirE)
        {
            if (lc)
            {
                prevE->cirE = coveredCirE;
                lc->tag_coverCirE(coveredCirE);
            }
            if (rc)
            {
                nextE->cirE = coveredCirE;
                rc->tag_coverCirE(coveredCirE);
            }
            hasCoveredCirE = false;
        }
    }
    void update()
    {
        if (prevE->getCirE() == nextE->getCirE())
            msg.headL = msg.tailL = -1;
        else
        {
            msg.headL = prevE->getCirE() ? 0 : -1;
            msg.tailL = nextE->getCirE() ? 0 : -1;
        }

        msg.midL = 0;

        msg.hasCirE = false;
        msg.firstE = prevE, msg.lastE = nextE;

        if (lc)
            this->msg = lc->msg + this->msg;
        if (rc)
            this->msg = this->msg + rc->msg;
    }
};

lct_node lctVer[MaxN + 1];
BlockAllocator<edge> lctCirEAllocator;
BlockAllocator<lct_edge> lctEAllocator;

int n;

void cactus_init()
{
    for (int v = 1; v <= n; v++)
    {
        lct_node *p = lctVer + v;
        p->fa = p->lc = p->rc = NULL;
        p->prevE = p->nextE = NULL;

        p->hasRev = false;
        p->hasCoveredCirE = false;

        p->update();
    }
}

bool cactus_link(int v, int u, int w)
{
    if (v == u)
        return false;
    if (v > u)
        swap(v, u);

    lct_node *x = lctVer + v, *y = lctVer + u;

    x->makeRoot();
    y->makeRoot();

    if (x->fa)
    {
        x->access();
        y->splay_until(x);
        if (x->msg.hasCirE)
            return false;
        edge *cirE = lctCirEAllocator.allocate();
        cirE->v = v, cirE->u = u, cirE->w = w;
        cirE->totL = x->msg.midL + w;

        y->nextE->cirE = cirE;
        x->prevE->cirE = cirE;
        if (y->rc)
            y->rc->tag_coverCirE(cirE);
        y->update(), x->update();
    }
    else
    {  
        x->fa = y;

        lct_edge *e = lctEAllocator.allocate();
        e->w = w, e->cirE = NULL;
        x->prevE = e;
        x->update();
    }
    return true;
}
bool cactus_cut(int v, int u, int w)
{
    if (v == u)
        return false;
    if (v > u)
        swap(v, u);

    lct_node *x = lctVer + v, *y = lctVer + u;

    if (x->findRoot() != y->findRoot())
        return false;

    y->makeRoot();
    x->access();
    y->splay_until(x);

    lct_edge *e = y->nextE;
    edge *cirE = e->cirE;

    if (cirE && cirE->v == v && cirE->u == u && cirE->w == w)
    {
        y->nextE->cirE = NULL;
        x->prevE->cirE = NULL;
        if (y->rc)
            y->rc->tag_coverCirE(NULL);
        y->update(), x->update();

        lctCirEAllocator.deallocate(cirE);

        return true;
    }
    if (!y->rc && e->w == w)
    {
        if (cirE)
        {
            y->nextE->cirE = NULL;
            x->prevE->cirE = NULL;
        }

        y->nextE = NULL, x->prevE = NULL;

        lctEAllocator.deallocate(e);

        x->lc = NULL, y->fa = NULL;
        x->update(), y->update();

        if (cirE)
        {
            lct_node *ex = lctVer + cirE->v;
            lct_node *ey = lctVer + cirE->u;

            lct_node *rx = ex->findRoot();
            lct_node *ry = ey->findRoot();
            if (rx != ex)
            {
                ex->access();
                rx->splay_until(ex);

                ex->prevE->cirE = NULL;
                rx->nextE->cirE = NULL;
                if (rx->rc)
                    rx->rc->tag_coverCirE(NULL);
                rx->update(), ex->update();
            }

            if (ry != ey)
            {
                ey->access();
                ry->splay_until(ey);

                ey->prevE->cirE = NULL;
                ry->nextE->cirE = NULL;
                if (ry->rc)
                    ry->rc->tag_coverCirE(NULL);
                ry->update(), ey->update();
            }

            ex->makeRoot(), ey->makeRoot();

            ex->fa = ey;

            e = lctEAllocator.allocate();
            e->w = cirE->w, e->cirE = NULL;
            ex->prevE = e, ex->update();

            lctCirEAllocator.deallocate(cirE);
        }
        return true;
    }
    return false;
}
int cactus_query(int qv, int qu)
{
    lct_node *x = lctVer + qv, *y = lctVer + qu;
    if (x->findRoot() != y->findRoot())
        return -1;

    x->makeRoot();
    y->access();
    return y->msg.midL;
}

int main() {
    int nQ;

    cin >> n >> nQ;

    cactus_init();
    while (nQ--) {
        char type;
        while (type = getchar(), type != 'l' && type != 'c' && type != 'd');

        if (type == 'l') {
            int v = getint(), u = getint(), w = getint();

            if (cactus_link(v, u, w))
                printf("ok\n");
            else
                printf("failed\n");
        } else if (type == 'c') {
            int v = getint(), u = getint(), w = getint();

            if (cactus_cut(v, u, w))
                printf("ok\n");
            else
                printf("failed\n");
        } else if (type == 'd') {
            int v = getint(), u = getint();
            printf("%d\n", cactus_query(v, u));
        } else {
            puts("error!");
        }
    }

    return 0;
}