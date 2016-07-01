int r;
int gcd(int u,int v){
	if(v==0) return u;
	else return gcd(v,u-u/v*v);
}
void main(void){
	int x; int y;
	x=18;
	y=15;
	gcd(x,y);
}