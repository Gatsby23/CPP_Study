class TreeNode{
	private:
		std::string value;
		int count;
		TreeNode *left;
		TreeNode *right;
	public:
		TreeNode();
		TreeNode(const string &s = string, TreeNode *lchild = nullptr, TreeNode *rchild = nullptr):value(s), count(1), left(lchild), right(rchild){}
		CopyTree(void);
		TreeNode(const TreeNode &tn);
		ReleaseTree(void);
		~TreeNode();
};


class BinStrTree{
	private:
		TreeNode *root;
	public:
		BinStrTree();
		BinStrTree(TreeNode *t = nullptr):root(t){}
		BinStrTree(const BinStrTree &bst);
		~BinStrTree();
};

TreeNode::TreeNode():value(""), count(1), left(nullptr), right(nullptr){}
BinStrTree::BinStrTree():root(nullptr){												//拷贝整棵树
	root->CopyTree();																//拷贝整棵树，而不是单独一个节点
}

void TreeNode::CopyTree(void){														//拷贝以此节点为根的子树——增加引用计数
	if(left)																		//左子树不空,拷贝左子树
		left->CopyTree();
	if(right)																		//右子树不空，拷贝右子树
		left->CopyTree();
}

BinStrTree::~BinStrTree(){															//释放整颗树
		if(!root->ReleaseTree()){													//释放整棵树,而非仅仅根节点
			delete root;
		}
}

int TreeNode::ReleaseTree(void){													//释放以此节点为根的子树
	if(left){
		if(!left->CopyTree())
	delete left;
	}

	if(right){
		if(!right->CopyTree())
	delete right;
	}

	count--;
	return count;
}

TreeNode::~TreeNode(){
	//count 为0表示资源已经被释放,是delete触发的析构函数,什么不做即可
	if(count)
	ReleaseTree();
}
