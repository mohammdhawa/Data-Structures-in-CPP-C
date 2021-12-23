struct Node* LLRotation(struct Node* p)
{
	int lbf, rbf;
	struct Node* pl = p->lchild;
	pl->bf = 0;
	p->lchild = pl->rchild;
	pl->rchild = p;
	lbf = height(p->lchild) + 1;
	rbf = height(p->rchild) + 1;
	p->bf = lbf - rbf;
	if (p == root)root = pl;
	return pl;
}
