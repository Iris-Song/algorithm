//Multi-Machine Scheduling
template<class Type>
class JobNode {
	friend void Greedy(Type a[], int, int);
public:
	operator int()const { return time; }
private:
	int ID, time;
};
template<class Type>
class MachineNode {
	friend void Greedy(Type a[], int, int);
public:
	operator int()const { return avail; }
private:
	int ID, avail;
};
template<class Type>
void Greedy(Type a[], int n, int m) {
	//n=job number,m=machine number
	if (n <= m) {
		cout << "Each job use a machine" << endl;
		return;
	}
	//对a中各作业所花费的时间进行排序,由大到小
	sort(a, n);
	MinHeap<MachineNode> H(m);
	MachineNode x;
	for (int i = 1; i <= m; i++) {
		x.avail = 0;
		x.ID = i;
		H.insert(x);
	}
	for (int i = n; i >= 1; i--) {
		H.DeleteMin(x);
		cout << "Machine " << x.ID << "'s time from " << x.avail << " to " << a.avail + a[i].time
			<< " give to job " << a[i].ID << endl;
		x.avail += a[i].time;
		H.Insert(x);
	}
}
