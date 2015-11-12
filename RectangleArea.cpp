class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int tmp=0, X=0, Y=0;
        if(C<A) {tmp=C;C=A;A=tmp;}
        if(D<B) {tmp=D;D=B;B=tmp;}
        if(G<E) {tmp=G;G=E;E=tmp;}
        if(H<F) {tmp=H;H=F;F=tmp;}
        int sum = (C-A)*(D-B)+(G-E)*(H-F);
        if(((A<=E&&E<=C)||(E<=A&&A<=G))&&((B<=F&&F<=D)||(F<=B&&B<=H)))
            sum -= (min(C,G)-max(A,E))*(min(D,H)-max(B,F));
        return sum;
    }
};