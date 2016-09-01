class Solution {
public:
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int s = (C-A) * (D-B) + (G-E) * (H-F); // areas of the two rectangle
    if(E>=C || F>=D || G<=A || H<=B)    return s; // no overlap
    return s - (min(C,G) - max(A,E)) * (min(D,H) - max(B,F)); //areas of the two rectangle - overlap
}
};


/*class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
{
    int total = (C-A) * (D-B) + (G-E) * (H-F);
    
    if (C<=E || A>=G || B>=H || D<=F )
        return total;
    else
    {
        vector <int> h;
        h.push_back(A);
        h.push_back(C);
        h.push_back(E);
        h.push_back(G);
   
        vector <int> v;
        v.push_back(B);
        v.push_back(D);
        v.push_back(F);
        v.push_back(H);
    
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
    
        total = total - (h[2] - h [1]) * (v[2] - v[1]);
        return total;
    }
}
};