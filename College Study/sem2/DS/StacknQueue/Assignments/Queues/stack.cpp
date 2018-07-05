class stack {

	int Arr[1000];
	int TOP;

	public :
		stack() {
			TOP = -1;
		}

		bool empty() {
			if(TOP==-1) return true;
			else return false;	
		}

		bool push(int x) {
			if(TOP>=999) return false;

			Arr[TOP+1] = x;
			++TOP;

			return true;
		}

		int top() {
			return Arr[TOP];
		}

		bool pop() {
			if(TOP==-1) return false;

			--TOP;

			return true;
		}

};