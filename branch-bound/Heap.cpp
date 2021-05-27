
template<class Type>
class MaxHeap
{
public:
	MaxHeap(int MaxHeapSize = 10);
	~MaxHeap() { delete[] heap; }

	int Size() const { return CurrentSize; }
	Type Max();//find max node
	MaxHeap<Type>& Insert(const Type& x); 
	MaxHeap<Type>& DeleteMax(Type& x); 

private:
	int CurrentSize, MaxSize;
	Type* heap;  // element array
};

template<class Type>
MaxHeap<Type>::MaxHeap(int MaxHeapSize)
{
	MaxSize = MaxHeapSize;
	heap = new Type[MaxSize + 1];
	CurrentSize = 0;
}
template<class Type>
Type MaxHeap<Type>::Max()
{          
	return heap[1];
}
template<class Type>
MaxHeap<Type>& MaxHeap<Type>::Insert(const Type& x)
{
	if (CurrentSize == MaxSize)
	{
		cout << "no space to insert!" << endl;
		return *this;
	}

	// find new element x's position
	// i is new element's position,find it's final positon from bottom to top
	int i = ++CurrentSize;
	while (i != 1 && x > heap[i / 2])//array digit num from 1 to start
	{
		// i is not root，its value bigger than its father，need modify
		heap[i] = heap[i / 2]; // father node down
		i /= 2;              // up to find final position
	}
	heap[i] = x;
	return *this;
}
template<class Type>
MaxHeap<Type>& MaxHeap<Type>::DeleteMax(Type& x)
{
	if (CurrentSize == 0)
	{
		cout << "empty heap!" << endl;
		return *this;
	}

	x = heap[1]; //max elem
	// get last node,modify heap from root
	Type y = heap[CurrentSize--]; 

	// find place for y starting at root
	int i = 1,  // current node of heap
		ci = 2; // child of i

	while (ci <= CurrentSize)
	{
		// ci is the bigger one child of i
		if (ci < CurrentSize && heap[ci] < heap[ci + 1])
			ci++;
		
		if (y >= heap[ci])
			break;// find right position
		
		heap[i] = heap[ci]; // bigger child up
		// next layer
		i = ci;            
		ci *= 2;
	}

	heap[i] = y;
	return *this;
}
