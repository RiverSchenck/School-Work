struct weight
{
	int stone;
	int pound;
	int ounce;
};


weight make_weight(int st, int pd, int ou);
weight make_weight(int on);
weight add(weight w1, weight w2);
void print(weight& w);
void read(weight* w);

