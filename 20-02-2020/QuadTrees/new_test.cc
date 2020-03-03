#include<vector>
#include<string>
#include<bitset>
#include<ctgmath>
#include<cstdlib>
#include<iostream>

#include "util.hh"

using namespace std;


typedef vector<double> Key;
typedef vector<double> PMQuery;

#define maxK 10

int K,s,n_min,n_max,n_pas,n_t;

//const double fq[5] = {.1,.2,.3,.4,.5};
vector<double> fq;

struct QuadtreeNode {
  Key x;
  vector<QuadtreeNode*> child;
  QuadtreeNode(const Key& _x) : x(_x),child(int(exp2(K)), NULL) {}
};

bool matches(const bitset<maxK>& w, int j) {
    bitset<maxK> tw(j);
    for (int i = 0; i < s; ++i)
        if (w[i] != tw[i]) return false;
    return true;
}

// partial match
// returns the number of visited nodes
int partial_match(const PMQuery& q, QuadtreeNode* p){
    if (not p) return 0;
    bitset<maxK> w;
    for (int i = 0; i < s; ++i)
        if (q[i] > p->x[i]) w[i] = 1;
    int pm = 1;
    for (int i = 0; i < p->child.size(); ++i){
        if (matches(w,i)) {
            pm += partial_match(q,p->child[i]);
        }
    }
    return pm;
}

int subtree_to_insert(const Key& newKey, const Key& pKey) {
    bitset<maxK> w;
    for (int i = 0; i < K; ++i)
        if (newKey[i] > pKey[i]) w[i] = 1;
    return int(w.to_ulong());
}

void insert(const Key& newKey, QuadtreeNode*& p) {
    if (not p) p = new QuadtreeNode(newKey);
    else {
        int st = subtree_to_insert(newKey, p->x);
        insert(newKey, p -> child[st]);
    }
}

void build_quad_tree(int n, QuadtreeNode*& p) {
        for (int i = 0; i < n; ++i) {
            Key newKey = vector_uniform(K);
            insert(newKey,p);
        }
}

// Releases memory allocated to the quad-tree t and its keys
void destroy_tree(QuadtreeNode*& t) {
    if (t) {
        for (int i = 0; i < (t->child).size(); ++i)
            destroy_tree(t->child[i]);
        delete t;
    }
    t = NULL;
}

void run_experiment() {
    for (int i = n_min; i <= n_max; i += n_pas){
        for (int q1 = 0; q1 < int(fq.size()); ++q1){
            //for (int q2 = 0; q2 < int(fq.size()); ++q2){
                //for (int q3 = 0; q3 < int(fq.size()); ++q3){
                    PMQuery q = vector_uniform(s);
                    q[0]=fq[q1];
                    //q[0]= 0.5;
                    //q[1]=fq[q2];
                    //q[1]= 0.1;
                    //q[2]=fq[q3];
                    for (int j = 0; j < n_t; ++ j) {
                        QuadtreeNode* p = NULL;
                        build_quad_tree(i,p);
                        int cost = partial_match(q,p);
                        cout << K << ",";
                        cout << s << ",";
                        cout << i << ",";
                        cout << q[0] << ",";
                        //cout << q[1] << ",";
                        //cout << q[2] << ",";
                        cout << cost << endl;
                        destroy_tree(p);
                    }
               // }
           // }
        }
    }
}

int main() {
    srand (time(NULL));
    cin >> K;
    cin >> s;
    cin >> n_min;
    cin >> n_max;
    cin >> n_pas;
    cin >> n_t;
    double x = 0.01;
    while ( x < 1) {
        fq.push_back(x);
        x += 0.01;
    }

    cout << "#Col 1: dimension K: " << K << endl;
    cout << "#Col 2: specified s: " << s << endl;
    cout << "#Col 3: min n: " << n_min << endl;
    cout << "#Col 4: max n" << n_max << endl;
    cout << "#Col 5: pas n" << n_pas << endl;
    cout << "#Col 7: n of trees" << n_t << endl;
    cout << endl;
    cout << "K,s,n,q,cost" << endl;
    run_experiment();
}
