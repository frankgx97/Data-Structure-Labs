#include "stdafx.h"
#include "HuffmanTree.h"


int main()
{
	HuffmanTree tree;
	string code,str;
	cout << "²âÊÔÑùÀý£º\nCASTCASTSATATATASA\n111011001110110011001001001001100" << endl;
	cout << "ÊäÈëÒª±àÂëµÄ×Ö·û´®" << endl;
	cin >> code;
	tree.build(code);
	tree.encode(tree.get_root(), "");
	tree.print_encoded(code);
	cout << "ÊäÈëÒª½âÂëµÄ×Ö·û´®" << endl;
	cin >> str;
	cout << tree.decode(tree.get_root(), str) << endl;
	system("pause");
    return 0;
}

