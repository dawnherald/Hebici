
#include <stdlib.h>

/*
*并查集
*/

int getRoot(int* parent, int len, int loc) {
	if (parent && len && loc > -1) {
		while (parent[loc] != loc) {
			parent[loc] = parent[parent[loc]];//路径压缩 对于并查集提高效率非常有效
			loc = parent[loc];
		}
		return loc;
	}
	return -1;
}

void quickUion(int* rank, int* parent, int len, int p, int q) {
	if (rank && parent && len && p > -1 && q > -1) {
		if (rank[p] > rank[q]) {
			parent[q] = getRoot(parent, len, p);
			rank[q] = rank[p];
		}
		else if (rank[p] < rank[q]) {
			parent[p] = getRoot(parent, len, q);
			rank[p] = rank[q];
		}
		else {
			parent[p] = getRoot(parent, len, q);
			rank[p]++;
			rank[q]++;
		}
	}
}

int quickFind(int* rank, int* parent, int len, int p, int q) {
	if (rank && parent && len && p > -1 && q > -1) {
		return getRoot(parent, len, q) == getRoot(parent, len, p) ? true : false;
	}
	return 0;
}

int main()
{
	int parent[26];
	int rank[26];
	for (int i = 0; i < 26; i++) {
		parent[i] = i;
		rank[i] = 1;
	}
	quickUion(rank, parent, 26, 1, 2);
	quickUion(rank, parent, 26, 3, 5);
	quickFind(rank, parent, 26, 1, 22);

	return 0;
}
