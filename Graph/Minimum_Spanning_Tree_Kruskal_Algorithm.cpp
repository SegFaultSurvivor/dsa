class Solution {
  public:
    int find(int node,vector<int> &parent){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = find(parent[node],parent);
    }
    void Union(int u,int v,vector<int> &parent,vector<int> &rank){
        if(rank[u] > rank[v]){
            parent[v] = u;
        }
        else if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else{
            parent[v] = u;
            rank[u]+=1;
        }
    }
    int fun(int V,vector<vector<int>> &edges,vector<int> &parent,vector<int> &rank){
        int sum = 0;
        for(auto& i : edges){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            
            int u_parent = find(u,parent);
            int v_parent = find(v,parent);
            
            if(u_parent != v_parent){
                sum+=wt;
                Union(u_parent,v_parent,parent,rank);
            }
        }
        return sum;
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        vector<int> parent (V,-1);
        vector<int> rank (V,0);
        for(int i=0;i<V;i++){
            parent[i] = i;
        }
        sort(edges.begin(),edges.end(),[](auto& a, auto& b){
            return a[2] < b[2];
        });
        return fun(V,edges,parent,rank);
    }
};