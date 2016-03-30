#include <fstream>
#define U short
#define L long long
#define Q(X) Y=fread(X,sizeof(X),1,M);
U A[8192],B[13],C[13][13],D[91][13],E[455][13],F[1820][13],
G[6188][13],H[18564][13],a,b,c,d,e,f,g,h,m,n;
L z,x=1;U W(){FILE*M=fopen("H","rb");size_t Q(B);Q(C);Q(D);Q(E);Q(F);Q(G);Q(H);Q(A);}
U V(U a,U b,U c,U d,U e,U f,U h){z=(x<<a)|(x<<b)|(x<<c)|(x<<d)|(x<<e)|(x<<f)|(x<<h);
m=A[z&0x1fff]|A[(z>>13)&0x1fff]|A[(z>>26)&0x1fff]|A[z>>39];
n=H[G[F[E[D[C[B[a%13]][b%13]][c%13]][d%13]][e%13]][f%13]][h%13];
if(!m)m=n;return m;
