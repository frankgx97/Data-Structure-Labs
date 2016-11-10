#include "stdafx.h"
#include "JosephusCircle.h"

JosephusCircle::JosephusCircle(int n,int k,int m)//n=��������k=��k��ʼ������m=����m���˳���
{
	head = NULL;
	JosephusNode *current = NULL;
	JosephusCircle::n = n;
	JosephusCircle::k = k;
	JosephusCircle::m = m;

	for (int i=1;i<=n;i++)
	{
		if (i == 1)
		{
			head = new JosephusNode(i);
			current = head;
			continue;
		}
		current -> set_next(new JosephusNode(i));
		current = current -> get_next();
	}
	current -> set_next(head);
}

/*��֪n���ˣ��Ա��1��2��3...n�ֱ��ʾ��Χ����һ��Բ����Χ��
�ӱ��Ϊk���˿�ʼ����������m���Ǹ��˳��У�
������һ�����ִ�1��ʼ����������m���Ǹ����ֳ��У�*/
void JosephusCircle::start_circle()
{
	int node_count = n;
	JosephusNode *current = head;
	JosephusNode *node_for_del = NULL;
	current = countdown(head,k-1);
	cout << "k=" << current -> get_id() << endl;
	//����ָ��λ��k����k��ʼ��
	while (node_count>0)
	{
		current = countdown(current,m-2);
		//����ָ��λ��Ҫ���е�ǰһλ
		cout << "== node " << current -> next -> get_id() << " eliminated,";
		node_for_del = current -> get_next();//��ɾ���Ľڵ�
		current ->set_next(current -> next -> next);//���С�
		delete node_for_del;//�ͷ��ڴ�
		node_count--;
		current = current -> get_next();
		cout << node_count<< " nodes remain ==\n";
	}
}

JosephusNode * JosephusCircle::countdown(JosephusNode *head,int num)
{
	JosephusNode *current = head;
	for (int i=1;i<=num;i++)
		current = current -> get_next();
	return current;
}