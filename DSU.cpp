#include<bits/stdc++.h>
using namespace std;

class DSU{
    public:
        int nodes;
        int components;
        vector<int> Rank, parent;

    
    DSU(int n){
        this->nodes = n;
        this->components = n;
        this->parent.resize(n);
        this->Rank.resize(n);

        for (int i = 0; i < n; i++){
            this->parent[i] = i;
            this->Rank[i] = 0;
        }
    }

    int findPar(int x){
        if(parent[x]==x)
            return x;

        return parent[x] = findPar(parent[x]);
    }

    void unite(int x, int y){
        int px = findPar(x);
        int py = findPar(y);

        if(px==py)
            return;
        
        if(Rank[px] > Rank[py]){
            parent[py] = px;
        }
        else if(Rank[py] > Rank[px]){
            parent[px] = py;
        }
        else{
            parent[py] = px;
            Rank[px]++;
        }
        components--;
    }

    int numOfComponents(){
        return components;
    }
};