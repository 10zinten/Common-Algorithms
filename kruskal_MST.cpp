#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int fathers[100];

int findf(int x) {
    if(fathers[x] == x)
        return x;
    else
        return findf(fathers[x]);
}

void unite(int x, int y) {
    int fx = findf(x);
    int fy = findf(y);
    fathers[fx] = fy;
}


int main() {

    // Declaratioin
    vector< pair <int, pair <int, int> > > edges;
    int n, m;
    int a, b, w;
    int mst_weight, mst_edges, mst_n;

    // Initialization
    for(int i = 0; i < 100; i++)
        fathers[i] = i;

    mst_weight = mst_edges = mst_n = 0;

    //Graph input
    // no.of nodes and no.of edges
    cin>>n>>m;

    //Edges and weight and Insert into vector< <weight, <node1 , node2>> >
    for(int i = 0; i < m; i++) {
        cin>>a>>b>>w;
        edges.push_back(make_pair(w, make_pair(a, b)));
    }

    sort(edges.begin(), edges.end());

    while((mst_edges < n - 1) && (mst_n < m)) {
        a = edges[mst_n].second.first;
        b = edges[mst_n].second.second;
        w = edges[mst_n].first;

        if(findf(a) != findf(b)) {
            unite(a, b);
            mst_weight += w;
            cout<<a<<" "<<b<<" "<<w<<endl;
            mst_edges++;
        }
        mst_n++;
    }

    cout<<"Weight of the MST: "<<mst_weight<<endl;
    cout<<"No. of the edges in MST: "<<mst_edges<<endl;
}
