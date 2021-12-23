struct Node* RRRotation(struct Node* p)
{
	int lbf, rbf;
	struct Node* pr = p->rchild;
	pr->bf = 0;
	p->rchild = pr->lchild;
	pr->lchild = p;
	lbf = height(p->lchild) + 1;
	rbf = height(p->rchild) + 1;
	p->bf = lbf - rbf;
	if (p == root)root = pr;
	return pr;
}
