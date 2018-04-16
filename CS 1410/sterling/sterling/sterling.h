struct sterling
{
	int pounds;
	int shillings;
	int pence;
};


sterling make_sterling(int pd, int sh, int pn);
sterling make_sterling(int pn);
sterling add(sterling p1, sterling p2);
void print(sterling& p);
void read(sterling* t);
