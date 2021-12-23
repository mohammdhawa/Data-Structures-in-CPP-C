struct Node* LRRotation(struct Node* p)
{
	int lbf, rbf;
	struct Node* pl = p->lchild;
	struct Node* plr = pl->rchild;
	plr->bf = 0;
	p->lchild = plr->rchild;
	pl->rchild = plr->lchild; plr->lchild = pl;
	plr->rchild = p;
	lbf = height(p->lchild) + 1;
	rbf = height(p->rchild) + 1;
	p->bf = lbf - rbf;
	lbf = height(pl->lchild) + 1;
	rbf = height(pl->rchild) + 1;
	pl->bf = lbf - rbf;
	if (p == root)root = plr;
	return plr;
}
